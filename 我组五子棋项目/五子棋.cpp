#include<stdio.h>
#include<graphics.h>

void printMap();

int map[15][15] = { 0 }; // 0��ʾ�յ�   1��ʾ����  2��ʾ����
int flag; // 1��ʾ����,2��ʾ����


int main() {
	printMap();
	return 0;

}


/*
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


