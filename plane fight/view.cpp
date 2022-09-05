#include"Game.h"

//view层函数
void Login_Page();		//登录界面
void Signin_Page();		//注册界面
void Forget_Page();		//忘记密码界面
void Menu_Page();		//菜单界面
void Rank_Page();		//排行榜界面
void Developer_Page();	//开发人员简介
void Tips_Page();		//游戏简介
void Game_Page();		//游戏页面
void Pause_Page();		//暂停页面
void Shop_Page();		//商城页面
void Victory_Page();	//游戏胜利页面
void Perish_Page();		//游戏失败页面
void Display_Link_Login();//显示登录界面的链接
void Get_Mouse_Login();//登录界面处理鼠标信息
void Display_Link_Menu();//显示菜单页面的链接
void Get_Mouse_Menu();//读取菜单页用户的鼠标输入采取行动
void Put_Me();//打印玩家
void Put_Bul();//打印子弹并实现其移动
void Put_Objects();//打印掉落物
void Put_Mark();//打印分数
void Put_HP();//打印血量
void Put_Enemies();//打印敌人并实现其移动
void Get_Keyboard_Game();//处理游戏内玩家的移动和暂停键盘消息
void Flush_Game_bk();//显示游戏界面的移动背景
void Move_Me();//根据键盘输入，修改玩家位置
void Shooting();//玩家射击功能

//引用的功能、全局变量
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


//————————————————————————登录界面相关————————————————————————
void Login_Page() {
	//打印背景图
	loadimage(Page[0], "./res/image/登录界面/login_page.png");
	putimage(0, 0, Page[0]);
	//显示按钮并等待用户输入
	Display_Link_Login();
	Get_Mouse_Login();
}
void Display_Link_Login() {
	//文字的格式
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	//背景矩形填充颜色
	setfillcolor(RGB(34, 249, 255));
	//绘制矩形和输出文字，即显示按钮链接
	fillroundrect(Login_L, Login_T, Login_R, Login_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("登录") / 2,
		GR_Height / 2 + 100 - textheight("登录") / 2,
		"登录");
	fillroundrect(Signin_L, Signin_T, Signin_R, Signin_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("注册") / 2,
		GR_Height / 2 + 200 - textheight("注册") / 2,
		"注册");
	fillroundrect(Forget_L, Forget_T, Forget_R, Forget_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("忘记密码") / 2,
		GR_Height / 2 + 300 - textheight("忘记密码") / 2,
		"忘记密码");
	fillroundrect(Exit_L, Exit_T, Exit_R, Exit_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("退出") / 2,
		GR_Height / 2 + 400 - textheight("退出") / 2,
		"退出");
}
void Get_Mouse_Login() {
	//死循环读取用户的鼠标输入，读取到之后要跳转到相应页面并退出循环
	while (1) {
		if (MouseHit()) {
			//获取鼠标消息
			Mouse = GetMouseMsg();
			//用户的鼠标在按钮范围内，并且按下左键
			if (Mouse.x >= Login_L && Mouse.x <= Login_R &&
				Mouse.y >= Login_T && Mouse.y <= Login_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//登录功能
				login();
				break;
			}
			else if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
				Mouse.y >= Signin_T && Mouse.y <= Signin_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//注册页面
				Signin_Page();
				break;
			}
			else if (Mouse.x >= Forget_L && Mouse.x <= Forget_R &&
				Mouse.y >= Forget_T && Mouse.y <= Forget_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//忘记密码界面
				Forget_Page();
				break;
			}
			else if (Mouse.x >= Exit_L && Mouse.x <= Exit_R &&
				Mouse.y >= Exit_T && Mouse.y <= Exit_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//直接退出程序
				exit(0);
			}
		}
	}
}

//————————————————————————注册界面相关————————————————————————
void Signin_Page() {
	//调用封装好的注册界面
	registered();
}

//————————————————————————忘记密码界面相关————————————————————————
void Forget_Page() {
	//调用封装好的忘记密码界面
	PassBack();
}

