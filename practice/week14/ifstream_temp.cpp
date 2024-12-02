#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream file("temp.txt");
    if (!file){
        cerr << "파일 오픈에 실패하였습니다" << endl;
        exit(1);
    }

    // float elem;
    // int cnt = 0;
    // while(file >> elem){
    //     if (cnt % 2 == 0) cout << elem << "시: ";
    //     else if (cnt % 2 == 1) cout << "온도 " << elem << endl;
    //     cnt += 1;
    // }

    int hour;
    double temperature;
    while (file >> hour >> temperature){
        cout << hour << "시: 온도 " << temperature << endl;
    }

    return 0;
}