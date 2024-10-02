#include <iostream>
using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수

    // 보드판 초기화
    for (x = 0; x < numCell; x++){
        for (y = 0; y < numCell; y++){
            board[x][y] = ' ';
        }
    }

    // 게임하는 코드
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 문자 변수
    while(1){
        // 1. 누구 차례인지 출력
        switch(k % 2){
            case 0:
                cout << "첫번째 유저(X)의 차례입니다 -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << "두번째 유저(O)의 차례입니다 -> ";
                currentUser = 'O';
                break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (x >= numCell || y >= numCell){
            cout << x << ", " << y << ": ";
            cout << "x와 y중 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }

        // 2-2. 좌표 변환
        int tmp = y;
        y = x;
        x = numCell - 1 - tmp;

        // 3-2. 입력받은 좌표의 유효성 체크
        if (board[x][y] != ' '){
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++){
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++){
                cout << " " << board[i][j];
                if (j == numCell - 1){
                    break;
                }
                cout << " |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

        // 6. 빙고 시 승자 출력 후 종료
        if (k >= 4){ // k < 4 이면 승자가 나올 수 없다
            int i = 0, j = 0;
            for (i = 0; i < numCell; i++){ // 가로
                for (j = 0; j < numCell - 1; j++){
                    if (board[i][j] == ' ') break;
                    if (board[i][j] == board[i][j+1]) continue;
                    else break;
                }
                if (j == numCell - 1){
                    cout << board[i][j] << "의 승리입니다" << endl;
                    return 0;
                }
            }

            for (j = 0; j < numCell; j++){ // 세로
                for (i = 0; i < numCell - 1; i++){
                    if (board[i][j] == ' ') break;
                    if (board[i][j] == board[i+1][j]) continue;
                    else break;
                }
                if (i == numCell - 1){
                    cout << board[i][j] << "의 승리입니다" << endl;
                    return 0;
                }
            }
            
            for (i = 0; i < numCell - 1; i++){ // 대각선
                if (board[i][i] == ' ') break;
                if (board[i][i] == board[i+1][i+1]) continue;
                else break;
            }
            if (i == numCell - 1){
                cout << board[i][i] << "의 승리입니다" << endl;
                return 0;
            }

            for (i = 0; i < numCell - 1; i++){ // 대각선
                if (board[(numCell-1)-i][i] == ' ') break;
                if (board[(numCell-1)-i][i] == board[(numCell-1)-(i+1)][i+1]) continue;
                else break;
            }
            if (i == numCell - 1){
                cout << board[(numCell-1)-i][i] << "의 승리입니다" << endl;
                return 0;
            }
        }

        // 7. 모든 칸이 찼으면 종료
        if (k == 8){
            cout << "무승부입니다.";
            break;
        }

        k++;
    }

    return 0;
}