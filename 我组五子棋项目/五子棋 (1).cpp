//头文件
#include<stdio.h>
#include<graphics.h>
#include<math.h>

//函数的声明
void printMap();
int getUserChoose();
int fun1(int x, int y);
void gameView();

//全局变量
int map[15][15] = {0}; // 0表示空地   1表示黑子  2表示白子
int flag=0; // 1表示黑子,2表示白子

int main()
{
	gameView();
	return 0;
}

void gameView()
{
	printMap();
	getUserChoose();
	int c=0;
	int d=0;
	fun1(c,d);
	return ;
}

/*-----------------------------------------2.绘制棋盘-------------------------------------------
*	负责人： 组长
	绘制棋盘， 0表示空地， 1表示黑子， 2表示白子
*/
void printMap()
{
	//绘制棋盘
		initgraph(510, 510);			//设置窗口大小
		setbkcolor(BROWN);             //设置背景颜色，棕色
		cleardevice(); 
		setlinecolor(WHITE);           //设置线条颜色，白色         
		for (int i = 30; i <= 480; i += 30)	//使用for循环绘制棋盘
		{
			line(i, 30, i, 480);
			line(30, i, 480, i);
		}
		for (int i = 120; i < 400; i += 270)
		{
			for (int j = 120; j < 400; j += 270)
				fillcircle(i, j, 3);//不被后面影响
		}

		
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (map[i][j] != 0) {
					if (map[i][j]==1)
					{
						int a =30+ i * 30;
						int b =30+ j * 30;
						setfillcolor(BLACK);
						
						fillcircle(a,b ,10 );
					}
					else {
						int a =30+ i * 30;
						int b =30+ j * 30;
						setfillcolor(WHITE);
						
						fillcircle(a, b, 10);
					}

				}


			}
		}	
		while (1);
	closegraph();
}


int getUserChoose()
{

	//鼠标
	MOUSEMSG m;//保存鼠标信息
	int x, y;//定义鼠标坐标
	int a, b;//数组下标

	while (1)
	{
		m = GetMouseMsg();//获取一个鼠标的信息

	//下在点上，30的倍数,辨认每一个点,abs：绝对值
		for (int i = 1; i < 15; i++)
		{
			for (int j = 1; j < 15; j++)
			{
				if (abs(m.x - i * 30) < 15 && abs(m.y - i * 30) < 15)
				{
					x = i * 30;//有问题
					y = j * 30;
					a = i;
					b = j;
					break;
				}
			}
		}

	}

	/*while (true)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			return 100 * (int)(m.x - 30) / 30 + (int)(m.y - 30) / 30;
		}
	}*/
	return -1;
}



int fun1(int x, int y)
{
	if (map[x][y] != 0)     //位置有棋子
	{
		return 0;
	}
	else					//位置无棋子
	{
		flag++;
		if (flag % 2 == 0)  //判断黑色还是白色棋子
		{
			map[x][y] = 1;
			setfillcolor(BLACK);
			fillcircle(x,y,14);
		}
		else
		{
			map[x][y] = 2;
			setfillcolor(WHITE);
			fillcircle(x, y, 14);
		}
	}

	int m, n;
	for (m = 0; m < 15; m++)	//判断胜负
	{
		for (n = 0; n < 15; n++)
		{
			if (map[m][n] == 1 && map[m][n + 1] == 1 && map[m][n + 2] == 1 && map[m][n + 3] == 1 && map[m][n + 4] == 1)return 2;
			if (map[m][n] == 1 && map[m + 1][n] == 1 && map[m + 2][n] == 1 && map[m + 3][n] == 1 && map[m + 4][n] == 1)return 2;
			if (map[m][n] == 1 && map[m + 1][n + 1] == 1 && map[m + 2][n + 2] == 1 && map[m + 3][n + 3] == 1 && map[m + 4][n + 4] == 1)return 2;
			if (n > 3 && map[m][n] == 1 && map[m + 1][n - 1] == 1 && map[m + 2][n - 2] == 1 && map[m + 3][n - 3] == 1 && map[m + 4][n - 4] == 1)return 2;
			if (map[m][n] == 2 && map[m][n + 1] == 2 && map[m][n + 2] == 2 && map[m][n + 3] == 2 && map[m][n + 4] == 2)return 2;
			if (map[m][n] == 2 && map[m + 1][n] == 2 && map[m + 2][n] == 2 && map[m + 3][n] == 2 && map[m + 4][n] == 2)return 2;
			if (map[m][n] == 2 && map[m + 1][n + 1] == 2 && map[m + 2][n + 2] == 2 && map[m + 3][n + 3] == 2 && map[m + 4][n + 4] == 2)return 2;
			if (n > 3 && map[m][n] == 2 && map[m + 1][n - 1] == 2 && map[m + 2][n - 2] == 2 && map[m + 3][n - 3] == 2 && map[m + 4][n - 4] == 2)return 2;
		}
	}
	if (flag > 225)			//棋盘满
	{
		return 3;
	}
	else
	{
		return 1;
	}
}