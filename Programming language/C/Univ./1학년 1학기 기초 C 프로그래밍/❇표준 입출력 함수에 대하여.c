#include <stdio.h>

int main()
{
	char c;

	while ((c = getch()) != '.')
	{
		putchar(c);  
	}
}
                
   ✅ Q. 왜 백스페이스나 엔터를 누르면 바로 진행이 되는 가?
	   
       A. getch() 함수나 getche() 함수는 버퍼를 사용하지 않는다. 
	  입력 받는 즉시 바로 출력을 하기 때문에 백스페이스나 엔터키 또한 바로 입력한다.
	   
	  엔터 키를 누르면 커서가 다음 줄로 넘어가는 것이 아니라 첫 번째 글자 아래에 위치한다.
	  그건 \r(캐리지 리턴)으로 커서를 현재 행의 처음 위치로 돌리기 때문이다.
	   
	  🎈🎈 getch()와 getche() 함수는 엔터값을 '\r'로 인지한다.
	   
	   while ((c = getch()) != '\r')
	 	putchar(c);             <-- 만약 엔터 입력시 종료를 하고 싶다면 조건문을 저렇게 수정하면 된다.

           여기서 생기는 또하나의 궁금증.. 
		   
		   그럼 getch() 와 getche() 함수는 '\n'을 입력하지 못하는 것인가???
		   
		   int main()
		  {
			char c;
	
			 while ((c = getch()) != '\r')
			{
		             putchar(c);  
			     putchar('\n');  <-- 이렇게 하면 다음 줄로 넘어갈 수 있기는 한데..
			}
		  }
		   
		   
----------------------------------------------------

#include <stdio.h>

int main()
{
	char c;

	while ((c = getchar()) != EOF)   // End OF Fil  (ctrl + z 누르면 종료)
	{
		putchar(c);     
		// printf("\n");   <-- 이걸 통해 입력버퍼 안의 값이 한꺼번에가 아닌 while문을 돌면서 차례로 출력된다는 것을 알 수 있음.
	}
}

     ✅ Q. 문자형 c를 입력 받았다. 그런데 출력의 형태는 문자형이 아니라 문자열 형태로 나온다.
	    이 말은 즉슨 c 안에 그 수많은 문자들이 한꺼번에 저장이 가능하다는 건데.. 그럼 배열을 쓸 이유가 있나?
	     
	 A. 문자형 변수 c 안에 문자들이 한꺼번에 저장되는 것이 아니다.
	    getchar() 함수를 이용해 "ABC"를 입력을 했다고 가정해보자.
	    그러면 입력 버퍼에 "ABC" 글자가 들어가게 된다. 그리고 putchar(c)를 통해서 처음에 입력 받은 문자 'A'가 출력된다.
	    그다음 다시 while문의 조건문으로 들어가지만 입력버퍼에 문자들이 이미 채워져 있는 상태이므로
	    getchar() 함수가 실행되지 않은 채 아래의 putchar() 함수를 실행시킨다. 그렇게 문자 'B'가 출력되고 이와 같은 방식으로 'C'까지 출력이 된다.
	    마지막에 Enter를 쳤으므로 버퍼에 Enter까지 들어가 있으므로 마지막에 '\n'을 실행시키면서 getchar() 함수가 종료된다.
	     
	     getchar() 함수는 '\n'에 의해 종료가 인식된다.
	     이 말은 '\n'를 만나기 전 까지는 종료하지 않는다는 말 인데..
	     
	     여기에서 "조건문에서 getchar() 함수를 만난다면 버퍼에 문자가 남아있든 말든 다시 실행시켜야 하는 것이 아닌가?" 라는 의문이 든다.
	     하지만 getchar() 함수가 종료되지 않아서 실행할 수 없는 거라면?
	     그래서 이전에 실행되었던 getchar() 함수에 의해 입력된 버퍼가 종료되어야만 다음 입력을 받을 수 있는 거라면?
	     
	     그래서 "ABC"를 입력을 해준다고 해도
	     'A'만 출력하고 while문의 조건식 안의 getchar() 함수를 다시 실행시키는 것이 아니라
	     이미 버퍼에 채워져있던 나머지 문자까지 차례로 내보내준다음 입력버퍼를 종료시킨 후 다시 실행시키는 거라면? 

	     아래에 설명이 있다.

	     
