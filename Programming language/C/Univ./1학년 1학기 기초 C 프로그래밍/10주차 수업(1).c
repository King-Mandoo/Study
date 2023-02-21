2022. 05. 05.

🟡 2차원 배열

🟠 2차원 배열의 기본 개념

 --> 2차원 배열은 1차원 배열을 여러 개 연결한 것으로, 첨자를 2개 사용하는 배열이다.
 
     int aa[3],[4];    -->  3행 4열 배열
     
     #include <stdio.h>

      int main()
      {
        int aa[3][4];

        aa[0][0] = 1; aa[0][1] = 2; aa[0][2] = 3; aa[0][3] = 4;
        aa[1][0] = 1; aa[1][1] = 2; aa[1][2] = 3; aa[1][3] = 4;
        aa[2][0] = 1; aa[2][1] = 2; aa[2][2] = 3; aa[2][3] = 4;

        printf("%3d %3d %3d %3d\n", aa[0][0], aa[0][1], aa[0][2], aa[0][3]);
        printf("%3d %3d %3d %3d\n", aa[1][0], aa[1][1], aa[1][2], aa[1][3]);
        printf("%3d %3d %3d %3d\n", aa[2][0], aa[2][1], aa[2][2], aa[2][3]);

        return 0;
      }
      
      출력결과: 
                1   2   3   4
                1   2   3   4
                1   2   3   4


🟠 2차원 배열의 초기화    책 p.265 보기


#include <stdio.h>

int main()
{
	int aa[3][4] = {            <-- 이렇게 초기화..!
		{1, 2 ,3 ,4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};

	printf("aa[0][0] 부터 aa[2][3]까지\n\n");

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			printf("aa[%d][%d]: %d\t", i, k, aa[i][k]);
		}
		printf("\n");
	}

	return 0;
}

출력결과 : 
              aa[0][0] 부터 aa[2][3]까지

              aa[0][0]: 1     aa[0][1]: 2     aa[0][2]: 3     aa[0][3]: 4
              aa[1][0]: 5     aa[1][1]: 6     aa[1][2]: 7     aa[1][3]: 8
              aa[2][0]: 9     aa[2][1]: 10    aa[2][2]: 11    aa[2][3]: 12


🟠 3차원 이상의 배열    책 p.265 ~ 266 보기
  
  -->   int aa [면] [행] [열];
  
  
#include <stdio.h>

