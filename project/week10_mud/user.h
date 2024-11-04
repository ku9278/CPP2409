class User{
private:
	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로
	int user_y = 0; // 세로
	// 유저의 HP
	int hp;

public:
    User();

	int getUser_x();
	int getUser_y();
	int getHp();

	void Move(int move_x, int move_y);
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
};