#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#define LEN sizeof(struct User)


//ser�㹦��
void login();//��¼����
void registered();//ע�ắ��
void PassBack();//�һ����뺯��
void add();//ע��������û���Ϣ��ֵ����
int login_state(int uid, char pass[16]);//��¼״̬�жϺ���
void registered_show();//ע�����չʾ
void login_show();//��¼����չʾ
void passback_show();//�����������չʾ
int str_int(char login_id[5]);//�ַ���ת����
char* int_str(char* str, int num);//����ת�ַ���
void login_input();//��¼���洦���û���������
void registered_confirm();//ע�������Ϣȷ�Ϻʹ�����
void registered_input();//ע����洦���û���������
void passback_confirm();//�������������Ϣȷ�ϴ�����
void pass_back();//����������洦���û���������
void save_score(int mark);//�������溯��
void rank(int uid);//���а���
void Load_Game_Res();//������Ϸ��Դ
void Make_Enemy();//ˢ�µ���
void Enemy_Shooting();//������˵����
void BOSS_Shooting(int i);//����BOSS�����
void BOSS_Shooting_1(int i);//Boss��һ״̬�������
void BOSS_Shooting_1_to_2(int i);//Boss����״̬�������
void BOSS_Shooting_2(int i);//Boss�ڶ�״̬�������һ����Ļ��
void Buy();//�̳ǹ�����
void Rechange();//��ֵ����

//���õĹ��ܺ�ȫ�ֱ���
void Menu_Page();
void Shop_Page();
void Init_Player_Bul(double angle);
void Init_Enemy(int x, int type);
void Init_Ene_Bullet(int type, double angle, int i);
void Init_Boss_Bul_1(int i, double A);
void Init_Boss_Bul_1_to_2(int i, double A);
void Init_Boss_Bul_2(int i, double A);
void Load_Game_Images();
void Load_Player_Datas();
void Load_Enemies_Datas();
void Load_Bul_Datas();
void Load_Obj_Datas();
int file_size();
void file_read();
void file_save();
void all_free();
void shop_payment(int style);
void Money_increase(int money);
void Get_money(int result);
int Rechange_confirm(char rechange_code[10]);
extern MOUSEMSG Mouse;
extern Player Me;
extern int mark;
extern int uid;
extern int bk_flush;
extern int enemy_batch;
extern int increase_bul_times;
extern bool is_victory;
extern bool boss_big_bul;
extern bool left;
extern bool start_shooting;
extern bool boss_bul_is_black;
extern Object objects[50];
extern Enemy enemies[50];
extern Bullet bullets[500];
extern clock_t game_start, game_moment;
extern clock_t start_shoot;
extern clock_t moment_shoot;
extern Refresh_Enemy L;
extern clock_t e_shoot_start, e_shoot_moment;
extern bool is_e_shoot;
extern clock_t chao_start, chao_moment;
extern bool is_chao_start;


//��¼ģ��ȫ�ֱ���
int n = 0;
char passback_answer[3][10];
char login_id[5];
char name[10];
char pass[16];
//�û��ṹ��
User* head, * p, * p1, * p2;

//��������������������������������������������������¼��ע�ᡢ�������빦�ܡ�����������������������������������������������


//ע��������û���Ϣ��ֵ����
void add()//����û�
{
	file_read();
	p1 = (struct User*)malloc(LEN);
	if (n == 0)
	{
		head = p1;
		p1->id = 10001;
	}
	else
	{
		p2->next = p1;
		p1->id = (p2->id) + 1;
	}
	strcpy_s(p1->name, name);
	strcpy_s(p1->password, pass);
	strcpy_s(p1->passback_answer[0], passback_answer[0]);
	strcpy_s(p1->passback_answer[1], passback_answer[1]);
	strcpy_s(p1->passback_answer[2], passback_answer[2]);
	p1->money = 0;
	for (int i = 1; i <= 3; i++) {
		p1->commodity[i - 1] = false;
	}
	p1->next = NULL;
	p2 = p1;
	printf("��ӳɹ�");
}

