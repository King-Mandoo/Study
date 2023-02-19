2022.03.10 수업

#include <stdio.h>  //standard input ouput

int main()                                         --> int main() 과 int main(void)와 같다는 것을 이제 알았다.                      ❓❓ >> void 뜻: 빈, 없는
{
	int a, b;        // 변수 a,b 선언
	int result;      // 결과값을 담을 변수 result 선언

	a = 100;         // 변수 a에 100을 넣음
	b = 50;          // 변수 b에 50을 넣음

	result = a + b;
	printf("%d+%d=%d\n", a, b, result); // <stdio.h> 안에 printf가 포함됨 그래서 사용 가능

	result = a - b;
	printf("%d-%d=%d\n", a, b, result);

	result = a * b;
	printf("%d*%d=%d\n", a, b, result);

	result = a / b;
	printf("%d/%d=%d\n", a, b, result);
}

// 주석!

// 주석222

/*  주석!!  */

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>  //standard input ouput

int main()
{
	int a, b;        
	int result;      

	printf("a = ");                                                                      -->  scanf()를 사용해도 됨. 그치만.
	scanf_s("%d", &a);    // 굳이 \n을 넣지 않아도 enter키를 누르기 때문에 줄이 바뀜              scanf()_s에 대한 설명은 책 p.60 쪽에 자세히 설명이 나와있다.
	printf("b = ");                                                      
	scanf_s("%d", &b);              ❓❓ >> & 연산자는 피연산자의 주소값을 반환하는 연산자이다. & 연산자는 변수의 앞에 사용하게 된다.   b라는 변수의 주소값에 값을 대입한다.
                             
                                        💥  3 + 7  -->  3과 7은 피연산자, +는 연산자
                                
	result = a + b;
	printf("%d + %d = %d\n", a, b, result); 

	result = a - b;
	printf("%d - %d = %d\n", a, b, result);

	result = a * b;
	printf("%d * %d = %d\n", a, b, result);

	result = a / b;
	printf("%d / %d = %d\n", a, b, result);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   
📌예제 문제풀이📌
   
1번. 틀림❌                                      이유: 1. scanf_s는 출력하는 함수가 아니다. scanf_s("%d", &a);로 고치고 값을 입력하라는 문구는 printf() 함수로 따로 입력해줘야한다.
                                                       2. 모든 변수의 합을 나타내는 변수 sum의 위치도 틀렸다. 입력을 받고 변수를 설정해야하는데 입력 받기전에 sun을 설정했다.
#include <stdio.h>  

int main()
{
	int a, b, c, d;
	int sum; 
	sum = a + b + c + d;

	scanf_s("첫 번째 계산할 값을 입력하세요 ==> %d", &a);     
	scanf_s("두 번째 계산할 값을 입력하세요 ==> %d", &b);       
	scanf_s("세 번째 계산할 값을 입력하세요 ==> %d", &c);
	scanf_s("네 번째 계산할 값을 입력하세요 ==> %d", &d);

	printf("%d + %d + %d = %d\n", a, b, c, d, sum);
	
}

🔻고친 답🔻

#include <stdio.h>  

int main()
{
	int a, b, c, d;
	int sum;

	printf("첫 번째 계산할 값을 입력하세요 ==> ");
	scanf_s("%d", &a);
	printf("두 번째 계산할 값을 입력하세요 ==> ");
	scanf_s("%d", &b);
	printf("세 번째 계산할 값을 입력하세요 ==> ");
	scanf_s("%d", &c);
	printf("네 번째 계산할 값을 입력하세요 ==> ");
	scanf_s("%d", &d);

	sum = a + b + c + d;

	printf("%d + %d + %d = %d\n", a, b, c, d, sum);
	
}

2번. 맞음⭕
#include <stdio.h>

int main(void)
{
	int a, b;
	int result;
	int k;

	printf("첫 번째 숫자를 입력하세요 ==> ");
	scanf_s("%d", &a);

	printf("<1>덧셈 <2>뺄셈 <3>곱셈 <4>나눗셈 ==> ");
	scanf_s("%d", &k);

	printf("두 번째 숫자를 입력하세요: ");
	scanf_s("%d", &b);

	if (k == 1)
	{
		result = a + b;
		printf("%d + %d = %d", a, b, result);
	}
	if (k == 2)
	{
		result = a - b;
		printf("%d - %d = %d", a, b, result);
	}
	if (k == 3)
	{
		result = a * b;
		printf("%d * %d = %d", a, b, result);
	}
	if (k == 4)
	{
		result = a / b;
		printf("%d / %d = %d", a, b, result);
	}
}

3번. 애매함❗❓

*내 답.

#include <stdio.h>

int main(void)
{
	int a, b;
	int result;
	int k;

	printf("첫 번째 숫자를 입력하세요 ==> ");
	scanf_s("%d", &a);

	printf("<1>덧셈 <2>뺄셈 <3>곱셈 <4>나눗셈 ==> ");
	scanf_s("%d", &k);

	printf("두 번째 숫자를 입력하세요: ");
	scanf_s("%d", &b);

	if (k == 4 && b == 0)
	{
		printf("0으로 나누면 안됩니다.");
	}

	if (k == 1)
	{
		result = a + b;
		printf("%d + %d = %d", a, b, result);
	}
	if (k == 2)
	{
		result = a - b;
		printf("%d - %d = %d", a, b, result);
	}
	if (k == 3)
	{
		result = a * b;
		printf("%d * %d = %d", a, b, result);
	}
	if (k == 4)
	{
		result = a / b;
		printf("%d / %d = %d", a, b, result);
	}
}

*답지.       <-- 책 한번 봐야됨 책이랑 다름 지금 이 답 내가 작성한거임. 책에 표시해둠 한번 질문 기회 생기면 해보셈  p.67

#include <stdio.h>

int main(void)              //책에 오류가 있는 거 같음. 아님 내가 모르거나 
{
	int a, b;
	int result;
	int k;

	printf("첫 번째 숫자를 입력하세요 ==> ");
	scanf_s("%d", &a);

	printf("<1>덧셈 <2>뺄셈 <3>곱셈 <4>나눗셈 <5>나머지 ==> ");
	scanf_s("%d", &k);

	printf("두 번째 숫자를 입력하세요: ");
	scanf_s("%d", &b);

	if (k == 1)
	{
		result = a + b;
		printf("%d + %d = %d", a, b, result);
	}
	if (k == 2)
	{
		result = a - b;
		printf("%d - %d = %d", a, b, result);
	}
	if (k == 3)
	{
		result = a * b;
		printf("%d * %d = %d", a, b, result);
	}
	if (k == 4)
	{
		if (b != 0)
		{
			result = a / b;
			printf("%d / %d = %d", a, b, result);
		}
		else
		{
			printf("0으로 나누면 안됩니다.\n");
		}
	}
	if (k == 5)
	{
		if (b != 0)
		{
			result = a % b;
			printf("%d %% %d = %d", a, b, result);
		}
		else
		{
			printf("0으로 나누면 나머지 값이 안됩니다.\n");
		}
	}
}

