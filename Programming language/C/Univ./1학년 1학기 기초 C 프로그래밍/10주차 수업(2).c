2022. 05. 05.

🟡 스택
  
     * stack 뜻 : 쌓다, 포개다

🟠 스택의 이해
 
  --> 스택은 한쪽 끝이 막힌 터널과 같은 데이터 구조로, 가장 나중에 들어간 것이 가장 먼저 나오는 LIFO (Last In First Out) 구조로 되어 있다.
      즉, 들어가는 순서는 A -> B -> C 이지만 나오는 순서는 C -> B -> A 이다.
      
      터널 안에 자동차 3대가 들어갔을 때 다음에 들어갈 자동차의 위치를 'top'이라고 한다.
      만약 자동차 C가 빠져나간다면 top의 위치가 자동차 C로 바뀔 것이다.
      즉, top은 현재 스택에서 다음에 들어갈 데이터의 위치를 가리킨다.
      또한 데이터를 넣는 것을 '푸시(push)', 빼는 것을 '팝(pop)'이라고 한다.
      
 #include <stdio.h>

int main()
{
	char stack[5];
	int top = 0;

	char carName = 'A';
	int select = 9;

	while (select != 3)
	{
		printf("<1> 차 추가 <2> 차 빼기 <3> 끝 : ");
		scanf("%d", &select);

		switch (select)
		{
		case 1: 
			if (top >= 5)
			{
				printf("더 이상 추가 불가능!\n");
			}
			else
			{
				stack[top] = carName++;
				printf("%c차 추가!\n", stack[top]);
				top++;
			}
			break;

		case 2:
			if (top <= 0)
			{
				printf("더 이상 빼기 불가능!\n");
			}
			else
			{
				top--;
				printf("%c차 빼기!\n", stack[top]);
				stack[top] = carName--;
			}
			break;

		case 3:
			printf("종료\n");
			break;

		default:
			printf("다시 입력\n");
			break;
		}
	}

	return 0;
}


--------------------------------------------------------

        ❗❗❗❗❗❗❗  재귀 호출과 스택!!!
 
#include <stdio.h>
                          
void my_func(int);
                                                       🎈🎈 함수는 종료되어 돌아갈 때 무조건 호출 되었던 그 위치로 돌아간다.
int main()
{
	my_func(1); // my_func(1) 호출

	return 0;
}

void my_func(int n)
{
	printf("Level %d, address of variable n = %d\n", n, (int)&n);

	if (n < 4)
		my_func(n + 1);  

	printf("Level %d, address of variable n = %d\n", n, (int)&n);
}

// main() --> my_func(1) --> my_func(2) --> my_func(3) --> my_func(4) --> my_func(3) --> my_func(2) --> my_func(1) --> main()
//               n = 1         n = 2           n = 3         n = 4          n = 3           n = 2         n = 1 
//            아직 종료 X      아직 종료 X     아직 종료 X     종료 O          종료 O          종료 O        종료 O


실행결과: 
		Level 1, address of variable n = 171504992
		Level 2, address of variable n = 171504736
		Level 3, address of variable n = 171504480
		Level 4, address of variable n = 171504224
		Level 4, address of variable n = 171504224
		Level 3, address of variable n = 171504480
		Level 2, address of variable n = 171504736
		Level 1, address of variable n = 171504992
		
---------------------------------------

🟡 메모리와 주소

🟠 정수형 변수의 메모리 할당

  --> 정수형 변수를 선언하면 임의의 위치에 4바이트가 자리를 잡는다.
      변수가 위치하는 곳을 '주소'라고 하며, 변수의 주소를 알리면 변수 앞에 &를 붙인다.
      
#include <stdio.h>

int main()
{
	int a = 100;
	int b = 200;
 
	printf("%d\n", &a);        <--  변수 a의 주소를 출력
	printf("%d", &b);         <--  변수 b의 주소를 출력

	return 0;
}


🟠 정수형 배열의 메모리 할당

  -->  int aa[3] = { 10, 20, 30 }
       변수는 연속된 메모리에 할당되지 않을 수도 있지만, 배열의 경우에는 주소에 연속해서 할당되는 특징이 있다.
       
       &aa[0] = 1031
       &aa[1] = 1035
       &aa[2] = 1039
       
       그리고 배열 이름 aa는 전체 배열의 주소를 의미한다. 즉 aa는 1031 번지를 의미한다.
       이때 주의할 점은, aa[0]의 주소는 &aa[0]으로 표현하지만 
       배열 이름 aa 자체가 주소를 의미하기 때문에 배열 aa의 주소를 구할 때는 &aa와 같이 표현하지 않고 단순히 aa로 표현한다는 것이다.

