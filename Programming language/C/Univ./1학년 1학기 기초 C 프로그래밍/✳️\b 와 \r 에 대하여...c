설명 출처:  https://youadokjon.tistory.com/1

🎈 \r 🎈 --> 캐리지 리턴 (Carriage Return), 줄의 끝에서 시작 위치로 되돌아가는 제어문자

\r :  10진수 -> 13
      16진수 -> 0x0D
        문자 -> CR

\r (캐리지 리턴) 은 현재 줄(행)에서 첫 부분으로 이동하는 것이다.
커서가 이동만 할 뿐이지 이전에 출력했던 문자들을 지우지는 않는다.



#include <stdio.h>

int main(void)

{

  printf("Berrrrrrrrrr\rHappy!");   -->  'Happy! rrrrr'로 출력

}

이 코드가  'Happy! rrrrr'로 출력되는 이유가 뭘까??

그 이유는 Happy! rrrr 사이의 공백에 커서가 위치하기 때문이다.


다른 예로,


#include <stdio.h>

int main(void)

{

	printf("aaaaa");     --> ' ddd '로 출력
	printf("\r ddd");

}

이 코드가 ' ddda'로 출력되지 않고, ' ddd '출력되는 이유가 뭘까??
같은 이유로 커서가 마지막 a위에 위치하기 때문이다.


하지만!!


#include <stdio.h>

int main(void)

{
	printf("Berrrrrrrrrr\rHappy!\n");   -->  'Hapyy!rrrrrr' 로 출력
}


이 코드는 왜 'Hapyy!rrrrrr'로 출력이 될까??

그건 바로 마지막의 \n 제어문자 때문이다.

"Berrrrrrrrrr\rHappy!" 여기까지는 'Hapyy! rrrrr' 이처럼 현재 커서의 위치가 !와 r의 사이에 위치한다.

하지만 \n이 "Berrrrrrrrrr\rHappy!\n" 등장함에 따라 커서의 위치가 아래로 이동하여
(!와 r사이에 있던 커서가 아래로 이동하여)

'Hapyy!rrrrrr' 로 출력되는 것이다.

다른 예로,

#include <stdio.h>

int main(void)

{

	printf("aaaaa");        --> 'dddaa'로 출력
	printf("\rddd\n");   

	return 0;

}

이 코드 또한 마찬가지이다.

  printf("aaaaa");     
	printf("\rddd");    여기까지는 분명히 'ddd a'로 출력이 될 것이다.
  
  하지만

  printf("aaaaa");        
	printf("\rddd\n");   \n이 붙음으로써 커서가 아래로 이동하기 때문에
                       'dddaa'로 출력이 되는 것이다.
  



🎈 \b 🎈 : 백 스페이스 (backspace)

백 스페이스라고 하지만 우리가 평소 사용하는 그 백 스페이스와는 다르다.

우리가 평소에 사용하는 backspace는 글자를 지움과 동시에 뒤로 움직이지만,

\b는 커서만을 한칸 뒤로 움직인다.


#include <stdio.h>

int main(void)

{

	printf("abcdef\b");   -->  'abcde' 로 출력

	return 0;

}

이 코드와 코드의 실행 결과만 봤을 때는 우리가 쓰는 백스페이스와 뭐가 다른지 짐작하기 어렵다.

하지만 현재 abcdef에서 f는 지워진 것이 아니라, 그 위에 커서가 위치하고 있는 것이다.



#include <stdio.h>

int main(void)

{

	printf("abcdef\b\b");  -->  'abcd f' 로 출력

	return 0;

}

이 코드의 실행결과는 'abcd f' 이다. 그 이유는 커서가 뒤로 두 번 이동했기 때문에

커서가 'e'자리에 위치하고 있기 때문이다.




#include <stdio.h>

int main(void)

{

	printf("abc\bd\b\b \n");   
	printf("fe\bh\b\b \n");  
	return 0;

}




이 코드는 어떻게 출력 될까?

🔎🔎 출력 결과:  a d
                   h

이 코드가 왜 이렇게 출력되는지는 위의 설명을 보면 충분히 유츄가 가능하다.

하지만 조금 헷갈리는 부분은 공백부분이다. 그것만 주의하면 될 듯하다.





#include <stdio.h>

int main(void)

{

	printf("abc\bd\b\bf\n");   -->  'afd' 로 출력
	printf("fe\bh\b\bc\n");  -->  'ch' 로 출력
	return 0;

}

이 코드는 위의 코드의 공백 부분에 각각 f와 c를 넣어주었다.
이걸 보면 더 이해가 확실히 될 것이다.




printf("ABC\b\bDEF");    -->  'ADEF'로 출력  // 커서의 위치가 'B'위에 있으므로 B위에서 DEF가 입력되기 때문.



 \r 과 \b는 인설트(insert) 모드를 잘 이해하고 있다면 충분히 잘 활용가능할 것이다.






