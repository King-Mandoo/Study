#include <stdio.h>
#include <string.h>
#include "libraryFunc.h"

void book_register(struct library* regiBook, int* bookNum)  // å ���
{
	if (*bookNum >= 100)
	{
		printf("å�� �� �̻� ����� �� �����ϴ�.\n");
		return;
	}

	printf("����� å ���� : ");
	scanf("%s", regiBook[*bookNum].bookName);

	printf("����� å ���� : ");
	scanf("%s", regiBook[*bookNum].author);

	printf("����� å ���ǻ� : ");
	scanf("%s", regiBook[*bookNum].publish);

	regiBook[*bookNum].borrowed = 0;  // ���� ���� å�� 0, ������ å�� 1, ������ +1, �ݳ��ϸ� �ٽ� -1

	printf("\n��ϵǾ����ϴ�.\n");

	*bookNum = *bookNum + 1;
}

void book_search(struct library* searchBook) // å �˻� �׸��� ������ + 1 �ϴ� �Լ�
{
	char searching[30];
	int num = 0;
	printf("�˻��� ����\n1.����\n2.����\n3.���ǻ�\n�Է� : ");
	scanf("%d", &num);

	while (1)
	{
		if (num == 1)
		{
			int cmp;
			printf("���� �Է� : ");
			scanf("%s", searching);
			for (cmp = 0; strcmp(searchBook[cmp].bookName, searching) != 0; cmp++);
			printf("\nã���ô� å ���� : %s\n", searchBook[cmp].bookName);
			printf("ã���ô� å ���� : %s\n", searchBook[cmp].author);
			printf("ã���ô� å ���ǻ� : %s\n\n", searchBook[cmp].publish);

			num = 0;
			if (searchBook[cmp].borrowed == 0)
			{
				printf("�� å�� ���� �����մϴ�..! �����Ͻðڽ��ϱ�?\n1.�� 2.�ƴϿ� : ");
				scanf("%d", &num);

				if (num == 1)
				{
					searchBook[cmp].borrowed++;
					printf("����Ǿ����ϴ�~\n");
				}
				else
					printf("\n");
			}
			else
			{
				printf("�̹� ����Ǿ����ϴ�!\n");
			}

			break;
		}
		else if (num == 2)
		{
			int cmp;
			printf("���� �Է� : ");
			scanf("%s", searching);
			for (cmp = 0; strcmp(searchBook[cmp].author, searching) != 0; cmp++);
			printf("\nã���ô� å ���� : %s\n", searchBook[cmp].bookName);
			printf("ã���ô� å ���� : %s\n", searchBook[cmp].author);
			printf("ã���ô� å ���ǻ� : %s\n\n", searchBook[cmp].publish);

			num = 0;
			if (searchBook[cmp].borrowed == 0)
			{
				printf("�� å�� ���� �����մϴ�..! �����Ͻðڽ��ϱ�?\n1.�� 2.�ƴϿ� : ");
				scanf("%d", &num);

				if (num == 1)
				{
					searchBook[cmp].borrowed++;
					printf("����Ǿ����ϴ�~\n");
				}
				else
					printf("\n\n");
			}
			else
			{
				printf("�̹� ����Ǿ����ϴ�!\n");
			}

			break;
		}
		else if (num == 3)
		{
			int cmp;
			printf("���ǻ� �Է� : ");
			scanf("%s", searching);
			for (cmp = 0; strcmp(searchBook[cmp].publish, searching) != 0; cmp++);
			printf("\nã���ô� å ���� : %s\n", searchBook[cmp].bookName);
			printf("ã���ô� å ���� : %s\n", searchBook[cmp].author);
			printf("ã���ô� å ���ǻ� : %s\n\n", searchBook[cmp].publish);

			num = 0;
			if (searchBook[cmp].borrowed == 0)
			{
				printf("�� å�� ���� �����մϴ�..! �����Ͻðڽ��ϱ�?\n1.�� 2.�ƴϿ� : ");
				scanf("%d", &num);

				if (num == 1)
				{
					searchBook[cmp].borrowed++;
					printf("����Ǿ����ϴ�~\n");
				}
				else
					printf("\n\n");
			}
			else
			{
				printf("�̹� ����Ǿ����ϴ�!\n");
			}

			break;
		}
		else
		{
			printf("�ٽ� �Է�\n");
			break;
		}
	}
}

void book_return(struct library* returnBook, int* bookNum)
{
	printf("���� å ���\n");

	for (int i = 0; i < *bookNum; i++)
	{
		if (returnBook[i].borrowed == 0)
		{
			printf("%d.���� ���� å : %s\n", i + 1, returnBook[i].bookName);
		}
		else
		{
			printf("%d.���� å : %s\n", i + 1, returnBook[i].bookName);
		}
	}

	int number = 0;

	printf("�����Ͻ� Ȥ�� �ݳ��Ͻ� å ��ȣ�� �Է����ּ��� : ");
	scanf("%d", &number);

	if (returnBook[number - 1].borrowed == 0)
	{
		returnBook[number - 1].borrowed++;
		printf("����Ǽ̽��ϴ�~!\n");
	}
	else
	{
		returnBook[number - 1].borrowed--;
		printf("�ݳ��Ǽ̽��ϴ�~!\n");
	}
}