//��¼״̬�жϺ���
int login_state(int uid, char pass[16])
{
	if (file_size() == 0)
		return 1;
	file_read();
	p = head;
	while (p != NULL)
	{
		if (p->id == uid)
		{
			if (strcmp(p->password, pass) != 0)
			{
				all_free();
				return 2;//�������
			}
			else {
				all_free();
				return 0;
			}//��¼�ɹ�
		}
		p = p->next;
	}
	all_free();
	return 1;//�˺Ų�����
}

//ע�����չʾ
void registered_show()
{
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, "./res/image/ע�����/registered.png", 1080, 960);
	putimage(0, 0, &img);
	setfillcolor(RGB(75, 160, 73));
	settextcolor(RGB(31, 31, 31));
	settextstyle(30, 0, "����");
	setbkmode(TRANSPARENT);
	solidrectangle(400, 100, 680, 140);
	outtextxy(400, 105, "�ǳ�");
	solidrectangle(400, 160, 680, 200);
	outtextxy(400, 165, "����");
	settextcolor(RGB(127, 131, 247));
	outtextxy(420, 240, "�������ܱ���:");
	settextcolor(RGB(31, 31, 31));
	solidrectangle(320, 300, 760, 340);
	outtextxy(325, 305, "����ϲ����ʳ��");
	solidrectangle(320, 350, 760, 390);
	outtextxy(325, 355, "����ϲ������ɫ");
	solidrectangle(320, 400, 760, 440);
	outtextxy(325, 405, "����ϲ���Ķ���");
	solidrectangle(460, 460, 620, 500);
	outtextxy(510, 465, "ע��");
	solidrectangle(460, 520, 620, 560);
	outtextxy(510, 525, "����");
	setfillcolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	fillrectangle(470, 105, 670, 135); //�ǳ������
	fillrectangle(470, 165, 670, 195); //���������
	fillrectangle(535, 305, 755, 335);
	fillrectangle(535, 355, 755, 385);
	fillrectangle(535, 405, 755, 435);
	EndBatchDraw();
}

//��¼����չʾ
void login_show()
{
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, "./res/image/��¼����/login.png", 1080, 960);
	putimage(0, 0, &img);
	setfillcolor(RGB(134, 192, 195));
	settextcolor(RED);
	settextstyle(30, 0, "����");
	setbkmode(TRANSPARENT);
	solidrectangle(400, 310, 680, 350);
	outtextxy(410, 315, "UID");
	solidrectangle(400, 370, 680, 410);
	outtextxy(400, 375, "����");
	solidrectangle(460, 430, 620, 470);
	outtextxy(480, 435, "����ǻ�");
	setfillcolor(RGB(40, 97, 137));
	solidrectangle(460, 480, 620, 520);
	outtextxy(510, 485, "ע��");
	setfillcolor(RGB(49, 115, 177));
	solidrectangle(460, 530, 620, 570);
	outtextxy(480, 535, "�һ�����");
	setfillcolor(RGB(167, 103, 112));
	solidrectangle(460, 580, 620, 620);
	outtextxy(480, 585, "�˳���Ϸ");
	setfillcolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	fillrectangle(470, 315, 670, 345); //�ǳ������
	fillrectangle(470, 375, 670, 405); //���������

	EndBatchDraw();
}
//�����������չʾ
void passback_show()
{
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, "./res/image/�����������/passback.png", 1080, 960);
	putimage(0, 0, &img);
	setfillcolor(RGB(134, 200, 233));
	settextcolor(RED);
	settextstyle(30, 0, "����");
	setbkmode(TRANSPARENT);
	solidrectangle(400, 180, 680, 220);
	outtextxy(410, 185, "UID");
	outtextxy(420, 240, "��ش��ܱ���:");
	solidrectangle(320, 300, 760, 340);
	outtextxy(325, 305, "����ϲ����ʳ��");
	solidrectangle(320, 350, 760, 390);
	outtextxy(325, 355, "����ϲ������ɫ");
	solidrectangle(320, 400, 760, 440);
	outtextxy(325, 405, "����ϲ���Ķ���");
	solidrectangle(460, 460, 620, 500);
	outtextxy(510, 465, "ȷ��");
	solidrectangle(460, 520, 620, 560);
	outtextxy(510, 525, "����");
	setfillcolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	fillrectangle(460, 185, 675, 215);//uid�����
	fillrectangle(535, 305, 755, 335);
	fillrectangle(535, 355, 755, 385);
	fillrectangle(535, 405, 755, 435);

	EndBatchDraw();
}

