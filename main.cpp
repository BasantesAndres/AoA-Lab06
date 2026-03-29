#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <iomanip>
#include <cmath>

using namespace std;

// ======================================================
// UTILIDADES
// ======================================================

void printLine() {
    cout << "============================================================\n";
}

void printVector(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

// ======================================================
// PARTE 2: MERGE SORT
// ======================================================

void mergeVec(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {   // <= mantiene estabilidad
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeVec(arr, left, mid, right);
}

void mergeSortDemo() {
    printLine();
    cout << "PART 2 - MERGE SORT IMPLEMENTATION\n";
    printLine();

    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array:\n";
    printVector(arr);

    mergeSort(arr, 0, (int)arr.size() - 1);

    cout << "Sorted array with Merge Sort:\n";
    printVector(arr);
    cout << "\n";
}

// ======================================================
// PARTE 3: ESTABILIDAD DE MERGE SORT
// ======================================================

struct Item {
    int key;
    string label;
};

void printItems(const vector<Item>& items) {
    for (const auto& item : items) {
        cout << "(" << item.key << "," << item.label << ") ";
    }
    cout << "\n";
}

void mergeItems(vector<Item>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Item> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].key <= R[j].key) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortItems(vector<Item>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSortItems(arr, left, mid);
    mergeSortItems(arr, mid + 1, right);
    mergeItems(arr, left, mid, right);
}

void stabilityDemo() {
    printLine();
    cout << "PART 3 - TESTING STABILITY OF MERGE SORT\n";
    printLine();

    vector<Item> items = {
        {5, "A"},
        {3, "B"},
        {5, "C"},
        {2, "D"},
        {3, "E"},
        {5, "F"}
    };

    cout << "Original items:\n";
    printItems(items);

    mergeSortItems(items, 0, (int)items.size() - 1);

    cout << "Sorted items by key:\n";
    printItems(items);
    cout << "\n";

    cout << "Observation:\n";
    cout << "Items with the same key preserve their original relative order.\n";
    cout << "For key = 5, the order remains A, C, F.\n";
    cout << "Therefore, Merge Sort is STABLE.\n\n";
}

// ======================================================
// PARTE 4: QUICK SORT
// ======================================================

int partitionVec(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionVec(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> generateRandomVector(int n, int minVal = 1, int maxVal = 100000) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(minVal, maxVal);

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }
    return arr;
}

void quickSortDemo() {
    printLine();
    cout << "PART 4 - QUICK SORT IMPLEMENTATION\n";
    printLine();

    vector<int> arr = generateRandomVector(20, 1, 100);

    cout << "Random array before Quick Sort:\n";
    printVector(arr);

    quickSort(arr, 0, (int)arr.size() - 1);

    cout << "Array after Quick Sort:\n";
    printVector(arr);

    cout << "Is sorted? " << (isSorted(arr) ? "YES" : "NO") << "\n\n";
}

// ======================================================
// PARTE 5: ANALISIS EMPIRICO DE QUICK SORT
// ======================================================

double measureQuickSortTime(int n) {
    vector<int> arr = generateRandomVector(n);

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, (int)arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

void empiricalAnalysisQuickSort() {
    printLine();
    cout << "PART 5 - EMPIRICAL ANALYSIS OF QUICK SORT\n";
    printLine();

    vector<int> sizes = {1000, 5000, 10000, 20000, 50000, 100000};

    cout << left << setw(12) << "n"
         << setw(18) << "time(ms)"
         << setw(18) << "n*log2(n)"
         << "\n";

    printLine();

    for (int n : sizes) {
        double timeMs = measureQuickSortTime(n);
        double nlogn = n * log2((double)n);

        cout << left << setw(12) << n
             << setw(18) << fixed << setprecision(4) << timeMs
             << setw(18) << fixed << setprecision(2) << nlogn
             << "\n";
    }

    cout << "\nConclusion:\n";
    cout << "For random inputs, Quick Sort should behave approximately like O(n log n).\n";
    cout << "The empirical times generally follow that trend, although exact times may vary.\n\n";
}

// ======================================================
// MAIN
// ======================================================

int main() {
    cout << "ANALYSIS OF ALGORITHMS - LAB 06\n";
    cout << "Parts 2, 3, 4 and 5 only\n\n";

    mergeSortDemo();
    stabilityDemo();
    quickSortDemo();
    empiricalAnalysisQuickSort();

    printLine();
    cout << "END OF PROGRAM\n";
    printLine();

    return 0;
}