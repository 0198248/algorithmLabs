#include <iostream>
#include <chrono>
#include <vector>

//bubble sort
void bubbleSort(std::vector<int>& arr) {
    int length = arr.size();
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int searching(std::vector<int>& arr, int num) {
    int length = arr.size();
    for (int i = 0; i < length; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}
void printArray(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void createArray(std::vector<int>& arr, int count) {
    for (int i = count; i > 0; i--) {
        arr.push_back(i);
    }
}



int main() {
    //сортування 1
    std::vector<int> array1;

    int n1 = 1000;
    createArray(array1, n1);
    std::cout << "(bubble sort)count = " << n1 << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(array1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    float result1 = duration.count();
    std::cout << "Time: " << duration.count() << " seconds\n";

    //сортування 2
    std::vector<int> array2;
    int n2 = 10000;
    createArray(array2, n2);
    std::cout << "(bubble sort)count = " << n2 << std::endl;

    start = std::chrono::high_resolution_clock::now();
    bubbleSort(array2);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    float result2 = duration.count();
    std::cout << "Time: " << duration.count() << " seconds\n";
    std::cout << "Diffrence between results: " << result2 / result1 << " times\n";
    std::cout << "Diffrence between data-in: " << n2 / n1 << " times\n";

    //пошук 1
    std::vector<int> array3;
    int n3 = 1000;
    createArray(array3, n3);
    std::cout << "(search)count = " << n3 << std::endl;

    start = std::chrono::high_resolution_clock::now();
    int res1 = searching(array3, 1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "number finded in position: " << res1 << std::endl;
    duration = end - start;
    float result3 = duration.count();
    std::cout << "Time: " << duration.count() << " seconds\n";

    //пошук 2
    std::vector<int> array4;
    int n4 = 10000;
    createArray(array4, n4);
    std::cout << "(search)count = " << n4 << std::endl;

    start = std::chrono::high_resolution_clock::now();
    int res2 = searching(array4, 1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "number finded in position: " << res2 << std::endl;
    duration = end - start;
    float result4 = duration.count();
    std::cout << "Time: " << duration.count() << " seconds\n";
    std::cout << "Diffrence between results: " << result4 / result3 << " times\n";
    std::cout << "Diffrence between data-in: " << n4 / n3 << " times\n";
}