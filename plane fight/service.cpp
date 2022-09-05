#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#define LEN sizeof(struct User)


//ser层功能
void login();//登录函数
void registered();//注册函数
void PassBack();//找回密码函数
void add();//注册添加新用户信息赋值函数
int login_state(int uid, char pass[16]);//登录状态判断函数
void registered_show();//注册界面展示
void login_show();//登录界面展示
void passback_show();//忘记密码界面展示
int str_int(char login_id[5]);//字符串转整数
char* int_str(char* str, int num);//整数转字符串
void login_input();//登录界面处理用户操作函数
void registered_confirm();//注册界面信息确认和处理函数
void registered_input();//注册界面处理用户操作函数
void passback_confirm();//忘记密码界面信息确认处理函数
void pass_back();//忘记密码界面处理用户操作函数
void save_score(int mark);//分数保存函数
void rank(int uid);//排行榜函数
void Load_Game_Res();//加载游戏资源
void Make_Enemy();//刷新敌人
void Enemy_Shooting();//处理敌人的射击
void BOSS_Shooting(int i);//处理BOSS的射击
void BOSS_Shooting_1(int i);//Boss第一状态射击处理
void BOSS_Shooting_1_to_2(int i);//Boss过度状态射击处理
void BOSS_Shooting_2(int i);//Boss第二状态射击处理（一波弹幕）
void Buy();//商城购买功能
void Rechange();//充值功能

//引用的功能和全局变量
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


//登录模块全局变量
int n = 0;
char passback_answer[3][10];
char login_id[5];
char name[10];
char pass[16];
//用户结构体
User* head, * p, * p1, * p2;

//————————————————————————登录、注册、忘记密码功能————————————————————————


//注册添加新用户信息赋值函数
void add()//添加用户
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
	printf("添加成功");
}

//登录状态判断函数
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
				return 2;//密码错误
			}
			else {
				all_free();
				return 0;
			}//登录成功
		}
		p = p->next;
	}
	all_free();
	return 1;//账号不存在
}

//注册界面展示
void registered_show()
{
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, "./res/image/注册界面/registered.png", 1080, 960);
	putimage(0, 0, &img);
	setfillcolor(RGB(75, 160, 73));
	settextcolor(RGB(31, 31, 31));
	settextstyle(30, 0, "楷体");
	setbkmode(TRANSPARENT);
	solidrectangle(400, 100, 680, 140);
	outtextxy(400, 105, "昵称");
	solidrectangle(400, 160, 680, 200);
	outtextxy(400, 165, "密码");
	settextcolor(RGB(127, 131, 247));
	outtextxy(420, 240, "请设置密保答案:");
	settextcolor(RGB(31, 31, 31));
	solidrectangle(320, 300, 760, 340);
	outtextxy(325, 305, "你最喜欢的食物");
	solidrectangle(320, 350, 760, 390);
	outtextxy(325, 355, "你最喜欢的颜色");
	solidrectangle(320, 400, 760, 440);
	outtextxy(325, 405, "你最喜欢的动物");
	solidrectangle(460, 460, 620, 500);
	outtextxy(510, 465, "注册");
	solidrectangle(460, 520, 620, 560);
	outtextxy(510, 525, "返回");
	setfillcolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	fillrectangle(470, 105, 670, 135); //昵称输入框
	fillrectangle(470, 165, 670, 195); //密码输入框
	fillrectangle(535, 305, 755, 335);
	fillrectangle(535, 355, 755, 385);
	fillrectangle(535, 405, 755, 435);
	EndBatchDraw();
}