#include <stdio.h>
void main()
{
	char tmp;

	while ((tmp = getchar()) != '\n')
	{
		putchar(tmp);
	}

	printf("\n종료됨\n");			// 반복문 탈출
}


while문의 종료 조건을 자세히 보자. '\n' 과 비교하고 있다.

즉, \n 값이 들어오면 반복문을 종료 하라는 의미가 된다.

실행결과:
		test
		test
		종료됨

아래 화면에서 보면 test가 두번 찍힌 것을 알 수 있다.이유가 뭘까 ? 첫번째 test는 내가 입력하면서 적힌 내용이다.

test를 입력하고 엔터를 치면, while문의 getchar() 에 의해서 test라는 글자가 입력 버퍼로 들어감. (때문에 화면에 test가 남음)


그럼과 동시에 첫 글자인 t가 tmp에 들어가고 putchar(tmp)에서 t를 출력한다.

이게 두번째 줄의 t 이다.그리고는 다시 getchar()을 실행 하는데,

입력버퍼에 아까 입력한 값이 남아 있으므로 더 이상 값을 입력 받지 않고
est 중에서 첫번째 글자인 e 를 tmp에 저장하고 putchar(tmp)로 출력.

이를 반복해서 test 가 찍히고 마지막으로 엔터 입력으로 들어간 \n 가 빠져나오면서
조건문과 비교해 \n 이므로 탈출하게 되는 것.
	
											출처: https://kcoder.tistory.com/43 [K_Coder(転職資料):티스토리] 


----------------------------------------------------
 
#include <stdio.h>

int main()
{
	char c;

	while (1)
	{
		c = getchar();
		printf("%d\n", c);    // 문자를 입력 받고 그대로 아스키 코드를 출력한다.
		if (c == EOF)
			break;
	}
}

----------------------------------------------------

#include <stdio.h>

int main()
{
	char c;

	while (1)
	{
		scanf("%c", &c);
		printf("%d\n", c);    // 문자를 입력 받고 그대로 아스키 코드를 출력한다.
		if (c == EOF)
			break;
	}
}

-------------------------------------------------
	
	#include <stdio.h>

int main()
{
	int count = 0;
	
	while (1) {
		printf("Current count is %d (Continue? Y / N) \n", count);

		if (getchar() == 'N')
			break;

		while (getchar() != '\n')     // 버퍼를 
			continue;

		count++;

	}

	return 0;
}




#include <stdio.h>

int main()
{
	int count = 0;
	
	while (1) {
		printf("Current count is %d (Continue? Y / N) \n", count);

		int YorN = getchar();

		if (YorN == 'N' || YorN == 'n')    // 이렇게 가능
			break;

		while (getchar() != '\n')
			continue;

		count++;

	}

	return 0;
}

-----------------------------------------------------
#include <stdio.h>

void display(char cr, int lines, int width)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < width; j++)
		{
			/*printf("%c", cr);*/
			putchar(cr);
		}
		/*printf("\n");*/
		putchar('\n');
	}
}

int main()         // 결국 중요한건 scanf() 함수도 버퍼를 사용하기 때문에 '\n' 까지도 버퍼 안에 있다는 것을 알아야한다.
{                // 그리고 버퍼를 초기화 하는 방법 또한 알고 있어야 한다.
	char c;
	int rows, cols;

	while (1)
	{
		scanf("%c %d %d", &c, &rows, &cols);

		while (getchar() != '\n') continue;    // 이렇게 버퍼를 초기화 한다.
		 
		display(c, rows, cols);
		
		if (c == '\n')
			break;
	}

	return 0;
}











#include <stdio.h>

void display(char cr, int lines, int width)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < width; j++)
		{
			/*printf("%c", cr);*/
			putchar(cr);
		}
		/*printf("\n");*/
		putchar('\n');
	}
}

int main()         // 결국 중요한건 scanf() 함수도 버퍼를 사용하기 때문에 '\n' 까지도 버퍼 안에 있다는 것을 알아야한다.
{                // 그리고 버퍼를 초기화 하는 방법 또한 알고 있어야 한다.
	char c;
	int rows, cols;

	while ((c = getchar()) != '\n')     <-- 이 방법을 사용하면 enter 키를 눌렀을 때 바로 종료가 되도록 해줄 수 있음.
	{
		scanf("%d %d", &rows, &cols);

		while (getchar() != '\n') continue;    // 이렇게 버퍼를 초기화 한다.
		 
		display(c, rows, cols);
	}

	return 0;
}
