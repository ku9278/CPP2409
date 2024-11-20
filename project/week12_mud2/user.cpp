#include <iostream>
#include "user.h"

User::User(){
    hp = 20;
}

int User::getUser_x() { return user_x; }
int User::getUser_y() { return user_y; }
int User::getHp() { return hp; }

void User::Move(int move_x, int move_y){
    user_x += move_x;
    user_y += move_y;
}
void User::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}
void User::IncreaseHP(int inc_hp){
    hp += inc_hp;
}
void User::IncreaseItem(int inc_item){
    itemCnt += inc_item;
}

void User::DoAttack(){
    cout << "공격합니다" << endl;
}

ostream& operator << (ostream& os, const User& u){
    os << "현재 HP는 " << u.hp << "이고, 먹은 아이템은 총 " << u.itemCnt << "개 입니다." << endl;
    return os;
}

void Magician::DoAttack(){
    cout << "마법 사용" << endl;
}

void Warrior::DoAttack(){
    cout << "베기 사용" << endl;
}