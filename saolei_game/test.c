#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game()
{
	char mine[ROWS][COLS] = {0};//��Ų��úõ���ͼ
	char show[ROWS][COLS] = {0};//����Ų�����׵���Ϣ
	//��ʼ����������
	InitBoard(mine,ROWS,COLS,'0');//main������û���׵�ʱ����'0'
	InitBoard(show,ROWS,COLS,'*');//show������û�б��Ų��ʱ����'*'

	//���õ���
	SetMine(mine,ROW,COL);
	//��ӡ����
	//DisplayBoard(mine, ROW,COL);
	DisplayBoard(show, ROW, COL);
	//���ҵ���
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
	//�����������������
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ���Ƿ������Ϸ\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼɨ����Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳�ɨ����Ϸ\n");
			break;
		default:
			printf("�����������������!\n");
		}
	} while (input);
	return 0;
}