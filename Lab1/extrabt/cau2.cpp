#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace std::chrono;

class QuickSortAnalyzer {
private:
    // QuickSort with first element as pivot
    static int partitionDautien(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;

        while (true) {
            while (i <= j && arr[i] <= pivot) i++;
            while (i <= j && arr[j] > pivot) j--;
            
            if (i >= j) break;
            swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }

    // QuickSort with middle element as pivot
    static int partitionGiua(vector<int>& arr, int low, int high) {
        int mid = low + (high - low) / 2;
        swap(arr[mid], arr[low]);
        return partitionDautien(arr, low, high);
    }

    static void quickSortDautien(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partitionDautien(arr, low, high);
            quickSortDautien(arr, low, pi - 1);
            quickSortDautien(arr, pi + 1, high);
        }
    }

    static void quickSortGiua(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partitionGiua(arr, low, high);
            quickSortGiua(arr, low, pi - 1);
            quickSortGiua(arr, pi + 1, high);
        }
    }

public:
    static void SoSanhQuickSorts(int size) {
        // Generate two identical random arrays
        vector<vector<int>> arrays(2);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 10000);

        vector<int> original(size);
        for (int i = 0; i < size; i++) {
            original[i] = dis(gen);
        }

        arrays[0] = original;
        arrays[1] = original;

        // Test first element as pivot
        auto start = high_resolution_clock::now();
        quickSortDautien(arrays[0], 0, size - 1);
        auto end = high_resolution_clock::now();
        double timeFirst = duration_cast<microseconds>(end - start).count() / 1000.0;

        // Test middle element as pivot
        start = high_resolution_clock::now();
        quickSortGiua(arrays[1], 0, size - 1);
        end = high_resolution_clock::now();
        double timeMiddle = duration_cast<microseconds>(end - start).count() / 1000.0;

        // Print results
        cout << "\nArray size: " << size << endl;
        cout << setw(25) << "Phan tu" << setw(15) << "Thoigian(ms)" << endl;
        cout << string(40, '-') << endl;
        cout << setw(25) << "Phan tu dau" << setw(15) << fixed << setprecision(3) << timeFirst << endl;
        cout << setw(25) << "Phan tu giua" << setw(15) << timeMiddle << endl;
    }
};

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};
    
    cout << "So sanh phan tu dau va giua" << endl;
    for (int size : sizes) {
        QuickSortAnalyzer::SoSanhQuickSorts(size);
    }
    
    return 0;
}