#ifndef BANK_MANAGEMENT_H
#define BANK_MANAGEMENT_H

#include <vector>
#include "BankAccount.h"

class BankManagement {
private:
    std::vector<BankAccount> accounts;

public:
    void addAccount(BankAccount account);
    bool deposit(std::string accountNumber);
    void checkStatus(std::string accountNumber);
};

#endif