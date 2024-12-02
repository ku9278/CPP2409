#include <iostream>
using namespace std;

class User{
protected:
	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로
	int user_y = 0; // 세로
	// 유저의 HP
	int hp;
	// 아이템 먹은 횟수
	int itemCnt = 0;

public:
    User();

	virtual int getUser_x() = 0;
	virtual int getUser_y() = 0;
	virtual int getHp() = 0;

	virtual void Move(int move_x, int move_y) = 0;
    virtual void DecreaseHP(int dec_hp) = 0;
    virtual void IncreaseHP(int inc_hp) = 0;
	virtual void IncreaseItem(int inc_item) = 0;

	virtual void DoAttack() = 0;

	friend ostream& operator << (ostream& os, const User& u);
};

class Magician : public User{
public:
	int getUser_x();
	int getUser_y();
	int getHp();

	void Move(int move_x, int move_y);
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
	void IncreaseItem(int inc_item);

	void DoAttack();
};

class Warrior : public User{
public:
	int getUser_x();
	int getUser_y();
	int getHp();

	void Move(int move_x, int move_y);
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
	void IncreaseItem(int inc_item);

	void DoAttack();
};