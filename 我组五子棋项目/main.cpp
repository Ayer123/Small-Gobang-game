#include"Game.h"

//ȫ�ֱ���
Player Me;				//���
MOUSEMSG Mouse;			//�����Ϣ
int uid;				//���uid
int mark;				//����
bool start_shooting;	//�Ƿ��Ѿ���ʼ���
bool boss_big_bul;		//��BOSS��Ψһһ�δ��ӵ�
bool boss_bul_is_black;	//��ʶ��BOSS��2��̬�ӵ���ɫ�л�
Bullet bullets[500];	//�洢���������ӵ�
Bullet Bul[8];			//����ӵ���Ϣ
Enemy enemies[50];		//�洢�������е���
Enemy Ene[11];			//�洢���ֵ��˵���Ϣ
Refresh_Enemy L;		//�ȶ��ĵ���ˢ��˳��
Object Obj[10];			//��ŵ��������Ϣ
Object objects[50];		//��ų������е�����
clock_t game_start, game_moment;//��Ϸ���̵ļ�ʱ��
int decrease_cd_times;		//��cd�ĵ��Ӵ���
int decrease_mysize_times;	//��ֱ���ĵ��Ӵ���
int increase_bul_times;		//�����ӵ��ĵ��Ӵ���
int bk_flush = -GR_Height;	//������ʼλ��
int enemy_batch;		//ÿ��������Ŀ
bool is_victory;		//boss����ʱ������ΪTRUE����Ϸʤ��
bool is_e_shoot;		//�����Ƿ�ʼ���������Ϊ��
clock_t e_shoot_start, e_shoot_moment;//���˵��ӵ�����ʱ��
clock_t start_shoot;			//�ӵ���ʱ
clock_t moment_shoot;			//�ӵ�����˲��
clock_t chao_start, chao_moment;	//BOSS�Ĵ��ӵ��ӳ�ʱ���ʱ
bool is_chao_start;				//BOSS�Ĵ��ӵ��ӳ�ʱ���Ƿ�ʼ

void Login_Page();

int main() {
	initgraph(GR_Width, GR_Height, NULL);
	cleardevice();
	Login_Page();
	return 0;
}