//�ַ���ת����
int str_int(char login_id[5])  //�ַ�0~9ͨ����ȥ�ַ�'0'���Ի����ֵ
{

	int num = 0;
	for (int i = 0; i < strlen(login_id); i++)
	{
		num = num * 10 + login_id[i] - '0';  // ͨ����ȥ'0'���Խ��ַ�ת��Ϊint���͵���ֵ
	}
	return num;
}

//����ת�ַ���
char* int_str(char* str, int num)  //����ת�ַ���
{
	int i = 0;
	while (num != 0)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	str[i] = '\0';
	i--;
	for (int j = 0; j < i; j++, i--)
	{
		char ch = str[j];
		str[j] = str[i];
		str[i] = ch;
	}
	return str;
}

//��¼���洦���û���������
void login_input()
{
	void registered();
	void PassBack();//ע�ắ��������
	ExMessage msg;
	int flag1 = 0, flag2 = 0;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 470 && msg.x <= 670 && msg.y >= 315 && msg.y <= 345)
				{
					if (flag1)
					{
						cleardevice();
						login_show();
						settextcolor(BLACK);
						outtextxy(470, 375, pass);
					}
					settextcolor(BLACK);
					InputBox(login_id, 6, "������id");
					uid = str_int(login_id);
					outtextxy(470, 315, login_id);
					flag1 = 1;
				}
				else if (msg.x >= 470 && msg.x <= 670 && msg.y >= 375 && msg.y <= 405)
				{
					if (flag2)
					{
						cleardevice();
						login_show();
						settextcolor(BLACK);
						outtextxy(470, 315, login_id);
					}
					settextcolor(BLACK);
					InputBox(pass, 16, "����������");
					outtextxy(470, 375, pass);
					flag2 = 1;
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 430 && msg.y <= 470)
				{
					//��ȡ���ھ��
					HWND hnd = GetHWnd();
					//�������ڣ���ʾ�û�����
					int ok = MessageBox(hnd, "ȷ����¼��", "��ʾ", MB_OKCANCEL);
					if (ok == IDOK)
					{
						int state = login_state(uid, pass); //����uid��������жϵ�¼״̬
						if (state == 0)
						{
							settextcolor(WHITE);
							setbkmode(TRANSPARENT);
							settextstyle(30, 0, "SimHei");
							outtextxy(350, 200, "��¼�ɹ�, ���ڽ���˵�����.....");
							Sleep(1000);
							strcpy(pass, "0");
							cleardevice();
							Menu_Page();
						}
						//�ô��貹��˵�����
						else if (state == 1)
						{
							settextcolor(WHITE);
							setbkmode(TRANSPARENT);
							settextstyle(30, 0, "SimHei");
							outtextxy(350, 200, "�˺Ų�����, ���ڽ���ע�����.....");
							Sleep(1000);
							cleardevice();
							registered();
						}
						else
						{
							settextcolor(WHITE);
							setbkmode(TRANSPARENT);
							settextstyle(30, 0, "SimHei");
							outtextxy(400, 200, "�������, �����µ�¼");
							Sleep(1000);
							cleardevice();
							login();
						}
					}
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 480 && msg.y <= 520)
				{
					settextcolor(WHITE);
					setbkmode(TRANSPARENT);
					settextstyle(30, 0, "SimHei");
					outtextxy(350, 200, " ���ڽ���ע�����.....");
					Sleep(1000);
					cleardevice();
					registered();
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 530 && msg.y <= 570)
				{
					settextcolor(WHITE);
					setbkmode(TRANSPARENT);
					settextstyle(30, 0, "SimHei");
					outtextxy(350, 200, " ���ڽ����һ��������.....");
					Sleep(1000);
					cleardevice();
					PassBack();
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 580 && msg.y <= 620)
				{
					settextcolor(WHITE);
					setbkmode(TRANSPARENT);
					settextstyle(30, 0, "SimHei");
					outtextxy(350, 200, " ���ڽ����˳���Ϸ.....");
					Sleep(1000);
					exit(0);
				}
				break;
			default:
				break;
			}

		}
	}
}


