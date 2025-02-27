// //1. Trả lời các dòng lệnh có yêu cầu ghi chú. 
// int b[MAX], c[MAX], nb, nc; // Ghi chú: 2 mảng này dùng để làm gì? trả lời: dùng để chia mảng a thành 2 mảng con b và c
// void Distribute(int a[], int N, int &nb, int &nc, int k)
// {
//     int i, pa, pb, pc; // Ghi chú: các biến này có ý nghĩa gì? trả lời: pa là biến đếm số phần tử đã chia, pb là biến đếm số phần tử đã chia vào mảng b, pc là biến đếm số phần tử đã chia vào mảng c
//     pa = pb = pc = 0;
//     while (pa < N)
//     {
//         for (i = 0; (pa < N) && (i < k); i++, pa++, pb++)
//         { // Ghi chú: vòng lặp for (i = 0; (pa < N) && (i < k); i++, pa++, pb++) có ý nghĩa gì? vòng lặp này dùng để chia mảng a thành mảng b với số phần tử là k" và số phần tử còn lại chia vào mảng c với số phần tử là N - k (N là số phần tử của mảng a)
//             b[pb] = a[pa];
//         }
//         for (i = 0; (pa < N) && (i < k); i++, pa++, pc++)
//         { // Ghi chú: vòng lặp for (i = 0; (pa < N) && (i < k); i++, pa++, pc++) có ý nghĩa gì? vòng lặp này dùng để chia mảng a thành mảng c với số phần tử là k" và số phần tử còn lại chia vào mảng b với số phần tử là N - k (N là số phần tử của mảng a)
//             c[pc] = a[pa];
//         }
//     }
//     nb = pb;
//     nc = pc;
// }
// void Merge(int a[], int nb, int nc, int k)
// {
//     int pa, pb, pc;
//     pa = pb = pc = 0;
//     while ((pb < nb) && (pc < nc))
//     {
//         MergeSubarr(a, nb, nc, pa, pb, pc, k);
//     }
//     while (pb < nb)
//     {
//         a[pa++] = b[pb++]; // Ghi chú: câu lệnh này có ý nghĩa gì? câu lệnh này dùng để ghi phần tử của mảng b vào mảng a
//     }
//     while (pc < nc)
//     {
//         a[pa++] = c[pc++]; // Ghi chú: câu lệnh này có ý nghĩa gì? câu lệnh này dùng để ghi phần tử của mảng c vào mảng a
//     }
// }
// void MergeSubarr(int a[], int nb, int nc, int &pa, int &pb, int &pc, int k)
// {
//     int rb;
//     int rc;
//     rb = min(nb, pb + k);
//     rc = min(nc, pb + k);
//     while ((pb < rb) && (pc < rc))
//     {
//         if (b[pb] < c[pc])
//             a[pa++] = b[pb++];
//         else
//             a[pa++] = c[pc++];
//     }
//     while (pb < rb)
//     {
//         a[pa++] = b[pb++];
//     }
//     while (pc < rc)
//     {
//         a[pa++] = c[pc++];
//     }
// }

// 2. Cho biết chức năng của từng hàm trên. 
// trả lời:
// - Distribute: chia mảng a thành 2 mảng con b và c
// - Merge: trộn 2 mảng con b và c thành mảng a
// - MergeSubarr: trộn 2 mảng con b và c thành mảng a
/* 3. Bổ sung các hàm cần thiết vào chương trình mẫu (CacThuatToanSapXep) và viết hàm void
MergeSort(int a[], int N); để sắp xếp dãy số nguyên sau tăng dần.
5 2 9 3 7 2 4 11  */
#include <iostream>
#include <fstream>
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
//tang dan
void MergeSort(int a[], int N)
{
    int k = 1;
    while (k < N)
    {
        Distribute(a, N, nb, nc, k);
        Merge(a, nb, nc, k);
        k *= 2;
    }
}
/* or void MergeSort(int a[], int N) {
    int k;
    for (k = 1; k < N; k *= 2) {
        Distribute(a, N, nb, nc, k);
        Merge(a, nb, nc, k);
    }
} */
//giam dan
// void MergeSort(int a[], int N)
// {
//     int k = 1;
//     while (k < N)
//     {
//         Distribute(a, N, nb, nc, k);
//         Merge(a, nb, nc, k);
//         k *= 2;
//     }
//     for (int i = 0; i < N / 2; i++)
//     {
//         swap(a[i], a[N - i - 1]);
//     }
// }

int main()
{
    int a[] = {5, 2, 9, 3, 7, 2, 4, 11};
    int n = sizeof(a) / sizeof(a[0]);
        MergeSort(a, n);
        for (int i = 0; i < n; i++)
        {
        cout << a[i] << " ";
        }
        return 0;
    }

// 4. Sửa lại chương trình để sắp xếp dãy số trên giảm dần. 
void MergeSort(int a[], int N) {
    int k;
    for (k = 1; k < N; k *= 2) {
        Distribute(a, N, nb, nc, k);
        Merge(a, nb, nc, k);
    }
    for (int i = 0; i < N / 2; i++)
    {
        swap(a[i], a[N - i - 1]);
    }
}
