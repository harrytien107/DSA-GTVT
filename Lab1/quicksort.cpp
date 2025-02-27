/* 1. Bổ sung các hàm trên vào chương trình mẫu (CacThuatToanSapXep) đồng thời thay đổi hàm
main và file input để sắp xếp dãy số nguyên sau tăng dần:
42 23 74 11 65 58 94 36 99 87  */
// #include <iostream>
// #include <fstream>
// using namespace std;

// void Swap(int &a, int &b) {
//     int c = a;
//     a = b;
//     b = c;
// }

// void QuickSort(int a[], int left, int right) {
//     int i, j, x;
//     if (left >= right) {
//         return;
//     }

//     x = a[(left + right)/2];  // Chọn phần tử giữa làm giá trị mốc
//     i = left;
//     j = right;

//     while(i < j) {
//         while(a[i] < x) {
//             i++;
//         }
//         while(a[j] > x) {
//             j--;
//         }
//         if(i <= j) {
//             Swap(a[i], a[j]);
//             i++;
//             j--;
//         }
//     }

//     QuickSort(a, left, j);
//     QuickSort(a, i, right);
// }

// int main() {
// 	ifstream fin;
// 	fin.open("D:\\CODE\\BaitapC++\\Cauttrucgiaithuat\\Lab1\\input.txt");
// 	if (!fin.is_open())
// 	{
// 		cout << "ko mo dc\n";
// 		return -1;
// 	}
//     ofstream fout("D:\\CODE\\BaitapC++\\Cauttrucgiaithuat\\Lab1\\output.txt");

//     int a[50];
//     int n = 0;
//     while(fin >> a[n]) {
//         n++;
//     }
//     QuickSort(a, 0, n-1);
//     for(int i = 0; i < n; i++) {
//         fout << a[i] << " ";
//     }
//     fin.close();
//     fout.close();
//     return 0;
// }

/* 2. Sửa lại chương trình để đếm số phép gán và số phép so sánh sự dụng trong hàm QuickSort.  */
#include <iostream>
#include <fstream>
using namespace std;

void Swap(int &a, int &b, int &sophepgan) {
    int c = a;
    a = b;
    b = c;
    sophepgan += 3;
}
void QuickSort(int a[], int left, int right, int &sophepgan, int &sophepsosanh)
{
    int i, j, x;
    if (left >= right)
    {
        sophepsosanh++;
        return;
    }
    x = a[(left + right) / 2];
    // sophepgan++;
    i = left;
    j = right;
    sophepgan += 3;  // sophepgan = sophepgan + 3;
    // sophepgan += 2;
    while (i < j)
    {
        sophepsosanh++;
        while (a[i] < x)
        {
            i++;
            sophepgan++;
            sophepsosanh++;
        }
        sophepsosanh++;
        while (a[j] > x)
        {
            j--;
            sophepgan++;
            sophepsosanh++;
        }
        sophepsosanh++;
        if (i <= j)
        {
            sophepsosanh++;
            Swap(a[i], a[j], sophepgan);
            i++;
            sophepgan++;
            j--;
            sophepgan++;
        }
    }
    QuickSort(a, left, j, sophepgan, sophepsosanh);
    QuickSort(a, i, right, sophepgan, sophepsosanh);
}
int main()
{
    ifstream fin("D:\\CODE\\BaitapC++\\Cauttrucgiaithuat\\Lab1\\input.txt");
    if (!fin.is_open())
    {
        cout << "Cannot open input file\n";
        return -1;
    }
    ofstream fout("D:\\CODE\\BaitapC++\\Cauttrucgiaithuat\\Lab1\\output.txt");
    int n = 0;
    int a[50];
    while (fin >> a[n]) {
    n++;
}
    int sophepgan = 0;
    int sophepsosanh = 0;
    QuickSort(a, 0, n - 1, sophepgan, sophepsosanh);
    fout << "Sorted array is ";
    for (int i = 0; i < n; ++i)
        fout << a[i] << " ";
    fout << "\nSo phep gan: " << sophepgan;
    fout << "\nSo phep so sanh: " << sophepsosanh;
    return 0;
}

