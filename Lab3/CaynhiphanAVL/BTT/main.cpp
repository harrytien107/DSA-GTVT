#include "Dictionary.h"
#include "Dictionary.cpp"
#include "Node.h"
#include "AVLTree.h"
#include "AVLTree.cpp"
#include "Word.h"
#include <iostream>
#include <limits>

using namespace std;
int main() {
    Dictionary dict;
    int choice;
    string eng, vie;

    while (true) {
        cout << "\n===== Tu dien Anh-Viet =====\n";
        cout << "1. Them tu\n";
        cout << "2. Tim kiem tu\n";
        cout << "3. Sua tu\n";
        cout << "4. Hien thi tat ca tu\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Xóa cờ lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua bộ đệm
            cout << "Nhap sai. Vui long nhap so tu 1 den 5.\n";
            continue;
        }
        switch (choice) {
            case 1:
                cout << "Nhap tu Anh: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, eng);
                cout << "Nhap nghia tieng Viet: ";
                getline(cin, vie);
                dict.addWord(eng, vie);
                cout << "Them tu thanh cong.\n";
                break;
            case 2:
                cout << "Nhap tu Anh: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, eng);
                if (dict.lookupWord(eng, vie)) {
                    cout << "Nghia tieng Viet: " << vie << "\n";
                } else {
                    cout << "Tu khong tim thay.\n";
                }
                break;
            case 3:
                cout << "Nhap tu Anh: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, eng);
                cout << "Nhap nghia tieng Viet: ";
                getline(cin, vie);
                if (dict.modifyWord(eng, vie)) {
                    cout << "Sua tu thanh cong.\n";
                } else {
                    cout << "Tu khong tim thay.\n";
                }
                break;
            case 4:
                cout << "\nNoi dung tu dien:\n";
                dict.displayAll();
                break;
            case 5:
                cout << "Thoat chuong trinh. Tam biet!\n";
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    }

    return 0;
}