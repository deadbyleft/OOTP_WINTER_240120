/*

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>

#pragma comment (lib, "winmm.lib")

using namespace std;

double aaa = 0;
double bbb = 0;

int i = 0;
int j = 0;
int sim = 0; // �ڵ�, ���� ����

double tra = 1.00;

int scoreboard[2][20] = { // 13���ʹ� ���� ���. 13�� ��Ÿ��. 12��Ÿ 13���� 14Ȩ�� 15Ÿ�� 16Ÿ�� 19 [0] ������ Ʋ������
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

int op[2] = { 2,2 };


class base;
class pitcher;
class hitter;

void mode(int* sound, int* game_speed, bool* use_condition, bool* music_check, int* my_team, int* team_color);
void s_result(int i, int j, int homerun, int line, int game_speed);
void play(int gam, int* total_gam, int my_team, int sound, int game_speed, bool* music_check);
int sel(int* i, int a, int b, int c, int d);
void cur(short x, short y);
void CursorView(bool show);
int act(int pitching);
void print_hitter_record(int total_gam, int my_team, boolean br, boolean gameplay, int hitter);
void rechange_p(int total_gam, int my_team);
void gamestart();
void pixel_art(int choice, int team_color);
void music_on();
void recruit(int my_team, bool use_condition);
void draw_card(int my_team, bool use_condition);
void show_battleteam(int home, int away, int total_gam);
void draft(int my_team, bool use_condition);
void print_random(int row, int col, int count, int sleeptime);
void change(int total_gam, int my_team, boolean trade);

void cur(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView(bool show)//Ŀ�� ������
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}





class base
{
private:
	int base1 = 0;
	int base2 = 0;
	int base3 = 0;

	int speed_1 = 0; // 1������ �ӵ�
	int speed_2 = 0;
	int speed_3 = 0;

	int b = 0; // ����

	int r = 0; // ������

	friend class hitter; // �� �Ǵ°���?

public:
	base(int a, int b, int c)
	{
		base1 = a;
		base2 = b;
		base3 = c;
	}

	int base1_()
	{
		return base1;
	}
	int base2_()
	{
		return base2;
	}
	int base3_()
	{
		return base3;
	}

	void ch()
	{
		base1 = 0;
		base2 = 0;
		base3 = 0;
	}

	void go(int rb_, int* rb, float spd, int** hp) // ����
	{
		int r;

		switch (b)
		{
		case 1:
			if (base3 == 1)
			{
				base3 = 0;
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			if (base2 == 1)
			{

				base2 = 0;
				//base3 = 0;

				r = rand() % 100;
				if (speed_2 / 3 < r - 25)
				{
					base3 = 1;
					speed_3 = speed_2;
				}
				else {
					*rb += 1;
					**hp -= 10;
					scoreboard[i][j] += 1;
				}
			}
			if (base1 == 1)
			{
				base1 = 0;
				r = rand() % 100 + 1;
				if (speed_1 / 3 < r - 15)
				{
					base2 = 1;
					speed_2 = speed_1;
				}
				else if (base3 == 0)
				{
					base3 = 1;
					speed_3 = speed_1;
				}
				else base2 = 1;
			}
			base1 = 1;
			speed_1 = spd;
			break;

		case 2:
			if (base3 == 1)
			{
				base3 = 0;
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			if (base2 == 1)
			{
				base2 = 0;
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			if (base1 == 1) // �� ������ Ȩ����
			{
				base1 = 0;
				//base3 = 0;
				r = rand() % 100 + 1;
				if (speed_1 / 3 < r - 15)
				{
					base3 = 1;
					speed_3 = speed_1;
				}

				else {
					*rb += 1;
					**hp -= 10;
					scoreboard[i][j] += 1;
				}

				//*rb += 1;
				//scoreboard[i][j] += 1;
			}
			base2 = 1;
			speed_2 = spd;
			break;

		case 3:
			if (base3 == 1)
			{
				base3 = 0;
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			if (base2 == 1)
			{
				base2 = 0;
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			if (base1 == 1) // �� ������ Ȩ����
			{
				base1 = 0;
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			base3 = 1;
			speed_3 = spd;
			break;

		case 4:
			if (base3 == 1)
			{
				base3 = 0;
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			if (base2 == 1)
			{
				base2 = 0;
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			if (base1 == 1) // Ȩ��
			{
				base1 = 0;
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			*rb += 1;
			**hp -= 10;
			scoreboard[i][j] += 1;
			break;

		case 5: // ����

			if (base3 == 1 && base2 == 1 && base1 == 1)
			{
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			if (base2 == 1 && base1 == 1)
			{
				base3 = 1;
				speed_3 = speed_2;
			}
			if (base1 == 1) // �� ������ Ȩ����
			{
				base2 = 1;
				speed_2 = speed_1;
			}

			base1 = 1;
			speed_1 = spd;
			break;

		case 6: // ����

			if (base3 == 1)
			{
				r = rand() % 100 + 1;
				if (speed_3 / 3 > r - 10) {
					base3 = 0;
					*rb += 1;
					**hp -= 10;
					scoreboard[i][j] += 1;
					b = 9;
				}
			}

			break;

		case 7: // ����

			if (base3 == 1)
			{
				base3 = 0;
				*rb += 1;
				**hp -= 10;
				scoreboard[i][j] += 1;
			}
			if (base2 == 1)
			{
				base3 = 1;
				speed_3 = speed_2;
			}
			base1 = 0;
			base2 = 0;
			break;

		case 8: // ����

			if (base3 == 1)
			{
				base3 = 0;
			}
			if (base2 == 1)
			{
				base3 = 1;
				speed_3 = speed_2;
			}
			base1 = 0;
			base2 = 0;

			break;

		}
	}

	void basep()
	{
		int base = 0;

		int row = 64;
		int col = 7;

		//cout << ("[ ���� ");

		if (base1 == 0 && base2 == 0 && base3 == 0) {
			//cout << "���� ]";
			cur(row + 4, col + 1); cout << "��";
			cur(row + 2, col); cout << "��";
			cur(row, col + 1); cout << "��";
			cur(row + 2, col + 2); cout << "��";
			return;
		}

		if (base1 == 1 && base2 == 1 && base3 == 1) {
			//cout << "���� ]";
			cur(row + 4, col + 1); cout << "��";
			cur(row + 2, col); cout << "��";
			cur(row, col + 1); cout << "��";
			cur(row + 2, col + 2); cout << "��";
			return;
		}

		if (base1 == 1) {
			//cout << "1";
			base += 1;
		}


		if (base2 == 1) {
			if (base != 0) //cout << (",");
				base += 1;
			//cout << "2";
		}


		//if (base3 == 1) {
			//if (base != 0) //cout << (",");
			//cout << "3";
		//}


		//cout << "�� ]";

		cur(row + 4, col + 1);
		if (base1 == 1) cout << "��"; else cout << "��";

		cur(row + 2, col);
		if (base2 == 1) cout << "��"; else cout << "��";

		cur(row, col + 1);
		if (base3 == 1) cout << "��"; else cout << "��";

		cur(row + 2, col + 2); cout << "��";

	}

	void change_base(int i)
	{
		b = i;
	}

	int b1()
	{
		return base1;
	}

	int b2()
	{
		return base2;
	}

	int b3()
	{
		return base3;
	}

	int r_base()
	{
		return b;
	}
};


base Base(0, 0, 0);



class pitcher
{
private:
	char* name; // �̸�
	int team;
	int game;
	double era = 0;
	int kk;
	int bb;
	int con; // ����
	int stu; // ����. ball power
	float spd; // ����
	int type;
	int panta = 0; // �Ǿ�Ÿ
	int phr = 0; // ��Ȩ��
	int inn = 0; // ��ȭ �̴�. 300 = 100�̴�
	int los = 0; // ���� (��å��)
	int win = 0;
	int lose = 0;
	int hp = 0;
	int pitching = 0; // ��⿡�� ���� �� ��
	int play_game = 0; // ���� ����

	friend class hitter;
	friend class base;

public:
	pitcher(const char* myname, int team, int con, int stu, float spd, int hp) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);

		this->stu = stu;
		this->team = team;
		this->con = con;
		this->spd = spd;
		this->hp = hp;
	}

	int con_()
	{
		return con;
	}

	int stu_()
	{
		return stu;
	}

	int inn_()
	{
		return inn;
	}

	int team_()
	{
		return team;
	}

	int panta_()
	{
		return panta;
	}

	int hprint_()
	{
		return hp;
	}

	int pitching_()
	{
		return pitching;
	}

	char name_()
	{
		return *name;
	}

	void con_(int i)
	{
		con = i;
	}

	void change_kk()
	{
		kk += 1;
	}

	void change_bb()
	{
		bb += 1;
	}

	void change_los(int i)
	{
		los += i;
	}

	void change_pitching(int i)
	{
		pitching += i;
	}

	void reset_pitching()
	{
		pitching = 0;
	}

	void change_name(char* i)
	{
		name = new char[10];
		strcpy(name, i);
	}

	void change_con(int i)
	{
		int cal = i / 3;
		cal += 131;
		cal *= 10;
		con = cal;
	}

	void change_stu(int i)
	{
		int cal = i - 30;
		cal *= 30;
		cal += 500;
		stu = cal;
	}

	void change_spd(int i)
	{
		spd = i;
	}

	void change_hp(int i)
	{
		hp = i * 3;
	}

	void change_play_game()
	{
		play_game++;
	}

	void print_los()
	{
		cout.precision(2);
		cout << fixed;

		if (inn == 0) cout << "0.00";
		else cout << ((los * 27.0) / inn);
	}

	void print_pitching()
	{
		cout << pitching;
	}

	void print_con()
	{
		cout << con / 10 - 100;
	}

	void print_rspd()
	{
		cout << spd - 3 + rand() % 7 + 1 << " km";
	}

	void print_stu()
	{
		cout << stu / 10 - 100;
	}

	void print_name()
	{
		cout << name;
	}

	void print_play_game()
	{
		cout << play_game;
	}

	void pitcher_result(bool result)
	{
		if (result == true) win++;
		else lose++;
	}

	void print_winlose(int i) // ���������� ��������
	{
		//cout << left;
		if (i == 0) // ������ ����
		{
			cout.width(2);
			cout << right << win << "�� ";
			cout.width(2);
			cout << right << lose << "��";
		}
		else
		{
			if (win > 10)
				cout.width(2);
			else
				cout.width(1);
			cout << right << win << "�� ";
			cout.width(2);
			cout << right << lose << "��";
		}

	}

	void print_whip()
	{
		if (inn > 0)
			cout << ((panta + bb) / (float)inn) * 3;
		else
			cout << "0.00";
	}

	void printp(int tinn) // ���� ����
	{

		cout.precision(2);
		cout << fixed;

		if (inn != 0)	era = ((los * 27.0) / inn);

		if (tinn == 100) // �巡��Ʈ��
		{
			cout << setw(11) << name << setw(11);
			if (hprint_() < 400000) cout << "����";
			else cout << "�߰�";

			cout << setw(9) << inn / 3 << "." << inn % 3;



			cout << setw(15);

			cout.precision(2);
			cout << fixed;

			cout << era;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			cout << setw(12) << kk << setw(12) << bb << setw(10) << win << setw(9) << lose << setw(11) << phr << setw(14);

			cout << ((float)kk / inn) * 27 << setw(10)
				<< ((float)bb / inn) * 27 << setw(10) << ((panta + bb) / (float)inn) * 3
				<< '\n' << '\n';

			return;
		}

		if (tinn < 6) cout << " [ " << tinn << "���� ] ";
		else if (tinn < 8) cout << " [ " << "�߰�A ] ";
		else if (tinn < 10) cout << " [ " << "�߰�B ] ";
		else cout << "  [ " << "�ĺ� ] ";  // 10�ϰ��

		cout << setw(10) << name << setw(9) <<
			inn / 3 << "." << inn % 3;


		if (era <= 3.0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		else if (era <= 3.5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else if (era >= 5.0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

		cout << setw(13) << era;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		if ((con / 10 - 131) * 3 >= 95) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		else if ((con / 10 - 131) * 3 >= 85) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		else if ((con / 10 - 131) * 3 >= 75) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else if ((con / 10 - 131) * 3 < 60) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

		cout << setw(12) << (con / 10 - 131) * 3 << setw(10);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		if (((stu - 500) / 30 + 30) >= 95) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		else if (((stu - 500) / 30 + 30) >= 85) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		else if (((stu - 500) / 30 + 30) >= 75) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else if (((stu - 500) / 30 + 30) < 60) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

		cout << ((stu - 500) / 30 + 30) << setw(11);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << (hp / 5) * 2 - 20 << setw(11);

		if (spd >= 152) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		else if (spd >= 148) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		else if (spd >= 144) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else if (spd < 139) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

		cout << (int)spd << setw(12);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << kk
			<< setw(11) << bb << setw(9) << win << setw(10) << lose << setw(10) << phr << setw(11);

		if (inn != 0)
		{
			cout << ((float)kk / inn) * 27 << setw(10) << ((float)bb / inn) * 27 << setw(10) << ((panta + bb) / (float)inn) * 3 << setw(9);
		}

		else
		{
			cout << "0.00" << setw(10) << "0.00" << setw(10) << "0.00" << setw(9);
		}

		cout << play_game << '\n' << '\n';


		return;
	}

	int print__inn()
	{
		return inn;
	}

	int return_los()
	{
		return ((los * 27.0) / (float)inn);
	}

	int pitcher_los()
	{
		return los;
	}
};

pitcher p1("��ĳ��", 0, 1630, 1600, 150, 280); // 9��
pitcher pp("��ĳ��", 0, 1500, 1600, 150, 300); // 9��
pitcher ppp("��ĳ��", 0, 1500, 1600, 150, 300); // 9��
pitcher pppp("��ĳ��", 0, 1500, 1600, 150, 300); // 9��
pitcher home_pitcher("��ĳ��", 0, 1500, 1600, 150, 300); // ���� Ȯ�ο�
pitcher away_pitcher("��ĳ��", 0, 1500, 1600, 150, 300); // ���� Ȯ�ο�


class hitter
{
private:
	char* name; // �̸�
	int team; // �Ҽ� ��
	int pos; // ������

	int ts_ = 0; // Ÿ��
	int tasu = 0; // Ÿ��
	int anta = 0; // ��Ÿ
	int anta_2 = 0; // 2��Ÿ
	int anta_3 = 0; // 3��Ÿ
	int steal = 0; // ����
	int hr = 0; // Ȩ��
	int bb = 0; // ����
	int kk = 0; // ����
	int db = 0; // ���� (���� �÷���)
	int rb = 0; // Ÿ��
	int hit; // Ÿ��
	double chul; // �����
	int jang; // ��Ÿ��
	int ops; // OPS
	int play_game = 0; // ���� ��� ��. ������ ����
	int condition = 0;

	int condition_pow = 0; // ����ǿ� ���� �߰�, ���ҵǴ� �ɷ�ġ
	int condition_acc = 0;
	int condition_cont = 0;
	int condition_spd = 0;

	int d_tasu = 0;
	int d_anta = 0; // ������ ��Ÿ


	int cont; // ����
	int acc; // ��Ȯ
	int pow; // �Ŀ�
	float spd; // �ӵ�
	int def; // ����
	int cond; // �����
	int num; // X��Ÿ��
	int dom; // ����Ÿ��

	int today_ts_ = 0;
	int today_tasu = 0;
	int today_anta = 0;



public:
	hitter(const char* myname, int team, int pos,
		int cont, int acc, int pow, float spd, int def, int cond, int num) // 9��
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);

		this->team = team;
		this->pos = pos;
		this->cont = cont;
		this->acc = acc;
		this->pow = pow;
		this->spd = spd;
		this->def = def;
		this->num = num;

	}


	double stat(int total_gam)
	{
		int tasu_ = tasu + 1;
		double anta_ = anta;
		double bb_ = bb;
		double jang_ = jang;

		double value = ((cont - 60) + 1.2 * (acc - 50) + 0.8 * (pow - 20) + 0.2 * spd);

		double i = (anta_ / tasu_ - 0.255) * tasu;
		double j = 0.5 * ((bb + anta_) / (ts_ + 1) - 0.34) * (ts_ - tasu);
		double k = (jang_ / tasu_ - 0.36) * tasu;

		if (value + i + j + k >= 1000)
			return 999;

		else if (value + i + j + k <= 200)
			return 200;

		return value + i + j + k;



	}

	void reset_condition()
	{
		condition = rand() % 10 + 1;
	}

	void no_condition()
	{
		condition = 0;
	}

	void oprint_(int i)
	{
		if (i == 0) {
			switch (op[0]) {
			case 1:
				cont -= 40;
				acc += 25;
				break;
			case 3:
				cont += 40;
				acc -= 25;
				break;
			}
		}
		if (i == 0) {
			switch (op[1]) {
			case 1:
				pow += 150;
				cont -= 20;
				acc -= 5;
				break;
			case 3:
				pow -= 150;
				cont += 20;
				acc += 5;
				break;
			}
		}
		if (i == 1) {
			switch (op[0]) {
			case 1:
				cont += 40;
				acc -= 25;
				break;
			case 3:
				cont -= 40;
				acc += 25;
				break;
			}
		}
		if (i == 1) {
			switch (op[1]) {
			case 1:
				pow -= 150;
				cont += 20;
				acc += 5;
				break;
			case 3:
				pow += 150;
				cont -= 20;
				acc -= 5;
				break;
			}
		}
	}

	void battle(pitcher& p, int* out, int inn, int* hp, int battlecount, int game_speed, int sound) // ����� Ÿ�ڸ� ����ߴ°�?
	{
		int thr = 1; // �� X��
		int r = 0;

		int strike = 0;
		int ball = 0;

		int slp = 400;

		int rb_ = rb;

		int row = 85;
		int col = 2;

		int change_hp = *hp;

		int home_score = 0, away_score = 0;

		if (today_ts_ == 0)
		{
			play_game++;
			today_ts_++;
		}


		battlecount *= 2;
		battlecount += 19;

		if (sim == 2)
		{
			for (int i = 0; i < 9; i++)
			{

				home_score += scoreboard[0][i];
				away_score += scoreboard[1][i];
			}


			if (home_score <= away_score && scoreboard[0][19] == 1 && sound <= 2) // ����Ʈ Ʈ�� ���� �������� ��
			{
				PlaySound(NULL, NULL, NULL);
				PlaySound(TEXT("cheer.wav"), NULL, SND_ASYNC);

				scoreboard[0][19]++;
			}

			home_score = 0;
			away_score = 0;
		}


		ts_ += 1; // Ÿ��

		while (1) {

			if (sim == 2) { // �ù�

				//system("cls");

				//cur(0, 5); cout << "                                                                                                     "; // 5��° ���θ� ����

				// cur(60, 14); cout << "              ";




				cur(35, 44); cout << "[ ���� ��ŵ : Esc | Ÿ�� ��ü : Backspace | ���� ��ü : Enter ]";
				cur(35, 46); cout << "[  ���� ��ü�� �ڵ����� �̷������, ��ü�� 1���� �����մϴ�.  ]";

				cur(42, 8 + num * 2 - 2); cout << "  ";

				cur(47, 7); cout << "                                                         ";

				cur(0, 0); cout << "                                   " << '\n';



				cout << " [ " << (inn + 1) / 2 << "ȸ";
				if (inn % 2 == 1) cout << " �� ] " << '\n' << '\n' << '\n' << '\n';
				else cout << " �� ] " << '\n' << '\n' << '\n' << '\n';

				cout.precision(3);
				cout << fixed;

				switch (ppp.team) {
				case 0:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					cout << " [ �Ｚ ���̿��� ]";
					break;
				case 1:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << " [ �Ե� ���̾��� ]";
					break;
				case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
					cout << " [  NC ���̳뽺  ]";
					break;
				case 3:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
					cout << " [  �λ� ���  ]";
					break;
				case 4:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << " [   LG  Ʈ����  ]";
					break;
				case 5:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << " [   SSG ������  ]";
					break;
				case 11:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << " [ ���� �����ܽ� ]";
					break;
				case 12:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << " [ ���� Ÿ�̰��� ]";
					break;
				}

				switch (pp.team) {
				case 0:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					cout << right << setw(115) << "[ �Ｚ ���̿��� ]" << '\n' << '\n';
					break;
				case 1:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << right << setw(115) << "[ �Ե� ���̾��� ]" << '\n' << '\n';
					break;
				case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
					cout << right << setw(115) << "[  NC ���̳뽺  ]" << '\n' << '\n';
					break;
				case 3:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
					cout << right << setw(115) << "[  �λ� ���  ]" << '\n' << '\n';
					break;
				case 4:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << right << setw(115) << "[   LG  Ʈ����  ]" << '\n' << '\n';
					break;
				case 5:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << right << setw(115) << "[   SSG ������  ]" << '\n' << '\n';
					break;
				case 11:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << right << setw(115) << "[ ���� �����ܽ� ]" << '\n' << '\n';
					break;
				case 12:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << right << setw(115) << "[ ���� Ÿ�̰��� ]" << '\n' << '\n';
					break;
				}


				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				if (inn % 2 == 1) {



					if (Base.base2_() || Base.base3_()) // ��Ÿ��
					{
						if (d_tasu == 0)
							cout << "  " << num << "�� Ÿ�� : [ " << name << " ] " << " [ ������ : " << "0.000 ]  [ " << hr << " Ȩ�� ]";
						else if (hr < 10)
							cout << "  " << num << "�� Ÿ�� : [ " << name << " ] " << " [ ������ : " << (float)d_anta / (float)d_tasu << " ]   [ " << hr << " Ȩ�� ]";
						else
							cout << "  " << num << "�� Ÿ�� : [ " << name << " ] " << " [ ������ : " << (float)d_anta / (float)d_tasu << " ]  [ " << hr << " Ȩ�� ]";
					}



					else
					{
						if (tasu == 0)
							cout << "  " << num << "�� Ÿ�� : [ " << name << " ] " << " [ Ÿ�� : " << "0.000 ]  [ " << hr << " Ȩ�� ]";
						else if (hr < 10)
							cout << "  " << num << "�� Ÿ�� : [ " << name << " ] " << " [ Ÿ�� : " << (float)anta / tasu << " ]   [ " << hr << " Ȩ�� ]";
						else
							cout << "  " << num << "�� Ÿ�� : [ " << name << " ] " << " [ Ÿ�� : " << (float)anta / tasu << " ]  [ " << hr << " Ȩ�� ]";
					}




					cur(42, 8 + num * 2); cout << "��";
				}

				else {
					cout.precision(2);
					cout << fixed;

					if (p.inn_() != 0) {
						cout << " " << " ���� ���� : [ " << p.name << " ]";

						cout << " [ �����å�� :  "; p.print_los();  cout << "  ] " << '\n' << '\n';


					}
					else
						cout << " " << " ���� ���� : [ " << p.name << " ] [ �����å�� : " << " 0.00 " << " ] " << '\n' << '\n';

					cur(90, 8 + num * 2); cout << "��";
				}



				cur(25, 5); cout << ("����������������������������������������������������������������������������������������������������������������������������������������������������������  ");

				cur(60, 5); Base.basep(); cur(74, 7); // ���� X��


				if (inn % 2 == 1) {
					cout.precision(2);
					cout << fixed;

					if (p.inn_() != 0) {

						if (p.return_los() >= 100)
						{
							cout << right << setw(27) << fixed << " ���� ���� : [ " << p.name << " ] [ �����å�� : ";
							p.print_los();  cout << " ] " << '\n' << '\n';
						}

						else if (p.return_los() >= 10)
						{
							cout << right << setw(27) << fixed << " ���� ���� : [ " << p.name << " ] [ �����å�� : ";
							p.print_los();  cout << "  ] " << '\n' << '\n';
						}

						else
						{
							cout << right << setw(27) << fixed << " ���� ���� : [ " << p.name << " ] [ �����å�� :  ";
							p.print_los();  cout << "  ] " << '\n' << '\n';
						}



					}
					else
						cout << right << setw(27) << fixed << " ���� ���� : [ " << p.name << " ] [ �����å�� : " << " 0.00 " << " ] " << '\n' << '\n';
				}

				else {

					cur(74, 7);

					cout.precision(3);
					cout << fixed;


					if (Base.base2_() || Base.base3_())
					{
						cur(72, 7);

						if (d_tasu == 0)
							cout << right << setw(9) << fixed << num << "�� Ÿ�� : [ " << name << " ] " << " [ ������ : " << "0.000 ]  [ " << hr << " Ȩ�� ]";
						else if (hr < 10)
							cout << right << setw(9) << fixed << num << "�� Ÿ�� : [ " << name << " ] " << " [ ������ : " << (float)d_anta / (float)d_tasu << " ]  [ " << hr << " Ȩ�� ]";
						else
							cout << right << setw(8) << fixed << num << "�� Ÿ�� : [ " << name << " ] " << " [ ������ : " << (float)d_anta / (float)d_tasu << " ]  [ " << hr << " Ȩ�� ]";
					}

					else
					{
						if (tasu == 0)
							cout << right << setw(9) << fixed << num << "�� Ÿ�� : [ " << name << " ] " << " [ Ÿ�� : " << "0.000 ]  [ " << hr << " Ȩ�� ]";
						else if (hr < 10)
							cout << right << setw(9) << fixed << num << "�� Ÿ�� : [ " << name << " ] " << " [ Ÿ�� : " << (float)anta / tasu << " ]  [ " << hr << " Ȩ�� ]";
						else
							cout << right << setw(8) << fixed << num << "�� Ÿ�� : [ " << name << " ] " << " [ Ÿ�� : " << (float)anta / tasu << " ]  [ " << hr << " Ȩ�� ]";
					}



				}



				cur(46, battlecount); cout << right << setw(3) << fixed << num << ". [ " << name << " ] ";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cur(row, col);
				cout << "  S ";
				switch (strike) {
				case 0:
					cout << " �� ��" << '\n'; break;
				case 1:
					cout << " �� ��" << '\n'; break;
				case 2:
					cout << " �� ��" << '\n'; break;
				}



				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cur(row, col + 1);
				cout << "  B ";
				switch (ball) {
				case 0:
					cout << " �� �� ��" << '\n'; break;
				case 1:
					cout << " �� �� ��" << '\n'; break;
				case 2:
					cout << " �� �� ��" << '\n'; break;
				case 3:
					cout << " �� �� ��" << '\n'; break;
				}


				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cur(row, col + 2);
				cout << "  O ";
				switch (*out) {
				case 0:
					cout << " �� ��" << '\n'; break;
				case 1:
					cout << " �� ��" << '\n'; break;
				case 2:
					cout << " �� ��" << '\n'; break;
				}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				if (inn % 2 == 1 && team == ppp.team) oprint_(1);

				cur(46, 14);
				cout << "                  �� = " << p.pitching_() + thr - 1;

				switch (game_speed)
				{
				case 5: Sleep(600); break;
				}

				if (thr == 1)
				{
					switch (game_speed)
					{
					case 3: Sleep(800); break;
					case 4: Sleep(1000); break;
					}

					//cur(45, 19); cout << "                                ";
					for (int i = 0; i < 14; i++) {
						act(p.pitching_() + thr);

						//Sleep(10);

					}
				}

				if (act(p.pitching_() + thr) == 27) sim = 3; // ��ŵ

				if (inn % 2 == 1 && team == ppp.team) oprint_(0);



				cur(17, 1); cout << "     ";  // �̰� ��� ����
				//if (thr > 9) {
				//	cur(57, battlecount); cout << " �� " << thr << "��";
				//}
				//else {
				//	cur(57, battlecount); cout << " �� " << thr << " ��";
				//}

			}


			aaa += 1;

			r = rand() % p.con + 1;

			if (inn % 2 == 1 && team == ppp.team) oprint_(0);

			if (r > 1100 + cont)
			{
				//cout << " ��Ʈ����ũ" << '\n';

				strike += 1;

				if (strike == 3) { //��Ʈ 3

					today_tasu++;

					if (sim == 2)
					{
						p.change_pitching(thr);
					}


					if (Base.b2() || Base.b3())
					{
						d_tasu += 1;
					}
					if (sim == 2) {
						s_result(4, p.spd, 0, battlecount, game_speed);

					}
					*hp -= 2;
					p.change_kk();
					kk += 1;
					tasu += 1;
					if (*out != 3) *out += 1;
					p.inn += 1;
					if (inn % 2 == 1 && team == ppp.team) oprint_(1);

					if (inn % 2 == 1) {
						scoreboard[0][17] += 1;
						scoreboard[0][16] += 1;
					}

					else {
						scoreboard[1][17] += 1;
						scoreboard[1][16] += 1;
					}

					break;
				}
			}



			else if (r < 400 + cont) //��. ���� ������ ��ƮȮ�� ��
			{


				r = rand() % p.con + 1;
				//cout << cont << "        " << acc << "           " << r << '\n';
				ball += 1;

				if (ball == 4) { //�� 4

					if (sim == 2)
					{
						p.change_pitching(thr);
						s_result(5, p.spd, 0, battlecount, game_speed);
					}

					Base.change_base(5);
					p.change_bb();
					*hp -= 10;
					bb += 1;
					if (inn % 2 == 1) scoreboard[0][18] += 1;
					else scoreboard[1][18] += 1;
					//if (sim == 2) cout << "����" << '\n';
					if (inn % 2 == 1 && team == ppp.team) oprint_(1);
					if (inn % 2 == 1) {
						scoreboard[0][16] += 1;
					}

					else {
						scoreboard[1][16] += 1;
					}

					break;
				}
			}



			else
			{


				bh(p.con_(), acc, spd, &strike, &out, &jang, p.stu_(), inn, &hp, battlecount, game_speed, sound);

				//tasu += 1;
				//anta += 1;
				//break;
				if (strike == 4) { // ��Ÿ�� ��

					today_tasu++;
					today_anta++;

					if (sim == 2)
					{
						p.change_pitching(thr);
					}

					if (Base.b2() || Base.b3())
					{
						d_tasu += 1;
					}
					if (inn % 2 == 1 && team == ppp.team) oprint_(1);
					tasu += 1;
					strike = 0;
					if (inn % 2 == 1) scoreboard[0][12] += 1;
					else scoreboard[1][12] += 1;

					if (inn % 2 == 1) {
						scoreboard[0][17] += 1;
						scoreboard[0][16] += 1;
					}

					else {
						scoreboard[1][17] += 1;
						scoreboard[1][16] += 1;
					}
					break;
				}
				else  if (strike == 5) { // �ƿ��� ��

					today_tasu++;

					if (sim == 2)
					{
						p.change_pitching(thr);
					}

					if (Base.b2() || Base.b3())
					{
						d_tasu += 1;
					}
					if (*out != 2)
					{
						Base.change_base(6);
					}

					*hp -= 2;
					p.inn += 1;
					*out += 1;
					tasu += 1;
					if (inn % 2 == 1 && team == ppp.team) oprint_(1);
					if (inn % 2 == 1) {
						scoreboard[0][17] += 1;
						scoreboard[0][16] += 1;
					}

					else {
						scoreboard[1][17] += 1;
						scoreboard[1][16] += 1;
					}
					break;
				}

				else if (strike == 6) { // ������ ��

					today_tasu++;

					if (sim == 2)
					{
						p.change_pitching(thr);
					}

					if (Base.b2() || Base.b3())
					{
						d_tasu += 1;
					}
					db += 1;
					*hp -= 2;
					if (*out == 0) Base.change_base(7);
					else if (*out == 1) Base.change_base(8);
					p.inn += 2;
					*out += 2;
					tasu += 1;

					if (inn % 2 == 1 && team == ppp.team) oprint_(1);
					if (inn % 2 == 1) {
						scoreboard[0][17] += 1;
						scoreboard[0][16] += 1;
					}

					else {
						scoreboard[1][17] += 1;
						scoreboard[1][16] += 1;
					}
					break;
				}
			}

			if (inn % 2 == 1 && team == ppp.team) oprint_(1);

			thr += 1;
			*hp -= 2;




		}




		if (sim == 2) {
			cur(42, 8 + num * 2);
			cout << "  ";
		}


		Base.go(rb, &rb, spd, &hp);
		if (Base.r_base() == 9)
		{
			today_tasu--;
			tasu--; // ������ Ÿ���� ���� �ʴ´�.
		}


		p.change_los(rb - rb_);



		if (sim == 2)
		{
			home_score = 0;
			away_score = 0;

			for (int i = 0; i < 9; i++)
			{

				home_score += scoreboard[0][i];
				away_score += scoreboard[1][i];
			}


			if (home_score > away_score && scoreboard[0][19] == 1 && inn % 2 == 1 && game_speed >= 3 && sound == 1 && inn > 8)
			{
				PlaySound(NULL, NULL, NULL);
				PlaySound(TEXT("apartment.wav"), NULL, SND_ASYNC);
				scoreboard[0][19]++;
			}
		}

		bbb += 1;

	}

	void bo(pitcher& p, int* out, // ��Ÿ ����
		int** jang, int*** hp, int* inn, int battlecount, int game_speed, int sound) // ��Ÿ�� � ��Ÿ����
	{
		int r = rand() % p.stu_() + 1;
		int home_score = 0, away_score = 0;

		p.panta += 1;

		// ���� �󸶳� ������ jang���� ����
		// �� ���� ���߿� return���� ����

		if (r > 300 + pow * 2) // ��Ÿ, ���ǵ������
			// 1,2�� ���� �ִٸ� 2���̽���
		{
			//if (sim == 2) cout << " ��Ÿ" << '\n';
			if (sim == 2) {
				s_result(1, p.spd, 0, battlecount, game_speed);
			}
			Base.change_base(1);
			**jang += 1;
			*hp -= 8;
			return;
		}

		else if (rand() % p.stu_() + 1 > 50 + pow * 4) // ��Ÿ, ���ǵ������
			// 1,2�� ���� �ִٸ� 2���̽���
		{
			r = rand() % p.stu_() + 1;
			//cout << " ��Ÿ" << '\n';
			if (r < spd * 2.5 - 70) { // ������ 3��Ÿ
				if (sim == 2) {
					s_result(3, p.spd, 0, battlecount, game_speed);
				}
				//if (sim == 2) cout << " 3��Ÿ" << '\n';
				Base.change_base(3);
				**jang += 3;
				anta_3 += 1;
				*hp -= 16;

				if (*inn % 2 == 1) scoreboard[0][14] += 1;
				else scoreboard[1][14] += 1;

				return;
			}
			else { // ������ 2��Ÿ
				//if (sim == 2) cout << " 2��Ÿ" << '\n';
				if (sim == 2) {
					s_result(2, p.spd, 0, battlecount, game_speed);
				}
				Base.change_base(2);
				**jang += 2;
				anta_2 += 1;
				*hp -= 12;

				if (*inn % 2 == 1) scoreboard[0][13] += 1;
				else scoreboard[1][13] += 1;

				return;
			}
		}


		else // Ȩ��
		{
			p.phr += 1;
			Base.change_base(4);
			hr += 1;
			**jang += 4;
			if (sim == 2) {
				s_result(0, p.spd, hr, battlecount, game_speed);
			}
			//if (sim == 2) cout << " Ȩ��" << '\n';
			*hp -= 25;

			if (*inn % 2 == 1) scoreboard[0][15] += 1;
			else scoreboard[1][15] += 1;


			if (sim == 2 && *inn > 8 && *inn % 2 == 1) // Ȩ���� 5ȸ �� ���Ŀ� Ȩ�� �� �������϶�
				scoreboard[0][19]++; // ���� 1ȸ�� ����Ʈ ���




			return;
		}

		//else if (r > 650) // ����, ���쵵
		//{
			//cout << "��Ʈ����ũ" << '\n';
			//out += 1;
			//return;
		//}

		//else if (r > 200) // ���, ���õ�
		//{
			//cout << "���" << '\n';
		out += 1;
		r = rand() % p.con + 1;
		//if (r > 200 + acc && out !=2 && base3==1)
		//	cout << "����" << '\n';
		//return;
	//}

	}

	void bj(pitcher& p, int* out, // �ƿ� ����
		int* jang) // ��Ÿ�� � ��Ÿ����
	{
		int r = rand() % p.con + 1;

		// ���� �󸶳� ������ jang���� ����
		// �� ���� ���߿� return���� ����

		if (r > 1150) // ��Ÿ, ���ǵ������
			// 1,2�� ���� �ִٸ� 2���̽���
		{
			//if (sim == 2) cout << "��Ÿ" << '\n';
			jang += 1;
			return;
		}

		else if (r > 650 + pow) // ����, ���쵵
		{
			//if (sim == 2) cout << "��Ʈ����ũ" << '\n';
			out += 1;
			return;
		}

		else if (r > 200 + pow) // ���, ���õ�
		{
			if (sim == 2) cout << " [ ��� ]" << '\n';
			out += 1;
			r = rand() % p.con + 1;
			//if (r > 200 + acc && out !=2 && base3==1)
			//	cout << "����" << '\n';
			return;
		}

	}

	void bh(int p, int acc, float spd, int* strike, int** out,
		int* jang, int phr, int inn, int** hp, int battlecount, int game_speed, int sound) // Ÿ�� ����� ��������
	{

		int r = rand() % p + 1;


		if (r < acc - 5) // ��Ÿ
		{
			//cout << "��Ÿ" << '\n';
			//jang = 1;

			if (inn % 2 == 1) bo(pp, *out, &jang, &hp, &inn, battlecount, game_speed, sound);
			else bo(ppp, *out, &jang, &hp, &inn, battlecount, game_speed, sound);

			anta += 1;
			if (Base.b2() || Base.b3())
			{
				d_anta += 1;
			}
			*strike = 4;
			return;
		}

		else if ((r > 1380 + (rand() % (int)spd + 1) + spd * 0.7) && **out != 2 && Base.b1() == 1) // ����
		{
			if (sim == 2) {
				if (inn % 2 == 1) s_result(7, pp.spd, 0, battlecount, game_speed);
				else  s_result(7, ppp.spd, 0, battlecount, game_speed);
			}

			//tasu += 1; �� ������ �߻��ϴ°���?
			//if (sim == 2) cout << " �ƿ�" << '\n';
			*strike = 6;

			return;
		}

		else if (r > 1140) // �ƿ�
		{
			if (sim == 2) {
				if (inn % 2 == 1) s_result(6, pp.spd, 0, battlecount, game_speed);
				else  s_result(6, ppp.spd, 0, battlecount, game_speed);
			}
			//tasu += 1; �� ������ �߻��ϴ°���?
			//if (sim == 2) cout << " �ƿ�" << '\n';
			*strike = 5;

			return;
		}

		else // �Ŀ�
		{
			//if (sim == 2) cout << " �Ŀ�" << '\n';
			//jang = 4;
			if (*strike != 2) *strike += 1;
			return;
		}
	}


	float anta_()
	{
		return anta;
	}

	int tasu_()
	{
		return tasu;
	}

	int ts__()
	{
		return ts_;
	}

	int bb_()
	{
		return bb;
	}

	int hr_()
	{
		return hr;
	}

	int num_()
	{
		return num;
	}

	int pos_()
	{
		return pos;
	}

	void change_pos_(int i)
	{
		pos = i;
	}

	int dom_()
	{
		return dom;
	}

	void cn_(int i)
	{
		num = i;
	}

	void print_name()
	{
		cout << name << '\n' << '\n';
	}

	int team_()
	{
		return team;
	}


	void print_play_game()
	{
		cout << play_game;
	}

	void print_cont()
	{
		if (cont >= 210) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		else if (cont >= 180) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else if (cont < 140) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

		cout << cont / 2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}

	void print_acc()
	{
		if (acc >= 260) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		else if (acc >= 220) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else if (acc < 180) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

		cout << acc / 2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}

	void print_pow()
	{
		if (pow >= 130) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		else if (pow >= 100) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else if (pow < 40) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

		cout << pow / 2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}

	void print_spd()
	{
		if (spd >= 140) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		else if (spd >= 100) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else if (spd < 50) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

		cout << (int)spd / 2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		//cout << '\n' << '\n'; // ����.
	}

	//20_�Ｚ 21_�Ե� 22_NC 23_�λ� 24_LG 25_SSG
	//26_Ű�� 27_kt 28_��ȭ 29_KIA
	//30_���� 31_�ֹ�� 32_����� 33_��� 34_���� 35_OB 36_û�� 37_���׷� 38_û��
	void draw_print_team() // ���� �̱⶧�� ���
	{
		switch (team)
		{
		case 20:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << " [ �Ｚ ���̿��� ]";
			break;

		case 21:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << " [ �Ե� ���̾��� ]";
			break;

		case 22:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			cout << " [  NC  ���̳뽺 ]";
			break;

		case 23:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			cout << " [  �λ� ���  ]";
			break;

		case 24:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << " [   LG Ʈ����   ]";
			break;

		case 25:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << " [  SSG  ������  ]";
			break;

		case 26:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << " [ Ű�� ������� ]";
			break;

		case 27:
			cout << " [    KT ����    ]";
			break;

		case 28:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout << " [  ��ȭ �̱۽�  ]";
			break;

		case 29:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << " [ KIA  Ÿ�̰��� ]";
			break;

		case 30:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << " [ ���� �����ܽ� ]";
			break;

		case 31:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << " [�ֹ�� ���̴���]";
			break;

		case 32:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << " [ ����� ���ɽ� ]";
			break;

		case 33:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << " [��� "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << "���۽�Ÿ��]";
			break;

		case 34:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << " [ ���� Ÿ�̰��� ]";
			break;

		case 35:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			cout << " [  OB   ���  ]";
			break;

		case 36:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << " [  û�� ���佺  ]";
			break;

		case 37:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout << " [ ���׷� �̱۽� ]";
			break;

		case 38:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << " [   MBC    û��   ]";
			break;

		case 39:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << " [  SK ���̹���  ]";
			break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}

	void draw_hitter(int row, int col, boolean use_condition)
	{
		print_pos(); Sleep(2000);  col += 3; cur(row + 7, col);
		draw_print_team(); Sleep(2000);  col += 3; cur(row + 11, col);
		print_name(); cur(row + 17, col);
		cout << " ȹ��! "; col += 3; cur(row + 7, col);
		cout << " ���� : "; print_cont(); col += 2; cur(row + 7, col);
		cout << " ��Ȯ : "; print_acc(); col += 2; cur(row + 7, col);
		cout << " �Ŀ� : "; print_pow(); col += 2; cur(row + 7, col);
		cout << " �ӵ� : "; print_spd(); col += 2; cur(row, col + 1);
		cout << " ������ : "; print_ov(); col += 3; cur(row, col + 1); system("pause");
		if (use_condition == true) reset_condition();
	}

	void print_condition()
	{


		switch (condition)
		{
		case 0:
			cout << "[ ���� ]";
			break;
		case 1:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "[ �ֻ� ]";
			break;
		case 2: case 3:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "[ ���� ]";
			break;
		case 4: case 5: case 6: case 7:
			cout << "[ ���� ]";
			break;
		case 8: case 9:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			cout << "[ ���� ]";
			break;
		case 10:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			cout << "[ �־� ]";
			break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}

	void print_ov()
	{
		double ov_basic = 0.8 * (cont - 60) + 1.2 * (acc - 50) + 0.8 * (pow - 20) + 0.3 * spd;
		double ov = ov_basic * 0.22 - 5;

		if (ov >= 90) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		else if (ov >= 80) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		else if (ov >= 70) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		else if (ov < 60) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

		cout << (int)ov;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		//cout << '\n' << '\n'; // ����.
	}

	void print_pos()
	{


		if (pos == 2) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			if (dom == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "����";
		}

		else if (pos == 3 || pos == 5) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			if (dom == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

			if (pos == 3)
				cout << "1���";
			else
				cout << "3���";
		}

		else if (pos == 4 || pos == 6) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			if (dom == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

			if (pos == 4)
				cout << "2���";
			else
				cout << "���ݼ�";
		}

		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			if (dom == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

			if (pos == 7)
				cout << "���ͼ�";
			else if (pos == 8)
				cout << "�߰߼�";
			else
				cout << "���ͼ�";

		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}

	void clear_today()
	{
		today_ts_ = 0;
		today_tasu = 0;
		today_anta = 0;
	}

	void clear_schoolscore()
	{
		d_tasu = 0;
		d_anta = 0;
		play_game = 0;
	}

	void change_dom(int i)
	{
		dom = i;
	}

	void change_play_game()
	{
		play_game++;
	}

	void change_name(char* i)
	{
		name = new char[10];
		strcpy(name, i);
	}

	void change_pow(int i)
	{
		pow = i * 2;
	}

	void change_cont(int i)
	{
		cont = i * 2;
	}

	void change_acc(int i)
	{
		acc = i * 2;
	}

	void change_spd(int i)
	{
		spd = i * 2;
	}

	void change_pos(int i)
	{
		pos = i;
	}

	void change_ov()
	{
		int random = rand() % 3 + 0; random *= 10;

		pow -= 10; pow += random; random = rand() % 3 + 0; random *= 10;
		cont -= 10; cont += random; random = rand() % 3 + 0; random *= 10;
		acc -= 10; acc += random; random = rand() % 3 + 0; random *= 10;
		spd -= 10; spd += random;
	}

	void correct_condition()
	{
		condition_pow = pow * 0.1;
		condition_cont = cont * 0.1;
		condition_acc = acc * 0.1;
		condition_spd = spd * 0.1;

		if (condition == 1 || condition == 10)
		{
			condition_pow *= 2;
			condition_cont *= 2;
			condition_acc *= 2;
			condition_spd *= 2;
		}

		if (condition <= 3 && condition > 0)
		{
			pow += condition_pow;
			cont += condition_cont;
			acc += condition_acc;
			spd += condition_spd;
		}

		else if (condition >= 8)
		{
			pow -= condition_pow;
			cont -= condition_cont;
			acc -= condition_acc;
			spd -= condition_spd;
		}


	}

	void restore_condition(boolean play)
	{
		if (condition >= 8)
		{
			pow += condition_pow;
			cont += condition_cont;
			acc += condition_acc;
			spd += condition_spd;
		}

		else if (condition <= 3 && condition > 0)
		{
			pow -= condition_pow;
			cont -= condition_cont;
			acc -= condition_acc;
			spd -= condition_spd;
		}

		if (condition > 0 && play == false) // ���� �� ��ü�϶��� ������� �ٲ�� �� ��
			condition = rand() % 10 + 1;
	}

	void print(int total_gam, int i)
	{
		cout.precision(3);
		cout << fixed;

		if (i != 5 && i != 10) { // 10 = �巡��Ʈ

			if (num <= 9)
				cout << "   [ " << num << "��Ÿ�� ] ";
			else
				cout << "    [  �ĺ�  ] ";
		}

		if (i == 1) {

			cout << setw(8) << name << setw(11);



			print_pos();

			if (tasu != 0) {

				cout << setw(11) <<
					((float)anta / tasu) << setw(12) << (((float)anta + (float)bb) / ts_) << setw(12) <<
					((float)jang / tasu);

			}

			else {
				cout << setw(11) <<
					"0.000" << setw(12) << "0.000" << setw(12) <<
					"0.000";
			}

			cout << setw(14);
			print_condition();

			if ((3.1 * total_gam) <= ts_ + 0.99) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << setw(10) << ts_;
			if ((3.1 * total_gam) <= ts_ + 0.99) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << setw(10) << tasu << setw(10) << anta << setw(11) << hr << setw(11);

			cout.precision(1);
			cout << fixed;
			cout << stat(total_gam);



			cout.precision(3);
			cout << fixed;

			cout << '\n' << '\n';

		}

		else if (i == 2) {

			cout << setw(8) << name << setw(11);
			print_pos();

			cout << setw(10) << kk << setw(10) << bb << setw(10) << anta;
			cout << setw(11) << anta_2 << setw(11) << anta_3 << setw(10) << hr << setw(10) << rb << setw(10) << db << setw(12);

			if (tasu != 0)
			{
				if (((float)d_anta / (float)d_tasu) >= 0.33)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				else if (((float)d_anta / (float)d_tasu) >= 0.3)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				else if (((float)d_anta / (float)d_tasu) < 0.2)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				else if (((float)d_anta / (float)d_tasu) < 0.23)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);


				if (d_tasu == 0) cout << (float)d_tasu;
				else cout << (float)d_anta / (float)d_tasu;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else {
				cout << "0.000";
			}


			cout << '\n' << '\n';
		}

		else if (i == 3) {
			cout << setw(8) << name << setw(11);
			print_pos();
			cout << setw(10);
			print_cont(); cout << setw(12);
			print_acc(); cout << setw(12);
			print_pow(); cout << setw(12);
			print_spd(); cout << setw(14);
			print_condition(); cout << setw(9);
			print_play_game(); cout << setw(11);

			print_ov();

			if (ts_ != 0)
			{
				if ((((float)anta + (float)bb) / ts_) + ((float)jang / tasu) > 0.9)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				else if ((((float)anta + (float)bb) / ts_) + ((float)jang / tasu) > 0.8)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				else if ((((float)anta + (float)bb) / ts_) + ((float)jang / tasu) < 0.6)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				else if ((((float)anta + (float)bb) / ts_) + ((float)jang / tasu) < 0.65)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

				if (tasu == 0) cout << setw(14) << (((float)anta + (float)bb) / ts_);
				else cout << setw(14) << (((float)anta + (float)bb) / ts_) + ((float)jang / tasu);



				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
				cout << setw(14) << "0.000";



			cout << '\n' << '\n';
		}

		else if (i == 4) {
			cout << name << setw(3);



			switch (condition)
			{
			case 0: cout << ""; break;
			case 1: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cout << "��"; break;
			case 2: case 3: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cout << "��"; break;
			case 8: case 9: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); cout << "��"; break;
			case 10: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); cout << "��"; break;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			if (condition <= 3 || condition >= 8)
				cout << setw(7);
			else
				cout << setw(9);



			print_pos(); cout << setw(8);

			if (tasu != 0) {
				cout << ((float)anta / tasu) << '\n' << '\n';
			}

			else {
				cout << "0.000" << '\n' << '\n';
			}


			//cout << name << setw(11); // ����� ��� ���Ҷ� �� �ڵ� ���
			//print_pos(); cout << setw(8);

			//if (tasu != 0) {
				//cout << ((float)anta / tasu) << '\n' << '\n';
			//}

			//else {
				//cout << "0.000" << '\n' << '\n';
			//}
		}

		else if (i == 5) {

			if (tasu != 0) {
				cout << ((float)anta / tasu) << setw(8);
			}

			else {
				cout << "0.000" << setw(8);
			}




			print_pos();

			cout << setw(11) << name;

			if (num <= 9)
				cout << setw(11) << "[ " << num << "��Ÿ�� ] ";
			else
				cout << setw(11) << " [  �ĺ�  ] ";


		}

		else if (i == 6) {

			cout << setw(8) << name << setw(11);
			print_pos();
			cout << setw(10);
			print_cont(); cout << setw(12);
			print_acc(); cout << setw(12);
			print_pow(); cout << setw(12);
			print_spd(); cout << setw(14);
			print_condition();

			if (tasu != 0)
				cout << setw(12) << (float)anta / tasu;
			else
				cout << setw(12) << "0.000";

			if (ts_ != 0)
				cout << setw(12) << (((float)anta + (float)bb) / ts_);
			else
				cout << setw(12) << "0.000";

			if (tasu != 0)
				cout << setw(12) << ((float)jang / tasu);
			else
				cout << setw(12) << "0.000";

			if (ts_ != 0 && tasu == 0)
				cout << setw(11) << (((float)anta + (float)bb) / ts_);
			else if (tasu != 0)
				cout << setw(11) << ((float)jang / tasu) + (((float)anta + (float)bb) / ts_);
			else
				cout << setw(11) << "0.000";

			if (((float)d_anta / (float)d_tasu) >= 0.33)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			else if (((float)d_anta / (float)d_tasu) >= 0.3)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			else if (((float)d_anta / (float)d_tasu) < 0.2)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			else if (((float)d_anta / (float)d_tasu) < 0.23)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

			if (d_tasu != 0)
				cout << setw(12) << (float)d_anta / d_tasu;
			else
				cout << setw(12) << "0.000";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


			if (today_tasu >= 3 && today_anta == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			else if (today_tasu >= 3 && today_anta == today_tasu) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			else if (today_tasu >= 3 && today_anta / (float)today_tasu >= 0.6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

			cout << setw(9) << today_anta; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			cout << "  /  ";

			if (today_tasu >= 3 && today_anta == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			else if (today_tasu >= 3 && today_anta == today_tasu) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			else if (today_tasu >= 3 && today_anta / (float)today_tasu >= 0.6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << today_tasu; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


			cout << '\n' << '\n';
		}

		else if (i == 10) {

			cout << setw(10) << name << setw(11);
			print_pos();

			if (tasu != 0) {

				cout << setw(11) <<
					((float)anta / tasu) << setw(12) << (((float)anta + (float)bb) / ts_) << setw(12) <<
					((float)jang / tasu);

			}

			//if ((3.1*total_gam) <= ts_ + 0.99) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			//cout << setw(10) << ts_;
			cout << setw(10) << tasu << setw(10) << anta << setw(10) << hr << setw(10) << bb << setw(10) << kk
				<< setw(11) << anta_2 << setw(11) << anta_3;

			cout << '\n' << '\n';

		}

	}

	void re()
	{
		ts_ = 0; // Ÿ��
		tasu = 0; // Ÿ��
		anta = 0; // ��Ÿ
		anta_2 = 0; // 2��Ÿ
		anta_3 = 0; // 3��Ÿ
		steal = 0; // ����
		hr = 0; // Ȩ��
		bb = 0; // ����
		kk = 0; // ����
		db = 0; // ���� (���� �÷���)
		rb = 0; // Ÿ��
		jang = 0;
	}

};



class team
{
private:
	char* name;
	int tn; // �� �Ҽ�
	int win;
	int draw;
	int lose;
	int bb;
	int era;
	int chu;
	int anta;
	int anta_2 = 0;
	int anta_3 = 0;
	int hr;
	int tasu;
	int ts;
	int jang = 0;
	int get; // ��� ����
	int lost; // ��� ����
	int l_game = -1; // ���� ��� ���
	int ll_game = -1; // ������ ��� ���
	int streak = 0; // ����,����

	int recent[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

	friend class result;

public:
	team(const char* myname, int tn, int win, int draw, int lose, int hr, int bb, int era,
		int chu, int anta, int tasu, int ts, int get, int lost)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		this->tn = tn;
		this->win = win;
		this->draw = draw;
		this->lose = lose;
		this->hr = hr;
		this->bb = bb;
		this->era = era;
		this->chu = chu;
		this->anta = anta;
		this->tasu = tasu;
		this->ts = ts;
		this->get = get;
		this->lose = lose;
	}

public:

	void s_recent()
	{
		int win = 0, draw = 0, lose = 0;

		for (int i = 0; i < 10; i++)
		{
			if (recent[i] == 0)
				win += 1;
			else if (recent[i] == 1)
				draw += 1;
			else if (recent[i] == 2)
				lose += 1;
			else
				break;
		}

		cout << win << "��-" << lose << "��-" << draw << "��";

	}

	void s_streak()
	{


		if (l_game <= 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << streak << "��";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}

		else if (l_game == 1)
			cout << streak << "��";
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << streak << "��";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}



	}

	int tn_()
	{
		return tn;
	}

	void res(int i) // ���, �ֱٰ�� �� ���� ���� �Ǵ�
	{
		l_game = i; // ���� �Ǵܿ�

		if (i == 0) win += 1;
		else if (i == 1) draw += 1;
		else if (i == 2) lose += 1;

		recent[((win + lose + draw - 1) % 10)] = i;

		if (l_game == ll_game)
			streak++;
		else
			streak = 1;

		ll_game = l_game;

	}

	void s_res()
	{
		cout.precision(1);
		cout << fixed;
		cout << setw(7);

		if (win == 0 && lose == 0 && draw > 0)
		{
			cout << win + lose + draw; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << setw(11) << win; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << setw(11) << lose; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << setw(11) << draw << setw(8) << " ";
			cout << "0.0 %        ";
		}

		else if (win == 0 && lose == 0) {
			cout << win + lose + draw;

			cout << setw(11);
			cout << win;
			cout << setw(11) << lose;
			cout << setw(11) << draw << setw(10) << " ";
			cout << "0.0 %      ";
		}

		else {
			cout << win + lose + draw; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << setw(11) << win; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << setw(11) << lose; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << setw(11) << draw << setw(11) << (float)win / (float)(win + lose) * 100 << " %        ";
		}

	}

	double s__res()
	{
		if (win == 0 && lose == 0 && draw > 0)
			return 0.1;
		else
			return (float)win / (float)(win + lose) * 100;

	}



	void result(int i)
	{
		anta += scoreboard[i][12];
		anta_2 += scoreboard[i][13];
		anta_3 += scoreboard[i][14];
		hr += scoreboard[i][15];

		ts += scoreboard[i][16];
		tasu += scoreboard[i][17];
		bb += scoreboard[i][18];

	}

	void show_hr()
	{
		cout << hr;
	}

	void s_bb()
	{
		cout << bb;
	}


	void show_hit(int i)
	{
		if (i == 0)
		{
			if (tasu != 0)
				cout << (anta / (float)tasu);
			else
				cout << "0.000";
		}

		else if (i == 2)
		{
			cout << (anta / (float)tasu);
		}

		else
		{
			jang = anta + anta_2 + (anta_3 * 2) + (hr * 3);

			if ((anta / (float)tasu) >= 0.29) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			else if ((anta / (float)tasu) >= 0.28) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			else if ((anta / (float)tasu) < 0.24) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			else if ((anta / (float)tasu) < 0.25) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

			cout << (anta / (float)tasu);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			cout << "        ";

			if ((bb + anta) / (float)ts >= 0.38) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			else if ((bb + anta) / (float)ts >= 0.37) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			else if ((bb + anta) / (float)ts < 0.3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			else if ((bb + anta) / (float)ts < 0.34) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

			cout << ((bb + anta) / (float)ts);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			cout << "         ";

			if (jang / (float)tasu >= 0.44) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			else if (jang / (float)tasu >= 0.42) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			else if (jang / (float)tasu < 0.36) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			else if (jang / (float)tasu < 0.38) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

			cout << (jang / (float)tasu);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);



		}
	}


	void show_get()
	{
		if (win + lose + draw == 0)	cout << "0.00";

		else {
			cout << fixed;
			cout.precision(2);
			cout << (float)get / (win + lose + draw);
		}

	}

	void show_lost()
	{
		if (win + lose + draw == 0)	cout << "0.00";

		else {
			cout << fixed;
			cout.precision(2);
			cout << (float)lost / (win + lose + draw);
		}
	}

	void change_get(int i)
	{
		get += i;
	}

	void change_lost(int i)
	{
		lost += i;
	}

};

class result
{
private:
	char* date;
	friend class team;
};



team samsung("�Ｚ ���̿���", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
team lotte("�Ե� ���̾���", 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
team nc("NC ���̳뽺", 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
team doosan("�λ� ���", 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
team lg("LG  Ʈ����", 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
team ssg("SSG ������", 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
team hd("���� �����ܽ�", 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
team hai("���� Ÿ�̰���", 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

hitter h1("���ع�", 0, 8,
	180, 240, 50, 160, 4, 2, 1);

hitter h2("���ڿ�", 0, 9,
	140, 260, 120, 120, 4, 2, 2);

hitter h3("�Ƿ���", 0, 7,
	140, 250, 160, 100, 4, 2, 3);

hitter h4("������", 0, 3,
	150, 230, 150, 40, 4, 1, 4);

hitter h5("����ȣ", 0, 2,
	170, 250, 120, 30, 4, 3, 5);

hitter h6("�̿���", 0, 5,
	210, 200, 100, 30, 4, 1, 6);

hitter h7("�����", 0, 7,
	170, 230, 30, 50, 4, 2, 7);

hitter h8("������", 0, 6,
	110, 180, 80, 60, 4, 1, 8);

hitter h9("����", 0, 4,  // �̸� �Ҽ��� ������
	200, 180, 20, 100, 4, 1, 9); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h10("������", 0, 4,
	150, 220, 10, 180, 4, 1, 10);

hitter h11("�ֿ���", 0, 5,
	140, 190, 60, 60, 4, 2, 10);

hitter h12("������", 0, 8,
	160, 220, 40, 100, 4, 2, 10);

hitter h13("���±�", 0, 2,
	120, 220, 50, 20, 4, 3, 10);

hitter h14("�赿��", 0, 7,
	110, 210, 120, 60, 4, 2, 10);

hitter h15("���ѿ�", 0, 5,
	140, 210, 0, 110, 4, 1, 10);

hitter h16("������", 0, 6,
	60, 210, 90, 80, 4, 1, 10);

//pitcher p1("��ĳ��", 0, 1570, 148); // 9��

pitcher p2("������", 0, 1590, 1590, 143, 250); // 9��

pitcher p3("������", 0, 1560, 1590, 138, 220); // 9��

pitcher p4("����", 0, 1510, 1590, 140, 190); // 9��

//pitcher p5("�ڼ���", 0, 1800, 4300, 154, 360); // 9�� ��ä�� 1500

pitcher p5("��ä��", 0, 1490, 1590, 141, 170); // 9�� ��ä�� 1500

pitcher p6("����ȯ", 0, 1570, 1590, 141, 1500); // 9��

pitcher p7("��Թ�", 0, 1560, 1590, 141, 1500); // 9��

pitcher p8("������", 0, 1550, 1590, 138, 1500); // 9��

pitcher p9("�̽���", 0, 1540, 1590, 146, 1500); // 9��

pitcher p10("������", 0, 1540, 1590, 146, 1500); // 9��

pitcher p11("��â��", 0, 1540, 1590, 146, 1500); // 9��

hitter h19("������", 0, 3,
	15, 2, 3, 3, 4, 3, 99);



hitter h31("��ġȫ", 1, 4,
	180, 250, 100, 100, 4, 1, 1); // 9�� ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h32("�վƼ�", 1, 9,
	190, 260, 20, 140, 4, 2, 2);

hitter h33("�̴�ȣ", 1, 3,
	150, 250, 130, 30, 4, 1, 3);

hitter h34("���ؿ�", 1, 7,
	180, 280, 50, 60, 4, 2, 4);

hitter h35("��  ��", 1, 3,
	200, 240, 100, 80, 4, 1, 5);

hitter h36("������", 1, 8, // �̺��Ե�
	170, 230, 80, 70, 4, 2, 6);

hitter h37("�ѵ���", 1, 5,
	180, 210, 140, 40, 4, 1, 7); // 600 150

hitter h38("������", 1, 6,
	200, 210, 70, 120, 4, 1, 8);

hitter h39("���ÿ�", 1, 2,
	80, 200, 90, 30, 4, 3, 9);

hitter h40("�ſ��", 1, 8,
	150, 210, 50, 70, 4, 2, 10);

hitter h41("���¿�", 1, 3,
	130, 200, 30, 70, 4, 1, 10);

hitter h42("������", 1, 2,
	170, 170, 70, 50, 4, 3, 10);

hitter h43("�̺���", 1, 9,
	200, 180, 80, 30, 4, 1, 10);

hitter h44("������", 1, 5,
	150, 180, 50, 50, 4, 2, 10);

hitter h45("������", 1, 8,
	110, 240, 50, 80, 4, 2, 10);

hitter h46("��μ�", 1, 5,
	150, 200, 80, 60, 4, 1, 10);

pitcher p31("���ϸ�", 1, 1630, 1590, 144, 280); // 9��

pitcher p32("�ڼ���", 1, 1580, 1590, 146, 250); // 9��

pitcher p33("����", 1, 1550, 1590, 145, 220); // 9��

pitcher p34("���վ�", 1, 1510, 1590, 141, 190); // 9��

pitcher p35("������", 1, 1500, 1590, 139, 170); // 9��

pitcher p36("�����", 1, 1560, 1590, 139, 1500); // 9��

pitcher p37("����ȣ", 1, 1550, 1590, 139, 1500); // 9��

pitcher p38("����", 1, 1540, 1590, 139, 1500); // 9��

pitcher p39("���ؿ�", 1, 1530, 1590, 139, 1500); // 9��

pitcher p40("������", 0, 1530, 1590, 146, 1500); // 9��

pitcher p41("���ؿ�", 0, 1530, 1590, 146, 1500); // 9��

hitter  h49("��  ư", 1, 3,
	15, 2, 3, 3, 4, 3, 99);




hitter h61("�ڹο�", 2, 4,
	180, 210, 30, 120, 4, 2, 1);

hitter h62("����", 2, 7,
	230, 200, 130, 50, 4, 1, 2);

hitter h63("������", 2, 9,
	120, 250, 160, 70, 4, 2, 3);

hitter h64("������", 2, 2,
	240, 280, 170, 60, 4, 2, 4);

hitter h65("���׾�", 2, 8,
	120, 240, 170, 100, 4, 3, 5);

hitter h66("�ڼ���", 2, 5,
	200, 190, 160, 40, 4, 1, 6);

hitter h67("������", 2, 6,
	150, 270, 100, 50, 4, 1, 7);

hitter h68("�̸��", 2, 7,  // �̸� �Ҽ��� ������
	200, 230, 40, 80, 4, 1, 8); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h69("������", 2, 3,
	130, 210, 100, 100, 4, 3, 9);

hitter h70("������", 2, 3,
	70, 230, 110, 60, 4, 2, 10);

hitter h71("���±�", 2, 2,
	180, 180, 70, 30, 4, 1, 10);

hitter h72("���μ�", 2, 9,
	140, 190, 20, 60, 4, 2, 10);

hitter h73("���ؿ�", 2, 5,
	130, 170, 100, 50, 4, 2, 10);

hitter h74("������", 2, 7,
	110, 190, 70, 70, 4, 2, 10);

hitter h75("��â��", 2, 3,
	90, 230, 90, 60, 4, 1, 10);

hitter h76("���ؿ�", 2, 9,
	180, 160, 10, 40, 4, 1, 10);




pitcher p61("��ģ��", 2, 1600, 1590, 147, 280); // 9��

pitcher p62("�Ľ���", 2, 1560, 1590, 148, 250); // 9��

pitcher p63("�Ź���", 2, 1540, 1590, 145, 220); // 9��

pitcher p64("������", 2, 1500, 1590, 143, 190); // 9��

pitcher p65("�۸��", 2, 1480, 1590, 138, 170); // 9��

pitcher p66("�ֱݰ�", 2, 1550, 1590, 151, 1500); // 9��

pitcher p67("ȫ����", 2, 1540, 1590, 140, 1500); // 9��

pitcher p68("��â��", 2, 1530, 1590, 142, 1500); // 9��

pitcher p69("������", 2, 1520, 1590, 141, 1500); // 9��

pitcher p70("������", 0, 1520, 1590, 146, 1500); // 9��

pitcher p71("��μ�", 0, 1520, 1590, 146, 1500); // 9��

hitter h79("�տ켺", 2, 3,
	15, 2, 3, 3, 4, 3, 99);





hitter h91("����", 3, 5,  // �̸� �Ҽ��� ������
	100, 240, 40, 50, 4, 1, 1); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h92("ȣ����", 3, 3,
	220, 250, 100, 30, 4, 2, 2);

hitter h93("�ڰǿ�", 3, 9,
	170, 280, 40, 90, 4, 2, 3);

hitter h94("����ȯ", 3, 7,
	200, 220, 170, 70, 4, 1, 4);

hitter h95("�缮ȯ", 3, 3,
	120, 240, 150, 40, 4, 3, 5);

hitter h96("������", 3, 8,
	210, 200, 80, 40, 4, 1, 6);

hitter h97("�ڰ��", 3, 6,
	140, 230, 70, 50, 4, 2, 7);

hitter h98("����ȣ", 3, 4,
	150, 190, 110, 90, 4, 2, 8);

hitter h99("�����", 3, 2,
	140, 190, 60, 30, 4, 1, 9);

hitter h100("�ֿ���", 3, 2,
	150, 200, 40, 30, 4, 1, 10);

hitter h101("���缮", 3, 6,
	80, 240, 60, 50, 4, 2, 10);

hitter h102("�ȱǼ�", 3, 9,
	160, 190, 60, 70, 4, 2, 10);

hitter h103("�ڼ���", 3, 2,
	170, 180, 30, 70, 4, 3, 10);

hitter h104("����ȣ", 3, 6,
	180, 170, 40, 70, 4, 2, 10);

hitter h105("������", 3, 8,
	160, 200, 30, 120, 4, 1, 10);

hitter h106("������", 3, 8,
	170, 200, 10, 80, 4, 1, 10);



pitcher p91("��  ��", 3, 1630, 1590, 147, 280); // 9��

pitcher p92("�ֿ���", 3, 1610, 1590, 139, 250); // 9��

pitcher p93("�̶���", 3, 1590, 1590, 151, 220); // 9��

pitcher p94("��  ��", 3, 1540, 1590, 145, 190); // 9��

pitcher p95("�����", 3, 1500, 1590, 135, 170); // 9��

pitcher p96("��ġ��", 3, 1580, 1590, 139, 1500); // 9��

pitcher p97("�谭��", 3, 1570, 1590, 146, 1500); // 9��

pitcher p98("����", 3, 1560, 1590, 142, 1500); // 9��

pitcher p99("ȫ����", 3, 1550, 1590, 145, 1500); // 9��

pitcher p100("�̽���", 0, 1550, 1590, 146, 1500); // 9��

pitcher p101("������", 0, 1550, 1590, 146, 1500); // 9��

hitter h109("������", 3, 3,
	15, 2, 3, 3, 4, 3, 99);







hitter h131("ȫâ��", 4, 8,  // �̸� �Ҽ��� ������
	260, 250, 20, 110, 4, 1, 1); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h132("������", 4, 9,
	160, 180, 140, 60, 4, 1, 2);

hitter h133("������", 4, 7,
	200, 220, 130, 70, 4, 1, 3);

hitter h134("ä����", 4, 9,
	140, 240, 130, 60, 4, 1, 4);

hitter h135("����ȯ", 4, 6,
	160, 200, 60, 80, 4, 1, 5);

hitter h136("������", 4, 3,
	190, 180, 120, 40, 4, 1, 6);

hitter h137("��μ�", 4, 5,
	160, 180, 110, 60, 4, 1, 7);

hitter h138("������", 4, 2,
	120, 210, 100, 50, 4, 1, 8);

hitter h139("������", 4, 4,
	160, 190, 50, 60, 4, 1, 9);

hitter h140("��õ��", 4, 8,
	210, 140, 50, 60, 4, 1, 10);

hitter h141("�̿���", 4, 3,
	120, 210, 50, 60, 4, 1, 10);

hitter h142("�����", 4, 8,
	220, 150, 30, 110, 4, 1, 10);

hitter h143("���缺", 4, 2,
	150, 150, 60, 60, 4, 1, 10);

hitter h144("�����", 4, 9,
	70, 230, 130, 40, 4, 1, 10);

hitter h145("�Ѽ���", 4, 7,
	150, 200, 70, 80, 4, 1, 10);

hitter h146("����â", 4, 4,
	190, 200, 50, 70, 4, 1, 10);




pitcher p131("���Ʒ�", 4, 1630, 1590, 147, 280); // 9��

pitcher p132("��  ��", 4, 1610, 1590, 148, 250); // 9��

pitcher p133("������", 4, 1590, 1590, 141, 220); // 9��

pitcher p134("������", 4, 1550, 1590, 139, 190); // 9��

pitcher p135("������", 4, 1530, 1590, 139, 170); // 9��

pitcher p136("�����", 4, 1600, 1590, 144, 1500); // 9��

pitcher p137("������", 4, 1590, 1590, 141, 1500); // 9��

pitcher p138("��켮", 4, 1580, 1590, 151, 1500); // 9��

pitcher p139("���ؼ�", 4, 1570, 1590, 142, 1500); // 9��

pitcher p140("���쿵", 0, 1570, 1590, 146, 1500); // 9��

pitcher p141("������", 0, 1570, 1590, 146, 1500); // 9��

hitter h149("������", 4, 3,
	15, 2, 3, 3, 4, 3, 99);







hitter h161("������", 5, 8,  // �̸� �Ҽ��� ������, 0:���� 1:
	160, 210, 60, 130, 4, 1, 1); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h162("��  ��", 5, 3,
	170, 180, 190, 30, 4, 2, 2);

hitter h163("�߽ż�", 5, 9,
	240, 200, 140, 100, 4, 2, 3);

hitter h164("��  ��", 5, 5,
	220, 220, 190, 90, 4, 1, 4);

hitter h165("������", 5, 9,
	160, 230, 170, 30, 4, 1, 5);

hitter h166("����ȯ", 5, 4,
	170, 210, 140, 30, 4, 1, 6);

hitter h167("�ڼ���", 5, 6,
	170, 250, 40, 100, 4, 3, 7);

hitter h168("������", 5, 7,
	90, 200, 120, 40, 4, 1, 8);

hitter h169("�����", 5, 2,
	160, 230, 40, 20, 4, 2, 9);



hitter h170("������", 5, 7,
	140, 220, 20, 40, 4, 1, 10);

hitter h171("�谭��", 5, 8,
	120, 200, 120, 60, 4, 2, 10);

hitter h172("�����", 5, 2,
	160, 200, 30, 30, 4, 2, 10);

hitter h173("�輺��", 5, 4,
	200, 210, 60, 60, 4, 1, 10);

hitter h174("���°�", 5, 3,
	90, 220, 100, 70, 4, 2, 10);

hitter h175("��  ��", 5, 4,
	210, 180, 30, 40, 4, 1, 10);

hitter h176("������", 5, 3,
	130, 180, 40, 40, 4, 1, 10);




pitcher p161("��  Ʈ", 5, 1620, 1590, 147, 280); // 9��

pitcher p162("������", 5, 1590, 1590, 139, 250); // 9��

pitcher p163("���¿�", 5, 1570, 1590, 142, 220); // 9��

pitcher p164("���¾�", 5, 1510, 1590, 140, 190); // 9��

pitcher p165("������", 5, 1490, 1590, 138, 170); // 9��

pitcher p166("������", 5, 1580, 1590, 139, 1500); // 9��

pitcher p167("������", 5, 1570, 1590, 141, 1500); // 9��

pitcher p168("�ڹ�ȣ", 5, 1560, 1590, 142, 1500); // 9��

pitcher p169("����", 5, 1550, 1590, 145, 1500); // 9��

pitcher p170("���翵", 0, 1550, 1590, 146, 1500); // 9��

pitcher p171("������", 0, 1550, 1590, 146, 1500); // 9��

hitter h179("�����", 5, 3,
	15, 2, 3, 3, 4, 3, 99);








hitter hh("ȫ�浿", 0, 3,
	15, 2, 3, 3, 4, 3, 12);

hitter hhh("ȫ�浿", 0, 3,
	15, 2, 3, 3, 4, 3, 12);

hitter hhhh("ȫ�浿", 0, 3,  // .X��Ÿ�� �����
	15, 2, 3, 3, 4, 3, 12);



hitter h1000("������", 0, 4,
	210, 190, 50, 50, 4, 1, 10);

hitter h1001("����ȣ", 10, 2,
	120, 200, 130, 30, 4, 1, 10);

hitter h1002("������", 10, 9,
	120, 220, 80, 70, 4, 1, 10);

hitter h1003("��ſ�", 10, 8,
	150, 230, 20, 130, 4, 1, 10);

hitter h1004("�̽���", 10, 5,
	160, 200, 110, 50, 4, 1, 10);

hitter h1005("������", 10, 7,
	100, 210, 140, 80, 4, 1, 10);

hitter h1006("�տ켺", 10, 6,
	160, 220, 20, 100, 4, 1, 10);

hitter h1007("����ö", 10, 2,
	150, 210, 30, 40, 4, 1, 10);

hitter h1008("�ڼ���", 10, 3,
	140, 230, 50, 60, 4, 1, 10);

pitcher p1000("�̿��", 2, 1550, 1590, 139, 300000); // 9��
pitcher p1001("�ڿ�ȣ", 2, 1550, 1590, 143, 300000); // 9��
pitcher p1002("�����", 2, 1550, 1590, 143, 300000); // 9��
pitcher p1003("������", 2, 1550, 1590, 143, 500000); // 9��
pitcher p1004("�̹μ�", 2, 1550, 1590, 143, 500000); // 9��
pitcher p1005("����ȯ", 2, 1550, 1590, 143, 500000); // 9��







//20_�Ｚ 21_�Ե� 22_NC 23_�λ� 24_LG 25_SSG
//26_Ű�� 27_kt 28_��ȭ 29_KIA
//30_���� 31_�ֹ�� 32_����� 33_��� 34_���� 35_OB 36_û�� 37_���׷� 38_û�� 39_SK // ���۵� �� : 28����

hitter h2000("�̽¿�", 20, 3,
	180, 250, 200, 60, 4, 1, 10);

hitter h2001("������", 20, 9,
	220, 260, 140, 90, 4, 1, 10);

hitter h2002("�̸���", 20, 2,
	210, 240, 160, 30, 4, 1, 10);

hitter h2003("�迵��", 20, 2,
	100, 110, 20, 30, 4, 1, 10);

hitter h2004("������", 20, 6,
	170, 230, 50, 100, 4, 1, 10);

hitter h2005("�����", 20, 5,
	120, 190, 10, 150, 4, 1, 10);

hitter h2006("������", 20, 9,
	200, 240, 70, 70, 4, 1, 10);

hitter h2031("�쵿��", 20, 8,
	150, 160, 70, 50, 4, 1, 10);

hitter h2032("��ȿ��", 20, 7,
	260, 270, 70, 90, 4, 1, 10);

hitter h2033("����", 20, 8,
	120, 140, 20, 200, 4, 1, 10);

hitter h2041("���Ѽ�", 20, 5,
	150, 260, 110, 80, 4, 1, 10);

////////////////////////////////////

hitter h2007("������", 21, 2,
	40, 80, 80, 30, 4, 1, 10);

hitter h2008("������", 21, 4,
	210, 230, 110, 60, 4, 1, 10);

hitter h2009("���ؿ�", 21, 3,
	160, 250, 150, 50, 4, 1, 10);

hitter h2010("�̿��", 21, 7,
	90, 190, 30, 90, 4, 1, 10);

hitter h2011("������", 21, 6,
	130, 200, 30, 50, 4, 1, 10);

hitter h2036("������", 21, 4,
	50, 200, 90, 30, 4, 1, 10);

hitter h2037("������", 21, 7,
	190, 250, 70, 130, 4, 1, 10);

hitter h2043("ȣ  ��", 21, 9,
	200, 260, 160, 130, 4, 1, 10);


////////////////////////////////////

hitter h2012("���ٿ�", 39, 4,
	190, 250, 80, 170, 4, 1, 10);

hitter h2045("����ȣ", 39, 2,
	60, 180, 90, 30, 4, 1, 10);

hitter h2013("�̺���", 24, 8,
	150, 270, 120, 120, 4, 1, 10);

hitter h2014("�ڿ���", 24, 7,
	140, 270, 110, 150, 4, 1, 10);

hitter h2015("�赿��", 24, 2,
	180, 210, 130, 60, 4, 1, 10);

hitter h2040("������", 24, 6,
	210, 240, 70, 150, 4, 1, 10);

hitter h2042("������", 24, 9,
	190, 250, 130, 80, 4, 1, 10);

////////////////////////////////////

hitter h2039("������", 26, 8,
	240, 270, 70, 140, 4, 1, 10);

hitter h2016("���±�", 28, 3,
	180, 280, 150, 50, 4, 1, 10);

hitter h2029("�̹�ȣ", 28, 5,
	170, 230, 150, 40, 4, 1, 10);

hitter h2030("��  ��", 28, 6,
	130, 160, 50, 50, 4, 1, 10);

hitter h2044("�̾��", 28, 9,
	110, 190, 40, 50, 4, 1, 10);

////////////////////////////////////

hitter h2017("����ȫ", 30, 8,
	160, 230, 160, 120, 4, 1, 10);

hitter h2018("���濱", 30, 6,
	120, 170, 30, 80, 4, 1, 10);

hitter h2046("������", 30, 6,
	160, 210, 90, 70, 4, 1, 10);

hitter h2019("�����", 31, 3,
	210, 240, 160, 60, 4, 1, 10);

hitter h2020("�ڰ��", 31, 2,
	140, 220, 170, 60, 4, 1, 10);

////////////////////////////////////

hitter h2021("������", 34, 6,
	240, 290, 110, 170, 4, 1, 10);

hitter h2022("ȫ����", 34, 5,
	180, 230, 130, 110, 4, 1, 10);

hitter h2023("�̼�ö", 34, 8,
	180, 230, 100, 150, 4, 1, 10);

hitter h2034("�����", 34, 3,
	90, 160, 30, 40, 4, 1, 10);

hitter h2035("�Ѵ�ȭ", 34, 5,
	220, 230, 110, 80, 4, 1, 10);

////////////////////////////////////

hitter h2024("������", 35, 9,
	150, 250, 160, 50, 4, 1, 10);

hitter h2025("������", 35, 8,
	200, 230, 20, 180, 4, 1, 10);

hitter h2026("������", 35, 2,
	140, 200, 10, 30, 4, 1, 10);

hitter h2027("������", 37, 3,
	150, 250, 160, 90, 4, 1, 10);

hitter h2028("����õ", 38, 8,
	240, 300, 110, 110, 4, 1, 10);

hitter h2038("�����", 38, 6,
	240, 220, 50, 170, 4, 1, 10);










pitcher p2000("�̿��", 2, 1550, 1590, 139, 300000); // 9��
pitcher p2001("�ڿ�ȣ", 2, 1550, 1590, 143, 300000); // 9��
pitcher p2002("�����", 2, 1550, 1590, 143, 300000); // 9��
pitcher p2003("������", 2, 1550, 1590, 143, 500000); // 9��
pitcher p2004("�̹μ�", 2, 1550, 1590, 143, 500000); // 9��
pitcher p2005("�ڼ���", 2, 1550, 1590, 143, 500000); // 9��


hitter h999("Ÿ�ں�", 10, 3,
	110, 140, 90, 60, 4, 1, 1);
pitcher p999("������", 2, 1500, 1500, 151, 300); // 9��

hitter h9999("", 10, 3, // Ŀ��Ƭ
	150, 150, 40, 60, 4, 1, 10);

pitcher p9999("", 2, 1500, 1500, 151, 300); // Ŀ��Ƭ





hitter h1101("��ȿ��", 0, 7,
	260, 290, 90, 100, 4, 2, 1);

hitter h1102("��Կ�", 0, 9,
	150, 280, 60, 130, 4, 2, 2);

hitter h1103("�輺��", 0, 4,
	200, 230, 120, 60, 4, 2, 3);

hitter h1104("�̸���", 0, 2,
	200, 260, 160, 50, 4, 1, 4);

hitter h1105("����â", 0, 8,
	200, 230, 80, 70, 4, 3, 5);

hitter h1106("���¼�", 0, 8,
	200, 240, 30, 60, 4, 1, 6);

hitter h1107("��뱹", 0, 5,
	180, 190, 90, 40, 4, 2, 7);

hitter h1108("���м�", 0, 3,
	160, 190, 70, 70, 4, 2, 8);

hitter h1109("����", 0, 6,  // �̸� �Ҽ��� ������
	170, 220, 70, 60, 4, 1, 9); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h1110("����ȣ", 0, 4,
	200, 220, 80, 50, 4, 1, 10);

hitter h1111("������", 0, 8,
	130, 210, 80, 30, 4, 2, 10);

hitter h1112("������", 0, 9,
	110, 190, 110, 80, 4, 2, 10);

hitter h1113("���ϼ�", 0, 2,
	180, 160, 90, 40, 4, 3, 10);

hitter h1114("�ڽ�ȣ", 0, 9,
	110, 260, 120, 30, 4, 1, 10);

hitter h1115("���뼮", 0, 6,
	150, 170, 40, 40, 4, 1, 10);

hitter h1116("��ټ�", 0, 5,
	140, 160, 100, 30, 4, 1, 10);

pitcher p1101("�����", 0, 1800, 1600, 150, 300); // 9��

pitcher p1102("������", 0, 1670, 1590, 143, 260); // 9��

pitcher p1103("Ȳ�Ժ�", 0, 1610, 1590, 138, 230); // 9��

pitcher p1104("�ǿ�ȣ", 0, 1590, 1580, 141, 210); // 9��

pitcher p1105("������", 0, 1570, 1600, 140, 180); // 9��

//pitcher p5("�ڼ���", 0, 1800, 4300, 154, 360); // 9�� ��ä�� 1500

pitcher p1106("����ȯ", 0, 1580, 1590, 141, 1500); // 9�� ��ä�� 1500

pitcher p1107("�ǿ�ȣ", 0, 1610, 1580, 141, 1500); // 9��

pitcher p1108("����ȣ", 0, 1560, 1590, 138, 1500); // 9��

pitcher p1109("������", 0, 1540, 1590, 146, 1500); // 9��

pitcher p1110("������", 0, 1530, 1590, 146, 1500); // 9��

pitcher p1111("�Ǳ�ȫ", 0, 1530, 1590, 146, 1500); // 9��




hitter h1201("�ŵ���", 0, 7,
	130, 300, 140, 100, 4, 2, 1);

hitter h1202("���Ѽ�", 0, 5,
	110, 270, 70, 70, 4, 2, 2);

hitter h1203("�̽¿�", 0, 3,
	160, 280, 180, 60, 4, 2, 3);

hitter h1204("������", 0, 9,
	230, 270, 170, 50, 4, 1, 4);

hitter h1205("���ͼ�", 0, 8,
	170, 260, 120, 150, 4, 3, 5);

hitter h1206("���±�", 0, 6,
	170, 200, 160, 60, 4, 1, 6);

hitter h1207("�����", 0, 4,
	110, 240, 120, 70, 4, 2, 7);

hitter h1208("����", 0, 2,
	90, 220, 60, 110, 4, 2, 8);

hitter h1209("Ȳ����", 0, 8,  // �̸� �Ҽ��� ������
	100, 220, 30, 60, 4, 1, 9); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h1210("������", 0, 6,
	130, 190, 110, 50, 4, 1, 10);

hitter h1211("�̸���", 0, 2,
	130, 180, 90, 20, 4, 2, 10);

hitter h1212("�迵��", 0, 2,
	120, 150, 90, 40, 4, 2, 10);

hitter h1213("������", 0, 7,
	90, 190, 60, 90, 4, 3, 10);

hitter h1214("�̵���", 0, 5,
	60, 150, 60, 50, 4, 1, 10);

hitter h1215("�����", 0, 4,
	110, 150, 70, 80, 4, 1, 10);

hitter h1216("���念", 0, 2,
	50, 180, 90, 50, 4, 1, 10);

pitcher p1201("���", 0, 1620, 1600, 150, 250); // 9��

pitcher p1202("�����", 0, 1560, 1590, 143, 270); // 9��

pitcher p1203("��  ��", 0, 1580, 1590, 134, 210); // 9��

pitcher p1204("����ȣ", 0, 1530, 1580, 141, 190); // 9��

pitcher p1205("������", 0, 1520, 1600, 140, 170); // 9��

//pitcher p5("�ڼ���", 0, 1800, 4300, 154, 360); // 9�� ��ä�� 1500

pitcher p1206("������", 0, 1560, 1590, 141, 1500); // 9�� ��ä�� 1500

pitcher p1207("��ä��", 0, 1550, 1580, 141, 1500); // 9��

pitcher p1208("����ȣ", 0, 1530, 1590, 138, 1500); // 9��

pitcher p1209("��â��", 0, 1520, 1590, 146, 1500); // 9��

pitcher p1210("�̻���", 0, 1510, 1590, 146, 1500); // 9��

pitcher p1211("�����", 0, 1510, 1590, 146, 1500); // 9��



hitter h1301("������", 0, 9,
	210, 260, 90, 100, 4, 2, 1);

hitter h1302("���Ѽ�", 0, 5,
	140, 270, 90, 50, 4, 2, 2);

hitter h1303("�̽¿�", 0, 3,
	210, 250, 240, 60, 4, 2, 3);

hitter h1304("���ؿ�", 0, 3,
	200, 260, 170, 50, 4, 1, 4);

hitter h1305("������", 0, 7,
	200, 270, 190, 50, 4, 3, 5);

hitter h1306("�긮��", 0, 6,
	140, 210, 160, 40, 4, 1, 6);

hitter h1307("������", 0, 2,
	100, 260, 120, 30, 4, 2, 7);

hitter h1308("������", 0, 8,
	200, 200, 80, 80, 4, 2, 8);

hitter h1309("������", 0, 4,  // �̸� �Ҽ��� ������
	100, 260, 50, 70, 4, 1, 9); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h1310("����ȯ", 0, 4,
	160, 180, 40, 50, 4, 1, 10);

hitter h1311("�ɼ���", 0, 7,
	100, 180, 100, 40, 4, 2, 10);

hitter h1312("������", 0, 7,
	80, 180, 70, 70, 4, 2, 10);

hitter h1313("������", 0, 2,
	150, 150, 40, 40, 4, 3, 10);

hitter h1314("�����", 0, 6,
	90, 160, 30, 110, 4, 1, 10);

hitter h1315("������", 0, 5,
	80, 170, 40, 60, 4, 1, 10);

hitter h1316("����ö", 0, 9,
	140, 190, 60, 50, 4, 1, 10);

pitcher p1301("��â��", 0, 1670, 1600, 151, 270); // 9��

pitcher p1302("�迵��", 0, 1610, 1590, 148, 240); // 9��

pitcher p1303("������", 0, 1560, 1590, 141, 220); // 9��

pitcher p1304("����ȣ", 0, 1530, 1580, 137, 200); // 9��

pitcher p1305("���̾�", 0, 1520, 1600, 140, 170); // 9��

//pitcher p5("�ڼ���", 0, 1800, 4300, 154, 360); // 9�� ��ä�� 1500

pitcher p1306("������", 0, 1610, 1590, 141, 1500); // 9�� ��ä�� 1500

pitcher p1307("�����", 0, 1580, 1580, 141, 1500); // 9��

pitcher p1308("������", 0, 1530, 1590, 138, 1500); // 9��

pitcher p1309("������", 0, 1550, 1590, 146, 1500); // 9��

pitcher p1310("������", 0, 1520, 1590, 146, 1500); // 9��

pitcher p1311("��  ��", 0, 1520, 1590, 146, 1500); // 9��




hitter h1401("������", 0, 8,
	200, 240, 80, 80, 4, 2, 1);

hitter h1402("����ȣ", 0, 4,
	200, 210, 60, 60, 4, 2, 2);

hitter h1403("������", 0, 3,
	110, 240, 120, 120, 4, 2, 3);

hitter h1404("������", 0, 7,
	190, 220, 170, 50, 4, 1, 4);

hitter h1405("���Ѽ�", 0, 5,
	90, 270, 110, 50, 4, 3, 5);

hitter h1406("������", 0, 2,
	180, 240, 60, 40, 4, 1, 6);

hitter h1407("������", 0, 9,
	220, 200, 120, 90, 4, 2, 7);

hitter h1408("������", 0, 9,
	160, 200, 60, 100, 4, 2, 8);

hitter h1409("������", 0, 6,  // �̸� �Ҽ��� ������
	170, 210, 50, 80, 4, 1, 9); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h1410("�����", 0, 8,
	120, 230, 50, 40, 4, 1, 10);

hitter h1411("������", 0, 7,
	110, 220, 70, 50, 4, 2, 10);

hitter h1412("����", 0, 8,
	130, 210, 20, 170, 4, 2, 10);

hitter h1413("������", 0, 2,
	140, 190, 60, 40, 4, 3, 10);

hitter h1414("�����", 0, 6,
	80, 200, 30, 110, 4, 1, 10);

hitter h1415("�ڼ���", 0, 5,
	140, 170, 50, 50, 4, 1, 10);

hitter h1416("����ȯ", 0, 4,
	120, 160, 70, 60, 4, 1, 10);

pitcher p1401("�迵��", 0, 1670, 1600, 148, 250); // 9��

pitcher p1402("�ϸ�Į", 0, 1580, 1590, 147, 210); // 9��

pitcher p1403("����ȣ", 0, 1550, 1590, 137, 190); // 9��

pitcher p1404("��ũ��", 0, 1530, 1580, 147, 170); // 9��

pitcher p1405("��â��", 0, 1490, 1600, 150, 150); // 9��

//pitcher p5("�ڼ���", 0, 1800, 4300, 154, 360); // 9�� ��ä�� 1500

pitcher p1406("����ȯ", 0, 1870, 1590, 151, 1500); // 9�� ��ä�� 1500

pitcher p1407("�ǿ���", 0, 1660, 1580, 147, 1500); // 9��

pitcher p1408("�ӵ���", 0, 1590, 1590, 142, 1500); // 9��

pitcher p1409("������", 0, 1570, 1590, 146, 1500); // 9��

pitcher p1410("�ڼ���", 0, 1560, 1590, 143, 1500); // 9��

pitcher p1411("������", 0, 1560, 1590, 143, 1500); // 9��





hitter h1501("���ڿ�", 0, 9,
	160, 310, 80, 110, 4, 2, 1);

hitter h1502("���ع�", 0, 8,
	140, 260, 10, 200, 4, 2, 2);

hitter h1503("���ٷ�", 0, 4,
	220, 230, 210, 130, 4, 2, 3);

hitter h1504("������", 0, 7,
	160, 280, 170, 40, 4, 1, 4);

hitter h1505("�ڼ���", 0, 5,
	180, 270, 170, 50, 4, 3, 5);

hitter h1506("�̽¿�", 0, 3,
	140, 300, 160, 50, 4, 1, 6);

hitter h1507("ä����", 0, 3,
	90, 320, 80, 40, 4, 2, 7);

hitter h1508("������", 0, 2,
	120, 270, 50, 40, 4, 2, 8);

hitter h1509("����", 0, 6,  // �̸� �Ҽ��� ������
	180, 230, 90, 140, 4, 1, 9); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h1510("������", 0, 9,
	190, 250, 100, 70, 4, 1, 10);

hitter h1511("������", 0, 2,
	140, 250, 80, 20, 4, 2, 10);

hitter h1512("������", 0, 8,
	130, 210, 20, 170, 4, 2, 10);

hitter h1513("�����", 0, 2,
	40, 210, 70, 50, 4, 3, 10);

hitter h1514("������", 0, 6,
	130, 180, 30, 60, 4, 1, 10);

hitter h1515("����", 0, 4,
	170, 200, 50, 40, 4, 1, 10);

hitter h1516("�迵��", 0, 8,
	150, 220, 50, 70, 4, 1, 10);

pitcher p1501("�ǰ���", 0, 1620, 1600, 150, 250); // 9��

pitcher p1502("����ȯ", 0, 1590, 1590, 142, 230); // 9��

pitcher p1503("������", 0, 1540, 1590, 145, 210); // 9��

pitcher p1504("Ŭ����", 0, 1510, 1580, 144, 200); // 9��

pitcher p1505("�����", 0, 1480, 1600, 139, 190); // 9��

//pitcher p5("�ڼ���", 0, 1800, 4300, 154, 360); // 9�� ��ä�� 1500

pitcher p1506("��â��", 0, 1630, 1590, 150, 1500); // 9�� ��ä�� 1500

pitcher p1507("������", 0, 1600, 1580, 144, 1500); // 9��

pitcher p1508("�ڱ�ȫ", 0, 1560, 1590, 141, 1500); // 9��

pitcher p1509("��â��", 0, 1530, 1590, 146, 1500); // 9��

pitcher p1510("������", 0, 1520, 1590, 140, 1500); // 9��

pitcher p1511("������", 0, 1520, 1590, 141, 1500); // 9��





hitter h1701("���ع�", 0, 8,
	180, 240, 50, 160, 4, 2, 1);

hitter h1702("���ڿ�", 0, 9,
	140, 260, 120, 120, 4, 2, 2);

hitter h1703("�Ƿ���", 0, 7,
	140, 250, 160, 100, 4, 2, 3);

hitter h1704("������", 0, 3,
	150, 230, 150, 40, 4, 1, 4);

hitter h1705("����ȣ", 0, 2,
	170, 250, 120, 30, 4, 3, 5);

hitter h1706("�̿���", 0, 5,
	210, 200, 100, 30, 4, 1, 6);

hitter h1707("�����", 0, 7,
	170, 230, 30, 50, 4, 2, 7);

hitter h1708("������", 0, 6,
	110, 180, 80, 60, 4, 1, 8);

hitter h1709("����", 0, 4,  // �̸� �Ҽ��� ������
	200, 180, 20, 100, 4, 1, 9); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h1710("������", 0, 4,
	150, 220, 10, 180, 4, 1, 10);

hitter h1711("�ֿ���", 0, 5,
	140, 190, 60, 60, 4, 2, 10);

hitter h1712("������", 0, 8,
	160, 220, 40, 100, 4, 2, 10);

hitter h1713("���±�", 0, 2,
	120, 220, 50, 20, 4, 3, 10);

hitter h1714("�赿��", 0, 7,
	110, 210, 120, 60, 4, 2, 10);

hitter h1715("���ѿ�", 0, 5,
	140, 210, 0, 110, 4, 1, 10);

hitter h1716("������", 0, 6,
	60, 210, 90, 80, 4, 1, 10);

pitcher p1701("��ĳ��", 0, 1630, 1600, 150, 280); // 9��

pitcher p1702("������", 0, 1590, 1590, 143, 250); // 9��

pitcher p1703("������", 0, 1560, 1590, 138, 220); // 9��

pitcher p1704("����", 0, 1510, 1590, 140, 190); // 9��

//pitcher p5("�ڼ���", 0, 1800, 4300, 154, 360); // 9�� ��ä�� 1500

pitcher p1705("��ä��", 0, 1490, 1590, 141, 170); // 9�� ��ä�� 1500

pitcher p1706("����ȯ", 0, 1570, 1590, 141, 1500); // 9��

pitcher p1707("��Թ�", 0, 1560, 1590, 141, 1500); // 9��

pitcher p1708("������", 0, 1550, 1590, 138, 1500); // 9��

pitcher p1709("�̽���", 0, 1540, 1590, 146, 1500); // 9��

pitcher p1710("������", 0, 1540, 1590, 146, 1500); // 9��

pitcher p1711("��â��", 0, 1540, 1590, 146, 1500); // 9��




hitter h8001("����ȣ", 11, 7,
	230, 260, 20, 120, 4, 2, 1);

hitter h8002("������", 11, 6,
	120, 260, 120, 50, 4, 2, 2);

hitter h8003("����ȣ", 11, 4,
	220, 280, 80, 80, 4, 2, 3);

hitter h8004("����ȫ", 11, 8,
	190, 260, 170, 160, 4, 1, 4);

hitter h8005("�ڰ��", 11, 2,
	170, 240, 210, 80, 4, 3, 5);

hitter h8006("��  ��", 11, 5,
	40, 230, 220, 50, 4, 1, 6);

hitter h8007("�̸��", 11, 4,
	180, 280, 70, 60, 4, 2, 7);

hitter h8008("�̼���", 11, 3,
	170, 240, 130, 60, 4, 1, 8);

hitter h8009("������", 11, 9,  // �̸� �Ҽ��� ������
	190, 210, 160, 70, 4, 1, 9); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h8010("������", 11, 3,
	160, 210, 200, 40, 4, 1, 10);

hitter h8011("����ȣ", 11, 8,
	160, 180, 100, 100, 4, 2, 10);

hitter h8012("������", 11, 2,
	130, 180, 100, 30, 4, 2, 10);

hitter h8013("���濱", 11, 4,
	110, 220, 10, 110, 4, 3, 10);

hitter h8014("������", 11, 4,
	90, 190, 120, 70, 4, 2, 10);

hitter h8015("����", 11, 7,
	200, 250, 140, 60, 4, 1, 10);

hitter h8016("����ǥ", 11, 3,
	160, 200, 150, 50, 4, 1, 10);

pitcher p8001("�Ӽ���", 11, 1670, 1600, 150, 270); // 9��

pitcher p8002("������", 11, 1640, 1590, 143, 260); // 9��

pitcher p8003("�����", 11, 1600, 1590, 138, 250); // 9��

pitcher p8004("������", 11, 1540, 1590, 140, 170); // 9��

//pitcher p5("�ڼ���", 0, 1800, 4300, 154, 360); // 9�� ��ä�� 1500

pitcher p8005("���Ͽ�", 11, 1550, 1590, 141, 160); // 9�� ��ä�� 1500

pitcher p8006("���翵", 11, 1650, 1590, 141, 1500); // 9��

pitcher p8007("����õ", 11, 1610, 1590, 141, 1500); // 9��

pitcher p8008("�����", 11, 1560, 1590, 138, 1500); // 9��

pitcher p8009("��ö��", 11, 1540, 1590, 146, 1500); // 9��

pitcher p8010("����ȣ", 11, 1530, 1590, 146, 1500); // 9��

pitcher p8011("������", 11, 1530, 1590, 146, 1500); // 9��




hitter h9001("������", 12, 6,
	160, 240, 80, 210, 4, 2, 1);

hitter h9002("�̼�ö", 12, 8,
	200, 200, 90, 120, 4, 2, 2);

hitter h9003("�̼�ȣ", 12, 9,
	240, 240, 80, 90, 4, 2, 3);

hitter h9004("ȫ����", 12, 5,
	200, 210, 110, 100, 4, 1, 4);

hitter h9005("�Ѵ�ȭ", 12, 5,
	200, 220, 120, 50, 4, 3, 5);

hitter h9006("������", 12, 7,
	210, 200, 140, 60, 4, 1, 6);

hitter h9007("��ȸ��", 12, 2,
	100, 250, 70, 30, 4, 2, 7);

hitter h9008("�輺��", 12, 3,
	110, 250, 70, 70, 4, 1, 8);

hitter h9009("��ö��", 12, 4,  // �̸� �Ҽ��� ������
	170, 220, 20, 50, 4, 1, 9); // ���� ��Ȯ �Ŀ� ���ǵ� ���� �����

hitter h9010("��ä��", 12, 2,
	200, 150, 100, 70, 4, 1, 10);

hitter h9011("�̰ǿ�", 12, 7,
	140, 180, 70, 100, 4, 2, 10);

hitter h9012("��  ��", 12, 9,
	160, 170, 90, 80, 4, 2, 10);

hitter h9013("�躴��", 12, 5,
	120, 160, 60, 50, 4, 3, 10);

hitter h9014("�̿뼮", 12, 4,
	30, 190, 60, 40, 4, 2, 10);

hitter h9015("�����", 12, 3,
	220, 230, 140, 60, 4, 1, 10);

hitter h9016("�̰溹", 12, 4,
	160, 190, 30, 40, 4, 1, 10);

pitcher p9001("������", 12, 1710, 1600, 150, 270); // 9��

pitcher p9002("�̰�ö", 12, 1670, 1590, 150, 230); // 9��

pitcher p9003("�̴���", 12, 1610, 1590, 147, 210); // 9��

pitcher p9004("������", 12, 1540, 1590, 142, 190); // 9��

//pitcher p5("�ڼ���", 0, 1800, 4300, 154, 360); // 9�� ��ä�� 1500

pitcher p9005("������", 12, 1520, 1590, 141, 170); // 9�� ��ä�� 1500

pitcher p9006("������", 12, 2000, 1590, 151, 1500); // 9��

pitcher p9007("�����", 12, 1590, 1590, 141, 1500); // 9��

pitcher p9008("���¿�", 12, 1560, 1590, 138, 1500); // 9��

pitcher p9009("�ŵ���", 12, 1540, 1590, 146, 1500); // 9��

pitcher p9010("���ö", 12, 1530, 1590, 146, 1500); // 9��

pitcher p9011("���縸", 12, 1530, 1590, 146, 1500); // 9��







void showteam(team& team, int inn, int type)
{


	switch (team.tn_()) {
	case 0:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

		if (type == 0)	cout << "�Ｚ";
		else cout << " [ �Ｚ ���̿��� ]";

		break;

	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

		if (type == 0)	cout << "�Ե�";
		else cout << " [ �Ե� ���̾��� ]";

		break;

	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

		if (type == 0)	cout << " NC ";
		else cout << " [  NC  ���̳뽺 ]";

		break;

	case 3:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

		if (type == 0)	cout << "�λ�";
		else cout << " [  �λ� ���  ]";

		break;

	case 4:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

		if (type == 0)	cout << " LG ";
		else cout << " [   LG Ʈ����   ]";

		break;

	case 5:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

		if (type == 0)	cout << "SSG ";
		else cout << " [  SSG  ������  ]";

		break;

	case 11:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

		if (type == 0)	cout << "����";
		else cout << " [ ���� �����ܽ� ]";

		break;

	case 12:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

		if (type == 0)	cout << "����";
		else cout << " [ ���� Ÿ�̰��� ]";

		break;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);




}

int change_pos(int i)
{
	return i;
}

int print_check(int i, int j)
{
	if (i == j) return 1;

	else if (i >= 7 && j >= 7) return 1;

	else if ((i == 3 && j == 5) || (i == 5 && j == 3)) return 1;

	else if ((i == 4 && j == 6) || (i == 6 && j == 4)) return 1;

	else return 0;
}

int act(int pitching) // ���� ������ ���� �ؼ� �޶���.
{
	int col = 46;
	int row = 12;

	//static int i = 2;
	//static int j = 2;
	//static int k = 2;

	int key = 0;

	int order = 0; // �Ű������� ���� ����

	if (pitching != 9999)

	{
		for (int i = 0; i < 5; i++)
		{
			cur(col, row + i);
			cout << "                                          ";
		}



		cur(col, row);
		cout << "      -- �ؼ� ������Ʈ �����Դϴ� --";

		cur(46, row + 2);
		cout << "                  �� = " << pitching;

	}

	if (kbhit()) {
		key = getch();
	}

	//op[0] = i;
	//op[1] = j;
	//op[2] = k * 10 - 20;

	//cur(col, row); cout << "[  Ÿ��  ]   [   ����   ]   [  �ַ�  ]";
	//cur(col - 1, row + 1); cout << "                                        ";

	//if (i == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cur(col, row + 2); cout << "[1] ������   "; // cur(48, 14)
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//if (j == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cout << "[4] ū ����    ";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//if (k == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cout << "[7] ������";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	//if (i == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cur(col, row + 3); cout << "[2] �Ϲ���   ";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//if (j == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cout << "[5] �Ϲ� ����  ";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//if (k == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cout << "[8] �Ϲ���";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	//if (i == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cur(col, row + 4); cout << "[3] �ұ���   ";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//if (j == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cout << "[6] ���� ����  ";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//if (k == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cout << "[9] �ұ���";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	return key;
}

void playball(team& a, team& b, int** total_gam, int sound, int game_speed, int my_team, bool use_condition)
{
	int out = 0;
	int inn = 1;
	int a_player = 9;
	int b_player = 9;
	int base = 0; // ���Ÿ����

	int home_score = 0;
	int away_score = 0;

	int h_hp = 0;
	int a_hp = 0;

	int home_randpitcher = -1, home_randpitchercheck = 0;
	int away_randpitcher = 0, away_randpitchercheck = 0;

	int home_gap = 0; // �� �� ��������
	int away_gap = 0;

	int battlecount = 0; // �� ���� Ÿ�ڸ� ����ߴ°�
	int pitcher_change = 1; // ������ �� �� ��ü�ߴ°�

	bool homesp_lead = true; // �������� �¸����
	bool awaysp_lead = true;

	bool hometeam_lead = true; // ���������� ������ �ڿ��� �켼�� �����ߴ°� Ȯ��
	bool awayteam_lead = true;

	bool homepitcher_change = false;
	bool awaypitcher_change = false;



	if (sound <= 2 && sim == 2)
	{
		PlaySound(TEXT("cheer.wav"), NULL, SND_ASYNC | SND_LOOP);
	}

	h1.clear_today(); h2.clear_today(); h3.clear_today(); h4.clear_today(); h5.clear_today();
	h6.clear_today(); h7.clear_today(); h8.clear_today(); h9.clear_today(); h10.clear_today();
	h11.clear_today(); h12.clear_today(); h13.clear_today(); h14.clear_today(); h15.clear_today(); h16.clear_today();

	h31.clear_today(); h32.clear_today(); h33.clear_today(); h34.clear_today(); h35.clear_today();
	h36.clear_today(); h37.clear_today(); h38.clear_today(); h39.clear_today(); h40.clear_today();
	h41.clear_today(); h42.clear_today(); h43.clear_today(); h44.clear_today(); h45.clear_today(); h46.clear_today();

	h61.clear_today(); h62.clear_today(); h63.clear_today(); h64.clear_today(); h65.clear_today();
	h66.clear_today(); h67.clear_today(); h68.clear_today(); h69.clear_today(); h70.clear_today();
	h71.clear_today(); h72.clear_today(); h73.clear_today(); h74.clear_today(); h75.clear_today(); h76.clear_today();

	h91.clear_today(); h92.clear_today(); h93.clear_today(); h94.clear_today(); h95.clear_today();
	h96.clear_today(); h97.clear_today(); h98.clear_today(); h99.clear_today(); h100.clear_today();
	h101.clear_today(); h102.clear_today(); h103.clear_today(); h104.clear_today(); h105.clear_today(); h106.clear_today();

	h131.clear_today(); h132.clear_today(); h133.clear_today(); h134.clear_today(); h135.clear_today();
	h136.clear_today(); h137.clear_today(); h138.clear_today(); h139.clear_today(); h140.clear_today();
	h141.clear_today(); h142.clear_today(); h143.clear_today(); h144.clear_today(); h145.clear_today(); h146.clear_today();

	h161.clear_today(); h162.clear_today(); h163.clear_today(); h164.clear_today(); h165.clear_today();
	h166.clear_today(); h167.clear_today(); h168.clear_today(); h169.clear_today(); h170.clear_today();
	h171.clear_today(); h172.clear_today(); h173.clear_today(); h174.clear_today(); h175.clear_today(); h176.clear_today();

	h8001.clear_today(); h8002.clear_today(); h8003.clear_today(); h8004.clear_today(); h8005.clear_today();
	h8006.clear_today(); h8007.clear_today(); h8008.clear_today(); h8009.clear_today(); h8010.clear_today();
	h8011.clear_today(); h8012.clear_today(); h8013.clear_today(); h8014.clear_today(); h8015.clear_today(); h8016.clear_today();

	h9001.clear_today(); h9002.clear_today(); h9003.clear_today(); h9004.clear_today(); h9005.clear_today();
	h9006.clear_today(); h9007.clear_today(); h9008.clear_today(); h9009.clear_today(); h9010.clear_today();
	h9011.clear_today(); h9012.clear_today(); h9013.clear_today(); h9014.clear_today(); h9015.clear_today(); h9016.clear_today();



	//int score[2][17] = {
	//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	//};


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 20; j++) {
			scoreboard[i][j] = 0;
		}
	}

	switch (a.tn_()) {
	case 0:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&ppp, &p1, sizeof(class pitcher)); break;
		case 1: memcpy(&ppp, &p2, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p3, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p4, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p5, sizeof(class pitcher)); break;

		}
		break;

	case 1:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&ppp, &p31, sizeof(class pitcher)); break;
		case 1: memcpy(&ppp, &p32, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p33, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p34, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p35, sizeof(class pitcher)); break;

		}
		break;

	case 2:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&ppp, &p61, sizeof(class pitcher)); break;
		case 1: memcpy(&ppp, &p62, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p63, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p64, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p65, sizeof(class pitcher)); break;

		}
		break;

	case 3:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&ppp, &p91, sizeof(class pitcher)); break;
		case 1: memcpy(&ppp, &p92, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p93, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p94, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p95, sizeof(class pitcher)); break;

		}
		break;


	case 4:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&ppp, &p131, sizeof(class pitcher)); break;
		case 1: memcpy(&ppp, &p132, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p133, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p134, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p135, sizeof(class pitcher)); break;

		}
		break;

	case 5:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&ppp, &p161, sizeof(class pitcher)); break;
		case 1: memcpy(&ppp, &p162, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p163, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p164, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p165, sizeof(class pitcher)); break;

		}
		break;

	case 11:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&ppp, &p8001, sizeof(class pitcher)); break;
		case 1: memcpy(&ppp, &p8002, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p8003, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p8004, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p8005, sizeof(class pitcher)); break;

		}
		break;

	case 12:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&ppp, &p9001, sizeof(class pitcher)); break;
		case 1: memcpy(&ppp, &p9002, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p9003, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p9004, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p9005, sizeof(class pitcher)); break;

		}
		break;

	}

	switch (b.tn_()) {
	case 0:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&pp, &p1, sizeof(class pitcher)); break;
		case 1: memcpy(&pp, &p2, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p3, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p4, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p5, sizeof(class pitcher)); break;

		}
		break;

	case 1:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&pp, &p31, sizeof(class pitcher)); break;
		case 1: memcpy(&pp, &p32, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p33, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p34, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p35, sizeof(class pitcher)); break;

		}
		break;

	case 2:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&pp, &p61, sizeof(class pitcher)); break;
		case 1: memcpy(&pp, &p62, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p63, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p64, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p65, sizeof(class pitcher)); break;

		}
		break;

	case 3:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&pp, &p91, sizeof(class pitcher)); break;
		case 1: memcpy(&pp, &p92, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p93, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p94, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p95, sizeof(class pitcher)); break;

		}
		break;

	case 4:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&pp, &p131, sizeof(class pitcher)); break;
		case 1: memcpy(&pp, &p132, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p133, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p134, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p135, sizeof(class pitcher)); break;

		}
		break;

	case 5:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&pp, &p161, sizeof(class pitcher)); break;
		case 1: memcpy(&pp, &p162, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p163, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p164, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p165, sizeof(class pitcher)); break;

		}
		break;

	case 11:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&pp, &p8001, sizeof(class pitcher)); break;
		case 1: memcpy(&pp, &p8002, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p8003, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p8004, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p8005, sizeof(class pitcher)); break;

		}
		break;

	case 12:
		switch (**total_gam % 5)
		{
		case 0: memcpy(&pp, &p9001, sizeof(class pitcher)); break;
		case 1: memcpy(&pp, &p9002, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p9003, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p9004, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p9005, sizeof(class pitcher)); break;

		}
		break;

	}

	h_hp = ppp.hprint_();
	a_hp = pp.hprint_();

	ppp.change_play_game();
	pp.change_play_game();

	// ��� ���� �� ����� ����. ����� ���� ���Ѵٸ� no_condition() �ߵ�

	if (use_condition == true)
	{
		h1.correct_condition(); h2.correct_condition(); h3.correct_condition(); h4.correct_condition(); h5.correct_condition();
		h6.correct_condition(); h7.correct_condition(); h8.correct_condition(); h9.correct_condition(); h10.correct_condition();
		h11.correct_condition(); h12.correct_condition(); h13.correct_condition(); h14.correct_condition(); h15.correct_condition(); h16.correct_condition();

		h31.correct_condition(); h32.correct_condition(); h33.correct_condition(); h34.correct_condition(); h35.correct_condition();
		h36.correct_condition(); h37.correct_condition(); h38.correct_condition(); h39.correct_condition(); h40.correct_condition();
		h41.correct_condition(); h42.correct_condition(); h43.correct_condition(); h44.correct_condition(); h45.correct_condition(); h46.correct_condition();

		h61.correct_condition(); h62.correct_condition(); h63.correct_condition(); h64.correct_condition(); h65.correct_condition();
		h66.correct_condition(); h67.correct_condition(); h68.correct_condition(); h69.correct_condition(); h70.correct_condition();
		h71.correct_condition(); h72.correct_condition(); h73.correct_condition(); h74.correct_condition(); h75.correct_condition(); h76.correct_condition();

		h91.correct_condition(); h92.correct_condition(); h93.correct_condition(); h94.correct_condition(); h95.correct_condition();
		h96.correct_condition(); h97.correct_condition(); h98.correct_condition(); h99.correct_condition(); h100.correct_condition();
		h101.correct_condition(); h102.correct_condition(); h103.correct_condition(); h104.correct_condition(); h105.correct_condition(); h106.correct_condition();

		h131.correct_condition(); h132.correct_condition(); h133.correct_condition(); h134.correct_condition(); h135.correct_condition();
		h136.correct_condition(); h137.correct_condition(); h138.correct_condition(); h139.correct_condition(); h140.correct_condition();
		h141.correct_condition(); h142.correct_condition(); h143.correct_condition(); h144.correct_condition(); h145.correct_condition(); h146.correct_condition();

		h161.correct_condition(); h162.correct_condition(); h163.correct_condition(); h164.correct_condition(); h165.correct_condition();
		h166.correct_condition(); h167.correct_condition(); h168.correct_condition(); h169.correct_condition(); h170.correct_condition();
		h171.correct_condition(); h172.correct_condition(); h173.correct_condition(); h174.correct_condition(); h175.correct_condition(); h176.correct_condition();

		h8001.correct_condition(); h8002.correct_condition(); h8003.correct_condition(); h8004.correct_condition(); h8005.correct_condition();
		h8006.correct_condition(); h8007.correct_condition(); h8008.correct_condition(); h8009.correct_condition(); h8010.correct_condition();
		h8011.correct_condition(); h8012.correct_condition(); h8013.correct_condition(); h8014.correct_condition(); h8015.correct_condition(); h8016.correct_condition();

		h9001.correct_condition(); h9002.correct_condition(); h9003.correct_condition(); h9004.correct_condition(); h9005.correct_condition();
		h9006.correct_condition(); h9007.correct_condition(); h9008.correct_condition(); h9009.correct_condition(); h9010.correct_condition();
		h9011.correct_condition(); h9012.correct_condition(); h9013.correct_condition(); h9014.correct_condition(); h9015.correct_condition(); h9016.correct_condition();
	}

	else
	{
		h1.no_condition(); h2.no_condition(); h3.no_condition(); h4.no_condition(); h5.no_condition();
		h6.no_condition(); h7.no_condition(); h8.no_condition(); h9.no_condition(); h10.no_condition();
		h11.no_condition(); h12.no_condition(); h13.no_condition(); h14.no_condition(); h15.no_condition(); h16.no_condition();

		h31.no_condition(); h32.no_condition(); h33.no_condition(); h34.no_condition(); h35.no_condition();
		h36.no_condition(); h37.no_condition(); h38.no_condition(); h39.no_condition(); h40.no_condition();
		h41.no_condition(); h42.no_condition(); h43.no_condition(); h44.no_condition(); h45.no_condition(); h46.no_condition();

		h61.no_condition(); h62.no_condition(); h63.no_condition(); h64.no_condition(); h65.no_condition();
		h66.no_condition(); h67.no_condition(); h68.no_condition(); h69.no_condition(); h70.no_condition();
		h71.no_condition(); h72.no_condition(); h73.no_condition(); h74.no_condition(); h75.no_condition(); h76.no_condition();

		h91.no_condition(); h92.no_condition(); h93.no_condition(); h94.no_condition(); h95.no_condition();
		h96.no_condition(); h97.no_condition(); h98.no_condition(); h99.no_condition(); h100.no_condition();
		h101.no_condition(); h102.no_condition(); h103.no_condition(); h104.no_condition(); h105.no_condition(); h106.no_condition();

		h131.no_condition(); h132.no_condition(); h133.no_condition(); h134.no_condition(); h135.no_condition();
		h136.no_condition(); h137.no_condition(); h138.no_condition(); h139.no_condition(); h140.no_condition();
		h141.no_condition(); h142.no_condition(); h143.no_condition(); h144.no_condition(); h145.no_condition(); h146.no_condition();

		h161.no_condition(); h162.no_condition(); h163.no_condition(); h164.no_condition(); h165.no_condition();
		h166.no_condition(); h167.no_condition(); h168.no_condition(); h169.no_condition(); h170.no_condition();
		h171.no_condition(); h172.no_condition(); h173.no_condition(); h174.no_condition(); h175.no_condition(); h176.no_condition();

		h8001.no_condition(); h8002.no_condition(); h8003.no_condition(); h8004.no_condition(); h8005.no_condition();
		h8006.no_condition(); h8007.no_condition(); h8008.no_condition(); h8009.no_condition(); h8010.no_condition();
		h8011.no_condition(); h8012.no_condition(); h8013.no_condition(); h8014.no_condition(); h8015.no_condition(); h8016.no_condition();

		h9001.no_condition(); h9002.no_condition(); h9003.no_condition(); h9004.no_condition(); h9005.no_condition();
		h9006.no_condition(); h9007.no_condition(); h9008.no_condition(); h9009.no_condition(); h9010.no_condition();
		h9011.no_condition(); h9012.no_condition(); h9013.no_condition(); h9014.no_condition(); h9015.no_condition(); h9016.no_condition();
	}




	while (inn != 19)
	{


		if (inn % 2 == 1)
		{
			home_score = 0;

			for (int i = 0; i < 9; i++) // Ȩ���� �̱���ִ���, �����ִ��� �Ǵ�
			{
				home_score += scoreboard[0][i];
				home_score -= scoreboard[1][i];
			}

			if (homepitcher_change == true) // �������� ��ü �� ���� ���带 ���״��� (�������� �¸��� ��������)
				if (home_score <= away_score)
					hometeam_lead = false;


			if (awaypitcher_change == true)
				if (home_score > away_score)
					awayteam_lead = false;

			home_score = 0;
		}




		i = (inn + 1) % 2;
		j = (inn - 1) / 2;


		if (sim == 2) {




			//cur(0, 7); cout << "                                                                                                                                                                                 ";

			cur(45, 11); cout << "���������������������������������������������������������������������������������������� ";
			cur(45, 12); cout << "��                                          �� ";
			cur(45, 13); cout << "��                                          �� ";
			cur(45, 14); cout << "��                                          �� ";
			cur(45, 15); cout << "��                                          �� ";
			cur(45, 16); cout << "��                                          �� ";
			cur(45, 17); cout << "���������������������������������������������������������������������������������������� ";

			for (int i = 19; i <= 50; i++) // ĭ �����
			{
				cur(44, i); cout << "                                              ";
			}

		}

		battlecount = -1;


		while (out != 3)
		{


			if (sim == 2)
			{
				if (act(9999) == 8 || (act(9999) == 13 && pitcher_change <= 1)) // ����Ű
				{
					if (act(9999) == 13 && pitcher_change <= 1)
					{
						pitcher_change++;
						h_hp = 0;
					}

					else  // �齺���̽�
					{
						print_hitter_record(**total_gam, a.tn_(), true, true, a_player);

						cur(45, 11); cout << "���������������������������������������������������������������������������������������� ";
						cur(45, 12); cout << "��                                          �� ";
						cur(45, 13); cout << "��                                          �� ";
						cur(45, 14); cout << "��                                          �� ";
						cur(45, 15); cout << "��                                          �� ";
						cur(45, 16); cout << "��                                          �� ";
						cur(45, 17); cout << "���������������������������������������������������������������������������������������� ";

						for (int i = 19; i <= 50; i++) // ĭ �����
						{
							cur(44, i); cout << "                                              ";
						}
					}
				}



			}


			battlecount++; // 1��° Ÿ�� = 0, 2��° Ÿ�� = 1.....

			if (battlecount > 8)
			{
				battlecount = 0;

				if (sim == 2)
				{
					for (int i = 19; i <= 50; i++) // ĭ �����
					{
						cur(44, i); cout << "                                              ";
					}
				}


			}


			home_score = 0;
			away_score = 0;




			if (h_hp <= 0)
			{


				if (sim == 2)
				{
					ppp.reset_pitching();
					cur(47, battlecount * 2 + 19); cout << right << setw(3) << fixed << " [ ������ü ] : "; ppp.print_name(); cout << "  -> ";

					cur(46, 14); //  ������ �ʱ�ȭ
					cout << "                  �� = 0      ";

				}



				home_score = 0;

				home_gap = 0;
				homepitcher_change = true;




				for (int i = 0; i < 9; i++)
				{
					home_gap += scoreboard[0][i];
					home_gap -= scoreboard[1][i];
				}

				for (int i = 0; i < 9; i++) // �������� �̱���ִ���, �����ִ��� �Ǵ�
				{
					home_score += scoreboard[0][i];
					home_score -= scoreboard[1][i];
				}

				if (home_score <= 0 || inn < 7) // 3�̴� �� ä�������
					homesp_lead = false;

				home_score = 0;

				// �̱���ִ��� �����ִ��Ŀ� ���� home_pitcher�� �� �߰�

				memcpy(&home_pitcher, &ppp, sizeof(class pitcher));

				switch (a.tn_()) {
				case 0:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p1, &ppp, sizeof(class pitcher)); break;
					case 1: memcpy(&p2, &ppp, sizeof(class pitcher)); break;
					case 2: memcpy(&p3, &ppp, sizeof(class pitcher)); break;
					case 3: memcpy(&p4, &ppp, sizeof(class pitcher)); break;
					case 4: memcpy(&p5, &ppp, sizeof(class pitcher)); break;

					}
					break;

				case 1:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p31, &ppp, sizeof(class pitcher)); break;
					case 1: memcpy(&p32, &ppp, sizeof(class pitcher)); break;
					case 2: memcpy(&p33, &ppp, sizeof(class pitcher)); break;
					case 3: memcpy(&p34, &ppp, sizeof(class pitcher)); break;
					case 4: memcpy(&p35, &ppp, sizeof(class pitcher)); break;

					}
					break;

				case 2:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p61, &ppp, sizeof(class pitcher)); break;
					case 1: memcpy(&p62, &ppp, sizeof(class pitcher)); break;
					case 2: memcpy(&p63, &ppp, sizeof(class pitcher)); break;
					case 3: memcpy(&p64, &ppp, sizeof(class pitcher)); break;
					case 4: memcpy(&p65, &ppp, sizeof(class pitcher)); break;

					}
					break;

				case 3:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p91, &ppp, sizeof(class pitcher)); break;
					case 1: memcpy(&p92, &ppp, sizeof(class pitcher)); break;
					case 2: memcpy(&p93, &ppp, sizeof(class pitcher)); break;
					case 3: memcpy(&p94, &ppp, sizeof(class pitcher)); break;
					case 4: memcpy(&p95, &ppp, sizeof(class pitcher)); break;

					}
					break;

				case 4:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p131, &ppp, sizeof(class pitcher)); break;
					case 1: memcpy(&p132, &ppp, sizeof(class pitcher)); break;
					case 2: memcpy(&p133, &ppp, sizeof(class pitcher)); break;
					case 3: memcpy(&p134, &ppp, sizeof(class pitcher)); break;
					case 4: memcpy(&p135, &ppp, sizeof(class pitcher)); break;

					}
					break;

				case 5:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p161, &ppp, sizeof(class pitcher)); break;
					case 1: memcpy(&p162, &ppp, sizeof(class pitcher)); break;
					case 2: memcpy(&p163, &ppp, sizeof(class pitcher)); break;
					case 3: memcpy(&p164, &ppp, sizeof(class pitcher)); break;
					case 4: memcpy(&p165, &ppp, sizeof(class pitcher)); break;

					}
					break;

				case 11:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p8001, &ppp, sizeof(class pitcher)); break;
					case 1: memcpy(&p8002, &ppp, sizeof(class pitcher)); break;
					case 2: memcpy(&p8003, &ppp, sizeof(class pitcher)); break;
					case 3: memcpy(&p8004, &ppp, sizeof(class pitcher)); break;
					case 4: memcpy(&p8005, &ppp, sizeof(class pitcher)); break;

					}
					break;

				case 12:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p9001, &ppp, sizeof(class pitcher)); break;
					case 1: memcpy(&p9002, &ppp, sizeof(class pitcher)); break;
					case 2: memcpy(&p9003, &ppp, sizeof(class pitcher)); break;
					case 3: memcpy(&p9004, &ppp, sizeof(class pitcher)); break;
					case 4: memcpy(&p9005, &ppp, sizeof(class pitcher)); break;

					}
					break;
				}

				if (home_randpitcher == 0) home_randpitcher = 1;
				else if (home_randpitcher == 1) home_randpitcher = 0; // �ߺ� ����

				if (home_randpitcher == -1) // ù ������ü�� ������, �ι�°�� ���� ������
					home_randpitcher = rand() % 2 + 0;



				// �ʽ��� �߰��� ����



				while (1)
				{
					if (home_gap < 3 && home_gap > -3)
					{
						switch (a.tn_()) {
						case 0:
							if (home_randpitcher == 0) memcpy(&ppp, &p6, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p7, sizeof(class pitcher));
							break;

						case 1:
							if (home_randpitcher == 0) memcpy(&ppp, &p36, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p37, sizeof(class pitcher));
							break;

						case 2:
							if (home_randpitcher == 0) memcpy(&ppp, &p66, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p67, sizeof(class pitcher));
							break;

						case 3:
							if (home_randpitcher == 0) memcpy(&ppp, &p96, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p97, sizeof(class pitcher));
							break;

						case 4:
							if (home_randpitcher == 0) memcpy(&ppp, &p136, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p137, sizeof(class pitcher));
							break;

						case 5:
							if (home_randpitcher == 0) memcpy(&ppp, &p166, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p167, sizeof(class pitcher));
							break;

						case 11:
							if (home_randpitcher == 0) memcpy(&ppp, &p8006, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p8007, sizeof(class pitcher));
							break;

						case 12:
							if (home_randpitcher == 0) memcpy(&ppp, &p9006, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p9007, sizeof(class pitcher));
							break;
						}

					}

					else
					{
						switch (a.tn_()) {
						case 0:
							if (home_randpitcher == 0) memcpy(&ppp, &p8, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p9, sizeof(class pitcher));
							break;

						case 1:
							if (home_randpitcher == 0) memcpy(&ppp, &p38, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p39, sizeof(class pitcher));
							break;

						case 2:
							if (home_randpitcher == 0) memcpy(&ppp, &p68, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p69, sizeof(class pitcher));
							break;

						case 3:
							if (home_randpitcher == 0) memcpy(&ppp, &p98, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p99, sizeof(class pitcher));
							break;

						case 4:
							if (home_randpitcher == 0) memcpy(&ppp, &p138, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p139, sizeof(class pitcher));
							break;

						case 5:
							if (home_randpitcher == 0) memcpy(&ppp, &p168, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p169, sizeof(class pitcher));
							break;

						case 11:
							if (home_randpitcher == 0) memcpy(&ppp, &p8008, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p8009, sizeof(class pitcher));
							break;

						case 12:
							if (home_randpitcher == 0) memcpy(&ppp, &p9008, sizeof(class pitcher));
							else if (home_randpitcher == 1) memcpy(&ppp, &p9009, sizeof(class pitcher));
							break;
						}
					}

					ppp.change_play_game();

					break;
				}











				h_hp = ppp.hprint_();

				if (sim == 2)
				{
					cur(75, battlecount * 2 + 19);
					ppp.print_name(); // ��ü�� ���� ����
					battlecount++;
				}


			}






			if (a_hp <= 0)
			{



				if (sim == 2)
				{

					pp.reset_pitching();
					cur(47, battlecount * 2 + 19); cout << right << setw(3) << fixed << " [ ������ü ] : "; pp.print_name(); cout << "  -> ";

					cur(46, 14);
					cout << "                  �� = 0     ";
				}

				away_gap = 0;
				awaypitcher_change = true;



				for (int i = 0; i < 9; i++)
				{
					away_gap += scoreboard[0][i];
					away_gap -= scoreboard[1][i];
				}



				for (int i = 0; i < 9; i++) // �������� �̱���ִ���, �����ִ��� �Ǵ�
				{
					home_score += scoreboard[0][i];
					home_score -= scoreboard[1][i];
				}

				if (home_score > 0 || inn < 7) // 3�̴� �� ä�������
					awaysp_lead = false;

				home_score = 0;





				memcpy(&away_pitcher, &pp, sizeof(class pitcher));




				switch (b.tn_()) {
				case 0:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p1, &pp, sizeof(class pitcher)); break;
					case 1: memcpy(&p2, &pp, sizeof(class pitcher)); break;
					case 2: memcpy(&p3, &pp, sizeof(class pitcher)); break;
					case 3: memcpy(&p4, &pp, sizeof(class pitcher)); break;
					case 4: memcpy(&p5, &pp, sizeof(class pitcher)); break;

					}
					break;

				case 1:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p31, &pp, sizeof(class pitcher)); break;
					case 1: memcpy(&p32, &pp, sizeof(class pitcher)); break;
					case 2: memcpy(&p33, &pp, sizeof(class pitcher)); break;
					case 3: memcpy(&p34, &pp, sizeof(class pitcher)); break;
					case 4: memcpy(&p35, &pp, sizeof(class pitcher)); break;

					}
					break;

				case 2:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p61, &pp, sizeof(class pitcher)); break;
					case 1: memcpy(&p62, &pp, sizeof(class pitcher)); break;
					case 2: memcpy(&p63, &pp, sizeof(class pitcher)); break;
					case 3: memcpy(&p64, &pp, sizeof(class pitcher)); break;
					case 4: memcpy(&p65, &pp, sizeof(class pitcher)); break;

					}
					break;

				case 3:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p91, &pp, sizeof(class pitcher)); break;
					case 1: memcpy(&p92, &pp, sizeof(class pitcher)); break;
					case 2: memcpy(&p93, &pp, sizeof(class pitcher)); break;
					case 3: memcpy(&p94, &pp, sizeof(class pitcher)); break;
					case 4: memcpy(&p95, &pp, sizeof(class pitcher)); break;

					}
					break;

				case 4:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p131, &pp, sizeof(class pitcher)); break;
					case 1: memcpy(&p132, &pp, sizeof(class pitcher)); break;
					case 2: memcpy(&p133, &pp, sizeof(class pitcher)); break;
					case 3: memcpy(&p134, &pp, sizeof(class pitcher)); break;
					case 4: memcpy(&p135, &pp, sizeof(class pitcher)); break;

					}
					break;

				case 5:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p161, &pp, sizeof(class pitcher)); break;
					case 1: memcpy(&p162, &pp, sizeof(class pitcher)); break;
					case 2: memcpy(&p163, &pp, sizeof(class pitcher)); break;
					case 3: memcpy(&p164, &pp, sizeof(class pitcher)); break;
					case 4: memcpy(&p165, &pp, sizeof(class pitcher)); break;

					}
					break;

				case 11:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p8001, &pp, sizeof(class pitcher)); break;
					case 1: memcpy(&p8002, &pp, sizeof(class pitcher)); break;
					case 2: memcpy(&p8003, &pp, sizeof(class pitcher)); break;
					case 3: memcpy(&p8004, &pp, sizeof(class pitcher)); break;
					case 4: memcpy(&p8005, &pp, sizeof(class pitcher)); break;

					}
					break;

				case 12:
					switch (**total_gam % 5)
					{
					case 0: memcpy(&p9001, &pp, sizeof(class pitcher)); break;
					case 1: memcpy(&p9002, &pp, sizeof(class pitcher)); break;
					case 2: memcpy(&p9003, &pp, sizeof(class pitcher)); break;
					case 3: memcpy(&p9004, &pp, sizeof(class pitcher)); break;
					case 4: memcpy(&p9005, &pp, sizeof(class pitcher)); break;

					}
					break;
				}

				away_randpitcher = rand() % 2 + 0;

				if (away_gap < 3 && away_gap > -3)
				{
					switch (b.tn_()) {
					case 0:
						if (away_randpitcher == 0) memcpy(&pp, &p6, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p7, sizeof(class pitcher));
						break;

					case 1:
						if (away_randpitcher == 0) memcpy(&pp, &p36, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p37, sizeof(class pitcher));
						break;

					case 2:
						if (away_randpitcher == 0) memcpy(&pp, &p66, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p67, sizeof(class pitcher));
						break;

					case 3:
						if (away_randpitcher == 0) memcpy(&pp, &p96, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p97, sizeof(class pitcher));
						break;

					case 4:
						if (away_randpitcher == 0) memcpy(&pp, &p136, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p137, sizeof(class pitcher));
						break;

					case 5:
						if (away_randpitcher == 0) memcpy(&pp, &p166, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p167, sizeof(class pitcher));
						break;

					case 11:
						if (away_randpitcher == 0) memcpy(&pp, &p8006, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p8007, sizeof(class pitcher));
						break;

					case 12:
						if (away_randpitcher == 0) memcpy(&pp, &p9006, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p9007, sizeof(class pitcher));
						break;
					}
				}

				else
				{
					switch (b.tn_()) {
					case 0:
						if (away_randpitcher == 0) memcpy(&pp, &p8, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p9, sizeof(class pitcher));
						break;

					case 1:
						if (away_randpitcher == 0) memcpy(&pp, &p38, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p39, sizeof(class pitcher));
						break;

					case 2:
						if (away_randpitcher == 0) memcpy(&pp, &p68, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p69, sizeof(class pitcher));
						break;

					case 3:
						if (away_randpitcher == 0) memcpy(&pp, &p98, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p99, sizeof(class pitcher));
						break;

					case 4:
						if (away_randpitcher == 0) memcpy(&pp, &p138, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p139, sizeof(class pitcher));
						break;

					case 5:
						if (away_randpitcher == 0) memcpy(&pp, &p168, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p169, sizeof(class pitcher));
						break;

					case 11:
						if (away_randpitcher == 0) memcpy(&pp, &p8008, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p8009, sizeof(class pitcher));
						break;

					case 12:
						if (away_randpitcher == 0) memcpy(&pp, &p9008, sizeof(class pitcher));
						else if (away_randpitcher == 1) memcpy(&pp, &p9009, sizeof(class pitcher));
						break;
					}
				}

				pp.change_play_game();

				a_hp = pp.hprint_();

				if (sim == 2)
				{
					cur(75, battlecount * 2 + 19);
					pp.print_name(); // ��ü�� ���� ����
					battlecount++;
				}
			}




			if (sim == 2) {


				cur(25, 1); cout << ("����������������������������������������������������������������������������������������������������������������������������������������������������������   ");
				cur(25, 2); cout << ("��      [1] [2] [3] [4] [5] [6] [7] [8] [9]  ��  [R]  [H]  [B]                ��  ");
				cur(25, 3); cout << ("��       "); //names(i);

				for (int b = 0; b < 9; b++) {
					if (inn == b * 2 + 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					if (scoreboard[0][b] > 9) {
						printf("X   ");
					}
					else
						printf("%d   ", scoreboard[0][b]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}





				printf("��                               ��\n");

				cur(25, 4);
				printf("��       ");


				for (int b = 0; b < 9; b++) {
					if (inn == b * 2 + 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					if (scoreboard[1][b] > 9) {
						printf("X   ");
					}
					else
						printf("%d   ", scoreboard[1][b]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}





				printf("��                               ��\n");


				cur(25, 5); cout << ("����������������������������������������������������������������������������������������������������������������������������������������������������������       ") << '\n';

				cur(73, 3);
				for (int i = 0; i < 9; i++) home_score += scoreboard[0][i];
				cout << home_score;

				cur(73, 4);
				for (int i = 0; i < 9; i++) away_score += scoreboard[1][i];
				cout << away_score;

				cur(78, 3);	cout << scoreboard[0][12];
				cur(78, 4);	cout << scoreboard[1][12];

				cur(83, 3);	cout << scoreboard[0][18];
				cur(83, 4);	cout << scoreboard[1][18];


				cur(27, 3);

				showteam(a, inn, 0);

				cur(27, 4);

				showteam(b, inn, 0);


			}




			if (sim == 2)
			{

				if (sound == 1) // ����Ʈ ��� �� �Ҹ� �����ִٸ� ���
				{
					if (SND_SENTRY == false)
						PlaySound(TEXT("cheer.wav"), NULL, SND_ASYNC | SND_LOOP);
				}

				switch (a.tn_())
				{
				case 0:
					cur(0, 10);
					h1.print(out, 4); // out�� ������ �������.
					h2.print(out, 4);
					h3.print(out, 4);
					h4.print(out, 4);
					h5.print(out, 4);
					h6.print(out, 4);
					h7.print(out, 4);
					h8.print(out, 4);
					h9.print(out, 4);
					h10.print(out, 4);
					h11.print(out, 4);
					h12.print(out, 4);
					h13.print(out, 4);
					h14.print(out, 4);
					h15.print(out, 4);
					h16.print(out, 4);

					break;

				case 1:
					cur(0, 10);
					h31.print(out, 4); // out�� ������ �������.
					h32.print(out, 4);
					h33.print(out, 4);
					h34.print(out, 4);
					h35.print(out, 4);
					h36.print(out, 4);
					h37.print(out, 4);
					h38.print(out, 4);
					h39.print(out, 4);
					h40.print(out, 4);
					h41.print(out, 4);
					h42.print(out, 4);
					h43.print(out, 4);
					h44.print(out, 4);
					h45.print(out, 4);
					h46.print(out, 4);

					break;

				case 2:
					cur(0, 10);
					h61.print(out, 4); // out�� ������ �������.
					h62.print(out, 4);
					h63.print(out, 4);
					h64.print(out, 4);
					h65.print(out, 4);
					h66.print(out, 4);
					h67.print(out, 4);
					h68.print(out, 4);
					h69.print(out, 4);
					h70.print(out, 4);
					h71.print(out, 4);
					h72.print(out, 4);
					h73.print(out, 4);
					h74.print(out, 4);
					h75.print(out, 4);
					h76.print(out, 4);

					break;

				case 3:
					cur(0, 10);
					h91.print(out, 4); // out�� ������ �������.
					h92.print(out, 4);
					h93.print(out, 4);
					h94.print(out, 4);
					h95.print(out, 4);
					h96.print(out, 4);
					h97.print(out, 4);
					h98.print(out, 4);
					h99.print(out, 4);
					h100.print(out, 4);
					h101.print(out, 4);
					h102.print(out, 4);
					h103.print(out, 4);
					h104.print(out, 4);
					h105.print(out, 4);
					h106.print(out, 4);

					break;

				case 4:
					cur(0, 10);
					h131.print(out, 4); // out�� ������ �������.
					h132.print(out, 4);
					h133.print(out, 4);
					h134.print(out, 4);
					h135.print(out, 4);
					h136.print(out, 4);
					h137.print(out, 4);
					h138.print(out, 4);
					h139.print(out, 4);
					h140.print(out, 4);
					h141.print(out, 4);
					h142.print(out, 4);
					h143.print(out, 4);
					h144.print(out, 4);
					h145.print(out, 4);
					h146.print(out, 4);

					break;

				case 5:
					cur(0, 10);
					h161.print(out, 4); // out�� ������ �������.
					h162.print(out, 4);
					h163.print(out, 4);
					h164.print(out, 4);
					h165.print(out, 4);
					h166.print(out, 4);
					h167.print(out, 4);
					h168.print(out, 4);
					h169.print(out, 4);
					h170.print(out, 4);
					h171.print(out, 4);
					h172.print(out, 4);
					h173.print(out, 4);
					h174.print(out, 4);
					h175.print(out, 4);
					h176.print(out, 4);

					break;

				case 11:
					cur(0, 10);
					h8001.print(out, 4); // out�� ������ �������.
					h8002.print(out, 4);
					h8003.print(out, 4);
					h8004.print(out, 4);
					h8005.print(out, 4);
					h8006.print(out, 4);
					h8007.print(out, 4);
					h8008.print(out, 4);
					h8009.print(out, 4);
					h8010.print(out, 4);
					h8011.print(out, 4);
					h8012.print(out, 4);
					h8013.print(out, 4);
					h8014.print(out, 4);
					h8015.print(out, 4);
					h8016.print(out, 4);

					break;

				case 12:
					cur(0, 10);
					h9001.print(out, 4); // out�� ������ �������.
					h9002.print(out, 4);
					h9003.print(out, 4);
					h9004.print(out, 4);
					h9005.print(out, 4);
					h9006.print(out, 4);
					h9007.print(out, 4);
					h9008.print(out, 4);
					h9009.print(out, 4);
					h9010.print(out, 4);
					h9011.print(out, 4);
					h9012.print(out, 4);
					h9013.print(out, 4);
					h9014.print(out, 4);
					h9015.print(out, 4);
					h9016.print(out, 4);

					break;
				}

				switch (b.tn_()) {
				case 0:
					cur(90, 10); h1.print(out, 4);
					cur(90, 12); h2.print(out, 4);
					cur(90, 14); h3.print(out, 4);
					cur(90, 16); h4.print(out, 4);
					cur(90, 18); h5.print(out, 4);
					cur(90, 20); h6.print(out, 4);
					cur(90, 22); h7.print(out, 4);
					cur(90, 24); h8.print(out, 4);
					cur(90, 26); h9.print(out, 4);
					cur(90, 28); h10.print(out, 4);
					cur(90, 30); h11.print(out, 4);
					cur(90, 32); h12.print(out, 4);
					cur(90, 34); h13.print(out, 4);
					cur(90, 36); h14.print(out, 4);
					cur(90, 38); h15.print(out, 4);
					cur(90, 40); h16.print(out, 4);
					break;

				case 1:
					cur(90, 10); h31.print(out, 4);
					cur(90, 12); h32.print(out, 4);
					cur(90, 14); h33.print(out, 4);
					cur(90, 16); h34.print(out, 4);
					cur(90, 18); h35.print(out, 4);
					cur(90, 20); h36.print(out, 4);
					cur(90, 22); h37.print(out, 4);
					cur(90, 24); h38.print(out, 4);
					cur(90, 26); h39.print(out, 4);
					cur(90, 28); h40.print(out, 4);
					cur(90, 30); h41.print(out, 4);
					cur(90, 32); h42.print(out, 4);
					cur(90, 34); h43.print(out, 4);
					cur(90, 36); h44.print(out, 4);
					cur(90, 38); h45.print(out, 4);
					cur(90, 40); h46.print(out, 4);
					break;

				case 2:
					cur(90, 10); h61.print(out, 4);
					cur(90, 12); h62.print(out, 4);
					cur(90, 14); h63.print(out, 4);
					cur(90, 16); h64.print(out, 4);
					cur(90, 18); h65.print(out, 4);
					cur(90, 20); h66.print(out, 4);
					cur(90, 22); h67.print(out, 4);
					cur(90, 24); h68.print(out, 4);
					cur(90, 26); h69.print(out, 4);
					cur(90, 28); h70.print(out, 4);
					cur(90, 30); h71.print(out, 4);
					cur(90, 32); h72.print(out, 4);
					cur(90, 34); h73.print(out, 4);
					cur(90, 36); h74.print(out, 4);
					cur(90, 38); h75.print(out, 4);
					cur(90, 40); h76.print(out, 4);
					break;

				case 3:
					cur(90, 10); h91.print(out, 4);
					cur(90, 12); h92.print(out, 4);
					cur(90, 14); h93.print(out, 4);
					cur(90, 16); h94.print(out, 4);
					cur(90, 18); h95.print(out, 4);
					cur(90, 20); h96.print(out, 4);
					cur(90, 22); h97.print(out, 4);
					cur(90, 24); h98.print(out, 4);
					cur(90, 26); h99.print(out, 4);
					cur(90, 28); h100.print(out, 4);
					cur(90, 30); h101.print(out, 4);
					cur(90, 32); h102.print(out, 4);
					cur(90, 34); h103.print(out, 4);
					cur(90, 36); h104.print(out, 4);
					cur(90, 38); h105.print(out, 4);
					cur(90, 40); h106.print(out, 4);
					break;

				case 4:
					cur(90, 10); h131.print(out, 4);
					cur(90, 12); h132.print(out, 4);
					cur(90, 14); h133.print(out, 4);
					cur(90, 16); h134.print(out, 4);
					cur(90, 18); h135.print(out, 4);
					cur(90, 20); h136.print(out, 4);
					cur(90, 22); h137.print(out, 4);
					cur(90, 24); h138.print(out, 4);
					cur(90, 26); h139.print(out, 4);
					cur(90, 28); h140.print(out, 4);
					cur(90, 30); h141.print(out, 4);
					cur(90, 32); h142.print(out, 4);
					cur(90, 34); h143.print(out, 4);
					cur(90, 36); h144.print(out, 4);
					cur(90, 38); h145.print(out, 4);
					cur(90, 40); h146.print(out, 4);
					break;

				case 5:
					cur(90, 10); h161.print(out, 4);
					cur(90, 12); h162.print(out, 4);
					cur(90, 14); h163.print(out, 4);
					cur(90, 16); h164.print(out, 4);
					cur(90, 18); h165.print(out, 4);
					cur(90, 20); h166.print(out, 4);
					cur(90, 22); h167.print(out, 4);
					cur(90, 24); h168.print(out, 4);
					cur(90, 26); h169.print(out, 4);
					cur(90, 28); h170.print(out, 4);
					cur(90, 30); h171.print(out, 4);
					cur(90, 32); h172.print(out, 4);
					cur(90, 34); h173.print(out, 4);
					cur(90, 36); h174.print(out, 4);
					cur(90, 38); h175.print(out, 4);
					cur(90, 40); h176.print(out, 4);
					break;

				case 11:
					cur(90, 10); h8001.print(out, 4);
					cur(90, 12); h8002.print(out, 4);
					cur(90, 14); h8003.print(out, 4);
					cur(90, 16); h8004.print(out, 4);
					cur(90, 18); h8005.print(out, 4);
					cur(90, 20); h8006.print(out, 4);
					cur(90, 22); h8007.print(out, 4);
					cur(90, 24); h8008.print(out, 4);
					cur(90, 26); h8009.print(out, 4);
					cur(90, 28); h8010.print(out, 4);
					cur(90, 30); h8011.print(out, 4);
					cur(90, 32); h8012.print(out, 4);
					cur(90, 34); h8013.print(out, 4);
					cur(90, 36); h8014.print(out, 4);
					cur(90, 38); h8015.print(out, 4);
					cur(90, 40); h8016.print(out, 4);
					break;

				case 12:
					cur(90, 10); h9001.print(out, 4);
					cur(90, 12); h9002.print(out, 4);
					cur(90, 14); h9003.print(out, 4);
					cur(90, 16); h9004.print(out, 4);
					cur(90, 18); h9005.print(out, 4);
					cur(90, 20); h9006.print(out, 4);
					cur(90, 22); h9007.print(out, 4);
					cur(90, 24); h9008.print(out, 4);
					cur(90, 26); h9009.print(out, 4);
					cur(90, 28); h9010.print(out, 4);
					cur(90, 30); h9011.print(out, 4);
					cur(90, 32); h9012.print(out, 4);
					cur(90, 34); h9013.print(out, 4);
					cur(90, 36); h9014.print(out, 4);
					cur(90, 38); h9015.print(out, 4);
					cur(90, 40); h9016.print(out, 4);
					break;
				}



				if (a_player == 9) // ���� ���� �� ȿ��
				{

					for (int i = 19; i <= 30; i++) // ĭ �����
					{
						cur(44, i); cout << "                                              ";
					}

					gamestart();

					cur(46, 13); showteam(a, inn, 1);

					cur(66, 13); cout << "vs";

					cur(69, 13); showteam(b, inn, 1);

					cur(58, 15); cout << "[ ���Ը��� " << **total_gam + 1 << "���� ]";


					cur(60, 19); cout << "[ �ֱ�  ��� ]";
					cur(47, 19); a.s_recent();
					cur(76, 19); b.s_recent();

					cur(60, 21); cout << "[  ��  Ÿ��  ]";

					cur(52, 21);
					if (**total_gam == 0) cout << "0.000";
					else a.show_hit(2);

					cur(77, 21);
					if (**total_gam == 0) cout << "0.000";
					else b.show_hit(2);




					cur(60, 24); cout << "[  ��������  ]";
					cur(52, 24); ppp.print_name();
					cur(76, 24); pp.print_name();


					cur(60, 26); cout << "[ �����å�� ]";
					cur(53, 26); ppp.print_los();
					cur(77, 26); pp.print_los();

					cur(60, 28); cout << "[   ��  ��   ]";
					cur(48, 28); ppp.print_winlose(0);
					cur(77, 28); pp.print_winlose(1);

					cur(60, 30); cout << "[    WHIP    ]";
					cur(53, 30); ppp.print_whip();
					cur(77, 30); pp.print_whip();






					cur(0, 0); cout << "                          ";



					if (game_speed > 1)
					{
						Sleep(1500);

						if (game_speed == 2)
						{
							for (int i = 3; i >= 0; i--)
							{
								cur(52, 34); cout << "[  " << i << "�� �� ��Ⱑ ���۵˴ϴ�  ]";
								Sleep(1000);
							}
						}

						else if (game_speed == 5)
						{
							Sleep(2500);
							for (int i = 5; i >= 0; i--)
							{
								cur(52, 34); cout << "[  " << i << "�� �� ��Ⱑ ���۵˴ϴ�  ]";
								Sleep(1000);
							}
						}

						else if (game_speed > 2)
						{
							for (int i = 5; i >= 0; i--)
							{
								cur(52, 34); cout << "[  " << i << "�� �� ��Ⱑ ���۵˴ϴ�  ]";
								Sleep(1000);
							}
						}

					}





					for (int i = 19; i <= 35; i++) // ĭ �����
					{
						cur(44, i); cout << "                                              ";
					}

				}
			}

			if (inn % 2 == 1) {

				switch (a.tn_())
				{
				case 0:
					switch (a_player % 9)
					{
					case 0: h1.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break; // �ƿ�ī��Ʈ Ȯ�� ����.
					case 1: h2.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 2: h3.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 3: h4.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 4: h5.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 5: h6.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 6: h7.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 7: h8.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 8: h9.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					}
					a_player += 1;
					break;

				case 1:
					switch (a_player % 9)
					{
					case 0: h31.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break; // �ƿ�ī��Ʈ Ȯ�� ����.
					case 1: h32.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 2: h33.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 3: h34.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 4: h35.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 5: h36.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 6: h37.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 7: h38.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 8: h39.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					}
					a_player += 1;
					break;

				case 2:
					switch (a_player % 9)
					{
					case 0: h61.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break; // �ƿ�ī��Ʈ Ȯ�� ����.
					case 1: h62.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 2: h63.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 3: h64.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 4: h65.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 5: h66.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 6: h67.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 7: h68.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 8: h69.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					}
					a_player += 1;
					break;

				case 3:
					switch (a_player % 9)
					{
					case 0: h91.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break; // �ƿ�ī��Ʈ Ȯ�� ����.
					case 1: h92.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 2: h93.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 3: h94.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 4: h95.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 5: h96.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 6: h97.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 7: h98.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 8: h99.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					}
					a_player += 1;
					break;

				case 4:
					switch (a_player % 9)
					{
					case 0: h131.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break; // �ƿ�ī��Ʈ Ȯ�� ����.
					case 1: h132.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 2: h133.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 3: h134.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 4: h135.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 5: h136.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 6: h137.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 7: h138.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 8: h139.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					}
					a_player += 1;
					break;

				case 5:
					switch (a_player % 9)
					{
					case 0: h161.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break; // �ƿ�ī��Ʈ Ȯ�� ����.
					case 1: h162.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 2: h163.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 3: h164.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 4: h165.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 5: h166.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 6: h167.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 7: h168.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 8: h169.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					}
					a_player += 1;
					break;

				case 11:
					switch (a_player % 9)
					{
					case 0: h8001.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break; // �ƿ�ī��Ʈ Ȯ�� ����.
					case 1: h8002.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 2: h8003.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 3: h8004.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 4: h8005.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 5: h8006.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 6: h8007.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 7: h8008.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 8: h8009.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					}
					a_player += 1;
					break;

				case 12:
					switch (a_player % 9)
					{
					case 0: h9001.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break; // �ƿ�ī��Ʈ Ȯ�� ����.
					case 1: h9002.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 2: h9003.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 3: h9004.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 4: h9005.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 5: h9006.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 6: h9007.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 7: h9008.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					case 8: h9009.battle(pp, &out, inn, &a_hp, battlecount, game_speed, sound); break;
					}
					a_player += 1;
					break;
				}

			}

			else {

				switch (b.tn_()) {
				case 0:
					switch (b_player % 9)
					{
					case 0: h1.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 1: h2.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 2: h3.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 3: h4.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 4: h5.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 5: h6.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 6: h7.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 7: h8.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 8: h9.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					}
					b_player += 1;
					break;

				case 1:
					switch (b_player % 9)
					{
					case 0: h31.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 1: h32.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 2: h33.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 3: h34.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 4: h35.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 5: h36.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 6: h37.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 7: h38.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 8: h39.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					}
					b_player += 1;
					break;

				case 2:
					switch (b_player % 9)
					{
					case 0: h61.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 1: h62.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 2: h63.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 3: h64.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 4: h65.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 5: h66.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 6: h67.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 7: h68.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 8: h69.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					}
					b_player += 1;
					break;

				case 3:
					switch (b_player % 9)
					{
					case 0: h91.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 1: h92.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 2: h93.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 3: h94.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 4: h95.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 5: h96.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 6: h97.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 7: h98.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 8: h99.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					}
					b_player += 1;
					break;

				case 4:
					switch (b_player % 9)
					{
					case 0: h131.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 1: h132.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 2: h133.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 3: h134.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 4: h135.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 5: h136.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 6: h137.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 7: h138.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 8: h139.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					}
					b_player += 1;
					break;

				case 5:
					switch (b_player % 9)
					{
					case 0: h161.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 1: h162.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 2: h163.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 3: h164.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 4: h165.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 5: h166.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 6: h167.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 7: h168.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 8: h169.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					}
					b_player += 1;
					break;

				case 11:
					switch (b_player % 9)
					{
					case 0: h8001.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 1: h8002.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 2: h8003.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 3: h8004.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 4: h8005.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 5: h8006.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 6: h8007.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 7: h8008.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 8: h8009.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					}
					b_player += 1;
					break;

				case 12:
					switch (b_player % 9)
					{
					case 0: h9001.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 1: h9002.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 2: h9003.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 3: h9004.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 4: h9005.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 5: h9006.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 6: h9007.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 7: h9008.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					case 8: h9009.battle(ppp, &out, inn, &h_hp, battlecount, game_speed, sound); break;
					}
					b_player += 1;
					break;
				}


			}


			home_score = 0;
			away_score = 0;

			for (int i = 0; i < 9; i++) home_score += scoreboard[0][i];
			for (int i = 0; i < 9; i++) away_score += scoreboard[1][i];

			if (inn == 18 && home_score < away_score) {
				out = 3;
				break;
			}

			Base.change_base(0);




		}



		if (out == 3) {
			Base.ch(); // ���̽� �ʱ�ȭ
			inn += 1;
			if (inn == 18 && home_score < away_score) inn += 1;
			out = 0;

			if (sim == 2)
			{
				battlecount *= 2;
				battlecount += 21;
				cur(48, battlecount + 1);
				cout << "[ 3�ƿ�  - ";
				if (inn != 19)
				{
					cout << "�������� ]";

					if (game_speed == 1) Sleep(500);
					else if (game_speed == 2) Sleep(1000);
					else Sleep(1500);
				}
				else
				{
					cout << "��� ���� ]";


				}


			}
		}


	}



	// 9ȸ������ ���� ���� ����

	//if (home_score > away_score)	awaysp_lead = false;
	//else if (away_score > home_score)		homesp_lead = false;

	// ���� ����� ����



	if (sim >= 2)
	{
		change(-10, my_team, false); // ���� �� ������ü �ʱ�ȭ
		ppp.reset_pitching();
		pp.reset_pitching();
	}

	if (homepitcher_change == true) // �������� ��ü �� ���� ���带 ���״��� (�������� �¸��� ��������)
		if (home_score <= away_score)
			hometeam_lead = false;


	if (awaypitcher_change == true)
		if (home_score > away_score)
			awayteam_lead = false;



	if (homepitcher_change == false) { // ���������� ������ ����



		if (home_score > away_score) // Ȩ�� ������ ���ٸ� �¸� �߰�
		{
			ppp.pitcher_result(true);

			if (a.tn_() == my_team && sim == 2)
			{
				cur(48, battlecount + 3);
				cout << "[ �¸� ���� ] : ";
				ppp.print_name();
			}

		}


		else if (home_score < away_score) // Ȩ�� ������ ���ٸ� �й� �߰�
		{
			ppp.pitcher_result(false);

			if (a.tn_() == my_team && sim == 2)
			{
				cur(48, battlecount + 5);
				cout << "[ �й� ���� ] : ";
				ppp.print_name();
			}

		}


		switch (a.tn_()) {
		case 0:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p1, &ppp, sizeof(class pitcher)); break;
			case 1: memcpy(&p2, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p3, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p4, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p5, &ppp, sizeof(class pitcher)); break;

			}
			break;

		case 1:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p31, &ppp, sizeof(class pitcher)); break;
			case 1: memcpy(&p32, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p33, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p34, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p35, &ppp, sizeof(class pitcher)); break;

			}
			break;

		case 2:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p61, &ppp, sizeof(class pitcher)); break;
			case 1: memcpy(&p62, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p63, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p64, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p65, &ppp, sizeof(class pitcher)); break;

			}
			break;

		case 3:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p91, &ppp, sizeof(class pitcher)); break;
			case 1: memcpy(&p92, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p93, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p94, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p95, &ppp, sizeof(class pitcher)); break;

			}
			break;

		case 4:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p131, &ppp, sizeof(class pitcher)); break;
			case 1: memcpy(&p132, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p133, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p134, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p135, &ppp, sizeof(class pitcher)); break;

			}
			break;

		case 5:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p161, &ppp, sizeof(class pitcher)); break;
			case 1: memcpy(&p162, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p163, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p164, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p165, &ppp, sizeof(class pitcher)); break;

			}
			break;

		case 11:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p8001, &ppp, sizeof(class pitcher)); break;
			case 1: memcpy(&p8002, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p8003, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p8004, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p8005, &ppp, sizeof(class pitcher)); break;

			}
			break;

		case 12:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p9001, &ppp, sizeof(class pitcher)); break;
			case 1: memcpy(&p9002, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p9003, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p9004, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p9005, &ppp, sizeof(class pitcher)); break;

			}
			break;
		}
	}

	if (homepitcher_change == true) { // ������ü�� �̷�����ٸ�



		if (homesp_lead == false && home_score > away_score)
		{
			ppp.pitcher_result(true);

			if (a.tn_() == my_team && sim == 2)
			{
				cur(48, battlecount + 3);
				cout << "[ �¸� ���� ] : ";
				ppp.print_name();
			}

		}


		else if (homesp_lead == true && home_score < away_score)
		{
			ppp.pitcher_result(false);

			if (a.tn_() == my_team && sim == 2)
			{
				cur(48, battlecount + 5);
				cout << "[ �й� ���� ] : ";
				ppp.print_name();
			}

		}



		else if (home_score > away_score || home_score < away_score) // ���������� �¸���� ���� �� �¸�, �Ҹ��� �� �й� (���ºδ� ������� ����)
		{

			if (home_score > away_score)
			{
				home_pitcher.pitcher_result(true);

				if (a.tn_() == my_team && sim == 2)
				{
					cur(48, battlecount + 3);
					cout << "[ �¸� ���� ] : ";
					home_pitcher.print_name();
				}

			}

			if (home_score < away_score)
			{
				home_pitcher.pitcher_result(false);

				if (a.tn_() == my_team && sim == 2)
				{
					cur(48, battlecount + 5);
					cout << "[ �й� ���� ] : ";
					home_pitcher.print_name();
				}

			}



			switch (a.tn_()) {
			case 0:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p1, &home_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p2, &home_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p3, &home_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p4, &home_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p5, &home_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 1:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p31, &home_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p32, &home_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p33, &home_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p34, &home_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p35, &home_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 2:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p61, &home_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p62, &home_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p63, &home_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p64, &home_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p65, &home_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 3:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p91, &home_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p92, &home_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p93, &home_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p94, &home_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p95, &home_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 4:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p131, &home_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p132, &home_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p133, &home_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p134, &home_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p135, &home_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 5:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p161, &home_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p162, &home_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p163, &home_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p164, &home_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p165, &home_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 11:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p8001, &home_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p8002, &home_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p8003, &home_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p8004, &home_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p8005, &home_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 12:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p9001, &home_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p9002, &home_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p9003, &home_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p9004, &home_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p9005, &home_pitcher, sizeof(class pitcher)); break;

				}
				break;
			}
		}




		if (home_gap < 3 && home_gap > -3)
		{
			switch (a.tn_()) {
			case 0:
				if (home_randpitcher == 0) memcpy(&p6, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p7, &ppp, sizeof(class pitcher));
				break;

			case 1:
				if (home_randpitcher == 0) memcpy(&p36, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p37, &ppp, sizeof(class pitcher));
				break;

			case 2:
				if (home_randpitcher == 0) memcpy(&p66, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p67, &ppp, sizeof(class pitcher));
				break;

			case 3:
				if (home_randpitcher == 0) memcpy(&p96, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p97, &ppp, sizeof(class pitcher));
				break;

			case 4:
				if (home_randpitcher == 0) memcpy(&p136, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p137, &ppp, sizeof(class pitcher));
				break;

			case 5:
				if (home_randpitcher == 0) memcpy(&p166, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p167, &ppp, sizeof(class pitcher));
				break;

			case 11:
				if (home_randpitcher == 0) memcpy(&p8006, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p8007, &ppp, sizeof(class pitcher));
				break;

			case 12:
				if (home_randpitcher == 0) memcpy(&p9006, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p9007, &ppp, sizeof(class pitcher));
				break;
			}
		}

		else
		{
			switch (a.tn_()) {
			case 0:
				if (home_randpitcher == 0) memcpy(&p8, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p9, &ppp, sizeof(class pitcher));
				break;

			case 1:
				if (home_randpitcher == 0) memcpy(&p38, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p39, &ppp, sizeof(class pitcher));
				break;

			case 2:
				if (home_randpitcher == 0) memcpy(&p68, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p69, &ppp, sizeof(class pitcher));
				break;

			case 3:
				if (home_randpitcher == 0) memcpy(&p98, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p99, &ppp, sizeof(class pitcher));
				break;

			case 4:
				if (home_randpitcher == 0) memcpy(&p138, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p139, &ppp, sizeof(class pitcher));
				break;

			case 5:
				if (home_randpitcher == 0) memcpy(&p168, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p169, &ppp, sizeof(class pitcher));
				break;

			case 11:
				if (home_randpitcher == 0) memcpy(&p8008, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p8009, &ppp, sizeof(class pitcher));
				break;

			case 12:
				if (home_randpitcher == 0) memcpy(&p9008, &ppp, sizeof(class pitcher));
				else if (home_randpitcher == 1) memcpy(&p9009, &ppp, sizeof(class pitcher));
				break;
			}
		}

	}

	if (awaypitcher_change == false) { // ���� �������� ����

		if (away_score > home_score)
		{
			pp.pitcher_result(true);

			if (a.tn_() == my_team && sim == 2)
			{
				cur(48, battlecount + 3);
				cout << "[ �¸� ���� ] : ";
				pp.print_name();
			}

		}
		else if (away_score < home_score)
		{
			pp.pitcher_result(false);

			if (a.tn_() == my_team && sim == 2)
			{
				cur(48, battlecount + 5);
				cout << "[ �й� ���� ] : ";
				pp.print_name();
			}

		}

		switch (b.tn_()) {
		case 0:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p1, &pp, sizeof(class pitcher)); break;
			case 1: memcpy(&p2, &pp, sizeof(class pitcher)); break;
			case 2: memcpy(&p3, &pp, sizeof(class pitcher)); break;
			case 3: memcpy(&p4, &pp, sizeof(class pitcher)); break;
			case 4: memcpy(&p5, &pp, sizeof(class pitcher)); break;

			}
			break;

		case 1:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p31, &pp, sizeof(class pitcher)); break;
			case 1: memcpy(&p32, &pp, sizeof(class pitcher)); break;
			case 2: memcpy(&p33, &pp, sizeof(class pitcher)); break;
			case 3: memcpy(&p34, &pp, sizeof(class pitcher)); break;
			case 4: memcpy(&p35, &pp, sizeof(class pitcher)); break;

			}
			break;

		case 2:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p61, &pp, sizeof(class pitcher)); break;
			case 1: memcpy(&p62, &pp, sizeof(class pitcher)); break;
			case 2: memcpy(&p63, &pp, sizeof(class pitcher)); break;
			case 3: memcpy(&p64, &pp, sizeof(class pitcher)); break;
			case 4: memcpy(&p65, &pp, sizeof(class pitcher)); break;

			}
			break;

		case 3:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p91, &pp, sizeof(class pitcher)); break;
			case 1: memcpy(&p92, &pp, sizeof(class pitcher)); break;
			case 2: memcpy(&p93, &pp, sizeof(class pitcher)); break;
			case 3: memcpy(&p94, &pp, sizeof(class pitcher)); break;
			case 4: memcpy(&p95, &pp, sizeof(class pitcher)); break;

			}
			break;

		case 4:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p131, &pp, sizeof(class pitcher)); break;
			case 1: memcpy(&p132, &pp, sizeof(class pitcher)); break;
			case 2: memcpy(&p133, &pp, sizeof(class pitcher)); break;
			case 3: memcpy(&p134, &pp, sizeof(class pitcher)); break;
			case 4: memcpy(&p135, &pp, sizeof(class pitcher)); break;

			}
			break;

		case 5:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p161, &pp, sizeof(class pitcher)); break;
			case 1: memcpy(&p162, &pp, sizeof(class pitcher)); break;
			case 2: memcpy(&p163, &pp, sizeof(class pitcher)); break;
			case 3: memcpy(&p164, &pp, sizeof(class pitcher)); break;
			case 4: memcpy(&p165, &pp, sizeof(class pitcher)); break;

			}
			break;

		case 11:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p8001, &pp, sizeof(class pitcher)); break;
			case 1: memcpy(&p8002, &pp, sizeof(class pitcher)); break;
			case 2: memcpy(&p8003, &pp, sizeof(class pitcher)); break;
			case 3: memcpy(&p8004, &pp, sizeof(class pitcher)); break;
			case 4: memcpy(&p8005, &pp, sizeof(class pitcher)); break;

			}
			break;

		case 12:
			switch (**total_gam % 5)
			{
			case 0: memcpy(&p9001, &pp, sizeof(class pitcher)); break;
			case 1: memcpy(&p9002, &pp, sizeof(class pitcher)); break;
			case 2: memcpy(&p9003, &pp, sizeof(class pitcher)); break;
			case 3: memcpy(&p9004, &pp, sizeof(class pitcher)); break;
			case 4: memcpy(&p9005, &pp, sizeof(class pitcher)); break;

			}
			break;
		}
	}

	if (awaypitcher_change == true) { // ������ ���������� ��ü�� �� ����


		if (awaysp_lead == false && home_score < away_score)
		{
			pp.pitcher_result(true);

			if (a.tn_() == my_team && sim == 2)
			{
				cur(48, battlecount + 3);
				cout << "[ �¸� ���� ] : ";
				pp.print_name();
			}

		}

		else if (awaysp_lead == true && home_score > away_score)
		{
			pp.pitcher_result(false);

			if (a.tn_() == my_team && sim == 2)
			{
				cur(48, battlecount + 5);
				cout << "[ �й� ���� ] : ";
				pp.print_name();
			}

		}



		else if (home_score < away_score || home_score > away_score) // ���������� �¸���� ���� �� �¸�, �Ҹ��� �� �й� (���ºδ� ������� ����)
		{

			if (home_score < away_score)
			{
				away_pitcher.pitcher_result(true);

				if (a.tn_() == my_team && sim == 2)
				{
					cur(48, battlecount + 3);
					cout << "[ �¸� ���� ] : ";
					away_pitcher.print_name();
				}

			}
			if (home_score > away_score)
			{
				away_pitcher.pitcher_result(false);

				if (a.tn_() == my_team && sim == 2)
				{
					cur(48, battlecount + 5);
					cout << "[ �й� ���� ] : ";
					away_pitcher.print_name();
				}

			}

			switch (b.tn_()) {
			case 0:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p1, &away_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p2, &away_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p3, &away_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p4, &away_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p5, &away_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 1:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p31, &away_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p32, &away_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p33, &away_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p34, &away_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p35, &away_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 2:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p61, &away_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p62, &away_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p63, &away_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p64, &away_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p65, &away_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 3:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p91, &away_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p92, &away_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p93, &away_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p94, &away_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p95, &away_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 4:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p131, &away_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p132, &away_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p133, &away_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p134, &away_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p135, &away_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 5:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p161, &away_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p162, &away_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p163, &away_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p164, &away_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p165, &away_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 11:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p8001, &away_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p8002, &away_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p8003, &away_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p8004, &away_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p8005, &away_pitcher, sizeof(class pitcher)); break;

				}
				break;

			case 12:
				switch (**total_gam % 5)
				{
				case 0: memcpy(&p9001, &away_pitcher, sizeof(class pitcher)); break;
				case 1: memcpy(&p9002, &away_pitcher, sizeof(class pitcher)); break;
				case 2: memcpy(&p9003, &away_pitcher, sizeof(class pitcher)); break;
				case 3: memcpy(&p9004, &away_pitcher, sizeof(class pitcher)); break;
				case 4: memcpy(&p9005, &away_pitcher, sizeof(class pitcher)); break;

				}
				break;
			}
		}

		if (away_gap < 3 && away_gap > -3)
		{
			switch (b.tn_()) {
			case 0:
				if (away_randpitcher == 0) memcpy(&p6, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p7, &pp, sizeof(class pitcher));
				break;

			case 1:
				if (away_randpitcher == 0) memcpy(&p36, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p37, &pp, sizeof(class pitcher));
				break;

			case 2:
				if (away_randpitcher == 0) memcpy(&p66, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p67, &pp, sizeof(class pitcher));
				break;

			case 3:
				if (away_randpitcher == 0) memcpy(&p96, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p97, &pp, sizeof(class pitcher));
				break;

			case 4:
				if (away_randpitcher == 0) memcpy(&p136, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p137, &pp, sizeof(class pitcher));
				break;

			case 5:
				if (away_randpitcher == 0) memcpy(&p166, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p167, &pp, sizeof(class pitcher));
				break;

			case 11:
				if (away_randpitcher == 0) memcpy(&p8006, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p8007, &pp, sizeof(class pitcher));
				break;

			case 12:
				if (away_randpitcher == 0) memcpy(&p9006, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p9007, &pp, sizeof(class pitcher));
				break;
			}
		}

		else
		{
			switch (b.tn_()) {
			case 0:
				if (away_randpitcher == 0) memcpy(&p8, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p9, &pp, sizeof(class pitcher));
				break;

			case 1:
				if (away_randpitcher == 0) memcpy(&p38, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p39, &pp, sizeof(class pitcher));
				break;

			case 2:
				if (away_randpitcher == 0) memcpy(&p68, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p69, &pp, sizeof(class pitcher));
				break;

			case 3:
				if (away_randpitcher == 0) memcpy(&p98, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p99, &pp, sizeof(class pitcher));
				break;

			case 4:
				if (away_randpitcher == 0) memcpy(&p138, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p139, &pp, sizeof(class pitcher));
				break;

			case 5:
				if (away_randpitcher == 0) memcpy(&p168, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p169, &pp, sizeof(class pitcher));
				break;

			case 11:
				if (away_randpitcher == 0) memcpy(&p8008, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p8009, &pp, sizeof(class pitcher));
				break;

			case 12:
				if (away_randpitcher == 0) memcpy(&p9008, &pp, sizeof(class pitcher));
				else if (away_randpitcher == 1) memcpy(&p9009, &pp, sizeof(class pitcher));
				break;
			}
		}
	}

	a.change_get(home_score); a.change_lost(away_score);
	b.change_get(away_score); b.change_lost(home_score);

	if (home_score > away_score) {
		a.res(0);
		b.res(2);

		if (sim == 2 && sound == 1)
		{
			switch (a.tn_())
			{
			case 0:
				PlaySound(TEXT("samsung_win.wav"), NULL, SND_ASYNC);
				break;
			case 1:
				PlaySound(TEXT("lotte_win.wav"), NULL, SND_ASYNC);
				break;
			case 2:
				PlaySound(TEXT("nc_win.wav"), NULL, SND_ASYNC);
				break;
			case 3:
				PlaySound(TEXT("doosan_win.wav"), NULL, SND_ASYNC);
				break;
			case 4:
				PlaySound(TEXT("lg_win.wav"), NULL, SND_ASYNC);
				break;
			case 5:
				PlaySound(TEXT("ssg_win.wav"), NULL, SND_ASYNC);
				break;
			}

		}


	}

	else if (home_score == away_score) {
		a.res(1);
		b.res(1);
	}

	else {
		a.res(2);
		b.res(0);

		if (sim == 2 && sound == 1)
		{
			switch (b.tn_())
			{
			case 0:
				PlaySound(TEXT("samsung_win.wav"), NULL, SND_ASYNC);
				break;
			case 1:
				PlaySound(TEXT("lotte_win.wav"), NULL, SND_ASYNC);
				break;
			case 2:
				PlaySound(TEXT("nc_win.wav"), NULL, SND_ASYNC);
				break;
			case 3:
				PlaySound(TEXT("doosan_win.wav"), NULL, SND_ASYNC);
				break;
			case 4:
				PlaySound(TEXT("lg_win.wav"), NULL, SND_ASYNC);
				break;
			case 5:
				PlaySound(TEXT("ssg_win.wav"), NULL, SND_ASYNC);
				break;
			}

		}

	}


	// ���� ����� ����


	if (use_condition == true)
	{
		h1.restore_condition(false); h2.restore_condition(false); h3.restore_condition(false); h4.restore_condition(false); h5.restore_condition(false);
		h6.restore_condition(false); h7.restore_condition(false); h8.restore_condition(false); h9.restore_condition(false); h10.restore_condition(false);
		h11.restore_condition(false); h12.restore_condition(false); h13.restore_condition(false); h14.restore_condition(false); h15.restore_condition(false); h16.restore_condition(false);

		h31.restore_condition(false); h32.restore_condition(false); h33.restore_condition(false); h34.restore_condition(false); h35.restore_condition(false);
		h36.restore_condition(false); h37.restore_condition(false); h38.restore_condition(false); h39.restore_condition(false); h40.restore_condition(false);
		h41.restore_condition(false); h42.restore_condition(false); h43.restore_condition(false); h44.restore_condition(false); h45.restore_condition(false); h46.restore_condition(false);

		h61.restore_condition(false); h62.restore_condition(false); h63.restore_condition(false); h64.restore_condition(false); h65.restore_condition(false);
		h66.restore_condition(false); h67.restore_condition(false); h68.restore_condition(false); h69.restore_condition(false); h70.restore_condition(false);
		h71.restore_condition(false); h72.restore_condition(false); h73.restore_condition(false); h74.restore_condition(false); h75.restore_condition(false); h76.restore_condition(false);

		h91.restore_condition(false); h92.restore_condition(false); h93.restore_condition(false); h94.restore_condition(false); h95.restore_condition(false);
		h96.restore_condition(false); h97.restore_condition(false); h98.restore_condition(false); h99.restore_condition(false); h100.restore_condition(false);
		h101.restore_condition(false); h102.restore_condition(false); h103.restore_condition(false); h104.restore_condition(false); h105.restore_condition(false); h106.restore_condition(false);

		h131.restore_condition(false); h132.restore_condition(false); h133.restore_condition(false); h134.restore_condition(false); h135.restore_condition(false);
		h136.restore_condition(false); h137.restore_condition(false); h138.restore_condition(false); h139.restore_condition(false); h140.restore_condition(false);
		h141.restore_condition(false); h142.restore_condition(false); h143.restore_condition(false); h144.restore_condition(false); h145.restore_condition(false); h146.restore_condition(false);

		h161.restore_condition(false); h162.restore_condition(false); h163.restore_condition(false); h164.restore_condition(false); h165.restore_condition(false);
		h166.restore_condition(false); h167.restore_condition(false); h168.restore_condition(false); h169.restore_condition(false); h170.restore_condition(false);
		h171.restore_condition(false); h172.restore_condition(false); h173.restore_condition(false); h174.restore_condition(false); h175.restore_condition(false); h176.restore_condition(false);

		h8001.restore_condition(false); h8002.restore_condition(false); h8003.restore_condition(false); h8004.restore_condition(false); h8005.restore_condition(false);
		h8006.restore_condition(false); h8007.restore_condition(false); h8008.restore_condition(false); h8009.restore_condition(false); h8010.restore_condition(false);
		h8011.restore_condition(false); h8012.restore_condition(false); h8013.restore_condition(false); h8014.restore_condition(false); h8015.restore_condition(false); h8016.restore_condition(false);

		h9001.restore_condition(false); h9002.restore_condition(false); h9003.restore_condition(false); h9004.restore_condition(false); h9005.restore_condition(false);
		h9006.restore_condition(false); h9007.restore_condition(false); h9008.restore_condition(false); h9009.restore_condition(false); h9010.restore_condition(false);
		h9011.restore_condition(false); h9012.restore_condition(false); h9013.restore_condition(false); h9014.restore_condition(false); h9015.restore_condition(false); h9016.restore_condition(false);
	}





	if (sim == 3)
	{
		system("cls");
		sim = 2; // �ù� ��ŵ�� ����
	}



	**total_gam += 1;
}


int sel(int* i, int a, int b, int c, int d) //����� ��������, �ప, �ѹ��� �� ĭ�� ��������, ������� �ִ���
{
	int key = 0;
	int k = 0;
	*i = 1;

	cur(a, b);
	cout << ("��");

	while (1) {

		key = getch();

		if (key == 224) {
			key = getch();

			switch (key) {
			case 72:  //��
				if (*i > 1 && *i < d + 1) {
					cur(a, b);
					cout << ("  ");
					cur(a, b - c);
					b -= c;
					*i -= 1;
					cout << ("��");
				}
				break;

			case 80:  //�Ʒ�
				if (*i > 0 && *i < d) {
					cur(a, b);
					cout << ("  ");
					cur(a, b + c);
					b += c;
					*i += 1;
					cout << ("��");
				}
				break;

			}
		}

		else if (key == 13) {
			//cout << j;
			cur(a, b);
			cout << ("  ");
			return *i;
		}

	}

}

void s_result(int i, int j, int homerun, int line, int game_speed)
{
	int a = rand() % 3 + 0;
	int b = rand() % 4 + 0;

	//int home_score = 0;
	//int away_score = 0;


	//cur(66, line); // �⺻�� 19����
	//cout << "                               ";



	cur(61, line);
	switch (i) {
	case 0:
	{
		//for (int i = 0; i < 9; i++) home_score += scoreboard[0][i];
		//for (int i = 0; i < 9; i++) away_score += scoreboard[1][i];
		cout << "  [ Ȩ�� ]  [ " << homerun << "ȣ ]";
		break;
	}

	case 1: cout << "  [ ��Ÿ ]"; break;
	case 2: cout << "  [ 2��Ÿ ]"; break;
	case 3: cout << "  [ 3��Ÿ ]"; break;
	case 4: cout << "  [ ���� ]"; break;
	case 5: cout << "  [ ���� ]"; break;
	case 6: cout << "  [ �ƿ� ]"; break;
	case 7: cout << "  [ ���� ]"; break;
	}


	cout << "  " << j + a - b << " km";
	//cout << "  [ ";
	//pp.print_rspd();
	//cout << " ]" << '\n';

	switch (game_speed)
	{
	case 1: Sleep(50); break;
	case 2: Sleep(600); break;
	case 3: Sleep(500); break;
	case 4: Sleep(800); break;
	case 5: Sleep(1200); break;
	}

}

void ch_h(hitter& a, hitter& b, int chg1, int chg2) //������. ������. ��� ����� ���ΰ�. (a�� b�� �� ��ȯ)
{

	memcpy(&hh, &a, sizeof(class hitter));
	memcpy(&hhh, &b, sizeof(class hitter));
	memcpy(&b, &hh, sizeof(class hitter));
	memcpy(&a, &hhh, sizeof(class hitter));
}

void change_h(hitter& a, hitter& b, int chg1, int chg2) // �� ����� �� ���� ���°ǰ�
{
	memcpy(&hh, &a, sizeof(class hitter));
	memcpy(&hhh, &b, sizeof(class hitter));

	hhhh.cn_(hh.num_()); //X��Ÿ�� ����
	hh.cn_(hhh.num_());
	hhh.cn_(hhhh.num_());

	if (hh.pos_() != hhh.pos_() && hh.dom_() != 1 && hhh.dom_() != 1 && !(chg1 < 10 && chg2 < 10))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cur(85, 1);
		//cout << " [ �� ������ �������� �ٸ��ϴ�. ] " << '\n';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		return;
	}

	if (!(chg1 < 10 && chg2 < 10) && hh.dom_() == 1)
	{
		hh.change_dom(0);
		hhh.change_dom(1);
	}

	else if (!(chg1 < 10 && chg2 < 10) && hhh.dom_() == 1)
	{
		hhh.change_dom(0);
		hh.change_dom(1);
	}

	memcpy(&a, &hhh, sizeof(class hitter));
	memcpy(&b, &hh, sizeof(class hitter));
}

void change(int total_gam, int my_team, boolean trade)
{
	int chg1 = 0, chg2 = 0; // �巡��Ʈ

	int tr = 0;

	int a_stat = 0;
	int b_stat = 0;

	int mmy_team = 0;
	int list[7] = { 81,81,81,81,81,81,0 };
	static int time = 0;

	int save = 0; // �����ǰ� �ӽ� ����

	int row = 20, col = 8;

	static boolean change_10 = false, change_11 = false, change_12 = false, change_13 = false, change_14 = false, change_15 = false, change_16 = false;

	if (total_gam == -10)
	{
		change_10 = false; change_11 = false; change_12 = false; change_13 = false; change_14 = false; change_15 = false; change_16 = false;
		return;
	}

	if (total_gam == -1 || total_gam == -4) // -1 : Ÿ�� �巡��Ʈ, -4 : Ÿ�� �̱�
	{

		if (total_gam == -1)
		{
			cur(16, 36);
			cout << "  [ ��� ]";

			sel(&chg1, 27, 9, 3, 10);
			if (chg1 == 10) return;
		}



		system("cls");

		cur(row, col);

		switch (my_team)
		{
		case 0:
			h10.print(total_gam, 1); col += 3; cur(row, col);
			h11.print(total_gam, 1); col += 3; cur(row, col);
			h12.print(total_gam, 1); col += 3; cur(row, col);
			h13.print(total_gam, 1); col += 3; cur(row, col);
			h14.print(total_gam, 1); col += 3; cur(row, col);
			h15.print(total_gam, 1); col += 3; cur(row, col);
			h16.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 1:
			h40.print(total_gam, 1); col += 3; cur(row, col);
			h41.print(total_gam, 1); col += 3; cur(row, col);
			h42.print(total_gam, 1); col += 3; cur(row, col);
			h43.print(total_gam, 1); col += 3; cur(row, col);
			h44.print(total_gam, 1); col += 3; cur(row, col);
			h45.print(total_gam, 1); col += 3; cur(row, col);
			h46.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 2:
			h70.print(total_gam, 1); col += 3; cur(row, col);
			h71.print(total_gam, 1); col += 3; cur(row, col);
			h72.print(total_gam, 1); col += 3; cur(row, col);
			h73.print(total_gam, 1); col += 3; cur(row, col);
			h74.print(total_gam, 1); col += 3; cur(row, col);
			h75.print(total_gam, 1); col += 3; cur(row, col);
			h76.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 3:
			h100.print(total_gam, 1); col += 3; cur(row, col);
			h101.print(total_gam, 1); col += 3; cur(row, col);
			h102.print(total_gam, 1); col += 3; cur(row, col);
			h103.print(total_gam, 1); col += 3; cur(row, col);
			h104.print(total_gam, 1); col += 3; cur(row, col);
			h105.print(total_gam, 1); col += 3; cur(row, col);
			h106.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 4:
			h140.print(total_gam, 1); col += 3; cur(row, col);
			h141.print(total_gam, 1); col += 3; cur(row, col);
			h142.print(total_gam, 1); col += 3; cur(row, col);
			h143.print(total_gam, 1); col += 3; cur(row, col);
			h144.print(total_gam, 1); col += 3; cur(row, col);
			h145.print(total_gam, 1); col += 3; cur(row, col);
			h146.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 5:
			h170.print(total_gam, 1); col += 3; cur(row, col);
			h171.print(total_gam, 1); col += 3; cur(row, col);
			h172.print(total_gam, 1); col += 3; cur(row, col);
			h173.print(total_gam, 1); col += 3; cur(row, col);
			h174.print(total_gam, 1); col += 3; cur(row, col);
			h175.print(total_gam, 1); col += 3; cur(row, col);
			h176.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 11:
			h8010.print(total_gam, 1); col += 3; cur(row, col);
			h8011.print(total_gam, 1); col += 3; cur(row, col);
			h8012.print(total_gam, 1); col += 3; cur(row, col);
			h8013.print(total_gam, 1); col += 3; cur(row, col);
			h8014.print(total_gam, 1); col += 3; cur(row, col);
			h8015.print(total_gam, 1); col += 3; cur(row, col);
			h8016.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 12:
			h9010.print(total_gam, 1); col += 3; cur(row, col);
			h9011.print(total_gam, 1); col += 3; cur(row, col);
			h9012.print(total_gam, 1); col += 3; cur(row, col);
			h9013.print(total_gam, 1); col += 3; cur(row, col);
			h9014.print(total_gam, 1); col += 3; cur(row, col);
			h9015.print(total_gam, 1); col += 3; cur(row, col);
			h9016.print(total_gam, 1); col += 3; cur(row, col);
			break;
		}

		cout << "    [  ���  ]";

		sel(&chg2, 35, 8, 3, 8);

		if (total_gam == -1) // -1 : Ÿ�� �巡��Ʈ
		{

			if (chg1 == 10) return;

			switch (chg1) {
			case 1: memcpy(&hh, &h1000, sizeof(class hitter)); break;
			case 2: memcpy(&hh, &h1001, sizeof(class hitter)); break;
			case 3: memcpy(&hh, &h1002, sizeof(class hitter)); break;
			case 4: memcpy(&hh, &h1003, sizeof(class hitter)); break;
			case 5: memcpy(&hh, &h1004, sizeof(class hitter)); break;
			case 6: memcpy(&hh, &h1005, sizeof(class hitter)); break;
			case 7: memcpy(&hh, &h1006, sizeof(class hitter)); break;
			case 8: memcpy(&hh, &h1007, sizeof(class hitter)); break;
			case 9: memcpy(&hh, &h1008, sizeof(class hitter)); break;
			}
		}



		hh.re();

		switch (my_team)
		{
		case 0:
			switch (chg2) {
			case 1: memcpy(&h10, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h11, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h12, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h13, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h14, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h15, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h16, &hh, sizeof(class hitter)); break;
			}
			break;
		case 1:
			switch (chg2) {
			case 1: memcpy(&h40, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h41, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h42, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h43, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h44, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h45, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h46, &hh, sizeof(class hitter)); break;
			}
			break;
		case 2:
			switch (chg2) {
			case 1: memcpy(&h70, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h71, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h72, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h73, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h74, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h75, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h76, &hh, sizeof(class hitter)); break;
			}
			break;
		case 3:
			switch (chg2) {
			case 1: memcpy(&h100, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h101, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h102, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h103, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h104, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h105, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h106, &hh, sizeof(class hitter)); break;
			}
			break;
		case 4:
			switch (chg2) {
			case 1: memcpy(&h140, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h141, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h142, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h143, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h144, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h145, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h146, &hh, sizeof(class hitter)); break;
			}
			break;
		case 5:
			switch (chg2) {
			case 1: memcpy(&h170, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h171, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h172, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h173, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h174, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h175, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h176, &hh, sizeof(class hitter)); break;
			}
			break;
		case 11:
			switch (chg2) {
			case 1: memcpy(&h8010, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h8011, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h8012, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h8013, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h8014, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h8015, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h8016, &hh, sizeof(class hitter)); break;
			}
			break;
		case 12:
			switch (chg2) {
			case 1: memcpy(&h9010, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h9011, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h9012, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h9013, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h9014, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h9015, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h9016, &hh, sizeof(class hitter)); break;
			}
			break;
		}

		if (total_gam == -1) list[my_team] = chg1;




		return;

	}

	else if (total_gam == -2) // Ŀ��Ƭ
	{

		system("cls");

		row = 20; col = 6;

		cur(row + 4, col - 1);

		cout << "[ ��ü�� ������ �������ֽʽÿ�. ]";


		col += 2;

		cur(row, col);

		switch (my_team)
		{
		case 0:
			h10.print(total_gam, 1); col += 3; cur(row, col);
			h11.print(total_gam, 1); col += 3; cur(row, col);
			h12.print(total_gam, 1); col += 3; cur(row, col);
			h13.print(total_gam, 1); col += 3; cur(row, col);
			h14.print(total_gam, 1); col += 3; cur(row, col);
			h15.print(total_gam, 1); col += 3; cur(row, col);
			h16.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 1:
			h40.print(total_gam, 1); col += 3; cur(row, col);
			h41.print(total_gam, 1); col += 3; cur(row, col);
			h42.print(total_gam, 1); col += 3; cur(row, col);
			h43.print(total_gam, 1); col += 3; cur(row, col);
			h44.print(total_gam, 1); col += 3; cur(row, col);
			h45.print(total_gam, 1); col += 3; cur(row, col);
			h46.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 2:
			h70.print(total_gam, 1); col += 3; cur(row, col);
			h71.print(total_gam, 1); col += 3; cur(row, col);
			h72.print(total_gam, 1); col += 3; cur(row, col);
			h73.print(total_gam, 1); col += 3; cur(row, col);
			h74.print(total_gam, 1); col += 3; cur(row, col);
			h75.print(total_gam, 1); col += 3; cur(row, col);
			h76.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 3:
			h100.print(total_gam, 1); col += 3; cur(row, col);
			h101.print(total_gam, 1); col += 3; cur(row, col);
			h102.print(total_gam, 1); col += 3; cur(row, col);
			h103.print(total_gam, 1); col += 3; cur(row, col);
			h104.print(total_gam, 1); col += 3; cur(row, col);
			h105.print(total_gam, 1); col += 3; cur(row, col);
			h106.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 4:
			h140.print(total_gam, 1); col += 3; cur(row, col);
			h141.print(total_gam, 1); col += 3; cur(row, col);
			h142.print(total_gam, 1); col += 3; cur(row, col);
			h143.print(total_gam, 1); col += 3; cur(row, col);
			h144.print(total_gam, 1); col += 3; cur(row, col);
			h145.print(total_gam, 1); col += 3; cur(row, col);
			h146.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 5:
			h170.print(total_gam, 1); col += 3; cur(row, col);
			h171.print(total_gam, 1); col += 3; cur(row, col);
			h172.print(total_gam, 1); col += 3; cur(row, col);
			h173.print(total_gam, 1); col += 3; cur(row, col);
			h174.print(total_gam, 1); col += 3; cur(row, col);
			h175.print(total_gam, 1); col += 3; cur(row, col);
			h176.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 11:
			h8010.print(total_gam, 1); col += 3; cur(row, col);
			h8011.print(total_gam, 1); col += 3; cur(row, col);
			h8012.print(total_gam, 1); col += 3; cur(row, col);
			h8013.print(total_gam, 1); col += 3; cur(row, col);
			h8014.print(total_gam, 1); col += 3; cur(row, col);
			h8015.print(total_gam, 1); col += 3; cur(row, col);
			h8016.print(total_gam, 1); col += 3; cur(row, col);
			break;
		case 12:
			h9010.print(total_gam, 1); col += 3; cur(row, col);
			h9011.print(total_gam, 1); col += 3; cur(row, col);
			h9012.print(total_gam, 1); col += 3; cur(row, col);
			h9013.print(total_gam, 1); col += 3; cur(row, col);
			h9014.print(total_gam, 1); col += 3; cur(row, col);
			h9015.print(total_gam, 1); col += 3; cur(row, col);
			h9016.print(total_gam, 1); col += 3; cur(row, col);
			break;
		}

		cout << "    [  ���  ]";

		sel(&chg2, 35, 8, 3, 8);

		if (chg1 == 8) return;

		memcpy(&hh, &h9999, sizeof(class hitter));


		hh.re();

		switch (my_team)
		{
		case 0:
			switch (chg2) {
			case 1: memcpy(&h10, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h11, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h12, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h13, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h14, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h15, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h16, &hh, sizeof(class hitter)); break;
			}
			break;
		case 1:
			switch (chg2) {
			case 1: memcpy(&h40, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h41, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h42, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h43, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h44, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h45, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h46, &hh, sizeof(class hitter)); break;
			}
			break;
		case 2:
			switch (chg2) {
			case 1: memcpy(&h70, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h71, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h72, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h73, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h74, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h75, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h76, &hh, sizeof(class hitter)); break;
			}
			break;
		case 3:
			switch (chg2) {
			case 1: memcpy(&h100, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h101, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h102, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h103, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h104, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h105, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h106, &hh, sizeof(class hitter)); break;
			}
			break;
		case 4:
			switch (chg2) {
			case 1: memcpy(&h140, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h141, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h142, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h143, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h144, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h145, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h146, &hh, sizeof(class hitter)); break;
			}
			break;
		case 5:
			switch (chg2) {
			case 1: memcpy(&h170, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h171, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h172, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h173, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h174, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h175, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h176, &hh, sizeof(class hitter)); break;
			}
			break;
		case 11:
			switch (chg2) {
			case 1: memcpy(&h8010, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h8011, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h8012, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h8013, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h8014, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h8015, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h8016, &hh, sizeof(class hitter)); break;
			}
			break;
		case 12:
			switch (chg2) {
			case 1: memcpy(&h9010, &hh, sizeof(class hitter)); break;
			case 2: memcpy(&h9011, &hh, sizeof(class hitter)); break;
			case 3: memcpy(&h9012, &hh, sizeof(class hitter)); break;
			case 4: memcpy(&h9013, &hh, sizeof(class hitter)); break;
			case 5: memcpy(&h9014, &hh, sizeof(class hitter)); break;
			case 6: memcpy(&h9015, &hh, sizeof(class hitter)); break;
			case 7: memcpy(&h9016, &hh, sizeof(class hitter)); break;
			}
			break;
		}

		return;
	}

	else if (total_gam == -3) // Ŀ��Ƭ
	{


		cur(0, 16);
		cout << "   [ ��� ]";

		system("cls");
		cout << '\n' << '\n' << '\n' << '\n' << '\n';

		switch (my_team)
		{
		case 0:
			cout << " [ ��ü�� ������ �������ֽʽÿ�. ]" << '\n' << '\n' << '\n';
			p1.printp(1); p2.printp(2); p3.printp(3); p4.printp(4); p5.printp(5);
			p6.printp(6); p7.printp(7); p8.printp(8); p9.printp(9); p10.printp(10); p11.printp(10);
			break;
		case 1:
			cout << " [ ��ü�� ������ �������ֽʽÿ�. ]" << '\n' << '\n' << '\n';
			p31.printp(1); p32.printp(2); p33.printp(3); p34.printp(4); p35.printp(5);
			p36.printp(6); p37.printp(7); p38.printp(8); p39.printp(9); p40.printp(10); p41.printp(10);
			break;

		case 2:
			cout << " [ ��ü�� ������ �������ֽʽÿ�. ]" << '\n' << '\n' << '\n';
			p61.printp(1); p62.printp(2); p63.printp(3); p64.printp(4); p65.printp(5);
			p66.printp(6); p67.printp(7); p68.printp(8); p69.printp(9); p70.printp(10); p71.printp(10);
			break;

		case 3:
			cout << " [ ��ü�� ������ �������ֽʽÿ�. ]" << '\n' << '\n' << '\n';
			p91.printp(1); p92.printp(2); p93.printp(3); p94.printp(4); p95.printp(5);
			p96.printp(6); p97.printp(7); p98.printp(8); p99.printp(9); p100.printp(10); p101.printp(10);
			break;

		case 4:
			cout << " [ ��ü�� ������ �������ֽʽÿ�. ]" << '\n' << '\n' << '\n';
			p131.printp(1); p132.printp(2); p133.printp(3); p134.printp(4); p135.printp(5);
			p136.printp(6); p137.printp(7); p138.printp(8); p139.printp(9); p140.printp(10); p141.printp(10);
			break;

		case 5:
			cout << " [ ��ü�� ������ �������ֽʽÿ�. ]" << '\n' << '\n' << '\n';
			p161.printp(1); p162.printp(2); p163.printp(3); p164.printp(4); p165.printp(5);
			p166.printp(6); p167.printp(7); p168.printp(8); p169.printp(9); p170.printp(10); p171.printp(10);
			break;

		case 11:
			cout << " [ ��ü�� ������ �������ֽʽÿ�. ]" << '\n' << '\n' << '\n';
			p8001.printp(1); p8002.printp(2); p8003.printp(3); p8004.printp(4); p8005.printp(5);
			p8006.printp(6); p8007.printp(7); p8008.printp(8); p8009.printp(9); p8010.printp(10); p8011.printp(10);
			break;

		case 12:
			cout << " [ ��ü�� ������ �������ֽʽÿ�. ]" << '\n' << '\n' << '\n';
			p9001.printp(1); p9002.printp(2); p9003.printp(3); p9004.printp(4); p9005.printp(5);
			p9006.printp(6); p9007.printp(7); p9008.printp(8); p9009.printp(9); p9010.printp(10); p9011.printp(10);
			break;
		}


		cout << "  [ ��� ]";

		sel(&chg1, 12, 8, 2, 12);
		if (chg1 == 12) return;

		memcpy(&ppp, &p9999, sizeof(class hitter));

		switch (my_team)
		{
		case 0:
			switch (chg1) {
			case 1: memcpy(&p1, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p2, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p3, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p4, &ppp, sizeof(class pitcher)); break;
			case 5: memcpy(&p5, &ppp, sizeof(class pitcher)); break;
			case 6: memcpy(&p6, &ppp, sizeof(class pitcher)); break;
			case 7: memcpy(&p7, &ppp, sizeof(class pitcher)); break;
			case 8: memcpy(&p8, &ppp, sizeof(class pitcher)); break;
			case 9: memcpy(&p9, &ppp, sizeof(class pitcher)); break;
			case 10: memcpy(&p10, &ppp, sizeof(class pitcher)); break;
			case 11: memcpy(&p11, &ppp, sizeof(class pitcher)); break;
			}
			break;
		case 1:
			switch (chg1) {
			case 1: memcpy(&p31, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p32, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p33, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p34, &ppp, sizeof(class pitcher)); break;
			case 5: memcpy(&p35, &ppp, sizeof(class pitcher)); break;
			case 6: memcpy(&p36, &ppp, sizeof(class pitcher)); break;
			case 7: memcpy(&p37, &ppp, sizeof(class pitcher)); break;
			case 8: memcpy(&p38, &ppp, sizeof(class pitcher)); break;
			case 9: memcpy(&p39, &ppp, sizeof(class pitcher)); break;
			case 10: memcpy(&p40, &ppp, sizeof(class pitcher)); break;
			case 11: memcpy(&p41, &ppp, sizeof(class pitcher)); break;
			}
			break;
		case 2:
			switch (chg1) {
			case 1: memcpy(&p61, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p62, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p63, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p64, &ppp, sizeof(class pitcher)); break;
			case 5: memcpy(&p65, &ppp, sizeof(class pitcher)); break;
			case 6: memcpy(&p66, &ppp, sizeof(class pitcher)); break;
			case 7: memcpy(&p67, &ppp, sizeof(class pitcher)); break;
			case 8: memcpy(&p68, &ppp, sizeof(class pitcher)); break;
			case 9: memcpy(&p69, &ppp, sizeof(class pitcher)); break;
			case 10: memcpy(&p70, &ppp, sizeof(class pitcher)); break;
			case 11: memcpy(&p71, &ppp, sizeof(class pitcher)); break;
			}
			break;
		case 3:
			switch (chg1) {
			case 1: memcpy(&p91, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p92, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p93, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p94, &ppp, sizeof(class pitcher)); break;
			case 5: memcpy(&p95, &ppp, sizeof(class pitcher)); break;
			case 6: memcpy(&p96, &ppp, sizeof(class pitcher)); break;
			case 7: memcpy(&p97, &ppp, sizeof(class pitcher)); break;
			case 8: memcpy(&p98, &ppp, sizeof(class pitcher)); break;
			case 9: memcpy(&p99, &ppp, sizeof(class pitcher)); break;
			case 10: memcpy(&p100, &ppp, sizeof(class pitcher)); break;
			case 11: memcpy(&p101, &ppp, sizeof(class pitcher)); break;
			}
			break;
		case 4:
			switch (chg1) {
			case 1: memcpy(&p131, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p132, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p133, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p134, &ppp, sizeof(class pitcher)); break;
			case 5: memcpy(&p135, &ppp, sizeof(class pitcher)); break;
			case 6: memcpy(&p136, &ppp, sizeof(class pitcher)); break;
			case 7: memcpy(&p137, &ppp, sizeof(class pitcher)); break;
			case 8: memcpy(&p138, &ppp, sizeof(class pitcher)); break;
			case 9: memcpy(&p139, &ppp, sizeof(class pitcher)); break;
			case 10: memcpy(&p140, &ppp, sizeof(class pitcher)); break;
			case 11: memcpy(&p141, &ppp, sizeof(class pitcher)); break;
			}
			break;
		case 5:
			switch (chg1) {
			case 1: memcpy(&p161, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p162, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p163, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p164, &ppp, sizeof(class pitcher)); break;
			case 5: memcpy(&p165, &ppp, sizeof(class pitcher)); break;
			case 6: memcpy(&p166, &ppp, sizeof(class pitcher)); break;
			case 7: memcpy(&p167, &ppp, sizeof(class pitcher)); break;
			case 8: memcpy(&p168, &ppp, sizeof(class pitcher)); break;
			case 9: memcpy(&p169, &ppp, sizeof(class pitcher)); break;
			case 10: memcpy(&p170, &ppp, sizeof(class pitcher)); break;
			case 11: memcpy(&p171, &ppp, sizeof(class pitcher)); break;
			}
			break;
		case 11:
			switch (chg1) {
			case 1: memcpy(&p8001, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p8002, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p8003, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p8004, &ppp, sizeof(class pitcher)); break;
			case 5: memcpy(&p8005, &ppp, sizeof(class pitcher)); break;
			case 6: memcpy(&p8006, &ppp, sizeof(class pitcher)); break;
			case 7: memcpy(&p8007, &ppp, sizeof(class pitcher)); break;
			case 8: memcpy(&p8008, &ppp, sizeof(class pitcher)); break;
			case 9: memcpy(&p8009, &ppp, sizeof(class pitcher)); break;
			case 10: memcpy(&p8010, &ppp, sizeof(class pitcher)); break;
			case 11: memcpy(&p8011, &ppp, sizeof(class pitcher)); break;
			}
			break;
		case 12:
			switch (chg1) {
			case 1: memcpy(&p9001, &ppp, sizeof(class pitcher)); break;
			case 2: memcpy(&p9002, &ppp, sizeof(class pitcher)); break;
			case 3: memcpy(&p9003, &ppp, sizeof(class pitcher)); break;
			case 4: memcpy(&p9004, &ppp, sizeof(class pitcher)); break;
			case 5: memcpy(&p9005, &ppp, sizeof(class pitcher)); break;
			case 6: memcpy(&p9006, &ppp, sizeof(class pitcher)); break;
			case 7: memcpy(&p9007, &ppp, sizeof(class pitcher)); break;
			case 8: memcpy(&p9008, &ppp, sizeof(class pitcher)); break;
			case 9: memcpy(&p9009, &ppp, sizeof(class pitcher)); break;
			case 10: memcpy(&p9010, &ppp, sizeof(class pitcher)); break;
			case 11: memcpy(&p9011, &ppp, sizeof(class pitcher)); break;
			}
			break;
		}

		return;

	}

	while (1)
	{

		cur(0, 0); cout << '\n' << '\n'; cur(23, 2);

		cur(0, 38); cout << "    [  ���  ] " << '\n';







		if (my_team == 0) {  // �츮�� �Ｚ

			sel(&chg1, 15, 6, 2, 17); // �Ե��� chg3, chg4
			if (chg1 == 17) break;

			if (trade == false) {
				sel(&chg2, 15, 6, 2, 17);
				if (chg2 == 17) break;
			}

			//  ch_h()

			switch (chg1) {
			case 1: memcpy(&hh, &h1, sizeof(class hitter)); break;
			case 2: memcpy(&hh, &h2, sizeof(class hitter)); break;
			case 3: memcpy(&hh, &h3, sizeof(class hitter)); break;
			case 4: memcpy(&hh, &h4, sizeof(class hitter)); break;
			case 5: memcpy(&hh, &h5, sizeof(class hitter)); break;
			case 6: memcpy(&hh, &h6, sizeof(class hitter)); break;
			case 7: memcpy(&hh, &h7, sizeof(class hitter)); break;
			case 8: memcpy(&hh, &h8, sizeof(class hitter)); break;
			case 9: memcpy(&hh, &h9, sizeof(class hitter)); break;
			case 10: memcpy(&hh, &h10, sizeof(class hitter)); break;
			case 11: memcpy(&hh, &h11, sizeof(class hitter)); break;
			case 12: memcpy(&hh, &h12, sizeof(class hitter)); break;
			case 13: memcpy(&hh, &h13, sizeof(class hitter)); break;
			case 14: memcpy(&hh, &h14, sizeof(class hitter)); break;
			case 15: memcpy(&hh, &h15, sizeof(class hitter)); break;
			case 16: memcpy(&hh, &h16, sizeof(class hitter)); break;
			}



			if (trade == true) { // Ʈ���̵� ����

				cur(0, 38); cout << "    [  ���  ] " << '\n';

				system("cls");





				cout << "Ʈ���̵� �� ��븦 �������ֽʽÿ� : " << '\n'
					<< "[0] �Ｚ" << '\n' << "[1] �Ե�" << '\n' << "[2] NC" << '\n' << "[3] �λ�" << '\n' << "[4] LG" << '\n' << "[5] SSG" << '\n' << "[9] ���";

				cur(36, 0);
				cin >> tr;

				if (tr != 1 && tr != 2 && tr != 3 && tr != 4 && tr != 5) break;

				system("cls");

				cout << hh.stat(total_gam) << '\n';

				switch (tr) {
				case 1:
					print_hitter_record(total_gam, 1, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h31, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h32, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h33, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h34, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h35, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h36, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h37, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h38, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h39, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h40, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h41, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h42, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h43, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h44, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h45, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h46, sizeof(class hitter)); break;
					}
					break;

				case 2:
					print_hitter_record(total_gam, 2, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h61, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h62, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h63, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h64, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h65, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h66, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h67, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h68, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h69, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h70, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h71, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h72, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h73, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h74, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h75, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h76, sizeof(class hitter)); break;
					}
					break;

				case 3:
					print_hitter_record(total_gam, 3, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h91, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h92, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h93, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h94, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h95, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h96, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h97, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h98, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h99, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h100, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h101, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h102, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h103, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h104, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h105, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h106, sizeof(class hitter)); break;
					}
					break;

				case 4:
					print_hitter_record(total_gam, 4, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h131, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h132, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h133, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h134, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h135, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h136, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h137, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h138, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h139, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h140, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h141, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h142, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h143, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h144, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h145, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h146, sizeof(class hitter)); break;
					}
					break;

				case 5:
					print_hitter_record(total_gam, 5, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h161, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h162, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h163, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h164, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h165, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h166, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h167, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h168, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h169, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h170, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h171, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h172, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h173, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h174, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h175, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h176, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) - 1 <= hhh.stat(total_gam)) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&hhh, &h1, sizeof(class hitter)); break;
				case 2: memcpy(&hhh, &h2, sizeof(class hitter)); break;
				case 3: memcpy(&hhh, &h3, sizeof(class hitter)); break;
				case 4: memcpy(&hhh, &h4, sizeof(class hitter)); break;
				case 5: memcpy(&hhh, &h5, sizeof(class hitter)); break;
				case 6: memcpy(&hhh, &h6, sizeof(class hitter)); break;
				case 7: memcpy(&hhh, &h7, sizeof(class hitter)); break;
				case 8: memcpy(&hhh, &h8, sizeof(class hitter)); break;
				case 9: memcpy(&hhh, &h9, sizeof(class hitter)); break;
				case 10: memcpy(&hhh, &h10, sizeof(class hitter)); break;
				case 11: memcpy(&hhh, &h11, sizeof(class hitter)); break;
				case 12: memcpy(&hhh, &h12, sizeof(class hitter)); break;
				case 13: memcpy(&hhh, &h13, sizeof(class hitter)); break;
				case 14: memcpy(&hhh, &h14, sizeof(class hitter)); break;
				case 15: memcpy(&hhh, &h15, sizeof(class hitter)); break;
				case 16: memcpy(&hhh, &h16, sizeof(class hitter)); break;
				}



				if (print_check(hh.pos_(), hhh.pos_()) != 1 && hh.dom_() != 1 && hhh.dom_() != 1 && !(chg1 < 10 && chg2 < 10))
				{
					break;
				}

				if (total_gam == -5 && (chg1 < 10 && chg2 < 10) || (chg1 >= 10 && chg2 >= 10)) break;

				if (total_gam == -5) //��ü �ǿ���� (�ѹ� �ĺ��� ���� ������ �ٽ� �������� ���� �� ����.)
				{
					if ((chg1 == 10 || chg2 == 10) && change_10 == true) break;
					if ((chg1 == 11 || chg2 == 11) && change_11 == true) break;
					if ((chg1 == 12 || chg2 == 12) && change_12 == true) break;
					if ((chg1 == 13 || chg2 == 13) && change_13 == true) break;
					if ((chg1 == 14 || chg2 == 14) && change_14 == true) break;
					if ((chg1 == 15 || chg2 == 15) && change_15 == true) break;
					if ((chg1 == 16 || chg2 == 16) && change_16 == true) break;

					switch (chg1)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

					switch (chg2)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

				}

			}

			if (trade == true && (print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 || chg2 < 10) && hhh.dom_() != 1 && hh.dom_() != 1)) break;
			if (trade == true && print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 && chg2 < 10) && (hhh.dom_() != 1 || hh.dom_() != 1)) break;
			if (trade == true && (double)(hh.stat(total_gam) * tra) < hhh.stat(total_gam)) break;


			if (chg2 == 17) break;



			if (hh.pos_() != hhh.pos_() && (print_check(hh.pos_(), hhh.pos_()) == 1) && !(chg1 < 10 && chg2 < 10))
			{
				save = hh.pos_();

				hh.change_pos_(change_pos(hhh.pos_()));

				hhh.change_pos_(save);


			}

			if (trade == true) {

				if (hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			else {

				if (!(chg1 < 10 && chg2 < 10) && hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (!(chg1 < 10 && chg2 < 10) && hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			hhhh.cn_(hh.num_()); //X��Ÿ�� ����
			hh.cn_(hhh.num_());
			hhh.cn_(hhhh.num_());



			switch (chg1) {
			case 1: memcpy(&h1, &hhh, sizeof(class hitter)); break;
			case 2: memcpy(&h2, &hhh, sizeof(class hitter)); break;
			case 3: memcpy(&h3, &hhh, sizeof(class hitter)); break;
			case 4: memcpy(&h4, &hhh, sizeof(class hitter)); break;
			case 5: memcpy(&h5, &hhh, sizeof(class hitter)); break;
			case 6: memcpy(&h6, &hhh, sizeof(class hitter)); break;
			case 7: memcpy(&h7, &hhh, sizeof(class hitter)); break;
			case 8: memcpy(&h8, &hhh, sizeof(class hitter)); break;
			case 9: memcpy(&h9, &hhh, sizeof(class hitter)); break;
			case 10: memcpy(&h10, &hhh, sizeof(class hitter)); break;
			case 11: memcpy(&h11, &hhh, sizeof(class hitter)); break;
			case 12: memcpy(&h12, &hhh, sizeof(class hitter)); break;
			case 13: memcpy(&h13, &hhh, sizeof(class hitter)); break;
			case 14: memcpy(&h14, &hhh, sizeof(class hitter)); break;
			case 15: memcpy(&h15, &hhh, sizeof(class hitter)); break;
			case 16: memcpy(&h16, &hhh, sizeof(class hitter)); break;
			}



			if (trade == true) {

				switch (tr) {
				case 1:
					switch (chg2) {
					case 1: memcpy(&h31, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h32, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h33, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h34, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h35, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h36, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h37, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h38, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h39, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h40, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h41, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h42, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h43, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h44, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h45, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h46, &hh, sizeof(class hitter)); break;
					}
					break;

				case 2:
					switch (chg2) {
					case 1: memcpy(&h61, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h62, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h63, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h64, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h65, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h66, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h67, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h68, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h69, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h70, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h71, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h72, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h73, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h74, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h75, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h76, &hh, sizeof(class hitter)); break;
					}
					break;

				case 3:
					switch (chg2) {
					case 1: memcpy(&h91, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h92, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h93, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h94, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h95, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h96, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h97, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h98, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h99, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h100, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h101, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h102, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h103, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h104, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h105, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h106, &hh, sizeof(class hitter)); break;
					}
					break;

				case 4:
					switch (chg2) {
					case 1: memcpy(&h131, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h132, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h133, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h134, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h135, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h136, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h137, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h138, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h139, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h140, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h141, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h142, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h143, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h144, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h145, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h146, &hh, sizeof(class hitter)); break;
					}
					break;

				case 5:
					switch (chg2) {
					case 1: memcpy(&h161, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h162, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h163, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h164, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h165, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h166, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h167, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h168, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h169, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h170, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h171, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h172, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h173, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h174, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h175, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h176, &hh, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) > hhh.stat(total_gam) + 1) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&h1, &hh, sizeof(class hitter)); break;
				case 2: memcpy(&h2, &hh, sizeof(class hitter)); break;
				case 3: memcpy(&h3, &hh, sizeof(class hitter)); break;
				case 4: memcpy(&h4, &hh, sizeof(class hitter)); break;
				case 5: memcpy(&h5, &hh, sizeof(class hitter)); break;
				case 6: memcpy(&h6, &hh, sizeof(class hitter)); break;
				case 7: memcpy(&h7, &hh, sizeof(class hitter)); break;
				case 8: memcpy(&h8, &hh, sizeof(class hitter)); break;
				case 9: memcpy(&h9, &hh, sizeof(class hitter)); break;
				case 10: memcpy(&h10, &hh, sizeof(class hitter)); break;
				case 11: memcpy(&h11, &hh, sizeof(class hitter)); break;
				case 12: memcpy(&h12, &hh, sizeof(class hitter)); break;
				case 13: memcpy(&h13, &hh, sizeof(class hitter)); break;
				case 14: memcpy(&h14, &hh, sizeof(class hitter)); break;
				case 15: memcpy(&h15, &hh, sizeof(class hitter)); break;
				case 16: memcpy(&h16, &hh, sizeof(class hitter)); break;
				}
			}
			break;



		}

		if (my_team == 1) {  // �츮�� �Ｚ

			sel(&chg1, 15, 6, 2, 17); // �Ե��� chg3, chg4
			if (chg1 == 17) break;

			if (trade == false) {
				sel(&chg2, 15, 6, 2, 17);
				if (chg2 == 17) break;
			}

			//  ch_h()

			switch (chg1) {
			case 1: memcpy(&hh, &h31, sizeof(class hitter)); break;
			case 2: memcpy(&hh, &h32, sizeof(class hitter)); break;
			case 3: memcpy(&hh, &h33, sizeof(class hitter)); break;
			case 4: memcpy(&hh, &h34, sizeof(class hitter)); break;
			case 5: memcpy(&hh, &h35, sizeof(class hitter)); break;
			case 6: memcpy(&hh, &h36, sizeof(class hitter)); break;
			case 7: memcpy(&hh, &h37, sizeof(class hitter)); break;
			case 8: memcpy(&hh, &h38, sizeof(class hitter)); break;
			case 9: memcpy(&hh, &h39, sizeof(class hitter)); break;
			case 10: memcpy(&hh, &h40, sizeof(class hitter)); break;
			case 11: memcpy(&hh, &h41, sizeof(class hitter)); break;
			case 12: memcpy(&hh, &h42, sizeof(class hitter)); break;
			case 13: memcpy(&hh, &h43, sizeof(class hitter)); break;
			case 14: memcpy(&hh, &h44, sizeof(class hitter)); break;
			case 15: memcpy(&hh, &h45, sizeof(class hitter)); break;
			case 16: memcpy(&hh, &h46, sizeof(class hitter)); break;
			}



			if (trade == true) { // Ʈ���̵� ����

				cur(0, 38); cout << "    [  ���  ] " << '\n';

				system("cls");

				cout << "Ʈ���̵� �� ��븦 �������ֽʽÿ� : " << '\n'
					<< "[0] �Ｚ" << '\n' << "[1] �Ե�" << '\n' << "[2] NC" << '\n' << "[3] �λ�" << '\n' << "[4] LG" << '\n' << "[5] SSG" << '\n' << "[9] ���";

				cur(36, 0);
				cin >> tr;

				if (tr != 0 && tr != 2 && tr != 3 && tr != 4 && tr != 5) break;

				system("cls");

				cout << hh.stat(total_gam) << '\n';

				switch (tr) {
				case 0:
					print_hitter_record(total_gam, 0, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h1, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h2, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h3, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h4, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h5, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h6, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h7, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h8, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h9, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h10, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h11, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h12, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h13, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h14, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h15, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h16, sizeof(class hitter)); break;
					}
					break;

				case 2:
					print_hitter_record(total_gam, 2, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h61, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h62, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h63, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h64, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h65, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h66, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h67, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h68, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h69, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h70, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h71, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h72, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h73, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h74, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h75, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h76, sizeof(class hitter)); break;
					}
					break;

				case 3:
					print_hitter_record(total_gam, 3, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h91, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h92, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h93, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h94, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h95, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h96, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h97, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h98, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h99, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h100, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h101, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h102, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h103, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h104, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h105, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h106, sizeof(class hitter)); break;
					}
					break;

				case 4:
					print_hitter_record(total_gam, 4, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h131, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h132, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h133, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h134, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h135, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h136, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h137, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h138, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h139, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h140, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h141, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h142, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h143, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h144, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h145, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h146, sizeof(class hitter)); break;
					}
					break;

				case 5:
					print_hitter_record(total_gam, 5, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h161, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h162, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h163, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h164, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h165, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h166, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h167, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h168, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h169, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h170, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h171, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h172, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h173, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h174, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h175, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h176, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) - 1 <= hhh.stat(total_gam)) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&hhh, &h31, sizeof(class hitter)); break;
				case 2: memcpy(&hhh, &h32, sizeof(class hitter)); break;
				case 3: memcpy(&hhh, &h33, sizeof(class hitter)); break;
				case 4: memcpy(&hhh, &h34, sizeof(class hitter)); break;
				case 5: memcpy(&hhh, &h35, sizeof(class hitter)); break;
				case 6: memcpy(&hhh, &h36, sizeof(class hitter)); break;
				case 7: memcpy(&hhh, &h37, sizeof(class hitter)); break;
				case 8: memcpy(&hhh, &h38, sizeof(class hitter)); break;
				case 9: memcpy(&hhh, &h39, sizeof(class hitter)); break;
				case 10: memcpy(&hhh, &h40, sizeof(class hitter)); break;
				case 11: memcpy(&hhh, &h41, sizeof(class hitter)); break;
				case 12: memcpy(&hhh, &h42, sizeof(class hitter)); break;
				case 13: memcpy(&hhh, &h43, sizeof(class hitter)); break;
				case 14: memcpy(&hhh, &h44, sizeof(class hitter)); break;
				case 15: memcpy(&hhh, &h45, sizeof(class hitter)); break;
				case 16: memcpy(&hhh, &h46, sizeof(class hitter)); break;
				}

				if (print_check(hh.pos_(), hhh.pos_()) != 1 && hh.dom_() != 1 && hhh.dom_() != 1 && !(chg1 < 10 && chg2 < 10))
				{
					break;
				}

				if (total_gam == -5 && (chg1 < 10 && chg2 < 10) || (chg1 >= 10 && chg2 >= 10)) break;

				if (total_gam == -5) //��ü �ǿ���� (�ѹ� �ĺ��� ���� ������ �ٽ� �������� ���� �� ����.)
				{
					if ((chg1 == 10 || chg2 == 10) && change_10 == true) break;
					if ((chg1 == 11 || chg2 == 11) && change_11 == true) break;
					if ((chg1 == 12 || chg2 == 12) && change_12 == true) break;
					if ((chg1 == 13 || chg2 == 13) && change_13 == true) break;
					if ((chg1 == 14 || chg2 == 14) && change_14 == true) break;
					if ((chg1 == 15 || chg2 == 15) && change_15 == true) break;
					if ((chg1 == 16 || chg2 == 16) && change_16 == true) break;

					switch (chg1)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

					switch (chg2)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

				}

			}

			if (trade == true && (print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 || chg2 < 10) && hhh.dom_() != 1 && hh.dom_() != 1)) break;
			if (trade == true && print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 && chg2 < 10) && (hhh.dom_() != 1 || hh.dom_() != 1)) break;
			if (trade == true && (double)(hh.stat(total_gam) * tra) < hhh.stat(total_gam)) break;

			if (hh.pos_() != hhh.pos_() && (print_check(hh.pos_(), hhh.pos_()) == 1) && !(chg1 < 10 && chg2 < 10))
			{
				save = hh.pos_();

				hh.change_pos_(change_pos(hhh.pos_()));

				hhh.change_pos_(save);


			}

			if (trade == true) {

				if (hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			else {

				if (!(chg1 < 10 && chg2 < 10) && hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (!(chg1 < 10 && chg2 < 10) && hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			hhhh.cn_(hh.num_()); //X��Ÿ�� ����
			hh.cn_(hhh.num_());
			hhh.cn_(hhhh.num_());



			switch (chg1) {
			case 1: memcpy(&h31, &hhh, sizeof(class hitter)); break;
			case 2: memcpy(&h32, &hhh, sizeof(class hitter)); break;
			case 3: memcpy(&h33, &hhh, sizeof(class hitter)); break;
			case 4: memcpy(&h34, &hhh, sizeof(class hitter)); break;
			case 5: memcpy(&h35, &hhh, sizeof(class hitter)); break;
			case 6: memcpy(&h36, &hhh, sizeof(class hitter)); break;
			case 7: memcpy(&h37, &hhh, sizeof(class hitter)); break;
			case 8: memcpy(&h38, &hhh, sizeof(class hitter)); break;
			case 9: memcpy(&h39, &hhh, sizeof(class hitter)); break;
			case 10: memcpy(&h40, &hhh, sizeof(class hitter)); break;
			case 11: memcpy(&h41, &hhh, sizeof(class hitter)); break;
			case 12: memcpy(&h42, &hhh, sizeof(class hitter)); break;
			case 13: memcpy(&h43, &hhh, sizeof(class hitter)); break;
			case 14: memcpy(&h44, &hhh, sizeof(class hitter)); break;
			case 15: memcpy(&h45, &hhh, sizeof(class hitter)); break;
			case 16: memcpy(&h46, &hhh, sizeof(class hitter)); break;
			}

			if (chg2 == 17) break;

			if (trade == true) {


				switch (tr) {
				case 0:
					switch (chg2) {
					case 1: memcpy(&h1, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h2, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h3, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h4, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h5, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h6, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h7, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h8, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h9, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h10, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h11, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h12, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h13, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h14, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h15, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h16, &hh, sizeof(class hitter)); break;
					}
					break;

				case 2:
					switch (chg2) {
					case 1: memcpy(&h61, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h62, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h63, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h64, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h65, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h66, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h67, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h68, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h69, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h70, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h71, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h72, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h73, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h74, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h75, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h76, &hh, sizeof(class hitter)); break;
					}
					break;

				case 3:
					switch (chg2) {
					case 1: memcpy(&h91, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h92, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h93, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h94, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h95, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h96, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h97, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h98, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h99, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h100, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h101, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h102, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h103, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h104, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h105, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h106, &hh, sizeof(class hitter)); break;
					}
					break;

				case 4:
					switch (chg2) {
					case 1: memcpy(&h131, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h132, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h133, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h134, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h135, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h136, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h137, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h138, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h139, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h140, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h141, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h142, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h143, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h144, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h145, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h146, &hh, sizeof(class hitter)); break;
					}
					break;

				case 5:
					switch (chg2) {
					case 1: memcpy(&h161, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h162, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h163, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h164, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h165, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h166, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h167, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h168, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h169, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h170, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h171, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h172, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h173, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h174, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h175, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h176, &hh, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) > hhh.stat(total_gam) + 1) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&h31, &hh, sizeof(class hitter)); break;
				case 2: memcpy(&h32, &hh, sizeof(class hitter)); break;
				case 3: memcpy(&h33, &hh, sizeof(class hitter)); break;
				case 4: memcpy(&h34, &hh, sizeof(class hitter)); break;
				case 5: memcpy(&h35, &hh, sizeof(class hitter)); break;
				case 6: memcpy(&h36, &hh, sizeof(class hitter)); break;
				case 7: memcpy(&h37, &hh, sizeof(class hitter)); break;
				case 8: memcpy(&h38, &hh, sizeof(class hitter)); break;
				case 9: memcpy(&h39, &hh, sizeof(class hitter)); break;
				case 10: memcpy(&h40, &hh, sizeof(class hitter)); break;
				case 11: memcpy(&h41, &hh, sizeof(class hitter)); break;
				case 12: memcpy(&h42, &hh, sizeof(class hitter)); break;
				case 13: memcpy(&h43, &hh, sizeof(class hitter)); break;
				case 14: memcpy(&h44, &hh, sizeof(class hitter)); break;
				case 15: memcpy(&h45, &hh, sizeof(class hitter)); break;
				case 16: memcpy(&h46, &hh, sizeof(class hitter)); break;
				}
			}
			break;



		}


		else if (my_team == 2) {  // �츮�� �Ｚ

			sel(&chg1, 15, 6, 2, 17); // �Ե��� chg3, chg4
			if (chg1 == 17) break;

			if (trade == false) {
				sel(&chg2, 15, 6, 2, 17);
				if (chg2 == 17) break;
			}

			//  ch_h()

			switch (chg1) {
			case 1: memcpy(&hh, &h61, sizeof(class hitter)); break;
			case 2: memcpy(&hh, &h62, sizeof(class hitter)); break;
			case 3: memcpy(&hh, &h63, sizeof(class hitter)); break;
			case 4: memcpy(&hh, &h64, sizeof(class hitter)); break;
			case 5: memcpy(&hh, &h65, sizeof(class hitter)); break;
			case 6: memcpy(&hh, &h66, sizeof(class hitter)); break;
			case 7: memcpy(&hh, &h67, sizeof(class hitter)); break;
			case 8: memcpy(&hh, &h68, sizeof(class hitter)); break;
			case 9: memcpy(&hh, &h69, sizeof(class hitter)); break;
			case 10: memcpy(&hh, &h70, sizeof(class hitter)); break;
			case 11: memcpy(&hh, &h71, sizeof(class hitter)); break;
			case 12: memcpy(&hh, &h72, sizeof(class hitter)); break;
			case 13: memcpy(&hh, &h73, sizeof(class hitter)); break;
			case 14: memcpy(&hh, &h74, sizeof(class hitter)); break;
			case 15: memcpy(&hh, &h75, sizeof(class hitter)); break;
			case 16: memcpy(&hh, &h76, sizeof(class hitter)); break;
			}



			if (trade == true) { // Ʈ���̵� ����

				cur(0, 38); cout << "    [  ���  ] " << '\n';

				system("cls");

				cout << "Ʈ���̵� �� ��븦 �������ֽʽÿ� : " << '\n'
					<< "[0] �Ｚ" << '\n' << "[1] �Ե�" << '\n' << "[2] NC" << '\n' << "[3] �λ�" << '\n' << "[4] LG" << '\n' << "[5] SSG" << '\n' << "[9] ���";

				cur(36, 0);
				cin >> tr;

				if (tr != 0 && tr != 1 && tr != 3 && tr != 4 && tr != 5) break;

				system("cls");

				cout << hh.stat(total_gam) << '\n';

				switch (tr) {
				case 1:
					print_hitter_record(total_gam, 1, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h31, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h32, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h33, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h34, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h35, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h36, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h37, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h38, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h39, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h40, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h41, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h42, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h43, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h44, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h45, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h46, sizeof(class hitter)); break;
					}
					break;

				case 0:
					print_hitter_record(total_gam, 0, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h1, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h2, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h3, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h4, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h5, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h6, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h7, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h8, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h9, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h10, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h11, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h12, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h13, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h14, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h15, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h16, sizeof(class hitter)); break;
					}
					break;

				case 3:
					print_hitter_record(total_gam, 3, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h91, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h92, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h93, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h94, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h95, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h96, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h97, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h98, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h99, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h100, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h101, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h102, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h103, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h104, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h105, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h106, sizeof(class hitter)); break;
					}
					break;

				case 4:
					print_hitter_record(total_gam, 4, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h131, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h132, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h133, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h134, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h135, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h136, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h137, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h138, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h139, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h140, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h141, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h142, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h143, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h144, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h145, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h146, sizeof(class hitter)); break;
					}
					break;

				case 5:
					print_hitter_record(total_gam, 5, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h161, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h162, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h163, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h164, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h165, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h166, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h167, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h168, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h169, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h170, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h171, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h172, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h173, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h174, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h175, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h176, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) - 1 <= hhh.stat(total_gam)) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&hhh, &h61, sizeof(class hitter)); break;
				case 2: memcpy(&hhh, &h62, sizeof(class hitter)); break;
				case 3: memcpy(&hhh, &h63, sizeof(class hitter)); break;
				case 4: memcpy(&hhh, &h64, sizeof(class hitter)); break;
				case 5: memcpy(&hhh, &h65, sizeof(class hitter)); break;
				case 6: memcpy(&hhh, &h66, sizeof(class hitter)); break;
				case 7: memcpy(&hhh, &h67, sizeof(class hitter)); break;
				case 8: memcpy(&hhh, &h68, sizeof(class hitter)); break;
				case 9: memcpy(&hhh, &h69, sizeof(class hitter)); break;
				case 10: memcpy(&hhh, &h70, sizeof(class hitter)); break;
				case 11: memcpy(&hhh, &h71, sizeof(class hitter)); break;
				case 12: memcpy(&hhh, &h72, sizeof(class hitter)); break;
				case 13: memcpy(&hhh, &h73, sizeof(class hitter)); break;
				case 14: memcpy(&hhh, &h74, sizeof(class hitter)); break;
				case 15: memcpy(&hhh, &h75, sizeof(class hitter)); break;
				case 16: memcpy(&hhh, &h76, sizeof(class hitter)); break;
				}

				if (print_check(hh.pos_(), hhh.pos_()) != 1 && hh.dom_() != 1 && hhh.dom_() != 1 && !(chg1 < 10 && chg2 < 10))
				{
					break;
				}

				if (total_gam == -5 && (chg1 < 10 && chg2 < 10) || (chg1 >= 10 && chg2 >= 10)) break;

				if (total_gam == -5) //��ü �ǿ���� (�ѹ� �ĺ��� ���� ������ �ٽ� �������� ���� �� ����.)
				{
					if ((chg1 == 10 || chg2 == 10) && change_10 == true) break;
					if ((chg1 == 11 || chg2 == 11) && change_11 == true) break;
					if ((chg1 == 12 || chg2 == 12) && change_12 == true) break;
					if ((chg1 == 13 || chg2 == 13) && change_13 == true) break;
					if ((chg1 == 14 || chg2 == 14) && change_14 == true) break;
					if ((chg1 == 15 || chg2 == 15) && change_15 == true) break;
					if ((chg1 == 16 || chg2 == 16) && change_16 == true) break;

					switch (chg1)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

					switch (chg2)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

				}


			}

			if (trade == true && (print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 || chg2 < 10) && hhh.dom_() != 1 && hh.dom_() != 1)) break;
			if (trade == true && print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 && chg2 < 10) && (hhh.dom_() != 1 || hh.dom_() != 1)) break;
			if (trade == true && (double)(hh.stat(total_gam) * tra) < hhh.stat(total_gam)) break;

			if (hh.pos_() != hhh.pos_() && (print_check(hh.pos_(), hhh.pos_()) == 1) && !(chg1 < 10 && chg2 < 10))
			{
				save = hh.pos_();

				hh.change_pos_(change_pos(hhh.pos_()));

				hhh.change_pos_(save);


			}

			if (trade == true) {

				if (hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			else {

				if (!(chg1 < 10 && chg2 < 10) && hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (!(chg1 < 10 && chg2 < 10) && hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			hhhh.cn_(hh.num_()); //X��Ÿ�� ����
			hh.cn_(hhh.num_());
			hhh.cn_(hhhh.num_());



			switch (chg1) {
			case 1: memcpy(&h61, &hhh, sizeof(class hitter)); break;
			case 2: memcpy(&h62, &hhh, sizeof(class hitter)); break;
			case 3: memcpy(&h63, &hhh, sizeof(class hitter)); break;
			case 4: memcpy(&h64, &hhh, sizeof(class hitter)); break;
			case 5: memcpy(&h65, &hhh, sizeof(class hitter)); break;
			case 6: memcpy(&h66, &hhh, sizeof(class hitter)); break;
			case 7: memcpy(&h67, &hhh, sizeof(class hitter)); break;
			case 8: memcpy(&h68, &hhh, sizeof(class hitter)); break;
			case 9: memcpy(&h69, &hhh, sizeof(class hitter)); break;
			case 10: memcpy(&h70, &hhh, sizeof(class hitter)); break;
			case 11: memcpy(&h71, &hhh, sizeof(class hitter)); break;
			case 12: memcpy(&h72, &hhh, sizeof(class hitter)); break;
			case 13: memcpy(&h73, &hhh, sizeof(class hitter)); break;
			case 14: memcpy(&h74, &hhh, sizeof(class hitter)); break;
			case 15: memcpy(&h75, &hhh, sizeof(class hitter)); break;
			case 16: memcpy(&h76, &hhh, sizeof(class hitter)); break;
			}


			if (trade == true) {



				switch (tr) {

				case 0:
					switch (chg2) {
					case 1: memcpy(&h1, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h2, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h3, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h4, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h5, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h6, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h7, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h8, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h9, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h10, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h11, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h12, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h13, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h14, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h15, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h16, &hh, sizeof(class hitter)); break;
					}
					break;

				case 1:
					switch (chg2) {
					case 1: memcpy(&h31, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h32, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h33, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h34, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h35, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h36, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h37, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h38, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h39, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h40, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h41, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h42, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h43, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h44, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h45, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h46, &hh, sizeof(class hitter)); break;
					}
					break;



				case 3:
					switch (chg2) {
					case 1: memcpy(&h91, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h92, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h93, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h94, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h95, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h96, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h97, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h98, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h99, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h100, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h101, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h102, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h103, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h104, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h105, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h106, &hh, sizeof(class hitter)); break;
					}
					break;

				case 4:
					switch (chg2) {
					case 1: memcpy(&h131, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h132, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h133, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h134, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h135, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h136, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h137, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h138, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h139, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h140, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h141, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h142, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h143, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h144, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h145, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h146, &hh, sizeof(class hitter)); break;
					}
					break;

				case 5:
					switch (chg2) {
					case 1: memcpy(&h161, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h162, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h163, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h164, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h165, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h166, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h167, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h168, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h169, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h170, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h171, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h172, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h173, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h174, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h175, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h176, &hh, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}



			}

			else {

				switch (chg2) {
				case 1: memcpy(&h61, &hh, sizeof(class hitter)); break;
				case 2: memcpy(&h62, &hh, sizeof(class hitter)); break;
				case 3: memcpy(&h63, &hh, sizeof(class hitter)); break;
				case 4: memcpy(&h64, &hh, sizeof(class hitter)); break;
				case 5: memcpy(&h65, &hh, sizeof(class hitter)); break;
				case 6: memcpy(&h66, &hh, sizeof(class hitter)); break;
				case 7: memcpy(&h67, &hh, sizeof(class hitter)); break;
				case 8: memcpy(&h68, &hh, sizeof(class hitter)); break;
				case 9: memcpy(&h69, &hh, sizeof(class hitter)); break;
				case 10: memcpy(&h70, &hh, sizeof(class hitter)); break;
				case 11: memcpy(&h71, &hh, sizeof(class hitter)); break;
				case 12: memcpy(&h72, &hh, sizeof(class hitter)); break;
				case 13: memcpy(&h73, &hh, sizeof(class hitter)); break;
				case 14: memcpy(&h74, &hh, sizeof(class hitter)); break;
				case 15: memcpy(&h75, &hh, sizeof(class hitter)); break;
				case 16: memcpy(&h76, &hh, sizeof(class hitter)); break;
				}
			}
			break;



		}




		else if (my_team == 3) {  // �츮�� �Ｚ

			sel(&chg1, 15, 6, 2, 17); // �Ե��� chg3, chg4
			if (chg1 == 17) break;

			if (trade == false) {
				sel(&chg2, 15, 6, 2, 17);
				if (chg2 == 17) break;
			}

			//  ch_h()

			switch (chg1) {
			case 1: memcpy(&hh, &h91, sizeof(class hitter)); break;
			case 2: memcpy(&hh, &h92, sizeof(class hitter)); break;
			case 3: memcpy(&hh, &h93, sizeof(class hitter)); break;
			case 4: memcpy(&hh, &h94, sizeof(class hitter)); break;
			case 5: memcpy(&hh, &h95, sizeof(class hitter)); break;
			case 6: memcpy(&hh, &h96, sizeof(class hitter)); break;
			case 7: memcpy(&hh, &h97, sizeof(class hitter)); break;
			case 8: memcpy(&hh, &h98, sizeof(class hitter)); break;
			case 9: memcpy(&hh, &h99, sizeof(class hitter)); break;
			case 10: memcpy(&hh, &h100, sizeof(class hitter)); break;
			case 11: memcpy(&hh, &h101, sizeof(class hitter)); break;
			case 12: memcpy(&hh, &h102, sizeof(class hitter)); break;
			case 13: memcpy(&hh, &h103, sizeof(class hitter)); break;
			case 14: memcpy(&hh, &h104, sizeof(class hitter)); break;
			case 15: memcpy(&hh, &h105, sizeof(class hitter)); break;
			case 16: memcpy(&hh, &h106, sizeof(class hitter)); break;
			}



			if (trade == true) { // Ʈ���̵� ����

				cur(0, 38); cout << "    [  ���  ] " << '\n';

				system("cls");

				cout << "Ʈ���̵� �� ��븦 �������ֽʽÿ� : " << '\n'
					<< "[0] �Ｚ" << '\n' << "[1] �Ե�" << '\n' << "[2] NC" << '\n' << "[3] �λ�" << '\n' << "[4] LG" << '\n' << "[5] SSG" << '\n' << "[9] ���";

				cur(36, 0);
				cin >> tr;

				if (tr != 0 && tr != 1 && tr != 2 && tr != 4 && tr != 5) break;


				system("cls");

				cout << hh.stat(total_gam) << '\n';

				switch (tr) {
				case 1:
					print_hitter_record(total_gam, 1, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h31, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h32, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h33, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h34, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h35, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h36, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h37, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h38, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h39, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h40, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h41, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h42, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h43, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h44, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h45, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h46, sizeof(class hitter)); break;
					}
					break;

				case 0:
					print_hitter_record(total_gam, 0, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h1, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h2, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h3, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h4, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h5, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h6, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h7, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h8, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h9, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h10, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h11, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h12, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h13, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h14, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h15, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h16, sizeof(class hitter)); break;
					}
					break;

				case 2:
					print_hitter_record(total_gam, 2, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h61, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h62, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h63, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h64, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h65, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h66, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h67, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h68, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h69, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h70, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h71, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h72, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h73, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h74, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h75, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h76, sizeof(class hitter)); break;
					}
					break;

				case 4:
					print_hitter_record(total_gam, 4, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h131, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h132, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h133, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h134, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h135, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h136, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h137, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h138, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h139, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h140, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h141, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h142, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h143, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h144, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h145, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h146, sizeof(class hitter)); break;
					}
					break;

				case 5:
					print_hitter_record(total_gam, 5, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h161, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h162, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h163, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h164, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h165, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h166, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h167, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h168, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h169, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h170, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h171, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h172, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h173, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h174, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h175, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h176, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}


			}

			else {

				switch (chg2) {
				case 1: memcpy(&hhh, &h91, sizeof(class hitter)); break;
				case 2: memcpy(&hhh, &h92, sizeof(class hitter)); break;
				case 3: memcpy(&hhh, &h93, sizeof(class hitter)); break;
				case 4: memcpy(&hhh, &h94, sizeof(class hitter)); break;
				case 5: memcpy(&hhh, &h95, sizeof(class hitter)); break;
				case 6: memcpy(&hhh, &h96, sizeof(class hitter)); break;
				case 7: memcpy(&hhh, &h97, sizeof(class hitter)); break;
				case 8: memcpy(&hhh, &h98, sizeof(class hitter)); break;
				case 9: memcpy(&hhh, &h99, sizeof(class hitter)); break;
				case 10: memcpy(&hhh, &h100, sizeof(class hitter)); break;
				case 11: memcpy(&hhh, &h101, sizeof(class hitter)); break;
				case 12: memcpy(&hhh, &h102, sizeof(class hitter)); break;
				case 13: memcpy(&hhh, &h103, sizeof(class hitter)); break;
				case 14: memcpy(&hhh, &h104, sizeof(class hitter)); break;
				case 15: memcpy(&hhh, &h105, sizeof(class hitter)); break;
				case 16: memcpy(&hhh, &h106, sizeof(class hitter)); break;
				}

				if (print_check(hh.pos_(), hhh.pos_()) != 1 && hh.dom_() != 1 && hhh.dom_() != 1 && !(chg1 < 10 && chg2 < 10))
				{
					break;
				}

				if (total_gam == -5 && (chg1 < 10 && chg2 < 10) || (chg1 >= 10 && chg2 >= 10)) break;

				if (total_gam == -5) //��ü �ǿ���� (�ѹ� �ĺ��� ���� ������ �ٽ� �������� ���� �� ����.)
				{
					if ((chg1 == 10 || chg2 == 10) && change_10 == true) break;
					if ((chg1 == 11 || chg2 == 11) && change_11 == true) break;
					if ((chg1 == 12 || chg2 == 12) && change_12 == true) break;
					if ((chg1 == 13 || chg2 == 13) && change_13 == true) break;
					if ((chg1 == 14 || chg2 == 14) && change_14 == true) break;
					if ((chg1 == 15 || chg2 == 15) && change_15 == true) break;
					if ((chg1 == 16 || chg2 == 16) && change_16 == true) break;

					switch (chg1)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

					switch (chg2)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

				}

			}

			if (trade == true && (print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 || chg2 < 10) && hhh.dom_() != 1 && hh.dom_() != 1)) break;
			if (trade == true && print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 && chg2 < 10) && (hhh.dom_() != 1 || hh.dom_() != 1)) break;
			if (trade == true && (double)(hh.stat(total_gam) * tra) < hhh.stat(total_gam)) break;

			if (hh.pos_() != hhh.pos_() && (print_check(hh.pos_(), hhh.pos_()) == 1) && !(chg1 < 10 && chg2 < 10))
			{
				save = hh.pos_();

				hh.change_pos_(change_pos(hhh.pos_()));

				hhh.change_pos_(save);


			}

			if (trade == true) {

				if (hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			else {

				if (!(chg1 < 10 && chg2 < 10) && hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (!(chg1 < 10 && chg2 < 10) && hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			hhhh.cn_(hh.num_()); //X��Ÿ�� ����
			hh.cn_(hhh.num_());
			hhh.cn_(hhhh.num_());



			switch (chg1) {
			case 1: memcpy(&h91, &hhh, sizeof(class hitter)); break;
			case 2: memcpy(&h92, &hhh, sizeof(class hitter)); break;
			case 3: memcpy(&h93, &hhh, sizeof(class hitter)); break;
			case 4: memcpy(&h94, &hhh, sizeof(class hitter)); break;
			case 5: memcpy(&h95, &hhh, sizeof(class hitter)); break;
			case 6: memcpy(&h96, &hhh, sizeof(class hitter)); break;
			case 7: memcpy(&h97, &hhh, sizeof(class hitter)); break;
			case 8: memcpy(&h98, &hhh, sizeof(class hitter)); break;
			case 9: memcpy(&h99, &hhh, sizeof(class hitter)); break;
			case 10: memcpy(&h100, &hhh, sizeof(class hitter)); break;
			case 11: memcpy(&h101, &hhh, sizeof(class hitter)); break;
			case 12: memcpy(&h102, &hhh, sizeof(class hitter)); break;
			case 13: memcpy(&h103, &hhh, sizeof(class hitter)); break;
			case 14: memcpy(&h104, &hhh, sizeof(class hitter)); break;
			case 15: memcpy(&h105, &hhh, sizeof(class hitter)); break;
			case 16: memcpy(&h106, &hhh, sizeof(class hitter)); break;
			}


			if (trade == true) {



				switch (tr) {
				case 1:
					switch (chg2) {
					case 1: memcpy(&h31, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h32, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h33, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h34, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h35, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h36, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h37, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h38, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h39, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h40, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h41, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h42, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h43, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h44, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h45, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h46, &hh, sizeof(class hitter)); break;
					}
					break;

				case 0:
					switch (chg2) {
					case 1: memcpy(&h1, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h2, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h3, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h4, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h5, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h6, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h7, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h8, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h9, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h10, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h11, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h12, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h13, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h14, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h15, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h16, &hh, sizeof(class hitter)); break;
					}
					break;

				case 2:
					switch (chg2) {
					case 1: memcpy(&h61, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h62, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h63, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h64, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h65, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h66, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h67, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h68, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h69, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h70, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h71, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h72, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h73, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h74, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h75, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h76, &hh, sizeof(class hitter)); break;
					}
					break;

				case 4:
					switch (chg2) {
					case 1: memcpy(&h131, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h132, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h133, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h134, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h135, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h136, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h137, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h138, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h139, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h140, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h141, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h142, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h143, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h144, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h145, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h146, &hh, sizeof(class hitter)); break;
					}
					break;

				case 5:
					switch (chg2) {
					case 1: memcpy(&h161, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h162, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h163, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h164, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h165, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h166, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h167, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h168, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h169, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h170, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h171, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h172, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h173, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h174, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h175, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h176, &hh, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}



			}

			else {

				switch (chg2) {
				case 1: memcpy(&h91, &hh, sizeof(class hitter)); break;
				case 2: memcpy(&h92, &hh, sizeof(class hitter)); break;
				case 3: memcpy(&h93, &hh, sizeof(class hitter)); break;
				case 4: memcpy(&h94, &hh, sizeof(class hitter)); break;
				case 5: memcpy(&h95, &hh, sizeof(class hitter)); break;
				case 6: memcpy(&h96, &hh, sizeof(class hitter)); break;
				case 7: memcpy(&h97, &hh, sizeof(class hitter)); break;
				case 8: memcpy(&h98, &hh, sizeof(class hitter)); break;
				case 9: memcpy(&h99, &hh, sizeof(class hitter)); break;
				case 10: memcpy(&h100, &hh, sizeof(class hitter)); break;
				case 11: memcpy(&h101, &hh, sizeof(class hitter)); break;
				case 12: memcpy(&h102, &hh, sizeof(class hitter)); break;
				case 13: memcpy(&h103, &hh, sizeof(class hitter)); break;
				case 14: memcpy(&h104, &hh, sizeof(class hitter)); break;
				case 15: memcpy(&h105, &hh, sizeof(class hitter)); break;
				case 16: memcpy(&h106, &hh, sizeof(class hitter)); break;
				}
			}
			break;



		}


		else if (my_team == 4) {  // �츮�� �Ｚ

			sel(&chg1, 15, 6, 2, 17); // �Ե��� chg3, chg4
			if (chg1 == 17) break;

			if (trade == false) {
				sel(&chg2, 15, 6, 2, 17);
				if (chg2 == 17) break;
			}

			//  ch_h()

			switch (chg1) {
			case 1: memcpy(&hh, &h131, sizeof(class hitter)); break;
			case 2: memcpy(&hh, &h132, sizeof(class hitter)); break;
			case 3: memcpy(&hh, &h133, sizeof(class hitter)); break;
			case 4: memcpy(&hh, &h134, sizeof(class hitter)); break;
			case 5: memcpy(&hh, &h135, sizeof(class hitter)); break;
			case 6: memcpy(&hh, &h136, sizeof(class hitter)); break;
			case 7: memcpy(&hh, &h137, sizeof(class hitter)); break;
			case 8: memcpy(&hh, &h138, sizeof(class hitter)); break;
			case 9: memcpy(&hh, &h139, sizeof(class hitter)); break;
			case 10: memcpy(&hh, &h140, sizeof(class hitter)); break;
			case 11: memcpy(&hh, &h141, sizeof(class hitter)); break;
			case 12: memcpy(&hh, &h142, sizeof(class hitter)); break;
			case 13: memcpy(&hh, &h143, sizeof(class hitter)); break;
			case 14: memcpy(&hh, &h144, sizeof(class hitter)); break;
			case 15: memcpy(&hh, &h145, sizeof(class hitter)); break;
			case 16: memcpy(&hh, &h146, sizeof(class hitter)); break;
			}



			if (trade == true) { // Ʈ���̵� ����

				cur(0, 38); cout << "    [  ���  ] " << '\n';

				system("cls");

				cout << "Ʈ���̵� �� ��븦 �������ֽʽÿ� : " << '\n'
					<< "[0] �Ｚ" << '\n' << "[1] �Ե�" << '\n' << "[2] NC" << '\n' << "[3] �λ�" << '\n' << "[4] LG" << '\n' << "[5] SSG" << '\n' << "[9] ���";

				cur(36, 0);
				cin >> tr;



				if (tr != 0 && tr != 1 && tr != 2 && tr != 3 && tr != 5) break;

				system("cls");

				cout << hh.stat(total_gam) << '\n';

				switch (tr) {
				case 0:
					print_hitter_record(total_gam, 0, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h1, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h2, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h3, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h4, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h5, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h6, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h7, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h8, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h9, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h10, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h11, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h12, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h13, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h14, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h15, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h16, sizeof(class hitter)); break;
					}
					break;

				case 1:
					print_hitter_record(total_gam, 1, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h31, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h32, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h33, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h34, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h35, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h36, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h37, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h38, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h39, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h40, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h41, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h42, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h43, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h44, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h45, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h46, sizeof(class hitter)); break;
					}
					break;

				case 2:
					print_hitter_record(total_gam, 2, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h61, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h62, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h63, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h64, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h65, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h66, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h67, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h68, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h69, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h70, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h71, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h72, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h73, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h74, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h75, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h76, sizeof(class hitter)); break;
					}
					break;

				case 3:
					print_hitter_record(total_gam, 3, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h91, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h92, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h93, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h94, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h95, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h96, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h97, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h98, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h99, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h100, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h101, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h102, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h103, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h104, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h105, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h106, sizeof(class hitter)); break;
					}
					break;


				case 5:
					print_hitter_record(total_gam, 5, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h161, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h162, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h163, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h164, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h165, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h166, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h167, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h168, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h169, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h170, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h171, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h172, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h173, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h174, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h175, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h176, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) - 1 <= hhh.stat(total_gam)) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&hhh, &h131, sizeof(class hitter)); break;
				case 2: memcpy(&hhh, &h132, sizeof(class hitter)); break;
				case 3: memcpy(&hhh, &h133, sizeof(class hitter)); break;
				case 4: memcpy(&hhh, &h134, sizeof(class hitter)); break;
				case 5: memcpy(&hhh, &h135, sizeof(class hitter)); break;
				case 6: memcpy(&hhh, &h136, sizeof(class hitter)); break;
				case 7: memcpy(&hhh, &h137, sizeof(class hitter)); break;
				case 8: memcpy(&hhh, &h138, sizeof(class hitter)); break;
				case 9: memcpy(&hhh, &h139, sizeof(class hitter)); break;
				case 10: memcpy(&hhh, &h140, sizeof(class hitter)); break;
				case 11: memcpy(&hhh, &h141, sizeof(class hitter)); break;
				case 12: memcpy(&hhh, &h142, sizeof(class hitter)); break;
				case 13: memcpy(&hhh, &h143, sizeof(class hitter)); break;
				case 14: memcpy(&hhh, &h144, sizeof(class hitter)); break;
				case 15: memcpy(&hhh, &h145, sizeof(class hitter)); break;
				case 16: memcpy(&hhh, &h146, sizeof(class hitter)); break;
				}

				if (print_check(hh.pos_(), hhh.pos_()) != 1 && hh.dom_() != 1 && hhh.dom_() != 1 && !(chg1 < 10 && chg2 < 10))
				{
					break;
				}

				if (total_gam == -5 && (chg1 < 10 && chg2 < 10) || (chg1 >= 10 && chg2 >= 10)) break;

				if (total_gam == -5) //��ü �ǿ���� (�ѹ� �ĺ��� ���� ������ �ٽ� �������� ���� �� ����.)
				{
					if ((chg1 == 10 || chg2 == 10) && change_10 == true) break;
					if ((chg1 == 11 || chg2 == 11) && change_11 == true) break;
					if ((chg1 == 12 || chg2 == 12) && change_12 == true) break;
					if ((chg1 == 13 || chg2 == 13) && change_13 == true) break;
					if ((chg1 == 14 || chg2 == 14) && change_14 == true) break;
					if ((chg1 == 15 || chg2 == 15) && change_15 == true) break;
					if ((chg1 == 16 || chg2 == 16) && change_16 == true) break;

					switch (chg1)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

					switch (chg2)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

				}

			}

			if (trade == true && (print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 || chg2 < 10) && hhh.dom_() != 1 && hh.dom_() != 1)) break;
			if (trade == true && print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 && chg2 < 10) && (hhh.dom_() != 1 || hh.dom_() != 1)) break;
			if (trade == true && (double)(hh.stat(total_gam) * tra) < hhh.stat(total_gam)) break;

			if (hh.pos_() != hhh.pos_() && (print_check(hh.pos_(), hhh.pos_()) == 1) && !(chg1 < 10 && chg2 < 10))
			{
				save = hh.pos_();

				hh.change_pos_(change_pos(hhh.pos_()));

				hhh.change_pos_(save);


			}

			if (trade == true) {

				if (hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			else {

				if (!(chg1 < 10 && chg2 < 10) && hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (!(chg1 < 10 && chg2 < 10) && hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			hhhh.cn_(hh.num_()); //X��Ÿ�� ����
			hh.cn_(hhh.num_());
			hhh.cn_(hhhh.num_());



			switch (chg1) {
			case 1: memcpy(&h131, &hhh, sizeof(class hitter)); break;
			case 2: memcpy(&h132, &hhh, sizeof(class hitter)); break;
			case 3: memcpy(&h133, &hhh, sizeof(class hitter)); break;
			case 4: memcpy(&h134, &hhh, sizeof(class hitter)); break;
			case 5: memcpy(&h135, &hhh, sizeof(class hitter)); break;
			case 6: memcpy(&h136, &hhh, sizeof(class hitter)); break;
			case 7: memcpy(&h137, &hhh, sizeof(class hitter)); break;
			case 8: memcpy(&h138, &hhh, sizeof(class hitter)); break;
			case 9: memcpy(&h139, &hhh, sizeof(class hitter)); break;
			case 10: memcpy(&h140, &hhh, sizeof(class hitter)); break;
			case 11: memcpy(&h141, &hhh, sizeof(class hitter)); break;
			case 12: memcpy(&h142, &hhh, sizeof(class hitter)); break;
			case 13: memcpy(&h143, &hhh, sizeof(class hitter)); break;
			case 14: memcpy(&h144, &hhh, sizeof(class hitter)); break;
			case 15: memcpy(&h145, &hhh, sizeof(class hitter)); break;
			case 16: memcpy(&h146, &hhh, sizeof(class hitter)); break;
			}


			if (trade == true) {



				switch (tr) {
				case 1:
					switch (chg2) {
					case 1: memcpy(&h31, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h32, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h33, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h34, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h35, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h36, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h37, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h38, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h39, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h40, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h41, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h42, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h43, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h44, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h45, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h46, &hh, sizeof(class hitter)); break;
					}
					break;

				case 0:
					switch (chg2) {
					case 1: memcpy(&h1, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h2, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h3, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h4, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h5, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h6, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h7, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h8, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h9, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h10, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h11, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h12, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h13, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h14, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h15, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h16, &hh, sizeof(class hitter)); break;
					}
					break;

				case 2:
					switch (chg2) {
					case 1: memcpy(&h61, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h62, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h63, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h64, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h65, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h66, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h67, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h68, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h69, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h70, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h71, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h72, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h73, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h74, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h75, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h76, &hh, sizeof(class hitter)); break;
					}
					break;

				case 3:
					switch (chg2) {
					case 1: memcpy(&h91, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h92, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h93, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h94, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h95, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h96, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h97, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h98, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h99, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h100, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h101, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h102, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h103, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h104, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h105, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h106, &hh, sizeof(class hitter)); break;
					}
					break;


				case 5:
					switch (chg2) {
					case 1: memcpy(&h161, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h162, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h163, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h164, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h165, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h166, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h167, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h168, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h169, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h170, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h171, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h172, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h173, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h174, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h175, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h176, &hh, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}



			}

			else {

				switch (chg2) {
				case 1: memcpy(&h131, &hh, sizeof(class hitter)); break;
				case 2: memcpy(&h132, &hh, sizeof(class hitter)); break;
				case 3: memcpy(&h133, &hh, sizeof(class hitter)); break;
				case 4: memcpy(&h134, &hh, sizeof(class hitter)); break;
				case 5: memcpy(&h135, &hh, sizeof(class hitter)); break;
				case 6: memcpy(&h136, &hh, sizeof(class hitter)); break;
				case 7: memcpy(&h137, &hh, sizeof(class hitter)); break;
				case 8: memcpy(&h138, &hh, sizeof(class hitter)); break;
				case 9: memcpy(&h139, &hh, sizeof(class hitter)); break;
				case 10: memcpy(&h140, &hh, sizeof(class hitter)); break;
				case 11: memcpy(&h141, &hh, sizeof(class hitter)); break;
				case 12: memcpy(&h142, &hh, sizeof(class hitter)); break;
				case 13: memcpy(&h143, &hh, sizeof(class hitter)); break;
				case 14: memcpy(&h144, &hh, sizeof(class hitter)); break;
				case 15: memcpy(&h145, &hh, sizeof(class hitter)); break;
				case 16: memcpy(&h146, &hh, sizeof(class hitter)); break;
				}
			}
			break;



		}


		else if (my_team == 5) {  // �츮�� �Ｚ

			sel(&chg1, 15, 6, 2, 17); // �Ե��� chg3, chg4
			if (chg1 == 17) break;

			if (trade == false) {
				sel(&chg2, 15, 6, 2, 17);
				if (chg2 == 17) break;
			}

			//  ch_h()

			switch (chg1) {
			case 1: memcpy(&hh, &h161, sizeof(class hitter)); break;
			case 2: memcpy(&hh, &h162, sizeof(class hitter)); break;
			case 3: memcpy(&hh, &h163, sizeof(class hitter)); break;
			case 4: memcpy(&hh, &h164, sizeof(class hitter)); break;
			case 5: memcpy(&hh, &h165, sizeof(class hitter)); break;
			case 6: memcpy(&hh, &h166, sizeof(class hitter)); break;
			case 7: memcpy(&hh, &h167, sizeof(class hitter)); break;
			case 8: memcpy(&hh, &h168, sizeof(class hitter)); break;
			case 9: memcpy(&hh, &h169, sizeof(class hitter)); break;
			case 10: memcpy(&hh, &h170, sizeof(class hitter)); break;
			case 11: memcpy(&hh, &h171, sizeof(class hitter)); break;
			case 12: memcpy(&hh, &h172, sizeof(class hitter)); break;
			case 13: memcpy(&hh, &h173, sizeof(class hitter)); break;
			case 14: memcpy(&hh, &h174, sizeof(class hitter)); break;
			case 15: memcpy(&hh, &h175, sizeof(class hitter)); break;
			case 16: memcpy(&hh, &h176, sizeof(class hitter)); break;
			}



			if (trade == true) { // Ʈ���̵� ����

				cur(0, 38); cout << "    [  ���  ] " << '\n';

				system("cls");

				cout << "Ʈ���̵� �� ��븦 �������ֽʽÿ� : " << '\n'
					<< "[0] �Ｚ" << '\n' << "[1] �Ե�" << '\n' << "[2] NC" << '\n' << "[3] �λ�" << '\n' << "[4] LG" << '\n' << "[5] SSG" << '\n' << "[9] ���";

				cur(36, 0);
				cin >> tr;

				if (tr != 0 && tr != 1 && tr != 2 && tr != 3 && tr != 4) break;

				system("cls");

				cout << hh.stat(total_gam) << '\n';

				switch (tr) {
				case 1:
					print_hitter_record(total_gam, 1, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h31, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h32, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h33, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h34, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h35, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h36, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h37, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h38, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h39, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h40, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h41, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h42, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h43, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h44, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h45, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h46, sizeof(class hitter)); break;
					}
					break;

				case 0:
					print_hitter_record(total_gam, 0, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h1, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h2, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h3, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h4, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h5, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h6, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h7, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h8, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h9, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h10, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h11, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h12, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h13, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h14, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h15, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h16, sizeof(class hitter)); break;
					}
					break;

				case 2:
					print_hitter_record(total_gam, 2, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h61, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h62, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h63, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h64, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h65, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h66, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h67, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h68, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h69, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h70, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h71, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h72, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h73, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h74, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h75, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h76, sizeof(class hitter)); break;
					}
					break;

				case 3:
					print_hitter_record(total_gam, 3, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h91, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h92, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h93, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h94, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h95, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h96, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h97, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h98, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h99, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h100, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h101, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h102, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h103, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h104, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h105, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h106, sizeof(class hitter)); break;
					}
					break;

				case 4:
					print_hitter_record(total_gam, 4, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h131, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h132, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h133, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h134, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h135, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h136, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h137, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h138, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h139, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h140, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h141, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h142, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h143, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h144, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h145, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h146, sizeof(class hitter)); break;
					}
					break;

				case 5:
					print_hitter_record(total_gam, 5, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h161, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h162, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h163, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h164, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h165, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h166, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h167, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h168, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h169, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h170, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h171, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h172, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h173, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h174, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h175, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h176, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) - 1 <= hhh.stat(total_gam)) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&hhh, &h161, sizeof(class hitter)); break;
				case 2: memcpy(&hhh, &h162, sizeof(class hitter)); break;
				case 3: memcpy(&hhh, &h163, sizeof(class hitter)); break;
				case 4: memcpy(&hhh, &h164, sizeof(class hitter)); break;
				case 5: memcpy(&hhh, &h165, sizeof(class hitter)); break;
				case 6: memcpy(&hhh, &h166, sizeof(class hitter)); break;
				case 7: memcpy(&hhh, &h167, sizeof(class hitter)); break;
				case 8: memcpy(&hhh, &h168, sizeof(class hitter)); break;
				case 9: memcpy(&hhh, &h169, sizeof(class hitter)); break;
				case 10: memcpy(&hhh, &h170, sizeof(class hitter)); break;
				case 11: memcpy(&hhh, &h171, sizeof(class hitter)); break;
				case 12: memcpy(&hhh, &h172, sizeof(class hitter)); break;
				case 13: memcpy(&hhh, &h173, sizeof(class hitter)); break;
				case 14: memcpy(&hhh, &h174, sizeof(class hitter)); break;
				case 15: memcpy(&hhh, &h175, sizeof(class hitter)); break;
				case 16: memcpy(&hhh, &h176, sizeof(class hitter)); break;
				}

				if (print_check(hh.pos_(), hhh.pos_()) != 1 && hh.dom_() != 1 && hhh.dom_() != 1 && !(chg1 < 10 && chg2 < 10))
				{
					break;
				}

				if (total_gam == -5 && (chg1 < 10 && chg2 < 10) || (chg1 >= 10 && chg2 >= 10)) break;

				if (total_gam == -5) //��ü �ǿ���� (�ѹ� �ĺ��� ���� ������ �ٽ� �������� ���� �� ����.)
				{
					if ((chg1 == 10 || chg2 == 10) && change_10 == true) break;
					if ((chg1 == 11 || chg2 == 11) && change_11 == true) break;
					if ((chg1 == 12 || chg2 == 12) && change_12 == true) break;
					if ((chg1 == 13 || chg2 == 13) && change_13 == true) break;
					if ((chg1 == 14 || chg2 == 14) && change_14 == true) break;
					if ((chg1 == 15 || chg2 == 15) && change_15 == true) break;
					if ((chg1 == 16 || chg2 == 16) && change_16 == true) break;

					switch (chg1)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

					switch (chg2)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

				}

			}

			if (trade == true && (print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 || chg2 < 10) && hhh.dom_() != 1 && hh.dom_() != 1)) break;
			if (trade == true && print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 && chg2 < 10) && (hhh.dom_() != 1 || hh.dom_() != 1)) break;
			if (trade == true && (double)(hh.stat(total_gam) * tra) < hhh.stat(total_gam)) break;

			if (hh.pos_() != hhh.pos_() && (print_check(hh.pos_(), hhh.pos_()) == 1) && !(chg1 < 10 && chg2 < 10))
			{
				save = hh.pos_();

				hh.change_pos_(change_pos(hhh.pos_()));

				hhh.change_pos_(save);


			}

			if (trade == true) {

				if (hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			else {

				if (!(chg1 < 10 && chg2 < 10) && hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (!(chg1 < 10 && chg2 < 10) && hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			hhhh.cn_(hh.num_()); //X��Ÿ�� ����
			hh.cn_(hhh.num_());
			hhh.cn_(hhhh.num_());



			switch (chg1) {
			case 1: memcpy(&h161, &hhh, sizeof(class hitter)); break;
			case 2: memcpy(&h162, &hhh, sizeof(class hitter)); break;
			case 3: memcpy(&h163, &hhh, sizeof(class hitter)); break;
			case 4: memcpy(&h164, &hhh, sizeof(class hitter)); break;
			case 5: memcpy(&h165, &hhh, sizeof(class hitter)); break;
			case 6: memcpy(&h166, &hhh, sizeof(class hitter)); break;
			case 7: memcpy(&h167, &hhh, sizeof(class hitter)); break;
			case 8: memcpy(&h168, &hhh, sizeof(class hitter)); break;
			case 9: memcpy(&h169, &hhh, sizeof(class hitter)); break;
			case 10: memcpy(&h170, &hhh, sizeof(class hitter)); break;
			case 11: memcpy(&h171, &hhh, sizeof(class hitter)); break;
			case 12: memcpy(&h172, &hhh, sizeof(class hitter)); break;
			case 13: memcpy(&h173, &hhh, sizeof(class hitter)); break;
			case 14: memcpy(&h174, &hhh, sizeof(class hitter)); break;
			case 15: memcpy(&h175, &hhh, sizeof(class hitter)); break;
			case 16: memcpy(&h176, &hhh, sizeof(class hitter)); break;
			}


			if (trade == true) {



				switch (tr) {
				case 1:
					switch (chg2) {
					case 1: memcpy(&h31, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h32, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h33, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h34, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h35, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h36, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h37, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h38, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h39, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h40, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h41, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h42, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h43, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h44, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h45, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h46, &hh, sizeof(class hitter)); break;
					}
					break;

				case 0:
					switch (chg2) {
					case 1: memcpy(&h1, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h2, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h3, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h4, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h5, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h6, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h7, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h8, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h9, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h10, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h11, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h12, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h13, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h14, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h15, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h16, &hh, sizeof(class hitter)); break;
					}
					break;

				case 2:
					switch (chg2) {
					case 1: memcpy(&h61, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h62, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h63, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h64, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h65, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h66, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h67, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h68, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h69, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h70, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h71, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h72, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h73, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h74, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h75, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h76, &hh, sizeof(class hitter)); break;
					}
					break;

				case 3:
					switch (chg2) {
					case 1: memcpy(&h91, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h92, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h93, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h94, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h95, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h96, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h97, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h98, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h99, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h100, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h101, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h102, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h103, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h104, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h105, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h106, &hh, sizeof(class hitter)); break;
					}
					break;

				case 4:
					switch (chg2) {
					case 1: memcpy(&h131, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h132, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h133, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h134, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h135, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h136, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h137, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h138, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h139, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h140, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h141, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h142, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h143, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h144, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h145, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h146, &hh, sizeof(class hitter)); break;
					}
					break;

				case 5:
					switch (chg2) {
					case 1: memcpy(&h161, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h162, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h163, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h164, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h165, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h166, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h167, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h168, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h169, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h170, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h171, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h172, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h173, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h174, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h175, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h176, &hh, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}



			}

			else {

				switch (chg2) {
				case 1: memcpy(&h161, &hh, sizeof(class hitter)); break;
				case 2: memcpy(&h162, &hh, sizeof(class hitter)); break;
				case 3: memcpy(&h163, &hh, sizeof(class hitter)); break;
				case 4: memcpy(&h164, &hh, sizeof(class hitter)); break;
				case 5: memcpy(&h165, &hh, sizeof(class hitter)); break;
				case 6: memcpy(&h166, &hh, sizeof(class hitter)); break;
				case 7: memcpy(&h167, &hh, sizeof(class hitter)); break;
				case 8: memcpy(&h168, &hh, sizeof(class hitter)); break;
				case 9: memcpy(&h169, &hh, sizeof(class hitter)); break;
				case 10: memcpy(&h170, &hh, sizeof(class hitter)); break;
				case 11: memcpy(&h171, &hh, sizeof(class hitter)); break;
				case 12: memcpy(&h172, &hh, sizeof(class hitter)); break;
				case 13: memcpy(&h173, &hh, sizeof(class hitter)); break;
				case 14: memcpy(&h174, &hh, sizeof(class hitter)); break;
				case 15: memcpy(&h175, &hh, sizeof(class hitter)); break;
				case 16: memcpy(&h176, &hh, sizeof(class hitter)); break;
				}
			}
			break;




		}


		else if (my_team == 11) {  // �츮�� ����

			sel(&chg1, 15, 6, 2, 17); // �Ե��� chg3, chg4
			if (chg1 == 17) break;

			if (trade == false) {
				sel(&chg2, 15, 6, 2, 17);
				if (chg2 == 17) break;
			}

			//  ch_h()

			switch (chg1) {
			case 1: memcpy(&hh, &h8001, sizeof(class hitter)); break;
			case 2: memcpy(&hh, &h8002, sizeof(class hitter)); break;
			case 3: memcpy(&hh, &h8003, sizeof(class hitter)); break;
			case 4: memcpy(&hh, &h8004, sizeof(class hitter)); break;
			case 5: memcpy(&hh, &h8005, sizeof(class hitter)); break;
			case 6: memcpy(&hh, &h8006, sizeof(class hitter)); break;
			case 7: memcpy(&hh, &h8007, sizeof(class hitter)); break;
			case 8: memcpy(&hh, &h8008, sizeof(class hitter)); break;
			case 9: memcpy(&hh, &h8009, sizeof(class hitter)); break;
			case 10: memcpy(&hh, &h8010, sizeof(class hitter)); break;
			case 11: memcpy(&hh, &h8011, sizeof(class hitter)); break;
			case 12: memcpy(&hh, &h8012, sizeof(class hitter)); break;
			case 13: memcpy(&hh, &h8013, sizeof(class hitter)); break;
			case 14: memcpy(&hh, &h8014, sizeof(class hitter)); break;
			case 15: memcpy(&hh, &h8015, sizeof(class hitter)); break;
			case 16: memcpy(&hh, &h8016, sizeof(class hitter)); break;
			}



			if (trade == true) { // Ʈ���̵� ����

				cur(0, 38); cout << "    [  ���  ] " << '\n';

				system("cls");





				cout << "Ʈ���̵� �� ��븦 �������ֽʽÿ� : " << '\n'
					<< "[0] �Ｚ" << '\n' << "[1] �Ե�" << '\n' << "[2] NC" << '\n' << "[3] �λ�" << '\n' << "[4] LG" << '\n' << "[5] SSG" << '\n' << "[9] ���";

				cur(36, 0);
				cin >> tr;

				if (tr != 1 && tr != 2 && tr != 3 && tr != 4 && tr != 5) break;

				system("cls");

				cout << hh.stat(total_gam) << '\n';

				switch (tr) {
				case 1:
					print_hitter_record(total_gam, 1, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h31, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h32, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h33, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h34, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h35, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h36, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h37, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h38, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h39, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h40, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h41, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h42, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h43, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h44, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h45, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h46, sizeof(class hitter)); break;
					}
					break;

				case 2:
					print_hitter_record(total_gam, 2, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h61, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h62, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h63, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h64, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h65, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h66, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h67, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h68, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h69, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h70, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h71, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h72, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h73, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h74, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h75, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h76, sizeof(class hitter)); break;
					}
					break;

				case 3:
					print_hitter_record(total_gam, 3, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h91, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h92, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h93, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h94, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h95, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h96, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h97, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h98, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h99, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h100, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h101, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h102, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h103, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h104, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h105, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h106, sizeof(class hitter)); break;
					}
					break;

				case 4:
					print_hitter_record(total_gam, 4, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h131, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h132, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h133, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h134, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h135, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h136, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h137, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h138, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h139, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h140, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h141, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h142, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h143, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h144, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h145, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h146, sizeof(class hitter)); break;
					}
					break;

				case 5:
					print_hitter_record(total_gam, 5, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h161, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h162, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h163, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h164, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h165, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h166, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h167, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h168, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h169, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h170, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h171, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h172, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h173, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h174, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h175, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h176, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) - 1 <= hhh.stat(total_gam)) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&hhh, &h8001, sizeof(class hitter)); break;
				case 2: memcpy(&hhh, &h8002, sizeof(class hitter)); break;
				case 3: memcpy(&hhh, &h8003, sizeof(class hitter)); break;
				case 4: memcpy(&hhh, &h8004, sizeof(class hitter)); break;
				case 5: memcpy(&hhh, &h8005, sizeof(class hitter)); break;
				case 6: memcpy(&hhh, &h8006, sizeof(class hitter)); break;
				case 7: memcpy(&hhh, &h8007, sizeof(class hitter)); break;
				case 8: memcpy(&hhh, &h8008, sizeof(class hitter)); break;
				case 9: memcpy(&hhh, &h8009, sizeof(class hitter)); break;
				case 10: memcpy(&hhh, &h8010, sizeof(class hitter)); break;
				case 11: memcpy(&hhh, &h8011, sizeof(class hitter)); break;
				case 12: memcpy(&hhh, &h8012, sizeof(class hitter)); break;
				case 13: memcpy(&hhh, &h8013, sizeof(class hitter)); break;
				case 14: memcpy(&hhh, &h8014, sizeof(class hitter)); break;
				case 15: memcpy(&hhh, &h8015, sizeof(class hitter)); break;
				case 16: memcpy(&hhh, &h8016, sizeof(class hitter)); break;
				}



				if (print_check(hh.pos_(), hhh.pos_()) != 1 && hh.dom_() != 1 && hhh.dom_() != 1 && !(chg1 < 10 && chg2 < 10))
				{
					break;
				}

				if (total_gam == -5 && (chg1 < 10 && chg2 < 10) || (chg1 >= 10 && chg2 >= 10)) break;

				if (total_gam == -5) //��ü �ǿ���� (�ѹ� �ĺ��� ���� ������ �ٽ� �������� ���� �� ����.)
				{
					if ((chg1 == 10 || chg2 == 10) && change_10 == true) break;
					if ((chg1 == 11 || chg2 == 11) && change_11 == true) break;
					if ((chg1 == 12 || chg2 == 12) && change_12 == true) break;
					if ((chg1 == 13 || chg2 == 13) && change_13 == true) break;
					if ((chg1 == 14 || chg2 == 14) && change_14 == true) break;
					if ((chg1 == 15 || chg2 == 15) && change_15 == true) break;
					if ((chg1 == 16 || chg2 == 16) && change_16 == true) break;

					switch (chg1)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

					switch (chg2)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

				}

			}

			if (trade == true && (print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 || chg2 < 10) && hhh.dom_() != 1 && hh.dom_() != 1)) break;
			if (trade == true && print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 && chg2 < 10) && (hhh.dom_() != 1 || hh.dom_() != 1)) break;
			if (trade == true && (double)(hh.stat(total_gam) * tra) < hhh.stat(total_gam)) break;


			if (chg2 == 17) break;



			if (hh.pos_() != hhh.pos_() && (print_check(hh.pos_(), hhh.pos_()) == 1) && !(chg1 < 10 && chg2 < 10))
			{
				save = hh.pos_();

				hh.change_pos_(change_pos(hhh.pos_()));

				hhh.change_pos_(save);


			}

			if (trade == true) {

				if (hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			else {

				if (!(chg1 < 10 && chg2 < 10) && hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (!(chg1 < 10 && chg2 < 10) && hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			hhhh.cn_(hh.num_()); //X��Ÿ�� ����
			hh.cn_(hhh.num_());
			hhh.cn_(hhhh.num_());



			switch (chg1) {
			case 1: memcpy(&h8001, &hhh, sizeof(class hitter)); break;
			case 2: memcpy(&h8002, &hhh, sizeof(class hitter)); break;
			case 3: memcpy(&h8003, &hhh, sizeof(class hitter)); break;
			case 4: memcpy(&h8004, &hhh, sizeof(class hitter)); break;
			case 5: memcpy(&h8005, &hhh, sizeof(class hitter)); break;
			case 6: memcpy(&h8006, &hhh, sizeof(class hitter)); break;
			case 7: memcpy(&h8007, &hhh, sizeof(class hitter)); break;
			case 8: memcpy(&h8008, &hhh, sizeof(class hitter)); break;
			case 9: memcpy(&h8009, &hhh, sizeof(class hitter)); break;
			case 10: memcpy(&h8010, &hhh, sizeof(class hitter)); break;
			case 11: memcpy(&h8011, &hhh, sizeof(class hitter)); break;
			case 12: memcpy(&h8012, &hhh, sizeof(class hitter)); break;
			case 13: memcpy(&h8013, &hhh, sizeof(class hitter)); break;
			case 14: memcpy(&h8014, &hhh, sizeof(class hitter)); break;
			case 15: memcpy(&h8015, &hhh, sizeof(class hitter)); break;
			case 16: memcpy(&h8016, &hhh, sizeof(class hitter)); break;
			}



			if (trade == true) {

				switch (tr) {
				case 1:
					switch (chg2) {
					case 1: memcpy(&h31, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h32, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h33, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h34, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h35, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h36, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h37, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h38, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h39, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h40, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h41, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h42, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h43, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h44, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h45, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h46, &hh, sizeof(class hitter)); break;
					}
					break;

				case 2:
					switch (chg2) {
					case 1: memcpy(&h61, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h62, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h63, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h64, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h65, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h66, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h67, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h68, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h69, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h70, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h71, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h72, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h73, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h74, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h75, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h76, &hh, sizeof(class hitter)); break;
					}
					break;

				case 3:
					switch (chg2) {
					case 1: memcpy(&h91, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h92, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h93, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h94, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h95, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h96, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h97, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h98, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h99, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h100, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h101, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h102, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h103, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h104, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h105, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h106, &hh, sizeof(class hitter)); break;
					}
					break;

				case 4:
					switch (chg2) {
					case 1: memcpy(&h131, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h132, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h133, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h134, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h135, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h136, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h137, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h138, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h139, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h140, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h141, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h142, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h143, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h144, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h145, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h146, &hh, sizeof(class hitter)); break;
					}
					break;

				case 5:
					switch (chg2) {
					case 1: memcpy(&h161, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h162, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h163, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h164, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h165, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h166, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h167, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h168, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h169, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h170, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h171, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h172, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h173, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h174, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h175, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h176, &hh, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) > hhh.stat(total_gam) + 1) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&h8001, &hh, sizeof(class hitter)); break;
				case 2: memcpy(&h8002, &hh, sizeof(class hitter)); break;
				case 3: memcpy(&h8003, &hh, sizeof(class hitter)); break;
				case 4: memcpy(&h8004, &hh, sizeof(class hitter)); break;
				case 5: memcpy(&h8005, &hh, sizeof(class hitter)); break;
				case 6: memcpy(&h8006, &hh, sizeof(class hitter)); break;
				case 7: memcpy(&h8007, &hh, sizeof(class hitter)); break;
				case 8: memcpy(&h8008, &hh, sizeof(class hitter)); break;
				case 9: memcpy(&h8009, &hh, sizeof(class hitter)); break;
				case 10: memcpy(&h8010, &hh, sizeof(class hitter)); break;
				case 11: memcpy(&h8011, &hh, sizeof(class hitter)); break;
				case 12: memcpy(&h8012, &hh, sizeof(class hitter)); break;
				case 13: memcpy(&h8013, &hh, sizeof(class hitter)); break;
				case 14: memcpy(&h8014, &hh, sizeof(class hitter)); break;
				case 15: memcpy(&h8015, &hh, sizeof(class hitter)); break;
				case 16: memcpy(&h8016, &hh, sizeof(class hitter)); break;
				}
			}
			break;



		}

		else if (my_team == 12) {  // �츮�� ����

			sel(&chg1, 15, 6, 2, 17); // �Ե��� chg3, chg4
			if (chg1 == 17) break;

			if (trade == false) {
				sel(&chg2, 15, 6, 2, 17);
				if (chg2 == 17) break;
			}

			//  ch_h()

			switch (chg1) {
			case 1: memcpy(&hh, &h9001, sizeof(class hitter)); break;
			case 2: memcpy(&hh, &h9002, sizeof(class hitter)); break;
			case 3: memcpy(&hh, &h9003, sizeof(class hitter)); break;
			case 4: memcpy(&hh, &h9004, sizeof(class hitter)); break;
			case 5: memcpy(&hh, &h9005, sizeof(class hitter)); break;
			case 6: memcpy(&hh, &h9006, sizeof(class hitter)); break;
			case 7: memcpy(&hh, &h9007, sizeof(class hitter)); break;
			case 8: memcpy(&hh, &h9008, sizeof(class hitter)); break;
			case 9: memcpy(&hh, &h9009, sizeof(class hitter)); break;
			case 10: memcpy(&hh, &h9010, sizeof(class hitter)); break;
			case 11: memcpy(&hh, &h9011, sizeof(class hitter)); break;
			case 12: memcpy(&hh, &h9012, sizeof(class hitter)); break;
			case 13: memcpy(&hh, &h9013, sizeof(class hitter)); break;
			case 14: memcpy(&hh, &h9014, sizeof(class hitter)); break;
			case 15: memcpy(&hh, &h9015, sizeof(class hitter)); break;
			case 16: memcpy(&hh, &h9016, sizeof(class hitter)); break;
			}



			if (trade == true) { // Ʈ���̵� ����

				cur(0, 38); cout << "    [  ���  ] " << '\n';

				system("cls");





				cout << "Ʈ���̵� �� ��븦 �������ֽʽÿ� : " << '\n'
					<< "[0] �Ｚ" << '\n' << "[1] �Ե�" << '\n' << "[2] NC" << '\n' << "[3] �λ�" << '\n' << "[4] LG" << '\n' << "[5] SSG" << '\n' << "[9] ���";

				cur(36, 0);
				cin >> tr;

				if (tr != 1 && tr != 2 && tr != 3 && tr != 4 && tr != 5) break;

				system("cls");

				cout << hh.stat(total_gam) << '\n';

				switch (tr) {
				case 0:
					print_hitter_record(total_gam, 0, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h1, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h2, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h3, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h4, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h5, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h6, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h7, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h8, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h9, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h10, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h11, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h12, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h13, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h14, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h15, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h16, sizeof(class hitter)); break;
					}
					break;

				case 1:
					print_hitter_record(total_gam, 1, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h31, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h32, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h33, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h34, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h35, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h36, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h37, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h38, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h39, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h40, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h41, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h42, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h43, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h44, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h45, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h46, sizeof(class hitter)); break;
					}
					break;

				case 3:
					print_hitter_record(total_gam, 3, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h91, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h92, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h93, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h94, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h95, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h96, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h97, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h98, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h99, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h100, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h101, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h102, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h103, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h104, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h105, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h106, sizeof(class hitter)); break;
					}
					break;

				case 4:
					print_hitter_record(total_gam, 4, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h131, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h132, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h133, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h134, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h135, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h136, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h137, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h138, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h139, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h140, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h141, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h142, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h143, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h144, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h145, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h146, sizeof(class hitter)); break;
					}
					break;

				case 5:
					print_hitter_record(total_gam, 5, true, false, 0);
					sel(&chg2, 15, 6, 2, 17);
					if (chg2 == 17) break;

					switch (chg2) {
					case 1: memcpy(&hhh, &h161, sizeof(class hitter)); break;
					case 2: memcpy(&hhh, &h162, sizeof(class hitter)); break;
					case 3: memcpy(&hhh, &h163, sizeof(class hitter)); break;
					case 4: memcpy(&hhh, &h164, sizeof(class hitter)); break;
					case 5: memcpy(&hhh, &h165, sizeof(class hitter)); break;
					case 6: memcpy(&hhh, &h166, sizeof(class hitter)); break;
					case 7: memcpy(&hhh, &h167, sizeof(class hitter)); break;
					case 8: memcpy(&hhh, &h168, sizeof(class hitter)); break;
					case 9: memcpy(&hhh, &h169, sizeof(class hitter)); break;
					case 10: memcpy(&hhh, &h170, sizeof(class hitter)); break;
					case 11: memcpy(&hhh, &h171, sizeof(class hitter)); break;
					case 12: memcpy(&hhh, &h172, sizeof(class hitter)); break;
					case 13: memcpy(&hhh, &h173, sizeof(class hitter)); break;
					case 14: memcpy(&hhh, &h174, sizeof(class hitter)); break;
					case 15: memcpy(&hhh, &h175, sizeof(class hitter)); break;
					case 16: memcpy(&hhh, &h176, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) - 1 <= hhh.stat(total_gam)) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&hhh, &h9001, sizeof(class hitter)); break;
				case 2: memcpy(&hhh, &h9002, sizeof(class hitter)); break;
				case 3: memcpy(&hhh, &h9003, sizeof(class hitter)); break;
				case 4: memcpy(&hhh, &h9004, sizeof(class hitter)); break;
				case 5: memcpy(&hhh, &h9005, sizeof(class hitter)); break;
				case 6: memcpy(&hhh, &h9006, sizeof(class hitter)); break;
				case 7: memcpy(&hhh, &h9007, sizeof(class hitter)); break;
				case 8: memcpy(&hhh, &h9008, sizeof(class hitter)); break;
				case 9: memcpy(&hhh, &h9009, sizeof(class hitter)); break;
				case 10: memcpy(&hhh, &h9010, sizeof(class hitter)); break;
				case 11: memcpy(&hhh, &h9011, sizeof(class hitter)); break;
				case 12: memcpy(&hhh, &h9012, sizeof(class hitter)); break;
				case 13: memcpy(&hhh, &h9013, sizeof(class hitter)); break;
				case 14: memcpy(&hhh, &h9014, sizeof(class hitter)); break;
				case 15: memcpy(&hhh, &h9015, sizeof(class hitter)); break;
				case 16: memcpy(&hhh, &h9016, sizeof(class hitter)); break;
				}



				if (print_check(hh.pos_(), hhh.pos_()) != 1 && hh.dom_() != 1 && hhh.dom_() != 1 && !(chg1 < 10 && chg2 < 10))
				{
					break;
				}

				if (total_gam == -5 && (chg1 < 10 && chg2 < 10) || (chg1 >= 10 && chg2 >= 10)) break;

				if (total_gam == -5) //��ü �ǿ���� (�ѹ� �ĺ��� ���� ������ �ٽ� �������� ���� �� ����.)
				{
					if ((chg1 == 10 || chg2 == 10) && change_10 == true) break;
					if ((chg1 == 11 || chg2 == 11) && change_11 == true) break;
					if ((chg1 == 12 || chg2 == 12) && change_12 == true) break;
					if ((chg1 == 13 || chg2 == 13) && change_13 == true) break;
					if ((chg1 == 14 || chg2 == 14) && change_14 == true) break;
					if ((chg1 == 15 || chg2 == 15) && change_15 == true) break;
					if ((chg1 == 16 || chg2 == 16) && change_16 == true) break;

					switch (chg1)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

					switch (chg2)
					{
					case 10:
						change_10 = true; break;
					case 11:
						change_11 = true; break;
					case 12:
						change_12 = true; break;
					case 13:
						change_13 = true; break;
					case 14:
						change_14 = true; break;
					case 15:
						change_15 = true; break;
					case 16:
						change_16 = true; break;
					}

				}

			}

			if (trade == true && (print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 || chg2 < 10) && hhh.dom_() != 1 && hh.dom_() != 1)) break;
			if (trade == true && print_check(hh.pos_(), hhh.pos_()) != 1 && (chg1 < 10 && chg2 < 10) && (hhh.dom_() != 1 || hh.dom_() != 1)) break;
			if (trade == true && (double)(hh.stat(total_gam) * tra) < hhh.stat(total_gam)) break;


			if (chg2 == 17) break;



			if (hh.pos_() != hhh.pos_() && (print_check(hh.pos_(), hhh.pos_()) == 1) && !(chg1 < 10 && chg2 < 10))
			{
				save = hh.pos_();

				hh.change_pos_(change_pos(hhh.pos_()));

				hhh.change_pos_(save);


			}

			if (trade == true) {

				if (hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			else {

				if (!(chg1 < 10 && chg2 < 10) && hh.dom_() == 1)
				{
					hh.change_dom(0);
					hhh.change_dom(1);
				}

				else if (!(chg1 < 10 && chg2 < 10) && hhh.dom_() == 1)
				{
					hhh.change_dom(0);
					hh.change_dom(1);
				}
			}

			hhhh.cn_(hh.num_()); //X��Ÿ�� ����
			hh.cn_(hhh.num_());
			hhh.cn_(hhhh.num_());



			switch (chg1) {
			case 1: memcpy(&h9001, &hhh, sizeof(class hitter)); break;
			case 2: memcpy(&h9002, &hhh, sizeof(class hitter)); break;
			case 3: memcpy(&h9003, &hhh, sizeof(class hitter)); break;
			case 4: memcpy(&h9004, &hhh, sizeof(class hitter)); break;
			case 5: memcpy(&h9005, &hhh, sizeof(class hitter)); break;
			case 6: memcpy(&h9006, &hhh, sizeof(class hitter)); break;
			case 7: memcpy(&h9007, &hhh, sizeof(class hitter)); break;
			case 8: memcpy(&h9008, &hhh, sizeof(class hitter)); break;
			case 9: memcpy(&h9009, &hhh, sizeof(class hitter)); break;
			case 10: memcpy(&h9010, &hhh, sizeof(class hitter)); break;
			case 11: memcpy(&h9011, &hhh, sizeof(class hitter)); break;
			case 12: memcpy(&h9012, &hhh, sizeof(class hitter)); break;
			case 13: memcpy(&h9013, &hhh, sizeof(class hitter)); break;
			case 14: memcpy(&h9014, &hhh, sizeof(class hitter)); break;
			case 15: memcpy(&h9015, &hhh, sizeof(class hitter)); break;
			case 16: memcpy(&h9016, &hhh, sizeof(class hitter)); break;
			}



			if (trade == true) {

				switch (tr) {

				case 0:
					switch (chg2) {
					case 1: memcpy(&h1, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h2, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h3, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h4, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h5, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h6, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h7, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h8, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h9, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h10, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h11, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h12, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h13, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h14, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h15, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h16, &hh, sizeof(class hitter)); break;
					}
					break;

				case 1:
					switch (chg2) {
					case 1: memcpy(&h31, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h32, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h33, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h34, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h35, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h36, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h37, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h38, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h39, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h40, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h41, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h42, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h43, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h44, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h45, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h46, &hh, sizeof(class hitter)); break;
					}
					break;



				case 3:
					switch (chg2) {
					case 1: memcpy(&h91, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h92, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h93, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h94, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h95, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h96, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h97, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h98, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h99, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h100, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h101, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h102, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h103, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h104, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h105, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h106, &hh, sizeof(class hitter)); break;
					}
					break;

				case 4:
					switch (chg2) {
					case 1: memcpy(&h131, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h132, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h133, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h134, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h135, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h136, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h137, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h138, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h139, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h140, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h141, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h142, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h143, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h144, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h145, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h146, &hh, sizeof(class hitter)); break;
					}
					break;

				case 5:
					switch (chg2) {
					case 1: memcpy(&h161, &hh, sizeof(class hitter)); break;
					case 2: memcpy(&h162, &hh, sizeof(class hitter)); break;
					case 3: memcpy(&h163, &hh, sizeof(class hitter)); break;
					case 4: memcpy(&h164, &hh, sizeof(class hitter)); break;
					case 5: memcpy(&h165, &hh, sizeof(class hitter)); break;
					case 6: memcpy(&h166, &hh, sizeof(class hitter)); break;
					case 7: memcpy(&h167, &hh, sizeof(class hitter)); break;
					case 8: memcpy(&h168, &hh, sizeof(class hitter)); break;
					case 9: memcpy(&h169, &hh, sizeof(class hitter)); break;
					case 10: memcpy(&h170, &hh, sizeof(class hitter)); break;
					case 11: memcpy(&h171, &hh, sizeof(class hitter)); break;
					case 12: memcpy(&h172, &hh, sizeof(class hitter)); break;
					case 13: memcpy(&h173, &hh, sizeof(class hitter)); break;
					case 14: memcpy(&h174, &hh, sizeof(class hitter)); break;
					case 15: memcpy(&h175, &hh, sizeof(class hitter)); break;
					case 16: memcpy(&h176, &hh, sizeof(class hitter)); break;
					}
					break;

				case 9:
					break;
				}

				//if ((hh.pos_() != hhh.pos_() && chg1 < 10) || (hh.pos_() != hhh.pos_() && chg2 < 10 || tr == 9)) break;
				//if (hh.stat(total_gam) > hhh.stat(total_gam) + 1) break;

			}

			else {

				switch (chg2) {
				case 1: memcpy(&h9001, &hh, sizeof(class hitter)); break;
				case 2: memcpy(&h9002, &hh, sizeof(class hitter)); break;
				case 3: memcpy(&h9003, &hh, sizeof(class hitter)); break;
				case 4: memcpy(&h9004, &hh, sizeof(class hitter)); break;
				case 5: memcpy(&h9005, &hh, sizeof(class hitter)); break;
				case 6: memcpy(&h9006, &hh, sizeof(class hitter)); break;
				case 7: memcpy(&h9007, &hh, sizeof(class hitter)); break;
				case 8: memcpy(&h9008, &hh, sizeof(class hitter)); break;
				case 9: memcpy(&h9009, &hh, sizeof(class hitter)); break;
				case 10: memcpy(&h9010, &hh, sizeof(class hitter)); break;
				case 11: memcpy(&h9011, &hh, sizeof(class hitter)); break;
				case 12: memcpy(&h9012, &hh, sizeof(class hitter)); break;
				case 13: memcpy(&h9013, &hh, sizeof(class hitter)); break;
				case 14: memcpy(&h9014, &hh, sizeof(class hitter)); break;
				case 15: memcpy(&h9015, &hh, sizeof(class hitter)); break;
				case 16: memcpy(&h9016, &hh, sizeof(class hitter)); break;
				}
			}
			break;



		}
	}
}

void changepitcher(int my_team)
{
	int chg1 = 0, chg2 = 0;

	system("cls");
	cur(3, 2);
	cout << " [ �������� : 7�� ]   [ �� �� ]  [ �����å�� ]  [ ���� ]  [ ���� ]   [ ü�� ]   [ ���� ]   [ ���� ]   [ ���� ]   [ �� ]   [ �� ]  [ ��Ȩ�� ]  [ K/9 ]   [ BB/9 ]  [ WHIP ]  [ ���� ]" << '\n' << '\n';


	switch (my_team)
	{
	case 0:
		cout << " [ �Ｚ ]" << '\n' << '\n';
		p1.printp(1); p2.printp(2); p3.printp(3); p4.printp(4); p5.printp(5);
		p6.printp(6); p7.printp(7); p8.printp(8); p9.printp(9); p10.printp(10); p11.printp(10);
		break;
	case 1:
		cout << " [ �Ե� ]" << '\n' << '\n';
		p31.printp(1); p32.printp(2); p33.printp(3); p34.printp(4); p35.printp(5);
		p36.printp(6); p37.printp(7); p38.printp(8); p39.printp(9); p40.printp(10); p41.printp(10);
		break;

	case 2:
		cout << " [  NC  ]" << '\n' << '\n';
		p61.printp(1); p62.printp(2); p63.printp(3); p64.printp(4); p65.printp(5);
		p66.printp(6); p67.printp(7); p68.printp(8); p69.printp(9); p70.printp(10); p71.printp(10);
		break;

	case 3:
		cout << " [ �λ� ]" << '\n' << '\n';
		p91.printp(1); p92.printp(2); p93.printp(3); p94.printp(4); p95.printp(5);
		p96.printp(6); p97.printp(7); p98.printp(8); p99.printp(9); p100.printp(10); p101.printp(10);
		break;

	case 4:
		cout << " [  LG  ]" << '\n' << '\n';
		p131.printp(1); p132.printp(2); p133.printp(3); p134.printp(4); p135.printp(5);
		p136.printp(6); p137.printp(7); p138.printp(8); p139.printp(9); p140.printp(10); p141.printp(10);
		break;

	case 5:
		cout << " [ SSG  ]" << '\n' << '\n';
		p161.printp(1); p162.printp(2); p163.printp(3); p164.printp(4); p165.printp(5);
		p166.printp(6); p167.printp(7); p168.printp(8); p169.printp(9); p170.printp(10); p171.printp(10);
		break;

	case 11:
		cout << " [ ���� ]" << '\n' << '\n';
		p8001.printp(1); p8002.printp(2); p8003.printp(3); p8004.printp(4); p8005.printp(5);
		p8006.printp(6); p8007.printp(7); p8008.printp(8); p8009.printp(9); p8010.printp(10); p8011.printp(10);
		break;

	case 12:
		cout << " [ ���� ]" << '\n' << '\n';
		p9001.printp(1); p9002.printp(2); p9003.printp(3); p9004.printp(4); p9005.printp(5);
		p9006.printp(6); p9007.printp(7); p9008.printp(8); p9009.printp(9); p9010.printp(10); p9011.printp(10);
		break;

	}


	cur(0, 28);
	cout << "  [ ��� ]";

	sel(&chg1, 12, 6, 2, 12);
	if (chg1 == 12)
	{
		cur(0, 28);
		cout << "           ";
		return;
	}




	sel(&chg2, 12, 6, 2, 12);
	if (chg2 == 12)
	{
		cur(0, 28);
		cout << "           ";
		return;
	}

	switch (my_team)
	{
	case 0:
		switch (chg1) {
		case 1: memcpy(&pp, &p1, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p2, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p3, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p4, sizeof(class pitcher)); break;
		case 5: memcpy(&pp, &p5, sizeof(class pitcher)); break;
		case 6: memcpy(&pp, &p6, sizeof(class pitcher)); break;
		case 7: memcpy(&pp, &p7, sizeof(class pitcher)); break;
		case 8: memcpy(&pp, &p8, sizeof(class pitcher)); break;
		case 9: memcpy(&pp, &p9, sizeof(class pitcher)); break;
		case 10: memcpy(&pp, &p10, sizeof(class pitcher)); break;
		case 11: memcpy(&pp, &p11, sizeof(class pitcher)); break;
		}
		break;
	case 1:
		switch (chg1) {
		case 1: memcpy(&pp, &p31, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p32, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p33, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p34, sizeof(class pitcher)); break;
		case 5: memcpy(&pp, &p35, sizeof(class pitcher)); break;
		case 6: memcpy(&pp, &p36, sizeof(class pitcher)); break;
		case 7: memcpy(&pp, &p37, sizeof(class pitcher)); break;
		case 8: memcpy(&pp, &p38, sizeof(class pitcher)); break;
		case 9: memcpy(&pp, &p39, sizeof(class pitcher)); break;
		case 10: memcpy(&pp, &p40, sizeof(class pitcher)); break;
		case 11: memcpy(&pp, &p41, sizeof(class pitcher)); break;
		}
		break;
	case 2:
		switch (chg1) {
		case 1: memcpy(&pp, &p61, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p62, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p63, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p64, sizeof(class pitcher)); break;
		case 5: memcpy(&pp, &p65, sizeof(class pitcher)); break;
		case 6: memcpy(&pp, &p66, sizeof(class pitcher)); break;
		case 7: memcpy(&pp, &p67, sizeof(class pitcher)); break;
		case 8: memcpy(&pp, &p68, sizeof(class pitcher)); break;
		case 9: memcpy(&pp, &p69, sizeof(class pitcher)); break;
		case 10: memcpy(&pp, &p70, sizeof(class pitcher)); break;
		case 11: memcpy(&pp, &p71, sizeof(class pitcher)); break;
		}
		break;
	case 3:
		switch (chg1) {
		case 1: memcpy(&pp, &p91, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p92, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p93, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p94, sizeof(class pitcher)); break;
		case 5: memcpy(&pp, &p95, sizeof(class pitcher)); break;
		case 6: memcpy(&pp, &p96, sizeof(class pitcher)); break;
		case 7: memcpy(&pp, &p97, sizeof(class pitcher)); break;
		case 8: memcpy(&pp, &p98, sizeof(class pitcher)); break;
		case 9: memcpy(&pp, &p99, sizeof(class pitcher)); break;
		case 10: memcpy(&pp, &p100, sizeof(class pitcher)); break;
		case 11: memcpy(&pp, &p101, sizeof(class pitcher)); break;
		}
		break;
	case 4:
		switch (chg1) {
		case 1: memcpy(&pp, &p131, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p132, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p133, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p134, sizeof(class pitcher)); break;
		case 5: memcpy(&pp, &p135, sizeof(class pitcher)); break;
		case 6: memcpy(&pp, &p136, sizeof(class pitcher)); break;
		case 7: memcpy(&pp, &p137, sizeof(class pitcher)); break;
		case 8: memcpy(&pp, &p138, sizeof(class pitcher)); break;
		case 9: memcpy(&pp, &p139, sizeof(class pitcher)); break;
		case 10: memcpy(&pp, &p140, sizeof(class pitcher)); break;
		case 11: memcpy(&pp, &p141, sizeof(class pitcher)); break;
		}
		break;
	case 5:
		switch (chg1) {
		case 1: memcpy(&pp, &p161, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p162, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p163, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p164, sizeof(class pitcher)); break;
		case 5: memcpy(&pp, &p165, sizeof(class pitcher)); break;
		case 6: memcpy(&pp, &p166, sizeof(class pitcher)); break;
		case 7: memcpy(&pp, &p167, sizeof(class pitcher)); break;
		case 8: memcpy(&pp, &p168, sizeof(class pitcher)); break;
		case 9: memcpy(&pp, &p169, sizeof(class pitcher)); break;
		case 10: memcpy(&pp, &p170, sizeof(class pitcher)); break;
		case 11: memcpy(&pp, &p171, sizeof(class pitcher)); break;
		}
		break;
	case 11:
		switch (chg1) {
		case 1: memcpy(&pp, &p8001, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p8002, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p8003, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p8004, sizeof(class pitcher)); break;
		case 5: memcpy(&pp, &p8005, sizeof(class pitcher)); break;
		case 6: memcpy(&pp, &p8006, sizeof(class pitcher)); break;
		case 7: memcpy(&pp, &p8007, sizeof(class pitcher)); break;
		case 8: memcpy(&pp, &p8008, sizeof(class pitcher)); break;
		case 9: memcpy(&pp, &p8009, sizeof(class pitcher)); break;
		case 10: memcpy(&pp, &p8010, sizeof(class pitcher)); break;
		case 11: memcpy(&pp, &p8011, sizeof(class pitcher)); break;
		}
		break;
	case 12:
		switch (chg1) {
		case 1: memcpy(&pp, &p9001, sizeof(class pitcher)); break;
		case 2: memcpy(&pp, &p9002, sizeof(class pitcher)); break;
		case 3: memcpy(&pp, &p9003, sizeof(class pitcher)); break;
		case 4: memcpy(&pp, &p9004, sizeof(class pitcher)); break;
		case 5: memcpy(&pp, &p9005, sizeof(class pitcher)); break;
		case 6: memcpy(&pp, &p9006, sizeof(class pitcher)); break;
		case 7: memcpy(&pp, &p9007, sizeof(class pitcher)); break;
		case 8: memcpy(&pp, &p9008, sizeof(class pitcher)); break;
		case 9: memcpy(&pp, &p9009, sizeof(class pitcher)); break;
		case 10: memcpy(&pp, &p9010, sizeof(class pitcher)); break;
		case 11: memcpy(&pp, &p9011, sizeof(class pitcher)); break;
		}
		break;
	}



	system("cls");
	cur(3, 2);
	cout << " [ �������� : 7�� ]   [ �� �� ]  [ �����å�� ]  [ ���� ]  [ ���� ]   [ ü�� ]   [ ���� ]   [ ���� ]   [ ���� ]   [ �� ]   [ �� ]  [ ��Ȩ�� ]  [ K/9 ]   [ BB/9 ]  [ WHIP ]  [ ���� ]" << '\n' << '\n';

	cout << " [ �Ｚ ]" << '\n' << '\n';
	p1.printp(1); p2.printp(2); p3.printp(3); p4.printp(4); p5.printp(5);
	p6.printp(6); p7.printp(7); p8.printp(8); p9.printp(9); p10.printp(10); p11.printp(11);

	if (chg1 == chg2) return;

	switch (my_team)
	{
	case 0:
		switch (chg2) {
		case 1: memcpy(&ppp, &p1, sizeof(class pitcher)); memcpy(&p1, &pp, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p2, sizeof(class pitcher)); memcpy(&p2, &pp, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p3, sizeof(class pitcher)); memcpy(&p3, &pp, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p4, sizeof(class pitcher)); memcpy(&p4, &pp, sizeof(class pitcher)); break;
		case 5: memcpy(&ppp, &p5, sizeof(class pitcher)); memcpy(&p5, &pp, sizeof(class pitcher)); break;
		case 6: memcpy(&ppp, &p6, sizeof(class pitcher)); memcpy(&p6, &pp, sizeof(class pitcher)); break;
		case 7: memcpy(&ppp, &p7, sizeof(class pitcher)); memcpy(&p7, &pp, sizeof(class pitcher)); break;
		case 8: memcpy(&ppp, &p8, sizeof(class pitcher)); memcpy(&p8, &pp, sizeof(class pitcher)); break;
		case 9: memcpy(&ppp, &p9, sizeof(class pitcher)); memcpy(&p9, &pp, sizeof(class pitcher)); break;
		case 10: memcpy(&ppp, &p10, sizeof(class pitcher)); memcpy(&p10, &pp, sizeof(class pitcher)); break;
		case 11: memcpy(&ppp, &p11, sizeof(class pitcher)); memcpy(&p11, &pp, sizeof(class pitcher)); break;
		}
		break;
	case 1:
		switch (chg2) {
		case 1: memcpy(&ppp, &p31, sizeof(class pitcher)); memcpy(&p31, &pp, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p32, sizeof(class pitcher)); memcpy(&p32, &pp, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p33, sizeof(class pitcher)); memcpy(&p33, &pp, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p34, sizeof(class pitcher)); memcpy(&p34, &pp, sizeof(class pitcher)); break;
		case 5: memcpy(&ppp, &p35, sizeof(class pitcher)); memcpy(&p35, &pp, sizeof(class pitcher)); break;
		case 6: memcpy(&ppp, &p36, sizeof(class pitcher)); memcpy(&p36, &pp, sizeof(class pitcher)); break;
		case 7: memcpy(&ppp, &p37, sizeof(class pitcher)); memcpy(&p37, &pp, sizeof(class pitcher)); break;
		case 8: memcpy(&ppp, &p38, sizeof(class pitcher)); memcpy(&p38, &pp, sizeof(class pitcher)); break;
		case 9: memcpy(&ppp, &p39, sizeof(class pitcher)); memcpy(&p39, &pp, sizeof(class pitcher)); break;
		case 10: memcpy(&ppp, &p40, sizeof(class pitcher)); memcpy(&p40, &pp, sizeof(class pitcher)); break;
		case 11: memcpy(&ppp, &p41, sizeof(class pitcher)); memcpy(&p41, &pp, sizeof(class pitcher)); break;
		}
		break;
	case 2:
		switch (chg2) {
		case 1: memcpy(&ppp, &p61, sizeof(class pitcher)); memcpy(&p61, &pp, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p62, sizeof(class pitcher)); memcpy(&p62, &pp, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p63, sizeof(class pitcher)); memcpy(&p63, &pp, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p64, sizeof(class pitcher)); memcpy(&p64, &pp, sizeof(class pitcher)); break;
		case 5: memcpy(&ppp, &p65, sizeof(class pitcher)); memcpy(&p65, &pp, sizeof(class pitcher)); break;
		case 6: memcpy(&ppp, &p66, sizeof(class pitcher)); memcpy(&p66, &pp, sizeof(class pitcher)); break;
		case 7: memcpy(&ppp, &p67, sizeof(class pitcher)); memcpy(&p67, &pp, sizeof(class pitcher)); break;
		case 8: memcpy(&ppp, &p68, sizeof(class pitcher)); memcpy(&p68, &pp, sizeof(class pitcher)); break;
		case 9: memcpy(&ppp, &p69, sizeof(class pitcher)); memcpy(&p69, &pp, sizeof(class pitcher)); break;
		case 10: memcpy(&ppp, &p70, sizeof(class pitcher)); memcpy(&p70, &pp, sizeof(class pitcher)); break;
		case 11: memcpy(&ppp, &p71, sizeof(class pitcher)); memcpy(&p71, &pp, sizeof(class pitcher)); break;
		}
		break;
	case 3:
		switch (chg2) {
		case 1: memcpy(&ppp, &p91, sizeof(class pitcher)); memcpy(&p91, &pp, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p92, sizeof(class pitcher)); memcpy(&p92, &pp, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p93, sizeof(class pitcher)); memcpy(&p93, &pp, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p94, sizeof(class pitcher)); memcpy(&p94, &pp, sizeof(class pitcher)); break;
		case 5: memcpy(&ppp, &p95, sizeof(class pitcher)); memcpy(&p95, &pp, sizeof(class pitcher)); break;
		case 6: memcpy(&ppp, &p96, sizeof(class pitcher)); memcpy(&p96, &pp, sizeof(class pitcher)); break;
		case 7: memcpy(&ppp, &p97, sizeof(class pitcher)); memcpy(&p97, &pp, sizeof(class pitcher)); break;
		case 8: memcpy(&ppp, &p98, sizeof(class pitcher)); memcpy(&p98, &pp, sizeof(class pitcher)); break;
		case 9: memcpy(&ppp, &p99, sizeof(class pitcher)); memcpy(&p99, &pp, sizeof(class pitcher)); break;
		case 10: memcpy(&ppp, &p100, sizeof(class pitcher)); memcpy(&p100, &pp, sizeof(class pitcher)); break;
		case 11: memcpy(&ppp, &p101, sizeof(class pitcher)); memcpy(&p101, &pp, sizeof(class pitcher)); break;
		}
		break;
	case 4:
		switch (chg2) {
		case 1: memcpy(&ppp, &p131, sizeof(class pitcher)); memcpy(&p131, &pp, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p132, sizeof(class pitcher)); memcpy(&p132, &pp, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p133, sizeof(class pitcher)); memcpy(&p133, &pp, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p134, sizeof(class pitcher)); memcpy(&p134, &pp, sizeof(class pitcher)); break;
		case 5: memcpy(&ppp, &p135, sizeof(class pitcher)); memcpy(&p135, &pp, sizeof(class pitcher)); break;
		case 6: memcpy(&ppp, &p136, sizeof(class pitcher)); memcpy(&p136, &pp, sizeof(class pitcher)); break;
		case 7: memcpy(&ppp, &p137, sizeof(class pitcher)); memcpy(&p137, &pp, sizeof(class pitcher)); break;
		case 8: memcpy(&ppp, &p138, sizeof(class pitcher)); memcpy(&p138, &pp, sizeof(class pitcher)); break;
		case 9: memcpy(&ppp, &p139, sizeof(class pitcher)); memcpy(&p139, &pp, sizeof(class pitcher)); break;
		case 10: memcpy(&ppp, &p140, sizeof(class pitcher)); memcpy(&p140, &pp, sizeof(class pitcher)); break;
		case 11: memcpy(&ppp, &p141, sizeof(class pitcher)); memcpy(&p141, &pp, sizeof(class pitcher)); break;
		}
		break;
	case 5:
		switch (chg2) {
		case 1: memcpy(&ppp, &p161, sizeof(class pitcher)); memcpy(&p161, &pp, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p162, sizeof(class pitcher)); memcpy(&p162, &pp, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p163, sizeof(class pitcher)); memcpy(&p163, &pp, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p164, sizeof(class pitcher)); memcpy(&p164, &pp, sizeof(class pitcher)); break;
		case 5: memcpy(&ppp, &p165, sizeof(class pitcher)); memcpy(&p165, &pp, sizeof(class pitcher)); break;
		case 6: memcpy(&ppp, &p166, sizeof(class pitcher)); memcpy(&p166, &pp, sizeof(class pitcher)); break;
		case 7: memcpy(&ppp, &p167, sizeof(class pitcher)); memcpy(&p167, &pp, sizeof(class pitcher)); break;
		case 8: memcpy(&ppp, &p168, sizeof(class pitcher)); memcpy(&p168, &pp, sizeof(class pitcher)); break;
		case 9: memcpy(&ppp, &p169, sizeof(class pitcher)); memcpy(&p169, &pp, sizeof(class pitcher)); break;
		case 10: memcpy(&ppp, &p170, sizeof(class pitcher)); memcpy(&p170, &pp, sizeof(class pitcher)); break;
		case 11: memcpy(&ppp, &p171, sizeof(class pitcher)); memcpy(&p171, &pp, sizeof(class pitcher)); break;
		}
		break;
	case 11:
		switch (chg2) {
		case 1: memcpy(&ppp, &p8001, sizeof(class pitcher)); memcpy(&p8001, &pp, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p8002, sizeof(class pitcher)); memcpy(&p8002, &pp, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p8003, sizeof(class pitcher)); memcpy(&p8003, &pp, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p8004, sizeof(class pitcher)); memcpy(&p8004, &pp, sizeof(class pitcher)); break;
		case 5: memcpy(&ppp, &p8005, sizeof(class pitcher)); memcpy(&p8005, &pp, sizeof(class pitcher)); break;
		case 6: memcpy(&ppp, &p8006, sizeof(class pitcher)); memcpy(&p8006, &pp, sizeof(class pitcher)); break;
		case 7: memcpy(&ppp, &p8007, sizeof(class pitcher)); memcpy(&p8007, &pp, sizeof(class pitcher)); break;
		case 8: memcpy(&ppp, &p8008, sizeof(class pitcher)); memcpy(&p8008, &pp, sizeof(class pitcher)); break;
		case 9: memcpy(&ppp, &p8009, sizeof(class pitcher)); memcpy(&p8009, &pp, sizeof(class pitcher)); break;
		case 10: memcpy(&ppp, &p8010, sizeof(class pitcher)); memcpy(&p8010, &pp, sizeof(class pitcher)); break;
		case 11: memcpy(&ppp, &p8011, sizeof(class pitcher)); memcpy(&p8011, &pp, sizeof(class pitcher)); break;
		}
		break;
	case 12:
		switch (chg2) {
		case 1: memcpy(&ppp, &p9001, sizeof(class pitcher)); memcpy(&p9001, &pp, sizeof(class pitcher)); break;
		case 2: memcpy(&ppp, &p9002, sizeof(class pitcher)); memcpy(&p9002, &pp, sizeof(class pitcher)); break;
		case 3: memcpy(&ppp, &p9003, sizeof(class pitcher)); memcpy(&p9003, &pp, sizeof(class pitcher)); break;
		case 4: memcpy(&ppp, &p9004, sizeof(class pitcher)); memcpy(&p9004, &pp, sizeof(class pitcher)); break;
		case 5: memcpy(&ppp, &p9005, sizeof(class pitcher)); memcpy(&p9005, &pp, sizeof(class pitcher)); break;
		case 6: memcpy(&ppp, &p9006, sizeof(class pitcher)); memcpy(&p9006, &pp, sizeof(class pitcher)); break;
		case 7: memcpy(&ppp, &p9007, sizeof(class pitcher)); memcpy(&p9007, &pp, sizeof(class pitcher)); break;
		case 8: memcpy(&ppp, &p9008, sizeof(class pitcher)); memcpy(&p9008, &pp, sizeof(class pitcher)); break;
		case 9: memcpy(&ppp, &p9009, sizeof(class pitcher)); memcpy(&p9009, &pp, sizeof(class pitcher)); break;
		case 10: memcpy(&ppp, &p9010, sizeof(class pitcher)); memcpy(&p9010, &pp, sizeof(class pitcher)); break;
		case 11: memcpy(&ppp, &p9011, sizeof(class pitcher)); memcpy(&p9011, &pp, sizeof(class pitcher)); break;
		}
		break;
	}

	switch (my_team)
	{
	case 0:
		switch (chg1) {
		case 1: memcpy(&p1, &ppp, sizeof(class pitcher)); break;
		case 2: memcpy(&p2, &ppp, sizeof(class pitcher)); break;
		case 3: memcpy(&p3, &ppp, sizeof(class pitcher)); break;
		case 4: memcpy(&p4, &ppp, sizeof(class pitcher)); break;
		case 5: memcpy(&p5, &ppp, sizeof(class pitcher)); break;
		case 6: memcpy(&p6, &ppp, sizeof(class pitcher)); break;
		case 7: memcpy(&p7, &ppp, sizeof(class pitcher)); break;
		case 8: memcpy(&p8, &ppp, sizeof(class pitcher)); break;
		case 9: memcpy(&p9, &ppp, sizeof(class pitcher)); break;
		case 10: memcpy(&p10, &ppp, sizeof(class pitcher)); break;
		case 11: memcpy(&p11, &ppp, sizeof(class pitcher)); break;
		}
		break;
	case 1:
		switch (chg1) {
		case 1: memcpy(&p31, &ppp, sizeof(class pitcher)); break;
		case 2: memcpy(&p32, &ppp, sizeof(class pitcher)); break;
		case 3: memcpy(&p33, &ppp, sizeof(class pitcher)); break;
		case 4: memcpy(&p34, &ppp, sizeof(class pitcher)); break;
		case 5: memcpy(&p35, &ppp, sizeof(class pitcher)); break;
		case 6: memcpy(&p36, &ppp, sizeof(class pitcher)); break;
		case 7: memcpy(&p37, &ppp, sizeof(class pitcher)); break;
		case 8: memcpy(&p38, &ppp, sizeof(class pitcher)); break;
		case 9: memcpy(&p39, &ppp, sizeof(class pitcher)); break;
		case 10: memcpy(&p40, &ppp, sizeof(class pitcher)); break;
		case 11: memcpy(&p41, &ppp, sizeof(class pitcher)); break;
		}
		break;
	case 2:
		switch (chg1) {
		case 1: memcpy(&p61, &ppp, sizeof(class pitcher)); break;
		case 2: memcpy(&p62, &ppp, sizeof(class pitcher)); break;
		case 3: memcpy(&p63, &ppp, sizeof(class pitcher)); break;
		case 4: memcpy(&p64, &ppp, sizeof(class pitcher)); break;
		case 5: memcpy(&p65, &ppp, sizeof(class pitcher)); break;
		case 6: memcpy(&p66, &ppp, sizeof(class pitcher)); break;
		case 7: memcpy(&p67, &ppp, sizeof(class pitcher)); break;
		case 8: memcpy(&p68, &ppp, sizeof(class pitcher)); break;
		case 9: memcpy(&p69, &ppp, sizeof(class pitcher)); break;
		case 10: memcpy(&p70, &ppp, sizeof(class pitcher)); break;
		case 11: memcpy(&p71, &ppp, sizeof(class pitcher)); break;
		}
		break;
	case 3:
		switch (chg1) {
		case 1: memcpy(&p91, &ppp, sizeof(class pitcher)); break;
		case 2: memcpy(&p92, &ppp, sizeof(class pitcher)); break;
		case 3: memcpy(&p93, &ppp, sizeof(class pitcher)); break;
		case 4: memcpy(&p94, &ppp, sizeof(class pitcher)); break;
		case 5: memcpy(&p95, &ppp, sizeof(class pitcher)); break;
		case 6: memcpy(&p96, &ppp, sizeof(class pitcher)); break;
		case 7: memcpy(&p97, &ppp, sizeof(class pitcher)); break;
		case 8: memcpy(&p98, &ppp, sizeof(class pitcher)); break;
		case 9: memcpy(&p99, &ppp, sizeof(class pitcher)); break;
		case 10: memcpy(&p100, &ppp, sizeof(class pitcher)); break;
		case 11: memcpy(&p101, &ppp, sizeof(class pitcher)); break;
		}
		break;
	case 4:
		switch (chg1) {
		case 1: memcpy(&p131, &ppp, sizeof(class pitcher)); break;
		case 2: memcpy(&p132, &ppp, sizeof(class pitcher)); break;
		case 3: memcpy(&p133, &ppp, sizeof(class pitcher)); break;
		case 4: memcpy(&p134, &ppp, sizeof(class pitcher)); break;
		case 5: memcpy(&p135, &ppp, sizeof(class pitcher)); break;
		case 6: memcpy(&p136, &ppp, sizeof(class pitcher)); break;
		case 7: memcpy(&p137, &ppp, sizeof(class pitcher)); break;
		case 8: memcpy(&p138, &ppp, sizeof(class pitcher)); break;
		case 9: memcpy(&p139, &ppp, sizeof(class pitcher)); break;
		case 10: memcpy(&p140, &ppp, sizeof(class pitcher)); break;
		case 11: memcpy(&p141, &ppp, sizeof(class pitcher)); break;
		}
		break;
	case 5:
		switch (chg1) {
		case 1: memcpy(&p161, &ppp, sizeof(class pitcher)); break;
		case 2: memcpy(&p162, &ppp, sizeof(class pitcher)); break;
		case 3: memcpy(&p163, &ppp, sizeof(class pitcher)); break;
		case 4: memcpy(&p164, &ppp, sizeof(class pitcher)); break;
		case 5: memcpy(&p165, &ppp, sizeof(class pitcher)); break;
		case 6: memcpy(&p166, &ppp, sizeof(class pitcher)); break;
		case 7: memcpy(&p167, &ppp, sizeof(class pitcher)); break;
		case 8: memcpy(&p168, &ppp, sizeof(class pitcher)); break;
		case 9: memcpy(&p169, &ppp, sizeof(class pitcher)); break;
		case 10: memcpy(&p170, &ppp, sizeof(class pitcher)); break;
		case 11: memcpy(&p171, &ppp, sizeof(class pitcher)); break;
		}
		break;
	case 11:
		switch (chg1) {
		case 1: memcpy(&p8001, &ppp, sizeof(class pitcher)); break;
		case 2: memcpy(&p8002, &ppp, sizeof(class pitcher)); break;
		case 3: memcpy(&p8003, &ppp, sizeof(class pitcher)); break;
		case 4: memcpy(&p8004, &ppp, sizeof(class pitcher)); break;
		case 5: memcpy(&p8005, &ppp, sizeof(class pitcher)); break;
		case 6: memcpy(&p8006, &ppp, sizeof(class pitcher)); break;
		case 7: memcpy(&p8007, &ppp, sizeof(class pitcher)); break;
		case 8: memcpy(&p8008, &ppp, sizeof(class pitcher)); break;
		case 9: memcpy(&p8009, &ppp, sizeof(class pitcher)); break;
		case 10: memcpy(&p8010, &ppp, sizeof(class pitcher)); break;
		case 11: memcpy(&p8011, &ppp, sizeof(class pitcher)); break;
		}
		break;
	case 12:
		switch (chg1) {
		case 1: memcpy(&p9001, &ppp, sizeof(class pitcher)); break;
		case 2: memcpy(&p9002, &ppp, sizeof(class pitcher)); break;
		case 3: memcpy(&p9003, &ppp, sizeof(class pitcher)); break;
		case 4: memcpy(&p9004, &ppp, sizeof(class pitcher)); break;
		case 5: memcpy(&p9005, &ppp, sizeof(class pitcher)); break;
		case 6: memcpy(&p9006, &ppp, sizeof(class pitcher)); break;
		case 7: memcpy(&p9007, &ppp, sizeof(class pitcher)); break;
		case 8: memcpy(&p9008, &ppp, sizeof(class pitcher)); break;
		case 9: memcpy(&p9009, &ppp, sizeof(class pitcher)); break;
		case 10: memcpy(&p9010, &ppp, sizeof(class pitcher)); break;
		case 11: memcpy(&p9011, &ppp, sizeof(class pitcher)); break;
		}
		break;
	}

	system("cls");
	cur(3, 2);
	cout << " [ �������� : 7�� ]   [ �� �� ]  [ �����å�� ]  [ ���� ]  [ ���� ]   [ ü�� ]   [ ���� ]   [ ���� ]   [ ���� ]   [ �� ]   [ �� ]  [ ��Ȩ�� ]  [ K/9 ]   [ BB/9 ]  [ WHIP ]  [ ���� ]" << '\n' << '\n';


	switch (my_team)
	{
	case 0:
		cout << " [ �Ｚ ]" << '\n' << '\n';
		p1.printp(1); p2.printp(2); p3.printp(3); p4.printp(4); p5.printp(5);
		p6.printp(6); p7.printp(7); p8.printp(8); p9.printp(9); p10.printp(10); p11.printp(10);
		break;
	case 1:
		cout << " [ �Ե� ]" << '\n' << '\n';
		p31.printp(1); p32.printp(2); p33.printp(3); p34.printp(4); p35.printp(5);
		p36.printp(6); p37.printp(7); p38.printp(8); p39.printp(9); p40.printp(10); p41.printp(10);
		break;

	case 2:
		cout << " [  NC  ]" << '\n' << '\n';
		p61.printp(1); p62.printp(2); p63.printp(3); p64.printp(4); p65.printp(5);
		p66.printp(6); p67.printp(7); p68.printp(8); p69.printp(9); p70.printp(10); p71.printp(10);
		break;

	case 3:
		cout << " [ �λ� ]" << '\n' << '\n';
		p91.printp(1); p92.printp(2); p93.printp(3); p94.printp(4); p95.printp(5);
		p96.printp(6); p97.printp(7); p98.printp(8); p99.printp(9); p100.printp(10); p101.printp(10);
		break;

	case 4:
		cout << " [  LG  ]" << '\n' << '\n';
		p131.printp(1); p132.printp(2); p133.printp(3); p134.printp(4); p135.printp(5);
		p136.printp(6); p137.printp(7); p138.printp(8); p139.printp(9); p140.printp(10); p141.printp(10);
		break;

	case 5:
		cout << " [ SSG  ]" << '\n' << '\n';
		p161.printp(1); p162.printp(2); p163.printp(3); p164.printp(4); p165.printp(5);
		p166.printp(6); p167.printp(7); p168.printp(8); p169.printp(9); p170.printp(10); p171.printp(10);
		break;

	case 11:
		cout << " [ ���� ]" << '\n' << '\n';
		p8001.printp(1); p8002.printp(2); p8003.printp(3); p8004.printp(4); p8005.printp(5);
		p8006.printp(6); p8007.printp(7); p8008.printp(8); p8009.printp(9); p8010.printp(10); p8011.printp(10);
		break;

	case 12:
		cout << " [ ���� ]" << '\n' << '\n';
		p9001.printp(1); p9002.printp(2); p9003.printp(3); p9004.printp(4); p9005.printp(5);
		p9006.printp(6); p9007.printp(7); p9008.printp(8); p9009.printp(9); p9010.printp(10); p9011.printp(10);
		break;
	}

	return;




}


void play(int gam, int* total_gam, int my_team, int sound, int game_speed, bool use_condition, bool* music_check)
{


	for (int i = 8; i < 50; i++)
	{
		cur(15, i);
		cout << "                         ";
	}

	cur(12, 15);
	cout << "�÷����� ��� �� : ";
	cin >> gam;

	system("cls");

	Base.ch();


	int s_sim = sim;

	int split = 5;

	if (cin.fail() || gam < 1) {
		cin.clear();
		cin.ignore(100, '\n');
	}

	else { // ������ �������

		if (sim == 2)
			PlaySound(NULL, NULL, NULL);

		for (int i = 0; i < gam; i++)
		{
			switch (my_team) {
			case 0:
				if (*total_gam % split == 0) {
					playball(samsung, nc, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					nc.result(1);
					sim = 1;

					*total_gam -= 1; playball(ssg, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(lg, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					doosan.result(1);

					sim = s_sim;

				}

				else if (*total_gam % split == 1) {
					playball(samsung, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					doosan.result(1);
					sim = 1;

					*total_gam -= 1; playball(lg, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					ssg.result(1);

					*total_gam -= 1; playball(lotte, nc, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					nc.result(1);


					sim = s_sim;

				}

				else if (*total_gam % split == 2) {
					playball(samsung, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					lotte.result(1);
					sim = 1;

					*total_gam -= 1; playball(nc, lg, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					nc.result(0);
					lg.result(1);

					*total_gam -= 1; playball(doosan, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					ssg.result(1);

					sim = s_sim;

				}

				else if (*total_gam % split == 3) {
					playball(samsung, lg, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					lg.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, lotte, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(ssg, nc, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					nc.result(1);

					sim = s_sim;

				}

				else if (*total_gam % split == 4) {
					playball(samsung, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					ssg.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, nc, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					nc.result(1);

					*total_gam -= 1; playball(lotte, lg, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					lg.result(1);

					sim = s_sim;

				}

				break;

			case 1:
				if (*total_gam % split == 0) {
					playball(lotte, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					ssg.result(1);
					sim = 1;

					*total_gam -= 1; playball(samsung, nc, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					nc.result(1);

					*total_gam -= 1; playball(lg, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					doosan.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 1) {
					playball(lotte, nc, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					nc.result(1);
					sim = 1;

					*total_gam -= 1; playball(lg, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					ssg.result(1);

					*total_gam -= 1; playball(doosan, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					samsung.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 2) {
					playball(lotte, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					samsung.result(1);
					sim = 1;

					*total_gam -= 1; playball(nc, lg, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					nc.result(0);
					lg.result(1);

					*total_gam -= 1; playball(doosan, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					ssg.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 3) {
					playball(lotte, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					doosan.result(1);
					sim = 1;

					*total_gam -= 1; playball(samsung, lg, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					samsung.result(0);
					lg.result(1);

					*total_gam -= 1; playball(ssg, nc, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					nc.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 4) {
					playball(lotte, lg, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					lg.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, nc, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					nc.result(1);

					*total_gam -= 1; playball(samsung, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					ssg.result(1);
					sim = s_sim;

				}

				break;

			case 2:
				if (*total_gam % split == 0) {
					playball(nc, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					nc.result(0);
					samsung.result(1);
					sim = 1;

					*total_gam -= 1; playball(ssg, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(lg, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					doosan.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 1) {
					playball(nc, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					nc.result(0);
					lotte.result(1);
					sim = 1;

					*total_gam -= 1; playball(lg, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					ssg.result(1);

					*total_gam -= 1; playball(doosan, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					samsung.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 2) {
					playball(nc, lg, &total_gam, sound, game_speed, my_team, use_condition);
					nc.result(0);
					lg.result(1);
					sim = 1;

					*total_gam -= 1; playball(samsung, lotte, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					samsung.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(doosan, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					ssg.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 3) {
					playball(nc, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					nc.result(0);
					ssg.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, lotte, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(lg, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					samsung.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 4) {
					playball(nc, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					nc.result(0);
					doosan.result(1);
					sim = 1;

					*total_gam -= 1; playball(ssg, samsung, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					ssg.result(0);
					samsung.result(1);

					*total_gam -= 1; playball(lotte, lg, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					lg.result(1);
					sim = s_sim;

				}

				break;

			case 3:
				if (*total_gam % split == 0) {
					playball(doosan, lg, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					lg.result(1);
					sim = 1;

					*total_gam -= 1; playball(ssg, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(samsung, nc, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					nc.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 1) {
					playball(doosan, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					samsung.result(1);
					sim = 1;

					*total_gam -= 1; playball(lg, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					ssg.result(1);

					*total_gam -= 1; playball(lotte, nc, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					nc.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 2) {
					playball(doosan, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					ssg.result(1);
					sim = 1;

					*total_gam -= 1; playball(nc, lg, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					nc.result(0);
					lg.result(1);

					*total_gam -= 1; playball(samsung, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					lotte.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 3) {
					playball(doosan, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					lotte.result(1);
					sim = 1;

					*total_gam -= 1; playball(lg, samsung, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					lg.result(0);
					samsung.result(1);

					*total_gam -= 1; playball(ssg, nc, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					nc.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 4) {
					playball(doosan, nc, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					nc.result(1);
					sim = 1;

					*total_gam -= 1; playball(samsung, ssg, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					samsung.result(0);
					ssg.result(1);

					*total_gam -= 1; playball(lotte, lg, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					lg.result(1);
					sim = s_sim;

				}

				break;

			case 4:
				if (*total_gam % split == 0) {
					playball(lg, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					doosan.result(1);
					sim = 1;

					*total_gam -= 1; playball(ssg, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(samsung, nc, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					nc.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 1) {
					playball(lg, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					ssg.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					samsung.result(1);

					*total_gam -= 1; playball(lotte, nc, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					nc.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 2) {
					playball(lg, nc, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					nc.result(1);
					sim = 1;

					*total_gam -= 1; playball(samsung, lotte, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					samsung.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(doosan, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					ssg.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 3) {
					playball(lg, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					samsung.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, lotte, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(ssg, nc, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					nc.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 4) {
					playball(lg, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					lotte.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, nc, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					nc.result(1);

					*total_gam -= 1; playball(samsung, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					ssg.result(1);
					sim = s_sim;

				}

				break;

			case 5:
				if (*total_gam % split == 0) {
					playball(ssg, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					lotte.result(1);
					sim = 1;

					*total_gam -= 1; playball(samsung, nc, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					nc.result(1);

					*total_gam -= 1; playball(lg, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					doosan.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 1) {
					playball(ssg, lg, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					lg.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					samsung.result(1);

					*total_gam -= 1; playball(nc, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					nc.result(0);
					lotte.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 2) {
					playball(ssg, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					doosan.result(1);
					sim = 1;

					*total_gam -= 1; playball(nc, lg, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					nc.result(0);
					lg.result(1);

					*total_gam -= 1; playball(samsung, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					samsung.result(0);
					lotte.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 3) {
					playball(ssg, nc, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					nc.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, lotte, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(lg, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					samsung.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 4) {
					playball(ssg, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					samsung.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, nc, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					nc.result(1);

					*total_gam -= 1; playball(lotte, lg, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					lg.result(1);
					sim = s_sim;

				}

				break;

			case 11:
				if (*total_gam % split == 0) {
					playball(hd, nc, &total_gam, sound, game_speed, my_team, use_condition);
					hd.result(0);
					nc.result(1);
					sim = 1;

					*total_gam -= 1; playball(ssg, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(lg, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					doosan.result(1);

					sim = s_sim;

				}

				else if (*total_gam % split == 1) {
					playball(hd, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					hd.result(0);
					doosan.result(1);
					sim = 1;

					*total_gam -= 1; playball(lg, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					ssg.result(1);

					*total_gam -= 1; playball(lotte, nc, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					nc.result(1);


					sim = s_sim;

				}

				else if (*total_gam % split == 2) {
					playball(hd, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					hd.result(0);
					lotte.result(1);
					sim = 1;

					*total_gam -= 1; playball(nc, lg, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					nc.result(0);
					lg.result(1);

					*total_gam -= 1; playball(doosan, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					ssg.result(1);

					sim = s_sim;

				}

				else if (*total_gam % split == 3) {
					playball(hd, lg, &total_gam, sound, game_speed, my_team, use_condition);
					hd.result(0);
					lg.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, lotte, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(ssg, nc, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					nc.result(1);

					sim = s_sim;

				}

				else if (*total_gam % split == 4) {
					playball(hd, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					hd.result(0);
					ssg.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, nc, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					nc.result(1);

					*total_gam -= 1; playball(lotte, lg, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					lg.result(1);

					sim = s_sim;

				}

				break;

			case 12:
				if (*total_gam % split == 0) {
					playball(hai, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					hai.result(0);
					samsung.result(1);
					sim = 1;

					*total_gam -= 1; playball(ssg, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					ssg.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(lg, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					doosan.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 1) {
					playball(hai, lotte, &total_gam, sound, game_speed, my_team, use_condition);
					hai.result(0);
					lotte.result(1);
					sim = 1;

					*total_gam -= 1; playball(lg, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					ssg.result(1);

					*total_gam -= 1; playball(doosan, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					samsung.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 2) {
					playball(hai, lg, &total_gam, sound, game_speed, my_team, use_condition);
					hai.result(0);
					lg.result(1);
					sim = 1;

					*total_gam -= 1; playball(samsung, lotte, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					samsung.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(doosan, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					doosan.result(0);
					ssg.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 3) {
					playball(hai, ssg, &total_gam, sound, game_speed, my_team, use_condition);
					hai.result(0);
					ssg.result(1);
					sim = 1;

					*total_gam -= 1; playball(doosan, lotte, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					doosan.result(0);
					lotte.result(1);

					*total_gam -= 1; playball(lg, samsung, &total_gam, sound, game_speed, my_team, use_condition);
					lg.result(0);
					samsung.result(1);
					sim = s_sim;

				}

				else if (*total_gam % split == 4) {
					playball(hai, doosan, &total_gam, sound, game_speed, my_team, use_condition);
					hai.result(0);
					doosan.result(1);
					sim = 1;

					*total_gam -= 1; playball(ssg, samsung, &total_gam, sound, game_speed, my_team, use_condition);// *total_gam -= 1;
					ssg.result(0);
					samsung.result(1);

					*total_gam -= 1; playball(lotte, lg, &total_gam, sound, game_speed, my_team, use_condition);
					lotte.result(0);
					lg.result(1);
					sim = s_sim;

				}

				break;
			}

			cur(0, 43);
			if (sim == 2 && gam > 0)
			{
				system("pause");

				cur(0, 43); cout << "                                                                    ";
			}


			if (sim == 2)
			{
				PlaySound(NULL, NULL, NULL);
				scoreboard[0][19] = 0;
				*music_check = false;
			}

			//*total_gam += gam;
		}
	}
}



void print_hitter_record(int total_gam, int my_team, boolean br, boolean gameplay, int hitter) // Ÿ�� ���,
{
	int key = 49; // �ʱⰪ��

	int re = 0; // ������

	int show = 0; // show�� ��ü

	static int change_hitter = 3;
	static int change_totalgam = 0;

	double t[17];

	if (gameplay == false)
	{
		while (1) {

			re = key;

			if (key > 48 && key < 56) {
				if (key == 52 || key == 53)
				{
					if (re == 54 || re == 55)
						re = key;
				}

				else
					system("cls");
			}

			if (br == true) {
				cur(5, 4); cout << hh.stat(total_gam);
				cur(0, 38); cout << "    [  ���  ] " << '\n';
			}

			cur(1, 1);
			cout << "  [ Esc : ������ ] [ [1], [2] : ���� Ȯ�� ] [ [3] : �ɷ�ġ Ȯ�� ] [ [4] : ���� ��ü ] [ [5] : Ʈ���̵� ] [ [6], [7] : �� ���� ] ";
			cur(23, 4);

			if (key == 49) cout << "   [ ������ ]  [ Ÿ �� ]  [ ����� ]  [ ��Ÿ�� ]   [ ����� ]   [ Ÿ�� ]  [ Ÿ�� ]  [ ��Ÿ ]  [ Ȩ�� ]   [ ��ġ ]   " << '\n' << '\n';
			else if (key == 50) cout << "   [ ������ ]  [ ���� ]  [ ���� ]  [ ��Ÿ ]  [ 2��Ÿ ]  [ 3��Ÿ ]  [ Ȩ�� ]  [ Ÿ�� ]  [ ���� ]  [ ������ ]" << '\n' << '\n';
			else if (key == 51) cout << "   [ ������ ]  [ ������ ]  [ ��Ȯ�� ]  [ �� �� ]  [ ���ǵ� ]  [ ����� ]  [ ���� ]  [ ������ ]   [  OPS  ]" << '\n' << '\n';
			else if (key == 54 || ((re == 50 || re == 51) && key > 50)) {
				cur(5, 4);
				cout << "   [    ���ܸ�    ]   [  ���  ]   [  ��  ]   [  ��  ]   [  ��  ]  [  �·�  ]   [  Ÿ��  ]   [ ����� ]    [ ��Ÿ�� ]   [ ����å ] " << '\n' << '\n';
			}
			else if (key == 55 || ((re == 50 || re == 51) && key > 50)) {
				cur(5, 4);
				cout << "   [    ���ܸ�    ]   [  ���  ]   [  ��  ]   [  ��  ]   [  ��  ]  [  �·�  ]    [ �ֱ� 10��� ]   [ ���� ]   [ Ȩ�� ]" << '\n' << '\n';
			}




			if (key > 48 && key < 54 && re < 52) {

				show = key - 48;

				if (my_team == 0 || my_team == 11) {

					if (my_team == 0)
					{
						h1.print(total_gam, show); h2.print(total_gam, show); h3.print(total_gam, show);
						h4.print(total_gam, show); h5.print(total_gam, show); h6.print(total_gam, show);
						h7.print(total_gam, show); h8.print(total_gam, show); h9.print(total_gam, show);


						h10.print(total_gam, show); h11.print(total_gam, show); h12.print(total_gam, show);
						h13.print(total_gam, show); h14.print(total_gam, show); h15.print(total_gam, show); h16.print(total_gam, show);


						cout << '\n' << '\n' << "   [ �� Ÿ�� ] :  "; // ��� ��Ÿ��

						samsung.show_hit(0);

						cout << "  [ �� ��յ��� ] :  "; samsung.show_get();
						cout << "  [ �� ��ս��� ] :  "; samsung.show_lost();

						cout << '\n' << '\n';
					}

					else
					{
						h8001.print(total_gam, show); h8002.print(total_gam, show); h8003.print(total_gam, show);
						h8004.print(total_gam, show); h8005.print(total_gam, show); h8006.print(total_gam, show);
						h8007.print(total_gam, show); h8008.print(total_gam, show); h8009.print(total_gam, show);


						h8010.print(total_gam, show); h8011.print(total_gam, show); h8012.print(total_gam, show);
						h8013.print(total_gam, show); h8014.print(total_gam, show); h8015.print(total_gam, show); h8016.print(total_gam, show);


						cout << '\n' << '\n' << "   [ �� Ÿ�� ] :  "; // ��� ��Ÿ��

						hd.show_hit(0);

						cout << "  [ �� ��յ��� ] :  "; hd.show_get();
						cout << "  [ �� ��ս��� ] :  "; hd.show_lost();

						cout << '\n' << '\n';
					}

				}

				else if (my_team == 1) {

					h31.print(total_gam, show); h32.print(total_gam, show); h33.print(total_gam, show);
					h34.print(total_gam, show); h35.print(total_gam, show); h36.print(total_gam, show);
					h37.print(total_gam, show); h38.print(total_gam, show); h39.print(total_gam, show);


					h40.print(total_gam, show); h41.print(total_gam, show); h42.print(total_gam, show);
					h43.print(total_gam, show); h44.print(total_gam, show); h45.print(total_gam, show); h46.print(total_gam, show);


					cout << '\n' << '\n' << "   [ �� Ÿ�� ] :  "; // ��� ��Ÿ��

					lotte.show_hit(0);

					cout << "  [ �� ��յ��� ] :  "; lotte.show_get();
					cout << "  [ �� ��ս��� ] :  "; lotte.show_lost();

					cout << '\n' << '\n';

				}

				else if (my_team == 2 || my_team == 12) {

					if (my_team == 2)
					{
						h61.print(total_gam, show); h62.print(total_gam, show); h63.print(total_gam, show);
						h64.print(total_gam, show); h65.print(total_gam, show); h66.print(total_gam, show);
						h67.print(total_gam, show); h68.print(total_gam, show); h69.print(total_gam, show);


						h70.print(total_gam, show); h71.print(total_gam, show); h72.print(total_gam, show);
						h73.print(total_gam, show); h74.print(total_gam, show); h75.print(total_gam, show); h76.print(total_gam, show);


						cout << '\n' << '\n' << "   [ �� Ÿ�� ] :  "; // ��� ��Ÿ��

						nc.show_hit(0);

						cout << "  [ �� ��յ��� ] :  "; nc.show_get();
						cout << "  [ �� ��ս��� ] :  "; nc.show_lost();

						cout << '\n' << '\n';
					}

					else
					{
						h9001.print(total_gam, show); h9002.print(total_gam, show); h9003.print(total_gam, show);
						h9004.print(total_gam, show); h9005.print(total_gam, show); h9006.print(total_gam, show);
						h9007.print(total_gam, show); h9008.print(total_gam, show); h9009.print(total_gam, show);


						h9010.print(total_gam, show); h9011.print(total_gam, show); h9012.print(total_gam, show);
						h9013.print(total_gam, show); h9014.print(total_gam, show); h9015.print(total_gam, show); h9016.print(total_gam, show);


						cout << '\n' << '\n' << "   [ �� Ÿ�� ] :  "; // ��� ��Ÿ��

						hai.show_hit(0);

						cout << "  [ �� ��յ��� ] :  "; hai.show_get();
						cout << "  [ �� ��ս��� ] :  "; hai.show_lost();

						cout << '\n' << '\n';
					}

				}


				else if (my_team == 3) {

					h91.print(total_gam, show); h92.print(total_gam, show); h93.print(total_gam, show);
					h94.print(total_gam, show); h95.print(total_gam, show); h96.print(total_gam, show);
					h97.print(total_gam, show); h98.print(total_gam, show); h99.print(total_gam, show);


					h100.print(total_gam, show); h101.print(total_gam, show); h102.print(total_gam, show);
					h103.print(total_gam, show); h104.print(total_gam, show); h105.print(total_gam, show); h106.print(total_gam, show);


					cout << '\n' << '\n' << "   [ �� Ÿ�� ] :  "; // ��� ��Ÿ��

					doosan.show_hit(0);

					cout << "  [ �� ��յ��� ] :  "; doosan.show_get();
					cout << "  [ �� ��ս��� ] :  "; doosan.show_lost();

					cout << '\n' << '\n';

				}


				else if (my_team == 4) {

					h131.print(total_gam, show); h132.print(total_gam, show); h133.print(total_gam, show);
					h134.print(total_gam, show); h135.print(total_gam, show); h136.print(total_gam, show);
					h137.print(total_gam, show); h138.print(total_gam, show); h139.print(total_gam, show);


					h140.print(total_gam, show); h141.print(total_gam, show); h142.print(total_gam, show);
					h143.print(total_gam, show); h144.print(total_gam, show); h145.print(total_gam, show); h146.print(total_gam, show);


					cout << '\n' << '\n' << "   [ �� Ÿ�� ] :  "; // ��� ��Ÿ��

					lg.show_hit(0);

					cout << "  [ �� ��յ��� ] :  "; lg.show_get();
					cout << "  [ �� ��ս��� ] :  "; lg.show_lost();

					cout << '\n' << '\n';

				}


				else if (my_team == 5) {

					h161.print(total_gam, show); h162.print(total_gam, show); h163.print(total_gam, show);
					h164.print(total_gam, show); h165.print(total_gam, show); h166.print(total_gam, show);
					h167.print(total_gam, show); h168.print(total_gam, show); h169.print(total_gam, show);


					h170.print(total_gam, show); h171.print(total_gam, show); h172.print(total_gam, show);
					h173.print(total_gam, show); h174.print(total_gam, show); h175.print(total_gam, show); h176.print(total_gam, show);


					cout << '\n' << '\n' << "   [ �� Ÿ�� ] :  "; // ��� ��Ÿ��

					ssg.show_hit(0);

					cout << "  [ �� ��յ��� ] :  "; ssg.show_get();
					cout << "  [ �� ��ս��� ] :  "; ssg.show_lost();

					cout << '\n' << '\n';

				}
			}

			cout.precision(2); cout << fixed;

			if (key >= 54) {

				if (my_team == 11)
				{
					t[0] = hd.s__res();
					t[1] = lotte.s__res();
					t[2] = nc.s__res();
					t[3] = doosan.s__res();
					t[4] = lg.s__res();
					t[5] = ssg.s__res();
					t[6] = 0;
					t[7] = 0;
					t[8] = 0;
					t[9] = 0;
					t[10] = 0;
					t[11] = 0;
					t[12] = 0;
				}

				else if (my_team == 12)
				{
					t[0] = samsung.s__res();
					t[1] = lotte.s__res();
					t[2] = hai.s__res();
					t[3] = doosan.s__res();
					t[4] = lg.s__res();
					t[5] = ssg.s__res();
					t[6] = 0;
					t[7] = 0;
					t[8] = 0;
					t[9] = 0;
					t[10] = 0;
					t[11] = 0;
					t[12] = 0;
				}

				else
				{
					t[0] = samsung.s__res();
					t[1] = lotte.s__res();
					t[2] = nc.s__res();
					t[3] = doosan.s__res();
					t[4] = lg.s__res();
					t[5] = ssg.s__res();
					t[6] = 0;
					t[7] = 0;
					t[8] = 0;
					t[9] = 0;
					t[10] = 0;
					t[11] = 0;
					t[12] = 0;
				}





				for (int k = 0; k < 5; k++)
				{
					for (int i = 0; i < 5; i++)
					{
						if (t[i] < t[i + 1])
						{
							t[6] = t[i];
							t[i] = t[i + 1];
							t[i + 1] = t[6];
						}
					}
				}




				for (int i = 0; i < 6; i++)
				{

					if ((t[i] == samsung.s__res() && t[7] == 0) || (t[i] == hd.s__res() && t[7] == 0))
					{
						if (my_team != 11)
						{
							if (t[i] == samsung.s__res() && t[7] == 0)
							{
								if (my_team == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

								t[7] = 1;
								cout << "  [" << i + 1 << "]";
								cout << "    �Ｚ ���̿���     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								samsung.s_res(); cout.precision(3); cout << fixed;


								if (key == 54)
								{
									samsung.show_hit(1);
									cout << setw(12);

									cout.precision(2); cout << fixed;
									cout << (float)(p1.pitcher_los() + p2.pitcher_los() + p3.pitcher_los() + p4.pitcher_los() + p5.pitcher_los()
										+ p6.pitcher_los() + p7.pitcher_los() + p8.pitcher_los() + p9.pitcher_los() + p10.pitcher_los() + p11.pitcher_los()) /
										(p1.print__inn() + p2.print__inn() + p3.print__inn() + p4.print__inn() + p5.print__inn()
											+ p6.print__inn() + p7.print__inn() + p8.print__inn() + p9.print__inn() + p10.print__inn() + p11.print__inn()) * 27;
								}


								else
								{

									samsung.s_recent();
									cout << setw(9);
									samsung.s_streak();
									cout << setw(11);
									samsung.show_hr();


								}




								cout << '\n' << '\n';

								cout.precision(3); cout << fixed;

							}
						}

						else
						{
							if (t[i] == hd.s__res() && t[7] == 0)
							{
								if (my_team == 11) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

								t[7] = 1;
								cout << "  [" << i + 1 << "]";
								cout << "    ���� �����ܽ�     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								hd.s_res(); cout.precision(3); cout << fixed;


								if (key == 54)
								{
									hd.show_hit(1);
									cout << setw(12);

									cout.precision(2); cout << fixed;
									cout << (float)(p8001.pitcher_los() + p8002.pitcher_los() + p8003.pitcher_los() + p8004.pitcher_los() +
										p8005.pitcher_los() + p8006.pitcher_los() + p8007.pitcher_los() + p8008.pitcher_los() + p8009.pitcher_los() + p8010.pitcher_los() + p8011.pitcher_los()) /
										(p8001.print__inn() + p8002.print__inn() + p8003.print__inn() + p8004.print__inn() +
											p8005.print__inn() + p8006.print__inn() + p8007.print__inn() + p8008.print__inn() + p8009.print__inn() + p8010.print__inn() + p8011.print__inn()) * 27;
								}


								else
								{

									hd.s_recent();
									cout << setw(9);
									hd.s_streak();
									cout << setw(11);
									hd.show_hr();


								}




								cout << '\n' << '\n';

								cout.precision(3); cout << fixed;

							}
						}

					}




					else if (t[i] == lotte.s__res() && t[8] == 0)
					{
						if (my_team == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

						t[8] = 1;
						cout << "  [" << i + 1 << "]";
						cout << "    �Ե� ���̾���     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						lotte.s_res(); cout.precision(3); cout << fixed;






						if (key == 54)
						{
							lotte.show_hit(1);
							cout << setw(12);

							cout.precision(2); cout << fixed;
							cout << (float)(p31.pitcher_los() + p32.pitcher_los() + p33.pitcher_los() + p34.pitcher_los() + p35.pitcher_los()
								+ p36.pitcher_los() + p37.pitcher_los() + p38.pitcher_los() + p39.pitcher_los() + p40.pitcher_los() + p41.pitcher_los()) /
								(p31.print__inn() + p32.print__inn() + p33.print__inn() + p34.print__inn() + p35.print__inn()
									+ p36.print__inn() + p37.print__inn() + p38.print__inn() + p39.print__inn() + p40.print__inn() + p41.print__inn()) * 27;
						}

						else
						{
							lotte.s_recent();
							cout << setw(9);
							lotte.s_streak();
							cout << setw(11);
							lotte.show_hr();

						}



						cout << '\n' << '\n';

						cout.precision(3); cout << fixed;
					}


					else if ((t[i] == nc.s__res() && t[9] == 0) || (t[i] == hai.s__res() && t[9] == 0))
					{

						if (my_team != 12)
						{
							if (my_team == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

							t[9] = 1;
							cout << "  [" << i + 1 << "]";
							cout << "     NC  ���̳뽺     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							nc.s_res(); cout.precision(3); cout << fixed;





							if (key == 54)
							{
								nc.show_hit(1);
								cout << setw(12);

								cout.precision(2); cout << fixed;
								cout << (float)(p61.pitcher_los() + p62.pitcher_los() + p63.pitcher_los() + p64.pitcher_los() +
									p65.pitcher_los() + p66.pitcher_los() + p67.pitcher_los() + p68.pitcher_los() + p69.pitcher_los() + p70.pitcher_los() + p71.pitcher_los()) /
									(p61.print__inn() + p62.print__inn() + p63.print__inn() + p64.print__inn() + p65.print__inn() +
										p66.print__inn() + p67.print__inn() + p68.print__inn() + p69.print__inn() + p70.print__inn() + p71.print__inn()) * 27;
							}

							else
							{
								nc.s_recent();
								cout << setw(9);
								nc.s_streak();
								cout << setw(11);
								nc.show_hr();
							}


							cout << '\n' << '\n';



							cout.precision(3); cout << fixed;
						}

						else
						{
							if (t[i] == hai.s__res() && t[9] == 0)
							{
								if (my_team == 12) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

								t[9] = 1;
								cout << "  [" << i + 1 << "]";
								cout << "    ���� Ÿ�̰���     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								hai.s_res(); cout.precision(3); cout << fixed;


								if (key == 54)
								{
									hai.show_hit(1);
									cout << setw(12);

									cout.precision(2); cout << fixed;
									cout << (float)(p9001.pitcher_los() + p9002.pitcher_los() + p9003.pitcher_los() + p9004.pitcher_los() +
										p9005.pitcher_los() + p9006.pitcher_los() + p9007.pitcher_los() + p9008.pitcher_los() + p9009.pitcher_los() + p9010.pitcher_los() + p9011.pitcher_los()) /
										(p9001.print__inn() + p9002.print__inn() + p9003.print__inn() + p9004.print__inn() +
											p9005.print__inn() + p9006.print__inn() + p9007.print__inn() + p9008.print__inn() + p9009.print__inn() + p9010.print__inn() + p9011.print__inn()) * 27;
								}


								else
								{

									hai.s_recent();
									cout << setw(9);
									hai.s_streak();
									cout << setw(11);
									hai.show_hr();


								}




								cout << '\n' << '\n';

								cout.precision(3); cout << fixed;

							}
						}



					}

					else if (t[i] == doosan.s__res() && t[10] == 0)
					{
						if (my_team == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

						t[10] = 1;
						cout << "  [" << i + 1 << "]";
						cout << "     �λ�  ���     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						doosan.s_res(); cout.precision(3); cout << fixed;

						if (key == 54)
						{
							doosan.show_hit(1);
							cout << setw(12);

							cout.precision(2); cout << fixed;
							cout << (float)(p91.pitcher_los() + p92.pitcher_los() + p93.pitcher_los() + p94.pitcher_los() + p95.pitcher_los()
								+ p96.pitcher_los() + p97.pitcher_los() + p98.pitcher_los() + p99.pitcher_los() + p100.pitcher_los() + p101.pitcher_los()) /
								(p91.print__inn() + p92.print__inn() + p93.print__inn() + p94.print__inn() + p95.print__inn()
									+ p96.print__inn() + p97.print__inn() + p98.print__inn() + p99.print__inn() + p100.print__inn() + p101.print__inn()) * 27;
						}

						else
						{
							doosan.s_recent();
							cout << setw(9);
							doosan.s_streak();
							cout << setw(11);
							doosan.show_hr();
						}



						cout << '\n' << '\n';



						cout.precision(3); cout << fixed;
					}

					else if (t[i] == lg.s__res() && t[11] == 0)
					{
						if (my_team == 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

						t[11] = 1;
						cout << "  [" << i + 1 << "]";
						cout << "       LG  Ʈ����     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						lg.s_res(); cout.precision(3); cout << fixed;

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

						if (key == 54)
						{
							lg.show_hit(1);
							cout << setw(12);

							cout.precision(2); cout << fixed;
							cout << (float)(p131.pitcher_los() + p132.pitcher_los() + p133.pitcher_los() + p134.pitcher_los() + p135.pitcher_los() +
								p136.pitcher_los() + p137.pitcher_los() + p138.pitcher_los() + p139.pitcher_los() + p140.pitcher_los() + p141.pitcher_los()) /
								(p131.print__inn() + p132.print__inn() + p133.print__inn() + p134.print__inn() + p135.print__inn() +
									p136.print__inn() + p137.print__inn() + p138.print__inn() + p139.print__inn() + p140.print__inn() + p141.print__inn()) * 27;
						}


						else
						{
							lg.s_recent();
							cout << setw(9);
							lg.s_streak();
							cout << setw(11);
							lg.show_hr();

						}


						cout << '\n' << '\n';



						cout.precision(3); cout << fixed;
					}

					else if (t[i] == ssg.s__res() && t[12] == 0)
					{

						if (my_team == 5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

						t[12] = 1;
						cout << "  [" << i + 1 << "]";
						cout << "      SSG  ������     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						ssg.s_res(); cout.precision(3); cout << fixed;

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

						if (key == 54)
						{
							ssg.show_hit(1);
							cout << setw(12);

							cout.precision(2); cout << fixed;
							cout << (float)(p161.pitcher_los() + p162.pitcher_los() + p163.pitcher_los() + p164.pitcher_los() + p165.pitcher_los() +
								p166.pitcher_los() + p167.pitcher_los() + p168.pitcher_los() + p169.pitcher_los() + p170.pitcher_los() + p171.pitcher_los()) /
								(p161.print__inn() + p162.print__inn() + p163.print__inn() + p164.print__inn() + p165.print__inn() +
									p166.print__inn() + p167.print__inn() + p168.print__inn() + p169.print__inn() + p170.print__inn() + p171.print__inn()) * 27;
						}


						else
						{
							ssg.s_recent();
							cout << setw(9);
							ssg.s_streak();
							cout << setw(11);
							ssg.show_hr();
						}


						cout << '\n' << '\n';



						cout.precision(3); cout << fixed;
					}


				}



				key = re;


				cur(56, 22); cout << " [  ���� �������  ] ";

				switch (my_team)
				{
				case 0:
					switch (total_gam % 5)
					{
					case 0:
						cur(30, 25); show_battleteam(0, 2, total_gam);
						cur(30, 28); show_battleteam(5, 1, total_gam);
						cur(30, 31); show_battleteam(4, 3, total_gam);
						break;
					case 1:
						cur(30, 25); show_battleteam(0, 3, total_gam);
						cur(30, 28); show_battleteam(4, 5, total_gam);
						cur(30, 31); show_battleteam(1, 2, total_gam);
						break;
					case 2:
						cur(30, 25); show_battleteam(0, 1, total_gam);
						cur(30, 28); show_battleteam(1, 4, total_gam);
						cur(30, 31); show_battleteam(3, 5, total_gam);
						break;
					case 3:
						cur(30, 25); show_battleteam(0, 4, total_gam);
						cur(30, 28); show_battleteam(3, 1, total_gam);
						cur(30, 31); show_battleteam(5, 2, total_gam);
						break;
					case 4:
						cur(30, 25); show_battleteam(0, 5, total_gam);
						cur(30, 28); show_battleteam(3, 2, total_gam);
						cur(30, 31); show_battleteam(1, 4, total_gam);
						break;
					}
					break;
				case 1:
					switch (total_gam % 5)
					{
					case 0:
						cur(30, 26); show_battleteam(1, 5, total_gam);
						cur(30, 29); show_battleteam(0, 2, total_gam);
						cur(30, 32); show_battleteam(4, 3, total_gam);
						break;
					case 1:
						cur(30, 26); show_battleteam(1, 2, total_gam);
						cur(30, 29); show_battleteam(4, 5, total_gam);
						cur(30, 32); show_battleteam(3, 0, total_gam);
						break;
					case 2:
						cur(30, 26); show_battleteam(1, 0, total_gam);
						cur(30, 29); show_battleteam(2, 4, total_gam);
						cur(30, 32); show_battleteam(3, 5, total_gam);
						break;
					case 3:
						cur(30, 26); show_battleteam(1, 3, total_gam);
						cur(30, 29); show_battleteam(0, 4, total_gam);
						cur(30, 32); show_battleteam(5, 2, total_gam);
						break;
					case 4:
						cur(30, 26); show_battleteam(1, 4, total_gam);
						cur(30, 29); show_battleteam(3, 2, total_gam);
						cur(30, 32); show_battleteam(0, 5, total_gam);
						break;
					}
					break;
				case 2:
					switch (total_gam % 5)
					{
					case 0:
						cur(30, 26); show_battleteam(2, 0, total_gam);
						cur(30, 29); show_battleteam(5, 1, total_gam);
						cur(30, 32); show_battleteam(4, 3, total_gam);
						break;
					case 1:
						cur(30, 26); show_battleteam(2, 1, total_gam);
						cur(30, 29); show_battleteam(4, 5, total_gam);
						cur(30, 32); show_battleteam(3, 0, total_gam);
						break;
					case 2:
						cur(30, 26); show_battleteam(2, 4, total_gam);
						cur(30, 29); show_battleteam(0, 1, total_gam);
						cur(30, 32); show_battleteam(3, 5, total_gam);
						break;
					case 3:
						cur(30, 26); show_battleteam(2, 5, total_gam);
						cur(30, 29); show_battleteam(3, 1, total_gam);
						cur(30, 32); show_battleteam(4, 0, total_gam);
						break;
					case 4:
						cur(30, 26); show_battleteam(2, 3, total_gam);
						cur(30, 29); show_battleteam(5, 0, total_gam);
						cur(30, 32); show_battleteam(1, 4, total_gam);
						break;
					}
					break;
				case 3:
					switch (total_gam % 5)
					{
					case 0:
						cur(30, 26); show_battleteam(3, 4, total_gam);
						cur(30, 29); show_battleteam(5, 1, total_gam);
						cur(30, 32); show_battleteam(0, 2, total_gam);
						break;
					case 1:
						cur(30, 26); show_battleteam(3, 0, total_gam);
						cur(30, 29); show_battleteam(4, 5, total_gam);
						cur(30, 32); show_battleteam(1, 2, total_gam);
						break;
					case 2:
						cur(30, 26); show_battleteam(3, 5, total_gam);
						cur(30, 29); show_battleteam(2, 4, total_gam);
						cur(30, 32); show_battleteam(0, 1, total_gam);
						break;
					case 3:
						cur(30, 26); show_battleteam(3, 1, total_gam);
						cur(30, 29); show_battleteam(4, 0, total_gam);
						cur(30, 32); show_battleteam(5, 2, total_gam);
						break;
					case 4:
						cur(30, 26); show_battleteam(3, 2, total_gam);
						cur(30, 29); show_battleteam(0, 5, total_gam);
						cur(30, 32); show_battleteam(1, 4, total_gam);
						break;
					}
					break;
				case 4:
					switch (total_gam % 5)
					{
					case 0:
						cur(30, 26); show_battleteam(4, 3, total_gam);
						cur(30, 29); show_battleteam(5, 1, total_gam);
						cur(30, 32); show_battleteam(0, 2, total_gam);
						break;
					case 1:
						cur(30, 26); show_battleteam(4, 5, total_gam);
						cur(30, 29); show_battleteam(3, 0, total_gam);
						cur(30, 32); show_battleteam(1, 2, total_gam);
						break;
					case 2:
						cur(30, 26); show_battleteam(4, 2, total_gam);
						cur(30, 29); show_battleteam(0, 1, total_gam);
						cur(30, 32); show_battleteam(3, 5, total_gam);
						break;
					case 3:
						cur(30, 26); show_battleteam(4, 0, total_gam);
						cur(30, 29); show_battleteam(3, 1, total_gam);
						cur(30, 32); show_battleteam(5, 2, total_gam);
						break;
					case 4:
						cur(30, 26); show_battleteam(4, 1, total_gam);
						cur(30, 29); show_battleteam(3, 2, total_gam);
						cur(30, 32); show_battleteam(0, 5, total_gam);
						break;
					}
					break;
				case 5:
					switch (total_gam % 5)
					{
					case 0:
						cur(30, 26); show_battleteam(5, 1, total_gam);
						cur(30, 29); show_battleteam(0, 2, total_gam);
						cur(30, 32); show_battleteam(4, 3, total_gam);
						break;
					case 1:
						cur(30, 26); show_battleteam(5, 4, total_gam);
						cur(30, 29); show_battleteam(3, 0, total_gam);
						cur(30, 32); show_battleteam(2, 1, total_gam);
						break;
					case 2:
						cur(30, 26); show_battleteam(5, 3, total_gam);
						cur(30, 29); show_battleteam(2, 4, total_gam);
						cur(30, 32); show_battleteam(0, 1, total_gam);
						break;
					case 3:
						cur(30, 26); show_battleteam(5, 2, total_gam);
						cur(30, 29); show_battleteam(3, 1, total_gam);
						cur(30, 32); show_battleteam(4, 0, total_gam);
						break;
					case 4:
						cur(30, 26); show_battleteam(5, 0, total_gam);
						cur(30, 29); show_battleteam(3, 2, total_gam);
						cur(30, 32); show_battleteam(1, 4, total_gam);
						break;
					}
					break;
				case 11:
					switch (total_gam % 5)
					{
					case 0:
						cur(30, 25); show_battleteam(11, 2, total_gam);
						cur(30, 28); show_battleteam(5, 1, total_gam);
						cur(30, 31); show_battleteam(4, 3, total_gam);
						break;
					case 1:
						cur(30, 25); show_battleteam(11, 3, total_gam);
						cur(30, 28); show_battleteam(4, 5, total_gam);
						cur(30, 31); show_battleteam(1, 2, total_gam);
						break;
					case 2:
						cur(30, 25); show_battleteam(11, 1, total_gam);
						cur(30, 28); show_battleteam(1, 4, total_gam);
						cur(30, 31); show_battleteam(3, 5, total_gam);
						break;
					case 3:
						cur(30, 25); show_battleteam(11, 4, total_gam);
						cur(30, 28); show_battleteam(3, 1, total_gam);
						cur(30, 31); show_battleteam(5, 2, total_gam);
						break;
					case 4:
						cur(30, 25); show_battleteam(11, 5, total_gam);
						cur(30, 28); show_battleteam(3, 2, total_gam);
						cur(30, 31); show_battleteam(1, 4, total_gam);
						break;
					}
					break;
				case 12:
					switch (total_gam % 5)
					{
					case 0:
						cur(30, 26); show_battleteam(12, 0, total_gam);
						cur(30, 29); show_battleteam(5, 1, total_gam);
						cur(30, 32); show_battleteam(4, 3, total_gam);
						break;
					case 1:
						cur(30, 26); show_battleteam(12, 1, total_gam);
						cur(30, 29); show_battleteam(4, 5, total_gam);
						cur(30, 32); show_battleteam(3, 0, total_gam);
						break;
					case 2:
						cur(30, 26); show_battleteam(12, 4, total_gam);
						cur(30, 29); show_battleteam(0, 1, total_gam);
						cur(30, 32); show_battleteam(3, 5, total_gam);
						break;
					case 3:
						cur(30, 26); show_battleteam(12, 5, total_gam);
						cur(30, 29); show_battleteam(3, 1, total_gam);
						cur(30, 32); show_battleteam(4, 0, total_gam);
						break;
					case 4:
						cur(30, 26); show_battleteam(12, 3, total_gam);
						cur(30, 29); show_battleteam(5, 0, total_gam);
						cur(30, 32); show_battleteam(1, 4, total_gam);
						break;
					}
					break;
				}
			}


			if (key > 48 && key < 56 && re < 52) {
				cout << "   ���� ���� : " << total_gam << " ��� [ ����Ÿ�� : " << (int)(3.1 * total_gam) << " Ÿ�� ] ";
			}





			if (br == true) break;


			if (br == false) {

				key = getch();
				if (key == 27) break;
				if (!(key > 48 && key < 56))
					key = re;
			}



			if (key == 52 && re < 52) {
				change(total_gam, my_team, false);
				key = re;
			}

			else if (key == 53 && re < 52) {
				change(total_gam, my_team, true);
				key = re;
			}
		}
	}

	else if (change_totalgam != total_gam || change_hitter > 0)
	{
		system("cls");

		h1.restore_condition(true); h2.restore_condition(true); h3.restore_condition(true); h4.restore_condition(true); h5.restore_condition(true);
		h6.restore_condition(true); h7.restore_condition(true); h8.restore_condition(true); h9.restore_condition(true); h10.restore_condition(true);
		h11.restore_condition(true); h12.restore_condition(true); h13.restore_condition(true); h14.restore_condition(true); h15.restore_condition(true); h16.restore_condition(true);

		h31.restore_condition(true); h32.restore_condition(true); h33.restore_condition(true); h34.restore_condition(true); h35.restore_condition(true);
		h36.restore_condition(true); h37.restore_condition(true); h38.restore_condition(true); h39.restore_condition(true); h40.restore_condition(true);
		h41.restore_condition(true); h42.restore_condition(true); h43.restore_condition(true); h44.restore_condition(true); h45.restore_condition(true); h46.restore_condition(true);

		h61.restore_condition(true); h62.restore_condition(true); h63.restore_condition(true); h64.restore_condition(true); h65.restore_condition(true);
		h66.restore_condition(true); h67.restore_condition(true); h68.restore_condition(true); h69.restore_condition(true); h70.restore_condition(true);
		h71.restore_condition(true); h72.restore_condition(true); h73.restore_condition(true); h74.restore_condition(true); h75.restore_condition(true); h76.restore_condition(true);

		h91.restore_condition(true); h92.restore_condition(true); h93.restore_condition(true); h94.restore_condition(true); h95.restore_condition(true);
		h96.restore_condition(true); h97.restore_condition(true); h98.restore_condition(true); h99.restore_condition(true); h100.restore_condition(true);
		h101.restore_condition(true); h102.restore_condition(true); h103.restore_condition(true); h104.restore_condition(true); h105.restore_condition(true); h106.restore_condition(true);

		h131.restore_condition(true); h132.restore_condition(true); h133.restore_condition(true); h134.restore_condition(true); h135.restore_condition(true);
		h136.restore_condition(true); h137.restore_condition(true); h138.restore_condition(true); h139.restore_condition(true); h140.restore_condition(true);
		h141.restore_condition(true); h142.restore_condition(true); h143.restore_condition(true); h144.restore_condition(true); h145.restore_condition(true); h146.restore_condition(true);

		h161.restore_condition(true); h162.restore_condition(true); h163.restore_condition(true); h164.restore_condition(true); h165.restore_condition(true);
		h166.restore_condition(true); h167.restore_condition(true); h168.restore_condition(true); h169.restore_condition(true); h170.restore_condition(true);
		h171.restore_condition(true); h172.restore_condition(true); h173.restore_condition(true); h174.restore_condition(true); h175.restore_condition(true); h176.restore_condition(true);

		h8001.restore_condition(true); h8002.restore_condition(true); h8003.restore_condition(true); h8004.restore_condition(true); h8005.restore_condition(true);
		h8006.restore_condition(true); h8007.restore_condition(true); h8008.restore_condition(true); h8009.restore_condition(true); h8010.restore_condition(true);
		h8011.restore_condition(true); h8012.restore_condition(true); h8013.restore_condition(true); h8014.restore_condition(true); h8015.restore_condition(true); h8016.restore_condition(true);

		h9001.restore_condition(true); h9002.restore_condition(true); h9003.restore_condition(true); h9004.restore_condition(true); h9005.restore_condition(true);
		h9006.restore_condition(true); h9007.restore_condition(true); h9008.restore_condition(true); h9009.restore_condition(true); h9010.restore_condition(true);
		h9011.restore_condition(true); h9012.restore_condition(true); h9013.restore_condition(true); h9014.restore_condition(true); h9015.restore_condition(true); h9016.restore_condition(true);


		if (change_totalgam != total_gam)
		{
			change_totalgam = total_gam;
			change_hitter = 3;
		}

		while (1)
		{

			cur(25, 2); cout << " [ ��ü : [4] | ���� ���� : [Space]    ( ���� ��üȽ�� : " << change_hitter << "ȸ ) ] " << "   [ ���� Ÿ�� : " << hitter % 9 + 1 << "�� Ÿ�� ]";

			cur(23, 4);

			cout << "   [ ������ ]  [ ������ ]  [ ��Ȯ�� ]  [ �� �� ]  [ ���ǵ� ]  [ ����� ]   [ Ÿ  �� ]  [ ����� ]  [ ��Ÿ�� ]  [  OPS  ]  [ ������ ]  [ ��Ÿ / Ÿ�� ]" << '\n' << '\n';

			show = 6;

			if (my_team == 0) {

				h1.print(total_gam, show); h2.print(total_gam, show); h3.print(total_gam, show);
				h4.print(total_gam, show); h5.print(total_gam, show); h6.print(total_gam, show);
				h7.print(total_gam, show); h8.print(total_gam, show); h9.print(total_gam, show);


				h10.print(total_gam, show); h11.print(total_gam, show); h12.print(total_gam, show);
				h13.print(total_gam, show); h14.print(total_gam, show); h15.print(total_gam, show); h16.print(total_gam, show);

				cout << '\n' << '\n';

			}

			else if (my_team == 1) {

				h31.print(total_gam, show); h32.print(total_gam, show); h33.print(total_gam, show);
				h34.print(total_gam, show); h35.print(total_gam, show); h36.print(total_gam, show);
				h37.print(total_gam, show); h38.print(total_gam, show); h39.print(total_gam, show);


				h40.print(total_gam, show); h41.print(total_gam, show); h42.print(total_gam, show);
				h43.print(total_gam, show); h44.print(total_gam, show); h45.print(total_gam, show); h46.print(total_gam, show);

				cout << '\n' << '\n';

			}

			else if (my_team == 2) {

				h61.print(total_gam, show); h62.print(total_gam, show); h63.print(total_gam, show);
				h64.print(total_gam, show); h65.print(total_gam, show); h66.print(total_gam, show);
				h67.print(total_gam, show); h68.print(total_gam, show); h69.print(total_gam, show);


				h70.print(total_gam, show); h71.print(total_gam, show); h72.print(total_gam, show);
				h73.print(total_gam, show); h74.print(total_gam, show); h75.print(total_gam, show); h76.print(total_gam, show);

				cout << '\n' << '\n';

			}


			else if (my_team == 3) {

				h91.print(total_gam, show); h92.print(total_gam, show); h93.print(total_gam, show);
				h94.print(total_gam, show); h95.print(total_gam, show); h96.print(total_gam, show);
				h97.print(total_gam, show); h98.print(total_gam, show); h99.print(total_gam, show);


				h100.print(total_gam, show); h101.print(total_gam, show); h102.print(total_gam, show);
				h103.print(total_gam, show); h104.print(total_gam, show); h105.print(total_gam, show); h106.print(total_gam, show);

				cout << '\n' << '\n';

			}


			else if (my_team == 4) {

				h131.print(total_gam, show); h132.print(total_gam, show); h133.print(total_gam, show);
				h134.print(total_gam, show); h135.print(total_gam, show); h136.print(total_gam, show);
				h137.print(total_gam, show); h138.print(total_gam, show); h139.print(total_gam, show);


				h140.print(total_gam, show); h141.print(total_gam, show); h142.print(total_gam, show);
				h143.print(total_gam, show); h144.print(total_gam, show); h145.print(total_gam, show); h146.print(total_gam, show);

				cout << '\n' << '\n';

			}


			else if (my_team == 5) {

				h161.print(total_gam, show); h162.print(total_gam, show); h163.print(total_gam, show);
				h164.print(total_gam, show); h165.print(total_gam, show); h166.print(total_gam, show);
				h167.print(total_gam, show); h168.print(total_gam, show); h169.print(total_gam, show);


				h170.print(total_gam, show); h171.print(total_gam, show); h172.print(total_gam, show);
				h173.print(total_gam, show); h174.print(total_gam, show); h175.print(total_gam, show); h176.print(total_gam, show);

				cout << '\n' << '\n';

			}

			else if (my_team == 11) {

				h8001.print(total_gam, show); h8002.print(total_gam, show); h8003.print(total_gam, show);
				h8004.print(total_gam, show); h8005.print(total_gam, show); h8006.print(total_gam, show);
				h8007.print(total_gam, show); h8008.print(total_gam, show); h8009.print(total_gam, show);


				h8010.print(total_gam, show); h8011.print(total_gam, show); h8012.print(total_gam, show);
				h8013.print(total_gam, show); h8014.print(total_gam, show); h8015.print(total_gam, show); h8016.print(total_gam, show);

				cout << '\n' << '\n';

			}

			else if (my_team == 12) {

				h9001.print(total_gam, show); h9002.print(total_gam, show); h9003.print(total_gam, show);
				h9004.print(total_gam, show); h9005.print(total_gam, show); h9006.print(total_gam, show);
				h9007.print(total_gam, show); h9008.print(total_gam, show); h9009.print(total_gam, show);


				h9010.print(total_gam, show); h9011.print(total_gam, show); h9012.print(total_gam, show);
				h9013.print(total_gam, show); h9014.print(total_gam, show); h9015.print(total_gam, show); h9016.print(total_gam, show);

				cout << '\n' << '\n';

			}

			key = getch();

			if (key == 32)
			{
				change_hitter--;
				system("cls");


				h1.correct_condition(); h2.correct_condition(); h3.correct_condition(); h4.correct_condition(); h5.correct_condition();
				h6.correct_condition(); h7.correct_condition(); h8.correct_condition(); h9.correct_condition(); h10.correct_condition();
				h11.correct_condition(); h12.correct_condition(); h13.correct_condition(); h14.correct_condition(); h15.correct_condition(); h16.correct_condition();

				h31.correct_condition(); h32.correct_condition(); h33.correct_condition(); h34.correct_condition(); h35.correct_condition();
				h36.correct_condition(); h37.correct_condition(); h38.correct_condition(); h39.correct_condition(); h40.correct_condition();
				h41.correct_condition(); h42.correct_condition(); h43.correct_condition(); h44.correct_condition(); h45.correct_condition(); h46.correct_condition();

				h61.correct_condition(); h62.correct_condition(); h63.correct_condition(); h64.correct_condition(); h65.correct_condition();
				h66.correct_condition(); h67.correct_condition(); h68.correct_condition(); h69.correct_condition(); h70.correct_condition();
				h71.correct_condition(); h72.correct_condition(); h73.correct_condition(); h74.correct_condition(); h75.correct_condition(); h76.correct_condition();

				h91.correct_condition(); h92.correct_condition(); h93.correct_condition(); h94.correct_condition(); h95.correct_condition();
				h96.correct_condition(); h97.correct_condition(); h98.correct_condition(); h99.correct_condition(); h100.correct_condition();
				h101.correct_condition(); h102.correct_condition(); h103.correct_condition(); h104.correct_condition(); h105.correct_condition(); h106.correct_condition();

				h131.correct_condition(); h132.correct_condition(); h133.correct_condition(); h134.correct_condition(); h135.correct_condition();
				h136.correct_condition(); h137.correct_condition(); h138.correct_condition(); h139.correct_condition(); h140.correct_condition();
				h141.correct_condition(); h142.correct_condition(); h143.correct_condition(); h144.correct_condition(); h145.correct_condition(); h146.correct_condition();

				h161.correct_condition(); h162.correct_condition(); h163.correct_condition(); h164.correct_condition(); h165.correct_condition();
				h166.correct_condition(); h167.correct_condition(); h168.correct_condition(); h169.correct_condition(); h170.correct_condition();
				h171.correct_condition(); h172.correct_condition(); h173.correct_condition(); h174.correct_condition(); h175.correct_condition(); h176.correct_condition();

				h8001.correct_condition(); h8002.correct_condition(); h8003.correct_condition(); h8004.correct_condition(); h8005.correct_condition();
				h8006.correct_condition(); h8007.correct_condition(); h8008.correct_condition(); h8009.correct_condition(); h8010.correct_condition();
				h8011.correct_condition(); h8012.correct_condition(); h8013.correct_condition(); h8014.correct_condition(); h8015.correct_condition(); h8016.correct_condition();

				h9001.correct_condition(); h9002.correct_condition(); h9003.correct_condition(); h9004.correct_condition(); h9005.correct_condition();
				h9006.correct_condition(); h9007.correct_condition(); h9008.correct_condition(); h9009.correct_condition(); h9010.correct_condition();
				h9011.correct_condition(); h9012.correct_condition(); h9013.correct_condition(); h9014.correct_condition(); h9015.correct_condition(); h9016.correct_condition();


				break;
			}


			if (key == 52)
			{
				cur(0, 38); cout << "    [  ���  ] " << '\n';

				change(-5, my_team, false); // X��Ÿ�ڳ����� ��ü �Ұ���
				system("cls");
			}
		}


	}

}



void rechange_p(int total_gam, int my_team)
{
	int key = 49;

	while (1)
	{
		if (key == 27) {
			system("cls");
			return;
		}

		if (key > 48 && key < 56) {

			system("cls");
			cur(3, 2);
			cout << " [ �������� : 7�� ]   [ �� �� ]  [ �����å�� ]  [ ���� ]  [ ���� ]   [ ü�� ]   [ ���� ]   [ ���� ]   [ ���� ]   [ �� ]   [ �� ]  [ ��Ȩ�� ]  [ K/9 ]   [ BB/9 ]  [ WHIP ]  [  G  ]" << '\n' << '\n';

			switch (key)
			{
			case 49:
				if (my_team != 11)
				{
					cout << " [ �Ｚ ]" << '\n' << '\n';
					p1.printp(1); p2.printp(2); p3.printp(3); p4.printp(4); p5.printp(5);
					p6.printp(6); p7.printp(7); p8.printp(8); p9.printp(9); p10.printp(10); p11.printp(10);
				}
				else
				{
					cout << " [ ���� ]" << '\n' << '\n';
					p8001.printp(1); p8002.printp(2); p8003.printp(3); p8004.printp(4); p8005.printp(5);
					p8006.printp(6); p8007.printp(7); p8008.printp(8); p8009.printp(9); p8010.printp(10); p8011.printp(10);
				}

				break;
			case 50:
				cout << " [ �Ե� ]" << '\n' << '\n';
				p31.printp(1); p32.printp(2); p33.printp(3); p34.printp(4); p35.printp(5);
				p36.printp(6); p37.printp(7); p38.printp(8); p39.printp(9); p40.printp(10); p41.printp(10);
				break;

			case 51:
				if (my_team != 12)
				{
					cout << " [  NC  ]" << '\n' << '\n';
					p61.printp(1); p62.printp(2); p63.printp(3); p64.printp(4); p65.printp(5);
					p66.printp(6); p67.printp(7); p68.printp(8); p69.printp(9); p70.printp(10); p71.printp(10);
					break;
				}

				else
				{
					cout << " [ ���� ]" << '\n' << '\n';
					p9001.printp(1); p9002.printp(2); p9003.printp(3); p9004.printp(4); p9005.printp(5);
					p9006.printp(6); p9007.printp(7); p9008.printp(8); p9009.printp(9); p9010.printp(10); p9011.printp(10);
				}
				break;


			case 52:
				cout << " [ �λ� ]" << '\n' << '\n';
				p91.printp(1); p92.printp(2); p93.printp(3); p94.printp(4); p95.printp(5);
				p96.printp(6); p97.printp(7); p98.printp(8); p99.printp(9); p100.printp(10); p101.printp(10);
				break;

			case 53:
				cout << " [  LG  ]" << '\n' << '\n';
				p131.printp(1); p132.printp(2); p133.printp(3); p134.printp(4); p135.printp(5);
				p136.printp(6); p137.printp(7); p138.printp(8); p139.printp(9); p140.printp(10); p141.printp(10);
				break;

			case 54:
				cout << " [ SSG  ]" << '\n' << '\n';
				p161.printp(1); p162.printp(2); p163.printp(3); p164.printp(4); p165.printp(5);
				p166.printp(6); p167.printp(7); p168.printp(8); p169.printp(9); p170.printp(10); p171.printp(10);
				break;

			case 55:
				changepitcher(my_team);
				break;
			}
		}

		key = getch();
	}

}

void change_teamcolor(int my_team, int* number)
{
	if (my_team == 0) // �Ｚ
	{

		if (*number == 1) // '85�Ｚ
		{

			memcpy(&h1, &h1101, sizeof(class hitter)); memcpy(&h2, &h1102, sizeof(class hitter)); memcpy(&h3, &h1103, sizeof(class hitter));
			memcpy(&h4, &h1104, sizeof(class hitter)); memcpy(&h5, &h1105, sizeof(class hitter)); memcpy(&h6, &h1106, sizeof(class hitter));
			memcpy(&h7, &h1107, sizeof(class hitter)); memcpy(&h8, &h1108, sizeof(class hitter)); memcpy(&h9, &h1109, sizeof(class hitter));
			memcpy(&h10, &h1110, sizeof(class hitter)); memcpy(&h11, &h1111, sizeof(class hitter)); memcpy(&h12, &h1112, sizeof(class hitter));
			memcpy(&h13, &h1113, sizeof(class hitter)); memcpy(&h14, &h1114, sizeof(class hitter)); memcpy(&h15, &h1115, sizeof(class hitter));
			memcpy(&h16, &h1116, sizeof(class hitter));

			memcpy(&p1, &p1101, sizeof(class pitcher)); memcpy(&p2, &p1102, sizeof(class pitcher)); memcpy(&p3, &p1103, sizeof(class pitcher));
			memcpy(&p4, &p1104, sizeof(class pitcher)); memcpy(&p5, &p1105, sizeof(class pitcher)); memcpy(&p6, &p1106, sizeof(class pitcher));
			memcpy(&p7, &p1107, sizeof(class pitcher)); memcpy(&p8, &p1108, sizeof(class pitcher)); memcpy(&p9, &p1109, sizeof(class pitcher));
			memcpy(&p10, &p1110, sizeof(class pitcher)); memcpy(&p11, &p1111, sizeof(class pitcher));

			h6.change_dom(1);
		}
		else if (*number == 2) // '97�Ｚ
		{

			memcpy(&h1, &h1201, sizeof(class hitter)); memcpy(&h2, &h1202, sizeof(class hitter)); memcpy(&h3, &h1203, sizeof(class hitter));
			memcpy(&h4, &h1204, sizeof(class hitter)); memcpy(&h5, &h1205, sizeof(class hitter)); memcpy(&h6, &h1206, sizeof(class hitter));
			memcpy(&h7, &h1207, sizeof(class hitter)); memcpy(&h8, &h1208, sizeof(class hitter)); memcpy(&h9, &h1209, sizeof(class hitter));
			memcpy(&h10, &h1210, sizeof(class hitter)); memcpy(&h11, &h1211, sizeof(class hitter)); memcpy(&h12, &h1212, sizeof(class hitter));
			memcpy(&h13, &h1213, sizeof(class hitter)); memcpy(&h14, &h1214, sizeof(class hitter)); memcpy(&h15, &h1215, sizeof(class hitter));
			memcpy(&h16, &h1216, sizeof(class hitter));

			memcpy(&p1, &p1201, sizeof(class pitcher)); memcpy(&p2, &p1202, sizeof(class pitcher)); memcpy(&p3, &p1203, sizeof(class pitcher));
			memcpy(&p4, &p1204, sizeof(class pitcher)); memcpy(&p5, &p1205, sizeof(class pitcher)); memcpy(&p6, &p1206, sizeof(class pitcher));
			memcpy(&p7, &p1207, sizeof(class pitcher)); memcpy(&p8, &p1208, sizeof(class pitcher)); memcpy(&p9, &p1209, sizeof(class pitcher));
			memcpy(&p10, &p1210, sizeof(class pitcher)); memcpy(&p11, &p1211, sizeof(class pitcher));

			h9.change_dom(1);
		}
		else if (*number == 3) // '03�Ｚ
		{

			memcpy(&h1, &h1301, sizeof(class hitter)); memcpy(&h2, &h1302, sizeof(class hitter)); memcpy(&h3, &h1303, sizeof(class hitter));
			memcpy(&h4, &h1304, sizeof(class hitter)); memcpy(&h5, &h1305, sizeof(class hitter)); memcpy(&h6, &h1306, sizeof(class hitter));
			memcpy(&h7, &h1307, sizeof(class hitter)); memcpy(&h8, &h1308, sizeof(class hitter)); memcpy(&h9, &h1309, sizeof(class hitter));
			memcpy(&h10, &h1310, sizeof(class hitter)); memcpy(&h11, &h1311, sizeof(class hitter)); memcpy(&h12, &h1312, sizeof(class hitter));
			memcpy(&h13, &h1313, sizeof(class hitter)); memcpy(&h14, &h1314, sizeof(class hitter)); memcpy(&h15, &h1315, sizeof(class hitter));
			memcpy(&h16, &h1316, sizeof(class hitter));

			memcpy(&p1, &p1301, sizeof(class pitcher)); memcpy(&p2, &p1302, sizeof(class pitcher)); memcpy(&p3, &p1303, sizeof(class pitcher));
			memcpy(&p4, &p1304, sizeof(class pitcher)); memcpy(&p5, &p1305, sizeof(class pitcher)); memcpy(&p6, &p1306, sizeof(class pitcher));
			memcpy(&p7, &p1307, sizeof(class pitcher)); memcpy(&p8, &p1308, sizeof(class pitcher)); memcpy(&p9, &p1309, sizeof(class pitcher));
			memcpy(&p10, &p1310, sizeof(class pitcher)); memcpy(&p11, &p1311, sizeof(class pitcher));

			h4.change_dom(1);
		}
		else if (*number == 4) // '05�Ｚ
		{

			memcpy(&h1, &h1401, sizeof(class hitter)); memcpy(&h2, &h1402, sizeof(class hitter)); memcpy(&h3, &h1403, sizeof(class hitter));
			memcpy(&h4, &h1404, sizeof(class hitter)); memcpy(&h5, &h1405, sizeof(class hitter)); memcpy(&h6, &h1406, sizeof(class hitter));
			memcpy(&h7, &h1407, sizeof(class hitter)); memcpy(&h8, &h1408, sizeof(class hitter)); memcpy(&h9, &h1409, sizeof(class hitter));
			memcpy(&h10, &h1410, sizeof(class hitter)); memcpy(&h11, &h1411, sizeof(class hitter)); memcpy(&h12, &h1412, sizeof(class hitter));
			memcpy(&h13, &h1413, sizeof(class hitter)); memcpy(&h14, &h1414, sizeof(class hitter)); memcpy(&h15, &h1415, sizeof(class hitter));
			memcpy(&h16, &h1416, sizeof(class hitter));

			memcpy(&p1, &p1401, sizeof(class pitcher)); memcpy(&p2, &p1402, sizeof(class pitcher)); memcpy(&p3, &p1403, sizeof(class pitcher));
			memcpy(&p4, &p1404, sizeof(class pitcher)); memcpy(&p5, &p1405, sizeof(class pitcher)); memcpy(&p6, &p1406, sizeof(class pitcher));
			memcpy(&p7, &p1407, sizeof(class pitcher)); memcpy(&p8, &p1408, sizeof(class pitcher)); memcpy(&p9, &p1409, sizeof(class pitcher));
			memcpy(&p10, &p1410, sizeof(class pitcher)); memcpy(&p11, &p1411, sizeof(class pitcher));

			h7.change_dom(1);
		}
		else if (*number == 5) // '15�Ｚ
		{

			memcpy(&h1, &h1501, sizeof(class hitter)); memcpy(&h2, &h1502, sizeof(class hitter)); memcpy(&h3, &h1503, sizeof(class hitter));
			memcpy(&h4, &h1504, sizeof(class hitter)); memcpy(&h5, &h1505, sizeof(class hitter)); memcpy(&h6, &h1506, sizeof(class hitter));
			memcpy(&h7, &h1507, sizeof(class hitter)); memcpy(&h8, &h1508, sizeof(class hitter)); memcpy(&h9, &h1509, sizeof(class hitter));
			memcpy(&h10, &h1510, sizeof(class hitter)); memcpy(&h11, &h1511, sizeof(class hitter)); memcpy(&h12, &h1512, sizeof(class hitter));
			memcpy(&h13, &h1513, sizeof(class hitter)); memcpy(&h14, &h1514, sizeof(class hitter)); memcpy(&h15, &h1515, sizeof(class hitter));
			memcpy(&h16, &h1516, sizeof(class hitter));

			memcpy(&p1, &p1501, sizeof(class pitcher)); memcpy(&p2, &p1502, sizeof(class pitcher)); memcpy(&p3, &p1503, sizeof(class pitcher));
			memcpy(&p4, &p1504, sizeof(class pitcher)); memcpy(&p5, &p1505, sizeof(class pitcher)); memcpy(&p6, &p1506, sizeof(class pitcher));
			memcpy(&p7, &p1507, sizeof(class pitcher)); memcpy(&p8, &p1508, sizeof(class pitcher)); memcpy(&p9, &p1509, sizeof(class pitcher));
			memcpy(&p10, &p1510, sizeof(class pitcher)); memcpy(&p11, &p1511, sizeof(class pitcher));

			h7.change_dom(1);
		}
		else if (*number == 6) // '21�Ｚ
		{

			memcpy(&h1, &h1701, sizeof(class hitter)); memcpy(&h2, &h1702, sizeof(class hitter)); memcpy(&h3, &h1703, sizeof(class hitter));
			memcpy(&h4, &h1704, sizeof(class hitter)); memcpy(&h5, &h1705, sizeof(class hitter)); memcpy(&h6, &h1706, sizeof(class hitter));
			memcpy(&h7, &h1707, sizeof(class hitter)); memcpy(&h8, &h1708, sizeof(class hitter)); memcpy(&h9, &h1709, sizeof(class hitter));
			memcpy(&h10, &h1710, sizeof(class hitter)); memcpy(&h11, &h1711, sizeof(class hitter)); memcpy(&h12, &h1712, sizeof(class hitter));
			memcpy(&h13, &h1713, sizeof(class hitter)); memcpy(&h14, &h1714, sizeof(class hitter)); memcpy(&h15, &h1715, sizeof(class hitter));
			memcpy(&h16, &h1716, sizeof(class hitter));

			memcpy(&p1, &p1701, sizeof(class pitcher)); memcpy(&p2, &p1702, sizeof(class pitcher)); memcpy(&p3, &p1703, sizeof(class pitcher));
			memcpy(&p4, &p1704, sizeof(class pitcher)); memcpy(&p5, &p1705, sizeof(class pitcher)); memcpy(&p6, &p1706, sizeof(class pitcher));
			memcpy(&p7, &p1707, sizeof(class pitcher)); memcpy(&p8, &p1708, sizeof(class pitcher)); memcpy(&p9, &p1709, sizeof(class pitcher));
			memcpy(&p10, &p1710, sizeof(class pitcher)); memcpy(&p11, &p1711, sizeof(class pitcher));

			h3.change_dom(1);
		}
	}
}

void mode(int* sound, int* game_speed, bool* use_condition, bool* music_check, int* my_team, int* team_color) // ��� ����, ������ � ��������
{
	int menu;
	int dif = 3;
	int mod[3] = { 0,0,0 };
	int key = 0;
	int condition = 0;
	static int before_condition = 2;
	int before_sound = 0;
	int row = 15, col = 12;

	for (int i = 8; i < 50; i++)
	{
		cur(15, i);
		cout << "                         ";
	}

	col = 12;

	cur(row, col);

	cout << " [ ���� �޴� ] "; col += 3; cur(row, col);
	cout << " [ 1 ] ���� ���"; col += 3; cur(row, col);
	cout << " [ 2 ] Ʈ���̵� ���̵� "; col += 3; cur(row, col);
	cout << " [ 3 ] ���� ���� "; col += 3; cur(row, col);
	cout << " [ 4 ] ���Ӽӵ� ���� "; col += 3; cur(row, col);
	cout << " [ 5 ] ����� ���� "; col += 3; cur(row, col);
	cout << " [ 6 ] ���÷� ���� "; col += 3; cur(row, col);
	cout << " [ 7 ] ��� ";
	sel(&menu, 46, 15, 3, 7);

	for (int i = 8; i < 55; i++)
	{
		cur(15, i);
		cout << "                         ";
	}

	col = 12;

	cur(row, col);

	switch (menu)
	{
	case 1:
		cout << " [ ���Ӹ�� ���� ] "; col += 3; cur(row, col);
		cout << " [ 1 ] �ڵ� ( ���� �ڵ� ��ŵ )"; col += 3; cur(row, col);
		cout << " [ 2 ] ���� ( ���� ���� )";
		sel(&sim, 48, 15, 3, 2);
		break;

	case 2:
		cout << " [ Ʈ���̵� ���̵� ] "; col += 3; cur(row, col);
		cout << " [ 1 ] ��� ���� "; col += 3; cur(row, col);
		cout << " [ 2 ] ���� "; col += 3; cur(row, col);
		cout << " [ 3 ] �ణ ���� "; col += 3; cur(row, col);
		cout << " [ 4 ] ���� "; col += 3; cur(row, col);
		cout << " [ 5 ] �ణ ����� "; col += 3; cur(row, col);
		cout << " [ 6 ] ��ٷο� "; col += 3; cur(row, col);
		cout << " [ 7 ] ��� �Ұ��� "; col += 3; cur(row, col);
		cout << " [ 8 ] ��� ";
		sel(&dif, 40, 15, 3, 8);

		switch (dif) {
		case 8: break;
		case 7: tra = 0; break;
		case 6: tra = 0.96; break;
		case 5: tra = 0.98; break;
		case 4: tra = 1.00; break;
		case 3: tra = 1.02; break;
		case 2: tra = 1.04; break;
		case 1: tra = 100.0; break;
		}
		break;

	case 3:
		cout << " [ ������ ��� ] "; col += 3; cur(row, col);
		cout << " [ 1 ] ��� ���"; col += 3; cur(row, col);
		cout << " [ 2 ] ����� �Ҹ��� ��� (������ ����)"; col += 3; cur(row, col);
		cout << " [ 3 ] ���Ұ�";
		sel(sound, 58, 15, 3, 3);

		if (before_sound == 3 && (*sound == 1 || *sound == 2))
			*music_check = false;

		before_sound = *sound;
		break;

	case 4:
		cout << " [ ���� ����ӵ� ] "; col += 3; cur(row, col);
		cout << " [ 1 ] �ſ� ���� "; col += 3; cur(row, col);
		cout << " [ 2 ] ���� "; col += 3; cur(row, col);
		cout << " [ 3 ] ǥ�� "; col += 3; cur(row, col);
		cout << " [ 4 ] ���� "; col += 3; cur(row, col);
		cout << " [ 5 ] �ſ� ���� ";
		sel(game_speed, 40, 15, 3, 5);
		break;

	case 5:
		cout << " [ ����� ��뿩�� ] "; col += 3; cur(row, col);
		cout << " [ 1 ] ��� "; col += 3; cur(row, col);
		cout << " [ 2 ] �̻�� "; col += 3; cur(row, col);
		sel(&condition, 40, 15, 3, 2);

		if (condition == 1 && before_condition != 1)
		{
			*use_condition = true;

			h1.reset_condition(); h2.reset_condition(); h3.reset_condition(); h4.reset_condition(); h5.reset_condition();
			h6.reset_condition(); h7.reset_condition(); h8.reset_condition(); h9.reset_condition(); h10.reset_condition();
			h11.reset_condition(); h12.reset_condition(); h13.reset_condition(); h14.reset_condition(); h15.reset_condition(); h16.reset_condition();

			h31.reset_condition(); h32.reset_condition(); h33.reset_condition(); h34.reset_condition(); h35.reset_condition();
			h36.reset_condition(); h37.reset_condition(); h38.reset_condition(); h39.reset_condition(); h40.reset_condition();
			h41.reset_condition(); h42.reset_condition(); h43.reset_condition(); h44.reset_condition(); h45.reset_condition(); h46.reset_condition();

			h61.reset_condition(); h62.reset_condition(); h63.reset_condition(); h64.reset_condition(); h65.reset_condition();
			h66.reset_condition(); h67.reset_condition(); h68.reset_condition(); h69.reset_condition(); h70.reset_condition();
			h71.reset_condition(); h72.reset_condition(); h73.reset_condition(); h74.reset_condition(); h75.reset_condition(); h76.reset_condition();

			h91.reset_condition(); h92.reset_condition(); h93.reset_condition(); h94.reset_condition(); h95.reset_condition();
			h96.reset_condition(); h97.reset_condition(); h98.reset_condition(); h99.reset_condition(); h100.reset_condition();
			h101.reset_condition(); h102.reset_condition(); h103.reset_condition(); h104.reset_condition(); h105.reset_condition(); h106.reset_condition();

			h131.reset_condition(); h132.reset_condition(); h133.reset_condition(); h134.reset_condition(); h135.reset_condition();
			h136.reset_condition(); h137.reset_condition(); h138.reset_condition(); h139.reset_condition(); h140.reset_condition();
			h141.reset_condition(); h142.reset_condition(); h143.reset_condition(); h144.reset_condition(); h145.reset_condition(); h146.reset_condition();

			h161.reset_condition(); h162.reset_condition(); h163.reset_condition(); h164.reset_condition(); h165.reset_condition();
			h166.reset_condition(); h167.reset_condition(); h168.reset_condition(); h169.reset_condition(); h170.reset_condition();
			h171.reset_condition(); h172.reset_condition(); h173.reset_condition(); h174.reset_condition(); h175.reset_condition(); h176.reset_condition();

			h8001.reset_condition(); h8002.reset_condition(); h8003.reset_condition(); h8004.reset_condition(); h8005.reset_condition();
			h8006.reset_condition(); h8007.reset_condition(); h8008.reset_condition(); h8009.reset_condition(); h8010.reset_condition();
			h8011.reset_condition(); h8012.reset_condition(); h8013.reset_condition(); h8014.reset_condition(); h8015.reset_condition(); h8016.reset_condition();

			h9001.reset_condition(); h9002.reset_condition(); h9003.reset_condition(); h9004.reset_condition(); h9005.reset_condition();
			h9006.reset_condition(); h9007.reset_condition(); h9008.reset_condition(); h9009.reset_condition(); h9010.reset_condition();
			h9011.reset_condition(); h9012.reset_condition(); h9013.reset_condition(); h9014.reset_condition(); h9015.reset_condition(); h9016.reset_condition();
		}


		else
		{
			*use_condition = false;

			h1.no_condition(); h2.no_condition(); h3.no_condition(); h4.no_condition(); h5.no_condition();
			h6.no_condition(); h7.no_condition(); h8.no_condition(); h9.no_condition(); h10.no_condition();
			h11.no_condition(); h12.no_condition(); h13.no_condition(); h14.no_condition(); h15.no_condition(); h16.no_condition();

			h31.no_condition(); h32.no_condition(); h33.no_condition(); h34.no_condition(); h35.no_condition();
			h36.no_condition(); h37.no_condition(); h38.no_condition(); h39.no_condition(); h40.no_condition();
			h41.no_condition(); h42.no_condition(); h43.no_condition(); h44.no_condition(); h45.no_condition(); h46.no_condition();

			h61.no_condition(); h62.no_condition(); h63.no_condition(); h64.no_condition(); h65.no_condition();
			h66.no_condition(); h67.no_condition(); h68.no_condition(); h69.no_condition(); h70.no_condition();
			h71.no_condition(); h72.no_condition(); h73.no_condition(); h74.no_condition(); h75.no_condition(); h76.no_condition();

			h91.no_condition(); h92.no_condition(); h93.no_condition(); h94.no_condition(); h95.no_condition();
			h96.no_condition(); h97.no_condition(); h98.no_condition(); h99.no_condition(); h100.no_condition();
			h101.no_condition(); h102.no_condition(); h103.no_condition(); h104.no_condition(); h105.no_condition(); h106.no_condition();

			h131.no_condition(); h132.no_condition(); h133.no_condition(); h134.no_condition(); h135.no_condition();
			h136.no_condition(); h137.no_condition(); h138.no_condition(); h139.no_condition(); h140.no_condition();
			h141.no_condition(); h142.no_condition(); h143.no_condition(); h144.no_condition(); h145.no_condition(); h146.no_condition();

			h161.no_condition(); h162.no_condition(); h163.no_condition(); h164.no_condition(); h165.no_condition();
			h166.no_condition(); h167.no_condition(); h168.no_condition(); h169.no_condition(); h170.no_condition();
			h171.no_condition(); h172.no_condition(); h173.no_condition(); h174.no_condition(); h175.no_condition(); h176.no_condition();

			h8001.no_condition(); h8002.no_condition(); h8003.no_condition(); h8004.no_condition(); h8005.no_condition();
			h8006.no_condition(); h8007.no_condition(); h8008.no_condition(); h8009.no_condition(); h8010.no_condition();
			h8011.no_condition(); h8012.no_condition(); h8013.no_condition(); h8014.no_condition(); h8015.no_condition(); h8016.no_condition();

			h9001.no_condition(); h9002.no_condition(); h9003.no_condition(); h9004.no_condition(); h9005.no_condition();
			h9006.no_condition(); h9007.no_condition(); h9008.no_condition(); h9009.no_condition(); h9010.no_condition();
			h9011.no_condition(); h9012.no_condition(); h9013.no_condition(); h9014.no_condition(); h9015.no_condition(); h9016.no_condition();
		}

		break;

	case 6:
	{

		switch (*my_team)
		{
		case 0: // �Ｚ
		{
			cout << " [ ������ �� ] "; col += 3; cur(row, col);
			cout << " [ 1 ] '85 �Ｚ "; col += 3; cur(row, col);
			cout << " [ 2 ] '97 �Ｚ "; col += 3; cur(row, col);
			cout << " [ 3 ] '03 �Ｚ "; col += 3; cur(row, col);
			cout << " [ 4 ] '05 �Ｚ "; col += 3; cur(row, col);
			cout << " [ 5 ] '15 �Ｚ "; col += 3; cur(row, col);
			cout << " [ 6 ] '21 �Ｚ "; col += 3; cur(row, col);
			cout << " [ 7 ]  ��� ";

			sel(team_color, 40, 15, 3, 7);

			change_teamcolor(*my_team, team_color);



			break;
		}

		case 1: // �Ե�
		{
			cout << " [ ������ �� ] "; col += 3; cur(row, col);
			cout << " [ 1 ] '84 �Ե� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 2 ] '92 �Ե� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 3 ] '99 �Ե� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 4 ] '08 �Ե� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 5 ] '10 �Ե� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 6 ] '17 �Ե� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 7 ] '21 �Ե� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 8 ]  ��� ";

			sel(team_color, 40, 15, 3, 8);

			change_teamcolor(*my_team, team_color);



			break;
		}

		case 2: // NC
		{
			cout << " [ ������ �� ] "; col += 3; cur(row, col);
			cout << " [ 1 ] '15 NC (�̿�) "; col += 3; cur(row, col);
			cout << " [ 2 ] '20 NC (�̿�) "; col += 3; cur(row, col);
			cout << " [ 3 ] '21 NC (�̿�) "; col += 3; cur(row, col);
			cout << " [ 4 ]  ��� ";

			sel(team_color, 40, 15, 3, 4);

			change_teamcolor(*my_team, team_color);



			break;
		}

		case 3: // �λ�
		{
			cout << " [ ������ �� ] "; col += 3; cur(row, col);
			cout << " [ 1 ] '82 OB (�̿�) "; col += 3; cur(row, col);
			cout << " [ 2 ] '95 OB (�̿�) "; col += 3; cur(row, col);
			cout << " [ 3 ] '01 �λ� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 4 ] '08 �λ� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 5 ] '16 �λ� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 6 ] '19 �λ� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 7 ] '21 �λ� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 8 ]  ��� ";

			sel(team_color, 40, 15, 3, 8);

			change_teamcolor(*my_team, team_color);



			break;
		}

		case 4: // LG
		{
			cout << " [ ������ �� ] "; col += 3; cur(row, col);
			cout << " [ 1 ] '90 LG (�̿�) "; col += 3; cur(row, col);
			cout << " [ 2 ] '94 LG (�̿�) "; col += 3; cur(row, col);
			cout << " [ 3 ] '02 LG (�̿�) "; col += 3; cur(row, col);
			cout << " [ 4 ] '13 LG (�̿�) "; col += 3; cur(row, col);
			cout << " [ 5 ] '21 LG (�̿�) "; col += 3; cur(row, col);
			cout << " [ 6 ] '22 LG (�̿�) "; col += 3; cur(row, col);
			cout << " [ 7 ]  ��� ";

			sel(team_color, 40, 15, 3, 7);

			change_teamcolor(*my_team, team_color);



			break;
		}

		case 5: // SSG
		{
			cout << " [ ������ �� ] "; col += 3; cur(row, col);
			cout << " [ 1 ] '97 �ֹ�� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 2 ] '08 SK (�̿�) "; col += 3; cur(row, col);
			cout << " [ 3 ] '10 SK (�̿�) "; col += 3; cur(row, col);
			cout << " [ 4 ] '18 SK (�̿�) "; col += 3; cur(row, col);
			cout << " [ 5 ] '21 SSG (�̿�) "; col += 3; cur(row, col);
			cout << " [ 6 ] '22 SSG (�̿�) "; col += 3; cur(row, col);
			cout << " [ 7 ]  ��� ";

			sel(team_color, 40, 15, 3, 7);

			change_teamcolor(*my_team, team_color);



			break;
		}

		case 6: // ��Ÿ (���,���� ��)
		{
			cout << " [ ������ �� ] "; col += 3; cur(row, col);
			cout << " [ 1 ] '94 ����� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 2 ] '99 ��ȭ (�̿�) "; col += 3; cur(row, col);
			cout << " [ 3 ] '00 ���� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 4 ] '04 ���� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 5 ] '08 ���� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 6 ] '15 ���� (�̿�) "; col += 3; cur(row, col);
			cout << " [ 7 ]  ��� ";

			sel(team_color, 40, 15, 3, 7);

			change_teamcolor(*my_team, team_color);



			break;
		}

		break;
		}

	}
	break;

	}


}

void draft_h(hitter& a, int sim)
{
	int asdf = 0;
	int pow = 10000000;
	for (int i = 0; i < sim; i++)
	{
		a.battle(p999, &asdf, 0, &pow, 0, 0, 3);
	}

}

void draft_p(pitcher& a, int sim)  // ����� �� ����
{
	int asdf = 0;
	int pow = 10000000;
	int before_los = 0, after_los = 0;
	for (int i = 0; i < sim; i++)
	{
		h999.battle(a, &asdf, 0, &pow, 0, 0, 3);
		if (asdf % 3 == 0)
		{

			if (asdf % 18 == 0)
			{

				after_los = a.pitcher_los();

				before_los = after_los - before_los;

				if (asdf % 18 == 0 && before_los < 2) // �¸� ���� : 6�̴� 3���� ����
					a.pitcher_result(true);


				else if (asdf % 18 == 0 && before_los > 3) // �й� ���� : 6�̴� 5���� �̻�
					a.pitcher_result(false);

				before_los = after_los;
			}



			Base.ch();
		}
	}

}

void recruit(int my_team, bool use_condition)
{
	int choice = 0;
	int row = 20, col = 15;

	for (int i = 8; i < 50; i++)
	{
		cur(15, i);
		cout << "                         ";
	}



	cur(20, 15);
	cout << " [ ���� ���� ]"; col += 3; cur(row, col);
	cout << " [ 1 ] �巡��Ʈ "; col += 3; cur(row, col);
	cout << " [ 2 ] ���� �̱� "; col += 3; cur(row, col);
	cout << " [ 3 ] ���";

	sel(&choice, 40, 18, 3, 3);

	if (choice == 1)
		draft(my_team, use_condition);
	else if (choice == 2)
		draw_card(my_team, use_condition);
}














void print_random(int row, int col, int count, int sleeptime)
{

	for (int i = 0; i < count; i++)
	{
		cur(row, col);
		int random = rand() % 46 + 0;
		switch (random)
		{
		case 0: cout << "�̽¿�"; break;
		case 1: cout << "������"; break;
		case 2: cout << "�̸���"; break;
		case 3: cout << "�迵��"; break;
		case 4: cout << "������"; break;
		case 5: cout << "�����"; break;
		case 6: cout << "������"; break;
		case 7: cout << "������"; break;
		case 8: cout << "������"; break;
		case 9: cout << "���ؿ�"; break;
		case 10: cout << "�̿��"; break;
		case 11: cout << "������"; break;
		case 12: cout << "ȫ����"; break;
		case 13: cout << "�̺���"; break;
		case 14: cout << "�ڿ���"; break;
		case 15: cout << "�赿��"; break;
		case 16: cout << "���±�"; break;
		case 17: cout << "����ȫ"; break;
		case 18: cout << "���濱"; break;
		case 19: cout << "�����"; break;
		case 20: cout << "�ڰ��"; break;
		case 21: cout << "������"; break;
		case 22: cout << "ȫ����"; break;
		case 23: cout << "�̼�ö"; break;
		case 24: cout << "������"; break;
		case 25: cout << "������"; break;
		case 26: cout << "������"; break;
		case 27: cout << "������"; break;
		case 28: cout << "����õ"; break;
		case 29: cout << "��  ��"; break;
		case 30: cout << "�̹�ȣ"; break;
		case 31: cout << "�쵿��"; break;
		case 32: cout << "��ȿ��"; break;
		case 33: cout << "����"; break;
		case 34: cout << "�����"; break;
		case 35: cout << "�Ѵ�ȭ"; break;
		case 36: cout << "������"; break;
		case 37: cout << "������"; break;
		case 38: cout << "�����"; break;
		case 39: cout << "������"; break;
		case 40: cout << "������"; break;
		case 41: cout << "���Ѽ�"; break;
		case 42: cout << "������"; break;
		case 43: cout << "ȣ  ��"; break;
		case 44: cout << "�̾��"; break;
		case 45: cout << "����ȣ"; break;
		case 46: cout << "������"; break;

		}

		Sleep(sleeptime);
	}

	cur(row, col); cout << "       ";
	cur(row, col);
	for (int i = 0; i < 6; i++)
	{
		cout << "?";
		Sleep(150);
	}

}

void draw_card(int my_team, bool use_condition)
{
	int choice = 0;
	int row = 19, col = 15;
	int pick = 0;
	int key = 0;

	for (int i = 8; i < 50; i++)
	{
		cur(15, i);
		cout << "                         ";
	}



	cur(20, 15);
	cout << " [ ���� �̱� ]"; col += 3; cur(row + 1, col);
	cout << " [ 1 ] Ÿ�� "; col += 3; cur(row + 1, col);
	cout << " [ 2 ] ���� "; col += 3; cur(row + 1, col);
	cout << " [ 3 ] ���";

	sel(&choice, 40, 18, 3, 3);

	if (choice == 1)
	{
		for (int i = 8; i < 50; i++)
		{
			cur(15, i);
			cout << "                         ";
		}

		pick = rand() % 47 + 0;






		col = 10;

		cur(row + 1, col); cout << "[ �ƹ� Ű�� ������ ���µ˴ϴ�! ]"; col += 4;


		key = getch();

		cur(row + 1, col);
		cout << "[                              ]";
		//Sleep(2000); cur(row + 14, col);

		print_random(row + 14, col, 30, 46); Sleep(150);

		for (int i = 0; i < 20; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cur(row + 1, col + i); cout << "|"; cur(row + 32, col + i); cout << "|";
			Sleep(50);
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		col += 3; cur(row + 14, col);

		switch (pick)
		{
		case 0:		h2000.draw_hitter(row, col, use_condition); memcpy(&hh, &h2000, sizeof(class hitter)); break;
		case 1:		h2001.draw_hitter(row, col, use_condition); memcpy(&hh, &h2001, sizeof(class hitter)); break;
		case 2:		h2002.draw_hitter(row, col, use_condition); memcpy(&hh, &h2002, sizeof(class hitter)); break;
		case 3:		h2003.draw_hitter(row, col, use_condition); memcpy(&hh, &h2003, sizeof(class hitter)); break;
		case 4:		h2004.draw_hitter(row, col, use_condition); memcpy(&hh, &h2004, sizeof(class hitter)); break;
		case 5:		h2005.draw_hitter(row, col, use_condition); memcpy(&hh, &h2005, sizeof(class hitter)); break;
		case 6:		h2006.draw_hitter(row, col, use_condition); memcpy(&hh, &h2006, sizeof(class hitter)); break;
		case 7:		h2007.draw_hitter(row, col, use_condition); memcpy(&hh, &h2007, sizeof(class hitter)); break;
		case 8:		h2008.draw_hitter(row, col, use_condition); memcpy(&hh, &h2008, sizeof(class hitter)); break;
		case 9:		h2009.draw_hitter(row, col, use_condition); memcpy(&hh, &h2009, sizeof(class hitter)); break;
		case 10:		h2010.draw_hitter(row, col, use_condition); memcpy(&hh, &h2010, sizeof(class hitter)); break;
		case 11:		h2011.draw_hitter(row, col, use_condition); memcpy(&hh, &h2011, sizeof(class hitter)); break;
		case 12:		h2012.draw_hitter(row, col, use_condition); memcpy(&hh, &h2012, sizeof(class hitter)); break;
		case 13:		h2013.draw_hitter(row, col, use_condition); memcpy(&hh, &h2013, sizeof(class hitter)); break;
		case 14:		h2014.draw_hitter(row, col, use_condition); memcpy(&hh, &h2014, sizeof(class hitter)); break;
		case 15:		h2015.draw_hitter(row, col, use_condition); memcpy(&hh, &h2015, sizeof(class hitter)); break;
		case 16:		h2016.draw_hitter(row, col, use_condition); memcpy(&hh, &h2016, sizeof(class hitter)); break;
		case 17:		h2017.draw_hitter(row, col, use_condition); memcpy(&hh, &h2017, sizeof(class hitter)); break;
		case 18:		h2018.draw_hitter(row, col, use_condition); memcpy(&hh, &h2018, sizeof(class hitter)); break;
		case 19:		h2019.draw_hitter(row, col, use_condition); memcpy(&hh, &h2019, sizeof(class hitter)); break;
		case 20:		h2020.draw_hitter(row, col, use_condition); memcpy(&hh, &h2020, sizeof(class hitter)); break;
		case 21:		h2021.draw_hitter(row, col, use_condition); memcpy(&hh, &h2021, sizeof(class hitter)); break;
		case 22:		h2022.draw_hitter(row, col, use_condition); memcpy(&hh, &h2022, sizeof(class hitter)); break;
		case 23:		h2023.draw_hitter(row, col, use_condition); memcpy(&hh, &h2023, sizeof(class hitter)); break;
		case 24:		h2024.draw_hitter(row, col, use_condition); memcpy(&hh, &h2024, sizeof(class hitter)); break;
		case 25:		h2025.draw_hitter(row, col, use_condition); memcpy(&hh, &h2025, sizeof(class hitter)); break;
		case 26:		h2026.draw_hitter(row, col, use_condition); memcpy(&hh, &h2026, sizeof(class hitter)); break;
		case 27:		h2027.draw_hitter(row, col, use_condition); memcpy(&hh, &h2027, sizeof(class hitter)); break;
		case 28:		h2028.draw_hitter(row, col, use_condition); memcpy(&hh, &h2028, sizeof(class hitter)); break;
		case 29:		h2029.draw_hitter(row, col, use_condition); memcpy(&hh, &h2029, sizeof(class hitter)); break;
		case 30:		h2030.draw_hitter(row, col, use_condition); memcpy(&hh, &h2030, sizeof(class hitter)); break;
		case 31:		h2031.draw_hitter(row, col, use_condition); memcpy(&hh, &h2031, sizeof(class hitter)); break;
		case 32:		h2032.draw_hitter(row, col, use_condition); memcpy(&hh, &h2032, sizeof(class hitter)); break;
		case 33:		h2033.draw_hitter(row, col, use_condition); memcpy(&hh, &h2033, sizeof(class hitter)); break;
		case 34:		h2034.draw_hitter(row, col, use_condition); memcpy(&hh, &h2034, sizeof(class hitter)); break;
		case 35:		h2035.draw_hitter(row, col, use_condition); memcpy(&hh, &h2035, sizeof(class hitter)); break;
		case 36:		h2036.draw_hitter(row, col, use_condition); memcpy(&hh, &h2036, sizeof(class hitter)); break;
		case 37:		h2037.draw_hitter(row, col, use_condition); memcpy(&hh, &h2037, sizeof(class hitter)); break;
		case 38:		h2038.draw_hitter(row, col, use_condition); memcpy(&hh, &h2038, sizeof(class hitter)); break;
		case 39:		h2039.draw_hitter(row, col, use_condition); memcpy(&hh, &h2039, sizeof(class hitter)); break;
		case 40:		h2040.draw_hitter(row, col, use_condition); memcpy(&hh, &h2040, sizeof(class hitter)); break;
		case 41:		h2041.draw_hitter(row, col, use_condition); memcpy(&hh, &h2041, sizeof(class hitter)); break;
		case 42:		h2042.draw_hitter(row, col, use_condition); memcpy(&hh, &h2042, sizeof(class hitter)); break;
		case 43:		h2043.draw_hitter(row, col, use_condition); memcpy(&hh, &h2043, sizeof(class hitter)); break;
		case 44:		h2044.draw_hitter(row, col, use_condition); memcpy(&hh, &h2044, sizeof(class hitter)); break;
		case 45:		h2045.draw_hitter(row, col, use_condition); memcpy(&hh, &h2045, sizeof(class hitter)); break;
		case 46:		h2046.draw_hitter(row, col, use_condition); memcpy(&hh, &h2046, sizeof(class hitter)); break;

		}

		change(-4, my_team, false);
	}

	else if (choice == 2)
	{

	}
}


void draft(int my_team, bool use_condition)
{
	int sim = 0;
	int key = 0;
	int choice = 0;
	static int hitter_visit = false;
	static int pitcher_visit = false;

	int row = 20, col = 15;

	for (int i = 8; i < 50; i++)
	{
		cur(15, i);
		cout << "                         ";
	}



	cur(20, 15);
	cout << "������ ������ �����Ͻʽÿ�."; col += 3; cur(row, col);
	cout << " [ 1 ] Ÿ��"; col += 3; cur(row, col);
	cout << " [ 2 ] ����"; col += 3; cur(row, col);
	cout << " [ 3 ] ���";

	sel(&choice, 40, 18, 3, 3);

	system("cls");

	if (choice == 1)
	{
		if (hitter_visit == false)
		{
			h1000.change_ov(); h1005.change_ov();
			h1001.change_ov(); h1006.change_ov();
			h1002.change_ov(); h1007.change_ov();
			h1003.change_ov(); h1008.change_ov();
			h1004.change_ov();

			sim = rand() % 180 + 131;

			h1000.reset_condition(); h1005.reset_condition();
			h1001.reset_condition(); h1006.reset_condition();
			h1002.reset_condition(); h1007.reset_condition();
			h1003.reset_condition(); h1008.reset_condition();
			h1004.reset_condition();

			memcpy(&hhh, &h1000, sizeof(class hitter));
			draft_h(hhh, sim); sim = rand() % 180 + 131;
			memcpy(&h1000, &hhh, sizeof(class hitter));

			memcpy(&hhh, &h1001, sizeof(class hitter));
			draft_h(hhh, sim); sim = rand() % 180 + 131;
			memcpy(&h1001, &hhh, sizeof(class hitter));

			memcpy(&hhh, &h1002, sizeof(class hitter));
			draft_h(hhh, sim); sim = rand() % 180 + 131;
			memcpy(&h1002, &hhh, sizeof(class hitter));

			memcpy(&hhh, &h1003, sizeof(class hitter));
			draft_h(hhh, sim); sim = rand() % 180 + 131;
			memcpy(&h1003, &hhh, sizeof(class hitter));

			memcpy(&hhh, &h1004, sizeof(class hitter));
			draft_h(hhh, sim); sim = rand() % 180 + 131;
			memcpy(&h1004, &hhh, sizeof(class hitter));

			memcpy(&hhh, &h1005, sizeof(class hitter));
			draft_h(hhh, sim); sim = rand() % 180 + 131;
			memcpy(&h1005, &hhh, sizeof(class hitter));

			memcpy(&hhh, &h1006, sizeof(class hitter));
			draft_h(hhh, sim); sim = rand() % 180 + 131;
			memcpy(&h1006, &hhh, sizeof(class hitter));

			memcpy(&hhh, &h1007, sizeof(class hitter));
			draft_h(hhh, sim); sim = rand() % 180 + 131;
			memcpy(&h1007, &hhh, sizeof(class hitter));

			memcpy(&hhh, &h1008, sizeof(class hitter));
			draft_h(hhh, sim); sim = rand() % 180 + 131;
			memcpy(&h1008, &hhh, sizeof(class hitter));

			if (use_condition == false)
			{
				h1000.no_condition(); h1005.no_condition();
				h1001.no_condition(); h1006.no_condition();
				h1002.no_condition(); h1007.no_condition();
				h1003.no_condition(); h1008.no_condition();
				h1004.no_condition();
			}

			h1000.clear_schoolscore(); h1005.clear_schoolscore(); // ���߱� ���� �ʱ�ȭ (��Ÿ��)
			h1001.clear_schoolscore(); h1006.clear_schoolscore();
			h1002.clear_schoolscore(); h1007.clear_schoolscore();
			h1003.clear_schoolscore(); h1008.clear_schoolscore();
			h1004.clear_schoolscore();

			hitter_visit = true;
		}

		while (key != 27)

		{
			row = 15; col = 3;

			system("cls");

			cur(row, col); cout << "   [ ���߱� ���� ]  [ <1> ����  |  <Esc> ������ ]"; col += 3;
			cur(row, col); cout << "   [ �̸� ]  [ ������ ]  [ Ÿ �� ]  [ ����� ]  [ ��Ÿ�� ]  [ Ÿ�� ]  [ ��Ÿ ]  [ Ȩ�� ]  [ ���� ]  [ ���� ]  [ 2��Ÿ ]  [ 3��Ÿ ]"; col += 3;

			cur(row, col); h1000.print(0, 10); col += 3;
			cur(row, col); h1001.print(0, 10); col += 3;
			cur(row, col); h1002.print(0, 10); col += 3;
			cur(row, col); h1003.print(0, 10); col += 3;
			cur(row, col); h1004.print(0, 10); col += 3;
			cur(row, col); h1005.print(0, 10); col += 3;
			cur(row, col); h1006.print(0, 10); col += 3;
			cur(row, col); h1007.print(0, 10); col += 3;
			cur(row, col); h1008.print(0, 10);

			key = getch();

			if (key == 49)
				change(-1, my_team, false);
		}

	}

	else if (choice == 2)
	{
		if (pitcher_visit == false)
		{
			sim = rand() % 210 + 211;

			memcpy(&ppp, &p1000, sizeof(class pitcher));
			draft_p(ppp, sim); sim = rand() % 210 + 211;
			memcpy(&p1000, &ppp, sizeof(class pitcher));

			memcpy(&ppp, &p1001, sizeof(class pitcher));
			draft_p(ppp, sim); sim = rand() % 210 + 211;
			memcpy(&p1001, &ppp, sizeof(class pitcher));

			memcpy(&ppp, &p1002, sizeof(class pitcher));
			draft_p(ppp, sim); sim = rand() % 100 + 91;
			memcpy(&p1002, &ppp, sizeof(class pitcher));

			memcpy(&ppp, &p1003, sizeof(class pitcher));
			draft_p(ppp, sim); sim = rand() % 100 + 91;
			memcpy(&p1003, &ppp, sizeof(class pitcher));

			memcpy(&ppp, &p1004, sizeof(class pitcher));
			draft_p(ppp, sim); sim = rand() % 100 + 91;
			memcpy(&p1004, &ppp, sizeof(class pitcher));

			memcpy(&ppp, &p1005, sizeof(class pitcher));
			draft_p(ppp, sim); sim = rand() % 100 + 91;
			memcpy(&p1005, &ppp, sizeof(class pitcher));


			pitcher_visit = true;
		}


		while (key != 27)
		{

			row = 15; col = 3;

			system("cls");

			cur(row, col); cout << "   [ ���߱� ���� ]  [ <1> ����  |  <Esc> ������ ]  [  ���� �巡��Ʈ�� �̿ϼ��Դϴ�. ]"; col += 3;
			cur(row, col); cout << "    [ �̸� ]    [ ���� ]   [ �̴� ]   [ �����å�� ]   [ ���� ]    [ ���� ]   [ �� ]   [ �� ]   [ ��Ȩ�� ]    [ K/9 ]   [ BB/9 ]  [ WHIP ]  [ ���� ]"; col += 3;
			cur(row, col);

			p1000.printp(100); col += 3; cur(row, col);
			p1001.printp(100); col += 3; cur(row, col);
			p1002.printp(100); col += 3; cur(row, col);
			p1003.printp(100); col += 3; cur(row, col);
			p1004.printp(100); col += 3; cur(row, col);
			p1005.printp(100); col += 3; cur(row, col);


			key = getch();

			if (key == 49)
				change(-2, my_team, false);
		}

	}





}

void create(int my_team, bool use_condition)
{

	char name[10];
	int var = 0, choice = 0;

	int row = 20, col = 15;

	for (int i = 8; i < 50; i++)
	{
		cur(15, i);
		cout << "                         ";
	}



	cur(20, 15);
	cout << " ���� ������ ������ �����Ͻʽÿ�."; col += 3; cur(row, col);
	cout << " [ 1 ] Ÿ��"; col += 3; cur(row, col);
	cout << " [ 2 ] ����"; col += 3; cur(row, col);
	cout << " [ 3 ] ���";

	sel(&choice, 40, 18, 3, 3);

	for (int i = 8; i < 50; i++)
	{
		cur(15, i);
		cout << "                         ";
	}

	row = 20; col = 13; cur(row, col);

	switch (choice)
	{
	case 1:
		cout << "ĳ���� �̸��� �Է����ֽʽÿ�. (�ִ� 3����)"; col += 2; cur(row, col);
		cout << "( ����� �������� �ʽ��ϴ�. ) : ";
		cin >> name;
		h9999.change_name(name);
		col += 3; cur(row, col);

		cout << "[ ���� �Է� ] �Ŀ� : ";
		cin >> var;
		h9999.change_pow(var);
		col += 3; cur(row, col);

		cout << "[ ���� �Է� ] ���� : ";
		cin >> var;
		h9999.change_cont(var);
		col += 3; cur(row, col);

		cout << "[ ���� �Է� ] ��Ȯ�� : ";
		cin >> var;
		h9999.change_acc(var);
		col += 3; cur(row, col);

		cout << "[ ���� �Է� ] ���ǵ� : ";
		cin >> var;
		h9999.change_spd(var);
		col += 4; cur(row, col);

		cout << "[ ������ ���� ]"; col += 2; cur(row, col);
		cout << "[ ����    : 2 | 1���  : 3 | 2���  : 4 ]"; col += 2; cur(row, col);
		cout << "[ 3���   : 5 | ���ݼ� : 6 | ���ͼ� : 7 ]"; col += 2; cur(row, col);
		cout << "[ �߰߼�  : 8 | ���ͼ� : 9 ] : ";
		cin >> var;
		h9999.change_pos(var);
		col += 3; cur(row, col);

		h9999.reset_condition();

		if (use_condition == false)
		{
			h9999.no_condition();
		}

		if (var > 1 && var < 10)
			change(-2, my_team, false);
		break;

	case 2:
		row = 20; col = 13; cur(row, col);
		cout << "ĳ���� �̸��� �Է����ֽʽÿ�. (�ִ� 3����)"; col += 2; cur(row, col);
		cout << "( ����� �������� �ʽ��ϴ�. ) : ";
		cin >> name;
		p9999.change_name(name);
		col += 3; cur(row, col);

		cout << "[ ���� �Է� ] ���� : ";
		cin >> var;
		p9999.change_con(var);
		col += 3; cur(row, col);

		cout << "[ ���� �Է� ] ���� : ";
		cin >> var;
		p9999.change_stu(var);
		col += 3; cur(row, col);

		cout << "[ ���� �Է� ] ���� : ";
		cin >> var;
		p9999.change_spd(var);
		col += 3; cur(row, col);

		cout << "[ ���� �Է� ] ü�� : ";
		cin >> var;
		p9999.change_hp(var);
		col += 3; cur(row, col);


		cout << "[ ������ �Է� ] (���� : 1, �߰� : 2) : ";
		cin >> var;
		col += 3; cur(row, col);

		if (var == 2) p9999.change_hp(1500);

		if (var == 1 || var == 2)
			change(-3, my_team, false);
		break;

	case 3:
		break;

	}


}



void gamestart()
{

}

void show_battleteam(int home, int away, int total_gam)
{
	switch (home) {
	case 0:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << " [ �Ｚ ���̿��� ]"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); cout << "  [ ";
		switch (total_gam % 5)
		{
		case 0: p1.print_name(); break;
		case 1: p2.print_name(); break;
		case 2: p3.print_name(); break;
		case 3: p4.print_name(); break;
		case 4: p5.print_name(); break;
		}
		cout << " ]";
		break;
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << " [ �Ե� ���̾��� ]"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); cout << "  [ ";
		switch (total_gam % 5)
		{
		case 0: p31.print_name(); break;
		case 1: p32.print_name(); break;
		case 2: p33.print_name(); break;
		case 3: p34.print_name(); break;
		case 4: p35.print_name(); break;
		}
		cout << " ]";
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << " [  NC ���̳뽺  ]"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); cout << "  [ ";
		switch (total_gam % 5)
		{
		case 0: p61.print_name(); break;
		case 1: p62.print_name(); break;
		case 2: p63.print_name(); break;
		case 3: p64.print_name(); break;
		case 4: p65.print_name(); break;
		}
		cout << " ]";
		break;
	case 3:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << " [  �λ� ���  ]"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); cout << "  [ ";
		switch (total_gam % 5)
		{
		case 0: p91.print_name(); break;
		case 1: p92.print_name(); break;
		case 2: p93.print_name(); break;
		case 3: p94.print_name(); break;
		case 4: p95.print_name(); break;
		}
		cout << " ]";
		break;
	case 4:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << " [   LG  Ʈ����  ]"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); cout << "  [ ";
		switch (total_gam % 5)
		{
		case 0: p131.print_name(); break;
		case 1: p132.print_name(); break;
		case 2: p133.print_name(); break;
		case 3: p134.print_name(); break;
		case 4: p135.print_name(); break;
		}
		cout << " ]";
		break;
	case 5:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << " [   SSG ������  ]"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); cout << "  [ ";
		switch (total_gam % 5)
		{
		case 0: p161.print_name(); break;
		case 1: p162.print_name(); break;
		case 2: p163.print_name(); break;
		case 3: p164.print_name(); break;
		case 4: p165.print_name(); break;
		}
		cout << " ]";
		break;
	case 11:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << " [ ���� �����ܽ� ]"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); cout << "  [ ";
		switch (total_gam % 5)
		{
		case 0: p8001.print_name(); break;
		case 1: p8002.print_name(); break;
		case 2: p8003.print_name(); break;
		case 3: p8004.print_name(); break;
		case 4: p8005.print_name(); break;
		}
		cout << " ]";
		break;
	case 12:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << " [ ���� Ÿ�̰��� ]"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); cout << "  [ ";
		switch (total_gam % 5)
		{
		case 0: p9001.print_name(); break;
		case 1: p9002.print_name(); break;
		case 2: p9003.print_name(); break;
		case 3: p9004.print_name(); break;
		case 4: p9005.print_name(); break;
		}
		cout << " ]";
		break;
	}



	cout << "     V S  ";

	switch (away) {
	case 0:
		cout << right << setw(5) << " [ ";
		switch (total_gam % 5)
		{
		case 0: p1.print_name(); break;
		case 1: p2.print_name(); break;
		case 2: p3.print_name(); break;
		case 3: p4.print_name(); break;
		case 4: p5.print_name(); break;
		}
		cout << " ]  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << "[ �Ｚ ���̿��� ]" << '\n' << '\n';
		break;
	case 1:
		cout << right << setw(5) << " [ ";
		switch (total_gam % 5)
		{
		case 0: p31.print_name(); break;
		case 1: p32.print_name(); break;
		case 2: p33.print_name(); break;
		case 3: p34.print_name(); break;
		case 4: p35.print_name(); break;
		}
		cout << " ]  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << right << setw(5) << "[ �Ե� ���̾��� ]" << '\n' << '\n';
		break;
	case 2:
		cout << right << setw(5) << " [ ";
		switch (total_gam % 5)
		{
		case 0: p61.print_name(); break;
		case 1: p62.print_name(); break;
		case 2: p63.print_name(); break;
		case 3: p64.print_name(); break;
		case 4: p65.print_name(); break;
		}
		cout << " ]  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << right << setw(5) << "[  NC ���̳뽺  ]" << '\n' << '\n';
		break;
	case 3:
		cout << right << setw(5) << " [ ";
		switch (total_gam % 5)
		{
		case 0: p91.print_name(); break;
		case 1: p92.print_name(); break;
		case 2: p93.print_name(); break;
		case 3: p94.print_name(); break;
		case 4: p95.print_name(); break;
		}
		cout << " ]  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << right << setw(5) << "[  �λ� ���  ]" << '\n' << '\n';
		break;
	case 4:
		cout << right << setw(5) << " [ ";
		switch (total_gam % 5)
		{
		case 0: p131.print_name(); break;
		case 1: p132.print_name(); break;
		case 2: p133.print_name(); break;
		case 3: p134.print_name(); break;
		case 4: p135.print_name(); break;
		}
		cout << " ]  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << right << setw(5) << "[   LG  Ʈ����  ]" << '\n' << '\n';
		break;
	case 5:
		cout << right << setw(5) << " [ ";
		switch (total_gam % 5)
		{
		case 0: p161.print_name(); break;
		case 1: p162.print_name(); break;
		case 2: p163.print_name(); break;
		case 3: p164.print_name(); break;
		case 4: p165.print_name(); break;
		}
		cout << " ]  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << right << setw(5) << "[   SSG ������  ]" << '\n' << '\n';
		break;
	case 11:
		cout << right << setw(5) << " [ ";
		switch (total_gam % 5)
		{
		case 0: p8001.print_name(); break;
		case 1: p8002.print_name(); break;
		case 2: p8003.print_name(); break;
		case 3: p8004.print_name(); break;
		case 4: p8005.print_name(); break;
		}
		cout << " ]  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "[ ���� �����ܽ� ]" << '\n' << '\n';
		break;
	case 12:
		cout << right << setw(5) << " [ ";
		switch (total_gam % 5)
		{
		case 0: p9001.print_name(); break;
		case 1: p9002.print_name(); break;
		case 2: p9003.print_name(); break;
		case 3: p9004.print_name(); break;
		case 4: p9005.print_name(); break;
		}
		cout << " ]  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "[ ���� Ÿ�̰��� ]" << '\n' << '\n';
		break;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void show_menu(int my_team, int sound, bool* music_check, int team_color)
{
	int random = rand() % 3 + 1;

	int row = 8, col = 15;

	system("cls");
	cur(col + 8, row);
	cout << " [ �޴� ]"; row += 3; cur(col, row);
	cout << " [ 1 ] ��� ����"; row += 3; cur(col, row);
	cout << " [ 2 ] ���� ���� (Ÿ��)"; row += 3; cur(col, row);
	cout << " [ 3 ] ���� ���� (����)"; row += 3; cur(col, row);
	cout << " [ 4 ] ���� ����"; row += 3; cur(col, row);
	cout << " [ 5 ] �巡��Ʈ"; row += 3; cur(col, row);
	cout << " [ 6 ] �� ����"; row += 3; cur(col, row);
	cout << " [ 7 ] Ŀ��Ƭ"; row += 3; cur(col, row);
	cout << " [ 8 ] ���� ����"; row += 3; cur(col, row);

	pixel_art(my_team, team_color);

	if (*music_check == false && sound == 1)
	{
		if (random == 1) PlaySound(TEXT("newjeans_all.wav"), NULL, SND_ASYNC | SND_LOOP);
		else if (random == 2) PlaySound(TEXT("newjeans_all2.wav"), NULL, SND_ASYNC | SND_LOOP);
		else if (random == 3) PlaySound(TEXT("newjeans_all3.wav"), NULL, SND_ASYNC | SND_LOOP);

		*music_check = true;
	}

	if (sound != 1)
		PlaySound(NULL, NULL, NULL);
}

int sel_team(int team, int* team_color, int total_gam) {

	if (team == -1)
	{
		int row = 20, col = 10;

		for (int i = 8; i < 50; i++)
		{
			cur(15, i);
			cout << "                         ";
		}

		cur(row, col);

		cout << " [ ��� ���� �����Ͻʽÿ�. ]"; col += 3; cur(row, col);
		cout << " [ 1 ] �Ｚ"; col += 3; cur(row, col);
		cout << " [ 2 ] �Ե�"; col += 3; cur(row, col);
		cout << " [ 3 ] NC"; col += 3; cur(row, col);
		cout << " [ 4 ] �λ�"; col += 3; cur(row, col);
		cout << " [ 5 ] LG"; col += 3; cur(row, col);
		cout << " [ 6 ] SSG"; col += 3; cur(row, col);

		sel(&team, 40, 13, 3, 6);

		return team - 1;
	}


	int row = 20, col = 10;

	int before_team = team;

	for (int i = 8; i < 50; i++)
	{
		cur(15, i);
		cout << "                         ";
	}



	cur(row, col);

	cout << " [ ��� ���� �����Ͻʽÿ�. ]"; col += 3; cur(row, col);
	cout << " ( ��ü�� ���� ���� ������ 0�� ��쿡�� ���� �����մϴ�. )"; col += 3; cur(row, col);
	cout << " [ 1 ] �Ｚ"; col += 3; cur(row, col);
	cout << " [ 2 ] �Ե�"; col += 3; cur(row, col);
	cout << " [ 3 ] NC"; col += 3; cur(row, col);
	cout << " [ 4 ] �λ�"; col += 3; cur(row, col);
	cout << " [ 5 ] LG"; col += 3; cur(row, col);
	cout << " [ 6 ] SSG"; col += 3; cur(row, col);
	cout << " [ 7 ] ����   ( <-> �Ｚ )"; col += 3; cur(row, col);
	cout << " [ 8 ] ����   ( <->  NC  )"; col += 3; cur(row, col);
	cout << " [ 9 ] ���"; col += 3; cur(row, col);



	sel(&team, 48, 16, 3, 9);

	if (team < 7)
	{
		if (before_team == 11 || before_team == 12)
			if (total_gam != 0)
				return before_team;
	}

	if (team == 7)
	{
		if (total_gam == 0) return 11;
		else return before_team;
	}

	if (team == 8)
	{
		if (total_gam == 0) return 12;
		else return before_team;
	}

	if (team == 9) return before_team;

	if (before_team != team - 1) *team_color = 10;

	return team - 1;
}

void basic_setting()
{
	h3.change_dom(1); // �⺻ ����Ÿ��
	h33.change_dom(1);
	h62.change_dom(1);
	h92.change_dom(1);
	h132.change_dom(1);
	h163.change_dom(1);
	h8007.change_dom(1);
	h9005.change_dom(1);
}



void pixel_art(int my_team, int team_color)
{
	int col = 70, row = 1;

	int col2 = 120, row2 = 5;

	row = 1; cur(col, row);

	if (my_team == 0)
	{

		if (team_color > 4 && team_color != 7)
		{
			cur(col, row);


			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

			cout << "                             .....                                    "; row++; cur(col, row);
			cout << "                          ,~~-,,,-~-                                  "; row++; cur(col, row);
			cout << "                        ,---,--~--,--,                                "; row++; cur(col, row);
			cout << "                       ~,-~----~----,-,                               "; row++; cur(col, row);
			cout << "                     .~,-----,--,------,                              "; row++; cur(col, row);
			cout << "                     -,-----.~ .~,-----~                              "; row++; cur(col, row);
			cout << "                    ,,--------  ~---~,,~                              "; row++; cur(col, row);
			cout << "                    ~-------~-  ~---,--.                              "; row++; cur(col, row);
			cout << "                   .~,--------  ~,-~,                                 "; row++; cur(col, row);
			cout << "                   .~-------.-   -.                                   "; row++; cur(col, row);
			cout << "                   .---------~                    .                   "; row++; cur(col, row);
			cout << "                   .~--------,-                 ,-~                   "; row++; cur(col, row);
			cout << "                    ~,---------,              ,-- -                   "; row++; cur(col, row);
			cout << "                    ~-----------.          .-~,--,,                   "; row++; cur(col, row);
			cout << "                     ----------,~.       .---,---~.                   "; row++; cur(col, row);
			cout << "                     -,--------~ ~     .~-.------~                    "; row++; cur(col, row);
			cout << "                     .~,-----------  ,-,----------                    "; row++; cur(col, row);
			cout << "                      .----------,--~-,--~-----~,.                    "; row++; cur(col, row);
			cout << "                       --~---------,--,-.--------                     "; row++; cur(col, row);
			cout << "                        -,----------,--~,------.-                     "; row++; cur(col, row);
			cout << "                         ~,--------.-  ~------~,-                     "; row++; cur(col, row);
			cout << "                         ----------.- .~--------.                     "; row++; cur(col, row);
			cout << "                       -~-.,--------~ ,--------~                      "; row++; cur(col, row);
			cout << "                    ,--,--,~--------~ ,.-------~                      "; row++; cur(col, row);
			cout << "                 .---,--,--~-------.- ~,------.,                      "; row++; cur(col, row);
			cout << "               -~,,---,~-. ..------.- ---------.                      "; row++; cur(col, row);
			cout << "               ~,------.   ..-------,,,------,-                       "; row++; cur(col, row);
			cout << "               ~----~.     ,,------~ ~-------,-                       "; row++; cur(col, row);
			cout << "               ,,~--.-     ~-----,-. ~,-------,                       "; row++; cur(col, row);
			cout << "                -,-----. .--------- .~--------                        "; row++; cur(col, row);
			cout << "                ,-----,---,----,--  ..~------~                        "; row++; cur(col, row);
			cout << "                 --,----------,-,   -.------.,        ..              "; row++; cur(col, row);
			cout << "                  ,~,,-~~~-,,~~.    ~------~,.       .~~~             "; row++; cur(col, row);
			cout << "                    ,-------,.      -------,~.      --,,-             "; row++; cur(col, row);
			cout << "                                   ---------~   .,~~,-~,.             "; row++; cur(col, row);
			cout << "                                   -,-------~---,,------              "; row++; cur(col, row);
			cout << "                                   ~,------,-,,-~-----.-              "; row++; cur(col, row);
			cout << "                                  ,,~--------------~-,-,              "; row++; cur(col, row);
			cout << "                                 -------------~--------               "; row++; cur(col, row);
			cout << "                                -,---------~-,.-~~-.                  "; row++; cur(col, row);
			cout << "                                ~-----~-,,----,.                      "; row++; cur(col, row);
			cout << "                                ~,----,,~~-.                          "; row++; cur(col, row);
			cout << "                               ,-,,-~-,.                              "; row++; cur(col, row);
			cout << "                               ,---,                                  "; row++; cur(col, row);
			cout << "                               ,                                      "; row++; cur(col, row);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}

		else
		{
			col += 10;
			row += 4;
			cur(col, row);


			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);








			cout << "                         .,,,,..                  "; row++; cur(col, row);
			cout << "                     ,,-----------,,              "; row++; cur(col, row);
			cout << "                   ,---~~~~~~~~~~~----            "; row++; cur(col, row);
			cout << "                 ,--~~~~~~~~~~~~~~~~~-            "; row++; cur(col, row);
			cout << "                ,--~~~~~~~~~~~~~~~~~~-            "; row++; cur(col, row);
			cout << "               ,-~~~~~~~~~~~~~~~~~~~~-            "; row++; cur(col, row);
			cout << "              .-~~~~~~~~~~------~~~~~-            "; row++; cur(col, row);
			cout << "              --~~~~~~~~~--,,,,---~~~-            "; row++; cur(col, row);
			cout << "             .-~~~~~~~~~--      .--~~-            "; row++; cur(col, row);
			cout << "             ,-~~~~~~~~~-.        ,-~-            "; row++; cur(col, row);
			cout << "             ,-~~~~~~~~~-.         ,--            "; row++; cur(col, row);
			cout << "             --~~~~~~~~~-,          -,            "; row++; cur(col, row);
			cout << "             --~~~~~~~~~~-,          ,            "; row++; cur(col, row);
			cout << "             ,-~~~~~~~~~~~--,        .            "; row++; cur(col, row);
			cout << "             ,-~~~~~~~~~~~~---,                   "; row++; cur(col, row);
			cout << "             .-~~~~~~~~~~~~~~---,.                "; row++; cur(col, row);
			cout << "              --~~~~~~~~~~~~~~~~--,               "; row++; cur(col, row);
			cout << "              .-~~~~~~~~~~~~~~~~~~--,             "; row++; cur(col, row);
			cout << "               ,-~~~~~~~~~~~~~~~~~~--,            "; row++; cur(col, row);
			cout << "                ,-~~~~~~~~~~~~~~~~~~~--           "; row++; cur(col, row);
			cout << "                 ,--~~~~~~~~~~~~~~~~~~-,          "; row++; cur(col, row);
			cout << "                  .---~~~~~~~~~~~~~~~~~-,         "; row++; cur(col, row);
			cout << "                    .---~~~~~~~~~~~~~~~--         "; row++; cur(col, row);
			cout << "                      .---~~~~~~~~~~~~~~-,        "; row++; cur(col, row);
			cout << "                        .---~~~~~~~~~~~~--        "; row++; cur(col, row);
			cout << "          ..              .---~~~~~~~~~~~-        "; row++; cur(col, row);
			cout << "           -.               ,--~~~~~~~~~~-.       "; row++; cur(col, row);
			cout << "           ,-,               ,-~~~~~~~~~~-.       "; row++; cur(col, row);
			cout << "           .---               --~~~~~~~~~-.       "; row++; cur(col, row);
			cout << "            -~--,             ,-~~~~~~~~~-        "; row++; cur(col, row);
			cout << "            ,-~~--.           ,-~~~~~~~~--        "; row++; cur(col, row);
			cout << "            .-~~~---,        .-~~~~~~~~~-,        "; row++; cur(col, row);
			cout << "             -~~~~~----,    ,--~~~~~~~~~-.        "; row++; cur(col, row);
			cout << "             ,-~~~~~~~-------~~~~~~~~~~-,         "; row++; cur(col, row);
			cout << "             .-~~~~~~~~~~~~~~~~~~~~~~~--          "; row++; cur(col, row);
			cout << "              -~~~~~~~~~~~~~~~~~~~~~~--           "; row++; cur(col, row);
			cout << "              --~~~~~~~~~~~~~~~~~~~--,            "; row++; cur(col, row);
			cout << "              .---~~~~~~~~~~~~~~~---.             "; row++; cur(col, row);
			cout << "                .,------~~~~~----,.               "; row++; cur(col, row);
			cout << "                    .,,------,,.                  "; row++; cur(col, row);




			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}


	}

	else if (my_team == 1)
	{

		if (team_color > 4)
		{
			cur(col, row);


			cur(col, row);


			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

			cout << "                            ,*********!.          "; row++; cur(col, row);
			cout << "                      .,-*****========****:,,     "; row++; cur(col, row);
			cout << "                    ~~;**;;;;~........~;;!=**~.   "; row++; cur(col, row);
			cout << "                  ~;***~~.................-~**!-  "; row++; cur(col, row);
			cout << "                ,****,.......................-**, "; row++; cur(col, row);
			cout << "              .,**=,...........------.........~** "; row++; cur(col, row);
			cout << "             ,***:..........:;!******!-........!*,"; row++; cur(col, row);
			cout << "            -!*:..........-****:----~**,.......-*!"; row++; cur(col, row);
			cout << "           !**~..........~***..      ~*,........=*"; row++; cur(col, row);
			cout << "          **;..........,***~         ~*,.......~**"; row++; cur(col, row);
			cout << "        .**!.........,~=*:           ~*,.......!* "; row++; cur(col, row);
			cout << "       ,!*;.........,**;~            ~*,......-=* "; row++; cur(col, row);
			cout << "      .;*:..........=*:.            .!*,.....,=*~ "; row++; cur(col, row);
			cout << "      ,*:..........=*;              ,*:......**~  "; row++; cur(col, row);
			cout << "     ,**~.........-*;              ,**~.---=*!:   "; row++; cur(col, row);
			cout << "     **:.........-**              ,**=:;***;:.    "; row++; cur(col, row);
			cout << "    ~*;.........-**~             -******:--.      "; row++; cur(col, row);
			cout << "    !*,.........:*-             --......          "; row++; cur(col, row);
			cout << "   ;*..........,**,                               "; row++; cur(col, row);
			cout << "  .;=..........:*-                                "; row++; cur(col, row);
			cout << "  ~*,..........*;.                                "; row++; cur(col, row);
			cout << " .;*-.........;*:                                 "; row++; cur(col, row);
			cout << " ,*;..........*!                       ~!!!!!!!!! "; row++; cur(col, row);
			cout << " ,*:..........*!                 ;**************, "; row++; cur(col, row);
			cout << " -*:.........-*!           .,,****======,....;*!. "; row++; cur(col, row);
			cout << " !=-.........**-          ~;***;;;,..........*!.  "; row++; cur(col, row);
			cout << " *!..........=*         :;*=:~,.............=!.   "; row++; cur(col, row);
			cout << " *!..........=*       ~***.................**!    "; row++; cur(col, row);
			cout << " *!..........=*      -**,.-----,...........=*     "; row++; cur(col, row);
			cout << " *!..........=*    -~***;;******;-........~*:     "; row++; cur(col, row);
			cout << " *!..........=*   -*******!~--~**=,.......!*      "; row++; cur(col, row);
			cout << " *!..........=*~ -***;.....    .~*,......~**      "; row++; cur(col, row);
			cout << " :*:..........*!,-              ~*,......:*,      "; row++; cur(col, row);
			cout << " ,*:..........*!.              ,*:......,!*,      "; row++; cur(col, row);
			cout << " ,**,.........;*;              ,*:......,*;.      "; row++; cur(col, row);
			cout << "  :*,..........*!-             ;*,......,*~       "; row++; cur(col, row);
			cout << "  ~*=..........-**,           **!.......,*~       "; row++; cur(col, row);
			cout << "   ;*-..........~***...    ..!**........*!.       "; row++; cur(col, row);
			cout << "   -**~..........:*****~--~****.........*;        "; row++; cur(col, row);
			cout << "    -**:...........:;;=****=;;..........*;        "; row++; cur(col, row);
			cout << "     ,**=,............,----,...........=!.        "; row++; cur(col, row);
			cout << "      ,***-,...........................*!         "; row++; cur(col, row);
			cout << "        ~;***~~~..............,~~~*~..,*!         "; row++; cur(col, row);
			cout << "          ~:!***;;;;;;;;;;;;;;!*****;-!*~         "; row++; cur(col, row);
			cout << "            ,,,!***************-,,,*****          "; row++; cur(col, row);
			cout << "                  .        .        -***          "; row++; cur(col, row);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}

		else
		{
			cur(col, row);


			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);






			cout << "                            .........          "; row++; cur(col, row);
			cout << "                       .,..          ..,..      "; row++; cur(col, row);
			cout << "                   ...   ,~:;!****!!;~-.   ...  "; row++; cur(col, row);
			cout << "                 ,.  .;$@@@@@@@@@@@@@@@@@=;, .  "; row++; cur(col, row);
			cout << "              ... ,;$@@@$*;~-,.....,-~:!=#@@..  "; row++; cur(col, row);
			cout << "             ,. -=@@@*~.                 .*@ .  "; row++; cur(col, row);
			cout << "           ., -=@@=~                      =# .  "; row++; cur(col, row);
			cout << "          ,. !@@*,                        #= .  "; row++; cur(col, row);
			cout << "         , ,#@=,                          @* .  "; row++; cur(col, row);
			cout << "        . ~@@:                           .@; .  "; row++; cur(col, row);
			cout << "       , :@#.                            ,@: .  "; row++; cur(col, row);
			cout << "      , :@$.                     ,,-~~~-,;@-.  "; row++; cur(col, row);
			cout << "     , -@#                  .:*#@@@@@@@@@@@-.   "; row++; cur(col, row);
			cout << "     ..#@,               -!#@@#$*!;:~~~:;;*..   "; row++; cur(col, row);
			cout << "    . *@:              -$@@$:,.             ,   "; row++; cur(col, row);
			cout << "   ..,@=             .*@#!.  ......     ...,.   "; row++; cur(col, row);
			cout << "   , $@,            ,$@!. ...         .......   "; row++; cur(col, row);
			cout << "  . -@*            .#@~ .,      ......   .. ,   "; row++; cur(col, row);
			cout << "  . *@,           .#@- ,......     .-:;*$#* .   "; row++; cur(col, row);
			cout << "  . @$            *@~ , .    .-;*#@@@@@@#@!     "; row++; cur(col, row);
			cout << "   ~@~           -@! ,  . *$@@@@#$*!:-, ,@:     "; row++; cur(col, row);
			cout << " . =@.           ## .   . @#!:-..       ~@-.    "; row++; cur(col, row);
			cout << " , @=           -@; .   . @!            :@..    "; row++; cur(col, row);
			cout << " .,@!           !@,.    ..@!            !@ .    "; row++; cur(col, row);
			cout << " .~@~           $# ,    .,@:.,,         =# .    "; row++; cur(col, row);
			cout << "  :@-          .#= .    .~@##@@,        $$ .    "; row++; cur(col, row);
			cout << ". ;@,          .#! .     ~$=*$@         @* .    "; row++; cur(col, row);
			cout << ". !@.          ,@! .   ..    *#         @! .    "; row++; cur(col, row);
			cout << ". ;@,          .#* .    ,,.. $$        ,@:      "; row++; cur(col, row);
			cout << "  :@-           $$ ,       . @!        -@~ .    "; row++; cur(col, row);
			cout << " .~@~           *@,.       ..@:        :@-.     "; row++; cur(col, row);
			cout << " .,@;           -@! ,       -@-        ;@,.     "; row++; cur(col, row);
			cout << " , @=            *@: ..   . :@,        *#..     "; row++; cur(col, row);
			cout << " . *@.            =@;. ...  *@.        =$ ,     "; row++; cur(col, row);
			cout << "  ..@!            .=@#;~,-~!@$         $= .     "; row++; cur(col, row);
			cout << "  . *@.             ~#@@@@@@#~        .#* .     "; row++; cur(col, row);
			cout << "  ..,@=               -~::~,          ,@!       "; row++; cur(col, row);
			cout << "   , !@;                              -@:       "; row++; cur(col, row);
			cout << "    , =@:                             !@~       "; row++; cur(col, row);
			cout << "    .. $@!                          -$@= .      "; row++; cur(col, row);
			cout << "     .. *@$-                      -=@#: ..      "; row++; cur(col, row);
			cout << "      .. :@@*,                  ~=@@!. ,        "; row++; cur(col, row);
			cout << "        , .*@@$:.           .-!@@#!. .,         "; row++; cur(col, row);
			cout << "         .. ,;#@@$*!:~~~:;*$@@@=:. ..           "; row++; cur(col, row);
			cout << "           ,.  ,!#@@@@@@@@@#*~   ,,             "; row++; cur(col, row);
			cout << "             ...   ,-~~~-,.  ....               "; row++; cur(col, row);
			cout << "                 .,.......,..                   "; row++; cur(col, row);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);



		}
	}






	else if (my_team == 4)
	{
		row += 5;

		cur(col, row);


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

		cout << "                                                    !=                "; row++; cur(col, row);
		cout << "                                                  ~#;;                "; row++; cur(col, row);
		cout << "                                               ,=#* ;-                "; row++; cur(col, row);
		cout << "                      .*#####################@=, ,.#                 "; row++; cur(col, row);
		cout << "                    =#=,                     .,--- #                 "; row++; cur(col, row);
		cout << "                ;#, ,--------------------------.#,                 "; row++; cur(col, row);
		cout << "                $= ----------------------------.;$                  "; row++; cur(col, row);
		cout << "              ;=.---------------------------- *#                   "; row++; cur(col, row);
		cout << "                # --------------------------- .#*                    "; row++; cur(col, row);
		cout << "              -*-------,.      ------      !#$                      "; row++; cur(col, row);
		cout << "               *.-----, =###### ------.###@=~                        "; row++; cur(col, row);
		cout << "               *.----- #,     # ------!.                             "; row++; cur(col, row);
		cout << "               -=----,@       # ------#                              "; row++; cur(col, row);
		cout << "               # ----~$       @,-----.#                              "; row++; cur(col, row);
		cout << "                .# .,-,~#.    $------ #                              "; row++; cur(col, row);
		cout << "                   @#*;!##    :------- #                              "; row++; cur(col, row);
		cout << "                     .-,      @ ------ @                              "; row++; cur(col, row);
		cout << "                              # ------.!                              "; row++; cur(col, row);
		cout << "                              # ------!,                              "; row++; cur(col, row);
		cout << "                              # ------@                               "; row++; cur(col, row);
		cout << "                              #,-----.#                               "; row++; cur(col, row);
		cout << "                              $------ #                               "; row++; cur(col, row);
		cout << "                             :------- #                               "; row++; cur(col, row);
		cout << "			           # ------ @                               "; row++; cur(col, row);
		cout << "			           # ------.*							   "; row++; cur(col, row);
		cout << "                             # ------;,                               "; row++; cur(col, row);
		cout << "                             # ------@                                "; row++; cur(col, row);
		cout << "                             #,-----.#                                "; row++; cur(col, row);
		cout << "		                   =------ #                                "; row++; cur(col, row);
		cout << "                            :------- #                                "; row++; cur(col, row);
		cout << "                            @ ------ @                                "; row++; cur(col, row);
		cout << "                            # ,,,,,, =                                "; row++; cur(col, row);
		cout << "                            #*******=,                                "; row++; cur(col, row);
		cout << "                            .........								  "; row++; cur(col, row);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}


}

void fullscreen() {
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

int main()
{
	fullscreen();

	system("mode con cols=285 lines=165");
	srand((unsigned)time(NULL));

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	int menu = 0;
	int gam = 0;
	int total_gam = 0; // ���� ���
	int my_team = -1; // �� ��, 0=�Ｚ 1=�Ե�
	int sound = 3; // ���� ��¿���
	int game_speed = 3; // ���� �ӵ�
	bool use_condition = false; // ����� ��� (�⺻�� : ���)
	bool music_check = false;
	int team_color = 10;

	basic_setting();

	CursorView(false);
	my_team = sel_team(my_team, &team_color, 0);


	while (1)
	{




		show_menu(my_team, sound, &music_check, team_color);

		sel(&menu, 45, 11, 3, 8); // ������ 6��

		switch (menu) // main���� ���°� ��������...
		{
		case 1:
			play(gam, &total_gam, my_team, sound, game_speed, use_condition, &music_check);
			break;

		case 2:
			print_hitter_record(total_gam, my_team, false, false, 0);
			break;

		case 3:
			rechange_p(total_gam, my_team);
			break;

		case 4:
			mode(&sound, &game_speed, &use_condition, &music_check, &my_team, &team_color);
			break;

		case 5:
			sim -= 1;
			recruit(my_team, use_condition);
			sim += 1;
			break;

		case 6:
			my_team = sel_team(my_team, &team_color, total_gam);
			break;

		case 7:
			create(my_team, use_condition);
			break;

		case 8:
			system("cls");
			exit(0);
		}
	}
}



// ���׷� �̱۽�

*/