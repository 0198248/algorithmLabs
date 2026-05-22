#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Timer {

	chrono::time_point<chrono::high_resolution_clock> startTime;
	chrono::time_point<chrono::high_resolution_clock> endTime;
	chrono::duration<double, micro> duration;

	void start() {
		startTime = chrono::high_resolution_clock::now();
	}

	void end() {
		endTime = chrono::high_resolution_clock::now();
		duration = endTime - startTime;
	}

	double result() {
		return duration.count();
	}

	Timer() {
		start();
	}
};

int linearSearch(const vector<int>& arr,
	int target) {

	for (int i = 0; i < arr.size(); i++) {

		if (arr[i] == target) {

			return i;
		}
	}

	return -1;
}

int binarySearch(const vector<int>& arr,
	int target) {

	int left = 0;

	int right = arr.size() - 1;

	while (left <= right) {

		int middle = left +
			(right - left) / 2;

		if (arr[middle] == target) {

			return middle;
		}

		if (target < arr[middle]) {

			right = middle - 1;
		}

		else {

			left = middle + 1;
		}
	}

	return -1;
}

int main() {

	setlocale(LC_ALL, "uk_UA");

	const int N = 1000000;

	vector<int> arr;

	for (int i = 0; i < N; i++) {

		arr.push_back(i);
	}

	int target = N - 1;

	Timer linearTimer;

	int linearResult =
		linearSearch(arr, target);

	linearTimer.end();


	Timer binaryTimer;

	int binaryResult =
		binarySearch(arr, target);

	binaryTimer.end();

	cout << "Розмір масиву: "
		<< N
		<< endl << endl;

	cout << "Шуканий елемент: "
		<< target
		<< endl << endl;

	cout << "Лінійний пошук:\n";

	cout << "Індекс: "
		<< linearResult
		<< endl;

	cout << "Час: "
		<< linearTimer.result()
		<< " мікросекунд\n\n";

	cout << "Бінарний пошук:\n";

	cout << "Індекс: "
		<< binaryResult
		<< endl;

	cout << "Час: "
		<< binaryTimer.result()
		<< " мікросекунд\n";

	return 0;
}