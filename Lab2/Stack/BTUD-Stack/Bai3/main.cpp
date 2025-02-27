#include "TrainMovement.h"
#include "TrainMovement.cpp"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong toa: ";
    cin >> n;

    vector<int> targetOrder(n);
    cout << "Nhap thu tu toa (cach nhau boi khoang trang): ";
    for (int i = 0; i < n; i++) {
        cin >> targetOrder[i];
    }

    TrainMovement solver(n, targetOrder);
    if (!solver.findSolution()) {
        cout << "Khong co giai phap!" << endl;
    }

    return 0;
}