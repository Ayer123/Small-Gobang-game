#include"Game.h"

//view�㺯��
void Login_Page();		//��¼����
void Signin_Page();		//ע�����
void Forget_Page();		//�����������
void Menu_Page();		//�˵�����
void Rank_Page();		//���а����
void Developer_Page();	//������Ա���
void Tips_Page();		//��Ϸ���
void Game_Page();		//��Ϸҳ��
void Pause_Page();		//��ͣҳ��
void Shop_Page();		//�̳�ҳ��
void Victory_Page();	//��Ϸʤ��ҳ��
void Perish_Page();		//��Ϸʧ��ҳ��
void Display_Link_Login();//��ʾ��¼���������
void Get_Mouse_Login();//��¼���洦�������Ϣ
void Display_Link_Menu();//��ʾ�˵�ҳ�������
void Get_Mouse_Menu();//��ȡ�˵�ҳ�û�����������ȡ�ж�
void Put_Me();//��ӡ���
void Put_Bul();//��ӡ�ӵ���ʵ�����ƶ�
void Put_Objects();//��ӡ������
void Put_Mark();//��ӡ����
void Put_HP();//��ӡѪ��
void Put_Enemies();//��ӡ���˲�ʵ�����ƶ�
void Get_Keyboard_Game();//������Ϸ����ҵ��ƶ�����ͣ������Ϣ
void Flush_Game_bk();//��ʾ��Ϸ������ƶ�����
void Move_Me();//���ݼ������룬�޸����λ��
void Shooting();//����������

//���õĹ��ܡ�ȫ�ֱ���
void login();
void registered();
void PassBack();
void Set_Is_Live();
int Me_and_Bullet();
int Me_and_Enemy();
int Me_and_Object();
int Enemy_and_Bullet();
void Load_Game_Res();
void Make_Enemy();
void Enemy_Shooting();
void save_score(int mark);
void rank(int uid);
void Init_Player_Bul(double angle);
void save_score(int mark);
void file_read();
void Buy();
char* int_str(char* str, int num);
void all_free();
extern MOUSEMSG Mouse;
extern Player Me;
extern int mark;
extern int uid;
extern int bk_flush;
extern int enemy_batch;
extern int increase_bul_times;
extern bool is_victory;
extern bool boss_big_bul;
extern bool start_shooting;
extern Object objects[50];
extern Enemy enemies[50];
extern Bullet bullets[500];
extern clock_t game_start, game_moment;
extern clock_t start_shoot;
extern clock_t moment_shoot;
extern User* head, * p, * p1, * p2;
extern IMAGE* Page[18];
extern IMAGE* Bul_Image[8][2];
extern IMAGE* Obj_Image[10][2];
extern IMAGE* Ene_Image[12][2];
extern IMAGE* Me_Image[4][2];


//��������������������������������������������������¼������ء�����������������������������������������������
void Login_Page() {
	//��ӡ����ͼ
	loadimage(Page[0], "./res/image/��¼����/login_page.png");
	putimage(0, 0, Page[0]);
	//��ʾ��ť���ȴ��û�����
	Display_Link_Login();
	Get_Mouse_Login();
}
void Display_Link_Login() {
	//���ֵĸ�ʽ
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	//�������������ɫ
	setfillcolor(RGB(34, 249, 255));
	//���ƾ��κ�������֣�����ʾ��ť����
	fillroundrect(Login_L, Login_T, Login_R, Login_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("��¼") / 2,
		GR_Height / 2 + 100 - textheight("��¼") / 2,
		"��¼");
	fillroundrect(Signin_L, Signin_T, Signin_R, Signin_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("ע��") / 2,
		GR_Height / 2 + 200 - textheight("ע��") / 2,
		"ע��");
	fillroundrect(Forget_L, Forget_T, Forget_R, Forget_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("��������") / 2,
		GR_Height / 2 + 300 - textheight("��������") / 2,
		"��������");
	fillroundrect(Exit_L, Exit_T, Exit_R, Exit_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("�˳�") / 2,
		GR_Height / 2 + 400 - textheight("�˳�") / 2,
		"�˳�");
}
void Get_Mouse_Login() {
	//��ѭ����ȡ�û���������룬��ȡ��֮��Ҫ��ת����Ӧҳ�沢�˳�ѭ��
	while (1) {
		if (MouseHit()) {
			//��ȡ�����Ϣ
			Mouse = GetMouseMsg();
			//�û�������ڰ�ť��Χ�ڣ����Ұ������
			if (Mouse.x >= Login_L && Mouse.x <= Login_R &&
				Mouse.y >= Login_T && Mouse.y <= Login_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//��¼����
				login();
				break;
			}
			else if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
				Mouse.y >= Signin_T && Mouse.y <= Signin_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//ע��ҳ��
				Signin_Page();
				break;
			}
			else if (Mouse.x >= Forget_L && Mouse.x <= Forget_R &&
				Mouse.y >= Forget_T && Mouse.y <= Forget_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//�����������
				Forget_Page();
				break;
			}
			else if (Mouse.x >= Exit_L && Mouse.x <= Exit_R &&
				Mouse.y >= Exit_T && Mouse.y <= Exit_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//ֱ���˳�����
				exit(0);
			}
		}
	}
}

