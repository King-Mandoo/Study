2022. 05. 26.

🟡 지역변수와 전역변수

  --> 변수는 사용되는 범위에 따라 크게 집(함수) 안에서만 사용되는 '지역변수(local variable)'와
      집 밖에서도 사용할 수 있는 '전역변수(global variable)'로 나뉜다.
      
      지역변수는 말 그대로 한정된 지역에서만 사용되는 변수이고 전역변수는 프로그램 전체에서 사용되는 변수이다.

🟠 함수의 개념

#include <stdio.h>

int a = 100;    <-- 전역 변수 a

void func1()
{
	int a = 200;            <-- 지역변수 a, 이게 없으면 당연히 100으로 출력
	printf("func1()에서 a의 값 ==> %d\n", a);
}

int main()
{
	func1();
	printf("main() 에서 a의 값 ==> %d\n", a);
}
 
출력결과 :
		func1()에서 a의 값 ==> 200
		main() 에서 a의 값 ==> 100

 ----------------------------------------------------------
 
 #include <stdio.h>

int a = 100;

void func1()
{
	a = 200;   <-- 이렇게 변수 a에 200을 넣어준다면 아래와 같이 출력한다.
	printf("func1()에서 a의 값 ==> %d\n", a);
}

int main()
{
	func1();
	printf("main() 에서 a의 값 ==> %d\n", a);
}

출력결과 :
		func1()에서 a의 값 ==> 200
		main() 에서 a의 값 ==> 200
		
		
  ✅ 위의 코드가 약간 헷갈려서 아래 처럼 코드 짜서 돌려봤다.

#include <stdio.h>

int main()
{
	int i = 0;
	printf("%d\n", i);

	for (int i = 1; i < 3; i++)
	{
		printf("%d\n", i);
	}

	printf("%d\n", i);
}

출력결과 :
 	    0
	    1
	    2
	    0

  🎈🎈 디버깅 해보니까 main() 함수 안의 변수 i와 for문 안의 변수 i가 다른 변수로 취급받음... wow
        두 변수의 메모리 주소가 다르기 때문이다..
 ----------------------------------------------------------
 
#include <stdio.h>    👈  🤮🤮🤮   너무 헷갈린다..

void func1(int a)
{
	printf("%d", a);
}

int func2()
{
	printf("int 형 함수에서 돌려준 값 ==> ");

	return 100;
}

int main()
{
	int a;

	func1(func2());    <-- 함수 안에서 함수를 호출

	return 0;
}

------------------------------------------------------------------

🟡 함수의 반환값과 매개변수

  --> 매개변수(媒介變數(중매 매, 낱 개, 변할 변, 셈 수)) , 영어로는 파라미터(parameter) ~!!
      
      매개하다 : 둘 사이에서 양편의 관계를 맺어 주다.  // *양편 뜻 : 두 쪽 다 원만하고 편함

     🎈🎈 C 언어로 구현된 아래의 프로그램에서, "sales_tax"는 함수의 이름이며 이 함수가 가지고 있는 "price"라는 이름의 변수가 바로 매개변수이다. 
          추가로 이 "price"라는 매개변수의 타입은 double (부동소수점)이며, 이 함수의 리턴 타입 또한 double이다.

	double sales_tax(double price)
	{
	    return 0.05 * price;
	}                                          
	
	출처: https://ko.wikipedia.org/wiki/%EB%A7%A4%EA%B0%9C%EB%B3%80%EC%88%98_(%EC%BB%B4%ED%93%A8%ED%84%B0_%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D)

---------------------------------------------------------------
🎈🎈	parameter (매개변수) : 함수와 메서드 입력 변수명
	argument (전달인자) : 함수와 메서드의 입력 값

	void func1(int a)   <-- ❗❗ 여기서 변수 a는 매개변수
	{
		printf("func1()에서 a의 값 ==> %d\n", a);
	}

	int main()
	{
		int a = 200;
		func1(a);     <-- ❗❗ 여기서 a는 인자
		printf("main() 에서 a의 값 ==> %d\n", a);
	}
---------------------------------------------------------------


🟠 반환값 유무에 따른 함수 구분
   
    --> 함수를 사용하다 보면 함수를 실행한 후 값을 돌려줄 때도 있고 그렇지 않을 때도 있다.
        값을 돌려받는 함수를 사용하는 경우에는 '돌려받을 값의 데이터형'으로 함수를 선언해야 한다.
	void 형으로 함수를 선언해야 한다.

   🔷 반환값이 있는 함수
   
     --> 함수를 실행하여 나온 결과값은 함수의 데이터형을 따른다.
         즉 'int 함수 이름 ()'으로 정의했다면 함수의 결과 역시 정수형 변수나 정숫값이어야 한다.
	 이는 'return 정수형 변수;' 또는 'return 정수;'로 표현해야 한다는 의미이다.
    

#include <stdio.h>   

int func2(int b)
{
	return 100;
}

int main()
{
	int a = 0;      <-- 초기화를 꼭 해줘야 한다. func2를 호출할 때 매개변수 b에 어떤 값을 보내줄지 정해주어야하기 때문이다.

	a = func2(a); 

	printf("%d", a);

	return 0;
}

--------------------------

#include <stdio.h>   

int func2()
{
	return 100;
}

