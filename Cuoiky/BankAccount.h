#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountName;
    std::string accountType;    // 001: Thanh toan, 002: Tiet kiem
    double balance;
    int status;                 // 0: Active, 1: Block
    const std::string PASSWORD = "123456";
    int wrongPasswordCount = 0;

public:
    BankAccount(std::string accNum, std::string name, std::string type, double bal, int stat);
    
    // Getters
    std::string getAccountNumber() const;
    std::string getAccountType() const;
    int getStatus() const;
    double getBalance() const;

    // Setters
    void setStatus(int stat);
    void setBalance(double bal);

    bool checkPassword(std::string inputPassword);
};

#endif