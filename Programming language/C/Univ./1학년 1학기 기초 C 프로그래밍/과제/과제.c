#include<stdio.h>

int main()
{
	int matrix1[10][10];
	int col1, row1;

	printf("Type the dimension of the first matrix: ");
	scanf("%d %d", &col1, &row1);

	for (int i = 0; i < col1; i++)
	{
		for (int j = 0; j < row1; j++)
		{
			if (i == 0)
			{
				printf("Type the 1st row: ");         <-- 이렇게 입력 받으면 1, 2 ,3 4 로 입력 할수가 없음 엔터키를 눌러야만 하기 때문이다
				scanf("%d", &matrix1[i][j]);
			}
			else if (i == 1)
			{
				printf("Type the 2nd row: ");
				scanf("%d", &matrix1[i][j]);
			}
			else if (i == 2)
			{
				printf("Type the 3rd row: ");
				scanf("%d", &matrix1[i][j]);
			}
			else
			{
				printf("Type the %dth row: ", i + 1);
				scanf("%d", &matrix1[i][j]);
			}
		}
	}

	return 0;
}

--------------------

#include<stdio.h>

int main()
{
	int matrix1[10][10];
	int col1, row1;

	int matrix2[10][10];
	int col2, row2;

	printf("Type the dimension of the first matrix: ");
	scanf("%d %d", &col1, &row1);
	printf("\n");

	for (int i = 0; i < col1; i++)
	{
		if (i == 0)
		{
			printf("Type the 1st row: ");
		}
		else if (i == 1)
		{
			printf("Type the 2nd row: ");
		}
		else if (i == 2)
		{
			printf("Type the 3rd row: ");
		}
		else
		{
			printf("Type the %dth row: ", i + 1);
		}

		for (int j = 0; j < row1; j++)
		{
			scanf("%d, ", &matrix1[i][j]);
		}
	}
	printf("\n");

	printf("Type the dimension of the second matrix: ");
	scanf("%d %d", &col2, &row2);

	while (1)
	{
		if (row1 != col2)
		{
			printf("Row number does not match!\n");
			printf("Re-type the dimension of the second matrix: ");
			scanf("%d %d", &col2, &row2);
		}
		else
			break;
	}
	printf("\n");

	for (int i = 0; i < col2; i++)
	{
		if (i == 0)
		{
			printf("Type the 1st row: ");
		}
		else if (i == 1)
		{
			printf("Type the 2nd row: ");
		}
		else if (i == 2)
		{
			printf("Type the 3rd row: ");
		}
		else
		{
			printf("Type the %dth row: ", i + 1);
		}

		for (int j = 0; j < row2; j++)
		{
			scanf("%d, ", &matrix2[i][j]);
		}
	}
	printf("\n");
	int sum;

	printf("The result is \n\n");

	for (int i = 0; i < col1; i++)
	{
		for (int j = 0; j < row2; j++)
		{
			sum = 0;
			for (int k = 0; k < col2; k++)
			{
				sum = sum + (matrix1[i][k] * matrix2[k][j]);
			}
			printf(" %d  ", sum);
		}
		printf("\n");
	}


	return 0;
}

--------------------------------------------------

#include<stdio.h>

void first_mat(int matrix1[10][10], int col1, int row1)       <--- row가 행 col이 열인데 헷갈려서 반대로 작성함. 그래서 아래에 다시 수정.
{
	for (int i = 0; i < col1; i++)
	{
		if (i == 0)
		{
			printf("Type the 1st row: ");
		}
		else if (i == 1)
		{
			printf("Type the 2nd row: ");
		}
		else if (i == 2)
		{
			printf("Type the 3rd row: ");
		}
		else
		{
			printf("Type the %dth row: ", i + 1);
		}

		for (int j = 0; j < row1; j++)
		{
			scanf("%d, ", &matrix1[i][j]);
		}
	}
	printf("\n");
}

void second_mat(int matrix2[10][10], int col2, int row2)
{
	for (int i = 0; i < col2; i++)
	{
		if (i == 0)
		{
			printf("Type the 1st row: ");
		}
		else if (i == 1)
		{
			printf("Type the 2nd row: ");
		}
		else if (i == 2)
		{
			printf("Type the 3rd row: ");
		}
		else
		{
			printf("Type the %dth row: ", i + 1);
		}

		for (int j = 0; j < row2; j++)
		{
			scanf("%d, ", &matrix2[i][j]);
		}
	}
}

int main()
{
	int matrix1[10][10];
	int col1, row1;

	int matrix2[10][10];
	int col2, row2;

	printf("Type the dimension of the first matrix: ");
	scanf("%d %d", &col1, &row1);
	printf("\n");
	
	first_mat(matrix1, col1, row1);

	printf("Type the dimension of the second matrix: ");
	scanf("%d %d", &col2, &row2);

	while (1)
	{
		if (row1 != col2)
		{
			printf("Row number does not match!\n");
			printf("Re-type the dimension of the second matrix: ");
			scanf("%d %d", &col2, &row2);
		}
		else
			break;
	}
	printf("\n");

	second_mat(matrix2, col2, row2);

	printf("\n");
	int sum;

	printf("The result is \n\n");

	for (int i = 0; i < col1; i++)
	{
		for (int j = 0; j < row2; j++)
		{
			sum = 0;
			for (int k = 0; k < col2; k++)
			{
				sum = sum + (matrix1[i][k] * matrix2[k][j]);
			}
			printf(" %d  ", sum);
		}
		printf("\n");
	}


	return 0;
}