int main()
{
	int a;

	a = func2();        <-- 이렇게 매개변수를 선언을 안해주는 것도 방법이다.

	printf("%d", a);

	return 0;
}

-------------------------------------

#include <stdio.h>   

double func2()    <-- 반환 값의 데이터 형식과 같게 해준다.
{
	return 130.35;
}

int main()
{
	double a;

	a = func2(); 

	printf("%.2lf", a);

	return 0;
}

---------------------------------------------

   🔷 반환값이 없는 함수

        --> 함수를 실행할 결과를 돌려주는 것이 없는 경우에는 함수의 데이터형을 'void'로 쓴다.

#include <stdio.h>   

void func2()
{
	printf("안녕\n");
}

int main()
{
	int a = 1;

	func2();    <-- void 함수 호출

	printf("%d", a);

	return 0;
}

------------------------------------------------

#include <stdio.h>   

void func1()
{
	printf("void 형 함수는 돌려줄게 없다.\n");
}

int func2()
{
	return 100;
}

int main()
{
	int a;

	func1();   <-- func1() 함수 호출

	a = func2();   <-- 변수 a에 func2() 함수의 반환값 대입

	printf("%d", a);

	return 0;
}

🟠 매개변수 전달 방법

   --> 매개변수를 전달할 때는 값으로 전달하는 (call by value) 방법과 주소로 전달하는 (call by reference) 방법이 있다. 

  🔷 값으로 전달 (call by value)
  
     --> 함수에 매개변수를 전달할 때 숫자나 문자 그 자체를 전달한다.
         그러면 받아들이는 함수는 그 값 자체를 받아들이는데, 원래 값을 전달한 곳에는 아무런 영향을 미치지 않는다.

#include <stdio.h>

void func1(int a)
{
	a = a + 1;
	printf("전달받은 a ==> %d\n", a);
}

int main()
{
	int a = 10;

	func1(a);
	printf("func1() 실행 후의 a ==> %d\n", a);

	return 0;
}

출력결과:
	   전달받은 a ==> 11
	   func1() 실행 후의 a ==> 10


  🔷 주소(또는 참조)로 전달 (call by reference)


#include <stdio.h>

void func1(int *a)
{
	*a = *a + 5;
	printf("전달받은 a ==> %d\n", *a);
}

int main()
{
	int a = 10;

	func1(&a);
	printf("func1() 실행 후의 a ==> %d\n", a);

	return 0;
}


출력결과:
	    전달받은 a ==> 15
	    func1() 실행 후의 a ==> 15
--------------------------------------------------

#include <stdio.h>

int func1(int *a,int *b)
{
	*a = *a + 5;
	*b = *b + 10;
	int sum = *a + *b;

	printf("전달받은 a ==> %d\n", *a);
	printf("전달받은 b ==> %d\n", *b);

	return sum;
}

int main()
{
	int a = 10;
	int b = 20;
	int c;

	c = func1(&a, &b);
	printf("func1() 실행 후의 a ==> %d\n", a);
	printf("func1() 실행 후의 b ==> %d\n", b);
	printf("합: %d\n", c);

	return 0;
}

출력결과: 
		전달받은 a ==> 15
		전달받은 b ==> 30
		func1() 실행 후의 a ==> 15
		func1() 실행 후의 b ==> 30
		합: 45

----------------------------------

#include <stdio.h>

void func1(char a, char b)
{
	int imsi;

	imsi = a;
	a = b;
	b = imsi;
}

void func2(char* a, char* b)
{
	int imsi;

	imsi = *a;
	*a = *b;
	*b = imsi;
}

void main()
{
	char x = 'A', y = 'Z';

	printf("원래 값        : x = %c, y = %c\n", x, y);

	func1(x, y);
	printf("값을 전달한 후 : x = %c, y = %c\n", x, y);

	func2(&x, &y);
	printf("값을 전달한 후 : x = %c, y = %c\n", x, y);
}

출력결과: 
		원래 값        : x = A, y = Z
		값을 전달한 후 : x = A, y = Z
		값을 전달한 후 : x = Z, y = A
----------------------------------------------------------------------------------------------------------------------------------------------------------------

📌예제 문제풀이📌

예제 27.  맞음⭕  
#include<stdio.h>

void dan(int num)
{
	int result;

	for (int i = 1; i < 10; i++)
	{
		result = num * i;
		printf("%2d X %2d = %2d\n", num, i, result);
	}
}

int main()
{
	int num;

	printf("출력하고 싶은 단을 입력 : ");
	scanf("%d", &num);

	dan(num);

	return 0;
}



예제 28.  맞음⭕  

#include<stdio.h>
#include<string.h>

void changer(char* p, int len)
{
	int a = 'a' - 'A';
	
	for (int i = 0; i < len; i++)
	{
		if (*(p + i) >= 'a' && *(p + i) <= 'z')
		{
			*(p + i) = *(p + i) - a;
		}
		else if (*(p + i) >= 'A' && *(p + i) <= 'Z')
		{
			*(p + i) = *(p + i) + a;
		}

		printf("%c", *(p + i));
	}
}

int main()
{
	int len;
	char aa[100];

	printf("문자열을 입력<100자 이내> : ");
	scanf("%s", aa);

	printf("변환된 결과 ==> ");

	len = strlen(aa);
	changer(aa , len);

	return 0;
}

 🔻 다른 답🔻
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
