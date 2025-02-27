#include <iostream>
#include <fstream>
using namespace std;

void Swap(int &a, int &b) {
    int c = a; 
    a = b; 
    b = c;
}

void SelectionSort(int a[], int N) { 
    int min;
    for (int i = 0; i < N - 1; i++) { 
        min = i;
        for (int j = i + 1; j < N; j++) { 
            if (a[j] > a[min]) {
                min = j;
            }
        }
        if (min != i) {
            Swap(a[min], a[i]);
        }
    }
}

int main() {
    int x[10];
    int n = 0;  
    ifstream fin("D:\\CODE\\BaitapC++\\Cauttrucgiaithuat\\Lab1\\input.txt");
    ofstream fout("D:\\CODE\\BaitapC++\\Cauttrucgiaithuat\\Lab1\\output.txt");
    while (fin >> x[n]) {
        n++;
    }

    SelectionSort(x, n);
        for (int i = 0; i < n; i++) {
        fout << x[i] << " ";
    }
    
    fin.close();
    fout.close();
    return 0;
}