int main()
{
	int aa[2][3][4] = {
		{
			{1, 2 ,3 ,4},
			{5, 6, 7, 8},
			{9, 10, 11, 12}
		}
		,                            <-- , 가 중요..!
		{
			{13, 14 ,15 ,16},
			{17, 18, 19, 20},
			{21, 22, 23, 24}
		}
	};

	printf("aa[0][0] 부터 aa[2][3]까지\n\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				printf("aa[%d}[%d][%d]: %d\t", i, j, k, aa[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	

	return 0;
}


----------------------------------------------------------------------------------------------------------------------------------------------------------------

📌예제 문제풀이📌

예제 20.  틀림❌  

내 처음 답.

#include <stdio.h>
#include <string.h>

int main()
{
	int i, k;
	char str[100];

	printf("문자열을 입력: ");
	scanf("%s", str);

	k = strlen(str);

	for (i = 0; i < k; i++)
	{
		str[i] = str[(k - 1) - i];  
	}
	str[k] = '\0';

	printf("%s", str);
	
	return 0;
}

✅틀린 이유:  문자형 배열 str에 "ABC"를 입력을 해줬는데 왜 계속 "CBC"로 출력이 되는지 이해가 되지 않았다.
	      그 이유는 for문에서 일어난다.
	    
	문자형 배열 str에 "ABC"를 입력해줬을 때
						    str[0] = str[2]    <-- str[0]에 str[2]의 값 'C' 대입
						    str[1] = str[1]    <-- str[1]에 str[1]의 값 'B' 대입
						    str[2] = str[0]    <-- 🎈 str[2]에 str[0]의 값 'C' 가 대입된다...

        이러한 이유로 내가 원하는 값으로 출력이 되지 않았던 것이다..ㅎ=ㅎ

🔻고친 답🔻

#include <string.h>

int main()
{
	int i, k;
	char str[100];
	char tt[100];                <--- 이렇게 문자형 배열을 하나 더 추가해준다.

	printf("문자열을 입력: ");         
	scanf("%s", str);             <-- gets(str); 로 변경가능     심지어 이게 더 좋아보임 scanf는 spacebar를 누르면 작동이 돼서 약간 꼬롬함.

	k = strlen(str);

	for (i = 0; i < k; i++)
	{ 
		tt[i] = str[(k - 1) - i];         <-- 다른 문자형 배열에 값을 입력해준다.
	}
	tt[k] = '\0';

	printf("%s", tt);      <-- puts(tt); 로 변경가능

	return 0;
}

  
예제 21.   맞음⭕     <다른 답 확인>

#include <stdio.h>
#include <string.h>

int main()
{
	char alpha[100];
	int i;

	printf("문자 입력: ");
	gets(alpha);

	i = strlen(alpha);

	for (int k = 0; k < i; k++)
	{
		if (alpha[k] > 64 && alpha[k] < 91)
		{
			alpha[k] += 32;
		}
		else if (alpha[k] > 96 && alpha[k] < 123)
		{
			alpha[k] -= 32;
		}
	}
	alpha[i] = '\0';               <-- ✅ Q. 왜 널 문자를 굳이 넣어주지 않아도 오류가 뜨지 않을까? 라고 생각했었다.
                                              A. 그 이유는 애초에 문자형 배열 alpha에는 gets() 함수를 사용하여 널 문자가 입력 되어 있기 때문이다. 
	printf("%s", alpha);                     따라서 207번 줄은 굳이 없어도 된다.

	return 0;
}


🔻 다른 답🔻

#include <stdio.h>
#include <string.h>

int main()
{
	char in[100], out[100];
	int i, len;
	int diff = 'a' - 'A';       <--  굳이 아스키 코드를 구하지 않아도 이런 식으로 차이를 찾아서 구할 수도 있겠구나.

	printf("문자 입력: ");
	gets(in);

	len = strlen(in);

	for (i = 0; i < len; i++)
	{
		if (('A' <= in[i]) && (in[i] <= 'Z'))
			out[i] = in[i] + diff;
		else if (('a' <= in[i]) && (in[i] <= 'z'))
			out[i] = in[i] - diff;
		else                                        <--  이 코드는 이렇게 다른 문자를 입력했을 경우를 따로 설정해줘야한다. out[i]에 값을 넣어줘야 하기 때문이다.
			out[i] = in[i];
	}
	out[i] = '\0';

	puts(out);

	return 0;
}


예제 22.   맞음⭕

#include <stdio.h>
#include <string.h>

int main()
{
	int dan[9][9];
	int i, k;

	for (i = 0; i < 9; i++)
	{
		for (k = 0; k < 9; k++)
		{
			dan[i][k] = (k + 1) * (i + 1);
			printf("%dX%d= %d\t", k + 1, i + 1, dan[i][k]);
		}
		printf("\n");
	}
	return 0;
}

예제 23.   맞음⭕

#include <stdio.h>
#include <string.h>

int main()
{
	char aa[100];
	char s;
	char new;
	int i;

	printf("여러 글자를 입력 : ");
	gets(aa);

	printf("기존 문자와 새로운 문자 : ");
	scanf("%c %c", &s, &new);

	i = strlen(aa);

	for (int k = 0; k < i; k++)
	{
		if (aa[k] == s)
		{
			aa[k] = new;
		}
	}
	aa[i] = '\0';            <-- ✅ 이것도 마찬가지다 굳이 널 문자를 넣어줄 필요가 없다.  문자형 배열 aa에 이미 널 문자가 들어가 있기 때문이다.

	printf("%s", aa);

	return 0;
}
