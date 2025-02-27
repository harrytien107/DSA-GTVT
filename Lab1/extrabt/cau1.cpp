#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Global counters
struct Counter {
    long long sophepsosanh = 0;
    long long sophepgan = 0;
};

class SortingAnalyzer {
private:
    // Selection Sort
    static void selectionSort(vector<int>& arr, Counter& counter) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                counter.sophepsosanh++;
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                swap(arr[i], arr[min_idx]);
                counter.sophepgan += 3; // swap uses 3 sophepgan
            }
        }
    }

    // Heap Sort helpers
    static void heapify(vector<int>& arr, int n, int i, Counter& counter) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        counter.sophepsosanh++;
        if (left < n && arr[left] > arr[largest])
            largest = left;

        counter.sophepsosanh++;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            counter.sophepgan += 3;
            heapify(arr, n, largest, counter);
        }
    }

    static void heapSort(vector<int>& arr, Counter& counter) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i, counter);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            counter.sophepgan += 3;
            heapify(arr, i, 0, counter);
        }
    }

    // Quick Sort
    static int partition(vector<int>& arr, int low, int high, Counter& counter) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            counter.sophepsosanh++;
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
                counter.sophepgan += 3;
            }
        }
        swap(arr[i + 1], arr[high]);
        counter.sophepgan += 3;
        return i + 1;
    }

    static void quickSort(vector<int>& arr, int low, int high, Counter& counter) {
        if (low < high) {
            int pi = partition(arr, low, high, counter);
            quickSort(arr, low, pi - 1, counter);
            quickSort(arr, pi + 1, high, counter);
        }
    }

    // Merge Sort
    static void merge(vector<int>& arr, int left, int mid, int right, Counter& counter) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            counter.sophepsosanh++;
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
            counter.sophepgan++;
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
            counter.sophepgan++;
        }

        while (j <= right) {
            temp[k++] = arr[j++];
            counter.sophepgan++;
        }

        for (i = 0; i < k; i++) {
            arr[left + i] = temp[i];
            counter.sophepgan++;
        }
    }

    static void mergeSort(vector<int>& arr, int left, int right, Counter& counter) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid, counter);
            mergeSort(arr, mid + 1, right, counter);
            merge(arr, left, mid, right, counter);
        }
    }

public:
    static void compareThuattoans(int size) {
        vector<vector<int>> arrays(4);
        // Generate random data
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 10000);

        // Initialize arrays with same random data
        vector<int> original(size);
        for (int i = 0; i < size; i++) {
            original[i] = dis(gen);
        }

        for (int i = 0; i < 4; i++) {
            arrays[i] = original;
        }

        vector<Counter> counters(4);
        vector<double> times(4);

        // Selection Sort
        auto start = high_resolution_clock::now();
        selectionSort(arrays[0], counters[0]);
        auto stop = high_resolution_clock::now();
        times[0] = duration_cast<microseconds>(stop - start).count() / 1000.0;

        // Heap Sort
        start = high_resolution_clock::now();
        heapSort(arrays[1], counters[1]);
        stop = high_resolution_clock::now();
        times[1] = duration_cast<microseconds>(stop - start).count() / 1000.0;

        // Quick Sort
        start = high_resolution_clock::now();
        quickSort(arrays[2], 0, size - 1, counters[2]);
        stop = high_resolution_clock::now();
        times[2] = duration_cast<microseconds>(stop - start).count() / 1000.0;

        // Merge Sort
        start = high_resolution_clock::now();
        mergeSort(arrays[3], 0, size - 1, counters[3]);
        stop = high_resolution_clock::now();
        times[3] = duration_cast<microseconds>(stop - start).count() / 1000.0;

        // Print results
        cout << "\nArray size: " << size << endl;
        cout << setw(15) << "Thuattoan" << setw(15) << "Thoigian(ms)" 
             << setw(15) << "Sophepsosanh" << setw(15) << "Sophepgan" << endl;
        cout << string(60, '-') << endl;
        
        vector<string> names = {"Selection Sort", "Heap Sort", "Quick Sort", "Merge Sort"};
        for (int i = 0; i < 4; i++) {
            cout << setw(15) << names[i] 
                 << setw(15) << fixed << setprecision(3) << times[i]
                 << setw(15) << counters[i].sophepsosanh 
                 << setw(15) << counters[i].sophepgan << endl;
        }
    }
};

int main() {
    vector<int> sizes = {1000, 5000};
    for (int size : sizes) {
        SortingAnalyzer::compareThuattoans(size);
    }
    return 0;
}