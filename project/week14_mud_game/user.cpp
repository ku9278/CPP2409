#include <iostream>
#include "user.h"

User::User(){
    hp = 20;
}

int User::getUser_x() { return user_x; }
int User::getUser_y() { return user_y; }
int User::getHp() { return hp; }

// void User::Move(int move_x, int move_y){
//     user_x += move_x;
//     user_y += move_y;
// }
// void User::DecreaseHP(int dec_hp){
//     hp -= dec_hp;
// }
// void User::IncreaseHP(int inc_hp){
//     hp += inc_hp;
// }
// void User::IncreaseItem(int inc_item){
//     itemCnt += inc_item;
// }

ostream& operator << (ostream& os, const User& u){
    os << "현재 HP는 " << u.hp << "이고, 먹은 아이템은 총 " << u.itemCnt << "개 입니다." << endl;
    return os;
}

// magician
int Magician::getUser_x() { return user_x; }
int Magician::getUser_y() { return user_y; }
int Magician::getHp() { return hp; }

void Magician::Move(int move_x, int move_y){
    user_x += move_x;
    user_y += move_y;
}
void Magician::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}
void Magician::IncreaseHP(int inc_hp){
    hp += inc_hp;
}
void Magician::IncreaseItem(int inc_item){
    itemCnt += inc_item;
}

void Magician::DoAttack(){
    cout << "마법 사용" << endl;
}

// warrior
int Warrior::getUser_x() { return user_x; }
int Warrior::getUser_y() { return user_y; }
int Warrior::getHp() { return hp; }

void Warrior::Move(int move_x, int move_y){
    user_x += move_x;
    user_y += move_y;
}
void Warrior::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}
void Warrior::IncreaseHP(int inc_hp){
    hp += inc_hp;
}
void Warrior::IncreaseItem(int inc_item){
    itemCnt += inc_item;
}

void Warrior::DoAttack(){
    cout << "베기 사용" << endl;
}