#include <stdio.h>

int return_function()
{
	int a = 20;
	int b = 10;

	//if (a > b)
	//	printf("true\n");
	//else
	//	printf("false\n");

	return (a > b) ? printf("true\n") : printf("false\n");   <-- if문을 사용하는 것 보다 이렇게 삼항연산자를 사용하는 것이 더 선호된다고 한다.

}

int main()
{
	int x;
	x = return_function();

	return 0;
}