//ע�������Ϣȷ�Ϻʹ�����
void registered_confirm()//���ע���ȷ��
{
	//��ȡ���ھ��
	HWND hnd = GetHWnd();
	//�������ڣ���ʾ�û�����
	int ok = MessageBox(hnd, "ȷ��ע����", "��ʾ", MB_OKCANCEL);
	if (ok == IDOK)
	{
		add();
		cleardevice();
		registered_show();
		settextcolor(RGB(0,255,0));
		setbkmode(TRANSPARENT);
		settextstyle(30, 0, "SimHei");
		outtextxy(470, 105, name);
		outtextxy(470, 165, pass);
		outtextxy(535, 305, passback_answer[0]);
		outtextxy(535, 355, passback_answer[1]);
		outtextxy(535, 405, passback_answer[2]);
		char str[] = "ע��ɹ�!����uidΪ";
		outtextxy(600, 600, str);
		char id[5];
		outtextxy(600 + textwidth(str), 600, int_str(id, p2->id));
		outtextxy(600, 650, "����ת���¼����");
		file_save();
		all_free();
		for (int i = 0; i < 3; i++)
		{
			passback_answer[i][0] = '\0';
		}
		Sleep(5000);
		setbkcolor(WHITE);
		cleardevice();
		login();
	}
}

//ע����洦���û���������
void registered_input()
{
	ExMessage msg;
	int flag[5] = { 0,0,0,0,0 };
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 470 && msg.x <= 670 && msg.y >= 105 && msg.y <= 135)
				{
					if (flag[0])
					{
						cleardevice();
						registered_show();
						outtextxy(470, 165, pass);
						outtextxy(535, 305, passback_answer[0]);
						outtextxy(535, 355, passback_answer[1]);
						outtextxy(535, 405, passback_answer[2]);
					}
					settextcolor(BLACK);
					setfillcolor(BLUE);
					InputBox(name, 10, "�������ǳ�");
					outtextxy(470, 105, name);
					flag[0] = 1;
				}
				else if (msg.x >= 470 && msg.x <= 670 && msg.y >= 165 && msg.y <= 195)
				{
					if (flag[1])
					{
						cleardevice();
						registered_show();
						outtextxy(470, 105, name);
						outtextxy(535, 305, passback_answer[0]);
						outtextxy(535, 355, passback_answer[1]);
						outtextxy(535, 405, passback_answer[2]);
					}
					settextcolor(BLACK);
					setfillcolor(BLUE);
					InputBox(pass, 16, "����������");
					outtextxy(470, 165, pass);
					flag[1] = 1;
				}
				else if (msg.x >= 535 && msg.x <= 755 && msg.y >= 305 && msg.y <= 335)
				{
					if (flag[2])
					{
						cleardevice();
						registered_show();
						outtextxy(470, 105, name);
						outtextxy(470, 165, pass);
						outtextxy(535, 355, passback_answer[1]);
						outtextxy(535, 405, passback_answer[2]);
					}
					settextcolor(BLACK);
					setfillcolor(BLUE);
					InputBox(passback_answer[0], 10, "��������ϲ����ʳ��");
					outtextxy(535, 305, passback_answer[0]);
					flag[2] = 1;
				}
				else if (msg.x >= 535 && msg.x <= 755 && msg.y >= 355 && msg.y <= 385)
				{
					if (flag[3])
					{
						cleardevice();
						registered_show();
						outtextxy(470, 105, name);
						outtextxy(470, 165, pass);
						outtextxy(535, 305, passback_answer[0]);
						outtextxy(535, 405, passback_answer[2]);
					}
					settextcolor(BLACK);
					setfillcolor(BLUE);
					InputBox(passback_answer[1], 10, "��������ϲ������ɫ");
					outtextxy(535, 355, passback_answer[1]);
					flag[3] = 1;
				}
				else if (msg.x >= 535 && msg.x <= 755 && msg.y >= 405 && msg.y <= 435)
				{
					if (flag[4])
					{
						cleardevice();
						registered_show();
						outtextxy(470, 105, name);
						outtextxy(470, 165, pass);
						outtextxy(535, 305, passback_answer[0]);
						outtextxy(535, 355, passback_answer[1]);
					}
					settextcolor(BLACK);
					setfillcolor(BLUE);
					InputBox(passback_answer[2], 16, "��������ϲ���Ķ���");
					outtextxy(535, 405, passback_answer[2]);
					flag[4] = 1;
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 460 && msg.y <= 500)
				{
					int a = flag[0] && flag[1] && flag[2] && flag[3] && flag[4];
					if (a && strlen(pass) >= 5)
						registered_confirm();
					else if (!a)
					{
						cleardevice();
						registered_show();
						outtextxy(470, 105, name);
						outtextxy(470, 165, pass);
						outtextxy(535, 305, passback_answer[0]);
						outtextxy(535, 355, passback_answer[1]);
						outtextxy(535, 405, passback_answer[2]);
						settextcolor(RGB(245, 87, 98));
						outtextxy(450, 600, "��δ��ȫ����");
					}
					else if (a && strlen(pass) < 5)
					{
						cleardevice();
						registered_show();
						outtextxy(470, 105, name);
						outtextxy(470, 165, pass);
						outtextxy(535, 305, passback_answer[0]);
						outtextxy(535, 355, passback_answer[1]);
						outtextxy(535, 405, passback_answer[2]);
						settextcolor(RGB(245, 87, 98));
						outtextxy(380, 600, "���볤��С����ͳ���5");
					}
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 520 && msg.y <= 560)
				{
					login();
				}
				break;
			default:
				break;
			}

		}
	}
}


