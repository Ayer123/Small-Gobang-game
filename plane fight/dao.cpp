#define LEN sizeof(struct User)
#define _CRT_SECURE_NO_WARNINGS
#include"Game.h"


//dao层功能
void Init_Player_Bul(double angle);//初始化玩家子弹
void Set_Is_Live();//修改各个目标的存活状态
void Init_Obj(int x, int y, int type);//在指定位置初始化一个指定类型掉落物
int Me_and_Bullet();//处理 玩家 与 敌人子弹 的碰撞，返回分数变化
int Me_and_Enemy();//处理 玩家 与 敌人 的碰撞，返回分数变化
int Me_and_Object();//处理 玩家 与 掉落物 的碰撞，返回分数变化
int Enemy_and_Bullet();//处理 敌人 与 玩家子弹 的碰撞，返回分数变化
void Init_Enemy(int x, int type);//在屏幕上方x处生成类型为type的敌人
void Load_Game_Images();//加载游戏图片资源
void Load_Player_Datas();//加载玩家相关信息
void Load_Enemies_Datas();//加载敌人相关信息
void Load_Bul_Datas();//加载子弹相关信息
void Load_Obj_Datas();//加载掉落物信息
void Set_Enemy_Sequence();//设置好敌人出场顺序信息
void Init_Ene_Bullet(int type, double angle, int i);//初始化敌人(非大BOSS)的子弹
void Init_Boss_Bul_1(int i, double A);//初始化Boss第一状态的一个子弹
void Init_Boss_Bul_1_to_2(int i, double A);//初始化Boss过度状态的一个子弹
void Init_Boss_Bul_2(int i, double A);//初始化Boss第二状态的一个子弹
int file_size();//文件信息判断函数
void file_read();//读取文件信息函数
void file_save();//信息保存文件函数
void all_free();//释放动态内存函数
void shop_payment(int style);//支付货币
void Money_increase(int money);//修改用户的货币
void Get_money(int result);//充值码信息处理后获取货币
int Rechange_confirm(char rechange_code[10]);//判断处理用户输入充值码信息
void Rechange();//充值货币


//引用的功能、全局变量
void Shop_Page();
extern Player Me;
extern int n;
extern Object objects[50];
extern bool is_victory;
extern int enemy_batch;
extern int uid;
extern Enemy enemies[50];
extern Bullet bullets[500];
extern Bullet Bul[8];
extern Enemy Ene[11];
extern Object Obj[10];
extern int increase_bul_times;
extern int decrease_mysize_times;
extern int decrease_cd_times;
extern bool start_shooting;	
extern bool is_e_shoot;
extern bool boss_big_bul;
extern clock_t e_shoot_start, e_shoot_moment;
extern Refresh_Enemy L;
extern bool boss_bul_is_black;
extern clock_t chao_start, chao_moment;
extern bool is_chao_start;
extern User* head, * p, * p1, * p2;


//图片变量，与文件名一致
IMAGE login_page;
IMAGE signin_page;
IMAGE forget_page;
IMAGE menu_page;
IMAGE rank_page;
IMAGE developer_page;
IMAGE tips_page_1;
IMAGE tips_page_2;
IMAGE tips_page_3;
IMAGE tips_page_4;
IMAGE shop_page;
IMAGE anger_w;
IMAGE anger_b;
IMAGE boss_1_w;
IMAGE boss_1_b;
IMAGE boss_2_w;
IMAGE boss_2_b;
IMAGE boss_3_1_w;
IMAGE boss_3_1_b;
IMAGE boss_3_2_w;
IMAGE boss_3_2_b;
IMAGE decrease_cd_w;
IMAGE decrease_cd_b;
IMAGE decrease_mysize_w;
IMAGE decrease_mysize_b;
IMAGE e_bullet_1_w;
IMAGE e_bullet_1_b;
IMAGE e_bullet_2_w;
IMAGE e_bullet_2_b;
IMAGE e_bullet_3_w;
IMAGE e_bullet_3_b;
IMAGE e_bullet_4_w;
IMAGE e_bullet_4_b;
IMAGE e_bullet_5_w;
IMAGE e_bullet_5_b;
IMAGE e_bullet_6_w;
IMAGE e_bullet_6_b;
IMAGE enemy_1_w;
IMAGE enemy_1_b;
IMAGE enemy_2_w;
IMAGE enemy_2_b;
IMAGE enemy_3_w;
IMAGE enemy_3_b;
IMAGE enemy_4_w;
IMAGE enemy_4_b;
IMAGE enemy_5_w;
IMAGE enemy_5_b;
IMAGE enemy_6_w;
IMAGE enemy_6_b;
IMAGE enemy_7_w;
IMAGE enemy_7_b;
IMAGE enemy_8_w;
IMAGE enemy_8_b;
IMAGE game_background;
IMAGE gold_l_w;
IMAGE gold_l_b;
IMAGE gold_me_w;
IMAGE gold_me_b;
IMAGE gold_r_w;
IMAGE gold_r_b;
IMAGE me_1_w;
IMAGE me_1_b;
IMAGE me_2_w;
IMAGE me_2_b;
IMAGE me_3_w;
IMAGE me_3_b;
IMAGE me_4_w;
IMAGE me_4_b;
IMAGE increase_bul_w;
IMAGE increase_bul_b;
IMAGE my_bullet_1_w;
IMAGE my_bullet_1_b;
IMAGE my_bullet_2_w;
IMAGE my_bullet_2_b;
IMAGE treat_10_w;
IMAGE treat_10_b;
IMAGE treat_15_w;
IMAGE treat_15_b;
IMAGE treat_30_w;
IMAGE treat_30_b;
IMAGE treat_50_w;
IMAGE treat_50_b;
IMAGE treat_100_w;
IMAGE treat_100_b;
IMAGE pause_page;
IMAGE victory_w;
IMAGE victory_b;
IMAGE perish_w;
IMAGE perish_b;
IMAGE blood;