//登录界面展示
void login_show()
{
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, "./res/image/登录界面/login.png", 1080, 960);
	putimage(0, 0, &img);
	setfillcolor(RGB(134, 192, 195));
	settextcolor(RED);
	settextstyle(30, 0, "楷体");
	setbkmode(TRANSPARENT);
	solidrectangle(400, 310, 680, 350);
	outtextxy(410, 315, "UID");
	solidrectangle(400, 370, 680, 410);
	outtextxy(400, 375, "密码");
	solidrectangle(460, 430, 620, 470);
	outtextxy(480, 435, "点击登机");
	setfillcolor(RGB(40, 97, 137));
	solidrectangle(460, 480, 620, 520);
	outtextxy(510, 485, "注册");
	setfillcolor(RGB(49, 115, 177));
	solidrectangle(460, 530, 620, 570);
	outtextxy(480, 535, "找回密码");
	setfillcolor(RGB(167, 103, 112));
	solidrectangle(460, 580, 620, 620);
	outtextxy(480, 585, "退出游戏");
	setfillcolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	fillrectangle(470, 315, 670, 345); //昵称输入框
	fillrectangle(470, 375, 670, 405); //密码输入框

	EndBatchDraw();
}
//忘记密码界面展示
void passback_show()
{
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, "./res/image/忘记密码界面/passback.png", 1080, 960);
	putimage(0, 0, &img);
	setfillcolor(RGB(134, 200, 233));
	settextcolor(RED);
	settextstyle(30, 0, "楷体");
	setbkmode(TRANSPARENT);
	solidrectangle(400, 180, 680, 220);
	outtextxy(410, 185, "UID");
	outtextxy(420, 240, "请回答密保答案:");
	solidrectangle(320, 300, 760, 340);
	outtextxy(325, 305, "你最喜欢的食物");
	solidrectangle(320, 350, 760, 390);
	outtextxy(325, 355, "你最喜欢的颜色");
	solidrectangle(320, 400, 760, 440);
	outtextxy(325, 405, "你最喜欢的动物");
	solidrectangle(460, 460, 620, 500);
	outtextxy(510, 465, "确认");
	solidrectangle(460, 520, 620, 560);
	outtextxy(510, 525, "返回");
	setfillcolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	fillrectangle(460, 185, 675, 215);//uid输入框
	fillrectangle(535, 305, 755, 335);
	fillrectangle(535, 355, 755, 385);
	fillrectangle(535, 405, 755, 435);

	EndBatchDraw();
}

//字符串转整数
int str_int(char login_id[5])  //字符0~9通过减去字符'0'可以获得数值
{

	int num = 0;
	for (int i = 0; i < strlen(login_id); i++)
	{
		num = num * 10 + login_id[i] - '0';  // 通过减去'0'可以将字符转换为int类型的数值
	}
	return num;
}

//整数转字符串
char* int_str(char* str, int num)  //整数转字符串
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