------------------------------------------------


// 2288065 선태욱

#include<stdio.h>

void first_mat(int matrix1[10][10], int row1, int col1)   // 첫 번째 행렬을 입력 받는 함수
{
	for (int i = 0; i < row1; i++)
	{   
		if (i == 0)                      
		{
			printf("Type the 1st row: ");
		}
		else if (i == 1)
		{
			printf("Type the 2nd row: ");
		}
		else if (i == 2)
		{
			printf("Type the 3rd row: ");
		}
		else
		{
			printf("Type the %dth row: ", i + 1);
		}

		for (int j = 0; j < col1; j++)
		{
			scanf("%d, ", &matrix1[i][j]);
		}
	}
	printf("\n");
}

void second_mat(int matrix2[10][10], int row2, int col2)  // 두 번째 행렬을 입력 받는 함수
{
	for (int i = 0; i < row2; i++)
	{
		if (i == 0)
		{
			printf("Type the 1st row: ");
		}
		else if (i == 1)
		{
			printf("Type the 2nd row: ");
		}
		else if (i == 2)
		{
			printf("Type the 3rd row: ");
		}
		else
		{
			printf("Type the %dth row: ", i + 1);
		}

		for (int j = 0; j < col2; j++)
		{
			scanf("%d, ", &matrix2[i][j]);
		}
	}
}

int main()
{
	int matrix1[10][10];
	int row1, col1;

	int matrix2[10][10];
	int row2, col2;

	printf("Type the dimension of the first matrix: ");
	scanf("%d %d", &row1, &col1);
	printf("\n");
	
	first_mat(matrix1, row1, col1);

	printf("Type the dimension of the second matrix: ");
	scanf("%d %d", &row2, &col2);

	while (1)
	{
		if (col1 != row2)
		{
			printf("Row number does not match!\n");
			printf("Re-type the dimension of the second matrix: ");
			scanf("%d %d", &row2, &col2);
		}
		else
			break;
	}
	printf("\n");

	second_mat(matrix2, row2, col2);

	printf("\n");
	int sum;

	printf("The result is \n\n");

	for (int i = 0; i < row1; i++)               // 행렬의 곱을 계산하는 for 문
	{
		for (int j = 0; j < col2; j++)
		{
			sum = 0;
			for (int k = 0; k < row2; k++)
			{
				sum = sum + (matrix1[i][k] * matrix2[k][j]);
			}
			printf("%3d ", sum);
		}
		printf("\n");
	}


	return 0;
}

-----------------------------------------------------------------------------------------


// 2288065 선태욱 과제

#include<stdio.h>

void mat(int matrix[10][10], int row, int col)   // 행렬을 입력 받는 함수
{
	for (int i = 0; i < row; i++)
	{   
		if (i == 0)                      
		{
			printf("Type the 1st row: ");
		}
		else if (i == 1)
		{
			printf("Type the 2nd row: ");
		}
		else if (i == 2)
		{
			printf("Type the 3rd row: ");
		}
		else
		{
			printf("Type the %dth row: ", i + 1);
		}

		for (int j = 0; j < col; j++)
		{
			scanf("%d, ", &matrix[i][j]);
		}
	}
	printf("\n");
}

int main()
{
	int matrix1[10][10];
	int row1, col1;

	int matrix2[10][10];
	int row2, col2;

	printf("Type the dimension of the first matrix: ");
	scanf("%d %d", &row1, &col1);
	printf("\n");
	
	mat(matrix1, row1, col1);

	printf("Type the dimension of the second matrix: ");
	scanf("%d %d", &row2, &col2);

	while (1)                                         // 첫 번째 행렬의 열과 두 번째 행렬의 행이 다르면 오류를 전하는 while 문
	{ 
		if (col1 != row2)
		{
			printf("Row number does not match!\n");
			printf("Re-type the dimension of the second matrix: ");
			scanf("%d %d", &row2, &col2);
		}
		else
			break;
	}
	printf("\n");

	mat(matrix2, row2, col2);

	printf("\n");
	int sum;

	printf("The result is \n\n");

	for (int i = 0; i < row1; i++)               // 행렬의 곱을 계산하는 for 문
	{
		for (int j = 0; j < col2; j++)
		{
			sum = 0;
			for (int k = 0; k < row2; k++)
			{
				sum = sum + (matrix1[i][k] * matrix2[k][j]);
			}
			printf("%3d ", sum);
		}
		printf("\n");
	}

	return 0;
}
