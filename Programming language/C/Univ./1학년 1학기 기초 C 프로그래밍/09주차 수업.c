2022. 04. 28.

🟡 배열의 이해

🟢 배열을 사용하는 이유

--> 각각의 변수에 값을 입력할 때, 변수의 개수가 3개 정도라면 각각 값을 입력할 때 그리 번거롭지 않겠지만, 변수의 개수가 50개, 100개
    이상으로 많아지게 된다면 변수의 값을 하나씩 입력받도록 하는 코드를 짜기가 많이 번거롭고, 보기에도 안좋을 것이다.
    하지만 배열을 사용하면 코드의 길이를 매우 단축할 수 있고 효과적인 코드를 짤수가 있다.
    
    int a,b,c,d;   
    int str[4];   --> 이렇게 배열을 사용하면 변수를 각각 선언하지 않아도 간단하게 변수를 담을 바구니를 만들어낼 수 있다.
    
    
    
 #include <stdio.h>

int main()
{
	int aa[4];
	int hap;

	printf("첫 번째 숫자를 입력: ");
	scanf("%d", &aa[0]);
	printf("두 번째 숫자를 입력: ");
	scanf("%d", &aa[1]);
	printf("세 번째 숫자를 입력: ");
	scanf("%d", &aa[2]);
	printf("네 번째 숫자를 입력: ");
	scanf("%d", &aa[3]);

	hap = aa[0] + aa[1] + aa[2] + aa[3];
	printf("합: %d", hap);

	return 0;
}

--> 배열을 활용한 코드이지만, 그다지 효율성을 느낄 수는 없다.   아래로 ㄱㄱ

🟢 배열의 활용 범위

 
  🟠 배열의 실제 활용
  
   --> 배열의 가치가 빛을 발하게 하려면 배열의 첨자가 순서대로 변할 수 있도록 반복문과 함께 활용해야 한다.
   
   
   
   #include <stdio.h>

int main()
{
	int aa[4];
	int hap = 0;

	for (int i = 0; i < 4; i++)
	{
		printf("%d 번째 숫자: ", i + 1);
		scanf("%d", &aa[i]);
		hap = hap + aa[i];
	}

	printf("합: %d", hap);

	return 0;
}

--> for문을 활용하여 비교적 훨씬 간단하게 코드를 수정하여 자신이 원하는 개수의 숫자의 합을 구할 수 있게 되었다.


  
  🟠 배열의 초기화
  
  int aa[4] = {100, 200, 300 ,400}; 
  
  --> int aa[0] = 100;
      int aa[1] = 200;
      int aa[2] = 300;
      int aa[3] = 400;   
      
      
   int aa[] = {100, 200, 300, 400};     -->   이렇게 배열의 개수(첨자)를 반드시 지정하지 않아도 된다.  {} 안의 초깃값 개수에 따라 자동으로 배열의 개수가 정해진다.
      
      
   int aa[4];   -->  이렇게 배열을 선언하기만 하고 초기화를 하지 않으면, 배열에 아무것도 넣지 않았기 때문에 쓰레기 값이 들어가게된다.
   
   
   int aa[4] = {100, 200};  -->  배열의 개수보다 초기화할 값의 개수가 적으면 초기값이 주어진 aa[0]과 aa[1]에는 각각 100과 200이 들어가지만,
                                 나머지 aa[2]와 aa[3]에는 0이 들어가게 된다.
                                 
   
   int aa[1000] = {0};   -->  1000개의 배열이 전부 0으로 초기화가 된다.
   
   
   int aa[3] = {100, 200, 300, 400};   -->  배열의 개수가 초기화 값보다 적다면 컴파일 오류가 발생한다.
   
   
   
   
   #include <stdio.h>

int main()
{
	int aa[50];
	int bb[50];
	int k = 1;

	for (int i = 0; i < 50; i++)
	{
		aa[i] = k *= 3;
		printf("aa[%d]의 값: %d \n", i, aa[i]);
	}

	printf("\n");

	for (int i = 0; i < 50; i++)
	{
		bb[i] = aa[49 - i];
		printf("bb[%d]의 값: %d \n", i, bb[i]);
	}

	return 0;
}

   
  
  🟠 배열의 크기 알아내기
  
  -->    배열의 크기(요소의 개수) = sizeof(전체 배열 이름) / sizeof(배열의 데이터 형식);
         
         
         int aa[5]; 일 때,
         배열의 크기(요소의 개수) = sizeof(aa) / sizeof(int)
         --> int 하나 당 4바이트를 차지하므로, sizeof(aa)는 20바이트이고 sizeof(int)는 4바이트이다.
             따라서 배열의 크기(요소의 개수)는 5개이다.
             aa[0], aa[1], aa[2], aa[3], aa[4]
  
  
  #include <stdio.h>

