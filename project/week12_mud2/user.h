#include <iostream>
using namespace std;

class User{
private:
	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로
	int user_y = 0; // 세로
	// 유저의 HP
	int hp;
	// 아이템 먹은 횟수
	int itemCnt = 0;

public:
    User();

	int getUser_x();
	int getUser_y();
	int getHp();

	void Move(int move_x, int move_y);
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
	void IncreaseItem(int inc_item);

	void DoAttack();

	friend ostream& operator << (ostream& os, const User& u);
};

class Magician : public User{
public:
	void DoAttack();
};

class Warrior : public User{
public:
	void DoAttack();
};