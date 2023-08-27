#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game()
{
	char mine[ROWS][COLS] = {0};//存放布置好的雷图
	char show[ROWS][COLS] = {0};//存放排查出的雷的信息
	//初始化数组内容
	InitBoard(mine,ROWS,COLS,'0');//main数组在没有雷的时候都是'0'
	InitBoard(show,ROWS,COLS,'*');//show数组在没有被排查的时候都是'*'

	//设置地雷
	SetMine(mine,ROW,COL);
	//打印数组
	//DisplayBoard(mine, ROW,COL);
	DisplayBoard(show, ROW, COL);
	//查找地雷
	FindMine(mine, show, ROW, COL);

}
void menu()
{
	printf("**************************\n");
	printf("*********  1.play ********\n");
	printf("*********  0.exit ********\n");
	printf("**************************\n");
}
int main()
{
	int input = 0;
	//设计随机数的生成起点
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择是否进入游戏\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始扫雷游戏\n");
			game();
			break;
		case 0:
			printf("退出扫雷游戏\n");
			break;
		default:
			printf("输入错误，请重新输入!\n");
		}
	} while (input);
	return 0;
}