int main()
{
	int aa[5] = { 100, 50, 300, 20, 0 };
	int count = 5;
	int hap = 0;

	for (int i = 0; i < count; i++)
	{
		hap = hap + aa[i];
	}

	printf("%d", hap);

	return 0;
}
  
🟡 배열과 문자열

🟢 정수형 배열과 문자형 배열

 -->  정수형 배열은 각각의 배열 요소에 정수 (100, 200, 300, 400)를 입력하고, 문자형 배열은 각각의 배열 요소에 문자 ('X', 'Y', 'Z', '\0')를 입력한다.
      문자형 배열의 마지막에는 문자열의 마지막을 의미하는 널문자 '\0'을 넣는다.
      문자열은 문자형 배열에 입력하는 '문자의 집합'이라고 할 수 있다.
      
      
  #include <stdio.h>

void main()
{
	char ss[5] = "abcd";
	char tt[5];
	
	for (int i = 0; i < 4; i++)
	{
		tt[i] = ss[3 - i];   // tt[0] = ss[3],  tt[1] = ss[2],  tt[2] = ss[1],  tt[3] = ss[0]
	}
	tt[4] = '\0';  

	printf("%s", tt);   // "dcba" 출력

	return 0;
}



🟢 문자열 함수로 문자열 다루기

  🟠 문자열 처리 함수
  
  -->   C에서는 문자열을 쉽게 사용할 수 있도록 도와주는 함수를 여러 개 제공한다.
        문자열 함수를 사용하려면 #include <string.h> 를 써줘야한다.
	
        strlen(), strcpy(), strcat(), strcmp()
	
	✅1. 문자열의 길이를 알려주는 함수: strlen()     <--  "string length" 의 약자

	#include <stdio.h>
	#include <string.h>

	int main()
	{
		char ss[] = "안녕";            <-- 배열 ss와 tt의 크기가 널 문자를 포함 하므로 각각 5와 3이다. 하지만 strlen()함수는 길이를 구할 때 널 문자를 제외한다.
		char tt[] = "HI";                  따라서 배열의 크기는 각각 5와 3이지만, 4와 2로 출력된다.
		int i, j;

		i = strlen(ss);   <-- 4바이트
		j = strlen(tt);   <-- 2바이트

		printf("문자열 %s의 길이 ==>  %d\n문자열 %s의 길이 ==>  %d", ss, i, tt, j);

		return 0;
	}

	출력결과: 문자열 안녕의 길이 ==>  4
		  문자열 HI의 길이 ==>  2
	
	 
	
	
	
	✅2. 문자열을 복사하는함수: strcpy()    <-- "string copy" 의 약자

	#include <stdio.h>
	#include <string.h>

	int main()
	{
		char ss[5];
		char tt[5];
		int i, j;

		strcpy(ss, "HI");            <-- strcpy()함수를 사용하여 배열 ss에 문자열 "HI"를 복사했다.
		strcpy(tt, "안녕");	   <-- strcpy()함수를 사용하여 배열 tt에 문자열 "안녕"를 복사했다.

		i = strlen(ss);
		j = strlen(tt);


		printf("문자열 %s의 길이 ==>  %d\n문자열 %s의 길이 ==>  %d", ss, i, tt, j);

		return 0;
	}
	
	출력결과: 문자열 HI의 길이 ==>  2
		  문자열 안녕의 길이 ==>  4
	
	
	
	
	char ss[5];
	char tt[5];
	
	ss="hi";      <-- 💞 이런식으로 이미 선언된 문자열 배열에 문자열을 바로 배열에 대입할 수 없고 strcpy() 함수를 사용해야 한다.
	tt = "안녕";
	
		  
	
	✅3. 두 문자열을 이어주는 함수: strcat()   --> string concatenate 의 약자           *concatenate 뜻: 사슬 같이 잇다
	
	#include <stdio.h>
	#include <string.h>

	int main()
	{
		char ss[7] = "abc";

		strcat(ss, "def");    <--  "abc"에 "def"를 붙혀줘서 "abcdef"이 된다.  "def"는 널 문자 자리부터 시작한다.


		printf("문자열: %s", ss);

		return 0;
	}

        출력결과: abcdef
	
	
