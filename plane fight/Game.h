#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <easyx.h>
#include <graphics.h>
#include <time.h>
#include <mmsystem.h>
#include <string>
#include <cmath>
#pragma comment(lib, "winmm.lib")

#define Pi 3.14159

//玩家
typedef struct Plane {
	int x;			//横坐标
	int y;			//纵坐标
	int HP;			//血量
	double CD;		//攻击速度
	int size;		//直径
	bool is_live;	//是否存活
	bool is_angry;	//是否有血怒
	int bul_bunch;	//子弹束数量
}Plane, * Player;

//敌人
enum Ene_Type {
	Rat = 1,
	Monkey = 2,
	Grandpa = 3,
	Chicken = 4,
	Cattle = 5,
	Bear = 6,
	Ghost = 7,
	Alienware = 8,
	Cat = 9,
	Pig = 10,
	BOSS = 11,
};
typedef struct Enemy {
	int x;
	int y;
	int HP;
	int size;
	int speed;		//移动速度
	bool is_live;	//是否存活
	int type;		//类型
	int damage;		//触碰伤害
	bool left;		//远程敌人的横向移动方向
}Enemy;

//子弹
enum Bul_Type {
	My_Bul_1 = 1,	//玩家非血怒子弹
	My_Bul_2 = 2,	//玩家血怒子弹
	E_Bul_1 = 3,	//猫子弹
	E_Bul_2 = 4,	//猪子弹
	E_Bul_3 = 5,	//BOSS子弹1
	E_Bul_4 = 6,	//BOSS子弹2
	E_Bul_5 = 7,	//BOSS子弹3
	E_Bul_6 = 8,	//BOSS子弹4
};
typedef struct Bullet {
	int x;
	int y;
	int size;
	int speed;		//移动速度
	int damage;		//子弹伤害
	bool is_live;	//是否存活
	int type;		//类型
	double angle;		//角度
}Bullet;

//用户结构体
struct User
{
	int id;
	char name[10];
	char password[16];
	char passback_answer[3][10];
	int score = 0;
	int money = 0;
	bool commodity[3];//购买的服务标识
	struct User* next;
};

//掉落物
enum Obj_Type {
	Anger = 1,				//血怒
	Decrease_CD = 2,		//减少玩家子弹CD
	Decrease_Mysize = 3,	//减少玩家直径
	Gold_Me = 4,			//增加玩家子弹束
	Increase_Bul = 5,		//增加玩家子弹束
	Treat_10 = 6,			//回复玩家10点HP
	Treat_15 = 7,			//回复玩家15点HP
	Treat_30 = 8,			//回复玩家30点HP
	Treat_50 = 9,			//回复玩家50点HP
	Treat_100 = 10			//回复玩家100点HP
};
typedef struct Object {
	int x;
	int y;
	int size;
	int speed;		//移动速度
	bool is_live;	//是否存活
	int type;	//掉落物类型
}Object;

//储存敌人刷新顺序信息的数组
typedef struct {
	int data[200];
	int enemy_num;
	int now;
}Refresh_Enemy;



//窗口大小
enum Graph_Size {
	GR_Width = 1080,
	GR_Height = 960
};

//所有界面链接圆角矩形的尺寸
enum Link_size
{
	Rctg_Width = 300,
	Rctg_Height = 60
};

//登录界面的链接位置
enum Link_Login
{
	//登录
	Login_L = GR_Width / 2 - Rctg_Width / 2,
	Login_T = GR_Height / 2 + 100 - Rctg_Height / 2,
	Login_R = GR_Width / 2 + Rctg_Width / 2,
	Login_B = GR_Height / 2 + 100 + Rctg_Height / 2,
	//注册
	Signin_L = GR_Width / 2 - Rctg_Width / 2,
	Signin_T = GR_Height / 2 + 200 - Rctg_Height / 2,
	Signin_R = GR_Width / 2 + Rctg_Width / 2,
	Signin_B = GR_Height / 2 + 200 + Rctg_Height / 2,
	//忘记密码
	Forget_L = GR_Width / 2 - Rctg_Width / 2,
	Forget_T = GR_Height / 2 + 300 - Rctg_Height / 2,
	Forget_R = GR_Width / 2 + Rctg_Width / 2,
	Forget_B = GR_Height / 2 + 300 + Rctg_Height / 2,
	//退出
	Exit_L = GR_Width / 2 - Rctg_Width / 2,
	Exit_T = GR_Height / 2 + 400 - Rctg_Height / 2,
	Exit_R = GR_Width / 2 + Rctg_Width / 2,
	Exit_B = GR_Height / 2 + 400 + Rctg_Height / 2,
};

//菜单界面的链接位置
enum Link_Menu {
	//开始游戏
	Game_L = GR_Width - Rctg_Width - 20,
	Game_T = GR_Height / 2 - 100 - Rctg_Height / 2,
	Game_R = GR_Width - 20,
	Game_B = GR_Height / 2 - 100 + Rctg_Height / 2,

	//排行榜
	Rank_L = GR_Width - Rctg_Width - 20,
	Rank_T = GR_Height / 2 - Rctg_Height / 2,
	Rank_R = GR_Width - 20,
	Rank_B = GR_Height / 2 + Rctg_Height / 2,

	//游戏简介
	Tips_L = GR_Width - Rctg_Width - 20,
	Tips_T = GR_Height / 2 + 100 - Rctg_Height / 2,
	Tips_R = GR_Width - 20,
	Tips_B = GR_Height / 2 + 100 + Rctg_Height / 2,

	//开发人员简介
	Developer_L = GR_Width - Rctg_Width - 20,
	Developer_T = GR_Height / 2 + 200 - Rctg_Height / 2,
	Developer_R = GR_Width - 20,
	Developer_B = GR_Height / 2 + 200 + Rctg_Height / 2,

	//退出登录
	Logout_L = GR_Width - Rctg_Width - 20,
	Logout_T = GR_Height / 2 + 300 - Rctg_Height / 2,
	Logout_R = GR_Width - 20,
	Logout_B = GR_Height / 2 + 300 + Rctg_Height / 2,

	//退出游戏
	Exit_Menu_L = GR_Width - Rctg_Width - 20,
	Exit_Menu_T = GR_Height / 2 + 400 - Rctg_Height / 2,
	Exit_Menu_R = GR_Width - 20,
	Exit_Menu_B = GR_Height / 2 + 400 + Rctg_Height / 2,
};

//各种速度
enum Speeds {
	Me_Speed = 10,		//玩家移动速度
};