//图片变量指针数组
IMAGE* Page[18] = 
{
	&login_page,//1
	&signin_page,//2
	&forget_page,//3
	&menu_page,//4
	&rank_page,//5
	&developer_page,//6
	&tips_page_1,//7
	&perish_w,//8
	&perish_b,//9
	&victory_w,//10
	&victory_b,//11
	&blood,//12
	&pause_page,//13
	&game_background,//14
	&shop_page,//15
	&tips_page_2,//16
	&tips_page_3,//17
	& tips_page_4,//18
};
IMAGE* Bul_Image[8][2] =
{
	{&my_bullet_1_w, &my_bullet_1_b},//1
	{&my_bullet_2_w, &my_bullet_2_b},//2
	{&e_bullet_1_w, &e_bullet_1_b},//3
	{&e_bullet_2_w, &e_bullet_2_b},//4
	{&e_bullet_3_w, &e_bullet_3_b},//5
	{&e_bullet_4_w, &e_bullet_4_b},//6
	{&e_bullet_5_w, &e_bullet_5_b},//7
	{&e_bullet_6_w, &e_bullet_6_b},//8
};
IMAGE* Obj_Image[10][2]
{
	{&anger_w, &anger_b},//1
	{&decrease_cd_w, &decrease_cd_b},//2
	{&decrease_mysize_w, &decrease_mysize_b},//3
	{&gold_me_w, &gold_me_b},//4
	{&increase_bul_w, &increase_bul_b},//5
	{&treat_10_w, &treat_10_b},//6
	{&treat_15_w, &treat_15_b},//7
	{&treat_30_w, &treat_30_b},//8
	{&treat_50_w, &treat_50_b},//9
	{&treat_100_w, &treat_100_b},//10
};
IMAGE* Ene_Image[12][2]
{
	{&enemy_1_w, &enemy_1_b},//1
	{&enemy_2_w, &enemy_2_b},//2
	{&enemy_3_w, &enemy_3_b},//3
	{&enemy_4_w, &enemy_4_b},//4
	{&enemy_5_w, &enemy_5_b},//5
	{&enemy_6_w, &enemy_6_b},//6
	{&enemy_7_w, &enemy_7_b},//7
	{&enemy_8_w, &enemy_8_b},//8
	{&boss_1_w, &boss_1_b},//9
	{&boss_2_w, &boss_2_b},//10
	{&boss_3_1_w, &boss_3_1_b},//11
	{&boss_3_2_w, &boss_3_2_b},//12
};

IMAGE* Me_Image[4][2]
{
	{&me_1_w, &me_1_b},
	{&me_2_w, &me_2_b},
	{&me_3_w, &me_3_b},
	{&me_4_w, &me_4_b},
};


//——————————————————游戏内功能——————————————————————————
//修改各个目标的存活状态
void Set_Is_Live() {
	//子弹的坐标超过了屏幕边界，视为死亡
	for (int i = 1; i <= 500; i++) {
		if (bullets[i - 1].x < -bullets[i - 1].size || bullets[i - 1].x > GR_Width ||
			bullets[i - 1].y < -bullets[i - 1].size || bullets[i - 1].y > GR_Height)
			bullets[i - 1].is_live = false;
	}
	//敌人血量不高于0，视为死亡
	for (int i = 1; i <= 50; i++) {
		if (enemies[i - 1].HP <= 0) {
			//如果boss死亡，直接获胜
			if (enemies[i - 1].type == 11) {
				is_victory = true;
				break;
			}
			enemies[i - 1].is_live = false;
			enemy_batch--;
			srand((unsigned)time(0));
			int type = rand() % 30 + 1;
			if (0 < type && type <= 10) {
				Init_Obj(enemies[i - 1].x, enemies[i - 1].y, type);
			}
		}
	}
	//掉落物超过屏幕边界，视为死亡
	for (int i = 1; i <= 50; i++) {
		if (objects[i - 1].is_live) {
			if (objects[i - 1].y >= GR_Height) {
				objects[i - 1].is_live = false;
			}
		}
	}
}

//初始化一个玩家子弹
void Init_Player_Bul(double angle) {
	int i;
	for (i = 1; i <= 500; i++) {//找到一个可写入子弹数据的位置
		if (!bullets[i - 1].is_live)
			break;
	}
	//按玩家血怒状态为其初始化子弹
	if (Me->is_angry) {
		bullets[i - 1].type = My_Bul_2;
		bullets[i - 1].x = Me->x + Me->size / 2 - 15;
		bullets[i - 1].y = Me->y;
		bullets[i - 1].size = Bul[My_Bul_2 - 1].size;
		bullets[i - 1].is_live = true;
		bullets[i - 1].speed = Bul[My_Bul_2 - 1].speed;
		bullets[i - 1].damage = Bul[My_Bul_2 - 1].damage;
		bullets[i - 1].angle = angle;
	}
	else {
		bullets[i - 1].type = My_Bul_1;
		bullets[i - 1].x = Me->x + Me->size / 2 - 15;
		bullets[i - 1].y = Me->y;
		bullets[i - 1].size = Bul[My_Bul_1 - 1].size;
		bullets[i - 1].is_live = true;
		bullets[i - 1].speed = Bul[My_Bul_1 - 1].speed;
		bullets[i - 1].damage = Bul[My_Bul_1 - 1].damage;
		bullets[i - 1].angle = angle;
	}
}

//在传入位置初始化指定类型掉落物
void Init_Obj(int x, int y, int type) {
	for (int i = 1; i <= 50; i++) {
		if (objects[i - 1].is_live == false) {
			objects[i - 1].is_live = true;//修改状态为存活，生成掉落物
			objects[i - 1].type = Obj[type - 1].type;
			objects[i - 1].size = Obj[type - 1].size;
			objects[i - 1].speed = Obj[type - 1].speed; //初始化掉落物数据
			objects[i - 1].x = x;
			objects[i - 1].y = y;//初始化掉落物坐标
			break;//跳出for循环
		}
	}
}

