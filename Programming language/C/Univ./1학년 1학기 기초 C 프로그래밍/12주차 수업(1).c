
📌예제 문제풀이📌

예제 24.  맞음⭕

#include <stdio.h>
#include <string.h>

int main(void)
{
	char ss[100];
	char* aa;
	int len;

	aa = ss;

	printf("문자열을 입력하세요 : ");
	scanf("%s", ss);

	len = strlen(ss);

	for (int i = len - 1; i >= 0; i--)  
  {
		printf("%c", *(aa + i));
	}
	
	return 0;
}


🔻다른 답🔻

#include <stdio.h>
#include <string.h>

int main(void)
{
	char ss[100];
	char* aa;
	int len;

	aa = ss;

	printf("문자열을 입력하세요 : ");
	scanf("%s", ss);

	len = strlen(ss);

	for (int i = 0; i < len; i++)
	{
		printf("%c", *(aa + len - (i + 1)));         <-- 여기를 수정해줬다.
	}

	return 0;
}


예제 25.  맞음⭕

#include <stdio.h>

int main(void)
{
	int a;
	int b;

	int* p1;
	int* p2;
	int tmp;

	p1 = &a;
	p2 = &b;

	printf("a 값 입력 : ");
	scanf("%d", &a);
	printf("b 값 입력 : ");
	scanf("%d", &b);

	tmp = *p1;               tmp = p1 이렇게 tmp에 p1 값 ( 주소값 ) 을 넣어주려고 했는데 오류가 난다.  
	*p1 = *p2;
	*p2 = tmp;


	printf("바뀐 값 a는 %d, b는 %d", *p1, *p2);

	return 0;
}


예제 26.   맞음⭕

#include <stdio.h>

int main()
{
	int s[10] = { 1,0,3,2,5,4,7,6,9,8 };
	int tmp;
	int* p;
	p = s;

	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (*(p + i) > *(p + j))
			{
				tmp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = tmp;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%2d", *(p + i));
	}

	return 0;
}
