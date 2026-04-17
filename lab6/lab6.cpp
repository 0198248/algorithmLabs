#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

int main() {
    const int sizes[] = { 100, 1000, 10000 };

    for (int size : sizes) {
        int* arr1 = new int[size];
        int* arr2 = new int[size];

        fillArray(arr1, size);

        for (int i = 0; i < size; i++)
            arr2[i] = arr1[i];

        auto start = high_resolution_clock::now();
        quickSort(arr1, 0, size - 1);
        auto end = high_resolution_clock::now();
        auto quickTime = duration_cast<milliseconds>(end - start);

        start = high_resolution_clock::now();
        shellSort(arr2, size);
        end = high_resolution_clock::now();
        auto shellTime = duration_cast<milliseconds>(end - start);

        cout << "Розмір: " << size << endl;
        cout << "Quick Sort: " << quickTime.count() << " ms" << endl;
        cout << "Shell Sort: " << shellTime.count() << " ms" << endl;
        cout << "--------------------------" << endl;

        delete[] arr1;
        delete[] arr2;
    }

    return 0;
}