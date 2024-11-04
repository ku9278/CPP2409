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