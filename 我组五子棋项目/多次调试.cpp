//头文件
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define MAX_LEN 16
#define A(ABC) 

//全局变量
//int map[MAX_LEN][MAX_LEN] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,1,2,1,2,1};
//int loc[225] = { 28,29,,3,4 };
//int loc_cnt = 4;
int loc[225] = { 0 };
int loc_cnt = -1;
int map[MAX_LEN][MAX_LEN] = { 0 }; // 0表示空地   1表示黑子  2表示白子
int flag = 0; // 1表示黑子,2表示白子

//函数的声明
void printMap();
int getUserChoose();
int fun1(int x, int y);
void gameView();
void rec_loc(int x, int y);
void go_back(int i);


/*
 * 负责人:艾尔崔
 * 参数:void
 * 返回值:AI下棋的坐标 x*10+y
 * 功能:
 * 调用位置:点击悔棋后
 */
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

int main()
{

	//绘制棋盘
	initgraph(510, 510);	//设置窗口大小
	A(flag)
	gameView();
	A(loc_cnt)
	return 0;
}

/*
*	负责人： 组长
	1. 初始化数据
	while(1){
		2. 打印棋盘
		3. 接受用户输入
			接受用户鼠标点击的坐标  根据坐标映射出对应的棋盘下标
		4. 点击了什么
			1. 退出游戏： return；
			2： 点击了棋盘
		5. 判断用户落点在这里会触发什么情况
			0： 这里有棋子了 不能落子
			1： 落子 然后正常运行（没有胜利， 没有满格）
			2： 胜利
			3： 平手（棋盘满了）

		6. 如果是落子， 切换flag的值
			如果是0： 提示用户操作错误  重新操作
			如果是2： 提示胜利
			如果是3： 提示平局
	}

*/
void gameView()
{

	while (1) {
		printMap();
		int result = getUserChoose();
		if (result == 1)return;//也许是出错退出

		int c = result / 100;
		int d = result % 100;//一个变量多用
		result = fun1(c, d);

		if (result == 0) {
			continue;
		}
		else if (result == 1) {
		}
		else if (result == 2) {
			return;
		}
		else if (result == 3) {
			return;
		}

		flag = flag ? 0 : 1;

	}
	return;
}

/*-----------------------------------------2.绘制棋盘-------------------------------------------
*	负责人： 组长
	绘制棋盘， 0表示空地， 1表示黑子， 2表示白子
*/
void printMap()
{
	BeginBatchDraw();//解决闪烁问题
	setbkcolor(BROWN);         //设置背景颜色，棕色
	cleardevice();
	setlinecolor(WHITE);           //设置线条颜色，白色         
	for (int i = 30; i <= 480; i += 30)	//使用for循环绘制棋盘
	{
		line(i, 30, i, 480);
		line(30, i, 480, i);
	}
	for (int i = 120; i < 400; i += 270)//只执行一次就好 或者调色  但都没用 小点还是会变色
	{
		for (int j = 120; j < 400; j += 270)
			fillcircle(i, j, 3);//不被后面影响
	}



	for (int i = 0; i < MAX_LEN; i++) {//画棋子
		for (int j = 0; j < MAX_LEN; j++) {
			if (map[i][j] != 0) {
				if (map[i][j] == 1)
				{
					int a = 30 + i * 30;
					int b = 30 + j * 30;
					setfillcolor(BLACK);

					fillcircle(a, b, 10);
				}
				else {
					int a = 30 + i * 30;
					int b = 30 + j * 30;
					setfillcolor(WHITE);

					fillcircle(a, b, 10);
				}

			}


		}
	}
	EndBatchDraw();
}


int getUserChoose()
{

	//鼠标
	MOUSEMSG m;//保存鼠标信息
	//int x, y;//定义鼠标坐标
	int a, b;//数组下标
	/*x = 0;
	while (x < 100) {//不知道干嘛的
		x++;

	}*/
	while (1)
	{


		//下在点上，30的倍数,辨认每一个点,abs：绝对值
		for (int i = loc_cnt; 1; i--)
		{
			m = GetMouseMsg();//获取一个鼠标的信息
			switch (m.uMsg)
			{
			case WM_RBUTTONDOWN:
				A(i)
				go_back(i);
				continue;
			case WM_LBUTTONDOWN:
				for (int i = 0; i < MAX_LEN; i++)
				{
					for (int j = 0; j < MAX_LEN; j++)
					{
						if (abs(m.x - 30 - i * 30) < MAX_LEN && abs(m.y - 30 - j * 30) < MAX_LEN)
						{
							//x = i * 30-45;              //有问题
							//y = j * 30-45;
							a = i;
							b = j;
							return a * 100 + b;
						}
					}
				}
			}
		}
	}
	//while (true)//再次获取？没用？
	//{
	//	MOUSEMSG m;
	//	m = GetMouseMsg();
	//	if (m.uMsg == WM_LBUTTONDOWN)
	//	{
	//		return 100 * (int)(m.x - 30) / 30 + (int)(m.y - 30) / 30;
	//	}
	//}
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
		if (flag % 2 == 0)  //判断黑色还是白色棋子
		{
			map[x][y] = 1;
			setfillcolor(BLACK);//不注释这个可以减少小点变色,玄学//小点只在部分点下棋后变色且每次运行相同
			//fillcircle(x, y, 14);
		}
		else
		{
			map[x][y] = 2;
			//setfillcolor(WHITE);//实际上没有乘以像素倍率，只能打印到左上然后被清除
			//fillcircle(x, y, 14);
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
/*
 * 负责人:艾尔崔
 * 参数:x,y
 * 返回值:无
 * 功能:按顺序记录棋子坐标
 * 调用位置:每次下棋后
 */
void rec_loc(int x, int y) {
	loc_cnt++;
	loc_cnt = loc_cnt < 0 ? 0 : loc_cnt;
	loc[loc_cnt] = x * 100 + y;
}
/*
 * 负责人:艾尔崔
 * 参数:void
 * 返回值:
 * 功能:解码后得到x y坐标用于清除上一个棋子并更改棋盘数据和切换下棋者
 * 调用位置:点击悔棋后
 */
void go_back(int i) {
	int x = loc[i] / 100;A(x)
	int y = loc[i] % 100;A(y)
	map[x][y] = 0;//改变数据
	gameView();
	loc_cnt = i;A(loc_cnt)
	flag = flag ? 0 : 1;//切换下棋者
}