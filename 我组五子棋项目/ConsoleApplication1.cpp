////头文件
//#include<stdio.h>
//#include<graphics.h>
//#include<math.h>
//#include<time.h>
//
////函数的声明
//
//void printMap();
//int getUserChoose();
//int fun1(int x, int y);
//void gameView();
//
////全局变量
//int map[15][15] = { 0 }; // 0表示空地   1表示黑子  2表示白子
//int flag = 0; // 1表示黑子,2表示白子
//
//int loc[255]={0};//全局变量
//int loc_cnt=-1;//全局变量
///*
// * 负责人:艾尔崔
// * 参数:无
// * 返回值:无
// * 功能:按顺序记录棋子坐标
// * 调用位置:每次下棋后
// */
//void get_loc(void) {
//    loc_cnt++;
//    loc[loc_cnt]=x*10+y;
//}
///*
// * 负责人:艾尔崔
// * 参数:void
// * 返回值:int x坐标*10+y坐标
// * 功能:解码后得到x y坐标用于清除上一个棋子并更改棋盘数据和切换下棋者
// * 调用位置:点击悔棋后
// */
//int go_back(void){
//    int x=loc[loc_cnt]/10;
//    int y=loc[loc_cnt]%10;
//    clearcircle(x,y,15);//清除图像,半径大1保证清除掉边框
//    map[x][y]=0;//改变数据
//    flag=flag?0:1;//切换下棋者
//}
//
//
//int main()
//{
//
//	//绘制棋盘
//	initgraph(510, 510);			//设置窗口大小
//	gameView();
//	return 0;
//}
//
///*
//*	负责人： 组长
//	1. 初始化数据
//	while(1){
//		2. 打印棋盘
//		3. 接受用户输入
//			接受用户鼠标点击的坐标  根据坐标映射出对应的棋盘下标
//		4. 点击了什么
//			1. 退出游戏： return；
//			2： 点击了棋盘
//		5. 判断用户落点在这里会触发什么情况
//			0： 这里有棋子了 不能落子
//			1： 落子 然后正常运行（没有胜利， 没有满格）
//			2： 胜利
//			3： 平手（棋盘满了）
//
//		6. 如果是落子， 切换flag的值
//			如果是0： 提示用户操作错误  重新操作
//			如果是2： 提示胜利
//			如果是3： 提示平局
//	}
//
//*/
//void gameView()
//{
//
//	while (1) {
//		printMap();
//		int result = getUserChoose();
//		if (result == 1)return;
//
//		int c = result / 100;
//		int d = result % 100;
//		result = fun1(c, d);
//
//		if (result == 0) {
//			continue;
//		}
//		else if (result == 1) {
//		}
//		else if (result == 2) {
//			return;
//		}
//		else if (result == 3) {
//			return;
//		}
//
//		flag = flag ? 0 : 1;
//
//
//	}
//	return;
//}
//
///*-----------------------------------------2.绘制棋盘-------------------------------------------
//*	负责人： 组长
//	绘制棋盘， 0表示空地， 1表示黑子， 2表示白子
//*/
//void printMap()
//{
//	setbkcolor(BROWN);             //设置背景颜色，棕色
//	cleardevice();
//	setlinecolor(WHITE);           //设置线条颜色，白色         
//	for (int i = 30; i <= 480; i += 30)	//使用for循环绘制棋盘
//	{
//		line(i, 30, i, 480);
//		line(30, i, 480, i);
//	}
//	for (int i = 120; i < 400; i += 270)
//	{
//		for (int j = 120; j < 400; j += 270) {
//			fillcircle(i, j, 3);//不被后面影响
//		}
//	}
//
//
//	for (int i = 0; i < 15; i++) {
//		for (int j = 0; j < 15; j++) {
//			if (map[i][j] != 0) {
//				if (map[i][j] == 1)
//				{
//					int a = 30 + i * 30;
//					int b = 30 + j * 30;
//					setfillcolor(BLACK);
//
//					fillcircle(a, b, 10);
//				}
//				else {
//					int a = 30 + i * 30;
//					int b = 30 + j * 30;
//					setfillcolor(WHITE);
//
//					fillcircle(a, b, 10);
//				}
//
//			}
//
//
//		}
//	}
//	
//}
//
//
//int getUserChoose()
//{
//
//	//鼠标
//	MOUSEMSG m;//保存鼠标信息
//	int x, y;//定义鼠标坐标
//	int a, b;//数组下标
//
//	while (1)
//	{
//		m = GetMouseMsg();//获取一个鼠标的信息
//
//	//下在点上，30的倍数,辨认每一个点,abs：绝对值
//
//		if (m.uMsg == WM_LBUTTONDOWN)
//		for (int i = 1; i < 15; i++)//遍历整个棋盘
//		{
//			for (int j = 1; j < 15; j++)
//			{
//				//判断鼠标点击是否在每个下棋点附近
//				if (abs(m.x - i * 30) < 15 && abs(m.y - j * 30) < 15)
//				{
//					x = i * 30;//有问题
//					y = j * 30;
//					a = i;
//					b = j;
//					return a*100 + b;
//				}
//			}
//		}
//
//	}
//	//while (true)
//	//{
//	//	MOUSEMSG m;
//	//	m = GetMouseMsg();
//	//	if (m.uMsg == WM_LBUTTONDOWN)
//	//	{
//	//		return 100 * (int)(m.x - 20) / 30 + (int)(m.y - 20) / 30;
//	//	}
//	//}
//	//return -1;
//}
//
//
//
//int fun1(int x, int y)
//{
//	if (map[x][y] != 0)     //位置有棋子
//	{
//		return 0;
//	}
//	else					//位置无棋子
//	{
//		if (flag % 2 == 0)  //判断黑色还是白色棋子
//		{
//			map[x][y] = 1;
//			setfillcolor(BLACK);
//			fillcircle(x, y, 14);
//		}
//		else
//		{
//			map[x][y] = 2;
//			setfillcolor(WHITE);
//			fillcircle(x, y, 14);
//		}
//	}
//
//	int m, n;
//	for (m = 0; m < 15; m++)	//判断胜负
//	{
//		for (n = 0; n < 15; n++)//会溢出
//		{
//			if (map[m][n] == 1 && map[m][n + 1] == 1 && map[m][n + 2] == 1 && map[m][n + 3] == 1 && map[m][n + 4] == 1)
//				return 2;
//			if (map[m][n] == 1 && map[m + 1][n] == 1 && map[m + 2][n] == 1 && map[m + 3][n] == 1 && map[m + 4][n] == 1)
//				return 2;
//			if (map[m][n] == 1 && map[m + 1][n + 1] == 1 && map[m + 2][n + 2] == 1 && map[m + 3][n + 3] == 1 && map[m + 4][n + 4] == 1)
//				return 2;
//			if (n > 3 && map[m][n] == 1 && map[m + 1][n - 1] == 1 && map[m + 2][n - 2] == 1 && map[m + 3][n - 3] == 1 && map[m + 4][n - 4] == 1)
//				return 2;
//			if (map[m][n] == 2 && map[m][n + 1] == 2 && map[m][n + 2] == 2 && map[m][n + 3] == 2 && map[m][n + 4] == 2)
//				return 2;
//			if (map[m][n] == 2 && map[m + 1][n] == 2 && map[m + 2][n] == 2 && map[m + 3][n] == 2 && map[m + 4][n] == 2)
//				return 2;
//			if (map[m][n] == 2 && map[m + 1][n + 1] == 2 && map[m + 2][n + 2] == 2 && map[m + 3][n + 3] == 2 && map[m + 4][n + 4] == 2)
//				return 2;
//			if (n > 3 && map[m][n] == 2 && map[m + 1][n - 1] == 2 && map[m + 2][n - 2] == 2 && map[m + 3][n - 3] == 2 && map[m + 4][n - 4] == 2)
//				return 2;
//		}
//	}
//	if (flag > 225)			//棋盘满
//	{
//		return 3;
//	}
//	else
//	{
//		return 1;
//	}
//}