//游戏初始：加载掉落物数据
void Load_Obj_Datas() {
	//把存放游戏内掉落物数据的objects数组全设为死的
	for (int i = 1; i <= 50; i++)
	{
		objects[i - 1].is_live = false;
	}
	//所有掉落物的速度和直径一致
	for (int i = 1; i <= 10; i++)
	{
		Obj[i - 1].size = 80;
		Obj[i - 1].speed = 3;
	}
	//在存放掉落物信息的数组内初始化其数据
	Obj[Anger - 1].type = Anger;
	Obj[Decrease_CD - 1].type = Decrease_CD;
	Obj[Decrease_Mysize - 1].type = Decrease_Mysize;
	Obj[Gold_Me - 1].type = Gold_Me;
	Obj[Increase_Bul - 1].type = Increase_Bul;
	Obj[Treat_10 - 1].type = Treat_10;
	Obj[Treat_15 - 1].type = Treat_15;
	Obj[Treat_30 - 1].type = Treat_30;
	Obj[Treat_50 - 1].type = Treat_50;
	Obj[Treat_100 - 1].type = Treat_100;
}

//处理玩家与敌人子弹的碰撞
int Me_and_Bullet() {
	int deduct_mark = 0;
	//遍历bullets数组，寻找存活的敌人子弹并检测是否碰撞
	for (int i = 1; i <= 500; i++) {
		if (bullets[i - 1].type > 2 && bullets[i - 1].is_live) 
		{
			//计算该子弹与玩家的圆心距，并判断是否小于两者半径之和
			double x_2 = pow(bullets[i - 1].x + bullets[i - 1].size / 2 - Me->x - Me->size / 2, 2);
			double y_2 = pow(bullets[i - 1].y + bullets[i - 1].size / 2 - Me->y - Me->size / 2, 2);
			double dis = pow(x_2 + y_2, 0.5);
			if (dis <= (double)(bullets[i - 1].size / 2 + Me->size / 2)) {
				Me->HP -= bullets[i - 1].damage;//玩家血量扣减
				deduct_mark -= bullets[i - 1].damage;//分数扣减值为玩家收到伤害
				bullets[i - 1].is_live = false;//该子弹消失
			}
		}
	}
	return deduct_mark;
}

//检测 玩家 和 敌人 的碰撞，返回分数值变化
int Me_and_Enemy() {
	int scare_decrease = 0;
	for (int i = 1; i <= 50; i++) {
		if (enemies[i - 1].is_live) {
			if (enemies[i - 1].y > GR_Height) //敌人到达窗口最下方，视为与玩家相撞
			{
				enemies[i - 1].is_live = false;
				Me->HP -= enemies[i - 1].damage;
				enemy_batch--;
				scare_decrease -= enemies[i - 1].damage;
				continue;
			}
			if (enemies[i - 1].type > 8) {
				continue;
			}
			//计算圆心距
			int x_Me = Me->x + Me->size / 2;
			int y_Me = Me->y + Me->size / 2;
			int x_Ene = enemies[i - 1].x + enemies[i - 1].size / 2;
			int y_Ene = enemies[i - 1].y + enemies[i - 1].size / 2;
			double x_2 = pow(x_Me - x_Ene, 2);
			double y_2 = pow(y_Me - y_Ene, 2);
			double dis = pow(x_2 + y_2, 0.5);
			//判断是否碰撞
			if (dis <= (double)(enemies[i].size / 2 + Me->size / 2))
			{
				if (enemies[i - 1].type <= 10) {//碰撞的敌人非大BOSS
					enemies[i - 1].is_live = false;//敌人去世
					Me->HP -= enemies[i - 1].damage;//扣减玩家血量
					scare_decrease -= enemies[i - 1].damage;//按伤害值扣分
					enemy_batch--;
					continue;
				}
				else {//撞到大BOSS直接去世
					Me->HP = 0; //当场去世
					scare_decrease -= enemies[i - 1].damage;//按伤害值扣分
					continue;
				}
				
			}
		}
	}
	return scare_decrease;
}

//检测玩家与掉落物的碰撞，按掉落物类型采取相应操作，返回分数变化
int Me_and_Object() {
	int x = 0;
	for (int i = 1; i <= 50; i++)
	{
		if (objects[i - 1].is_live) {
			double x_2 = pow((Me->x + Me->size / 2 - objects[i - 1].x - objects[i - 1].size / 2), 2);
			double y_2 = pow((Me->y + Me->size / 2 - objects[i - 1].y - objects[i - 1].size / 2), 2);
			double distance = pow((x_2 + y_2), 0.5);
			if (distance <= (double)(Me->size / 2 + objects[i - 1].size / 2))
			{
				objects[i - 1].is_live = false;
				switch (objects[i - 1].type) {
				case 1:
					//玩家进入血怒状态，永久
					if (Me->is_angry) {
						if (increase_bul_times < 9) {
							increase_bul_times += 2;
							//叠加次数++;
						}
					}
					else {
						Me->is_angry = true;
					}
					break;

				case 2:
					if (decrease_cd_times < 4) {
						Me->CD -= 0.02;
						decrease_cd_times++;
						//玩家CD减少0.05; 叠加次数++;
					}
					break;

				case 3:
					if (decrease_mysize_times < 10) {
						Me->size -= 2;
						decrease_mysize_times++;
						/*玩家size减少2; 叠加次数++;*/
						//改变了图片尺寸，需要重新加载图片
						//Me 1 小丑
						loadimage(&me_1_b, "./res/image/游戏界面/me_1_b.png", Me->size, Me->size);
						loadimage(&me_1_w, "./res/image/游戏界面/me_1_w.png", Me->size, Me->size);
						//Me 2 发怒
						loadimage(&me_2_b, "./res/image/游戏界面/me_2_b.png", Me->size, Me->size);
						loadimage(&me_2_w, "./res/image/游戏界面/me_2_w.png", Me->size, Me->size);
						//Me 3 受不了了
						loadimage(&me_3_b, "./res/image/游戏界面/me_3_b.png", Me->size, Me->size);
						loadimage(&me_3_w, "./res/image/游戏界面/me_3_w.png", Me->size, Me->size);
						//Me 4 鬼脸
						loadimage(&me_4_b, "./res/image/游戏界面/me_4_b.png", Me->size, Me->size);
						loadimage(&me_4_w, "./res/image/游戏界面/me_4_w.png", Me->size, Me->size);
					}
					break;

				case 4:
					//金身也视为叠加子弹束
					if (increase_bul_times < 9) {
						increase_bul_times += 2;
						//叠加次数++;
					}
					break;

				case 5:
					if (increase_bul_times < 9) {
						increase_bul_times += 2;
						//叠加次数++;
					}
					break;
				
				//回复生命值后，生命值不可以高于上限
				case 6:
					Me->HP += 10;
					//玩家生命值 + 10;
					if (Me->HP > 100)
						Me->HP = 100;
					break;

				case 7:
					Me->HP += 15;
					//玩家生命值 + 15;
					if (Me->HP > 100)
						Me->HP = 100;
					break;

				case 8:
					Me->HP += 30;
					//玩家生命值 + 30;
					if (Me->HP > 100)
						Me->HP = 100;
					break;

				case 9:
					Me->HP += 50;
					//玩家生命值 + 50;
					if (Me->HP > 100)
						Me->HP = 100;
					break;

				case 10:
					Me->HP += 100;
					//玩家生命值 + 100;
					if (Me->HP > 100)
						Me->HP = 100;
					break;
				}
				x++;
			}
		}
	}return x * 50;
}