//�������������Ϣȷ�ϴ�����
void passback_confirm()
{
	void PassBack();
	//��ȡ���ھ��
	HWND hnd = GetHWnd();
	//�������ڣ���ʾ�û�����
	int ok = MessageBox(hnd, "ȷ������", "��ʾ", MB_OKCANCEL);
	if (ok == IDOK)
	{
		file_read();
		p = head;
		int s[3] = { 0,0,0 };
		char str[] = "����ȷ!��������Ϊ";
		while (p != NULL)
		{
			if (p->id == uid)
			{
				for (int i = 0; i < 3; i++)
				{
					if (!strcmp(p->passback_answer[i], passback_answer[i]))
						s[i] = 1;
				}
				cleardevice();
				passback_show();
				settextcolor(BLACK);
				outtextxy(460, 185, login_id);
				outtextxy(535, 305, passback_answer[0]);
				outtextxy(535, 355, passback_answer[1]);
				outtextxy(535, 405, passback_answer[2]);
				if (s[0] && s[1] && s[2])
				{
					outtextxy(400, 600, str);
					outtextxy(400 + textwidth(str), 600, p->password);
				}
				else
				{
					outtextxy(400, 600, "��Ĵ𰸴���");
					Sleep(1000);
					PassBack();
				}
				break;
			}
		}
		all_free();
	}
}


