//头文件
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include <mmsyscom.h>
#pragma comment(lib,"winmm.lib")
#define MAX_LEN 16

//全局变量
int loc[255] = { 0 };
int loc_cnt = -1;
int map[MAX_LEN][MAX_LEN] = { 0 }; // 0表示空地   1表示黑子  2表示白子
int flag = 0; // 1表示黑子,2表示白子
int CHESS = 0;//棋子，用在result==2后

//函数的声明
void printMap();
void printCHESS();
int getUserChoose();
int fun1(int x, int y);
void gameView();
void rec_loc(int x, int y);
void go_back(void);
void MUSIC();
void change();

//-------------------------------------------main----------------------------------------------
int main()
{
	initgraph(610, 510);//设置窗口大小
	change();
	MUSIC();
	gameView();
	return 0;
}

//-------------------------------------------MUSIC----------------------------------------------
void MUSIC() {
	//alias   的作用是取别名
	mciSendString("open  1.mp3 alias a ", 0, 0, 0);//音乐在当前目录下也可以写"open ./2.mp3"./这里可以省略
	mciSendString("play a repeat", 0, 0, 0);//播放音乐，循环播放
	//mciSendString("close a", 0, 0, 0); // close 关闭播放
	//system("pause");//这里没有暂停程序会直接停止听不到音乐
	return;
}

//-------------------------------------------change----------------------------------------------
void change() {
	HWND well = GetHWnd();//获取窗口手柄
	SetWindowText(well, "好习惯养成组--五子棋");//设置窗口标题
}

//-------------------------------------------gameView----------------------------------------------
void gameView()
{
	printMap();//打印棋盘
	while (1) {
		printCHESS();//打印棋子                                 //
		int result = getUserChoose();
		if (result == -1)return;
		int c = result / 100;
		int d = result % 100;
		result = fun1(c, d);
		printCHESS();//打印棋子
		if (result == 0) {
			MessageBox(NULL, "                           操作错误请重新选                        ", "提示", MB_OK | MB_SYSTEMMODAL);//提升操作错误
			continue;
		}
		else if (result == 1) {
		}
		else if (result == 2) {
			if (CHESS == 1) {
				MessageBox(NULL, "                                  黑棋胜利                                  ", "提示", MB_OK | MB_SYSTEMMODAL);//提示黑棋胜利
			}
			else {
				MessageBox(NULL, "                                  白棋胜利                                  ", "提示", MB_OK | MB_SYSTEMMODAL);//提示白棋胜利

			}
			return;
		}
		else if (result == 3) {
			MessageBox(NULL, "                                  平局                                  ", "提示", MB_OK | MB_SYSTEMMODAL);//提示平局


			return;
		}

		flag = flag ? 0 : 1;

	}
	return;
}

//-----------------------------------------printMap-------------------------------------------
void printMap()
{
	setbkcolor(WHITE);//设置背景颜色
	cleardevice();	//清屏
	loadimage(NULL, "9.jpg", 610, 510);
	setlinecolor(WHITE);           //设置线条颜色，白色         
	for (int i = 30; i <= 480; i += 30)	//使用for循环绘制棋盘
	{
		line(i, 30, i, 480);
		line(30, i, 480, i);
	}
	for (int i = 120; i < 400; i += 270)
	{
		for (int j = 120; j < 400; j += 270)
			circle(i, j, 3);//不被后面影响
	}
	//设置字体颜色
	settextcolor(RGB(203, 120, 71));
	//设置线条样式
	setlinestyle(PS_SOLID, 1);
	//设置字体样风格
	settextstyle(30, 10, "宋体");
	//设置背景模式
	setbkmode(TRANSPARENT);
	//设置填充颜色
	setfillcolor(LIGHTGRAY);
	//输出文字,框
	fillrectangle(485, 178, 600, 208);
	outtextxy(485, 178, "黑棋选手");
	fillrectangle(485, 450, 600, 480);
	outtextxy(485, 450, "白棋选手");

	//框
	fillrectangle(485, 20, 600, 180);
	//保存图片
	IMAGE ddg;
	//加载图片
	loadimage(&ddg, "1.jpg", 115, 160);
	//贴图
	putimage(485, 20, &ddg);
	//框
	fillrectangle(485, 300, 600, 450);
	//保存图片
	IMAGE yunhai;
	//加载图片
	loadimage(&yunhai, "6.jpg", 115, 160);
	//贴图
	putimage(485, 290, &yunhai);

	return;
}

//-------------------------------------------printCHESS----------------------------------------------
void printCHESS() {
	for (int i = 0; i < MAX_LEN; i++) {//画棋子
		for (int j = 0; j < MAX_LEN; j++) {
			if (map[i][j] != 0) {
				if (map[i][j] == 1)
				{
					int a = 30 + i * 30;
					int b = 30 + j * 30;
					setfillcolor(BLACK);
					setlinecolor(LIGHTCYAN);           //设置线条颜色，白色     
					fillcircle(a, b, 8);

				}
				else {
					int a = 30 + i * 30;
					int b = 30 + j * 30;
					setfillcolor(WHITE);
					setlinecolor(RED);           //设置线条颜色，白色         
					fillcircle(a, b, 8);

				}

			}


		}
	}
	return;
}

