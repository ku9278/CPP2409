#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Temperature{
public:
    int hour;
    double temperature;
};

int main(){
    ifstream file("temp.txt");
    if (!file){
        cerr << "파일 오픈에 실패하였습니다" << endl;
        exit(1);
    }

    int hour;
    double temperature;
    vector<Temperature> vec;
    while (file >> hour >> temperature){
        Temperature T;
        T.hour = hour;
        T.temperature = temperature;
        vec.push_back(T);
    }
    for (Temperature T : vec){
        cout << T.hour << "시: 온도 " << T.temperature << endl;
    }

    return 0;
}