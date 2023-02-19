2022. 04. 07. 

🟡 if문

🟢 기본 if문

 >>     if (조건식)
          실행할 문장;
          


#include <stdio.h>

int main()
{
	int a = 200;

	if (a < 100)
		printf("100보다 작군요..\n");                     <-- if 문에서 두 문장 이상을 실행하고 싶다면 여러 개의 구문을 하나로 만드는 블록 {} 을 사용해야 한다.
		printf("거짓이므로 앞의 문장은 안보이겠죠?\n");
    
	printf("끝~!");
}                                                           출력결과:   거짓이므로 앞의 문장은 안보이겠죠?
                                                                         끝~!

          
    ------------------------------------------------------------------------------------------------------------------------------------      
          
                    
#include <stdio.h>

int main()
{
	int a = 200;

	if (a < 100)                                                <-- a가 200보다 작으므로 if문이 실행되지 않음..!
	{                                                               따라서 "끝~!" 만 출력된다.
		printf("100보다 작군요..\n");
		printf("거짓이므로 앞의 문장은 안보이겠죠?\n");
	}

	printf("끝~!");
  
  
                                 출력결과:   끝~!
  
  
}


        ------------------------------------------------------------------------------------------------------------------------------------


🟢 if ~ else문


  if (조건식)
    실행할 문장 1;
  else
    실행할 문장 2;




#include <stdio.h>

int main()
{
	int a = 200;

	if (a <	100)
	{
		printf("100보다 작군요..\n");
	}
	else
	{
		printf("100보다 크거나 같군요..\n");
	}

	printf("끝~!");
}                                             출력결과: 100보다 크거나 같군요..
                                                        끝~!


          ------------------------------------------------------------------------------------------------------------------------------------
 
 
🟡 중첩 if



#include <stdio.h>

int main()
{
	int a;

	printf("점수를 입력하세요: ");
	scanf("%d", &a);

	if (a >= 90)
	{
		printf("A");
	}
	else
	{
		if (a >= 80)
		{
			printf("B");
		}
		else
		{
			if (a >= 70)
			{
				printf("C");
			}
			else
			{
				if (a >= 60)
				{
					printf("D");
				}
				else
				{
					printf("F");
				}
			}
		}
	}

	printf(" 학점.");

	return 0;
}


-----------------------------------------------------------------------------------------------------------------------------------------------------------


#include <stdio.h>

