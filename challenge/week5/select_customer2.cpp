#include <iostream>
using namespace std;

int main(){
    const int maxPeople = 5; // 사람 수를 5로 수정
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;
    for(int i = 0; i < maxPeople; i++){
        cout << "사람" << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람" << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    while(1){
        int menu;
        cout << "\n메뉴 선택:\n1. 가장 나이가 많은 사람 출력\n2. 가장 나이가 적은 사람 출력\n3. 종료\n";
        cin >> menu;
        switch(menu){
            case 1: {
                int max_age = ages[0];
                int max_idx = 0;
                for (int i = 1; i < maxPeople; i++){
                    if (ages[i] > max_age){
                        max_age = ages[i];
                        max_idx = i;
                    }
                }
                cout << "나이가 가장 많은 사람: " << names[max_idx] << " (" << ages[max_idx] << "세)" << endl;
                break;
            }
            case 2: {
                int min_age = ages[0];
                int min_idx = 0;
                for (int i = 1; i < maxPeople; i++){
                    if (ages[i] < min_age){
                        min_age = ages[i];
                        min_idx = i;
                    }
                }
                cout << "나이가 가장 적은 사람: " << names[min_idx] << " (" << ages[min_idx] << "세)" << endl;
                break;
            }
            case 3:
                cout << "프로그램 종료." << endl;
                break;
            default:
                cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
                break;
        }
        if(menu == 3) break;
    }

    return 0;
}