//������������������������������������������������ע�������ء�����������������������������������������������
void Signin_Page() {
	//���÷�װ�õ�ע�����
	registered();
}

//�������������������������������������������������������������ء�����������������������������������������������
void Forget_Page() {
	//���÷�װ�õ������������
	PassBack();
}

//�������������������������������������������������˵�������ء�����������������������������������������������
void Menu_Page() {
	//���������Դ
	loadimage(Page[3], "./res/image/�˵�����/menu_page.png");
	//չʾ����ͼ
	putimage(0, 0, Page[3]);
	//��ʾ��������ȡ�û��������
	Display_Link_Menu();
	Get_Mouse_Menu();
}
void Display_Link_Menu() {
	//�������ָ�ʽ
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	//���þ�������ʽ
	setfillcolor(RGB(135, 135, 135));
	//���Ƹ�������
	fillroundrect(Game_L, 250, Game_R, 310, 10, 10);
	outtextxy(GR_Width - textwidth("�̵�") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 - 200 - textheight("�̵�") / 2,
		"�̵�");
	fillroundrect(Game_L, Game_T, Game_R, Game_B, 10, 10);
	outtextxy(GR_Width - textwidth("��ʼ��Ϸ") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 - 100 - textheight("��ʼ��Ϸ") / 2,
		"��ʼ��Ϸ");
	fillroundrect(Rank_L, Rank_T, Rank_R, Rank_B, 10, 10);
	outtextxy(GR_Width - textwidth("���а�") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 - textheight("���а�") / 2,
		"���а�");
	fillroundrect(Tips_L, Tips_T, Tips_R, Tips_B, 10, 10);
	outtextxy(GR_Width - textwidth("��Ϸ���") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 + 100 - textheight("��Ϸ���") / 2,
		"��Ϸ���");
	fillroundrect(Developer_L, Developer_T, Developer_R, Developer_B, 10, 10);
	outtextxy(GR_Width - textwidth("������Ա���") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 + 200 - textheight("������Ա���") / 2,
		"������Ա���");
	fillroundrect(Logout_L, Logout_T, Logout_R, Logout_B, 10, 10);
	outtextxy(GR_Width - textwidth("�˳���¼") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 + 300 - textheight("�˳���¼") / 2,
		"�˳���¼");
	fillroundrect(Exit_Menu_L, Exit_Menu_T, Exit_Menu_R, Exit_Menu_B, 10, 10);
	outtextxy(GR_Width - textwidth("�˳���Ϸ") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 + 400 - textheight("�˳���Ϸ") / 2,
		"�˳���Ϸ");
}
void Get_Mouse_Menu() {
	//��ѭ����ȡ�û���������룬��ȡ��֮��Ҫ��ת����Ӧҳ�沢�˳�ѭ��
	while (1) {
		if (MouseHit()) {
			//��ȡ�����Ϣ
			Mouse = GetMouseMsg();
			//�û�������ڰ�ť��Χ�ڣ����Ұ������
			if (Mouse.x >= Game_L && Mouse.x <= Game_R &&
				Mouse.y >= Game_T && Mouse.y <= Game_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//��Ϸ����
				Game_Page();
				break;
			}
			else if (Mouse.x >= Game_L && Mouse.x <= Rank_R &&
				Mouse.y >= 250 && Mouse.y <= 310 &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//�̵�ҳ��
				Shop_Page();
				break;
			}
			else if (Mouse.x >= Rank_L && Mouse.x <= Rank_R &&
				Mouse.y >= Rank_T && Mouse.y <= Rank_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//���а�ҳ��
				Rank_Page();
				break;
			}
			else if (Mouse.x >= Tips_L && Mouse.x <= Tips_R &&
				Mouse.y >= Tips_T && Mouse.y <= Tips_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//��Ϸ������
				Tips_Page();
				break;
			}
			else if (Mouse.x >= Developer_L && Mouse.x <= Developer_R &&
				Mouse.y >= Developer_T && Mouse.y <= Developer_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//������Ա������
				Developer_Page();
				break;
			}
			else if (Mouse.x >= Logout_L && Mouse.x <= Logout_R &&
				Mouse.y >= Logout_T && Mouse.y <= Logout_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//���ص���¼����
				Login_Page();
				break;
			}
			else if (Mouse.x >= Exit_Menu_L && Mouse.x <= Exit_Menu_R &&
				Mouse.y >= Exit_Menu_T && Mouse.y <= Exit_Menu_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//�˳�����
				exit(0);
				break;
			}
		}
	}
}

