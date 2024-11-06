#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
void displayMap(vector<vector<int>> map, int user_x, int user_y);
bool checkXY(int user_x, int mapX, int user_y, int mapY);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
int checkState(vector<vector<int>> map, int user_x, int user_y);
bool checkUser(User user);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	User user1;

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		// 이동 거리 변수
		int move_x = 0;
		int move_y = 0;

		// 입력
		cout << "현재 HP: " << user1.getHp();
		cout << "  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") move_y = -1;
		else if (user_input == "하") move_y = 1;
		else if (user_input == "좌") move_x = -1;
		else if (user_input == "우") move_x = 1;
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user1.getUser_x(), user1.getUser_y());
			continue;
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 이동
		user1.Move(move_x, move_y);
		bool inMap = checkXY(user1.getUser_x(), mapX, user1.getUser_y(), mapY);
		if (inMap == false){
			cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
			user1.Move(-move_x, -move_y);
			continue;
		}
		else{
			cout << user_input << "(으)로 이동합니다." << endl;
			user1.DecreaseHP(1);
			displayMap(map, user1.getUser_x(), user1.getUser_y());
		}

		// 이벤트가 발생하는지 체크
		int event = checkState(map, user1.getUser_x(), user1.getUser_y());
		switch (event){
			case 0: // 발생 안함
				break;
			case 1: // 아이템
				cout << "아이템이 있습니다." << endl;
				break;
			case 2: // 적
				cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
				user1.DecreaseHP(2);
				break;
			case 3: // 포션
				cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
				user1.IncreaseHP(2);
				break;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user1.getUser_x(), user1.getUser_y());
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// hp가 0이면 실패
        bool alive = checkUser(user1);
		if (!alive) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다.";
			break;
		}
	}
	
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>> map, int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>> map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 유저의 위치가 아이템, 포션, 적인지 체크하는 함수
// 1은 아이템, 2는 적, 3은 포션
int checkState(vector<vector<int>> map, int user_x, int user_y) {
	if (map[user_y][user_x] == 1) return 1;
	else if (map[user_y][user_x] == 2) return 2;
	else if (map[user_y][user_x] == 3) return 3;
	else return 0;
}

// 유저의 HP가 0인지 체크하는 함수
bool checkUser(User user){
    if(user.getHp() <= 0) return false;
    else return true;
}