////ͷ�ļ�
//#include<stdio.h>
//#include<graphics.h>
//#include<math.h>
//#include<time.h>
//#include<stdlib.h>
//#define MAX_LEN 16
////ȫ�ֱ���
//int loc[255] = { 0 };
//int loc_cnt = -1;
//int map[MAX_LEN][MAX_LEN] = { 0 }; // 0��ʾ�յ�   1��ʾ����  2��ʾ����
//int flag = 0; // 1��ʾ����,2��ʾ����
//int CHESS = 0;//���ӣ�����result==2ʱ
//
//
////����������
//void printMap();
//void printCHESS();
//int getUserChoose();
//int fun1(int x, int y);
//void gameView();
//void rec_loc(int x, int y);
//void go_back(void);
//
//
///*
// * ������:������
// * ����:void
// * ����ֵ:AI��������� x*10+y
// * ����:
// * ����λ��:��������
// */
//int easy() {
//	int x = loc[loc_cnt] / 10;
//	int y = loc[loc_cnt] % 10;
//	int blockingx = 1;
//	int blockingy = 1;
//	int random1 = rand();
//	int random2 = random1;
//	if (random1 % 100 < 50) {//50%�ĸ���
//		blockingx = 0;
//	}
//	else blockingx = 1;
//	if (random1 % 10 < 5) {
//		blockingx *= 1;
//	}
//	else blockingx *= -1;
//	if (random2 / 100 % 100 < 50) {
//		blockingy = 0;
//	}
//	else blockingy = 1;
//	blockingy = blockingx ? blockingy : 1;//��ֹ��������0
//	if (random2 / 100 % 10 < 5) {
//		blockingy *= 1;
//	}
//	else blockingy *= -1;
//	x += blockingx;
//	y += blockingy;
//	srand((unsigned)time(NULL));//�ı��������
//	if (map[x][y] == 0) {//�ж��Ƿ�Ϊ�յ�
//		return x * 10 + y;
//	}
//	else {
//		do {
//			x += blockingx;
//			y += blockingy;
//		} while (map[x][y] != 0);
//		return x * 10 + y;
//	}
//}
//
//
////-------------------------------------------main----------------------------------------------
//int main()
//{
//
//	initgraph(600, 510);//���ô��ڴ�С
//	gameView();
//	return 0;
//}
//
///*
//*	�����ˣ� �鳤
//	1. ��ʼ������
//	while(1){
//		2. ��ӡ����
//		3. �����û�����
//			�����û������������  ��������ӳ�����Ӧ�������±�
//		4. �����ʲô
//			-1. �˳���Ϸ�� return��
//			2�� ���������
//		5. �ж��û����������ᴥ��ʲô���
//			0�� ������������ ��������
//			1�� ���� Ȼ���������У�û��ʤ���� û������
//			2�� ʤ��
//			3�� ƽ�֣��������ˣ�
//
//		6. ��������ӣ� �л�flag��ֵ
//			�����0�� ��ʾ�û���������  ���²���
//			�����2�� ��ʾʤ��
//			�����3�� ��ʾƽ��
//	}
//
//*/
////-------------------------------------------gameView----------------------------------------------
//void gameView()
//{
//	printMap();
//	while (1) {
//		printCHESS();//��ӡ����
//		int result = getUserChoose();
//		
//		if (result == -1)return;//Ҳ���ǳ����˳�
//		int c = result / 100;
//		int d = result % 100;//һ����������
//		result = fun1(c, d);
//		printCHESS();//��ӡ����
//		if (result == 0) {
//			MessageBox(NULL, " ��ʾ�û���������  ���²���                                                                   ", "��ʾ", MB_OK | MB_SYSTEMMODAL);
//			continue;
//		}
//		else if (result == 1) {
//
//
//		}
//		else if (result == 2) {
//			if (CHESS == 1) {
//				MessageBox(NULL, "                                  ����ʤ��                                  ", "��ʾ", MB_OK | MB_SYSTEMMODAL);//��ʾ����ʤ��
//			}
//			else {
//				MessageBox(NULL, "                                  ����ʤ��                                  ", "��ʾ", MB_OK | MB_SYSTEMMODAL);//��ʾ����ʤ��
//
//			}
//			return;
//		}
//		else if (result == 3) {
//			MessageBox(NULL, "                                  ƽ��                                  ", "��ʾ", MB_OK | MB_SYSTEMMODAL);//��ʾƽ��
//			
//
//			return;
//		}
//
//		flag = flag ? 0 : 1;
//
//	}
//	return;
//}
//
////-----------------------------------------printMap-------------------------------------------
//
//void printMap()
//{
//	loadimage(NULL, "1.jpg", 600, 510);
//	setlinecolor(WHITE);           //����������ɫ����ɫ         
//	for (int i = 30; i <= 480; i += 30)	//ʹ��forѭ����������
//	{
//		line(i, 30, i, 480);
//		line(30, i, 480, i);
//	}
//	for (int i = 120; i < 400; i += 270)//ִֻ��һ�ξͺ� ���ߵ�ɫ
//	{
//		for (int j = 120; j < 400; j += 270)
//			circle(i, j, 3);//��������Ӱ��
//	}
//	return;
//}
//
////-------------------------------------------printCHESS----------------------------------------------
//void printCHESS() {
//	for (int i = 0; i < MAX_LEN; i++) {//������
//		for (int j = 0; j < MAX_LEN; j++) {
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
//	return;
//}
//
////-------------------------------------------getUserChoose----------------------------------------------
//int getUserChoose()
//{
//
//	//���
//	MOUSEMSG m;//���������Ϣ
//	int a, b;//�����±�
//	while (1)
//	{
//		m = GetMouseMsg();//��ȡһ��������Ϣ
//
//		//���ڵ��ϣ�30�ı���,����ÿһ����,abs������ֵ
//		if (m.uMsg == WM_RBUTTONDOWN) {
//			go_back();
//		}
//		if (m.uMsg == WM_LBUTTONDOWN) {
//			for (int i = 0; i < MAX_LEN; i++)
//			{
//				for (int j = 0; j < MAX_LEN; j++)
//				{
//					if (abs(m.x - 30 - i * 30) < MAX_LEN && abs(m.y - 30 - j * 30) < MAX_LEN)
//					{
//						
//						a = i;
//						b = j;
//						return a * 100 + b;
//						
//					}
//				}
//			}
//		}
//
//	}
//
//}
//
//
////-------------------------------------------fun1----------------------------------------------
//int fun1(int x, int y)
//{
//	if (map[x][y] != 0)     //λ��������
//	{
//		return 0;
//	}
//	else					//λ��������
//	{
//		if (flag % 2 == 0)  //�жϺ�ɫ���ǰ�ɫ����
//		{
//			map[x][y] = 1;
//			CHESS = 1;
//		}
//		else
//		{
//			map[x][y] = 2;
//			CHESS = 2;
//		}
//	}
//	rec_loc(x, y);
//	int m, n;
//	for (m = 0; m < MAX_LEN; m++)	//�ж�ʤ��
//	{
//		for (n = 0; n < MAX_LEN; n++)
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
//	if (flag > MAX_LEN * MAX_LEN)			//������
//	{
//		return 3;
//	}
//	else
//	{
//		return 1;
//	}
//}
//
///*
// * ������:������
// * ����:x,y
// * ����ֵ:��
// * ����:��˳���¼��������
// * ����λ��:ÿ�������
// */
//void rec_loc(int x, int y) {
//	loc_cnt++;
//	loc[loc_cnt] = x * 10 + y;
//}
///*
// * ������:������
// * ����:void
// * ����ֵ:
// * ����:�����õ�x y�������������һ�����Ӳ������������ݺ��л�������
// * ����λ��:��������
// */
//void go_back(void) {
//	int x = loc[loc_cnt] / 10;
//	int y = loc[loc_cnt] % 10;
//	map[x][y] = 0;//�ı�����
//	flag = flag ? 0 : 1;//�л�������
//	gameView();
//}