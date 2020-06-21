#include"mine.h"

void InitBoard(char Board[][COL], int row, int col,char elem)
{
	int i = 0;
	for (; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			Board[i][j] = elem;
		}
	}
}
void ShowBoard(char Board[][COL], int row, int col)
{

}
void SetMine(char Mine[][COL], int row, int col)
{

}
char GetMine(char Mine[][COL], int x, int y)
{

}
void Game()
{
	srand((unsigned long)time(NULL));

	char Board[ROW][COL];
	char Mine[ROW][COL];

	InitBoard(Board, ROW, COL,'*');
	InitBoard(Mine, ROW, COL,'0');


	SetMine(Mine, ROW, COL);
	ShowBoard(Board, ROW, COL);    //����� 1

	int count = (ROW-2)*(COL-2) - MINE;
	while (count>0)
	{
		system("cls");      //���Բ��ӻ�����
		int x = 0;
		int y = 0;
		//ShowBoard(Board, ROW, COL);   //���Ժͷ�������1+2��ʲô��ͬ
		printf("��������Ҫɨ�����꣺\n");
		scanf("%d", &x, &y);
		if (x<1 || x>10 || y<10 || y>10){
			printf("������������������������룡\n");
			Sleep(1000);            //���Բ��ӻ�����
			continue;
		}
		else if (Board[x][y] != '*'){
			printf("�������ѱ��ظ����룬���������룡\n");
			Sleep(1000);
			continue;
		}
		else if(Mine[x][y] == '0'){
			char num = GetMine(Mine, x, y);
			Board[x][y] = num;
			ShowBoard(Board, ROW, COL);  //+2
			count--;
		}
		else {
			printf("�������[%d][%d]�ط����ף�\n");
			break;
		}
	}
	char *result = NULL;
	if (count > 0){        //��������Ϊɨ������������whileѭ����������Ϊȫ��ɨ����count����0��
		result = "## ��Ŷ���㱻ը���ˣ�o(�i�n�i)o ##\n";
	}
	else{
		result = "## ɨ�׽�������ϲ����Ӯ����(*^��^*) ##\n";
	}
	printf("####################################\n");
	printf("%s", result);
	printf("####################################\n");
	ShowBoard(Mine, ROW, COL);
}