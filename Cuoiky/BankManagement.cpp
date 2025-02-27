#include "BankManagement.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void BankManagement::addAccount(BankAccount account) {
    accounts.push_back(account);
}

bool BankManagement::deposit(std::string accountNumber) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            std::cout << "\nKiem tra tai khoan..." << std::endl;
            
            // Kiểm tra tài khoản tồn tại
            std::cout << "- Tai khoan " << accountNumber << " ton tai" << std::endl;
            
            // Kiểm tra trạng thái active
            std::cout << "- Tinh trang tai khoan: " << acc.getStatus() 
                       << std::endl;
            if (acc.getStatus() == 1) {
                std::cout << "- Tai khoan bi khoa!" << std::endl;
                return false;
            }
            
            // Kiểm tra loại tài khoản
            if (acc.getAccountType() != "001") {
                std::cout << "- Chi tai khoan thanh toan moi duoc nop tien!" << std::endl;
                return false;
            }
            std::cout << "- Tai khoan thanh toan hop le" << std::endl;
            std::cout << "\nTat ca dieu kien deu thoa man. Tiep tuc giao dich...\n" << std::endl;

            for (int i = 0; i < 3; i++) {
                std::string password;
                std::cout << "Nhap mat khau: ";
                std::cin >> password;
                
                if (acc.checkPassword(password)) {
                    std::ifstream file("D:/CODE/BaitapC++/Cauttrucgiaithuat/Cuoiky/Cau1/tiennop.txt");
                    if (!file.is_open()) {
                        std::cout << "Khong the mo file tiennop.txt!" << std::endl;
                        return false;
                    }
                    
                    double amount;
                    if (file >> amount) {
                        acc.setBalance(acc.getBalance() + amount);
                        std::cout << std::fixed << std::setprecision(0);
                        std::cout << "Nop tien thanh cong!" << std::endl;
                        std::cout << "So tien nop: " << amount << " VND" << std::endl;
                        std::cout << "So du moi: " << acc.getBalance() << " VND" << std::endl;
                        file.close();
                        return true;
                    } else {
                        std::cout << "Khong the doc so tien tu file!" << std::endl;
                        file.close();
                        return false;
                    }
                }
                std::cout << "Mat khau sai! Con " << 2-i << " lan thu" << std::endl;
            }
            return false;
        }
    }
    std::cout << "Khong tim thay tai khoan!" << std::endl;
    return false;
}

void BankManagement::checkStatus(std::string accountNumber) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            std::cout << "Tinh trang tai khoan: " << acc.getStatus() 
                     << " (0 - Active, 1 - Block)" << std::endl;
            
            if (acc.getStatus() == 1) {
                char choice;
                std::cout << "Ban co muon kich hoat lai tai khoan? (y/n): ";
                std::cin >> choice;
                
                if (choice == 'y' || choice == 'Y') {
                    // Yêu cầu nhập mật khẩu để kích hoạt
                    int attempts = 0;
                    while (attempts < 3) {
                        std::string password;
                        std::cout << "Nhap mat khau de kich hoat: ";
                        std::cin >> password;
                        
                        if (acc.checkPassword(password)) {
                            acc.setStatus(0);
                            std::cout << "Tai khoan da duoc kich hoat lai!" << std::endl;
                            std::cout << "Tinh trang tai khoan moi: 0 (0 - Active, 1 - Block)" << std::endl;
                            return;
                        } else {
                            attempts++;
                            if (attempts < 3) {
                                std::cout << "Mat khau sai! Con " << (3 - attempts) << " lan thu." << std::endl;
                            }
                        }
                    }
                    std::cout << "Nhap sai mat khau qua 3 lan. Tai khoan van bi khoa!" << std::endl;
                }
            }
            return;
        }
    }
    std::cout << "Khong tim thay tai khoan!" << std::endl;
}