🔵 입력 바인딩의 기본

    using System.Collections;
    using System.Collections.Generic;
    using UnityEngine;

    public class Movement : MonoBehaviour
    {
        void Update()
        {
            ProcessThrust();
            ProcessRotation();
        }

        void ProcessThrust() 
        {
            if (Input.GetKey(KeyCode.Space))
            {
                Debug.Log("Pressed SPACE - Thrusting");
            }
        }

        void ProcessRotation()
        {
            if (Input.GetKey(KeyCode.A))
            {
                Debug.Log("Rotate Left");
            }
            else if (Input.GetKey(KeyCode.D))
            {
                Debug.Log("Rotate Right");
            }
        }
}

🔵 AddRelativeForce() 메소드

    void ProcessThrust() 
    {
        if (Input.GetKey(KeyCode.Space))
        {
            // rb.AddRelativeForce(0, 1, 0);
            rb.AddRelativeForce(Vector3.up);   // 위랑 같은 뜻 y축으로 올라감
        }
    }

🔵 transform.Rotate() 메소드

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [SerializeField]float mainThrust = 300f;
    [SerializeField]float rotationThrust = 100f;
    Rigidbody rb;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }
    void Update()
    {
        ProcessThrust();
        ProcessRotation();
    }

    private void ProcessThrust() 
    {
        if (Input.GetKey(KeyCode.Space))
        {
            rb.AddRelativeForce(Vector3.up * mainThrust * Time.deltaTime);
        }
    }

    private void ProcessRotation()
    {
        if (Input.GetKey(KeyCode.A)) 
        {
            ApplyRotation(rotationThrust);      
        }
        else if (Input.GetKey(KeyCode.D))
        {
            ApplyRotation(-rotationThrust);
        }
    }

    private void ApplyRotation(float rotationThisFrame)
    {
        transform.Rotate(Vector3.forward * rotationThisFrame * Time.deltaTime);   
    }
}

🔵 rigidbody 제약 조건

    private void ApplyRotation(float rotationThisFrame)
    {
        rb.freezeRotation = true; // '수동 제어를 할 수 있도록 회전을 고정한다'
        transform.Rotate(Vector3.forward * rotationThisFrame * Time.deltaTime);
        rb.freezeRotation = false; // 물리 시스템이 적용되도록 회전 고정을 해제한다.
    }
    
    
🔵 유니티 오디오  
    
 Main Camera에 Audio  Listener 컴포넌트 추가
 Rocket에 Audion Source 컴포넌트 추가
 
 Audacity (녹음 프로그램) 사용해서 내가 만든 로켓 사운드 입히기
 
 


🔵 AudioSource SFX 재생

    AudioSource audioSource;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
        audioSource = GetComponent<AudioSource>();   // audioSource로 AudioSource 컴포넌트 
    }

    void Update()
    {
        ProcessThrust();
        ProcessRotation();
    }

    private void ProcessThrust() 
    {
        if (Input.GetKey(KeyCode.Space))
        {
            rb.AddRelativeForce(Vector3.up * mainThrust * Time.deltaTime);
            if (!audioSource.isPlaying)  // 만약 오디오가 재생중이 아니라면
            {
                audioSource.Play();  // 오디오 재생
            }
        }
        else
        {
            audioSource.Stop();  // 스페이스가 안눌리면 오디오 정지
        }
    }

🔵 SceneManger를 사용한 리스폰

using UnityEngine;
using UnityEngine.SceneManagement;   // 새로운 네임스페이스 추가

public class CollisionHandler : MonoBehaviour
{
    private void OnCollisionEnter(Collision other) 
    {
        switch (other.gameObject.tag)
        {
            case "Friendly": 
                Debug.Log("This thing is friendly");
                break;    
            case "Finish": 
                Debug.Log("Congrats, yo, you finisihed!");
                ReloadLevel();
                break; 
            case "Fuel": 
                Debug.Log("You piced up fuel!");
                break; 
            default:
                Debug.Log("Sorry, you blew up!");
                ReloadLevel();
                break;
        } 
    }

    void ReloadLevel()  // 씬을 다시 
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // 현재 씬을 저장
        SceneManager.LoadScene(currentSceneIndex); // 현재 씬을 다시 불러옴
        //SceneManager.LoadScene("SandBox"); 
        //SceneManager.LoadScene(0);  <-- 0은 SandBox의 인데스 번호
    }
}


🔵 다음 단계 로드

    void LoadNextLevel() 
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // 현재씬 인덱스 저장
        int nextSceneIndex = currentSceneIndex + 1; // 다음 씬은 현재 씬 인덱스에 +1 을 해줌
        if (nextSceneIndex == SceneManager.sceneCountInBuildSettings) // 다음씬이 현재 저장되어있는 씬들의 수와 같다면
        {
            nextSceneIndex = 0; // 0으로 초기화
        }
        SceneManager.LoadScene(nextSceneIndex);  // 다음씬으로 이동
    }

    void ReloadLevel()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // 현재 씬을 저장
        SceneManager.LoadScene(currentSceneIndex); // 현재 씬을 다시 불러옴
    }



-------------------------------------------------------
    
🎈🎈 제대로 실행 안됐던 이유. --->  finish에 착륙하면 바로 게임 캐릭터를 움직이지 못하고, 1초 후에 다음 단계로 넘어가는 코드 작성을 하려고 함.

using UnityEngine;
using UnityEngine.SceneManagement;