//���������������������������������������������������н�����ء�����������������������������������������������
void Rank_Page() {
	//���������Դ
	loadimage(Page[4], "./res/image/���н���/rank_page.png");
	//չʾ����ͼ
	putimage(0, 0, Page[4]);
	//չʾ��������ȡ�����Ϣ
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	setfillcolor(RGB(255, 255, 255));
	fillroundrect(Exit_L, Exit_T, Exit_R, Exit_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("����") / 2,
			GR_Height / 2 + 400 - textheight("����") / 2,
			"����");
	rank(uid);
	while (1) {
		if (MouseHit()) {
			Mouse = GetMouseMsg();
			if (Mouse.x >= Exit_L && Mouse.x <= Exit_R &&
				Mouse.y >= Exit_T && Mouse.y <= Exit_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {//���ص���¼����
				break;
			}
		}
	}if (Mouse.x >= Exit_L && Mouse.x <= Exit_R &&
		Mouse.y >= Exit_T && Mouse.y <= Exit_B) {
		Menu_Page();
		return;
	}
}

//������������������������������������������������������Ա��������ء�����������������������������������������������
void Developer_Page() {
	//���������Դ
	loadimage(Page[5], "./res/image/�����߼�����/developer_page.png");
	//չʾ����ͼ
	putimage(0, 0, Page[5]);
	{
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		settextstyle(30, 0, "SimHei");
		setfillcolor(RGB(255, 255, 255));
		fillroundrect(730, Exit_T, 1030, Exit_B, 10, 10);
		outtextxy(880 - textwidth("����") / 2,
			GR_Height / 2 + 400 - textheight("����") / 2,
			"����");
		//�����������
		while (1) {
			if (MouseHit()) {
				Mouse = GetMouseMsg();
				if (Mouse.x >= 730 && Mouse.x <= 1030 &&
					Mouse.y >= Exit_T && Mouse.y <= Exit_B &&
					Mouse.uMsg == WM_LBUTTONDOWN) {//���ص���¼����
					Menu_Page();
				}
			}
		}
	}
}



//��������������������������������������������������Ϸ��������ء�����������������������������������������������
void Tips_Page() {
	//���������Դ
	loadimage(Page[6], "./res/image/��Ϸ������/tips_page_1.png", 1080, 960);
	loadimage(Page[15], "./res/image/��Ϸ������/tips_page_2.png", 1080, 960);
	loadimage(Page[16], "./res/image/��Ϸ������/tips_page_3.png", 1080, 960);
	loadimage(Page[17], "./res/image/��Ϸ������/tips_page_4.png", 1080, 960);
	//ҳ����
	int tips_status = 1;
	{
		BeginBatchDraw();
		//�����û��������
		while (1) {
			//��ҳ��չʾ����ͼ
			switch (tips_status) {
			case 1:
				putimage(0, 0, Page[6]);
				break;
			case 2:
				putimage(0, 0, Page[15]);
				break;
			case 3:
				putimage(0, 0, Page[16]);
				break;
			case 4:
				putimage(0, 0, Page[17]);
				break;
			}
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			settextstyle(30, 0, "SimHei");
			setfillcolor(RGB(255, 255, 255));
			//���ذ�ť
			fillroundrect(960, 890, 1070, 940, 10, 10);
			outtextxy(1010 - textwidth("����") / 2,
				915 - textheight("����") / 2,
				"����");
			//��һҳ
			fillroundrect(1020, 190, 1070, 290, 10, 10);
			outtextxy(1045 - textwidth("1") / 2,
				240 - textheight("1") / 2,
				"1");
			//�ڶ�ҳ
			fillroundrect(1020, 350, 1070, 450, 10, 10);
			outtextxy(1045 - textwidth("2") / 2,
				400 - textheight("2") / 2,
				"2");
			//����ҳ
			fillroundrect(1020, 510, 1070, 610, 10, 10);
			outtextxy(1045 - textwidth("3") / 2,
				560 - textheight("3") / 2,
				"3");
			//����ҳ
			fillroundrect(1020, 670, 1070, 770, 10, 10);
			outtextxy(1045 - textwidth("4") / 2,
				720 - textheight("4") / 2,
				"4");

			FlushBatchDraw();
			if (MouseHit()) {
				Mouse = GetMouseMsg();
				if (Mouse.x >= 960 && Mouse.x <= 1070 &&
					Mouse.y >= 890 && Mouse.y <= 940 &&
					Mouse.uMsg == WM_LBUTTONDOWN) {//���ص��˵�����
					EndBatchDraw();
					break;
				}
				else if (Mouse.x >= 1020 && Mouse.x <= 1070 &&
					Mouse.y >= 190 && Mouse.y <= 290 &&
					Mouse.uMsg == WM_LBUTTONDOWN) {//��һҳ
					tips_status = 1;
				}
				else if (	Mouse.x >= 1020 && Mouse.x <= 1070 &&
							Mouse.y >= 350 && Mouse.y <= 450 &&
							Mouse.uMsg == WM_LBUTTONDOWN) {//�ڶ�ҳ
					tips_status = 2;
				}
				else if (Mouse.x >= 1020 && Mouse.x <= 1070 &&
					Mouse.y >= 510 && Mouse.y <= 610 &&
					Mouse.uMsg == WM_LBUTTONDOWN) {//����ҳ
					tips_status = 3;
				}
				else if (Mouse.x >= 1020 && Mouse.x <= 1070 &&
					Mouse.y >= 670 && Mouse.y <= 770 &&
					Mouse.uMsg == WM_LBUTTONDOWN) {//����ҳ
					tips_status = 4;
				}
			}
		}if (Mouse.x >= 960 && Mouse.x <= 1070 &&
			Mouse.y >= 890 && Mouse.y <= 940) {//���ص��˵�����
			Menu_Page();
			return;
		}
	}
}




//��������������������������������������������������Ϸ������ء�����������������������������������������������
void Game_Page() {
	//Ϊ��ҷ���洢�ռ�
	mark = 0;
	Me = (Player)malloc(sizeof(Plane));
	Load_Game_Res();
	//ѭ����"��ʱ��"��ʵ��֡�ʿ���
	clock_t start_bk, moment_bk;
	start_bk = clock();
	//��Ϸ�Ŀ�ʼʱ��
	game_start = clock();
	//��ʼ��Ϸʱ"��0��"��������Ϊ0
	enemy_batch = 0;
	is_victory = false;
	BeginBatchDraw();
	//׼����ɣ�ѭ����ӡ��ʼ(��Ϸ��ʼ)
	mciSendString("open ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
	mciSendString("play ./res/audio/BACO-SUPERNOVA.mp3 repeat", 0, 0, 0);

	while (Me->HP > 0)
	{
		//�ж��Ƿ�ﵽһ֡�ĳ���ʱ��
		{
			moment_bk = clock();
			if ((double)(moment_bk - start_bk) / CLK_TCK <= 0.0166) {
				continue;
			}start_bk = clock();
		}
		//������ҵļ�����Ϣ
		Get_Keyboard_Game();

		//ˢ�µ���
		Make_Enemy();
		//������˵������Ϣ
		Enemy_Shooting();
		//�����ײ�����¸���Ŀ����Ϣ�����·���
		mark += Me_and_Bullet() + Me_and_Enemy() + Me_and_Object() + Enemy_and_Bullet();
		//�������޵У�Ѫ���ص�100
		file_read();
		for (p = head; p != NULL; p = p->next) {
			if (p->id == uid) {
				if (p->commodity[0]) {
					Me->HP = 100;
				}
			}
		}
		all_free();
		//����Ѫ�������꣬���ø���Ŀ�������
		Set_Is_Live();
		//���ҳ��Ԫ�أ�������Ŀ�꽫���ᱻ��ӡ
		Flush_Game_bk();	//��ӡ��Ϸ����
		Put_Me();			//��ӡ���
		Put_Enemies();		//��ӡ����
		Put_Bul();			//��ӡ�ӵ���ͬʱ�������ƶ�
		Put_HP();			//��ӡ���Ѫ��
		Put_Mark();			//��ӡ����
		Put_Objects();		//��ӡ������
		FlushBatchDraw();
		//boss������ʤ��
		if (is_victory) {
			//�ͷ���Ҵ洢�ռ�
			free(Me);
			boss_big_bul = true;
			Victory_Page();
		}
	}
	mciSendString("close ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
	free(Me);
	boss_big_bul = true;
	Perish_Page();
	EndBatchDraw();
}

//��ӡ���
void Put_Me() {
	//�������Ѫ����ŭ��״̬��ӡ���
	//��ȡ��ҹ���Ƥ����״̬
	file_read();
	for (p = head; p != NULL; p = p->next) {
		if (p->id == uid) {
			break;
		}
	}
	if (Me->HP <= 40) {
		putimage(Me->x, Me->y, Me->size, Me->size, Me_Image[2][0], 0, 0, SRCAND);
		putimage(Me->x, Me->y, Me->size, Me->size, Me_Image[2][1], 0, 0, SRCPAINT);
	}
	else if (Me->is_angry) {
		putimage(Me->x, Me->y, Me->size, Me->size, Me_Image[1][0], 0, 0, SRCAND);
		putimage(Me->x, Me->y, Me->size, Me->size, Me_Image[1][1], 0, 0, SRCPAINT);
	}
	else if (p->commodity[2]) {
		putimage(Me->x, Me->y, Me->size, Me->size, Me_Image[3][0], 0, 0, SRCAND);
		putimage(Me->x, Me->y, Me->size, Me->size, Me_Image[3][1], 0, 0, SRCPAINT);
	}
	else {
		putimage(Me->x, Me->y, Me->size, Me->size, Me_Image[0][0], 0, 0, SRCAND);
		putimage(Me->x, Me->y, Me->size, Me->size, Me_Image[0][1], 0, 0, SRCPAINT);
	}
	all_free();
}

//��ӡ�ӵ�
void Put_Bul() {
	extern IMAGE e_bullet_1_w;
	extern IMAGE e_bullet_1_b;
	extern IMAGE e_bullet_2_w;
	extern IMAGE e_bullet_2_b;
	extern IMAGE e_bullet_3_w;
	extern IMAGE e_bullet_3_b;
	extern IMAGE e_bullet_4_w;
	extern IMAGE e_bullet_4_b;
	extern IMAGE e_bullet_5_w;
	extern IMAGE e_bullet_5_b;
	extern IMAGE e_bullet_6_w;
	extern IMAGE e_bullet_6_b;
	extern IMAGE my_bullet_1_w;
	extern IMAGE my_bullet_1_b;
	extern IMAGE my_bullet_2_w;
	extern IMAGE my_bullet_2_b;
	for (int i = 1; i <= 500; i++) {
		if (bullets[i - 1].is_live) {
			switch (bullets[i - 1].type) {
			case My_Bul_1:
				putimage(bullets[i - 1].x, bullets[i - 1].y, &my_bullet_1_w, SRCAND);
				putimage(bullets[i - 1].x, bullets[i - 1].y, &my_bullet_1_b, SRCPAINT);
				bullets[i - 1].y -= bullets[i - 1].speed * cos((long double)bullets[i - 1].angle);
				bullets[i - 1].x -= bullets[i - 1].speed * sin((long double)bullets[i - 1].angle);
				break;

			case My_Bul_2:
				putimage(bullets[i - 1].x, bullets[i - 1].y, &my_bullet_2_w, SRCAND);
				putimage(bullets[i - 1].x, bullets[i - 1].y, &my_bullet_2_b, SRCPAINT);
				bullets[i - 1].y -= bullets[i - 1].speed * cos((long double)bullets[i - 1].angle);
				bullets[i - 1].x -= bullets[i - 1].speed * sin((long double)bullets[i - 1].angle);
				break;

			case E_Bul_1:
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_1_w, SRCAND);
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_1_b, SRCPAINT);
				bullets[i - 1].x += bullets[i - 1].speed * sin((long double)bullets[i - 1].angle);
				bullets[i - 1].y += bullets[i - 1].speed * cos((long double)bullets[i - 1].angle);
				break;

			case E_Bul_2:
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_2_w, SRCAND);
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_2_b, SRCPAINT);
				bullets[i - 1].x += bullets[i - 1].speed * sin((long double)bullets[i - 1].angle);
				bullets[i - 1].y += bullets[i - 1].speed * cos((long double)bullets[i - 1].angle);
				break;

			case E_Bul_3:
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_3_w, SRCAND);
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_3_b, SRCPAINT);
				bullets[i - 1].x += bullets[i - 1].speed * sin((long double)bullets[i - 1].angle);
				bullets[i - 1].y += bullets[i - 1].speed * cos((long double)bullets[i - 1].angle);
				break;

			case E_Bul_4:
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_4_w, SRCAND);
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_4_b, SRCPAINT);
				bullets[i - 1].x += bullets[i - 1].speed * sin((long double)bullets[i - 1].angle);
				bullets[i - 1].y += bullets[i - 1].speed * cos((long double)bullets[i - 1].angle);
				break;

			case E_Bul_5:
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_5_w, SRCAND);
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_5_b, SRCPAINT);
				bullets[i - 1].x += bullets[i - 1].speed * sin((long double)bullets[i - 1].angle);
				bullets[i - 1].y += bullets[i - 1].speed * cos((long double)bullets[i - 1].angle);
				break;

			case E_Bul_6:
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_6_w, SRCAND);
				putimage(bullets[i - 1].x, bullets[i - 1].y, &e_bullet_6_b, SRCPAINT);
				bullets[i - 1].x += bullets[i - 1].speed * sin((long double)bullets[i - 1].angle);
				bullets[i - 1].y += bullets[i - 1].speed * cos((long double)bullets[i - 1].angle);
				break;
			}
		}
	}
}