int Enemy_and_Bullet() {
	int r_mark = 0;
	for (int i = 0; i < 50; i++) //遍历敌人数组
	{
		if (enemies[i].is_live) {

			for (int j = 0; j < 500; j++) //遍历子弹数组
			{
				if (bullets[j].is_live) {
					if (bullets[j].type == 1 || bullets[j].type == 2) //玩家子弹才可以对敌人造成伤害
					{
						//计算二者圆心距
						double x_2 = pow(enemies[i].x + enemies[i].size / 2 - bullets[j].x - bullets[j].size / 2, 2);
						double y_2 = pow(enemies[i].y + enemies[i].size / 2 - bullets[j].y - bullets[j].size / 2, 2);
						double dis_2 = x_2 + y_2;
						if (dis_2 <= pow(enemies[i].size / 2 + bullets[j].size / 2, 2))
						{
							enemies[i].HP -= bullets[j].damage;//扣减敌人血量
							r_mark += 10;//分数增加
							bullets[j].is_live = false;//子弹消失
						}
					}
				}
			}
		}
	}
	return r_mark;
}

//在指定横坐标位置的屏幕最上方生成指定类型敌人
void Init_Enemy(int x, int type) {
	//遍历enemies找到可以写入的位置
	for (int i = 1; i <= 50; i++) {
		if (enemies[i - 1].is_live == false) {
			enemies[i - 1].is_live = true;//修改状态为存活，生成敌人
			enemies[i - 1].type = Ene[type - 1].type;
			enemies[i - 1].HP = Ene[type - 1].HP;
			enemies[i - 1].size = Ene[type - 1].size;
			enemies[i - 1].speed = Ene[type - 1].speed;
			enemies[i - 1].damage = Ene[type - 1].damage; //初始化敌人数据
			enemies[i - 1].x = x;
			enemies[i - 1].y = -enemies[i - 1].size;//初始化敌人坐标
			break;//跳出for循环
		}
	}
}

