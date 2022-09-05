#define LEN sizeof(struct User)
#define _CRT_SECURE_NO_WARNINGS
#include"Game.h"


//dao�㹦��
void Init_Player_Bul(double angle);//��ʼ������ӵ�
void Set_Is_Live();//�޸ĸ���Ŀ��Ĵ��״̬
void Init_Obj(int x, int y, int type);//��ָ��λ�ó�ʼ��һ��ָ�����͵�����
int Me_and_Bullet();//���� ��� �� �����ӵ� ����ײ�����ط����仯
int Me_and_Enemy();//���� ��� �� ���� ����ײ�����ط����仯
int Me_and_Object();//���� ��� �� ������ ����ײ�����ط����仯
int Enemy_and_Bullet();//���� ���� �� ����ӵ� ����ײ�����ط����仯
void Init_Enemy(int x, int type);//����Ļ�Ϸ�x����������Ϊtype�ĵ���
void Load_Game_Images();//������ϷͼƬ��Դ
void Load_Player_Datas();//������������Ϣ
void Load_Enemies_Datas();//���ص��������Ϣ
void Load_Bul_Datas();//�����ӵ������Ϣ
void Load_Obj_Datas();//���ص�������Ϣ
void Set_Enemy_Sequence();//���úõ��˳���˳����Ϣ
void Init_Ene_Bullet(int type, double angle, int i);//��ʼ������(�Ǵ�BOSS)���ӵ�
void Init_Boss_Bul_1(int i, double A);//��ʼ��Boss��һ״̬��һ���ӵ�
void Init_Boss_Bul_1_to_2(int i, double A);//��ʼ��Boss����״̬��һ���ӵ�
void Init_Boss_Bul_2(int i, double A);//��ʼ��Boss�ڶ�״̬��һ���ӵ�
int file_size();//�ļ���Ϣ�жϺ���
void file_read();//��ȡ�ļ���Ϣ����
void file_save();//��Ϣ�����ļ�����
void all_free();//�ͷŶ�̬�ڴ溯��
void shop_payment(int style);//֧������
void Money_increase(int money);//�޸��û��Ļ���
void Get_money(int result);//��ֵ����Ϣ������ȡ����
int Rechange_confirm(char rechange_code[10]);//�жϴ����û������ֵ����Ϣ
void Rechange();//��ֵ����


//���õĹ��ܡ�ȫ�ֱ���
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


//ͼƬ���������ļ���һ��
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

//ͼƬ����ָ������
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