//��ӡ������
void Put_Objects() {
	//����objects���飬��ӡһ�д�������
	for (int i = 1; i <= 50; i++) {
		//��λ����Ҫ��ӡ
		if (objects[i - 1].is_live) {
			putimage(objects[i - 1].x, objects[i - 1].y, Obj_Image[objects[i - 1].type - 1][0], SRCAND);
			putimage(objects[i - 1].x, objects[i - 1].y, Obj_Image[objects[i - 1].type - 1][1], SRCPAINT);
			//�������ꡢ�ٶȸ���λ��ʵ���ƶ�
			objects[i - 1].y += objects[i - 1].speed;
		}
	}
}

//��ӡ����
void Put_Mark() {
	std::string str = std::to_string(mark);//������תΪstring����
	//�������ָ�ʽ
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "SimHei");
	//��ӡ����ֵ
	outtextxy(0, 0, "������");
	outtextxy(150, 0, str.data());
}

//��ӡѪ��Ѫ��
void Put_HP() {
	std::string str = std::to_string(Me->HP);//��Ѫ��ֵתΪstring�����Ա��ӡ
	//�������ָ�ʽ
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	outtextxy(0, 900, str.data());
	//Ѫ���ж��٣��ʹ�ӡ���ٸ�2*30��С���Σ�ʵ�ֶ�̬Ѫ����
	if (Me->HP > 0) {
		for (int i = 1; i <= Me->HP; i++) {
			putimage(2 * (i - 1), 930, Page[11]);
		}
	}
}

