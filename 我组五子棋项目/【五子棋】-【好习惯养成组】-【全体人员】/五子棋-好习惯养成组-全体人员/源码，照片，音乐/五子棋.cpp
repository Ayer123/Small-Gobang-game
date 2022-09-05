//ͷ�ļ�
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

//ȫ�ֱ���
int loc[255] = { 0 };
int loc_cnt = -1;
int map[MAX_LEN][MAX_LEN] = { 0 }; // 0��ʾ�յ�   1��ʾ����  2��ʾ����
int flag = 0; // 1��ʾ����,2��ʾ����
int CHESS = 0;//���ӣ�����result==2��

//����������
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
	initgraph(610, 510);//���ô��ڴ�С
	change();
	MUSIC();
	gameView();
	return 0;
}

//-------------------------------------------MUSIC----------------------------------------------
void MUSIC() {
	//alias   ��������ȡ����
	mciSendString("open  1.mp3 alias a ", 0, 0, 0);//�����ڵ�ǰĿ¼��Ҳ����д"open ./2.mp3"./�������ʡ��
	mciSendString("play a repeat", 0, 0, 0);//�������֣�ѭ������
	//mciSendString("close a", 0, 0, 0); // close �رղ���
	//system("pause");//����û����ͣ�����ֱ��ֹͣ����������
	return;
}

//-------------------------------------------change----------------------------------------------
void change() {
	HWND well = GetHWnd();//��ȡ�����ֱ�
	SetWindowText(well, "��ϰ��������--������");//���ô��ڱ���
}

//-------------------------------------------gameView----------------------------------------------
void gameView()
{
	printMap();//��ӡ����
	while (1) {
		printCHESS();//��ӡ����                                 //
		int result = getUserChoose();
		if (result == -1)return;
		int c = result / 100;
		int d = result % 100;
		result = fun1(c, d);
		printCHESS();//��ӡ����
		if (result == 0) {
			MessageBox(NULL, "                           ��������������ѡ                        ", "��ʾ", MB_OK | MB_SYSTEMMODAL);//������������
			continue;
		}
		else if (result == 1) {
		}
		else if (result == 2) {
			if (CHESS == 1) {
				MessageBox(NULL, "                                  ����ʤ��                                  ", "��ʾ", MB_OK | MB_SYSTEMMODAL);//��ʾ����ʤ��
			}
			else {
				MessageBox(NULL, "                                  ����ʤ��                                  ", "��ʾ", MB_OK | MB_SYSTEMMODAL);//��ʾ����ʤ��

			}
			return;
		}
		else if (result == 3) {
			MessageBox(NULL, "                                  ƽ��                                  ", "��ʾ", MB_OK | MB_SYSTEMMODAL);//��ʾƽ��


			return;
		}

		flag = flag ? 0 : 1;

	}
	return;
}

//-----------------------------------------printMap-------------------------------------------
void printMap()
{
	setbkcolor(WHITE);//���ñ�����ɫ
	cleardevice();	//����
	loadimage(NULL, "9.jpg", 610, 510);
	setlinecolor(WHITE);           //����������ɫ����ɫ         
	for (int i = 30; i <= 480; i += 30)	//ʹ��forѭ����������
	{
		line(i, 30, i, 480);
		line(30, i, 480, i);
	}
	for (int i = 120; i < 400; i += 270)
	{
		for (int j = 120; j < 400; j += 270)
			circle(i, j, 3);//��������Ӱ��
	}
	//����������ɫ
	settextcolor(RGB(203, 120, 71));
	//����������ʽ
	setlinestyle(PS_SOLID, 1);
	//�������������
	settextstyle(30, 10, "����");
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//���������ɫ
	setfillcolor(LIGHTGRAY);
	//�������,��
	fillrectangle(485, 178, 600, 208);
	outtextxy(485, 178, "����ѡ��");
	fillrectangle(485, 450, 600, 480);
	outtextxy(485, 450, "����ѡ��");

	//��
	fillrectangle(485, 20, 600, 180);
	//����ͼƬ
	IMAGE ddg;
	//����ͼƬ
	loadimage(&ddg, "1.jpg", 115, 160);
	//��ͼ
	putimage(485, 20, &ddg);
	//��
	fillrectangle(485, 300, 600, 450);
	//����ͼƬ
	IMAGE yunhai;
	//����ͼƬ
	loadimage(&yunhai, "6.jpg", 115, 160);
	//��ͼ
	putimage(485, 290, &yunhai);

	return;
}

//-------------------------------------------printCHESS----------------------------------------------
void printCHESS() {
	for (int i = 0; i < MAX_LEN; i++) {//������
		for (int j = 0; j < MAX_LEN; j++) {
			if (map[i][j] != 0) {
				if (map[i][j] == 1)
				{
					int a = 30 + i * 30;
					int b = 30 + j * 30;
					setfillcolor(BLACK);
					setlinecolor(LIGHTCYAN);           //����������ɫ����ɫ     
					fillcircle(a, b, 8);

				}
				else {
					int a = 30 + i * 30;
					int b = 30 + j * 30;
					setfillcolor(WHITE);
					setlinecolor(RED);           //����������ɫ����ɫ         
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

	//���
	MOUSEMSG m;//���������Ϣ
	int a, b;//�����±�
	while (1)
	{
		m = GetMouseMsg();//��ȡһ��������Ϣ
		//���ڵ��ϣ�30�ı���,����ÿһ����,abs������ֵ
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
	if (map[x][y] != 0)     //λ��������
	{
		return 0;
	}
	else					//λ��������
	{
		if (flag % 2 == 0)  //�жϺ�ɫ���ǰ�ɫ����
		{
			map[x][y] = 1;
			CHESS = 1;//����
		}
		else
		{
			map[x][y] = 2;
			CHESS = 2;
		}
	}
	rec_loc(x, y);
	int m, n;
	for (m = 0; m < MAX_LEN; m++)	//�ж�ʤ��
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
	if (flag > MAX_LEN * MAX_LEN)			//������
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
	map[x][y] = 0;//�ı�����
	flag = flag ? 0 : 1;//�л�������
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
	if (random1 % 100 < 50) {//50%�ĸ���
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
	blockingy = blockingx ? blockingy : 1;//��ֹ��������0
	if (random2 / 100 % 10 < 5) {
		blockingy *= 1;
	}
	else blockingy *= -1;
	x += blockingx;
	y += blockingy;
	srand((unsigned)time(NULL));//�ı��������
	if (map[x][y] == 0) {//�ж��Ƿ�Ϊ�յ�
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