//��������������������������������������Ϸ�ڹ��ܡ���������������������������������������������������
//�޸ĸ���Ŀ��Ĵ��״̬
void Set_Is_Live() {
	//�ӵ������곬������Ļ�߽磬��Ϊ����
	for (int i = 1; i <= 500; i++) {
		if (bullets[i - 1].x < -bullets[i - 1].size || bullets[i - 1].x > GR_Width ||
			bullets[i - 1].y < -bullets[i - 1].size || bullets[i - 1].y > GR_Height)
			bullets[i - 1].is_live = false;
	}
	//����Ѫ��������0����Ϊ����
	for (int i = 1; i <= 50; i++) {
		if (enemies[i - 1].HP <= 0) {
			//���boss������ֱ�ӻ�ʤ
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
	//�����ﳬ����Ļ�߽磬��Ϊ����
	for (int i = 1; i <= 50; i++) {
		if (objects[i - 1].is_live) {
			if (objects[i - 1].y >= GR_Height) {
				objects[i - 1].is_live = false;
			}
		}
	}
}

//��ʼ��һ������ӵ�
void Init_Player_Bul(double angle) {
	int i;
	for (i = 1; i <= 500; i++) {//�ҵ�һ����д���ӵ����ݵ�λ��
		if (!bullets[i - 1].is_live)
			break;
	}
	//�����Ѫŭ״̬Ϊ���ʼ���ӵ�
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

//�ڴ���λ�ó�ʼ��ָ�����͵�����
void Init_Obj(int x, int y, int type) {
	for (int i = 1; i <= 50; i++) {
		if (objects[i - 1].is_live == false) {
			objects[i - 1].is_live = true;//�޸�״̬Ϊ�����ɵ�����
			objects[i - 1].type = Obj[type - 1].type;
			objects[i - 1].size = Obj[type - 1].size;
			objects[i - 1].speed = Obj[type - 1].speed; //��ʼ������������
			objects[i - 1].x = x;
			objects[i - 1].y = y;//��ʼ������������
			break;//����forѭ��
		}
	}
}

//��Ϸ��ʼ�����ص���������
void Load_Obj_Datas() {
	//�Ѵ����Ϸ�ڵ��������ݵ�objects����ȫ��Ϊ����
	for (int i = 1; i <= 50; i++)
	{
		objects[i - 1].is_live = false;
	}
	//���е�������ٶȺ�ֱ��һ��
	for (int i = 1; i <= 10; i++)
	{
		Obj[i - 1].size = 80;
		Obj[i - 1].speed = 3;
	}
	//�ڴ�ŵ�������Ϣ�������ڳ�ʼ��������
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

//�������������ӵ�����ײ
int Me_and_Bullet() {
	int deduct_mark = 0;
	//����bullets���飬Ѱ�Ҵ��ĵ����ӵ�������Ƿ���ײ
	for (int i = 1; i <= 500; i++) {
		if (bullets[i - 1].type > 2 && bullets[i - 1].is_live) 
		{
			//������ӵ�����ҵ�Բ�ľ࣬���ж��Ƿ�С�����߰뾶֮��
			double x_2 = pow(bullets[i - 1].x + bullets[i - 1].size / 2 - Me->x - Me->size / 2, 2);
			double y_2 = pow(bullets[i - 1].y + bullets[i - 1].size / 2 - Me->y - Me->size / 2, 2);
			double dis = pow(x_2 + y_2, 0.5);
			if (dis <= (double)(bullets[i - 1].size / 2 + Me->size / 2)) {
				Me->HP -= bullets[i - 1].damage;//���Ѫ���ۼ�
				deduct_mark -= bullets[i - 1].damage;//�����ۼ�ֵΪ����յ��˺�
				bullets[i - 1].is_live = false;//���ӵ���ʧ
			}
		}
	}
	return deduct_mark;
}

//��� ��� �� ���� ����ײ�����ط���ֵ�仯
int Me_and_Enemy() {
	int scare_decrease = 0;
	for (int i = 1; i <= 50; i++) {
		if (enemies[i - 1].is_live) {
			if (enemies[i - 1].y > GR_Height) //���˵��ﴰ�����·�����Ϊ�������ײ
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
			//����Բ�ľ�
			int x_Me = Me->x + Me->size / 2;
			int y_Me = Me->y + Me->size / 2;
			int x_Ene = enemies[i - 1].x + enemies[i - 1].size / 2;
			int y_Ene = enemies[i - 1].y + enemies[i - 1].size / 2;
			double x_2 = pow(x_Me - x_Ene, 2);
			double y_2 = pow(y_Me - y_Ene, 2);
			double dis = pow(x_2 + y_2, 0.5);
			//�ж��Ƿ���ײ
			if (dis <= (double)(enemies[i].size / 2 + Me->size / 2))
			{
				if (enemies[i - 1].type <= 10) {//��ײ�ĵ��˷Ǵ�BOSS
					enemies[i - 1].is_live = false;//����ȥ��
					Me->HP -= enemies[i - 1].damage;//�ۼ����Ѫ��
					scare_decrease -= enemies[i - 1].damage;//���˺�ֵ�۷�
					enemy_batch--;
					continue;
				}
				else {//ײ����BOSSֱ��ȥ��
					Me->HP = 0; //����ȥ��
					scare_decrease -= enemies[i - 1].damage;//���˺�ֵ�۷�
					continue;
				}
				
			}
		}
	}
	return scare_decrease;
}

//����������������ײ�������������Ͳ�ȡ��Ӧ���������ط����仯
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
					//��ҽ���Ѫŭ״̬������
					if (Me->is_angry) {
						if (increase_bul_times < 9) {
							increase_bul_times += 2;
							//���Ӵ���++;
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
						//���CD����0.05; ���Ӵ���++;
					}
					break;

				case 3:
					if (decrease_mysize_times < 10) {
						Me->size -= 2;
						decrease_mysize_times++;
						/*���size����2; ���Ӵ���++;*/
						//�ı���ͼƬ�ߴ磬��Ҫ���¼���ͼƬ
						//Me 1 С��
						loadimage(&me_1_b, "./res/image/��Ϸ����/me_1_b.png", Me->size, Me->size);
						loadimage(&me_1_w, "./res/image/��Ϸ����/me_1_w.png", Me->size, Me->size);
						//Me 2 ��ŭ
						loadimage(&me_2_b, "./res/image/��Ϸ����/me_2_b.png", Me->size, Me->size);
						loadimage(&me_2_w, "./res/image/��Ϸ����/me_2_w.png", Me->size, Me->size);
						//Me 3 �ܲ�����
						loadimage(&me_3_b, "./res/image/��Ϸ����/me_3_b.png", Me->size, Me->size);
						loadimage(&me_3_w, "./res/image/��Ϸ����/me_3_w.png", Me->size, Me->size);
						//Me 4 ����
						loadimage(&me_4_b, "./res/image/��Ϸ����/me_4_b.png", Me->size, Me->size);
						loadimage(&me_4_w, "./res/image/��Ϸ����/me_4_w.png", Me->size, Me->size);
					}
					break;

				case 4:
					//����Ҳ��Ϊ�����ӵ���
					if (increase_bul_times < 9) {
						increase_bul_times += 2;
						//���Ӵ���++;
					}
					break;

				case 5:
					if (increase_bul_times < 9) {
						increase_bul_times += 2;
						//���Ӵ���++;
					}
					break;
				
				//�ظ�����ֵ������ֵ�����Ը�������
				case 6:
					Me->HP += 10;
					//�������ֵ + 10;
					if (Me->HP > 100)
						Me->HP = 100;
					break;

				case 7:
					Me->HP += 15;
					//�������ֵ + 15;
					if (Me->HP > 100)
						Me->HP = 100;
					break;

				case 8:
					Me->HP += 30;
					//�������ֵ + 30;
					if (Me->HP > 100)
						Me->HP = 100;
					break;

				case 9:
					Me->HP += 50;
					//�������ֵ + 50;
					if (Me->HP > 100)
						Me->HP = 100;
					break;

				case 10:
					Me->HP += 100;
					//�������ֵ + 100;
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
	for (int i = 0; i < 50; i++) //������������
	{
		if (enemies[i].is_live) {

			for (int j = 0; j < 500; j++) //�����ӵ�����
			{
				if (bullets[j].is_live) {
					if (bullets[j].type == 1 || bullets[j].type == 2) //����ӵ��ſ��ԶԵ�������˺�
					{
						//�������Բ�ľ�
						double x_2 = pow(enemies[i].x + enemies[i].size / 2 - bullets[j].x - bullets[j].size / 2, 2);
						double y_2 = pow(enemies[i].y + enemies[i].size / 2 - bullets[j].y - bullets[j].size / 2, 2);
						double dis_2 = x_2 + y_2;
						if (dis_2 <= pow(enemies[i].size / 2 + bullets[j].size / 2, 2))
						{
							enemies[i].HP -= bullets[j].damage;//�ۼ�����Ѫ��
							r_mark += 10;//��������
							bullets[j].is_live = false;//�ӵ���ʧ
						}
					}
				}
			}
		}
	}
	return r_mark;
}

//��ָ��������λ�õ���Ļ���Ϸ�����ָ�����͵���
void Init_Enemy(int x, int type) {
	//����enemies�ҵ�����д���λ��
	for (int i = 1; i <= 50; i++) {
		if (enemies[i - 1].is_live == false) {
			enemies[i - 1].is_live = true;//�޸�״̬Ϊ�����ɵ���
			enemies[i - 1].type = Ene[type - 1].type;
			enemies[i - 1].HP = Ene[type - 1].HP;
			enemies[i - 1].size = Ene[type - 1].size;
			enemies[i - 1].speed = Ene[type - 1].speed;
			enemies[i - 1].damage = Ene[type - 1].damage; //��ʼ����������
			enemies[i - 1].x = x;
			enemies[i - 1].y = -enemies[i - 1].size;//��ʼ����������
			break;//����forѭ��
		}
	}
}

//��ʼ��ͼƬ����
void Load_Game_Images() {
	//EasyX˫�����ӡ����Ҫ���غʹ�ӡ�غϵĺڵ�ԭɫ��׵׺�ɫͼƬ
	//����
	loadimage(&game_background, "./res/image/��Ϸ����/game_background.png");
	//Ѫ��
	loadimage(&blood, "./res/image/��Ϸ����/blood.png", 2, 30);
	//ʤ����ʧ�ܽ���
	loadimage(&victory_w, "./res/image/victory_w.png");
	loadimage(&victory_b, "./res/image/victory_b.png");
	loadimage(&perish_w, "./res/image/perish_w.png");
	loadimage(&perish_b, "./res/image/perish_b.png");
	//Ѫŭ������
	loadimage(&anger_b, "./res/image/��Ϸ����/anger_b.png", 60, 60);
	loadimage(&anger_w, "./res/image/��Ϸ����/anger_w.png", 60, 60);
	//boss 1 è
	loadimage(&boss_1_b, "./res/image/��Ϸ����/boss_1_b.png", 100, 100);
	loadimage(&boss_1_w, "./res/image/��Ϸ����/boss_1_w.png", 100, 100);
	//boss 2 �� 
	loadimage(&boss_2_b, "./res/image/��Ϸ����/boss_2_b.png", 100, 100);
	loadimage(&boss_2_w, "./res/image/��Ϸ����/boss_2_w.png", 100, 100);
	//boss 3 1 ��Ц��
	loadimage(&boss_3_1_w, "./res/image/��Ϸ����/boss_3_1_w.png", 250, 250);
	loadimage(&boss_3_1_b, "./res/image/��Ϸ����/boss_3_1_b.png", 250, 250);
	//boss 3 2 �����ƶ�
	loadimage(&boss_3_2_b, "./res/image/��Ϸ����/boss_3_2_b.png", 250, 250);
	loadimage(&boss_3_2_w, "./res/image/��Ϸ����/boss_3_2_w.png", 250, 250);
	//��cd������
	loadimage(&decrease_cd_w, "./res/image/��Ϸ����/decrease_cd_w.png", 60, 60);
	loadimage(&decrease_cd_b, "./res/image/��Ϸ����/decrease_cd_b.png", 60, 60);
	//��size������
	loadimage(&decrease_mysize_w, "./res/image/��Ϸ����/decrease_mysize_w.png", 60, 60);
	loadimage(&decrease_mysize_b, "./res/image/��Ϸ����/decrease_mysize_b.png", 60, 60);
	//�����ӵ���������
	loadimage(&increase_bul_w, "./res/image/��Ϸ����/increase_bul_w.png", 60, 60);
	loadimage(&increase_bul_b, "./res/image/��Ϸ����/increase_bul_b.png", 60, 60);
	//è���ӵ�
	loadimage(&e_bullet_1_w, "./res/image/��Ϸ����/e_bullet_1_w.png", 50, 50);
	loadimage(&e_bullet_1_b, "./res/image/��Ϸ����/e_bullet_1_b.png", 50, 50);
	//����ӵ�
	loadimage(&e_bullet_2_w, "./res/image/��Ϸ����/e_bullet_2_w.png", 50, 50);
	loadimage(&e_bullet_2_b, "./res/image/��Ϸ����/e_bullet_2_b.png", 50, 50);
	//��Ц�����ӵ�
	loadimage(&e_bullet_3_w, "./res/image/��Ϸ����/e_bullet_3_w.png", 60, 60);
	loadimage(&e_bullet_3_b, "./res/image/��Ϸ����/e_bullet_3_b.png", 60, 60);
	//��Ц���ĳ����ӵ�
	loadimage(&e_bullet_4_w, "./res/image/��Ϸ����/e_bullet_4_w.png", 200, 200);
	loadimage(&e_bullet_4_b, "./res/image/��Ϸ����/e_bullet_4_b.png", 200, 200);
	//��Ц���ĵ�Ļ1
	loadimage(&e_bullet_5_w, "./res/image/��Ϸ����/e_bullet_5_w.png", 60, 60);
	loadimage(&e_bullet_5_b, "./res/image/��Ϸ����/e_bullet_5_b.png", 60, 60);
	//��Ц���ĵ�Ļ2
	loadimage(&e_bullet_6_w, "./res/image/��Ϸ����/e_bullet_6_w.png", 60, 60);
	loadimage(&e_bullet_6_b, "./res/image/��Ϸ����/e_bullet_6_b.png", 60, 60);
	//Me 1 С��
	loadimage(&me_1_b, "./res/image/��Ϸ����/me_1_b.png", Me->size, Me->size);
	loadimage(&me_1_w, "./res/image/��Ϸ����/me_1_w.png", Me->size, Me->size);
	//Me 2 ��ŭ
	loadimage(&me_2_b, "./res/image/��Ϸ����/me_2_b.png", Me->size, Me->size);
	loadimage(&me_2_w, "./res/image/��Ϸ����/me_2_w.png", Me->size, Me->size);
	//Me 3 �ܲ�����
	loadimage(&me_3_b, "./res/image/��Ϸ����/me_3_b.png", Me->size, Me->size);
	loadimage(&me_3_w, "./res/image/��Ϸ����/me_3_w.png", Me->size, Me->size);
	//Me 4 ����
	loadimage(&me_4_b, "./res/image/��Ϸ����/me_4_b.png", Me->size, Me->size);
	loadimage(&me_4_w, "./res/image/��Ϸ����/me_4_w.png", Me->size, Me->size);
	//����ӵ� 1 ȭͷ
	loadimage(&my_bullet_1_b, "./res/image/��Ϸ����/my_bullet_1_b.png", 30, 30);
	loadimage(&my_bullet_1_w, "./res/image/��Ϸ����/my_bullet_1_w.png", 30, 30);
	//����ӵ� 2 ��ָ
	loadimage(&my_bullet_2_b, "./res/image/��Ϸ����/my_bullet_2_b.png", 30, 30);
	loadimage(&my_bullet_2_w, "./res/image/��Ϸ����/my_bullet_2_w.png", 30, 30);
	//��Ѫ10
	loadimage(&treat_10_b, "./res/image/��Ϸ����/treat_10_b.png", 80, 80);
	loadimage(&treat_10_w, "./res/image/��Ϸ����/treat_10_w.png", 80, 80);
	//��Ѫ15
	loadimage(&treat_15_b, "./res/image/��Ϸ����/treat_15_b.png", 80, 80);
	loadimage(&treat_15_w, "./res/image/��Ϸ����/treat_15_w.png", 80, 80);
	//��Ѫ30
	loadimage(&treat_30_b, "./res/image/��Ϸ����/treat_30_b.png", 80, 80);
	loadimage(&treat_30_w, "./res/image/��Ϸ����/treat_30_w.png", 80, 80);
	//��Ѫ50
	loadimage(&treat_50_b, "./res/image/��Ϸ����/treat_50_b.png", 80, 80);
	loadimage(&treat_50_w, "./res/image/��Ϸ����/treat_50_w.png", 80, 80);
	//��Ѫ100
	loadimage(&treat_100_b, "./res/image/��Ϸ����/treat_100_b.png", 80, 80);
	loadimage(&treat_100_w, "./res/image/��Ϸ����/treat_100_w.png", 80, 80);
	//���������
	loadimage(&gold_me_b, "./res/image/��Ϸ����/gold_me_b.png", 80, 80);
	loadimage(&gold_me_w, "./res/image/��Ϸ����/gold_me_w.png", 80, 80);
	//����1 ����
	loadimage(&enemy_1_b, "./res/image/��Ϸ����/enemy_1_b.png", 80, 80);
	loadimage(&enemy_1_w, "./res/image/��Ϸ����/enemy_1_w.png", 80, 80);
	//����2 ����
	loadimage(&enemy_2_b, "./res/image/��Ϸ����/enemy_2_b.png", 80, 80);
	loadimage(&enemy_2_w, "./res/image/��Ϸ����/enemy_2_w.png", 80, 80);
	//����3 ү
	loadimage(&enemy_3_b, "./res/image/��Ϸ����/enemy_3_b.png", 80, 80);
	loadimage(&enemy_3_w, "./res/image/��Ϸ����/enemy_3_w.png", 80, 80);
	//����4 ��
	loadimage(&enemy_4_b, "./res/image/��Ϸ����/enemy_4_b.png", 80, 80);
	loadimage(&enemy_4_w, "./res/image/��Ϸ����/enemy_4_w.png", 80, 80);
	//����5 ţ
	loadimage(&enemy_5_b, "./res/image/��Ϸ����/enemy_5_b.png", 80, 80);
	loadimage(&enemy_5_w, "./res/image/��Ϸ����/enemy_5_w.png", 80, 80);
	//����6 ��
	loadimage(&enemy_6_b, "./res/image/��Ϸ����/enemy_6_b.png", 80, 80);
	loadimage(&enemy_6_w, "./res/image/��Ϸ����/enemy_6_w.png", 80, 80);
	//����7 ��
	loadimage(&enemy_7_b, "./res/image/��Ϸ����/enemy_7_b.png", 80, 80);
	loadimage(&enemy_7_w, "./res/image/��Ϸ����/enemy_7_w.png", 80, 80);
	//����8 ������
	loadimage(&enemy_8_b, "./res/image/��Ϸ����/enemy_8_b.png", 80, 80);
	loadimage(&enemy_8_w, "./res/image/��Ϸ����/enemy_8_w.png", 80, 80);
}

//���������س�ʼ����
void Load_Player_Datas() {
	//buffΪ0��
	decrease_cd_times = 0;
	decrease_mysize_times = 0;
	increase_bul_times = 1;
	//�����������ӵ��ܼ�
	file_read();
	for (p = head; p != NULL; p = p->next) {
		if (p->id == uid) {
			if (p->commodity[1]) {
				increase_bul_times = 9;
			}
		}
	}
	all_free();
	start_shooting = false;//��ʼδ��ʼ���
	Me->CD = 0.2;

	Me->HP = 100;

	Me->is_angry = false;
	Me->is_live = true;
	Me->size = 60;
	Me->y = GR_Height - Me->size;
	Me->x = GR_Width / 2 - Me->size / 2;
}

//��ʼ����������
void Load_Enemies_Datas() {
	is_chao_start = false;
	e_shoot_start = clock();//���������ʱ
	is_e_shoot = false;//���˳�ʼδ��ʼ���
	boss_big_bul = true;//BOSS�Ĵ��ӵ�����
	enemy_batch = 0;//��ʼ�˲�������Ϊ0
	Set_Enemy_Sequence();//ȷ�����˵�ˢ��˳��
	//enemies����ȫ����Ϊ����
	for (int i = 1; i <= 50; i++) {
		enemies[i - 1].HP = 1;
		enemies[i - 1].is_live = false;
	}
	//�ѵ�������д��Ene����
	//����
	Ene[Rat - 1].type = Rat;
	Ene[Rat - 1].HP = 10;
	Ene[Rat - 1].speed = 1;
	Ene[Rat - 1].damage = 10;
	Ene[Rat - 1].size = 80;
	//����
	Ene[Monkey - 1].type = Monkey;
	Ene[Monkey - 1].HP = 12;
	Ene[Monkey - 1].speed = 1;
	Ene[Monkey - 1].damage = 10;
	Ene[Monkey - 1].size = 80;
	//ү
	Ene[Grandpa - 1].type = Grandpa;
	Ene[Grandpa - 1].HP = 15;
	Ene[Grandpa - 1].speed = 1;
	Ene[Grandpa - 1].damage = 10;
	Ene[Grandpa - 1].size = 80;
	//��
	Ene[Chicken - 1].type = Chicken;
	Ene[Chicken - 1].HP = 15;
	Ene[Chicken - 1].speed = 2;
	Ene[Chicken - 1].damage = 6;
	Ene[Chicken - 1].size = 80;
	//ţ
	Ene[Cattle - 1].type = Cattle;
	Ene[Cattle - 1].HP = 20;
	Ene[Cattle - 1].speed = 1;
	Ene[Cattle - 1].damage = 15;
	Ene[Cattle - 1].size = 80;
	//��
	Ene[Bear - 1].type = Bear;
	Ene[Bear - 1].HP = 30;
	Ene[Bear - 1].speed = 1;
	Ene[Bear - 1].damage = 30;
	Ene[Bear - 1].size = 80;
	//��
	Ene[Ghost - 1].type = Ghost;
	Ene[Ghost - 1].HP = 50;
	Ene[Ghost - 1].speed = 1;
	Ene[Ghost - 1].damage = 20;
	Ene[Ghost - 1].size = 80;
	//������
	Ene[Alienware - 1].type = Alienware;
	Ene[Alienware - 1].HP = 30;
	Ene[Alienware - 1].speed = 2;
	Ene[Alienware - 1].damage = 20;
	Ene[Alienware - 1].size = 80;
	//è
	Ene[Cat - 1].type = Cat;
	Ene[Cat - 1].HP = 100;
	Ene[Cat - 1].speed = 1;
	Ene[Cat - 1].damage = 0;
	Ene[Cat - 1].size = 100;
	//��
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


//��ʼ���ӵ�����
void Load_Bul_Datas() {
	
	//bullets����ȫ��Ϊ��������ʼ���ӵ���
	for (int i = 1; i <= 500; i++) {
		bullets[i - 1].angle = 0;
		bullets[i - 1].is_live = false;
	}
	//���ӵ�����д��Bul����
	//��ҷ�Ѫŭ�ӵ�
	Bul[My_Bul_1 - 1].damage = 2;
	Bul[My_Bul_1 - 1].type = My_Bul_1;
	Bul[My_Bul_1 - 1].size = 30;
	Bul[My_Bul_1 - 1].speed = 10;
	//���Ѫŭ�ӵ�
	Bul[My_Bul_2 - 1].damage = 4;
	Bul[My_Bul_2 - 1].type = My_Bul_2;
	Bul[My_Bul_2 - 1].size = 30;
	Bul[My_Bul_2 - 1].speed = 10;
	//è�ӵ�
	Bul[E_Bul_1 - 1].damage = 8;
	Bul[E_Bul_1 - 1].type = E_Bul_1;
	Bul[E_Bul_1 - 1].size = 50;
	Bul[E_Bul_1 - 1].speed = 10;
	//���ӵ�
	Bul[E_Bul_2 - 1].damage = 10;
	Bul[E_Bul_2 - 1].type = E_Bul_2;
	Bul[E_Bul_2 - 1].size = 50;
	Bul[E_Bul_2 - 1].speed = 10;
	//BOSS�ӵ�1
	Bul[E_Bul_3 - 1].damage = 10;
	Bul[E_Bul_3 - 1].type = E_Bul_3;
	Bul[E_Bul_3 - 1].size = 50;
	Bul[E_Bul_3 - 1].speed = 10;
	//BOSS�ӵ�2
	Bul[E_Bul_4 - 1].damage = 60;
	Bul[E_Bul_4 - 1].type = E_Bul_4;
	Bul[E_Bul_4 - 1].size = 150;
	Bul[E_Bul_4 - 1].speed = 10;
	//BOSS�ӵ�3
	Bul[E_Bul_5 - 1].damage = 15;
	Bul[E_Bul_5 - 1].type = E_Bul_5;
	Bul[E_Bul_5 - 1].size = 30;
	Bul[E_Bul_5 - 1].speed = 10;
	//BOSS�ӵ�4
	Bul[E_Bul_6 - 1].damage = 15;
	Bul[E_Bul_6 - 1].type = E_Bul_6;
	Bul[E_Bul_6 - 1].size = 30;
	Bul[E_Bul_6 - 1].speed = 10;
}


void Set_Enemy_Sequence() {
	L.now = 0;
	L.enemy_num = 0;
	//ǰ48λΪ1,1,1,1,1,1,2,2,2,2...
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
	//Ѱ�ҿ���д���ӵ���λ��
	int a;
	for (a = 1; a <= 500; a++) {
		if (!bullets[a - 1].is_live)
			break;
	}
	//�������ӵ�����д�����ݣ��ӵ�������������Ӧ���˵����·�
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

//��ʼ��BOSS��һ״̬��һ���ӵ�
void Init_Boss_Bul_1(int i, double angle)
{
	//����Ѱ�ҿ���д���λ��
	for (int j = 0; j < 500; j++)
	{
		if (bullets[j].is_live == false)
		{
			//�ӵ�������ΪBOSSԲ��
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

//��ʼ��BOSS����״̬��һ���ӵ�
void Init_Boss_Bul_1_to_2(int i, double angle) {
	for (int j = 0; j < 500; j++)//����Ѱ�ҿ���д���λ��
	{
		if (bullets[j].is_live == false)
		{
			//�ӵ�������������Ӧ���˵����·�
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

//��ʼ��BOSS�ڶ�״̬��һ���ӵ�
void Init_Boss_Bul_2(int i, double A) {
	int j;
	//����Ѱ�ҿ���д���λ��
	for (j = 1; j <= 500; j++) {
		if (bullets[j - 1].is_live == 0) {	//�ж��Ƿ���Է����ӵ�
			bullets[j - 1].is_live = 1;
			bullets[j - 1].angle = A;
			break;							//����һ�Ż��ӵ��������˳�
		}
	}
	bullets[j - 1].x = enemies[i - 1].x + enemies[i - 1].size / 2 - Bul[E_Bul_6 - 1].size;		//��ʼ���ӵ����꣨��BOSS�������ɣ�
	bullets[j - 1].y = enemies[i - 1].y + enemies[i - 1].size / 2 - Bul[E_Bul_6 - 1].size;
	if (boss_bul_is_black == 1) {			//�ж��ӵ���ɫ
		bullets[j - 1].type = E_Bul_6;		//��
		bullets[j - 1].damage = Bul[E_Bul_6 - 1].damage;
		bullets[j - 1].size = Bul[E_Bul_6 - 1].size;
		bullets[j - 1].speed = Bul[E_Bul_6 - 1].speed;
	}
	else {									//��
		bullets[j - 1].type = E_Bul_5;
		bullets[j - 1].damage = Bul[E_Bul_5 - 1].damage;
		bullets[j - 1].size = Bul[E_Bul_5 - 1].size;
		bullets[j - 1].speed = Bul[E_Bul_5 - 1].speed;
	}
}



//���а���ع���
//�ļ���Ϣ�жϺ���
int file_size()
{
	FILE* p = fopen("./data.txt", "r");
	int size = 0;
	fseek(p, 0, SEEK_END);  //��Χ��0��ʼλ��ĩβ
	size = ftell(p);  //�ж��ļ���С,��Ϊ�գ�size=0 
	fclose(p);
	return size;
}

//��ȡ�ļ���Ϣ����
void file_read()
{
	if (file_size())
	{
		FILE* fp;
		if ((fp = fopen("./data.txt", "rb")) == NULL)
		{
			printf("�޷����ļ�!");
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
		printf("��ȡ���!\n");

	}

}

//��Ϣ�����ļ�����
void file_save()
{
	FILE* fp;
	struct User* p;
	if ((fp = fopen("./data.txt", "wb")) == NULL)
		printf("�޷����ļ�!");
	p = head;
	while (p != NULL)
	{
		if (fwrite(p, LEN, 1, fp) != 1)
		{
			printf("д�����ݳ���\n");
			fclose(fp);
			break;
		}
		p = p->next;
	}
	fclose(fp);
	printf("�洢���\n");
}

//�ͷŶ�̬�ڴ溯��
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
	printf("������");
}


//���������������������������������������������������������������������������������̳ǹ��ܡ���������������������������������������������������������������������������������������
//֧������
void shop_payment(int style)
{
	file_read();
	p = head;
	switch (style)
	{
	case 1://�����޵�
		while (p != NULL)
		{
			if (p->id == uid)
			{
				HWND hnd = GetHWnd();
				int ok = MessageBox(hnd, "ȷ�Ϲ�����", "��ʾ", MB_OKCANCEL);
				if (ok == IDOK)
				{
					if ((p->money >= 100) && (p->commodity[0] == 0)) {
						p->commodity[0] = 1;
						p->money -= 100;
						HWND abc = GetHWnd();
						MessageBox(abc, "����ɹ�", "��ʾ", MB_OKCANCEL);
						break;
					}
					else if ((p->money >= 100) && (p->commodity[0] == 1))
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "���Ѿ��������", "��ʾ", MB_OKCANCEL);
					}
					else
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "��Ǹ����Ļ��Ҳ���", "��ʾ", MB_OKCANCEL);
					}
				}
			}
			p = p->next;
		}
		break;
	case 2://�ӵ������
		while (p != NULL)
		{
			if (p->id == uid)
			{
				HWND hnd = GetHWnd();
				int ok = MessageBox(hnd, "ȷ�Ϲ�����", "��ʾ", MB_OKCANCEL);
				if (ok == IDOK)
				{
					if (p->money >= 200 && (p->commodity[1] == 0)) {
						p->commodity[1] = 1;
						p->money -= 200;
						HWND abc = GetHWnd();
						MessageBox(abc, "����ɹ�", "��ʾ", MB_OKCANCEL);
						break;
					}
					else if ((p->money >= 200) && (p->commodity[1] == 1))
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "���Ѿ��������", "��ʾ", MB_OKCANCEL);
					}
					else
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "��Ǹ����Ļ��Ҳ���", "��ʾ", MB_OKCANCEL);
					}
				}
			}
			p = p->next;
		}
		break;
	case 3://���������
		while (p != NULL)
		{
			if (p->id == uid)
			{
				HWND hnd = GetHWnd();
				int ok = MessageBox(hnd, "ȷ�Ϲ�����", "��ʾ", MB_OKCANCEL);
				if (ok == IDOK)
				{
					if (p->money >= 300 && (p->commodity[2] == 0)) {
						p->commodity[2] = 1;
						p->money -= 300;
						HWND abc = GetHWnd();
						MessageBox(abc, "����ɹ�", "��ʾ", MB_OKCANCEL);
						break;
					}
					else if ((p->money >= 300) && (p->commodity[2] == 1))
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "���Ѿ��������", "��ʾ", MB_OKCANCEL);
					}
					else
					{
						HWND abc = GetHWnd();
						MessageBox(abc, "��Ǹ����Ļ��Ҳ���", "��ʾ", MB_OKCANCEL);
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
//�޸��û��Ļ���
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
//��ֵ����Ϣ������ȡ����
void Get_money(int result)
{
	HWND hnd = GetHWnd();
	switch (result)
	{
	case 0:
		MessageBox(hnd, "���Ķһ������", "��ʾ", MB_OKCANCEL);
		break;
	case 1:
		MessageBox(hnd, "100���ҳ�ֵ�ɹ���", "��ʾ", MB_OKCANCEL);
		Money_increase(100);
		break;
	case 2:
		MessageBox(hnd, "300���ҳ�ֵ�ɹ���", "��ʾ", MB_OKCANCEL);
		Money_increase(300);
		break;
	case 3:
		MessageBox(hnd, "600���ҳ�ֵ�ɹ���", "��ʾ", MB_OKCANCEL);
		Money_increase(600);
		break;
	}
}
//�жϴ����û������ֵ����Ϣ
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
	printf("%s\n", "д��ɹ�");
	return flag;
}
