#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<float> score;
    float input;
    while (1){
        cout << "성적을 입력하시오(종료는 -1): ";
        cin >> input;
        if (input == -1) break;
        score.push_back(input);
    }

    float sum = 0;
    float mean;
    for (auto& e : score)
        sum += e;
    mean = sum/(float)score.size();
    cout << "성적 평균 = " << mean << endl;
    return 0;
}