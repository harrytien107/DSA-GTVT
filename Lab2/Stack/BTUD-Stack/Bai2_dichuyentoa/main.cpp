#include "TrainMovement.h"
#include "TrainMovement.cpp"
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so toa tau: ";
    cin >> n;

    vector<int> targetOrder(n);
    cout << "Nhap thu tu dich (cach nhau boi dau cach): ";
    for (int i = 0; i < n; i++) {
        cin >> targetOrder[i];
    }

    TrainMovement solver(n, targetOrder);
    if (!solver.findSolution()) {
        cout << "Khong tim thay giai phap!" << endl;
    }

    return 0;
}