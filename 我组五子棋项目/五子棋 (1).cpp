//ͷ�ļ�
#include<stdio.h>
#include<graphics.h>
#include<math.h>

//����������
void printMap();
int getUserChoose();
int fun1(int x, int y);
void gameView();

//ȫ�ֱ���
int map[15][15] = {0}; // 0��ʾ�յ�   1��ʾ����  2��ʾ����
int flag=0; // 1��ʾ����,2��ʾ����

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

/*-----------------------------------------2.��������-------------------------------------------
*	�����ˣ� �鳤
	�������̣� 0��ʾ�յأ� 1��ʾ���ӣ� 2��ʾ����
*/
void printMap()
{
	//��������
		initgraph(510, 510);			//���ô��ڴ�С
		setbkcolor(BROWN);             //���ñ�����ɫ����ɫ
		cleardevice(); 
		setlinecolor(WHITE);           //����������ɫ����ɫ         
		for (int i = 30; i <= 480; i += 30)	//ʹ��forѭ����������
		{
			line(i, 30, i, 480);
			line(30, i, 480, i);
		}
		for (int i = 120; i < 400; i += 270)
		{
			for (int j = 120; j < 400; j += 270)
				fillcircle(i, j, 3);//��������Ӱ��
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

	//���
	MOUSEMSG m;//���������Ϣ
	int x, y;//�����������
	int a, b;//�����±�

	while (1)
	{
		m = GetMouseMsg();//��ȡһ��������Ϣ

	//���ڵ��ϣ�30�ı���,����ÿһ����,abs������ֵ
		for (int i = 1; i < 15; i++)
		{
			for (int j = 1; j < 15; j++)
			{
				if (abs(m.x - i * 30) < 15 && abs(m.y - i * 30) < 15)
				{
					x = i * 30;//������
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
	if (map[x][y] != 0)     //λ��������
	{
		return 0;
	}
	else					//λ��������
	{
		flag++;
		if (flag % 2 == 0)  //�жϺ�ɫ���ǰ�ɫ����
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
	for (m = 0; m < 15; m++)	//�ж�ʤ��
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
	if (flag > 225)			//������
	{
		return 3;
	}
	else
	{
		return 1;
	}
}