#include <stdio.h>

int main()
{
	int aa[3] = { 100,200,300 };

	printf("%d\n", &aa[0]);
	printf("%d\n", &aa[1]);
	printf("%d\n", &aa[2]);
	printf("%d", aa);

	return 0;
}

출력결과: 391117432
          391117436   <-- 정수형 배열이므로 4바이트 증가
          391117440   <-- 4바이트 증가
          391117432   <-- &aa[0]과 똑같은 값을 출력
          
  ---------------------------------------------------
  
#include <stdio.h>

int main()
{
	char ss[4] = {  'A','B','C' };

	printf("%d\n", &ss[0]);
	printf("%d\n", &ss[1]);
	printf("%d\n", &ss[2]);
	printf("%d", ss);              <-- %d를 %s로 바꾸면 "ABC"로 출력한다.

	return 0;
}          
          
출력결과: 857536004  
          857536005   <-- 문자형 배열이므로 1바이트 증가
          857536006   <-- 1바이트 증가
          857536004   <-- &ss[0]과 같은 값을 출력
          
          
          🎈🎈 배열 이름은 변수가 아닌 주소 자체이다...!!
          
                             aa+1에서 +1은 단순히 1을 더하라는 의미가 아니라 '배열 aa의 위치에서 한 칸 건너뛰라'는 의미이다.
#include <stdio.h>

int main()
{
	int aa[4] = { 100,200,300 };

	printf("%d\n", &aa[0]);
	printf("%d\n", &aa[1]);
	printf("%d\n", &aa[2]);
	printf("%d\n", aa);             
	printf("%d\n", aa + 1);    <-- &aa[1] 와 aa+1은 같은 값을 가진다.   // &aa[x] 와 aa+x 는 동일한 주소이다.
	printf("%d\n", aa + 2);    <-- &aa[2] 와 aa+2는 같은 값을 가진다.

	return 0;
}

출력결과: 1944057160
          1944057164
          1944057168
          1944057160
          1944057164
          1944057168

--------------------------------------------------------------------------------------------------------------------------------------------------------

대망의..

🟡 포인터

  --> 정수형 변수 a에는 당연히 정수가 들어간다. 또한 문자형 변수 ch에는 문자가 들어간다. 그럼 포인터 변수 p에는 무엇이 들어갈까?
      바로 변수의 주소가 들어간다.

🟠 정수형 변수의 메모리 할당

       🎈🎈 주의사항
	1. 포인터 변수를 선언하려면 변수형에 *를 붙인다. 즉 int*, char*, float*와 같이하면 포인터 변수가 된다.
	   int*는 정수형 포인터 변수, char*은 문자형 포인터 변수, float*는 실수형 포인터 변수이다.
	
	2. char*p;로 선언하면 p에 문자형 변수의 주소값을 넣어야 하고 int* p;로 선언하면 p에 정수형 변수의 주솟값을 넣어야 한다.
	   간혹 실수로 데이터 형식을 통일하지 않고 사용할 때가 있다.
	   이런 경우 문법적으로는 이상이 없으므로 컴파일이 되지만 논리적으로는 틀리니 주의해야한다.
	   
	   -->  #include <stdio.h>
 
		int main()
		{
			int a;
			char* p;

			p = &a;      <-- 정수형 변수 a의 주소를 문자형 포인터 변수 p에 대입.
			*p = 10;     <-- 포인터 변수 p에 10대입, a에 10 대입이 된거나 마찬가지.

			printf("%d", a);        출력결과: -858993654   <-- 이렇게 데이터 형식을 통일하지 않아서 쓰레기 값이 나오게 된다.
                                                                           데이터 형식을 통일하면 제대로 출력된다.
			return 0;
		}	

------------------------------------------------------------

#include <stdio.h>
 
int main()
{
	char ch;
	char* p;
	int i;
	int k;

	ch = 'A';
	k = 65;
	p = &ch;
	i = &ch;

	printf("%d\n", ch);
	printf("%c\n", ch);
	printf("%d\n", k);
	printf("%c\n", k);
	printf("%d\n", p);
	printf("%d\n", i);
	printf("%d\n", *p);
	printf("%c\n", *p);

	return 0;
}		

출력결과: 
		65
		A
		65
		A
		443545508
		443545508
		65
		A		
		
----------------------------------------------------------

#include <stdio.h>
 
