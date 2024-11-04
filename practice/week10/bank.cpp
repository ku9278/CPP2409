#include <iostream>
#include <string>
using namespace std;

class BankAccount{
private:
    double balance;
    string accountHolderName;
public:
    BankAccount(string name, double initialBalance){
        accountHolderName = name;
        balance = initialBalance;
    }
    // 현재 잔액 조회 메소드
    double getBalance() const{
        return balance;
    }
    // 입금 메소드
    void deposit(double amount){
        if (amount > 0){
            balance += amount;
            cout << amount << " daposited. Current balance: " << balance << endl;
        }
    }
    //출금 메소드
    void withdraw(double amount){
        if (amount > 0 && amount <= balance){
            balance -= amount;
            cout << amount << " withdrawn. Current balance: " << balance << endl;
        }
        else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }
};

int main(){
    // 계좌 생성
    BankAccount myAccount("Alice", 1000);

    // 잔액 조회
    cout << "Initial Balance: " << myAccount.getBalance() << endl;

    // 입금 및 출금
    myAccount.deposit(500);
    myAccount.withdraw(200);

    // // 직접 접근 시도 (불가능)
    // myAccount.balance = 5000;
    // myAccount.accountHolderName = "Bob"

    return 0;
}