//��ӡ����
void Put_Enemies() {
	//����enemies���飬��ӡһ�д�����
	for (int i = 1; i <= 50; i++)
	{
		if (enemies[i - 1].is_live)
		{
			if (enemies[i - 1].type == 11 && enemies[i - 1].HP <= 1250) {
				putimage(enemies[i - 1].x, enemies[i - 1].y, Ene_Image[11][0], SRCAND);
				putimage(enemies[i - 1].x, enemies[i - 1].y, Ene_Image[11][1], SRCPAINT);
			}
			else {
				putimage(enemies[i - 1].x, enemies[i - 1].y, Ene_Image[enemies[i - 1].type - 1][0], SRCAND);
				putimage(enemies[i - 1].x, enemies[i - 1].y, Ene_Image[enemies[i - 1].type - 1][1], SRCPAINT);
			}
			//������˵��ƶ�
			if (enemies[i - 1].type == Cat || enemies[i - 1].type == Pig || enemies[i - 1].type == BOSS)
			{//Զ�̵���
				if (enemies[i - 1].y >= GR_Height / 4 - enemies[i - 1].size / 2) //�Ѿ������������1/4��
				{
					if (enemies[i - 1].x <= 360 - enemies[i - 1].size / 2)
					{//��������߽����
						enemies[i - 1].x += enemies[i - 1].speed;
						enemies[i - 1].left = false;//���˷���Ϊ��
					}
					else if (enemies[i - 1].x >= 720 - enemies[i - 1].size / 2)
					{//�������ұ߽��ұ�
						enemies[i - 1].x -= enemies[i - 1].speed;
						enemies[i - 1].left = true;//���˷���Ϊ��
					}
					else {
						//�����˵��ƶ������ƶ�
						if (enemies[i - 1].left)
							enemies[i - 1].x -= enemies[i - 1].speed;
						else
							enemies[i - 1].x += enemies[i - 1].speed;
					}
				}
				else {//��δ�����������1/4�����������ƶ���ͬʱ����Ĭ������
					enemies[i - 1].y += enemies[i - 1].speed;
					enemies[i - 1].left = true;
				}
			}
			else{//��ս���ˣ����������ƶ�
				enemies[i - 1].y += enemies[i - 1].speed;
				if (enemies[i - 1].type == Alienware || enemies[i - 1].type == Chicken)
				{
					if ((enemies[i - 1].x + enemies[i - 1].size / 2) > (Me->x + Me->size)) {
						enemies[i - 1].x -= enemies[i - 1].speed;
					}
					else if((enemies[i - 1].x + enemies[i - 1].size / 2) < (Me->x + Me->size)) {
						enemies[i - 1].x += enemies[i - 1].speed;
					}
				}
			}
		}

	}
}

