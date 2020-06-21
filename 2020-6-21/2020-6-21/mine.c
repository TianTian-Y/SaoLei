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
	ShowBoard(Board, ROW, COL);    //试这个 1

	int count = (ROW-2)*(COL-2) - MINE;
	while (count>0)
	{
		system("cls");      //试试不加会怎样
		int x = 0;
		int y = 0;
		//ShowBoard(Board, ROW, COL);   //试试和放在外面1+2有什么不同
		printf("请输入你要扫的坐标：\n");
		scanf("%d", &x, &y);
		if (x<1 || x>10 || y<10 || y>10){
			printf("你输入的坐标有误，请重新输入！\n");
			Sleep(1000);            //试试不加会怎样
			continue;
		}
		else if (Board[x][y] != '*'){
			printf("此坐标已被重复输入，请重新输入！\n");
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
			printf("你输入的[%d][%d]地方有雷！\n");
			break;
		}
	}
	char *result = NULL;
	if (count > 0){        //代表是因为扫到雷了跳出了while循环而不是因为全部扫完了count减到0了
		result = "## 啊哦！你被炸死了！o(╥﹏╥)o ##\n";
	}
	else{
		result = "## 扫雷结束！恭喜！你赢啦！(*^▽^*) ##\n";
	}
	printf("####################################\n");
	printf("%s", result);
	printf("####################################\n");
	ShowBoard(Mine, ROW, COL);
}