public class CollisionHandler : MonoBehaviour
{
    [SerializeField]float delayTime = 1f;
    private void OnCollisionEnter(Collision other) 
    {
        switch (other.gameObject.tag)
        {
            case "Friendly": 
                Debug.Log("This thing is friendly");
                break;    
            case "Finish": 
                Debug.Log("Congrats, yo, you finisihed!");
                Invoke("LoadNextLevel", delayTime);   // LoadNextLevel() 메서드를 1초 후에 호출함.
                break; 
            default:
                Debug.Log("Sorry, you blew up!");
                StartCrashSequence();
                break;
        } 
    }

    void StartCrashSequence() 
    {
        GetComponent<Movement>().enabled = false;
        Invoke("ReloadLevel", delayTime);
    }

    void LoadNextLevel() 
    {
        GetComponent<Movement>().enabled = false;  // 🎈🎈 플레이어를 못움직이게 하는 것 또한 1초 후에 호출 됨...
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; 
        int nextSceneIndex = currentSceneIndex + 1;
        if (nextSceneIndex == SceneManager.sceneCountInBuildSettings) 
        {
            nextSceneIndex = 0; // 0으로 초기화
        }
        SceneManager.LoadScene(nextSceneIndex);  // 다음씬으로 이동
    }

    void ReloadLevel()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // 현재 씬을 저장
        SceneManager.LoadScene(currentSceneIndex); // 현재 씬을 다시 불러옴
    }
}

--- ✅ 해결함.

using UnityEngine;
using UnityEngine.SceneManagement;

public class CollisionHandler : MonoBehaviour
{
    [SerializeField]float levelLoadDelay = 1f;
    private void OnCollisionEnter(Collision other) 
    {
        switch (other.gameObject.tag)
        {
            case "Friendly": 
                Debug.Log("This thing is friendly");
                break;    
            case "Finish": 
                Debug.Log("Congrats, yo, you finisihed!");
                StartSuccessSequence();
                break; 
            default:
                Debug.Log("Sorry, you blew up!");
                StartCrashSequence();
                break;
        } 
    }

    void StartCrashSequence() 
    {
        GetComponent<Movement>().enabled = false;
        Invoke("ReloadLevel", levelLoadDelay);
    }
 
    void StartSuccessSequence()   // ✅ finish에 착륙하면 바로 캐릭터 움직이지 못하게 하고, 1초 후 다음단계로 넘어가는 메소드.
    {
        GetComponent<Movement>().enabled = false;
        Invoke("LoadNextLevel", levelLoadDelay);
    }    

    void LoadNextLevel() 
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // 현재씬 인덱스 저장
        int nextSceneIndex = currentSceneIndex + 1; // 다음 씬은 현재 씬 인덱스에 +1 을 해줌
        if (nextSceneIndex == SceneManager.sceneCountInBuildSettings) // 다음씬이 현재 저장되어있는 씬들의 수와 같다면
        {
            nextSceneIndex = 0; // 0으로 초기화
        }
        SceneManager.LoadScene(nextSceneIndex);  // 다음씬으로 이동
    }

    void ReloadLevel()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // 현재 씬을 저장
        SceneManager.LoadScene(currentSceneIndex); // 현재 씬을 다시 불러옴
    }
}


🔵 다중 오디오 클립    (꼭 오디오클립에 오디오 파일을 첨부해줘야함)


using UnityEngine;
using UnityEngine.SceneManagement;

public class CollisionHandler : MonoBehaviour 
{
    [SerializeField] float levelLoadDelay = 1f;
    [SerializeField] AudioClip success;            // ✅ 착륙 성공했을 때 오디오 클립
    [SerializeField] AudioClip crash;              // ✅ 장애물과 부딪혔을 때 오디오 클립

    AudioSource audioSource;

    void Start() 
    {
        audioSource = GetComponent<AudioSource>();    // ✅ 오디오 캐싱
    }
    
    private void OnCollisionEnter(Collision other) 
    {
        switch (other.gameObject.tag)
        {
            case "Friendly": 
                Debug.Log("This thing is friendly");
                break;    
            case "Finish": 
                Debug.Log("Congrats, yo, you finisihed!");
                StartSuccessSequence();
                break; 
            default:
                Debug.Log("Sorry, you blew up!");
                StartCrashSequence();
                break;
        } 
    }

    void StartCrashSequence() 
    {
        audioSource.PlayOneShot(crash);              // ✅ 오디오 클립 적용
        GetComponent<Movement>().enabled = false;
        Invoke("ReloadLevel", levelLoadDelay);
    }

    void StartSuccessSequence()
    {
        audioSource.PlayOneShot(success);            // ✅ 오디오 클립 적용
        GetComponent<Movement>().enabled = false;
        Invoke("LoadNextLevel", levelLoadDelay);
    }    

    void LoadNextLevel() 
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // 현재씬 인덱스 저장
        int nextSceneIndex = currentSceneIndex + 1; // 다음 씬은 현재 씬 인덱스에 +1 을 해줌
        if (nextSceneIndex == SceneManager.sceneCountInBuildSettings) // 다음씬이 현재 저장되어있는 씬들의 수와 같다면
        {
            nextSceneIndex = 0; // 0으로 초기화
        }
        SceneManager.LoadScene(nextSceneIndex);  // 다음씬으로 이동
    }

    void ReloadLevel()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex; // 현재 씬을 저장
        SceneManager.LoadScene(currentSceneIndex); // 현재 씬을 다시 불러옴
    }
}