int main()
{
	char ch;
	char* p;
	char* q;

	ch = 'A';   --> 문자형 변수 ch에 'A' 대입
	p = &ch;    --> 변수 p에 ch 주소 대입

	q = p;      --> 변수 q에 p의 값 대입

	*q = 'Z';   --> 변수 q가 가르키는 주소에 'Z'대입,  변수 q가 가르키는 주소가 문자형 변수 ch의 주소이므로 변수 ch에 'Z'대입

	printf("ch => %c", ch);  --> 'Z' 

	return 0;
}					

출력결과: 
	   ch => Z
------------------------------------------------------------

#include <stdio.h>

// 두 변수의 값을 서로 변환하는 포인터 함수
void swap(int* a, int* b)   // 변수 a에는 변수 x의 주소 값이 넣어지고, 변수 b에는 변수 y의 주소 값이 넣어진다.
{
    int temp;
    temp = *a;   // 변수 temp에 (변수 a는 주소이고, *a는 그 주소의 값이다. 따라서 *a는 1이다.) *a의 값이 넣어진다.
    *a = *b;     // 위와 마찬가지로 *a에 *b의 값인 2가 넣어진다.
    *b = temp;   // 마지막으로 *b에 변수 temp의 값이 넣어진다.
}                // 여기까지 포인터를 활용하여 변수에 값을 넣은 것을 넘어서, 메모리의 한 주소에 각각 값을 넣어줬다.

// 포인터를 사용하면 swap 함수가 종료되면서 swap 함수 안에서 선언되었던 변수들이 끝나는 것이 아니라,
// 포인터를 사용함으로써 main 함수에 까지 그 영향을 끼칠 수 있게 된다.

int main()
{
    int x = 1;
    int y = 2;

    swap(&x, &y);     // swap 함수의 *a와 *b에 각각 변수 x의 주소 값과 변수 y의 주소 값을 넣어준다. 그리고 swap 함수의 실행 값을 받는다.

    printf("x = %d\ny = %d", x, y);  // 변수 x에 2가 들어가있고, 변수 y에는 1이 들어가있다.

    return 0;
}

출력결과:
	   x = 2
	   y = 1
	   
----------------------------------------------------------

#include <stdio.h>

int main()
{
    int i = 10;
    int* p;
    p = &i;
    printf("*p = %d\n", *p);
    printf("i = %d\n", i);
    *p = 20;
    printf("*p = %d\n", *p);
    printf("i = %d\n", i);

    return 0;
}

출력결과:
             *p = 10
	      i = 10
             *p = 20
	      i = 20

-----------------------------------------------
	      
  ✅ 책에서는 포인터 변수의 크기는 4바이트라고 설명했다. 하지만 내 컴파일러는 포인터 변수의 크기를 8바이트로 나타냈다.
      이에 대해 찾아봤다.
  
1. 포인터 변수의 크기는 4바이트로 고정된 것이 아니다.
2. 운영체제의 bit수가 포인터 변수의 크기에 영향을 미치는 것은 아니다.
3. 포인터 변수의 크기(double *,char *, int*)의 크기는 컴파일러의 상황에 따라 다르다
-32bit로 컴파일 시, 4바이트로 모두 같고
-64bit로 컴파일 시, 8바이트로 모두 같다.
 
 
4. 64bit의 운영체제에서 32bit로 컴파일 시 포인터변수의 크기가 4바이트로 나타난다.

5. 64bit의 운영체제에서 64bit로 컴파일 시 포인터변수의 크기가 8바이트로 나타난다.

  <-운영체제에 따라 포인터변수의 크기가 정해지는 것이 아님
  
    					               출처: https://m.blog.naver.com/123gtf/220905979083

#include <stdio.h>
 
int main()
{
	int* p;
	double* a;
	short* b;
	char* c;

	int i = sizeof(*p);   
	int j = sizeof(*a);
	int k = sizeof(*b);
	int t = sizeof(*c);

	int y = sizeof(p);
	int z = sizeof(a);
	int w = sizeof(b);
	int x = sizeof(c);

	printf("%d\n", i);
	printf("%d\n", j);
	printf("%d\n", k);
	printf("%d\n", t);

	printf("\n");

	printf("%d\n", y);
	printf("%d\n", z);
	printf("%d\n", w);
	printf("%d\n", x);

	return 0;
}					

출력결과: 
		4
		8
		2
		1

		8
		8
		8
		8
		
----------------------------------------------------------

🟡 배열과 포인터의 관계

🟠 문자형 배열과 


#include <stdio.h>