//����������洦���û���������
void pass_back()
{
	ExMessage msg;
	int flag[4] = { 0,0,0,0 };
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 460 && msg.x <= 675 && msg.y >= 185 && msg.y <= 215)
				{
					if (flag[0])
					{
						cleardevice();
						passback_show();
						outtextxy(535, 305, passback_answer[0]);
						outtextxy(535, 355, passback_answer[1]);
						outtextxy(535, 405, passback_answer[2]);
					}
					settextcolor(BLACK);
					setfillcolor(BLUE);
					InputBox(login_id, 6, "������id");
					uid = str_int(login_id);
					outtextxy(460, 185, login_id);
					flag[0] = 1;
				}
				else if (msg.x >= 535 && msg.x <= 755 && msg.y >= 305 && msg.y <= 335)
				{
					if (flag[1])
					{
						cleardevice();
						passback_show();
						outtextxy(460, 185, login_id);
						outtextxy(535, 355, passback_answer[1]);
						outtextxy(535, 405, passback_answer[2]);
					}
					settextcolor(BLACK);
					setfillcolor(BLUE);
					InputBox(passback_answer[0], 10, "��������ϲ����ʳ��");
					outtextxy(535, 305, passback_answer[0]);
					flag[1] = 1;
				}
				else if (msg.x >= 535 && msg.x <= 755 && msg.y >= 355 && msg.y <= 385)
				{
					if (flag[2])
					{
						cleardevice();
						passback_show();
						outtextxy(460, 185, login_id);
						outtextxy(535, 305, passback_answer[0]);
						outtextxy(535, 405, passback_answer[2]);
					}
					settextcolor(BLACK);
					setfillcolor(BLUE);
					InputBox(passback_answer[1], 10, "��������ϲ������ɫ");
					outtextxy(535, 355, passback_answer[1]);
					flag[2] = 1;
				}
				else if (msg.x >= 535 && msg.x <= 755 && msg.y >= 405 && msg.y <= 435)
				{
					if (flag[3])
					{
						cleardevice();
						passback_show();
						outtextxy(460, 185, login_id);
						outtextxy(535, 305, passback_answer[0]);
						outtextxy(535, 355, passback_answer[1]);
					}
					settextcolor(BLACK);
					setfillcolor(BLUE);
					InputBox(passback_answer[2], 16, "��������ϲ���Ķ���");
					outtextxy(535, 405, passback_answer[2]);
					flag[3] = 1;
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 460 && msg.y <= 500)
				{
					if (flag[0] && flag[1] && flag[2] && flag[3])
						passback_confirm();
					else
					{
						settextcolor(BLACK);
						outtextxy(450, 600, "��δ��ȫ����!");
					}
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 520 && msg.y <= 560)
				{
					login();
				}
				break;
			default:
				break;
			}

		}
	}

}

//��¼����
void login()
{
	//��ȡ���ھ��
	HWND hnd = GetHWnd();
	//���ô��ڱ���
	SetWindowText(hnd, "��¼");
	login_show();
	login_input();
}
//ע�ắ��
void registered()
{
	//��ȡ���ھ��
	HWND hnd = GetHWnd();
	//���ô��ڱ���
	SetWindowText(hnd, "ע��");
	registered_show();
	registered_input();
}
//�һ����뺯��
void PassBack()
{
	//��ȡ���ھ��
	HWND hnd = GetHWnd();
	//���ô��ڱ���
	SetWindowText(hnd, "��������");
	passback_show();
	pass_back();
}

//�����������������������������������������������������������а��ܡ���������������������������������������������������������������
void save_score(int mark)//�������溯��
{
	file_read();
	p = head;
	while (p != NULL)
	{
		if (p->id == uid)
		{
			if (p->score < mark)
			{
				p->score = mark;
				file_save();
			}
			break;
		}
		else p = p->next;
	}
	all_free();
}

//���а���
void rank(int uid)
{
	int rank_score[4] = { 0,0,0,0 };
	char rank_name[4][10] = { "����","����","����","����" };
	if (file_size())
	{
		file_read();
		p = head;
		while (p != NULL)
		{
			for (int i = 0; i < 3; i++)
			{
				if (p->score > rank_score[i])//����һ���ϸ߷֣����÷ֶκ��ƣ������丳ֵ��rank[i]
				{
					for (int j = 2; j > i; j--)
					{
						rank_score[j] = rank_score[j - 1];
						strcpy(rank_name[j], rank_name[j - 1]);
					}
					rank_score[i] = p->score;
					strcpy(rank_name[i], p->name);
					break;
				}
			}
			if (p->id == uid && p->score > 0)
			{
				rank_score[3] = p->score;
			}
			p = p->next;
		}
		all_free();
		if (rank_score[0] && rank_score[1] && rank_score[2] && rank_score[3] == 0)
		{
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			settextstyle(30, 0, "SimHei");
			outtextxy(600, 600, "��ǰû���û��÷�����");

		}
		else {
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			settextstyle(60, 0, "SimHei");
			outtextxy(700, 150, "����");
			outtextxy(200, 150, "�ǳ�");
			for (int i = 0; i < 3; i++)
			{
				if (rank_score[i]) {
					using namespace std;
					string str = to_string(rank_score[i]);
					outtextxy(700, 100 * (i + 1) + 150, str.data());
					outtextxy(200, 100 * (i + 1) + 150, rank_name[i]);
				}
			}
			if (rank_score[3])
			{
				using namespace std;
				string str = to_string(rank_score[3]);
				outtextxy(200, 550, "������߷֣�");
				outtextxy(700, 550, str.data());
			}
			else outtextxy(200, 550, "����ǰ�޷�����¼��");
		}
	}
	else {
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(30, 0, "SimHei");
		outtextxy(600, 600, "����δ���û�");
	}

}