//初始化图片对象
void Load_Game_Images() {
	//EasyX双缓冲打印：需要加载和打印重合的黑底原色与白底黑色图片
	//背景
	loadimage(&game_background, "./res/image/游戏界面/game_background.png");
	//血条
	loadimage(&blood, "./res/image/游戏界面/blood.png", 2, 30);
	//胜利与失败界面
	loadimage(&victory_w, "./res/image/victory_w.png");
	loadimage(&victory_b, "./res/image/victory_b.png");
	loadimage(&perish_w, "./res/image/perish_w.png");
	loadimage(&perish_b, "./res/image/perish_b.png");
	//血怒掉落物
	loadimage(&anger_b, "./res/image/游戏界面/anger_b.png", 60, 60);
	loadimage(&anger_w, "./res/image/游戏界面/anger_w.png", 60, 60);
	//boss 1 猫
	loadimage(&boss_1_b, "./res/image/游戏界面/boss_1_b.png", 100, 100);
	loadimage(&boss_1_w, "./res/image/游戏界面/boss_1_w.png", 100, 100);
	//boss 2 猪 
	loadimage(&boss_2_b, "./res/image/游戏界面/boss_2_b.png", 100, 100);
	loadimage(&boss_2_w, "./res/image/游戏界面/boss_2_w.png", 100, 100);
	//boss 3 1 哭笑脸
	loadimage(&boss_3_1_w, "./res/image/游戏界面/boss_3_1_w.png", 250, 250);
	loadimage(&boss_3_1_b, "./res/image/游戏界面/boss_3_1_b.png", 250, 250);
	//boss 3 2 流汗黄豆
	loadimage(&boss_3_2_b, "./res/image/游戏界面/boss_3_2_b.png", 250, 250);
	loadimage(&boss_3_2_w, "./res/image/游戏界面/boss_3_2_w.png", 250, 250);
	//减cd掉落物
	loadimage(&decrease_cd_w, "./res/image/游戏界面/decrease_cd_w.png", 60, 60);
	loadimage(&decrease_cd_b, "./res/image/游戏界面/decrease_cd_b.png", 60, 60);
	//减size掉落物
	loadimage(&decrease_mysize_w, "./res/image/游戏界面/decrease_mysize_w.png", 60, 60);
	loadimage(&decrease_mysize_b, "./res/image/游戏界面/decrease_mysize_b.png", 60, 60);
	//增加子弹束掉落物
	loadimage(&increase_bul_w, "./res/image/游戏界面/increase_bul_w.png", 60, 60);
	loadimage(&increase_bul_b, "./res/image/游戏界面/increase_bul_b.png", 60, 60);
	//猫的子弹
	loadimage(&e_bullet_1_w, "./res/image/游戏界面/e_bullet_1_w.png", 50, 50);
	loadimage(&e_bullet_1_b, "./res/image/游戏界面/e_bullet_1_b.png", 50, 50);
	//猪的子弹
	loadimage(&e_bullet_2_w, "./res/image/游戏界面/e_bullet_2_w.png", 50, 50);
	loadimage(&e_bullet_2_b, "./res/image/游戏界面/e_bullet_2_b.png", 50, 50);
	//哭笑脸的子弹
	loadimage(&e_bullet_3_w, "./res/image/游戏界面/e_bullet_3_w.png", 60, 60);
	loadimage(&e_bullet_3_b, "./res/image/游戏界面/e_bullet_3_b.png", 60, 60);
	//哭笑脸的超大子弹
	loadimage(&e_bullet_4_w, "./res/image/游戏界面/e_bullet_4_w.png", 200, 200);
	loadimage(&e_bullet_4_b, "./res/image/游戏界面/e_bullet_4_b.png", 200, 200);
	//哭笑脸的弹幕1
	loadimage(&e_bullet_5_w, "./res/image/游戏界面/e_bullet_5_w.png", 60, 60);
	loadimage(&e_bullet_5_b, "./res/image/游戏界面/e_bullet_5_b.png", 60, 60);
	//哭笑脸的弹幕2
	loadimage(&e_bullet_6_w, "./res/image/游戏界面/e_bullet_6_w.png", 60, 60);
	loadimage(&e_bullet_6_b, "./res/image/游戏界面/e_bullet_6_b.png", 60, 60);
	//Me 1 小丑
	loadimage(&me_1_b, "./res/image/游戏界面/me_1_b.png", Me->size, Me->size);
	loadimage(&me_1_w, "./res/image/游戏界面/me_1_w.png", Me->size, Me->size);
	//Me 2 发怒
	loadimage(&me_2_b, "./res/image/游戏界面/me_2_b.png", Me->size, Me->size);
	loadimage(&me_2_w, "./res/image/游戏界面/me_2_w.png", Me->size, Me->size);
	//Me 3 受不了了
	loadimage(&me_3_b, "./res/image/游戏界面/me_3_b.png", Me->size, Me->size);
	loadimage(&me_3_w, "./res/image/游戏界面/me_3_w.png", Me->size, Me->size);
	//Me 4 鬼脸
	loadimage(&me_4_b, "./res/image/游戏界面/me_4_b.png", Me->size, Me->size);
	loadimage(&me_4_w, "./res/image/游戏界面/me_4_w.png", Me->size, Me->size);
	//玩家子弹 1 拳头
	loadimage(&my_bullet_1_b, "./res/image/游戏界面/my_bullet_1_b.png", 30, 30);
	loadimage(&my_bullet_1_w, "./res/image/游戏界面/my_bullet_1_w.png", 30, 30);
	//玩家子弹 2 中指
	loadimage(&my_bullet_2_b, "./res/image/游戏界面/my_bullet_2_b.png", 30, 30);
	loadimage(&my_bullet_2_w, "./res/image/游戏界面/my_bullet_2_w.png", 30, 30);
	//回血10
	loadimage(&treat_10_b, "./res/image/游戏界面/treat_10_b.png", 80, 80);
	loadimage(&treat_10_w, "./res/image/游戏界面/treat_10_w.png", 80, 80);
	//回血15
	loadimage(&treat_15_b, "./res/image/游戏界面/treat_15_b.png", 80, 80);
	loadimage(&treat_15_w, "./res/image/游戏界面/treat_15_w.png", 80, 80);
	//回血30
	loadimage(&treat_30_b, "./res/image/游戏界面/treat_30_b.png", 80, 80);
	loadimage(&treat_30_w, "./res/image/游戏界面/treat_30_w.png", 80, 80);
	//回血50
	loadimage(&treat_50_b, "./res/image/游戏界面/treat_50_b.png", 80, 80);
	loadimage(&treat_50_w, "./res/image/游戏界面/treat_50_w.png", 80, 80);
	//回血100
	loadimage(&treat_100_b, "./res/image/游戏界面/treat_100_b.png", 80, 80);
	loadimage(&treat_100_w, "./res/image/游戏界面/treat_100_w.png", 80, 80);
	//金身掉落物
	loadimage(&gold_me_b, "./res/image/游戏界面/gold_me_b.png", 80, 80);
	loadimage(&gold_me_w, "./res/image/游戏界面/gold_me_w.png", 80, 80);
	//敌人1 老鼠
	loadimage(&enemy_1_b, "./res/image/游戏界面/enemy_1_b.png", 80, 80);
	loadimage(&enemy_1_w, "./res/image/游戏界面/enemy_1_w.png", 80, 80);
	//敌人2 猴子
	loadimage(&enemy_2_b, "./res/image/游戏界面/enemy_2_b.png", 80, 80);
	loadimage(&enemy_2_w, "./res/image/游戏界面/enemy_2_w.png", 80, 80);
	//敌人3 爷
	loadimage(&enemy_3_b, "./res/image/游戏界面/enemy_3_b.png", 80, 80);
	loadimage(&enemy_3_w, "./res/image/游戏界面/enemy_3_w.png", 80, 80);
	//敌人4 鸡
	loadimage(&enemy_4_b, "./res/image/游戏界面/enemy_4_b.png", 80, 80);
	loadimage(&enemy_4_w, "./res/image/游戏界面/enemy_4_w.png", 80, 80);
	//敌人5 牛
	loadimage(&enemy_5_b, "./res/image/游戏界面/enemy_5_b.png", 80, 80);
	loadimage(&enemy_5_w, "./res/image/游戏界面/enemy_5_w.png", 80, 80);
	//敌人6 熊
	loadimage(&enemy_6_b, "./res/image/游戏界面/enemy_6_b.png", 80, 80);
	loadimage(&enemy_6_w, "./res/image/游戏界面/enemy_6_w.png", 80, 80);
	//敌人7 鬼
	loadimage(&enemy_7_b, "./res/image/游戏界面/enemy_7_b.png", 80, 80);
	loadimage(&enemy_7_w, "./res/image/游戏界面/enemy_7_w.png", 80, 80);
	//敌人8 外星人
	loadimage(&enemy_8_b, "./res/image/游戏界面/enemy_8_b.png", 80, 80);
	loadimage(&enemy_8_w, "./res/image/游戏界面/enemy_8_w.png", 80, 80);
}

//加载玩家相关初始属性
void Load_Player_Datas() {
	//buff为0层
	decrease_cd_times = 0;
	decrease_mysize_times = 0;
	increase_bul_times = 1;
	//玩家如果购买子弹密集
	file_read();
	for (p = head; p != NULL; p = p->next) {
		if (p->id == uid) {
			if (p->commodity[1]) {
				increase_bul_times = 9;
			}
		}
	}
	all_free();
	start_shooting = false;//初始未开始射击
	Me->CD = 0.2;

	Me->HP = 100;

	Me->is_angry = false;
	Me->is_live = true;
	Me->size = 60;
	Me->y = GR_Height - Me->size;
	Me->x = GR_Width / 2 - Me->size / 2;
}

