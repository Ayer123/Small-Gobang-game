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

//���
typedef struct Plane {
	int x;			//������
	int y;			//������
	int HP;			//Ѫ��
	double CD;		//�����ٶ�
	int size;		//ֱ��
	bool is_live;	//�Ƿ���
	bool is_angry;	//�Ƿ���Ѫŭ
	int bul_bunch;	//�ӵ�������
}Plane, * Player;

//����
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
	int speed;		//�ƶ��ٶ�
	bool is_live;	//�Ƿ���
	int type;		//����
	int damage;		//�����˺�
	bool left;		//Զ�̵��˵ĺ����ƶ�����
}Enemy;

//�ӵ�
enum Bul_Type {
	My_Bul_1 = 1,	//��ҷ�Ѫŭ�ӵ�
	My_Bul_2 = 2,	//���Ѫŭ�ӵ�
	E_Bul_1 = 3,	//è�ӵ�
	E_Bul_2 = 4,	//���ӵ�
	E_Bul_3 = 5,	//BOSS�ӵ�1
	E_Bul_4 = 6,	//BOSS�ӵ�2
	E_Bul_5 = 7,	//BOSS�ӵ�3
	E_Bul_6 = 8,	//BOSS�ӵ�4
};
typedef struct Bullet {
	int x;
	int y;
	int size;
	int speed;		//�ƶ��ٶ�
	int damage;		//�ӵ��˺�
	bool is_live;	//�Ƿ���
	int type;		//����
	double angle;		//�Ƕ�
}Bullet;

//�û��ṹ��
struct User
{
	int id;
	char name[10];
	char password[16];
	char passback_answer[3][10];
	int score = 0;
	int money = 0;
	bool commodity[3];//����ķ����ʶ
	struct User* next;
};

//������
enum Obj_Type {
	Anger = 1,				//Ѫŭ
	Decrease_CD = 2,		//��������ӵ�CD
	Decrease_Mysize = 3,	//�������ֱ��
	Gold_Me = 4,			//��������ӵ���
	Increase_Bul = 5,		//��������ӵ���
	Treat_10 = 6,			//�ظ����10��HP
	Treat_15 = 7,			//�ظ����15��HP
	Treat_30 = 8,			//�ظ����30��HP
	Treat_50 = 9,			//�ظ����50��HP
	Treat_100 = 10			//�ظ����100��HP
};
typedef struct Object {
	int x;
	int y;
	int size;
	int speed;		//�ƶ��ٶ�
	bool is_live;	//�Ƿ���
	int type;	//����������
}Object;

//�������ˢ��˳����Ϣ������
typedef struct {
	int data[200];
	int enemy_num;
	int now;
}Refresh_Enemy;



//���ڴ�С
enum Graph_Size {
	GR_Width = 1080,
	GR_Height = 960
};

//���н�������Բ�Ǿ��εĳߴ�
enum Link_size
{
	Rctg_Width = 300,
	Rctg_Height = 60
};

//��¼���������λ��
enum Link_Login
{
	//��¼
	Login_L = GR_Width / 2 - Rctg_Width / 2,
	Login_T = GR_Height / 2 + 100 - Rctg_Height / 2,
	Login_R = GR_Width / 2 + Rctg_Width / 2,
	Login_B = GR_Height / 2 + 100 + Rctg_Height / 2,
	//ע��
	Signin_L = GR_Width / 2 - Rctg_Width / 2,
	Signin_T = GR_Height / 2 + 200 - Rctg_Height / 2,
	Signin_R = GR_Width / 2 + Rctg_Width / 2,
	Signin_B = GR_Height / 2 + 200 + Rctg_Height / 2,
	//��������
	Forget_L = GR_Width / 2 - Rctg_Width / 2,
	Forget_T = GR_Height / 2 + 300 - Rctg_Height / 2,
	Forget_R = GR_Width / 2 + Rctg_Width / 2,
	Forget_B = GR_Height / 2 + 300 + Rctg_Height / 2,
	//�˳�
	Exit_L = GR_Width / 2 - Rctg_Width / 2,
	Exit_T = GR_Height / 2 + 400 - Rctg_Height / 2,
	Exit_R = GR_Width / 2 + Rctg_Width / 2,
	Exit_B = GR_Height / 2 + 400 + Rctg_Height / 2,
};

//�˵����������λ��
enum Link_Menu {
	//��ʼ��Ϸ
	Game_L = GR_Width - Rctg_Width - 20,
	Game_T = GR_Height / 2 - 100 - Rctg_Height / 2,
	Game_R = GR_Width - 20,
	Game_B = GR_Height / 2 - 100 + Rctg_Height / 2,

	//���а�
	Rank_L = GR_Width - Rctg_Width - 20,
	Rank_T = GR_Height / 2 - Rctg_Height / 2,
	Rank_R = GR_Width - 20,
	Rank_B = GR_Height / 2 + Rctg_Height / 2,

	//��Ϸ���
	Tips_L = GR_Width - Rctg_Width - 20,
	Tips_T = GR_Height / 2 + 100 - Rctg_Height / 2,
	Tips_R = GR_Width - 20,
	Tips_B = GR_Height / 2 + 100 + Rctg_Height / 2,

	//������Ա���
	Developer_L = GR_Width - Rctg_Width - 20,
	Developer_T = GR_Height / 2 + 200 - Rctg_Height / 2,
	Developer_R = GR_Width - 20,
	Developer_B = GR_Height / 2 + 200 + Rctg_Height / 2,

	//�˳���¼
	Logout_L = GR_Width - Rctg_Width - 20,
	Logout_T = GR_Height / 2 + 300 - Rctg_Height / 2,
	Logout_R = GR_Width - 20,
	Logout_B = GR_Height / 2 + 300 + Rctg_Height / 2,

	//�˳���Ϸ
	Exit_Menu_L = GR_Width - Rctg_Width - 20,
	Exit_Menu_T = GR_Height / 2 + 400 - Rctg_Height / 2,
	Exit_Menu_R = GR_Width - 20,
	Exit_Menu_B = GR_Height / 2 + 400 + Rctg_Height / 2,
};

//�����ٶ�
enum Speeds {
	Me_Speed = 10,		//����ƶ��ٶ�
};