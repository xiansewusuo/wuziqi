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
}//初始化并打印棋盘

void initUI() {
	cout << "***************************************************" << endl;
	cout << "**********************选择模式*********************" << endl;
	cout << "***********************0,退出**********************" << endl;
	cout << "********************1，玩家VS玩家******************" << endl;
	cout << "**********************输入0或1*********************" << endl;
	cout << "***************************************************" << endl;
	cin >> mode;
}//初始化界面

class location {
public:
	int x;
	int y;
}player1, player2;
//定义棋子坐标

bool ifwin() {
	if (1) {
		return 1;
	}
}//player1胜负判断,胜为true负为false

void player1fight() {
	cout << "棋盘大小：15 * 15"<<endl;
	cout << "请输入玩家1（O形棋子）的横纵坐标，以空格区分"<<endl;
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
	cout << "棋盘大小：15 * 15"<<endl;
	cout << "请输入玩家2（X形棋子）的横纵坐标，以空格区分"<<endl;
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
				cout << "玩家1获胜！";
				break;
			}
			player2fight();
			if (!ifwin()) {
				cout << "玩家2获胜！";
				break;
			}
		}

	
	}

return 0;
}