//————————————————————————菜单界面相关————————————————————————
void Menu_Page() {
	//加载相关资源
	loadimage(Page[3], "./res/image/菜单界面/menu_page.png");
	//展示背景图
	putimage(0, 0, Page[3]);
	//显示按键、读取用户鼠标输入
	Display_Link_Menu();
	Get_Mouse_Menu();
}
void Display_Link_Menu() {
	//设置文字格式
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	//设置矩形填充格式
	setfillcolor(RGB(135, 135, 135));
	//绘制各个按键
	fillroundrect(Game_L, 250, Game_R, 310, 10, 10);
	outtextxy(GR_Width - textwidth("商店") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 - 200 - textheight("商店") / 2,
		"商店");
	fillroundrect(Game_L, Game_T, Game_R, Game_B, 10, 10);
	outtextxy(GR_Width - textwidth("开始游戏") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 - 100 - textheight("开始游戏") / 2,
		"开始游戏");
	fillroundrect(Rank_L, Rank_T, Rank_R, Rank_B, 10, 10);
	outtextxy(GR_Width - textwidth("排行榜") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 - textheight("排行榜") / 2,
		"排行榜");
	fillroundrect(Tips_L, Tips_T, Tips_R, Tips_B, 10, 10);
	outtextxy(GR_Width - textwidth("游戏简介") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 + 100 - textheight("游戏简介") / 2,
		"游戏简介");
	fillroundrect(Developer_L, Developer_T, Developer_R, Developer_B, 10, 10);
	outtextxy(GR_Width - textwidth("开发人员简介") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 + 200 - textheight("开发人员简介") / 2,
		"开发人员简介");
	fillroundrect(Logout_L, Logout_T, Logout_R, Logout_B, 10, 10);
	outtextxy(GR_Width - textwidth("退出登录") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 + 300 - textheight("退出登录") / 2,
		"退出登录");
	fillroundrect(Exit_Menu_L, Exit_Menu_T, Exit_Menu_R, Exit_Menu_B, 10, 10);
	outtextxy(GR_Width - textwidth("退出游戏") / 2 - 20 - Rctg_Width / 2,
		GR_Height / 2 + 400 - textheight("退出游戏") / 2,
		"退出游戏");
}
void Get_Mouse_Menu() {
	//死循环读取用户的鼠标输入，读取到之后要跳转到相应页面并退出循环
	while (1) {
		if (MouseHit()) {
			//获取鼠标消息
			Mouse = GetMouseMsg();
			//用户的鼠标在按钮范围内，并且按下左键
			if (Mouse.x >= Game_L && Mouse.x <= Game_R &&
				Mouse.y >= Game_T && Mouse.y <= Game_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//游戏界面
				Game_Page();
				break;
			}
			else if (Mouse.x >= Game_L && Mouse.x <= Rank_R &&
				Mouse.y >= 250 && Mouse.y <= 310 &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//商店页面
				Shop_Page();
				break;
			}
			else if (Mouse.x >= Rank_L && Mouse.x <= Rank_R &&
				Mouse.y >= Rank_T && Mouse.y <= Rank_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//排行榜页面
				Rank_Page();
				break;
			}
			else if (Mouse.x >= Tips_L && Mouse.x <= Tips_R &&
				Mouse.y >= Tips_T && Mouse.y <= Tips_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//游戏简介界面
				Tips_Page();
				break;
			}
			else if (Mouse.x >= Developer_L && Mouse.x <= Developer_R &&
				Mouse.y >= Developer_T && Mouse.y <= Developer_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//开发人员简介界面
				Developer_Page();
				break;
			}
			else if (Mouse.x >= Logout_L && Mouse.x <= Logout_R &&
				Mouse.y >= Logout_T && Mouse.y <= Logout_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//返回到登录界面
				Login_Page();
				break;
			}
			else if (Mouse.x >= Exit_Menu_L && Mouse.x <= Exit_Menu_R &&
				Mouse.y >= Exit_Menu_T && Mouse.y <= Exit_Menu_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {
				//退出程序
				exit(0);
				break;
			}
		}
	}
}

//————————————————————————排行界面相关————————————————————————
void Rank_Page() {
	//加载相关资源
	loadimage(Page[4], "./res/image/排行界面/rank_page.png");
	//展示背景图
	putimage(0, 0, Page[4]);
	//展示按键、读取鼠标信息
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	setfillcolor(RGB(255, 255, 255));
	fillroundrect(Exit_L, Exit_T, Exit_R, Exit_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("返回") / 2,
			GR_Height / 2 + 400 - textheight("返回") / 2,
			"返回");
	rank(uid);
	while (1) {
		if (MouseHit()) {
			Mouse = GetMouseMsg();
			if (Mouse.x >= Exit_L && Mouse.x <= Exit_R &&
				Mouse.y >= Exit_T && Mouse.y <= Exit_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {//返回到登录界面
				break;
			}
		}
	}if (Mouse.x >= Exit_L && Mouse.x <= Exit_R &&
		Mouse.y >= Exit_T && Mouse.y <= Exit_B) {
		Menu_Page();
		return;
	}
}

//————————————————————————开发人员简介界面相关————————————————————————
void Developer_Page() {
	//加载相关资源
	loadimage(Page[5], "./res/image/开发者简介界面/developer_page.png");
	//展示背景图
	putimage(0, 0, Page[5]);
	{
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		settextstyle(30, 0, "SimHei");
		setfillcolor(RGB(255, 255, 255));
		fillroundrect(730, Exit_T, 1030, Exit_B, 10, 10);
		outtextxy(880 - textwidth("返回") / 2,
			GR_Height / 2 + 400 - textheight("返回") / 2,
			"返回");
		//反馈鼠标输入
		while (1) {
			if (MouseHit()) {
				Mouse = GetMouseMsg();
				if (Mouse.x >= 730 && Mouse.x <= 1030 &&
					Mouse.y >= Exit_T && Mouse.y <= Exit_B &&
					Mouse.uMsg == WM_LBUTTONDOWN) {//返回到登录界面
					Menu_Page();
				}
			}
		}
	}
}



//————————————————————————游戏简介界面相关————————————————————————
void Tips_Page() {
	//加载相关资源
	loadimage(Page[6], "./res/image/游戏简介界面/tips_page_1.png", 1080, 960);
	loadimage(Page[15], "./res/image/游戏简介界面/tips_page_2.png", 1080, 960);
	loadimage(Page[16], "./res/image/游戏简介界面/tips_page_3.png", 1080, 960);
	loadimage(Page[17], "./res/image/游戏简介界面/tips_page_4.png", 1080, 960);
	//页面数
	int tips_status = 1;
	{
		BeginBatchDraw();
		//反馈用混的鼠标操作
		while (1) {
			//按页面展示背景图
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
			//返回按钮
			fillroundrect(960, 890, 1070, 940, 10, 10);
			outtextxy(1010 - textwidth("返回") / 2,
				915 - textheight("返回") / 2,
				"返回");
			//第一页
			fillroundrect(1020, 190, 1070, 290, 10, 10);
			outtextxy(1045 - textwidth("1") / 2,
				240 - textheight("1") / 2,
				"1");
			//第二页
			fillroundrect(1020, 350, 1070, 450, 10, 10);
			outtextxy(1045 - textwidth("2") / 2,
				400 - textheight("2") / 2,
				"2");
			//第三页
			fillroundrect(1020, 510, 1070, 610, 10, 10);
			outtextxy(1045 - textwidth("3") / 2,
				560 - textheight("3") / 2,
				"3");
			//第四页
			fillroundrect(1020, 670, 1070, 770, 10, 10);
			outtextxy(1045 - textwidth("4") / 2,
				720 - textheight("4") / 2,
				"4");

			FlushBatchDraw();
			if (MouseHit()) {
				Mouse = GetMouseMsg();
				if (Mouse.x >= 960 && Mouse.x <= 1070 &&
					Mouse.y >= 890 && Mouse.y <= 940 &&
					Mouse.uMsg == WM_LBUTTONDOWN) {//返回到菜单界面
					EndBatchDraw();
					break;
				}
				else if (Mouse.x >= 1020 && Mouse.x <= 1070 &&
					Mouse.y >= 190 && Mouse.y <= 290 &&
					Mouse.uMsg == WM_LBUTTONDOWN) {//第一页
					tips_status = 1;
				}
				else if (	Mouse.x >= 1020 && Mouse.x <= 1070 &&
							Mouse.y >= 350 && Mouse.y <= 450 &&
							Mouse.uMsg == WM_LBUTTONDOWN) {//第二页
					tips_status = 2;
				}
				else if (Mouse.x >= 1020 && Mouse.x <= 1070 &&
					Mouse.y >= 510 && Mouse.y <= 610 &&
					Mouse.uMsg == WM_LBUTTONDOWN) {//第三页
					tips_status = 3;
				}
				else if (Mouse.x >= 1020 && Mouse.x <= 1070 &&
					Mouse.y >= 670 && Mouse.y <= 770 &&
					Mouse.uMsg == WM_LBUTTONDOWN) {//第四页
					tips_status = 4;
				}
			}
		}if (Mouse.x >= 960 && Mouse.x <= 1070 &&
			Mouse.y >= 890 && Mouse.y <= 940) {//返回到菜单界面
			Menu_Page();
			return;
		}
	}
}




//————————————————————————游戏界面相关————————————————————————
void Game_Page() {
	//为玩家分配存储空间
	mark = 0;
	Me = (Player)malloc(sizeof(Plane));
	Load_Game_Res();
	//循环的"计时器"，实现帧率控制
	clock_t start_bk, moment_bk;
	start_bk = clock();
	//游戏的开始时刻
	game_start = clock();
	//开始游戏时"第0波"敌人数量为0
	enemy_batch = 0;
	is_victory = false;
	BeginBatchDraw();
	//准备完成，循环打印开始(游戏开始)
	mciSendString("open ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
	mciSendString("play ./res/audio/BACO-SUPERNOVA.mp3 repeat", 0, 0, 0);

	while (Me->HP > 0)
	{
		//判断是否达到一帧的持续时间
		{
			moment_bk = clock();
			if ((double)(moment_bk - start_bk) / CLK_TCK <= 0.0166) {
				continue;
			}start_bk = clock();
		}
		//处理玩家的键盘信息
		Get_Keyboard_Game();

		//刷新敌人
		Make_Enemy();
		//处理敌人的射击信息
		Enemy_Shooting();
		//检测碰撞、更新各个目标信息、更新分数
		mark += Me_and_Bullet() + Me_and_Enemy() + Me_and_Object() + Enemy_and_Bullet();
		//玩家如果无敌，血量回到100
		file_read();
		for (p = head; p != NULL; p = p->next) {
			if (p->id == uid) {
				if (p->commodity[0]) {
					Me->HP = 100;
				}
			}
		}
		all_free();
		//依据血量、坐标，设置各个目标的死活
		Set_Is_Live();
		//输出页面元素，死亡的目标将不会被打印
		Flush_Game_bk();	//打印游戏背景
		Put_Me();			//打印玩家
		Put_Enemies();		//打印敌人
		Put_Bul();			//打印子弹、同时设置其移动
		Put_HP();			//打印玩家血量
		Put_Mark();			//打印分数
		Put_Objects();		//打印掉落物
		FlushBatchDraw();
		//boss死亡，胜利
		if (is_victory) {
			//释放玩家存储空间
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

//打印玩家
void Put_Me() {
	//依据玩家血量、怒气状态打印玩家
	//读取玩家购买皮肤的状态
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

//打印子弹
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

//打印掉落物
void Put_Objects() {
	//遍历objects数组，打印一切存活掉落物
	for (int i = 1; i <= 50; i++) {
		//存活单位才需要打印
		if (objects[i - 1].is_live) {
			putimage(objects[i - 1].x, objects[i - 1].y, Obj_Image[objects[i - 1].type - 1][0], SRCAND);
			putimage(objects[i - 1].x, objects[i - 1].y, Obj_Image[objects[i - 1].type - 1][1], SRCPAINT);
			//依据坐标、速度更改位置实现移动
			objects[i - 1].y += objects[i - 1].speed;
		}
	}
}

//打印分数
void Put_Mark() {
	std::string str = std::to_string(mark);//将分数转为string类型
	//设置文字格式
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "SimHei");
	//打印分数值
	outtextxy(0, 0, "分数：");
	outtextxy(150, 0, str.data());
}

//打印血量血条
void Put_HP() {
	std::string str = std::to_string(Me->HP);//将血量值转为string类型以便打印
	//设置文字格式
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	outtextxy(0, 900, str.data());
	//血量有多少，就打印多少个2*30的小矩形（实现动态血条）
	if (Me->HP > 0) {
		for (int i = 1; i <= Me->HP; i++) {
			putimage(2 * (i - 1), 930, Page[11]);
		}
	}
}

//打印敌人
void Put_Enemies() {
	//遍历enemies数组，打印一切存活敌人
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
			//处理敌人的移动
			if (enemies[i - 1].type == Cat || enemies[i - 1].type == Pig || enemies[i - 1].type == BOSS)
			{//远程敌人
				if (enemies[i - 1].y >= GR_Height / 4 - enemies[i - 1].size / 2) //已经到窗口纵向的1/4处
				{
					if (enemies[i - 1].x <= 360 - enemies[i - 1].size / 2)
					{//敌人在左边界左边
						enemies[i - 1].x += enemies[i - 1].speed;
						enemies[i - 1].left = false;//敌人方向为右
					}
					else if (enemies[i - 1].x >= 720 - enemies[i - 1].size / 2)
					{//敌人在右边界右边
						enemies[i - 1].x -= enemies[i - 1].speed;
						enemies[i - 1].left = true;//敌人方向为左
					}
					else {
						//按敌人的移动方向移动
						if (enemies[i - 1].left)
							enemies[i - 1].x -= enemies[i - 1].speed;
						else
							enemies[i - 1].x += enemies[i - 1].speed;
					}
				}
				else {//还未到窗口纵向的1/4处，先纵向移动，同时设置默认向左
					enemies[i - 1].y += enemies[i - 1].speed;
					enemies[i - 1].left = true;
				}
			}
			else{//近战敌人，仅仅向下移动
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

//游戏界面内接受处理键盘消息
void Get_Keyboard_Game() {
	Move_Me();		//处理移动信息
	Shooting();		//处理射击信息
	if (GetAsyncKeyState(VK_ESCAPE)) {//暂停界面
		Pause_Page();
	}
}

//动态的游戏内背景
void Flush_Game_bk() {
	putimage(0, bk_flush, Page[13]);
	bk_flush = (bk_flush + 4) % GR_Height;//更改背景位置
	if (bk_flush > 0) {//打印到超出图片一半位置时，重设背景位置
		bk_flush -= GR_Height;
	}
}

//根据键盘输入，修改玩家位置
void Move_Me() {
	//每一帧打印时，位置都是刷新的
	//上移
	if (GetAsyncKeyState(VK_UP)|| GetAsyncKeyState('W') && Me->y > 0) {
		Me->y -= Me_Speed;
	}//下移
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S') && Me->y < (GR_Height - Me->size)) {
		Me->y += Me_Speed;
	}//左移
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A') && Me->x > 0) {
		Me->x -= Me_Speed;
	}//右移
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D') && Me->x < (GR_Width - Me->size)) {
		Me->x += Me_Speed;
	}
}

//玩家的射击功能
void Shooting() {
	//读取到空格，进行射击
	if (GetAsyncKeyState(VK_SPACE)) {
		if (!start_shooting) {
			//还未开始射击，则更新射击状态，启动射击计时
			start_shooting = true;
			start_shoot = clock();
			//根据玩家子弹束数量初始化子弹
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
			moment_shoot = clock();//此时此刻
			if ((double)(moment_shoot - start_shoot) / CLK_TCK >= Me->CD) //时间差达到射击CD
			{
				start_shoot = clock();//重置计时器
				//根据玩家子弹束数量初始化子弹
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



//————————————————————————暂停界面相关————————————————————————
void Pause_Page() {
	//暂停游戏内音乐
	mciSendString("pause ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
	mciSendString("pause ./res/audio/焯！.mp3", 0, 0, 0);
	//暂停界面
	loadimage(Page[12], "./res/image/暂停界面/pause_page.png", 1080, 960);
	//播放音效“砸瓦鲁多”
	mciSendString("open ./res/audio/The_World.wav", 0, 0, 0);
	mciSendString("play ./res/audio/The_World.wav", 0, 0, 0);
	//放置背景、按钮
	putimage(0, 0, Page[12]);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	setfillcolor(RGB(255, 255, 255));
	fillroundrect(Forget_L, Forget_T, Forget_R, Forget_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("返回") / 2,
		GR_Height / 2 + 300 - textheight("返回") / 2,
		"返回");
	fillroundrect(Signin_L, Signin_T, Signin_R, Signin_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("返回菜单") / 2,
		GR_Height / 2 + 200 - textheight("返回菜单") / 2,
		"返回菜单");
	FlushBatchDraw();//先输出按钮图像
	//循环读取鼠标信息
	while (1) {
		if (MouseHit()) {
			Mouse = GetMouseMsg();
			if (Mouse.x >= Forget_L && Mouse.x <= Forget_R &&
				Mouse.y >= Forget_T && Mouse.y <= Forget_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {//返回游戏
				for (int i = 1; i <= 50; i++) {
					//BOSS血量在50%以下
					if (enemies[i - 1].type == 11 && enemies[i - 1].HP <= 527) {
						//停止暂停音乐并继续游戏内音乐
						mciSendString("close ./res/audio/The_World.wav", 0, 0, 0);
						mciSendString("play ./res/audio/焯！.mp3", 0, 0, 0);
					}
					else {
						//停止暂停音乐并继续游戏内音乐
						mciSendString("close ./res/audio/The_World.wav", 0, 0, 0);
						mciSendString("play ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
					}
				}
				break;
			}
			else if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
				Mouse.y >= Signin_T && Mouse.y <= Signin_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {//返回菜单
				//停止暂停音乐
				mciSendString("close ./res/audio/The_World.wav", 0, 0, 0);
				break;
			}
		}
	}if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
		Mouse.y >= Signin_T && Mouse.y <= Signin_B) {
		EndBatchDraw();
		free(Me);
		//停止暂停音乐并继续游戏内音乐
		mciSendString("close ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
		mciSendString("close ./res/audio/焯！.mp3", 0, 0, 0);
		Menu_Page();
	}
}



//————————————————————————游戏胜利界面相关————————————————————————
void Victory_Page() {
	//分数保存到排行榜
	save_score(mark);
	//打印界面、结束双缓冲绘图
	putimage(0, 0, Page[9], SRCAND);
	putimage(0, 0, Page[10], SRCPAINT);
	EndBatchDraw();
	//绘制按键
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	setfillcolor(RGB(255, 255, 255));
	fillroundrect(Signin_L, Signin_T, Signin_R, Signin_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("返回菜单") / 2,GR_Height / 2 + 200 - textheight("返回菜单") / 2,"返回菜单");
	//停止游戏内音乐
	mciSendString("close ./res/audio/焯！.mp3", 0, 0, 0);
	//播放胜利音乐
	mciSendString("open ./res/audio/victory.mp3", 0, 0, 0);
	mciSendString("play ./res/audio/victory.mp3", 0, 0, 0);
	//循环读取鼠标输入
	while (1) {
		if (MouseHit()) {
			Mouse = GetMouseMsg();
			if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
				Mouse.y >= Signin_T && Mouse.y <= Signin_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {//返回菜单
				mciSendString("close ./res/audio/victory.mp3", 0, 0, 0);
				break;
			}
		}
	}if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
		Mouse.y >= Signin_T && Mouse.y <= Signin_B) {
		Menu_Page();
	}
}



//————————————————————————游戏失败界面相关————————————————————————
void Perish_Page() {
	//分数保存到排行榜
	save_score(mark);
	//打印界面、结束双缓冲绘图
	putimage(0, 0, Page[7], SRCAND);
	putimage(0, 0, Page[8], SRCPAINT);
	EndBatchDraw();
	//绘制按键
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "SimHei");
	setfillcolor(RGB(255, 255, 255));
	fillroundrect(Signin_L, Signin_T, Signin_R, Signin_B, 10, 10);
	outtextxy(GR_Width / 2 - textwidth("返回菜单") / 2,
		GR_Height / 2 + 200 - textheight("返回菜单") / 2,
		"返回菜单");
	//停止游戏内音乐
	mciSendString("close ./res/audio/焯！.mp3", 0, 0, 0);
	mciSendString("close ./res/audio/BACO-SUPERNOVA.mp3", 0, 0, 0);
	//播放失败音乐
	mciSendString("open ./res/audio/perish.mp3", 0, 0, 0);
	mciSendString("play ./res/audio/perish.mp3", 0, 0, 0);
	//循环读取鼠标输入
	while (1) {
		if (MouseHit()) {
			Mouse = GetMouseMsg();
			if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
				Mouse.y >= Signin_T && Mouse.y <= Signin_B &&
				Mouse.uMsg == WM_LBUTTONDOWN) {//返回菜单
				mciSendString("close ./res/audio/perish.mp3", 0, 0, 0);
				break;//先跳出循环
			}
		}
	}if (Mouse.x >= Signin_L && Mouse.x <= Signin_R &&
		Mouse.y >= Signin_T && Mouse.y <= Signin_B) {
		Menu_Page();//再回菜单界面
	}
}


//——————————————————————————商城页面相关————————————————————————————————
void Shop_Page() {
	//打印商城背景图
	loadimage(Page[14], "./res/image/商店界面/shop_page.png");
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
	settextstyle(30, 0, "楷体");
	outtextxy(50, 50, str.data());
	all_free();
	Buy();
}