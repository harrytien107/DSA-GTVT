#include "BankAccount.h"

BankAccount::BankAccount(std::string accNum, std::string name, std::string type, double bal, int stat) {
    accountNumber = accNum;
    accountName = name;
    accountType = type;
    balance = bal;
    status = stat;
}

std::string BankAccount::getAccountNumber() const { return accountNumber; }
std::string BankAccount::getAccountType() const { return accountType; }
int BankAccount::getStatus() const { return status; }
double BankAccount::getBalance() const { return balance; }

void BankAccount::setStatus(int stat) { status = stat; }
void BankAccount::setBalance(double bal) { balance = bal; }

bool BankAccount::checkPassword(std::string inputPassword) {
    if (inputPassword != PASSWORD) {
        wrongPasswordCount++;
        if (wrongPasswordCount >= 3) {
            status = 1; // Block account
            return false;
        }
        return false;
    }
    wrongPasswordCount = 0;
    return true;
}