//��������������������������������������������������������������Ϸ�ڹ��ܡ���������������������������������������������������������������
//������Ϸ����Դ
void Load_Game_Res() {
	//��ʼ������
	Load_Enemies_Datas();
	Load_Player_Datas();
	Load_Bul_Datas();
	Load_Obj_Datas();
	//��ʼ��ͼ��
	Load_Game_Images();
}


//ˢ�µ���
void Make_Enemy() {
	//��¼��ʱ�˿�
	game_moment = clock();
	//����뿪��С��2�룬��ˢ�µ���(����)
	if ((double)(game_moment - game_start) / CLK_TCK < 2.0) {
		return;
	}
	//��ǰ���ε�����С��3ʱ��ÿ��һ��������ˢ��һ��
	//ˢ�µ��˵�λ���������
	
	while (enemy_batch < 3 && L.now <= 200) {
		if (L.now <= L.enemy_num) {
			enemy_batch++;
			Init_Enemy(rand() % 600 + 200, L.data[++L.now - 1]);//��ָʾ�´�ˢ�µ��˵��±�now������˳��ˢ�µ���
		}
	}
}

//������˵������Ϣ
void Enemy_Shooting() {
	if (L.now == 49) {//����Ѿ��ֵ�Զ�̵��˳���
		is_e_shoot = true;//�����˵����״̬����
		e_shoot_start = clock();//���˿�ʼ�����ʱ��
	}
	if (is_e_shoot) {
		e_shoot_moment = clock();
		if ((e_shoot_moment - e_shoot_start) / CLK_TCK > 0.5) //�����ϴ������ʱ��͵�ǰʱ������0.5s
		{
			//�����������飬������Զ�̵��˳�ʼ���ӵ�
			for (int i = 1; i <= 50; i++) {
				if (enemies[i - 1].is_live) {
					if (enemies[i - 1].type == 9) {//è
						e_shoot_start = clock();//���������˲��ʱ��
						Init_Ene_Bullet(E_Bul_1, -Pi / 6, i);
						Init_Ene_Bullet(E_Bul_1, 0, i);
						Init_Ene_Bullet(E_Bul_1, Pi / 6, i);
					}
					else if (enemies[i - 1].type == 10) {//��
						e_shoot_start = clock();//���������˲��ʱ��
						Init_Ene_Bullet(E_Bul_2, -Pi / 6, i);
						Init_Ene_Bullet(E_Bul_2, 0, i);
						Init_Ene_Bullet(E_Bul_2, Pi / 6, i);
					}
					else if (enemies[i - 1].type == 11)
					{//��BOSS
						e_shoot_start = clock();//���������˲��ʱ��
						BOSS_Shooting(i);//��������BOSS�����
					}
					else {//����Զ�̵��ˣ���������ѭ��
						continue;
					}
				}
			}
		}

	}
}