//��Ϸ�����ڽ��ܴ��������Ϣ
void Get_Keyboard_Game() {
	Move_Me();		//�����ƶ���Ϣ
	Shooting();		//���������Ϣ
	if (GetAsyncKeyState(VK_ESCAPE)) {//��ͣ����
		Pause_Page();
	}
}

//��̬����Ϸ�ڱ���
void Flush_Game_bk() {
	putimage(0, bk_flush, Page[13]);
	bk_flush = (bk_flush + 4) % GR_Height;//���ı���λ��
	if (bk_flush > 0) {//��ӡ������ͼƬһ��λ��ʱ�����豳��λ��
		bk_flush -= GR_Height;
	}
}

//���ݼ������룬�޸����λ��
void Move_Me() {
	//ÿһ֡��ӡʱ��λ�ö���ˢ�µ�
	//����
	if (GetAsyncKeyState(VK_UP)|| GetAsyncKeyState('W') && Me->y > 0) {
		Me->y -= Me_Speed;
	}//����
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S') && Me->y < (GR_Height - Me->size)) {
		Me->y += Me_Speed;
	}//����
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A') && Me->x > 0) {
		Me->x -= Me_Speed;
	}//����
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D') && Me->x < (GR_Width - Me->size)) {
		Me->x += Me_Speed;
	}
}

