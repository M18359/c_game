#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			board[i][j] = set;
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------ɨ����Ϸ------\n");
	int n = 0;
	for (n = 0; n <= row; n++)
	{
		if (n == 0)
		{
			printf("  ");
		}
		else
			printf("%d ", n);
	}
	printf("\n");
	for (i = 1; i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------ɨ����Ϸ------\n");
}


void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		//1~9
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		//�ж��Ƿ��Ѿ����ù�����
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("������Ҫ���ҵ�λ�����꣺");
		scanf("%d %d", &x, &y);
		//�ж�������ȷ��
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '0')
			{
				//�޵��ף�������ܱߵĵ�������
				int m = 0;
				int n = 0;
				int sum = 0;
				for (m = x - 1; m <= x + 1; m++)
				{
					for (n = y - 1; n <= y + 1; n++)
					{
						if (mine[m][n] == '1')
							sum++;
					}
				}
				show[x][y] = sum+48;//�ַ������ּ�ת��
				DisplayBoard(show, ROW, COL);
			}
			else
			{
				//�е��ף��˳���Ϸ
				printf("�е��ף��˳���Ϸ!\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
		}
		else
		{
			printf("����������������������\n");
		}
	}
}

