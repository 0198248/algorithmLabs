#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
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
        bubbleSort(arr1, size);
        auto end = high_resolution_clock::now();

        auto durationBubble = duration_cast<milliseconds>(end - start);

        start = high_resolution_clock::now();
        insertionSort(arr2, size);
        end = high_resolution_clock::now();

        auto durationInsertion = duration_cast<milliseconds>(end - start);

        cout << "Size: " << size << endl;
        cout << "Bubble Sort: " << durationBubble.count() << " ms" << endl;
        cout << "Insertion Sort: " << durationInsertion.count() << " ms" << endl;
        cout << "--------------------------" << endl;

        delete[] arr1;
        delete[] arr2;
    }

    return 0;
}