#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 100;
int b[MAX], c[MAX], nb, nc;

void MergeSubarr(int a[], int nb, int nc, int &pa, int &pb, int &pc, int k)
{
    int rb;
    int rc;
    rb = min(nb, pb + k);
    rc = min(nc, pb + k);
    while ((pb < rb) && (pc < rc))
    {
        if (b[pb] < c[pc])
            a[pa++] = b[pb++];
        else
            a[pa++] = c[pc++];
    }
    while (pb < rb)
    {
        a[pa++] = b[pb++];
    }
    while (pc < rc)
    {
        a[pa++] = c[pc++];
    }
}


void Distribute(int a[], int N, int &nb, int &nc, int k)
{
    int i, pa, pb, pc;
        pa = pb = pc = 0;
    while (pa < N)
    {
        for (i = 0; (pa < N) && (i < k); i++, pa++, pb++)
        {
            b[pb] = a[pa];
        }
        for (i = 0; (pa < N) && (i < k); i++, pa++, pc++)
        {
            c[pc] = a[pa];
        }
    }
    nb = pb;
    nc = pc;
}
void Merge(int a[], int nb, int nc, int k)
{
    int pa, pb, pc;
    pa = pb = pc = 0;
    while ((pb < nb) && (pc < nc))
    {
        MergeSubarr(a, nb, nc, pa, pb, pc, k);
    }
    while (pb < nb)
    {
        a[pa++] = b[pb++];
    }
    while (pc < nc)
    {
        a[pa++] = c[pc++];
    }
}