-------------------------------------

	#include <stdio.h>
	#include <string.h>

	int main()
	{
	    char s1[10] = "World!";
	    char s2[20] = "Hello"; // s2 뒤에 붙일 것이므로 배열 크기를 크게 만듦

	    strcat(s2, s1);        // s2 뒤에 s1를 붙임

	    printf("%s\n", s2);    // HelloWorld!

	    return 0;
	}
	
        출력결과: HelloWorld!
	
-------------------------------------	
	
	🎈🎈 strcat(A, B)에서 A는 꼭 문자형 배열이어야한다.                  책 p.257
             이는 A와 B를 이은 결과를 다시 A(배열)에 넣어야 하기 때문이다.

		strcat(ss, tt) ⭕			strcat("ABC", "EFG") ❌
		strcat(ss, "ABC") ⭕			strcat("ABC", ss) ❌
	
	
	
	✅4. 두 문자열을 비교하는 함수: strcmp()   -->  string compare 의 약자
  		
	#include <stdio.h>
	#include <string.h>

	int main()
	{
	    char ss[] = "abc";
	    char tt[] = "abc";

	    int i;
	    i = strcmp(ss, tt);

	    printf("%d", i);

	    return 0;
	}
	
        출력결과: 0
-------------------------------

  	strcmp(s1, s2);
  	-1: ASCII 코드 기준으로 문자열2(s2)가 클 때 
	 0: ASCII 코드 기준으로 두 문자열이 같을 때 
	 1: ASCII 코드 기준으로 문자열1(s1)이 클 때
	 
	  컴파일러에 따라 출력 값이 반대인 경우도 있는 듯하다. 내 컴일러는 s2가 크면 1을 출력하고 s2가 작으면 -1을 출력한다.
	  
	 🎈🎈 두 문자열이 같으면 0, 다르면 그 외의 숫자가 나온다.
	      strcmp() 함수는 단지 두 문자열이 다르다는 뜻으로만 받아들이면 된다.
  
  
  🟠 문자열 입출력 함수
  
  1. 문자열을 입력받는 함수: gets()
   
   --> gets(입력받을 문자 배열) / enter를 입력할때 까지 ss에 문자열을 받아들인다.
   
       🎈🎈 scanf() 함수는 문자열 중간에 공백 문자(space)를 입력할 수 없지만 gets() 함수는 공백 문자를 입력할 수 있다.
       
       char ss[10];
       gets(ss);
  
  
  2. 문자열을 출력하는 함수: puts()
   
   --> puts(출력할 문자 배열)  /   🎈🎈 printf()와 다른 점은 \n이 없어도 출력한 후 자동으로 줄을 넘긴다는 것이다.
   	
       char ss[5];
       puts(ss);
       
       
----------------------------------------------------------------------------------------------------------------------------------------------------------------

💫나 홀로 고민.💫

#include <stdio.h>
#include <string.h> 

int main()
{
    char ss[100];
    char tt[100];

    printf("ss input : ");    
    scanf("%s", ss);        <-- 아마도 enter키를 누르는 것이 다음 gets에 영향을 미치는 것 같다.

    printf("tt input : ");
    gets(tt);

    printf("ss output : ");
    printf("%s", ss);

    printf("tt output : ");
    puts(tt);

    return 0;
}
 
 ---------------------------------------------  두 코드의 차이점은?   위 코드는 내가 생각한대로 실행되지 않는다. 그 이유가 뭘까?

#include <stdio.h>
#include <string.h>

int main()
{
    char ss[100];
    char tt[100];

    printf("tt input : ");
    gets(tt);

    printf("ss input : ");
    scanf("%s", ss);

    printf("tt output : ");
    puts(tt);

    printf("ss output : ");
    printf("%s", ss);

    return 0;
}  
  
  
  
  
  
  