int main()
{
	int a;

	printf("점수를 입력하세요: ");
	scanf("%d", &a);

	if (a >= 90)
	{
		printf("A");
	}
	else if (a >= 80)            <-- else if 문을 활용하여 더 간략하게 줄일 수 있다.
	{
		printf("B");
	}
	else if (a >= 70)
	{
		printf("C");
	}
	else
	{
		printf("Fail");
	}

	printf(" 학점.");

	return 0;
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------

🟡 switch ~ case문

-->  swtich의 조건값(정숫값)에 따라 case문을 실행한다. 즉 정숫값이 1이면 1의 값에 해당하는 문장,
     정숫값이 2이면 2의 값에 해당하는 문장을 실행한다.

 switch(정숫값)
 {
    case 정숫값 1:
      실행할 문장 1;
      break;
    case 정숫값 2:
      실행할 문장 2;
      break;
    default:
      실행할 문장 3;
      break;
 }

        -------------------------------------------------------------------------------------
        
 
#include <stdio.h>

int main()
{
	int a;
	printf("1~4 숫자를 입력하세요.\n");
	scanf("%d", &a);

	switch (a)
	{
	case 1:
		printf("1을 선택");
		break;
	case 2:
		printf("2를 선택");
		break;
	case 3:
		printf("3을 선택");
		break;
	case 4:
		printf("4를 선택");
		break;
	default:                             <-- a가 1,2,3,4 중 어디에도 해당되지 않을 때 수행한다.
		printf("1~4 숫자만 입력..!!");
	}
}



✅ break 문을 안써주면 어떻게 될까?

#include <stdio.h>

int main()
{
	int a;
	printf("1~4 숫자를 입력하세요.\n");
	scanf("%d", &a);

	switch (a)
	{
	case 1:
		printf("1을 선택");
		break;
	case 2:
		printf("2를 선택\n");
	
	case 3:
		printf("3을 선택\n");
		
	case 4:
		printf("4를 선택\n");
		
	default:
		printf("1~4 숫자만 입력..!!\n");
	}
}

출력결과:    1~4 숫자를 입력하세요.
            2                                 <-- 2를 입력하고 case 2의 아래의 모든 case들이 실행된다.
            2를 선택
            3을 선택
            4를 선택
            1~4 숫자만 입력..!!


------------------------------------------------------------------------------------



#include <stdio.h>

int main()
{
	int year;

	printf("출생년도를 입력하세요: ");
	scanf("%d", &year);

	switch(year % 12)        <--- 이렇게 계산을 입력할 수도 있음.
	{
		case 0: printf("원숭이띠\n"); break;
		case 1: printf("닭띠\n"); break;
		case 2: printf("개띠\n"); break;
		case 3: printf("돼지띠\n"); break;
		case 4: printf("쥐띠\n"); break;
		case 5: printf("소띠\n"); break;
		case 6: printf("호랑이띠\n"); break;
		case 7: printf("토끼띠\n"); break;
		case 8: printf("용띠\n"); break;
		case 9: printf("뱀띠\n"); break;
		case 10: printf("말띠\n"); break;
		case 11: printf("양띠\n"); break;
	}
}



----------------------------------------------------------------------------------------------------------------------------------------------------------------

📌예제 문제풀이📌


예제 11.  애매함❗❓

#include <stdio.h>

int main()
{
	int num1;
	int num2;
	char op;

	printf("첫 번째 숫자를 입력하세요 : ");
	scanf("%d", &num1);
	printf("계산할 연산자를 입력하세요 : ");
	scanf(" %c", &op);                                <--🎈🎈 A. 왜 " %c" 처럼 앞에 한칸을 띄어야 할까?
	printf("두 번째 숫자를 입력하세요 : ");
	scanf("%d", &num2);

	if (op == '+')
	{
		printf("%d + %d = %d", num1, num2, num1 + num2);
	}
	else if (op == '-')
	{
		printf("%d - %d = %d", num1, num2, num1 - num2);
	}
	else if (op == '*')
	{
		printf("%d * %d = %d", num1, num2, num1 * num2);
	}
	else if (op == '/')
	{
		printf("%d / %d = %.2f", num1, num2, num1 / (float)num2);     <-- 답지에서 이렇게 강제형변환을 활용하여, 출력값을 실수 형태로 나올 수 있게 했길래 나도 이렇게 써봤다.
	}
	else if (op == '%')
	{
		printf("%d %% %d = %d", num1, num2, num1 % num2);
	}
	
	return 0;
}


✅ 위의 질문에 대한 답. 

키보드로 입력한 값은 입력 스트림이라는 곳에 저장이 되고, scanf 함수는 입력 스트림에서 값을 읽어옵니다.

이 때, scanf 함수는 %d 또는 %f 같은 포맷형식을 참고해서 입력 스트림에서 그에 맞는 형태의 값을 읽어 드립니다. 
그런데 %c 같은 경우에는 입력 스트림에서 문자 하나를 그냥 가져 옵니다.

작성하신 코드에서 문제가 뭐냐하면 scanf("%f", &b);에서 사용자가 실수값을 치고 엔터키를 누를텐데, 이 때 실수값과 엔터값(줄바꿈값, '\n')이 입력 스트림에 저장됩니다. 
그리고 "%f"로 해석하여 입력 스트림안에서 실수형태의 값을 가져다가 b에 저장합니다. 이러고 나면 입력 스트림에는 엔터값(줄바꿈값, '\n')이 남아 있는 상태입니다.

이 상태에서 scanf("%c", &c1);이 실행되는 순간 입력스트림에 남아 있던 '\n'이 c1에 저장되고 scanf 함수가 종료되게 됩니다.

그래서 이러한 문제를 피하기 위해서는 "%c"라고 쓰지 말고, 앞에 공백을 하나 넣어서 " %c"로 하는 것을 공식 문서 등에서 추천하고 있습니다.
이렇게 공백 하나를 넣게되면 입력 스트림속에있는 스페이스나 줄바꿈, 탭 등을 저 공백하나가 흡수하게 되고 그러한 문자 뒤의 실제 글자 하나를 받아 들이게 됩니다.

설명이 길었는데, 사용자의 입력을 얻는 경우라면 "%c"를 습관적으로 " %c"의 형태로 사용하시면 됩니다.

출처: https://hashcode.co.kr/questions/12755/c%EC%96%B8%EC%96%B4-%EB%A7%89-%EC%8B%9C%EC%9E%91%ED%95%9C-%EC%B4%88%EB%B3%B4%EC%9E%90%EC%9E%85%EB%8B%88%EB%8B%A4-%EC%A0%95%EC%88%98%EC%99%80-%EC%8B%A4%EC%88%98%EA%B9%8C%EC%A7%80%EB%8A%94-%EC%9E%85%EB%A0%A5%EC%9D%B4-%EB%90%98%EB%8A%94%EB%8D%B0-%EB%AC%B8%EC%9E%90%EB%A5%BC-%EB%B0%94%EB%A3%8C-%EC%9E%85%EB%A0%A5-%EC%95%88%EB%B0%9B%EA%B3%A0-%EB%84%98%EC%96%B4%EA%B0%80%EB%B2%84%EB%A6%BD%EB%8B%88%EB%8B%A4-%EC%9D%B4%EC%9C%A0%EA%B0%80-%EB%AD%98%EA%B9%8C%EC%9A%94

---------------------------------

위의 설명에 따르면

#include <stdio.h>

int main()
{
	int num1;
	int num2;
	char op;


	printf("계산할 연산자를 입력하세요 : ");
	scanf("%c", &op);                                 <--- 이렇게 문자형을 받는 scanf를 맨 위에 위치시킨다면, %c앞에 공백을 남기지 않아도 입력을 받을 수 있다.
	printf("첫 번째 숫자를 입력하세요 : ");
	scanf("%d", &num1);
	printf("두 번째 숫자를 입력하세요 : ");
	scanf("%d", &num2);

	if (op == '+')
	{
		printf("%d + %d = %d", num1, num2, num1 + num2);
	}
	else if (op == '-')
	{
		printf("%d - %d = %d", num1, num2, num1 - num2);
	}
	else if (op == '*')
	{
		printf("%d * %d = %d", num1, num2, num1 * num2);
	}
	else if (op == '/')
	{
		printf("%d / %d = %.2f", num1, num2, num1 / (float)num2);
	}
	else if (op == '%')
	{
		printf("%d %% %d = %d", num1, num2, num1 % num2);
	}
	
	return 0;
}


---------------------------------
💞💞 예제 11. 2022. 04. 19 복습하다가 생긴 일 💞💞


#include <stdio.h>

int main(void)
{
	int a, b;
	char op;
	int result;

	printf("첫번째 수를 입력하세요 : ");
	scanf("%d", &a);
	printf("계산할 연산자를 입력허세요 : ");
	scanf(" %c", &op);
	printf("두번째 수를 입력하세요 : ");
	scanf("%d", &b);

	if (op == '+')
	{
		result = a + b;
		printf("%d + %d = %d 입니다.", a, b, result);
	}
	else if(op == '-')
	{
		result = a - b;
		printf("%d - %d = %d 입니다.", a, b, result);
	}
	else if (op == '*')
	{
		result = a * b;
		printf("%d * %d = %d 입니다.", a, b, result);
	}
	else if (op == '/')
	{
		result = (float)a / b;
		printf("%d / %d = %f 입니다.", a, b, (float)result);           <--✅ 이렇게 하면 왜 result의 출력이 소수점이 x.000000 으로 나오는지 궁금했다.
	}                                                                            10과 3을 입력을 하면 내가 원하는 출력은 
	else if (op == '%')                                                          "10 / 3 = 3.333333 입니다." 였다. 그런데 그렇게 출력되지 않고
	{                                                                            "10 / 3 = 3.000000 입니다." 로 출력이 된다. 이에 대한 이유를 생각해봤다.
		result = a % b;                   
		printf("%d %% %d = %d 입니다.", a, b, result);
	}
	else
	{
		printf("제대로된 연산자 입력");
	}

	return 0;
}




       🎈🎈 그 이유는 바로 !!
                    result = (float)a / b;                  <-- 여기서 실수형으로 강제 형변환을 하여 a / b를 한값이
		    				                result로 저장된다고 해도 result는 int형이기 때문에 3 (혹은 3.000000 일려나?)이 저장된다.
								
								
		    printf("%d / %d = %f 입니다.", a, b, (float)result);  <-- 그래서 (float)result 안에는 값이 3.333333이 아니라, 3.000000이 저장되어 있는 것이다.




    ------------------------------------------------------------------------------------------------------------------------------------      

예제 12. 맞음⭕

#include <stdio.h>

int main()
{
	int num1;
	int num2;
	char op;

	printf("첫 번째 숫자를 입력하세요 : ");
	scanf("%d", &num1);
	printf("계산할 연산자를 입력하세요 : ");
	scanf(" %c", &op);
	printf("두 번째 숫자를 입력하세요 : ");
	scanf("%d", &num2);

	if (op == '+')
	{
		printf("%d + %d = %d", num1, num2, num1 + num2);
	}
	else if (op == '-')
	{
		printf("%d - %d = %d", num1, num2, num1 - num2);
	}
	else if (op == '*')
	{
		printf("%d * %d = %d", num1, num2, num1 * num2);
	}
	else if (op == '/')
	{
		printf("%d / %d = %.2f", num1, num2, num1 / (float)num2);
	}
	else if (op == '%')
	{
		printf("%d %% %d = %d", num1, num2, num1 % num2);
	}
	else
	{ 
		printf("연산자를 잘못 입력했습니다.");       <-- 예제 11번에서 이것만 추가됨. 
	}
	
	return 0;
}




예제 13. 맞음⭕

#include <stdio.h>

int main()
{
	int num1;
	int num2;
	char fake_op;

	int real_op = 5;

	printf("수식을 한줄로 띄이쓰기로 입력하세요 : ");
	scanf("%d %c %d", &num1, &fake_op, &num2);

	if (fake_op == '+')
	{
		real_op = 0;
	}
	else if (fake_op == '-')
	{
		real_op = 1;
	}
	else if (fake_op == '*')
	{
		real_op = 2;
	}
	else if (fake_op == '/')
	{
		real_op = 3;
	}
	else if (fake_op == '%')
	{
		real_op = 4;
	}
	else
	{
		printf("연산자를 잘못 입력했습니다.");
	}

	switch (real_op)
	{
	case 0: printf("%d %c %d = %d입니다.", num1, fake_op, num2, num1 + num2); break;
	case 1: printf("%d %c %d = %d입니다.", num1, fake_op, num2, num1 - num2); break;
	case 2: printf("%d %c %d = %d입니다.", num1, fake_op, num2, num1 * num2); break;
	case 3: printf("%d %c %d = %d입니다.", num1, fake_op, num2, num1 / num2); break;
	case 4: printf("%d %c %d = %d입니다.", num1, fake_op, num2, num1 % num2);
	}
	return 0;
}


🔻다른 답🔻

#include <stdio.h>

int main()
{
	int num1;
	int num2;
	char op;

	printf("수식을 한줄로 띄이쓰기로 입력하세요 : ");
	scanf("%d %c %d", &num1, &op, &num2);

	switch (op)
	{  
	case '+': printf("%d %c %d = %d", num1, op, num2, num1 + num2); break;        🎈🎈 나는 case 뒤에 정수만 가능한줄알았다.. 그게아니다.. 상수면 된다.. 변수가 안되는거였다..
	case '-': printf("%d %c %d = %d", num1, op, num2, num1 - num2); break;        
	case '*': printf("%d %c %d = %d", num1, op, num2, num1 * num2); break;
	case '/': printf("%d %c %d = %.3f", num1, op, num2, num1 / (float)num2); break;
	case '%': printf("%d %c %d = %d", num1, op, num2, num1 % num2); break;
	default: printf("연산자를 잘못 입력했습니다.");
	}

	return 0;
}



