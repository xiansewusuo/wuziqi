#include<iostream>
#define PI 3.1415927
#define N 15
using namespace std;

char pan[N][2 * N];
int mode;
int eend = 1;

void initpan() {
	system("cls");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			pan[i][2 * j] = '*';
			pan[i][2 * j + 1] = ' ';
			cout << pan[i][2 * j] << pan[i][2 * j + 1];
		}
		cout << endl;
	}
}//��ʼ������ӡ����

void initUI() {
	cout << "***************************************************" << endl;
	cout << "**********************ѡ��ģʽ*********************" << endl;
	cout << "***********************0,�˳�**********************" << endl;
	cout << "********************1�����VS���******************" << endl;
	cout << "**********************����0��1*********************" << endl;
	cout << "***************************************************" << endl;
	cin >> mode;
}//��ʼ������

class location {
public:
	int x;
	int y;
}player1, player2;
//������������

void player1fight() {
	cout << "���̴�С��15 * 15"<<endl;
	cout << "���������1��O�����ӣ��ĺ������꣬�Կո�����"<<endl;
	cin >> player1.y >> player1.x;
	system("cls");
	pan[player1.y - 1][2 * player1.x - 2] = 'O';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << pan[i][2 * j] << pan[i][2 * j + 1];
		}
		cout << endl;
	}
}
void player2fight() {
	cout << "���̴�С��15 * 15"<<endl;
	cout << "���������2��X�����ӣ����������꣬�Կո�����"<<endl;
	cin >> player2.y >> player2.x;
	system("cls");
	pan[player2.y - 1][2 * player2.x - 2] = 'X';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << pan[i][2 * j] << pan[i][2 * j + 1];
		}
		cout << endl;
	}
}

bool ifwin1() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pan[i][2 * j] == 'O') {
				if (pan[i][2 * j + 2] == 'O' && pan[i][2 * j + 4] == 'O' && pan[i][2 * j + 8] == 'O' && pan[i][2 * j + 6] == 'O')
					return 1;//��5��
				if (pan[i + 1][2 * j] == 'O' && pan[i + 2][2 * j] == 'O' && pan[i + 3][2 * j] == 'O' && pan[i + 4][2 * j] == 'O')
					return 1;//��5��
				if (pan[i + 1][2 * j + 2] == 'O' && pan[i + 2][2 * j + 4] == 'O' && pan[i + 3][2 * j + 6] == 'O' && pan[i + 4][2 * j + 8] == 'O')
					return 1;//��5��
				if (pan[i + 1][2 * j - 2] == 'O' && pan[i + 2][2 * j - 4] == 'O' && pan[i + 3][2 * j - 6] == 'O' && pan[i + 4][2 * j - 8] == 'O')
					return 1;//Ʋ5��
			}
		}
	}
	return 0;
}//player1ʤ���ж�,ʤΪtrue��Ϊfalse

bool ifwin2() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pan[i][2 * j] == 'X') {
				if (pan[i][2 * j + 2] == 'X' && pan[i][2 * j + 4] == 'X' && pan[i][2 * j + 8] == 'X' && pan[i][2 * j + 6] == 'X')
					return 1;//��5��
				if (pan[i + 1][2 * j] == 'X' && pan[i + 2][2 * j] == 'X' && pan[i + 3][2 * j] == 'X' && pan[i + 4][2 * j] == 'X')
					return 1;//��5��
				if (pan[i + 1][2 * j + 2] == 'X' && pan[i + 2][2 * j + 4] == 'X' && pan[i + 3][2 * j + 6] == 'X' && pan[i + 4][2 * j + 8] == 'X')
					return 1;//��5��
				if (pan[i + 1][2 * j - 2] == 'X' && pan[i + 2][2 * j - 4] == 'X' && pan[i + 3][2 * j - 6] == 'X' && pan[i + 4][2 * j - 8] == 'X')
					return 1;//Ʋ5��
			}
		}
	}
	return 0;
}//player1ʤ���ж�,ʤΪtrue��Ϊfalse

int main() {
	system("cls");
	initUI();
begin:
	switch (mode) {
	case 0:
		return 0;
	case 1:
		initpan();
		while (1) {
			player1fight();
			if (ifwin1()) {
				cout << "���1��ʤ��"<<endl;
				break;
			}
			player2fight();
			if (ifwin2()) {
				cout << "���2��ʤ��"<<endl;
				break;
			}
		}

	
	}
	cout << endl;
	initUI();
	goto begin;
}