void MergeSort(int a[], int N) {
    int k;
    for (k = 1; k < N; k *= 2) {
        Distribute(a, N, nb, nc, k);
        Merge(a, nb, nc, k);
    }
}
// Sắp xếp dãy trên theo thứ tự giá trị tuyệt đối tăng dần.
void MergeSortGTTD(int a[], int N) {
    int k;
    for (k = 1; k < N; k *= 2) {
        Distribute(a, N, nb, nc, k);
        Merge(a, nb, nc, k);
    }
    // Sort by absolute values using a simple bubble sort for demonstration
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (abs(a[j]) > abs(a[j + 1])) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void timsolonthuba(int a[], int n, int &kq) {
    MergeSort(a, n);  // Sort in ascending order
    
    int count = 1; // Initialize count
    int sotruoc = a[n-1];  // Start from solonnhat (last element since ascending)
    kq = -1;        // Default if no third solonnhat exists
    
    for(int i = n-2; i >= 0 && count < 3; i--) {
        if(a[i] != sotruoc) {
            count++;
            sotruoc = a[i];
            if(count == 3) {
                kq = a[i];
                return;
            }
        }
    }
}
void SoPTLonNhat(int a[], int n, int &count) {
    MergeSort(a, n);  // Sort ascending
    
    count = 1;  // Initialize count
    int solonnhat = a[n-1];  // Last element is solonnhat
    
    // Count backwards from second-to-last element
    for(int i = n-2; i >= 0; i--) {
        if(a[i] == solonnhat) {
            count++;
        } else {
            break;  // Stop when we find different number
        }
    }
}
//Câu 5
// void SortArray(int a[], int n) {
//     vector<int> soduong;
//     vector<int> soam;

//     // Separate positive and negative numbers
//     for (int i = 0; i < n; i++) {
//         if (a[i] >= 0) {
//             soduong.push_back(a[i]);
//         } else {
//             soam.push_back(a[i]);
//         }
//     }

//     // Sort positive numbers in descending order
//     sort(soduong.begin(), soduong.end(), greater<int>());

//     // Sort negative numbers in ascending order
//     sort(soam.begin(), soam.end());

//     // Merge sorted arrays back into original array
//     int index = 0;
//     for (size_t  i = 0; i < soduong.size(); i++) {
//         a[index++] = soduong[i];
//     }
//     for (size_t  i = 0; i < soam.size(); i++) {
//         a[index++] = soam[i];
//     }
// }

//Cau 6
// void SortArray(int a[], int n) {
//     vector<int> chan;
//     vector<int> le;

//     // Separate chan and le numbers
//     for (int i = 0; i < n; i++) {
//         if (a[i] % 2 == 0) {
//             chan.push_back(a[i]);
//         } else {
//             le.push_back(a[i]);
//         }
//     }

//     // Sort chan numbers in ascending order
//     sort(chan.begin(), chan.end());

//     // Sort le numbers in descending order
//     sort(le.begin(), le.end(), greater<int>());

//     // Merge sorted arrays back into original array
//     int index = 0;
//     for (size_t i = 0; i < chan.size(); i++) {
//         a[index++] = chan[i];
//     }
//     for (size_t i = 0; i < le.size(); i++) {
//         a[index++] = le[i];
//     }
// }
//Cau 7
// void SortPreserveParity(int a[], int n) {
//     vector<int> chan, le;
//     vector<size_t> chan_codinh, le_codinh;
    
//     // Store numbers and their positions based on parity
//     for (int i = 0; i < n; i++) {
//         if (a[i] % 2 == 0) {
//             chan.push_back(a[i]);
//             chan_codinh.push_back(i);
//         } else {
//             le.push_back(a[i]);
//             le_codinh.push_back(i);
//         }
//     }
    
//     // Sort chan ascending, le descending
//     sort(chan.begin(), chan.end());  // 2,4,6
//     sort(le.begin(), le.end(), greater<int>());  // 7,5,3,1,1
    
//     // Place back maintaining original positions
//     for (size_t i = 0; i < chan.size(); i++) {
//         a[chan_codinh[i]] = chan[i];
//     }
//     for (size_t i = 0; i < le.size(); i++) {
//         a[le_codinh[i]] = le[i];
//     }
// }
//Cau 8
struct Student {
    int stt;
    string mssv;
    string hoTen;
    int namSinh;
};
string LayTen(const string& fullName) {
    // Find last space to get first name
    size_t lastSpace = fullName.rfind(' ');
    if (lastSpace != string::npos) {
        return fullName.substr(lastSpace + 1);
    }
    return fullName;
}

void danhsachsinhvien(const vector<Student> &dsSinhVien)
{
    cout << setw(5) << "STT" // setw(5) là gì? trả lời: setw(5) là hàm set width, dùng để set độ rộng của cột, trong trường hợp này là set độ rộng của cột STT là 5
        << setw(10) << "MSSV"
        << setw(25) << "Ho va ten"
        << setw(10) << "Nam sinh" << endl;
    cout << string(50, '-') << endl;

    for (const auto &sv : dsSinhVien)
    {
        cout << setw(5) << sv.stt
            << setw(10) << sv.mssv
            << setw(25) << sv.hoTen
            << setw(10) << sv.namSinh << endl;
    }
}
//Cau 9
void radixSortMSSV(vector<Student>& dsSinhVien) {
    vector<Student> output(dsSinhVien.size());
    int max_mssv = 0;
    
    // Find max MSSV
    for(const auto& sv : dsSinhVien) {
        max_mssv = max(max_mssv, stoi(sv.mssv));
    }
    
    // Do counting sort for every digit
    for(int exp = 1; max_mssv/exp > 0; exp *= 10) {
        vector<int> count(10, 0);
        
        // Store count of occurrences
        for(const auto& sv : dsSinhVien) {
            count[(stoi(sv.mssv)/exp)%10]++;
        }
        
        // Change count[i] to actual position
        for(int i = 1; i < 10; i++) {
            count[i] += count[i-1];
        }
        
        // Build output array
        for(int i = dsSinhVien.size()-1; i >= 0; i--) {
            output[count[(stoi(dsSinhVien[i].mssv)/exp)%10]-1] = dsSinhVien[i];
            count[(stoi(dsSinhVien[i].mssv)/exp)%10]--;
        }
        
        // Copy output array to dsSinhVien
        dsSinhVien = output;
    }
}
//Cau 10
void Sapxeptenvanam(vector<Student>& dsSinhVien) {
    sort(dsSinhVien.begin(), dsSinhVien.end(), 
        [](const Student& a, const Student& b) {
            string TenA = LayTen(a.hoTen);
            string TenB = LayTen(b.hoTen);
            if (TenA != TenB)
                return TenA < TenB;
            return a.namSinh < b.namSinh;
        });
}
int main() {
    int a[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
    int n = sizeof(a) / sizeof(a[0]);
    // MergeSort(a, n);
    //     for (int i = 0; i < n; i++)
    //     {
    //     cout << a[i] << " ";
    //     }
    // MergeSortGTTD(a, n);
    // cout << "\nSorted by absolute values: ";
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // SortPreserveParity(a, n);
    // cout << "\nSorted array: ";
    // for (int i = 0; i < n; i++) { //giải thích for (int i = 0; i < n; i++) là gì? trả lời: vòng lặp for (int i = 0; i < n; i++) là vòng lặp duyệt qua các phần tử của mảng a,cách hoạt động của vòng lặp này là duyệt qua từ phần tử đầu tiên đến phần tử cuối cùng của mảng a
    //     cout << a[i] << " ";
    // }
    // int solonthuba;
    // timsolonthuba(a, n, solonthuba);
    // cout << "\nThird solonnhat distinct number is: " << solonthuba;
    // int count;
    // SoPTLonNhat(a, n, count);
    // cout << "\nSo luong phan tu lon nhat: " << count;
    vector<Student> dsSinhVien = {
        {1, "1005", "Tran Minh Thanh", 1991},
        {2, "1001", "Tran Thi Bich", 1988},
        {3, "1003", "Tran Minh Thanh", 1990},
        {4, "1000", "Vo Quang Vinh", 1990},
        {5, "1008", "Nguyen Van An", 1990}
    };
    
    cout << "Danh sach sinh vien:\n";
    danhsachsinhvien(dsSinhVien);
    radixSortMSSV(dsSinhVien);
    cout << "\nDanh sach sau khi sap xep theo MSSV:\n";
    danhsachsinhvien(dsSinhVien);
    Sapxeptenvanam(dsSinhVien);
    cout << "\nDanh sach sau khi sap xep theo ten va nam sinh:\n";
    danhsachsinhvien(dsSinhVien);

    return 0;
}
