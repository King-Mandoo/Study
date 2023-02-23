-----------------------------
#include <stdio.h>

int main()
{
    char c;

    for (int i = 0; i < 3; i++)
    {
        scanf("%c", &c);
        printf("%c", c);
    }

    return 0;
}
      문자형 변수를 각각 입력을 하지말고  한번에 "ABC"를 입력한다고 가정해보자.
      그러면 scanf() 함수는 "ABC"를 입력 받았지만 이를 바로 출력하지 못한다.
      사실 입력된 "ABC"는 버퍼에 저장이 되어있는데, scanf() 함수는 버퍼에서 이를 가져올 뿐이다.
      따라서 "ABC"를 입력한 후에 버퍼에는 'A' 'B' 'C' '\n'가 저장되게 된다.
      
      🎈🎈 여기서 궁금증.. 그럼 printf() 함수는 버퍼에서 값을 빼주는 역할을 해주나?
           그래서 for 문이 끝나고 printf() 함수를 하나 더 붙혀봤다.
----------------------
#include <stdio.h>

int main()
{
    char c;

    for (int i = 0; i < 3; i++)
    {
        scanf("%c", &c);    <-- "apple"를 입력해준다.
        printf("%c", c);    <-- "app"를 출력한다.
    } 
    printf("%c", c);    <-- 'p'를 출력한다.

    return 0;
}

      이말은 즉슨 printf() 함수는 버퍼에서 값을 빼주는 역할을 하는 것이 아니라 그냥
      변수 c의 값을 출력해주는 역할을 하는 것이다.
      
      그래서 밑에 scanf() 함수를 하나 더 붙혀봤다.
----------------------------
#include <stdio.h>

int main()
{
    char c;

    for (int i = 0; i < 3; i++)
    {
        scanf("%c", &c);  <-- "apple"를 입력해준다.
        printf("%c", c);  <-- "app"를 출력한다.
    }
    scanf("%c", &c);
    printf("%c", c);   <-- 'l'를 출력한다.

    return 0;
}

      여기서 우린 알 수 있다. scanf() 함수가 버퍼에서 값을 빼와서 읽어주는 함수라는 것을..
      
      scanf() 함수를 통해 "apple"을 입력하여 버퍼에 'a' 'p' 'p' 'l' 'e' '\n' 을 넣어준다.
      
      그러면 처음 입력된 'a'가 출력, 그다음 'p'가 출력, 그다음 'p'
      그리고 for문 밖을 scanf()에서 또한 다음 버퍼에서 값을 빼와서 읽어주므로 'l'이 출력된다.
      
      결론은 scanf() 함수를 호출하고 값을 입력하고, 버퍼 안에 있는 값을 빼주긴 위해서는 
      다시 scanf() 함수를 호출해야 한다는 것이다. 그래야 버퍼 안에 있는 값을 
      scanf() 함수에 입력이 된다.
      
      🎈🎈 여기서 또 다시 드는 궁금증 만약.. 문자형 변수가 다르다면??
           버퍼를 공유할까??
----------------------------------
#include <stdio.h>

int main()
{
    char c;
    char d;   <-- 문자형 변수 d 선언

    for (int i = 0; i < 3; i++)
    { 
        scanf("%c", &c);    <-- "apple"를 입력해준다.
        printf("%c", c);    <-- "app"를 출력한다.
    }
    scanf("%c", &d);     <-- 'l'을 읽어옴
    printf("%c", d);     <-- 'l' 출력
    
    scanf("%c", &d);     <-- 'e'를 읽어옴
    printf("%c", d);     <-- 'e' 출력
    
    scanf("%c", &d);     <-- '\n'을 읽어옴
    printf("%c", d);     <-- '\n'을 출력
    
    return 0;
}

                     변수가 달라도 버퍼를 공유하는 듯 하다.
		     
		     하지만 내가 본 영상에서는 메모리에는 여러 버퍼가 있고
		     버퍼마다 이름이 있다고 한다.
		     그렇다면 버퍼를 지정해주는 건 어떻게 하는걸까..?
		     
--------------------------------------------

    scanf() 함수가 숫자를 입력하는 과정은 어떻게 될까..??
    
    int a;
    scanf("%d", &a);  -->  '10'을 입력  -->  버퍼에 '1' '0' '\n'의 아스키 코드 값이 들어간다.
                           (1과 0 그리고 \n을 각각의 아스키 코드 값에 따른 문자형 상태로 저장)
                      -->  따라서 %d를 사용하여 10진수 정수로 해석하라고 말함
                      -->  그리고 '1'과 '0'을 붙혀서 '10'이라는 10진수 형태의 숫자로 바꿔줌
                      --> 데이터로 인식되지 않는 '\n'은 버퍼에 남아있음.
                           
                      🎈🎈 %d %f %lf %s 는 '\n'과 같은 개행문자를 데이터로 인식하지 않는다.
                           히지만 %c는 개행문자를 데이터로 인식한다.
                      
                           따라서
#include <stdio.h>

int main()
{
    int a;
    char b;

    scanf("%d", &a);            
    scanf("%c", &b);
    printf("%d", a);
    printf("%c", b);

    return 0; 
}                                이제는 이러한 코드가 왜 내 뜻대로 작동하지 않았는지 알 수 있다.
                                 버에서 %c를 통해 b에 '\n'이 입력되었기 때문이다.
                      
   
     * scanf() 함수는 키보드로 Ctrl + z를 누르면 -1을 반환한다.
		      
---------------------------------------------------------------
✅ Q. 두 코드의 차이는 무엇일까?
       왜 왼쪽 코드는 내 생각대로 되지 않을까?

#include <stdio.h> 			        #include <stdio.h>

int main() 			                int main()
{					        {
    char ss[100]; 			  	    char ss[100];
    char tt[100];  				    har tt[100];
    
    printf("ss input : ");    			    printf("ss input : "); 
    scanf("%s", ss);  				    gets(ss);

    printf("tt input : "); 			    printf("tt input : ");
    gets(tt); 					    scanf("%s", tt);  

    printf("ss output : ");			    printf("ss output : ");
    printf("%s", ss);				    printf("%s", ss);

    printf("tt output : ");   			    printf("tt output : ");
    puts(tt);  					    puts(tt);

    return 0;    				    return 0;	
}						 }	
	
  A. 형식 지정자 %s를 사용하는 scanf() 함수는 공백문자(스페이스, 탭, '\n' 등)를 데이터 취급하지 않는다.
     따라서 
     
	     printf("ss input : ");
	     scanf("%s", ss); 
     
     이렇게 처음 입력을 받는 구간에서 scanf() 함수는 문자열을 입력을 하고 버퍼안에 '\n'은 놓고 나온다.
     따라서 gets() 함수는 '\n'을 받고 바로 종료가 되고 이어서 줄줄이 출력 되는 것이다.
  
  
     
    이 궁금증에 대하여 도움을 받은 자료들..
    https://www.youtube.com/watch?v=U77SN6iBQdo   <-- 20분 경에 내가 궁금했던 부분을 잘 알려줌
    https://bigpel66.oopy.io/library/c/chewing-c/6  <-- scanf() 함수를 다루면서 내가 궁금했던 부분이 적혀있음
    https://hashcode.co.kr/questions/16620/c%EC%96%B8%EC%96%B4-%EB%B2%84%ED%8D%BC%EC%97%90-%EA%B4%80%ED%95%B4%EC%84%9C
