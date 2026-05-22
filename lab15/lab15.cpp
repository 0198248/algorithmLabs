#include <iostream>
#include <vector>
#include <list>
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

class HashTable {

private:

	int tableSize;

	vector<list<int>> table;

	int hashFunction(int key) {

		return key % tableSize;
	}

public:

	HashTable(int size) {

		tableSize = size;

		table.resize(tableSize);
	}

	void insert(int key) {

		int index = hashFunction(key);

		table[index].push_back(key);
	}

	bool search(int key) {

		int index = hashFunction(key);

		for (int value : table[index]) {

			if (value == key) {

				return true;
			}
		}

		return false;
	}

	void remove(int key) {

		int index = hashFunction(key);

		table[index].remove(key);
	}

	void print() {

		for (int i = 0; i < tableSize; i++) {

			cout << i << ": ";

			for (int value : table[i]) {

				cout << value << " ";
			}

			cout << endl;
		}
	}
};

int main() {

	setlocale(LC_ALL, "uk_UA");

	HashTable ht(10);

	ht.insert(15);
	ht.insert(25);
	ht.insert(35);

	ht.insert(7);
	ht.insert(17);

	cout << "HASH TABLE:\n\n";

	ht.print();

	cout << "\nПОШУК 25:\n";

	if (ht.search(25)) {

		cout << "Елемент знайдено\n";
	}
	else {

		cout << "Елемент не знайдено\n";
	}

	cout << "\nВидалення 25\n";

	ht.remove(25);

	cout << "\nhash table після видалення:\n\n";

	ht.print();

	const int N = 100000;

	HashTable bigTable(10007);

	Timer insertTimer;

	for (int i = 0; i < N; i++) {

		bigTable.insert(i);
	}

	insertTimer.end();

	Timer searchTimer;

	bigTable.search(N - 1);

	searchTimer.end();

	Timer removeTimer;

	bigTable.remove(N - 1);

	removeTimer.end();

	cout << "Кількість елементів: "
		<< N
		<< endl << endl;

	cout << "INSERT: "
		<< insertTimer.result()
		<< " мікросекунд\n";

	cout << "SEARCH: "
		<< searchTimer.result()
		<< " мікросекунд\n";

	cout << "REMOVE: "
		<< removeTimer.result()
		<< " мікросекунд\n";

	return 0;
}