//BOSS���������
void BOSS_Shooting(int i) {
	//�ж�boss��Ѫ���Ƿ���һ������
	if (enemies[i - 1].HP >= 1250) {
		BOSS_Shooting_1(i);//BOSS��һ״̬�������
	}
	else { 
		//�л�Ϊ��̷С������
		mciSendString("close ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
		mciSendString("open ./res/audio/�̣�.mp3", 0, 0, 0);
		mciSendString("play ./res/audio/�̣�.mp3", 0, 0, 0);
		if (!is_chao_start) {
			is_chao_start = true;
			chao_start = clock();
		}
		chao_moment = clock();
		if ((chao_moment - chao_start) / CLK_TCK < 6.7) {
			return;
		}
		if (boss_big_bul) {//BOSSȫ��Ψһһ������̬�ӵ�
			BOSS_Shooting_1_to_2(i);//BOSS����״̬�������
			boss_big_bul = false;//ȫ�ֱ�����Ϊfalse���˾��ڲ��ٷ�����ӵ�
		}
		else //BOSS�Ĺ���̬�ӵ��Ѿ��������
		{
			BOSS_Shooting_2(i);//BOSS�ڶ�״̬�������
		}
	}
}

//BOSS��һ״̬�������
void BOSS_Shooting_1(int i) {
	//ΪBOSS��ʼ����ǰ��120�����η�Χ�ڵ�����ӵ���
	Init_Boss_Bul_1(i, 0);
	Init_Boss_Bul_1(i, -Pi / 6);
	Init_Boss_Bul_1(i, -Pi / 3);
	Init_Boss_Bul_1(i, Pi / 6);
	Init_Boss_Bul_1(i, Pi / 3);
}

//BOSS����״̬�������
void BOSS_Shooting_1_to_2(int i) {
	Init_Boss_Bul_1_to_2(i, 0);
}

//�����ڵڶ�״̬�µ���������ڸ�״̬�£�Boss���ӵ�Ϊ360�ȵġ��ڰ������ĵ�Ļ��

void BOSS_Shooting_2(int i) {
	int j = 1;
	double A = 0;
	for (int j = 1; j <= 24; j++) {//ѭ��24�Σ�ÿ�νǶ� + Pi / 12��
		Init_Boss_Bul_2(i, A);
		A += Pi / 12;
	}
	if (boss_bul_is_black == 0) {//ÿ����һ���ӵ����ı�����ɫ
		boss_bul_is_black = 1;
	}
	else {
		boss_bul_is_black = 0;
	}
	//�ٴθ���boss_bul_is_black����٣��ﵽÿһȦ��Ļ�ڰ������Ӿ�Ч�� 
}


//�������������������������������������������������̳���ع��ܡ�����������������������������������������������������������
void Buy()
{
	//��ȡ�û�������
	while (1)
	{
		if (MouseHit()) {
			Mouse = GetMouseMsg();
			if (Mouse.x >= 930 && Mouse.x <= 1030 &&
				Mouse.y >= 50 && Mouse.y <= 150 &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				Menu_Page();
			}
			else if (Mouse.x >= 50 && Mouse.x <= 250 &&
				Mouse.y >= 200 && Mouse.y <= 350 &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				shop_payment(1);
				//��ҹ����������޵�
				Shop_Page();
			}
			else if (Mouse.x >= 50 && Mouse.x <= 250 &&
				Mouse.y >= 400 && Mouse.y <= 550 &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				shop_payment(2);
				//��ҹ��������ܼ��ӵ�
				Shop_Page();
			}
			else if (Mouse.x >= 50 && Mouse.x <= 250 &&
				Mouse.y >= 600 && Mouse.y <= 750 &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				shop_payment(3);
				Shop_Page();
				//��ҹ�����Ƥ��
			}
			else if (Mouse.x >= 50 && Mouse.x <= 250 &&
				Mouse.y >= 800 && Mouse.y <= 900 &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				Rechange();
				//���Ҫ����һ���
			}
		}
	}
	if (Mouse.x >= 930 && Mouse.x <= 1030 &&
		Mouse.y >= 50 && Mouse.y <= 150) {
		Menu_Page();//���ز˵�����
	}
}

//��ֵ����
void Rechange()
{
	char rechange_code[10] = "0000000";
	InputBox(rechange_code, 10, "�������ֵ��");
	int result = Rechange_confirm(rechange_code);
	Get_money(result);
	Shop_Page();
}