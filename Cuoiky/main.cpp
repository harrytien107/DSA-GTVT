#include <bits/stdc++.h>
#include "BankManagement.h"
#include "BankAccount.h"
#include "BankManagement.cpp"
#include "BankAccount.cpp"
using namespace std;

int main() {
    BankManagement bank;
    
    // Thêm một số tài khoản mẫu
    bank.addAccount(BankAccount("0111222233334444", "Nguyen Van A", "001", 1000000, 0));
    bank.addAccount(BankAccount("0111222233335555", "Tran Thi B", "002", 2000000, 0));
    
    string accountNumber;
    cout << "Nhap so tai khoan : ";
    cin >> accountNumber;

    // Thực hiện nộp tiền
    if (bank.deposit(accountNumber)) {
        cout << "Giao dich hoan tat!" << endl;
    } else {
        cout << "Giao dich that bai!" << endl;
    }
    
    return 0;
}