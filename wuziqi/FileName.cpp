#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
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

bool ifwin() {
	if (1) {
		return 1;
	}
}//player1ʤ���ж�,ʤΪtrue��Ϊfalse

void player1fight() {
	cout << "���̴�С��15 * 15"<<endl;
	cout << "���������1��O�����ӣ��ĺ������꣬�Կո�����"<<endl;
	cin >> player1.x >> player1.y;
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
	cout << "���������2��X�����ӣ��ĺ������꣬�Կո�����"<<endl;
	cin >> player2.x >> player2.y;
	system("cls");
	pan[player2.y - 1][2 * player2.x - 2] = 'X';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << pan[i][2 * j] << pan[i][2 * j + 1];
		}
		cout << endl;
	}
}



int main() {
	system("cls");
	initUI();
	switch (mode) {
	case 0:
		return 0;
		break;
	case 1:
		initpan();
		while (1) {
			player1fight();
			if (ifwin()) {
				cout << "���1��ʤ��";
				break;
			}
			player2fight();
			if (!ifwin()) {
				cout << "���2��ʤ��";
				break;
			}
		}

	
	}

return 0;
}