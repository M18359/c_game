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
	printf("------扫雷游戏------\n");
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
	printf("------扫雷游戏------\n");
}


void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		//1~9
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		//判断是否已经放置过地雷
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	//'1'-'0'--->1
	//'0'-'0'-->0
	return board[x - 1][y] + board[x - 1][y - 1] + board[x][y - 1] +
		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] +
		board[x][y + 1] + board[x - 1][y + 1] - 8 * board[x][y];
}

void Judge(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int row,int col)
{
		//无地雷，需计算周边的地雷数量
		int count = get_mine_count(mine, x, y);
		//转换为数字字符
		if (count == 0)//该坐标周围没有雷--递归
		{
			show[x][y] = ' ';
			//排查其附近的位置---递归
			int m = 0;
			int n = 0;
			for (m = -1; m <= 1; m++)
			{
				for (n = -1; n <= 1; n++)
				{
					if (m ==n && m==0)
					{
						;//不是原来的位置才被后续处理
					}
					else
					{
						//判断合法性
						if (x+m >= 1 && x+m <= row && y+n >= 1 && y+n <= col)
						{
							//判断有没有被排查过
							if (show[x + m][y + n] != '*')
							{
								;
							}
							else//没被排查
							{
								Judge(mine, show, x + m, y + n,ROW,COL);
							}
						}
						
					}
				}
			}
		}
		else
		{
			show[x][y] = count + '0';
			//DisplayBoard(show, ROW, COL);
			//win++;
		}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//int win = 0;
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("请输入要查找的位置坐标：");
		scanf("%d %d", &x, &y);
		//判断坐标正确性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断是否被排查过
			if (show[x][y] != '*')
			{
				printf("该坐标已被排查过了，请重新输入!\n");
			}
			else
			{
				//判断是不是地雷
				if (mine[x][y] == '0')
				{
					//无地雷
					Judge(mine, show, x, y,ROW,COL);
					DisplayBoard(show, ROW, COL);
				}
				else
				{
					//有地雷，退出游戏
					printf("有地雷，退出游戏!\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
			}
		}
		else
		{
			printf("输入坐标有误，请重新输入\n");
		}
	}
	/*if (win == row * col - EASY_COUNT)
	{
		printf("恭喜获胜\n");
		DisplayBoard(mine, ROW, COL);
	}*/
}