//登录界面处理用户操作函数
void login_input()
{
	void registered();
	void PassBack();//注册函数的声明
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
					InputBox(login_id, 6, "请输入id");
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
					InputBox(pass, 16, "请输入密码");
					outtextxy(470, 375, pass);
					flag2 = 1;
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 430 && msg.y <= 470)
				{
					//获取窗口句柄
					HWND hnd = GetHWnd();
					//弹出窗口，提示用户操作
					int ok = MessageBox(hnd, "确定登录吗？", "提示", MB_OKCANCEL);
					if (ok == IDOK)
					{
						int state = login_state(uid, pass); //输入uid和密码后判断登录状态
						if (state == 0)
						{
							settextcolor(WHITE);
							setbkmode(TRANSPARENT);
							settextstyle(30, 0, "SimHei");
							outtextxy(350, 200, "登录成功, 正在进入菜单界面.....");
							Sleep(1000);
							strcpy(pass, "0");
							cleardevice();
							Menu_Page();
						}
						//该处需补充菜单函数
						else if (state == 1)
						{
							settextcolor(WHITE);
							setbkmode(TRANSPARENT);
							settextstyle(30, 0, "SimHei");
							outtextxy(350, 200, "账号不存在, 正在进入注册界面.....");
							Sleep(1000);
							cleardevice();
							registered();
						}
						else
						{
							settextcolor(WHITE);
							setbkmode(TRANSPARENT);
							settextstyle(30, 0, "SimHei");
							outtextxy(400, 200, "密码错误, 请重新登录");
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
					outtextxy(350, 200, " 正在进入注册界面.....");
					Sleep(1000);
					cleardevice();
					registered();
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 530 && msg.y <= 570)
				{
					settextcolor(WHITE);
					setbkmode(TRANSPARENT);
					settextstyle(30, 0, "SimHei");
					outtextxy(350, 200, " 正在进入找回密码界面.....");
					Sleep(1000);
					cleardevice();
					PassBack();
				}
				else if (msg.x >= 460 && msg.x <= 620 && msg.y >= 580 && msg.y <= 620)
				{
					settextcolor(WHITE);
					setbkmode(TRANSPARENT);
					settextstyle(30, 0, "SimHei");
					outtextxy(350, 200, " 正在进入退出游戏.....");
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


//注册界面信息确认和处理函数
void registered_confirm()//点击注册后确认
{
	//获取窗口句柄
	HWND hnd = GetHWnd();
	//弹出窗口，提示用户操作
	int ok = MessageBox(hnd, "确定注册吗？", "提示", MB_OKCANCEL);
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
		char str[] = "注册成功!您的uid为";
		outtextxy(600, 600, str);
		char id[5];
		outtextxy(600 + textwidth(str), 600, int_str(id, p2->id));
		outtextxy(600, 650, "正在转入登录界面");
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

//注册界面处理用户操作函数
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
					InputBox(name, 10, "请输入昵称");
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
					InputBox(pass, 16, "请输入密码");
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
					InputBox(passback_answer[0], 10, "请输入你喜欢的食物");
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
					InputBox(passback_answer[1], 10, "请输入你喜欢的颜色");
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
					InputBox(passback_answer[2], 16, "请输入你喜欢的动物");
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
						outtextxy(450, 600, "尚未完全输入");
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
						outtextxy(380, 600, "密码长度小于最低长度5");
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


//忘记密码界面信息确认处理函数
void passback_confirm()
{
	void PassBack();
	//获取窗口句柄
	HWND hnd = GetHWnd();
	//弹出窗口，提示用户操作
	int ok = MessageBox(hnd, "确定答案吗？", "提示", MB_OKCANCEL);
	if (ok == IDOK)
	{
		file_read();
		p = head;
		int s[3] = { 0,0,0 };
		char str[] = "答案正确!您的密码为";
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
					outtextxy(400, 600, "你的答案错误！");
					Sleep(1000);
					PassBack();
				}
				break;
			}
		}
		all_free();
	}
}


//忘记密码界面处理用户操作函数
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
					InputBox(login_id, 6, "请输入id");
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
					InputBox(passback_answer[0], 10, "请输入你喜欢的食物");
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
					InputBox(passback_answer[1], 10, "请输入你喜欢的颜色");
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
					InputBox(passback_answer[2], 16, "请输入你喜欢的动物");
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
						outtextxy(450, 600, "尚未完全输入!");
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

//登录函数
void login()
{
	//获取窗口句柄
	HWND hnd = GetHWnd();
	//设置窗口标题
	SetWindowText(hnd, "登录");
	login_show();
	login_input();
}
//注册函数
void registered()
{
	//获取窗口句柄
	HWND hnd = GetHWnd();
	//设置窗口标题
	SetWindowText(hnd, "注册");
	registered_show();
	registered_input();
}
//找回密码函数
void PassBack()
{
	//获取窗口句柄
	HWND hnd = GetHWnd();
	//设置窗口标题
	SetWindowText(hnd, "忘记密码");
	passback_show();
	pass_back();
}

//————————————————————————————排行榜功能————————————————————————————————
void save_score(int mark)//分数保存函数
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

//排行榜函数
void rank(int uid)
{
	int rank_score[4] = { 0,0,0,0 };
	char rank_name[4][10] = { "张三","李四","王五","秦六" };
	if (file_size())
	{
		file_read();
		p = head;
		while (p != NULL)
		{
			for (int i = 0; i < 3; i++)
			{
				if (p->score > rank_score[i])//发现一个较高分，将该分段后移，并将其赋值给rank[i]
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
			outtextxy(600, 600, "当前没有用户得分数据");

		}
		else {
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			settextstyle(60, 0, "SimHei");
			outtextxy(700, 150, "分数");
			outtextxy(200, 150, "昵称");
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
				outtextxy(200, 550, "您的最高分：");
				outtextxy(700, 550, str.data());
			}
			else outtextxy(200, 550, "您当前无分数记录！");
		}
	}
	else {
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(30, 0, "SimHei");
		outtextxy(600, 600, "尚且未有用户");
	}

}



//——————————————————————————————游戏内功能————————————————————————————————
//加载游戏内资源
void Load_Game_Res() {
	//初始化数据
	Load_Enemies_Datas();
	Load_Player_Datas();
	Load_Bul_Datas();
	Load_Obj_Datas();
	//初始化图像
	Load_Game_Images();
}


//刷新敌人
void Make_Enemy() {
	//记录此时此刻
	game_moment = clock();
	//如果离开局小于2秒，则不刷新敌人(返回)
	if ((double)(game_moment - game_start) / CLK_TCK < 2.0) {
		return;
	}
	//当前波次敌人数小于3时，每少一个敌人则刷新一个
	//刷新敌人的位置是随机的
	
	while (enemy_batch < 3 && L.now <= 200) {
		if (L.now <= L.enemy_num) {
			enemy_batch++;
			Init_Enemy(rand() % 600 + 200, L.data[++L.now - 1]);//将指示下次刷新敌人的下标now自增，顺序刷新敌人
		}
	}
}

//处理敌人的射击信息
void Enemy_Shooting() {
	if (L.now == 49) {//如果已经轮到远程敌人出场
		is_e_shoot = true;//将敌人的射击状态更新
		e_shoot_start = clock();//敌人开始射击的时间
	}
	if (is_e_shoot) {
		e_shoot_moment = clock();
		if ((e_shoot_moment - e_shoot_start) / CLK_TCK > 0.5) //敌人上次射击的时间和当前时间差大于0.5s
		{
			//遍历敌人数组，给存活的远程敌人初始化子弹
			for (int i = 1; i <= 50; i++) {
				if (enemies[i - 1].is_live) {
					if (enemies[i - 1].type == 9) {//猫
						e_shoot_start = clock();//重设射击的瞬间时间
						Init_Ene_Bullet(E_Bul_1, -Pi / 6, i);
						Init_Ene_Bullet(E_Bul_1, 0, i);
						Init_Ene_Bullet(E_Bul_1, Pi / 6, i);
					}
					else if (enemies[i - 1].type == 10) {//猪
						e_shoot_start = clock();//重设射击的瞬间时间
						Init_Ene_Bullet(E_Bul_2, -Pi / 6, i);
						Init_Ene_Bullet(E_Bul_2, 0, i);
						Init_Ene_Bullet(E_Bul_2, Pi / 6, i);
					}
					else if (enemies[i - 1].type == 11)
					{//大BOSS
						e_shoot_start = clock();//重设射击的瞬间时间
						BOSS_Shooting(i);//单独处理BOSS的射击
					}
					else {//不是远程敌人，跳过此轮循环
						continue;
					}
				}
			}
		}

	}
}

//BOSS的射击功能
void BOSS_Shooting(int i) {
	//判断boss的血量是否在一半以上
	if (enemies[i - 1].HP >= 1250) {
		BOSS_Shooting_1(i);//BOSS第一状态射击功能
	}
	else { 
		//切换为哥谭小丑音乐
		mciSendString("close ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
		mciSendString("open ./res/audio/焯！.mp3", 0, 0, 0);
		mciSendString("play ./res/audio/焯！.mp3", 0, 0, 0);
		if (!is_chao_start) {
			is_chao_start = true;
			chao_start = clock();
		}
		chao_moment = clock();
		if ((chao_moment - chao_start) / CLK_TCK < 6.7) {
			return;
		}
		if (boss_big_bul) {//BOSS全局唯一一发过渡态子弹
			BOSS_Shooting_1_to_2(i);//BOSS过渡状态射击功能
			boss_big_bul = false;//全局变量设为false，此局内不再发射该子弹
		}
		else //BOSS的过渡态子弹已经发射过了
		{
			BOSS_Shooting_2(i);//BOSS第二状态射击功能
		}
	}
}

//BOSS第一状态射击功能
void BOSS_Shooting_1(int i) {
	//为BOSS初始化其前方120度扇形范围内的五个子弹束
	Init_Boss_Bul_1(i, 0);
	Init_Boss_Bul_1(i, -Pi / 6);
	Init_Boss_Bul_1(i, -Pi / 3);
	Init_Boss_Bul_1(i, Pi / 6);
	Init_Boss_Bul_1(i, Pi / 3);
}

//BOSS过渡状态射击功能
void BOSS_Shooting_1_to_2(int i) {
	Init_Boss_Bul_1_to_2(i, 0);
}

//敌人在第二状态下的射击功能在该状态下，Boss的子弹为360度的、黑白脸相间的弹幕。

void BOSS_Shooting_2(int i) {
	int j = 1;
	double A = 0;
	for (int j = 1; j <= 24; j++) {//循环24次，每次角度 + Pi / 12。
		Init_Boss_Bul_2(i, A);
		A += Pi / 12;
	}
	if (boss_bul_is_black == 0) {//每发射一波子弹，改变其颜色
		boss_bul_is_black = 1;
	}
	else {
		boss_bul_is_black = 0;
	}
	//再次更改boss_bul_is_black的真假，达到每一圈弹幕黑白相间的视觉效果 
}


//————————————————————————商城相关功能——————————————————————————————
void Buy()
{
	//读取用户鼠标操作
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
				//玩家购买了永久无敌
				Shop_Page();
			}
			else if (Mouse.x >= 50 && Mouse.x <= 250 &&
				Mouse.y >= 400 && Mouse.y <= 550 &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				shop_payment(2);
				//玩家购买了最密集子弹
				Shop_Page();
			}
			else if (Mouse.x >= 50 && Mouse.x <= 250 &&
				Mouse.y >= 600 && Mouse.y <= 750 &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				shop_payment(3);
				Shop_Page();
				//玩家购买了皮肤
			}
			else if (Mouse.x >= 50 && Mouse.x <= 250 &&
				Mouse.y >= 800 && Mouse.y <= 900 &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				Rechange();
				//玩家要输入兑换码
			}
		}
	}
	if (Mouse.x >= 930 && Mouse.x <= 1030 &&
		Mouse.y >= 50 && Mouse.y <= 150) {
		Menu_Page();//返回菜单界面
	}
}

//充值货币
void Rechange()
{
	char rechange_code[10] = "0000000";
	InputBox(rechange_code, 10, "请输入充值码");
	int result = Rechange_confirm(rechange_code);
	Get_money(result);
	Shop_Page();
}