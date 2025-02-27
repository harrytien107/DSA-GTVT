#include <iostream>
#include <fstream>
using namespace std;

void Swap(int &a, int &b) {
    int c = a; 
    a = b; 
    b = c;
}

void Shift(int a[], int left, int right)
{
    int x;
    int curr;
    int joint;
    curr = left;
    joint = 2 * curr + 1; 
    x = a[curr];
    while (joint <= right)
    {
        if (joint < right) 
        {
            if (a[joint] < a[joint + 1])
            {
                joint = joint + 1;
            }
        }
        if (a[joint] < x)
        {
            break; // Thỏa quan hệ liên đới
        }
        a[curr] = a[joint];
        curr = joint; // Xét khả năng hiệu chỉnh lan truyền
        joint = 2 * curr + 1;
    }
    a[curr] = x;
}

void CreateHeap(int a[], int N)
{
    int left;
    left = N / 2 - 1;
    while (left >= 0)
    {
        Shift(a, left, N - 1);
        left = left - 1;
    }
}


//tang dan
// void HeapSort(int a[], int N)
// {
//     int right;
//     CreateHeap(a, N);
//     right = N - 1;
//     while (right > 0)
//     {
//         Swap(a[0], a[right]);
//         right = right - 1;
//         Shift(a, 0, right);
//     }
// }

//giam dan
void HeapSort(int a[], int N)
{
    int right;
    CreateHeap(a, N);
    right = N - 1;
    while (right > 0)
    {
        Swap(a[0], a[right]);
        right = right - 1;
        Shift(a, 0, right);
    }
    for (int i = 0; i < N / 2; i++)
    {
        Swap(a[i], a[N - i - 1]);
    }
}


int main()
{
    int x[10];
    int n = 0;
    ifstream fin("D:\\CODE\\BaitapC++\\Cauttrucgiaithuat\\Lab1\\input.txt");
    ofstream fout("D:\\CODE\\BaitapC++\\Cauttrucgiaithuat\\Lab1\\output.txt");
    while (fin >> x[n])
    {
        n++;
    }

    HeapSort(x, n);
    for (int i = 0; i < n; i++)
    {
        fout << x[i] << " ";
    }

    fin.close();
    fout.close();
    return 0;
}