//��ҵ��������
void Shooting() {
	//��ȡ���ո񣬽������
	if (GetAsyncKeyState(VK_SPACE)) {
		if (!start_shooting) {
			//��δ��ʼ�������������״̬�����������ʱ
			start_shooting = true;
			start_shoot = clock();
			//��������ӵ���������ʼ���ӵ�
			switch (increase_bul_times) {
			case 1:
				Init_Player_Bul(0);
				break;

			case 3:
				Init_Player_Bul(0);
				Init_Player_Bul(-Pi / 12);
				Init_Player_Bul(Pi / 12);
				break;

			case 5:
				Init_Player_Bul(0);
				Init_Player_Bul(-Pi / 12);
				Init_Player_Bul(Pi / 12);
				Init_Player_Bul(-Pi / 6);
				Init_Player_Bul(Pi / 6);
				break;

			case 7:
				Init_Player_Bul(0);
				Init_Player_Bul(-Pi / 12);
				Init_Player_Bul(Pi / 12);
				Init_Player_Bul(-Pi / 6);
				Init_Player_Bul(Pi / 6);
				Init_Player_Bul(-Pi / 4);
				Init_Player_Bul(Pi / 4);
				break;

			case 9:
				Init_Player_Bul(0);
				Init_Player_Bul(-Pi / 12);
				Init_Player_Bul(Pi / 12);
				Init_Player_Bul(-Pi / 6);
				Init_Player_Bul(Pi / 6);
				Init_Player_Bul(-Pi / 4);
				Init_Player_Bul(Pi / 4);
				Init_Player_Bul(-Pi / 3);
				Init_Player_Bul(Pi / 3);
				break;
			}
		}
		else {
			moment_shoot = clock();//��ʱ�˿�
			if ((double)(moment_shoot - start_shoot) / CLK_TCK >= Me->CD) //ʱ���ﵽ���CD
			{
				start_shoot = clock();//���ü�ʱ��
				//��������ӵ���������ʼ���ӵ�
				switch (increase_bul_times) {
				case 1:
					Init_Player_Bul(0);
					break;

				case 3:
					Init_Player_Bul(0);
					Init_Player_Bul(-Pi / 12);
					Init_Player_Bul(Pi / 12);
					break;

				case 5:
					Init_Player_Bul(0);
					Init_Player_Bul(-Pi / 12);
					Init_Player_Bul(Pi / 12);
					Init_Player_Bul(-Pi / 6);
					Init_Player_Bul(Pi / 6);
					break;

				case 7:
					Init_Player_Bul(0);
					Init_Player_Bul(-Pi / 12);
					Init_Player_Bul(Pi / 12);
					Init_Player_Bul(-Pi / 6);
					Init_Player_Bul(Pi / 6);
					Init_Player_Bul(-Pi / 4);
					Init_Player_Bul(Pi / 4);
					break;

				case 9:
					Init_Player_Bul(0);
					Init_Player_Bul(-Pi / 12);
					Init_Player_Bul(Pi / 12);
					Init_Player_Bul(-Pi / 6);
					Init_Player_Bul(Pi / 6);
					Init_Player_Bul(-Pi / 4);
					Init_Player_Bul(Pi / 4);
					Init_Player_Bul(-Pi / 3);
					Init_Player_Bul(Pi / 3);
					break;
				}
			}
		}
	}
}