int main()
{
	char ch[4] = "ABC";
	char* p;

	p = ch;

	printf("%d\n", p);       -->  주소 출력
	printf("%d\n", ch);      -->  주소 출력
							//printf("%s\n", *p);    <<>>    printf("%s\n", ch[0]); <-- 이게 안되는거랑 같은 느낌. 
							//printf("%s\n", *p + 1);
	printf("%s\n", p);       --> "ABC" 출력
	printf("%s\n", ch);      --> "ABC" 출력
	printf("%s\n", &ch[0]);  --> "ABC" 출력

	printf("%s\n", p + 1);    --> "BC" 출력
	printf("%s\n", ch + 1);   --> "BC" 출력
	printf("%s\n", &ch[1]);   --> "BC" 출력

	printf("%s\n", p + 2);    --> "C" 출력
	printf("%s\n", ch + 2);   --> "C" 출력
	printf("%s\n", &ch[2]);   --> "C" 출력

	printf("%s\n", p + 3);    --> '\0' 출력
	printf("%s\n", ch + 3);   --> '\0' 출력
	printf("%s\n", &ch[3]);   --> '\0' 출력

	printf("%c\n", *p);          --> 'A' 출력
	printf("%c\n", ch[0]);       --> 'A' 출력
	printf("%c\n", *(ch + 0));   --> 'A' 출력

	printf("%c\n", *(p + 1));     --> 'B' 출력
	printf("%c\n", ch[1]);        --> 'B' 출력
	printf("%c\n", *(ch + 1));    --> 'B' 출력
 
	printf("%c\n", *(p + 2));    --> 'C' 출력
	printf("%c\n", ch[2]);       --> 'C' 출력
	printf("%c\n", *(ch + 2));   --> 'C' 출력

	printf("%c\n", *(p + 3));    --> '\0' 출력
	printf("%c\n", ch[3]);       --> '\0' 출력
	printf("%c\n", *(ch + 3));   --> '\0' 출력

	printf("끝\n");

	return 0;
}

---------------------------------------------------------------------

  ✅ 포인터 상수와 포인터 변수!!!!!!
  
  -->  포인터는 가르키는 값의 메모리 주소값을 가진다.
       포인터는 크게 포인터 상수와 포인터 변수로 나눈다.
       
       포인터 상수에는 문자열 상수, 배열 이름, 함수 이름이 해당된다.
       포인터 상수는 포인터 변수와 다르게 저장된 값을 변경할 수 없다. (실행시 주소값이 자동으로 저장)
       
       변경하고 싶으면 포인터 상수를 포인터 변수에 저장하고, 포인터 변수를 변경하면 된다.
       
       
  🎈🎈 char a[] 와 char* a는 같지 않다!!
       
       char a[4] = "ABC";
       char* p;
       p = a;
        
       a는 포인터 상수.  a는 메모리의 주소, 그 자체를 나타낸다.
       
       p는 포인터 변수이다. 포인터 변수 p에 a를 대입해주면 p에는 a의 값, 즉 배열의 주소가 들어가고
       다른 배열을 선언하고, 그 배열을 대입하면 그 배열의 주소가 들어가게 된다.
	 
 												출처: https://sessionk.tistory.com/163


#include <stdio.h>

int main()
{
    int i[3] = { 100,200,300 };
    int* p;

    p = i;

    printf("%d\n", *p);
    printf("%d\n", *p + 1);            <-- 101 출력   // *p의 값이 100이므로 거기에 1을 더하면 101
    printf("%d\n", *(p + 1));          <-- 200 출력

    return 0;
}


🟠 문자형 배열과 포인터의 응용


#include <stdio.h>
                                                                   
int main()
{
	char s[8] = "Basic-C";
	char* p;
	int i;

	p = s;

	for (i = sizeof(s) - 2; i >= 0; i--)  // 
	{
		printf("%c", *(p + i));
	}

	return 0;
}
                                        ✅ 널문자는 어떡하지? 라고 생각했었다. 근데 그저 문자를 출력하는 것이기 때문에 널문자를 신경쓰지 않아도 된다.
                       


🟠 포인터 학습 노하우

  1. 포인터 변수가 무엇을 가르키는지 확인한다.
  
  2. 포인터 변수를 선언할 때는 변수 앞에 *만 붙이면 된다.
  
  3. 포인터 변수에는 꼭 주소값을 넣어줘야 한다. ✔✔✔
  
  4. 포인터가 가르키는 곳의 실제 값을 구하려면 *를 붙인다.

