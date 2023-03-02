Udemy 유니티

🔵 2022. 09. 05. 월

🟢 reset 하면 0, 0, 0으로 돌아옴

🟢 q, w, e, r, t, y 로 물체를 다양하게 움직임

🟢 shift를 누르면 하이라키 창에서 오브젝트 다중 선택 가능

🟢 creat empty를 하고 오브젝트를 몰아 넣는 거 추천

🟢 그 오브젝트를 프리팹하는거 추천 (프리팹하면 변경사항을 한꺼번에 변경가능)


🔵 2022. 09. 06. 화

🟢 void Start() 메소드 : 게임이 시작됨과 동시에 한번만 실행

🟢 void Update() 메소드 : 게임이 시작되고 나서 진행되는 매 프레임마다 실행

🟢 transform.Translate(0.1f, 0, 0);  :  x좌표로 0.1초 더함

🟢 변수를 사용해서 값을 지정하기!!
 --> 그러면 위에서 값을 더 깔끔하게 지정할 수 있음
        그리고 같은 값을 여러번 사용할 때 유용함!! 
float xValue = 0.01f;
transform.Translate(xValue, 0, 0);


🟢 meterial 활용해서 object 색깔, 질감 등등 바꾸기


🟢 직렬화 필드를 사용해 인스펙터에서 값을 수정할 수 있도록 해준다.
[SerializeField]float xValue = 0;
[SerializeField]float yValue = 0.02f;         이런 식으로..!!!
[SerializeField]float zValue = 0;


🔵 2022. 09. 07. 수

🟢 Input.GetAxis("Horziontal");
    -->  수평으로(x 축으로) 키보드의 입력을 받아 위치를 변경


🟢 Input.GetAxis("Vertical");   
    --> 수직으로 (z 축으로) 키보드의 입력을 받아 위치를 변경


🟢 Time.deltaTime
   -->  이것이 필요한 이유는 각각의 유저들의 컴퓨터 마다 사양이 다르기 때문에
            프레임 또한 달라진다. 결국 어느 컴퓨터가 좋은지에 따라 캐릭터의 움직임이나
            총알의 속도 또한 달라질 수 있는데, 결국 이는 사양이 좋은 컴퓨터가 
            게임에서 더 유리한 상황을 초래한다.
            이를 막기 위해서는 우리는 Time.deltaTime이라는 것을 사용한다.
            
            만약 1초에 10프레임이 나오는 컴퓨터라면 알아서 유니티가 0.1을 곱하여 1을 만들어주고,
            1초에 100프레임이 나오는 컴퓨터라면 유니티가 알아서 0.01초를 곱하여 1을 만들어준다.
   

🟢 따라다니는 카메라 만들기
1. Pacakge Manager에서 unity registry로 들어가서 Cinemachine 다운(비쥬얼코드 꺼져있어야함)
2. Cinemachine에서 create virtual camera 클릭
3. 카메라에 CinemachineBrain 컴포넌트 추가
4. 가상 카메라의 Body를 Framing Transposer로 변경
5. 가상 카메라가 따라다닐 오브젝트 설정

🟢 colider 그리고 rigidbody 중력과 충돌


🔵 2022. 09. 08. 목

🟢 Start() 메서드 : 유니티에서 시작 버튼 누르면 바로 실행해주는 메소드

🟢 Update() 메서드: 게임이 실행되는 동안 프레임단위로 계속해서 실행해주는 메소드

메소드를 꼭 잘 활용하자!!

 void Update()
    {                           // Axis 뜻 : 중심선
        MovePlayer();
    }

 void MovePlayer()
    {
        float xValue = Input.GetAxis("Horizontal") * Time.deltaTime * moveSpeed;  // Horizontal : 수평의 
        float zValue = Input.GetAxis("Vertical") * Time.deltaTime * moveSpeed;  // Vertical : 수직의

        transform.Translate(xValue, 0, zValue);
    }


🟢 OnCollisionEnter() 메소드 : 물체간의 충돌이 처음 일어났을 때 호출

   private void OnCollisionEnter(Collision other) 
    {
        Debug.Log("Bumped into a wall");
    }


🟢 OnCollisionStay() 메소드 : 물체간의 충돌이 일어난 후 충돌이 지속될 때 호출

   private void OnCollisionStay(Collision other)
    {
        Debug.Log("Bumped into a wall");
    }


🟢 OnCollisionExit() 메소드 : 물체간의 충돌이 끝나는 그 순간에 호출

   private void OnCollisionExit(Collision other) 
    {
        Debug.Log("Bumped into a wall");    
    }


🟢 GetComponent<MeshRenderer>().material.color = Color.red;
 
  --> Mesh Renderer 컴포넌트에서 material의 color를 빨간색으로 바꾸어주라


🟢 Time.time : 시간을 알려주는 변수 

 -->  Debug.Log(Time.time);
 
🟢 참조 캐싱하기

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dropper : MonoBehaviour
{
    MeshRenderer renderer; 
    Rigidbody rigidbody;
    [SerializeField]float timeToWait = 5f;
    // Start is called before the first frame update
    void Start()
    {
        renderer = GetComponent<MeshRenderer>(); // Caching  
        renderer.enabled = false;

        rigidbody = GetComponent<Rigidbody>();  // Generalization (일반화)
        rigidbody.useGravity = false;
    }

    // Update is called once per frame
    void Update()
    {
        if(Time.time > timeToWait)
        {
            renderer.enabled = true;   <-- 참조형이므로 다른 메소드에서 설정해도 여기서 
            rigidbody.useGravity = true;
        }
    }
}

🟢 태그 사용하기

public class Scorer : MonoBehaviour
{
    int hits = 0;
    private void OnCollisionEnter(Collision other) 
    {
        if(other.gameObject.tag != "Hit") // 만약 플레이어 오브젝트와 충돌한 오브젝트의 태그가 Hit가 아니라면
        {
            hits++;
            Debug.Log("You've bumped into a thing this many times: " + hits);  // hits 값 출력
        }
    }
}
----------------------------------------------------------------

public class ObjectHit : MonoBehaviour
{
    private void OnCollisionEnter(Collision other) // 물체간의 충돌이 처음 일어났을 경우 호출, 
    {
        if(other.gameObject.tag == "Player") // 만약 오브젝트와 플레이어 태그를 가진 오브젝트가 부딪칠 경우
        {
            GetComponent<MeshRenderer>().material.color = Color.red; // 빨간색으로 변경
            gameObject.tag = "Hit"; // 그리고 이 오브젝트의 태그를 "Hit"로 변경
        }
    }
}