//初始化敌人数据
void Load_Enemies_Datas() {
	is_chao_start = false;
	e_shoot_start = clock();//敌人射击计时
	is_e_shoot = false;//敌人初始未开始射击
	boss_big_bul = true;//BOSS的大子弹存在
	enemy_batch = 0;//初始此波敌人数为0
	Set_Enemy_Sequence();//确定敌人的刷新顺序
	//enemies数组全部设为已死
	for (int i = 1; i <= 50; i++) {
		enemies[i - 1].HP = 1;
		enemies[i - 1].is_live = false;
	}
	//把敌人属性写入Ene数组
	//老鼠
	Ene[Rat - 1].type = Rat;
	Ene[Rat - 1].HP = 10;
	Ene[Rat - 1].speed = 1;
	Ene[Rat - 1].damage = 10;
	Ene[Rat - 1].size = 80;
	//猴子
	Ene[Monkey - 1].type = Monkey;
	Ene[Monkey - 1].HP = 12;
	Ene[Monkey - 1].speed = 1;
	Ene[Monkey - 1].damage = 10;
	Ene[Monkey - 1].size = 80;
	//爷
	Ene[Grandpa - 1].type = Grandpa;
	Ene[Grandpa - 1].HP = 15;
	Ene[Grandpa - 1].speed = 1;
	Ene[Grandpa - 1].damage = 10;
	Ene[Grandpa - 1].size = 80;
	//鸡
	Ene[Chicken - 1].type = Chicken;
	Ene[Chicken - 1].HP = 15;
	Ene[Chicken - 1].speed = 2;
	Ene[Chicken - 1].damage = 6;
	Ene[Chicken - 1].size = 80;
	//牛
	Ene[Cattle - 1].type = Cattle;
	Ene[Cattle - 1].HP = 20;
	Ene[Cattle - 1].speed = 1;
	Ene[Cattle - 1].damage = 15;
	Ene[Cattle - 1].size = 80;
	//熊
	Ene[Bear - 1].type = Bear;
	Ene[Bear - 1].HP = 30;
	Ene[Bear - 1].speed = 1;
	Ene[Bear - 1].damage = 30;
	Ene[Bear - 1].size = 80;
	//鬼
	Ene[Ghost - 1].type = Ghost;
	Ene[Ghost - 1].HP = 50;
	Ene[Ghost - 1].speed = 1;
	Ene[Ghost - 1].damage = 20;
	Ene[Ghost - 1].size = 80;
	//外星人
	Ene[Alienware - 1].type = Alienware;
	Ene[Alienware - 1].HP = 30;
	Ene[Alienware - 1].speed = 2;
	Ene[Alienware - 1].damage = 20;
	Ene[Alienware - 1].size = 80;
	//猫
	Ene[Cat - 1].type = Cat;
	Ene[Cat - 1].HP = 100;
	Ene[Cat - 1].speed = 1;
	Ene[Cat - 1].damage = 0;
	Ene[Cat - 1].size = 100;
	//猪
	Ene[Pig - 1].type = Pig;
	Ene[Pig - 1].HP = 150;
	Ene[Pig - 1].size = 100;
	Ene[Pig - 1].damage = 0;
	Ene[Pig - 1].speed = 1;
	//BOSS
	Ene[BOSS - 1].type = BOSS;
	Ene[BOSS - 1].HP = 2500;
	Ene[BOSS - 1].damage = 1000;
	Ene[BOSS - 1].size = 250;
	Ene[BOSS - 1].speed = 3;
}


//初始化子弹数据
void Load_Bul_Datas() {
	
	//bullets数组全设为已死（初始无子弹）
	for (int i = 1; i <= 500; i++) {
		bullets[i - 1].angle = 0;
		bullets[i - 1].is_live = false;
	}
	//将子弹属性写入Bul数组
	//玩家非血怒子弹
	Bul[My_Bul_1 - 1].damage = 2;
	Bul[My_Bul_1 - 1].type = My_Bul_1;
	Bul[My_Bul_1 - 1].size = 30;
	Bul[My_Bul_1 - 1].speed = 10;
	//玩家血怒子弹
	Bul[My_Bul_2 - 1].damage = 4;
	Bul[My_Bul_2 - 1].type = My_Bul_2;
	Bul[My_Bul_2 - 1].size = 30;
	Bul[My_Bul_2 - 1].speed = 10;
	//猫子弹
	Bul[E_Bul_1 - 1].damage = 8;
	Bul[E_Bul_1 - 1].type = E_Bul_1;
	Bul[E_Bul_1 - 1].size = 50;
	Bul[E_Bul_1 - 1].speed = 10;
	//猪子弹
	Bul[E_Bul_2 - 1].damage = 10;
	Bul[E_Bul_2 - 1].type = E_Bul_2;
	Bul[E_Bul_2 - 1].size = 50;
	Bul[E_Bul_2 - 1].speed = 10;
	//BOSS子弹1
	Bul[E_Bul_3 - 1].damage = 10;
	Bul[E_Bul_3 - 1].type = E_Bul_3;
	Bul[E_Bul_3 - 1].size = 50;
	Bul[E_Bul_3 - 1].speed = 10;
	//BOSS子弹2
	Bul[E_Bul_4 - 1].damage = 60;
	Bul[E_Bul_4 - 1].type = E_Bul_4;
	Bul[E_Bul_4 - 1].size = 150;
	Bul[E_Bul_4 - 1].speed = 10;
	//BOSS子弹3
	Bul[E_Bul_5 - 1].damage = 15;
	Bul[E_Bul_5 - 1].type = E_Bul_5;
	Bul[E_Bul_5 - 1].size = 30;
	Bul[E_Bul_5 - 1].speed = 10;
	//BOSS子弹4
	Bul[E_Bul_6 - 1].damage = 15;
	Bul[E_Bul_6 - 1].type = E_Bul_6;
	Bul[E_Bul_6 - 1].size = 30;
	Bul[E_Bul_6 - 1].speed = 10;
}


