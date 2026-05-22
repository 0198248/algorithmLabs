#include <iostream>
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

// Черга на основі масиву

class Queue {
private:

	int* arr;

	int front;
	int rear;

	int capacity;
	int currentSize;

public:

	Queue(int size) {

		capacity = size;

		arr = new int[capacity];

		front = 0;
		rear = -1;

		currentSize = 0;
	}

	~Queue() {
		delete[] arr;
	}

	void enqueue(int value) {

		if (currentSize == capacity) {

			cout << "Queue overflow\n";
			return;
		}

		rear++;

		arr[rear] = value;

		currentSize++;
	}

	void dequeue() {

		if (isEmpty()) {

			cout << "Queue is empty\n";
			return;
		}

		front++;

		currentSize--;
	}

	int peek() {

		if (isEmpty()) {

			cout << "Queue is empty\n";
			return -1;
		}

		return arr[front];
	}

	bool isEmpty() {
		return currentSize == 0;
	}

	int size() {
		return currentSize;
	}

	void print() {

		for (int i = front; i <= rear; i++) {

			cout << arr[i] << " ";
		}

		cout << endl;
	}
};

// Черга на основі зв'язного списку

class LinkedListQueue {
private:

	struct Node {

		int data;
		Node* next;

		Node(int value) {

			data = value;
			next = nullptr;
		}
	};

	Node* front;
	Node* rear;

	int currentSize;

public:

	LinkedListQueue() {

		front = nullptr;
		rear = nullptr;

		currentSize = 0;
	}

	~LinkedListQueue() {

		while (!isEmpty()) {
			dequeue();
		}
	}

	void enqueue(int value) {

		Node* newNode = new Node(value);

		if (rear == nullptr) {

			front = rear = newNode;
		}
		else {

			rear->next = newNode;
			rear = newNode;
		}

		currentSize++;
	}

	void dequeue() {

		if (isEmpty()) {

			cout << "Queue is empty\n";
			return;
		}

		Node* temp = front;

		front = front->next;

		if (front == nullptr) {
			rear = nullptr;
		}

		delete temp;

		currentSize--;
	}

	int peek() {

		if (isEmpty()) {

			cout << "Queue is empty\n";
			return -1;
		}

		return front->data;
	}

	bool isEmpty() {
		return front == nullptr;
	}

	int size() {
		return currentSize;
	}

	void print() {

		Node* temp = front;

		while (temp != nullptr) {

			cout << temp->data << " ";

			temp = temp->next;
		}

		cout << endl;
	}
};

int main() {

	setlocale(LC_ALL, "uk_UA");

	cout << "Черга на основі масиву\n\n";

	Queue q1(10);

	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);

	cout << "Черга: ";
	q1.print();

	cout << "Перший елемент: "
		<< q1.peek()
		<< endl;

	q1.dequeue();

	cout << "Після dequeue(): ";
	q1.print();

	cout << "Розмір: "
		<< q1.size()
		<< endl;

	cout << "\nЧерга на основі зв'язного списку\n\n";

	LinkedListQueue q2;

	q2.enqueue(10);
	q2.enqueue(20);
	q2.enqueue(30);

	cout << "Черга: ";
	q2.print();

	cout << "Перший елемент: "
		<< q2.peek()
		<< endl;

	q2.dequeue();

	cout << "Після dequeue(): ";
	q2.print();

	cout << "Розмір: "
		<< q2.size()
		<< endl;

	const int N = 100000;

	Queue testArray(N);

	Timer arrayEnqueue;

	for (int i = 0; i < N; i++) {

		testArray.enqueue(i);
	}

	arrayEnqueue.end();

	Timer arrayDequeue;

	for (int i = 0; i < N; i++) {

		testArray.dequeue();
	}

	arrayDequeue.end();


	LinkedListQueue testList;

	Timer listEnqueue;

	for (int i = 0; i < N; i++) {

		testList.enqueue(i);
	}

	listEnqueue.end();

	Timer listDequeue;

	for (int i = 0; i < N; i++) {

		testList.dequeue();
	}

	listDequeue.end();

	cout << "Кількість елементів: "
		<< N
		<< endl << endl;

	cout << "Масив ENQUEUE: "
		<< arrayEnqueue.result()
		<< " мікросекунд\n";

	cout << "Масив DEQUEUE: "
		<< arrayDequeue.result()
		<< " мікросекунд\n\n";

	cout << "Linked List ENQUEUE: "
		<< listEnqueue.result()
		<< " мікросекунд\n";

	cout << "Linked List DEQUEUE: "
		<< listDequeue.result()
		<< " мікросекунд\n";

	return 0;
}