//-------------------------------------------getUserChoose----------------------------------------------
int getUserChoose()
{

	//鼠标
	MOUSEMSG m;//保存鼠标信息
	int a, b;//数组下标
	while (1)
	{
		m = GetMouseMsg();//获取一个鼠标的信息
		//下在点上，30的倍数,辨认每一个点,abs：绝对值
		if (m.uMsg == WM_RBUTTONDOWN) {
			go_back();
		}
		if (m.uMsg == WM_LBUTTONDOWN) {
			for (int i = 0; i < MAX_LEN; i++)
			{
				for (int j = 0; j < MAX_LEN; j++)
				{
					if (abs(m.x - 30 - i * 30) < MAX_LEN && abs(m.y - 30 - j * 30) < MAX_LEN)
					{
						a = i;
						b = j;
						return a * 100 + b;

					}
				}
			}
			flag++;
		}

	}

}

//-------------------------------------------fun1----------------------------------------------
int fun1(int x, int y)
{
	if (map[x][y] != 0)     //位置有棋子
	{
		return 0;
	}
	else					//位置无棋子
	{
		if (flag % 2 == 0)  //判断黑色还是白色棋子
		{
			map[x][y] = 1;
			CHESS = 1;//黑棋
		}
		else
		{
			map[x][y] = 2;
			CHESS = 2;
		}
	}
	rec_loc(x, y);
	int m, n;
	for (m = 0; m < MAX_LEN; m++)	//判断胜负
	{
		for (n = 0; n < MAX_LEN; n++)
		{
			if (map[m][n] == 1 && map[m][n + 1] == 1 && map[m][n + 2] == 1 && map[m][n + 3] == 1 && map[m][n + 4] == 1)
				return 2;
			if (map[m][n] == 1 && map[m + 1][n] == 1 && map[m + 2][n] == 1 && map[m + 3][n] == 1 && map[m + 4][n] == 1)
				return 2;
			if (map[m][n] == 1 && map[m + 1][n + 1] == 1 && map[m + 2][n + 2] == 1 && map[m + 3][n + 3] == 1 && map[m + 4][n + 4] == 1)
				return 2;
			if (n > 3 && map[m][n] == 1 && map[m + 1][n - 1] == 1 && map[m + 2][n - 2] == 1 && map[m + 3][n - 3] == 1 && map[m + 4][n - 4] == 1)
				return 2;
			if (map[m][n] == 2 && map[m][n + 1] == 2 && map[m][n + 2] == 2 && map[m][n + 3] == 2 && map[m][n + 4] == 2)
				return 2;
			if (map[m][n] == 2 && map[m + 1][n] == 2 && map[m + 2][n] == 2 && map[m + 3][n] == 2 && map[m + 4][n] == 2)
				return 2;
			if (map[m][n] == 2 && map[m + 1][n + 1] == 2 && map[m + 2][n + 2] == 2 && map[m + 3][n + 3] == 2 && map[m + 4][n + 4] == 2)
				return 2;
			if (n > 3 && map[m][n] == 2 && map[m + 1][n - 1] == 2 && map[m + 2][n - 2] == 2 && map[m + 3][n - 3] == 2 && map[m + 4][n - 4] == 2)
				return 2;
		}
	}
	if (flag > MAX_LEN * MAX_LEN)			//棋盘满
	{
		return 3;
	}
	else
	{
		return 1;
	}
}

 //-------------------------------------------rec_loc----------------------------------------------
void rec_loc(int x, int y) {
	loc_cnt++;
	loc[loc_cnt] = x * 10 + y;
}

//-------------------------------------------go_back----------------------------------------------
void go_back(void) {
	int x = loc[loc_cnt] / 10;
	int y = loc[loc_cnt] % 10;
	map[x][y] = 0;//改变数据
	flag = flag ? 0 : 1;//切换下棋者
	gameView();
}

//-------------------------------------------easy----------------------------------------------
int easy() {
	int x = loc[loc_cnt] / 10;
	int y = loc[loc_cnt] % 10;
	int blockingx = 1;
	int blockingy = 1;
	int random1 = rand();
	int random2 = random1;
	if (random1 % 100 < 50) {//50%的概率
		blockingx = 0;
	}
	else blockingx = 1;
	if (random1 % 10 < 5) {
		blockingx *= 1;
	}
	else blockingx *= -1;
	if (random2 / 100 % 100 < 50) {
		blockingy = 0;
	}
	else blockingy = 1;
	blockingy = blockingx ? blockingy : 1;//防止两个都是0
	if (random2 / 100 % 10 < 5) {
		blockingy *= 1;
	}
	else blockingy *= -1;
	x += blockingx;
	y += blockingy;
	srand((unsigned)time(NULL));//改变随机种子
	if (map[x][y] == 0) {//判断是否为空地
		return x * 10 + y;
	}
	else {
		do {
			x += blockingx;
			y += blockingy;
		} while (map[x][y] != 0);
		return x * 10 + y;
	}
}