void Set_Enemy_Sequence() {
	L.now = 0;
	L.enemy_num = 0;
	//前48位为1,1,1,1,1,1,2,2,2,2...
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 6; j++) {
			L.data[++L.enemy_num - 1] = i;
		}
	}
	for (int i = 1; i <= 3; i++) {
		L.data[++L.enemy_num - 1] = 9;
		L.data[++L.enemy_num - 1] = 6;
		L.data[++L.enemy_num - 1] = 8;
	}
	for (int i = 1; i <= 3; i++) {
		L.data[++L.enemy_num - 1] = 10;
		L.data[++L.enemy_num - 1] = 5;
		L.data[++L.enemy_num - 1] = 7;
	}
	L.data[++L.enemy_num - 1] = 11;
	while (L.enemy_num < 200) {
		L.data[++L.enemy_num - 1] = 5;
	}
}

void Init_Ene_Bullet(int type, double angle, int i) {
	//寻找可以写入子弹的位置
	int a;
	for (a = 1; a <= 500; a++) {
		if (!bullets[a - 1].is_live)
			break;
	}
	//按敌人子弹类型写入数据，子弹的坐标依据相应敌人的正下方
	if (type == E_Bul_1) {
		bullets[a - 1].size = Bul[E_Bul_1 - 1].size;
		bullets[a - 1].x = enemies[i - 1].x + enemies[i - 1].size / 2 - bullets[a - 1].size;
		bullets[a - 1].y = enemies[i - 1].y + enemies[i - 1].size;
		bullets[a - 1].is_live = true;
		bullets[a - 1].speed = 10;
		bullets[a - 1].damage = Bul[E_Bul_1 - 1].damage;
		bullets[a - 1].type = E_Bul_1;
		bullets[a - 1].angle = angle;
	}
	else if (type == E_Bul_2)
	{
		bullets[a - 1].size = Bul[E_Bul_2 - 1].size;
		bullets[a - 1].x = enemies[i - 1].x + enemies[i - 1].size / 2 - bullets[a - 1].size;
		bullets[a - 1].y = enemies[i - 1].y + enemies[i - 1].size;
		bullets[a - 1].is_live = true;
		bullets[a - 1].speed = Bul[E_Bul_2 - 1].speed;
		bullets[a - 1].damage = Bul[E_Bul_2 - 1].damage;
		bullets[a - 1].type = E_Bul_2;
		bullets[a - 1].angle = angle;
	}
}

//初始化BOSS第一状态的一颗子弹
void Init_Boss_Bul_1(int i, double angle)
{
	//遍历寻找可以写入的位置
	for (int j = 0; j < 500; j++)
	{
		if (bullets[j].is_live == false)
		{
			//子弹的坐标为BOSS圆心
			bullets[j].size = Bul[E_Bul_3 - 1].size;
			bullets[j].x = enemies[i - 1].x + enemies[i - 1].size / 2 - bullets[j].size / 2;
			bullets[j].y = enemies[i - 1].y + enemies[i - 1].size / 2 - bullets[j].size / 2;
			bullets[j].angle = angle;
			bullets[j].is_live = true;
			bullets[j].type = Bul[E_Bul_3 - 1].type;
			bullets[j].speed = Bul[E_Bul_3 - 1].speed;
			bullets[j].damage = Bul[E_Bul_3 - 1].damage;
			break;
		}
	}
}

//初始化BOSS过渡状态的一颗子弹
void Init_Boss_Bul_1_to_2(int i, double angle) {
	for (int j = 0; j < 500; j++)//遍历寻找可以写入的位置
	{
		if (bullets[j].is_live == false)
		{
			//子弹的坐标依据相应敌人的正下方
			bullets[j].size = Bul[E_Bul_4 - 1].size;
			bullets[j].x = enemies[i - 1].x + enemies[i - 1].size / 2 - bullets[j].size / 2;
			bullets[j].y = enemies[i - 1].y + enemies[i - 1].size;
			bullets[j].angle = angle;
			bullets[j].is_live = true;
			bullets[j].type = Bul[E_Bul_4 - 1].type;
			bullets[j].speed = Bul[E_Bul_4 - 1].speed;
			bullets[j].damage = Bul[E_Bul_4 - 1].damage;
			break;
		}
	}
}

//初始化BOSS第二状态的一颗子弹
void Init_Boss_Bul_2(int i, double A) {
	int j;
	//遍历寻找可以写入的位置
	for (j = 1; j <= 500; j++) {
		if (bullets[j - 1].is_live == 0) {	//判断是否可以放置子弹
			bullets[j - 1].is_live = 1;
			bullets[j - 1].angle = A;
			break;							//放入一颗活子弹后立即退出
		}
	}
	bullets[j - 1].x = enemies[i - 1].x + enemies[i - 1].size / 2 - Bul[E_Bul_6 - 1].size;		//初始化子弹坐标（从BOSS中心生成）
	bullets[j - 1].y = enemies[i - 1].y + enemies[i - 1].size / 2 - Bul[E_Bul_6 - 1].size;
	if (boss_bul_is_black == 1) {			//判断子弹颜色
		bullets[j - 1].type = E_Bul_6;		//黑
		bullets[j - 1].damage = Bul[E_Bul_6 - 1].damage;
		bullets[j - 1].size = Bul[E_Bul_6 - 1].size;
		bullets[j - 1].speed = Bul[E_Bul_6 - 1].speed;
	}
	else {									//白
		bullets[j - 1].type = E_Bul_5;
		bullets[j - 1].damage = Bul[E_Bul_5 - 1].damage;
		bullets[j - 1].size = Bul[E_Bul_5 - 1].size;
		bullets[j - 1].speed = Bul[E_Bul_5 - 1].speed;
	}
}



//排行榜相关功能
//文件信息判断函数
int file_size()
{
	FILE* p = fopen("./data.txt", "r");
	int size = 0;
	fseek(p, 0, SEEK_END);  //范围从0起始位至末尾
	size = ftell(p);  //判断文件大小,若为空，size=0 
	fclose(p);
	return size;
}

