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

// стек на основі масиву

class Stack {
private:

	int* arr;
	int top;
	int size;

public:

	Stack(int stackSize) {

		size = stackSize;
		arr = new int[size];
		top = -1;
	}

	~Stack() {
		delete[] arr;
	}

	void push(int value) {

		if (top == size - 1) {
			cout << "Stack overflow\n";
			return;
		}

		top++;
		arr[top] = value;
	}

	void pop() {

		if (isEmpty()) {
			cout << "Stack is empty\n";
			return;
		}

		top--;
	}

	int peek() {

		if (isEmpty()) {
			cout << "Stack is empty\n";
			return -1;
		}

		return arr[top];
	}

	bool isEmpty() {
		return top == -1;
	}

	void print() {

		for (int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}

		cout << endl;
	}
};

// стек на основі зв'язного списку

class LinkedListStack {
private:

	struct Node {

		int data;
		Node* next;

		Node(int value) {
			data = value;
			next = nullptr;
		}
	};

	Node* top;

public:

	LinkedListStack() {
		top = nullptr;
	}

	~LinkedListStack() {

		while (!isEmpty()) {
			pop();
		}
	}

	void push(int value) {

		Node* newNode = new Node(value);

		newNode->next = top;
		top = newNode;
	}

	void pop() {

		if (isEmpty()) {
			cout << "Stack is empty\n";
			return;
		}

		Node* temp = top;

		top = top->next;

		delete temp;
	}

	int peek() {

		if (isEmpty()) {
			cout << "Stack is empty\n";
			return -1;
		}

		return top->data;
	}

	bool isEmpty() {
		return top == nullptr;
	}

	void print() {

		Node* temp = top;

		while (temp != nullptr) {

			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;
	}
};


int main() {

	setlocale(LC_ALL, "Ukrainian");


	cout << "СТЕК НА ОСНОВІ МАСИВУ\n\n";

	Stack stackArray(10);

	stackArray.push(10);
	stackArray.push(20);
	stackArray.push(30);

	cout << "Стек: ";
	stackArray.print();

	cout << "Верхній елемент: "
		<< stackArray.peek()
		<< endl;

	stackArray.pop();

	cout << "Після pop(): ";
	stackArray.print();


	cout << "\nCтек на основі зв'язного списку\n\n";

	LinkedListStack stackList;

	stackList.push(10);
	stackList.push(20);
	stackList.push(30);

	cout << "Стек: ";
	stackList.print();

	cout << "Верхній елемент: "
		<< stackList.peek()
		<< endl;

	stackList.pop();

	cout << "Після pop(): ";
	stackList.print();


	const int N = 100000;


	Stack testArray(N);

	Timer timerArrayPush;

	for (int i = 0; i < N; i++) {
		testArray.push(i);
	}

	timerArrayPush.end();

	Timer timerArrayPop;

	for (int i = 0; i < N; i++) {
		testArray.pop();
	}

	timerArrayPop.end();


	LinkedListStack testList;

	Timer timerListPush;

	for (int i = 0; i < N; i++) {
		testList.push(i);
	}

	timerListPush.end();

	Timer timerListPop;

	for (int i = 0; i < N; i++) {
		testList.pop();
	}

	timerListPop.end();


	cout << "Кількість елементів: "
		<< N
		<< endl << endl;

	cout << "Масив PUSH: "
		<< timerArrayPush.result()
		<< " мікросекунд\n";

	cout << "Масив POP: "
		<< timerArrayPop.result()
		<< " мікросекунд\n\n";

	cout << "Linked List PUSH: "
		<< timerListPush.result()
		<< " мікросекунд\n";

	cout << "Linked List POP: "
		<< timerListPop.result()
		<< " мікросекунд\n";

	return 0;
}