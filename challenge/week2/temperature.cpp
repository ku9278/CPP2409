#include <iostream>
using namespace std;

int main(){
    float tem_f, tem_c;

    cout << "화씨온도: ";
    cin >> tem_f;

    tem_c = (5.0 / 9.0) * (tem_f - 32);
    cout << "섭씨온도 = " << tem_c << endl;

    return 0;
}