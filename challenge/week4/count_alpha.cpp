#include <iostream>
using namespace std;

int main(){
    int vowel = 0;
    int consonant = 0;
    cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

    char ch;

    while(cin >> ch){
        if(ch < 'a' || ch > 'z'){
            cout << "잘못입력되었습니다. 다시 입력하십시오." << endl;
            continue;
        }
        switch(ch){
            case 'a': case 'e': case 'i': case 'o': case 'u':
                vowel++;
                break;
            default:
                consonant++;
                break;
        }
    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;

    return 0;
}