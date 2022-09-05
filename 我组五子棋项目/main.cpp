#include"Game.h"

//全局变量
Player Me;				//玩家
MOUSEMSG Mouse;			//鼠标消息
int uid;				//玩家uid
int mark;				//分数
bool start_shooting;	//是否已经开始射击
bool boss_big_bul;		//大BOSS的唯一一次大子弹
bool boss_bul_is_black;	//标识大BOSS的2形态子弹颜色切换
Bullet bullets[500];	//存储场上所有子弹
Bullet Bul[8];			//存放子弹信息
Enemy enemies[50];		//存储场上所有敌人
Enemy Ene[11];			//存储各种敌人的信息
Refresh_Enemy L;		//既定的敌人刷新顺序
Object Obj[10];			//存放掉落物的信息
Object objects[50];		//存放场上所有掉落物
clock_t game_start, game_moment;//游戏过程的计时器
int decrease_cd_times;		//减cd的叠加次数
int decrease_mysize_times;	//减直径的叠加次数
int increase_bul_times;		//增加子弹的叠加次数
int bk_flush = -GR_Height;	//背景初始位置
int enemy_batch;		//每波敌人数目
bool is_victory;		//boss死亡时被设置为TRUE，游戏胜利
bool is_e_shoot;		//敌人是否开始射击，开局为否
clock_t e_shoot_start, e_shoot_moment;//敌人的子弹发射时间
clock_t start_shoot;			//子弹计时
clock_t moment_shoot;			//子弹发射瞬间
clock_t chao_start, chao_moment;	//BOSS的大子弹延迟时间计时
bool is_chao_start;				//BOSS的大子弹延迟时间是否开始

void Login_Page();

int main() {
	initgraph(GR_Width, GR_Height, NULL);
	cleardevice();
	Login_Page();
	return 0;
}