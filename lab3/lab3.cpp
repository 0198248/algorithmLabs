#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

int linearSearch(const vector<int>& arr, int value) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertA(vector<int>& arr, int index, int value) {
    if (index < 0 || index > arr.size()) return;
    arr.insert(arr.begin() + index, value);
}

void removeA(vector<int>& arr, int index) {
    if (index < 0 || index >= arr.size()) return;
    arr.erase(arr.begin() + index);
}

void dictionaryDemo() {
    unordered_map<int, int> dict;

    dict[1] = 10;
    dict[2] = 20;

    dict[1] = 100;

    if (dict.find(1) != dict.end()) {
        cout << "Key 1 value: " << dict[1] << endl;
    }

    dict.erase(2);
}


void statistics(const vector<int>& arr) {
    int minVal = arr[0];
    int maxVal = arr[0];
    double sum = 0;

    for (int x : arr) {
        if (x < minVal) minVal = x;
        if (x > maxVal) maxVal = x;
        sum += x;
    }

    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;
    cout << "Average: " << sum / arr.size() << endl;
}


void countElements(const vector<int>& arr) {
    unordered_map<int, int> freq;

    for (int x : arr) {
        freq[x]++;
    }

    cout << "Element frequencies:" << endl;
    for (auto& p : freq) {
        if (p.second > 1) {
            cout << p.first << " -> " << p.second << endl;
        }
    }
}


template<typename Func, typename... Args>
double Timer(Func f, Args... args) {
    auto start = chrono::high_resolution_clock::now();
    f(args...);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}


int main() {

    vector<int> arr;

    for (int i = 10000; i > 0; i--) {
        arr.push_back(i);
    }

    cout << "search time:" << Timer(linearSearch, arr, 1) << endl;

    cout << "sort time: " << Timer(bubbleSort, arr) << endl;

    cout << "insert / remove";
    insertA(arr, 8, 999);
    removeA(arr, 5);

    cout << endl << "dictionary: " << endl;
    dictionaryDemo();

    cout << endl << "statistics: " << endl;
    statistics(arr);

    cout << endl << "grouping: " << endl;
    countElements(arr);

    return 1;
}