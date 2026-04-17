#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
using namespace chrono;

void countingSort(int arr[], int n) {
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;

    int* count = new int[range]();

    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i]--) {
            arr[index++] = i + min;
        }
    }

    delete[] count;
}

void insertionSortVector(vector<int>& bucket) {
    for (int i = 1; i < bucket.size(); i++) {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(int arr[], int n) {
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int bucketCount = 10;
    vector<vector<int>> buckets(bucketCount);

    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min) * bucketCount / (max - min + 1);
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < bucketCount; i++) {
        insertionSortVector(buckets[i]);
    }

    int k = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int x : buckets[i]) {
            arr[k++] = x;
        }
    }
}

void generateSame(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 5;
}

void generateWide(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000000;
}

void generateUniform(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}

int main() {
    srand(time(NULL));
    const int size = 10000;

    int* arr1 = new int[size];
    int* arr2 = new int[size];

    generateUniform(arr1, size);

    for (int i = 0; i < size; i++)
        arr2[i] = arr1[i];

    auto start = high_resolution_clock::now();
    countingSort(arr1, size);
    auto end = high_resolution_clock::now();
    auto t1 = duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();
    bucketSort(arr2, size);
    end = high_resolution_clock::now();
    auto t2 = duration_cast<microseconds>(end - start);

    cout << "Counting: " << t1.count() << endl;
    cout << "Bucket: " << t2.count() << endl;

    delete[] arr1;
    delete[] arr2;
}