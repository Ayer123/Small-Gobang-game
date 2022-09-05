#include<stdio.h>
#include<graphics.h>

void printMap();

int map[15][15] = { 0 }; // 0表示空地   1表示黑子  2表示白子
int flag; // 1表示黑子,2表示白子


int main() {
	printMap();
	return 0;

}


/*
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