//读取文件信息函数
void file_read()
{
	if (file_size())
	{
		FILE* fp;
		if ((fp = fopen("./data.txt", "rb")) == NULL)
		{
			printf("无法打开文件!");
			exit(0);
		}
		do
		{
			p1 = (struct User*)malloc(LEN);
			if (n == 0)
				head = p1;
			else
				p2->next = p1;
			fread(p1, LEN, 1, fp);
			p2 = p1;
			n += 1;
		} while (p2->next != NULL);
		fclose(fp);
		printf("读取完成!\n");

	}

}

//信息保存文件函数
void file_save()
{
	FILE* fp;
	struct User* p;
	if ((fp = fopen("./data.txt", "wb")) == NULL)
		printf("无法打开文件!");
	p = head;
	while (p != NULL)
	{
		if (fwrite(p, LEN, 1, fp) != 1)
		{
			printf("写入数据出错\n");
			fclose(fp);
			break;
		}
		p = p->next;
	}
	fclose(fp);
	printf("存储完成\n");
}

//释放动态内存函数
void all_free()
{
	struct User* f;
	do
	{
		f = head;
		head = head->next;
		free(f);
	} while (head != NULL);
	n = 0;
	printf("清除完成");
}


//————————————————————————————————————————商城功能————————————————————————————————————————————
//支付货币
void shop_payment(int style)
{
	file_read();
	p = head;
	switch (style)
	{
	case 1://永久无敌
		while (p != NULL)
		{
			if (p->id == uid)
			{
				HWND hnd = GetHWnd();
				int ok = MessageBox(hnd, "确认购买吗？", "提示", MB_OKCANCEL);
				if (ok == IDOK)
				{
					if ((p->money >= 100) && (p->commodity[0] == 0)) {
						p->commodity[0] = 1;
						p->money -= 100;
						HWND abc = GetHWnd();
						MessageBox(abc, "购买成功", "提示", MB_OKCANCEL);
						break;
					}
					else if ((p->money >= 100) && (p->commodity[0] == 1))
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "你已经购买过了", "提示", MB_OKCANCEL);
					}
					else
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "抱歉，你的货币不足", "提示", MB_OKCANCEL);
					}
				}
			}
			p = p->next;
		}
		break;
	case 2://子弹束最高
		while (p != NULL)
		{
			if (p->id == uid)
			{
				HWND hnd = GetHWnd();
				int ok = MessageBox(hnd, "确认购买吗？", "提示", MB_OKCANCEL);
				if (ok == IDOK)
				{
					if (p->money >= 200 && (p->commodity[1] == 0)) {
						p->commodity[1] = 1;
						p->money -= 200;
						HWND abc = GetHWnd();
						MessageBox(abc, "购买成功", "提示", MB_OKCANCEL);
						break;
					}
					else if ((p->money >= 200) && (p->commodity[1] == 1))
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "你已经购买过了", "提示", MB_OKCANCEL);
					}
					else
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "抱歉，你的货币不足", "提示", MB_OKCANCEL);
					}
				}
			}
			p = p->next;
		}
		break;
	case 3://玩家新形象
		while (p != NULL)
		{
			if (p->id == uid)
			{
				HWND hnd = GetHWnd();
				int ok = MessageBox(hnd, "确认购买吗？", "提示", MB_OKCANCEL);
				if (ok == IDOK)
				{
					if (p->money >= 300 && (p->commodity[2] == 0)) {
						p->commodity[2] = 1;
						p->money -= 300;
						HWND abc = GetHWnd();
						MessageBox(abc, "购买成功", "提示", MB_OKCANCEL);
						break;
					}
					else if ((p->money >= 300) && (p->commodity[2] == 1))
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "你已经购买过了", "提示", MB_OKCANCEL);
					}
					else
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "抱歉，你的货币不足", "提示", MB_OKCANCEL);
					}
				}
			}
			p = p->next;
		}
		break;
	}
	file_save();
	all_free();
}
//修改用户的货币
void Money_increase(int money)
{
	file_read();
	p = head;
	while (p != NULL)
	{
		if (p->id == uid)
		{
			p->money += money;
			break;
		}
		p = p->next;
	}
	file_save();
	all_free();
}
//充值码信息处理后获取货币
void Get_money(int result)
{
	HWND hnd = GetHWnd();
	switch (result)
	{
	case 0:
		MessageBox(hnd, "您的兑换码错误", "提示", MB_OKCANCEL);
		break;
	case 1:
		MessageBox(hnd, "100货币充值成功！", "提示", MB_OKCANCEL);
		Money_increase(100);
		break;
	case 2:
		MessageBox(hnd, "300货币充值成功！", "提示", MB_OKCANCEL);
		Money_increase(300);
		break;
	case 3:
		MessageBox(hnd, "600货币充值成功！", "提示", MB_OKCANCEL);
		Money_increase(600);
		break;
	}
}
//判断处理用户输入充值码信息
int Rechange_confirm(char rechange_code[10])
{
	char code_confirm[100][10];
	char a[10];
	int flag;
	FILE* fr = fopen("./rechange.txt", "rb");
	if (fr != NULL)
	{
		for (int i = 0; i < 100; i++)
			fread(code_confirm[i], sizeof(a), 1, fr);
	}
	else exit(0);
	fclose(fr);
	for (int i = 1; rechange_code[i] != '\0'; i++)
	{
		if (i % 2 == 1)
			rechange_code[i] += (i + 5);
		else rechange_code[i] -= (i + 5);
	}
	for (int i = 0; i < 100; i++)
	{
		if (!strcmp(code_confirm[i], rechange_code))
		{
			switch (code_confirm[i][0])
			{
			case 'A':
				code_confirm[i][0] = 'D';
				flag = 1;
				break;
			case 'B':
				code_confirm[i][0] = 'D';
				flag = 2;
				break;
			case 'C':
				code_confirm[i][0] = 'D';
				flag = 3;
				break;

			}
			break;
		}
		else flag = 0;
	}
	FILE* fw = fopen("./rechange.txt", "wb");
	for (int i = 0; i < 100; i++)
		fwrite(code_confirm[i], sizeof(a), 1, fw);
	fclose(fw);
	printf("%s\n", "写入成功");
	return flag;
}