//��������������������������������������������������ͣ������ء�����������������������������������������������
void Pause_Page() {
	//��ͣ��Ϸ������
	mciSendString("pause ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
	mciSendString("pause ./res/audio/�̣�.mp3", 0, 0, 0);
	//��ͣ����
	loadimage(Page[12], "./res/image/��ͣ����/pause_page.png", 1080, 960);
	//������Ч������³�ࡱ
	mciSendString("open ./res/audio/The_World.wav", 0, 0, 0);
	mciSendString("play ./res/audio/The_World.wav", 0, 0, 0);
	//���ñ�������ť
	putimage(0, 0, Page[12]);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	setfillcolor(RGB(255, 255, 255));
	fillroundrect(Forget_L, Forget_T, Forget_R, Forget_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("����") / 2,
		GR_Height / 2 + 300 - textheight("����") / 2,
		"����");
	fillroundrect(Signin_L, Signin_T, Signin_R, Signin_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("���ز˵�") / 2,
		GR_Height / 2 + 200 - textheight("���ز˵�") / 2,
		"���ز˵�");
	FlushBatchDraw();//�������ťͼ��
	//ѭ����ȡ�����Ϣ
	while (1) {
		if (MouseHit()) {
			Mouse = GetMouseMsg();
			if (Mouse.x >= Forget_L && Mouse.x <= Forget_R &&
				Mouse.y >= Forget_T && Mouse.y <= Forget_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {//������Ϸ
				for (int i = 1; i <= 50; i++) {
					//BOSSѪ����50%����
					if (enemies[i - 1].type == 11 && enemies[i - 1].HP <= 527) {
						//ֹͣ��ͣ���ֲ�������Ϸ������
						mciSendString("close ./res/audio/The_World.wav", 0, 0, 0);
						mciSendString("play ./res/audio/�̣�.mp3", 0, 0, 0);
					}
					else {
						//ֹͣ��ͣ���ֲ�������Ϸ������
						mciSendString("close ./res/audio/The_World.wav", 0, 0, 0);
						mciSendString("play ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
					}
				}
				break;
			}
			else if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
				Mouse.y >= Signin_T && Mouse.y <= Signin_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {//���ز˵�
				//ֹͣ��ͣ����
				mciSendString("close ./res/audio/The_World.wav", 0, 0, 0);
				break;
			}
		}
	}if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
		Mouse.y >= Signin_T && Mouse.y <= Signin_B) {
		EndBatchDraw();
		free(Me);
		//ֹͣ��ͣ���ֲ�������Ϸ������
		mciSendString("close ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
		mciSendString("close ./res/audio/�̣�.mp3", 0, 0, 0);
		Menu_Page();
	}
}



//��������������������������������������������������Ϸʤ��������ء�����������������������������������������������
void Victory_Page() {
	//�������浽���а�
	save_score(mark);
	//��ӡ���桢����˫�����ͼ
	putimage(0, 0, Page[9], SRCAND);
	putimage(0, 0, Page[10], SRCPAINT);
	EndBatchDraw();
	//���ư���
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	setfillcolor(RGB(255, 255, 255));
	fillroundrect(Signin_L, Signin_T, Signin_R, Signin_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("���ز˵�") / 2,GR_Height / 2 + 200 - textheight("���ز˵�") / 2,"���ز˵�");
	//ֹͣ��Ϸ������
	mciSendString("close ./res/audio/�̣�.mp3", 0, 0, 0);
	//����ʤ������
	mciSendString("open ./res/audio/victory.mp3", 0, 0, 0);
	mciSendString("play ./res/audio/victory.mp3", 0, 0, 0);
	//ѭ����ȡ�������
	while (1) {
		if (MouseHit()) {
			Mouse = GetMouseMsg();
			if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
				Mouse.y >= Signin_T && Mouse.y <= Signin_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {//���ز˵�
				mciSendString("close ./res/audio/victory.mp3", 0, 0, 0);
				break;
			}
		}
	}if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
		Mouse.y >= Signin_T && Mouse.y <= Signin_B) {
		Menu_Page();
	}
}



//��������������������������������������������������Ϸʧ�ܽ�����ء�����������������������������������������������
void Perish_Page() {
	//�������浽���а�
	save_score(mark);
	//��ӡ���桢����˫�����ͼ
	putimage(0, 0, Page[7], SRCAND);
	putimage(0, 0, Page[8], SRCPAINT);
	EndBatchDraw();
	//���ư���
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	setfillcolor(RGB(255, 255, 255));
	fillroundrect(Signin_L, Signin_T, Signin_R, Signin_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("���ز˵�") / 2,
		GR_Height / 2 + 200 - textheight("���ز˵�") / 2,
		"���ز˵�");
	//ֹͣ��Ϸ������
	mciSendString("close ./res/audio/�̣�.mp3", 0, 0, 0);
	mciSendString("close ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
	//����ʧ������
	mciSendString("open ./res/audio/perish.mp3", 0, 0, 0);
	mciSendString("play ./res/audio/perish.mp3", 0, 0, 0);
	//ѭ����ȡ�������
	while (1) {
		if (MouseHit()) {
			Mouse = GetMouseMsg();
			if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
				Mouse.y >= Signin_T && Mouse.y <= Signin_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {//���ز˵�
				mciSendString("close ./res/audio/perish.mp3", 0, 0, 0);
				break;//������ѭ��
			}
		}
	}if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
		Mouse.y >= Signin_T && Mouse.y <= Signin_B) {
		Menu_Page();//�ٻز˵�����
	}
}


//�����������������������������������������������������̳�ҳ����ء���������������������������������������������������������������
void Shop_Page() {
	//��ӡ�̳Ǳ���ͼ
	loadimage(Page[14], "./res/image/�̵����/shop_page.png");
	putimage(0, 0, Page[14]);
	int money_num;
	file_read();
	p = head;
	while (p != NULL)
	{
		if (p->id == uid)
		{
			money_num = p->money;
			break;
		}
		p = p->next;
	}
	std::string str = std::to_string(money_num);
	settextcolor(BLACK);
	settextstyle(30, 0, "����");
	outtextxy(50, 50, str.data());
	all_free();
	Buy();
}