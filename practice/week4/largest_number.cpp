#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;

    cout << "3개의 정수를 입력하십시오: ";
    cin >> a >> b >> c;

    /*
    부등호에 등호를 추가하여 a 또는 b 또는 c가 같은 경우를 처리한다
    a = b = c
        a, b, c 모두 가장 큰 정수이며 첫번쨰 if문에서 걸린다
    a = b != c
        a가 큰 경우 첫번째 if문에서 걸리고 c가 큰 경우에는 else문에서 걸린다
    a = c != b
        a가 큰 경우 첫번째 if문에서 걸리고 b가 큰 경우에는 else if문에서 걸린다
    b = c != a
        b가 큰 경우 else if문에서 걸리고 a가 큰 경우에는 첫번째 if문에서 걸린다
    a != b != c
        이전 코드에서도 정상작동
    */
    if (a >= b && a >= c) // 등호 추가
        largest = a;
    else if(b >= a && b >= c) // 등호 추가
        largest = b;
    else
        largest = c;

    cout << "가장 큰 정수는" << largest << endl;

    return 0;
}