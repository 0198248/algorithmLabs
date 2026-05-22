#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// односпрямований список

class SinglyLinkedList {
private:
	struct Node {
		int data;
		Node* next;

		Node(int value) {
			data = value;
			next = nullptr;
		}
	};
	Node* head;
public:

	SinglyLinkedList()
	{
		head = nullptr;
	}

	~SinglyLinkedList()
	{
		while (head != nullptr)
		{
			deleteElementHead();
		}
	}

	void addElementHead(int value) {

		Node* newNode = new Node(value);
		newNode->next = head;

		head = newNode;

	}

	void addElementTail(int value) {

		Node* newNode = new Node(value);

		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		Node* temp = head;

		while (temp->next != nullptr) {

			temp = temp->next;

		}
		temp->next = newNode;

	}

	void deleteElementHead() {
		if (head == nullptr)
		{
			return;
		}

		Node* temp = head;
		head = head->next;

		delete temp;
	}

	void deleteElementTail() {
		if (head == nullptr)
		{
			return;
		}

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node* temp = head;

		while (temp->next->next != nullptr) {

			temp = temp->next;

		}

		delete temp->next;
		temp->next = nullptr;

	}

	void print() {
		Node* temp = head;
		while (temp != nullptr) {

			cout << temp->data << " ";
			temp = temp->next;

		}

		cout << endl;
	}

};

class DoublyLinkedList {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev;

		Node(int value) {
			data = value;
			next = nullptr;
			prev = nullptr;
		}
	};
	Node* head;
	Node* tail;
public:
	DoublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	~DoublyLinkedList()
	{
		while (head != nullptr)
		{
			deleteElementHead();
		}
	}

	void addElementHead(int value) {

		Node* newNode = new Node(value);

		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void addElementTail(int value) {

		Node* newNode = new Node(value);

		if (tail == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	void deleteElementHead() {
		if (head == nullptr)
		{
			return;
		}

		Node* temp = head;

		if (head == tail)
		{
			head = tail = nullptr;
		}
		else {
			head = head->next;
			head->prev = nullptr;
		}
		delete temp;
	}

	void deleteElementTail() {
		if (tail == nullptr)
		{
			return;
		}

		Node* temp = tail;

		if (head == tail)
		{
			head = tail = nullptr;
		}
		else {
			tail = tail->prev;
			tail->next = nullptr;
		}

		delete temp;

	}

	void printForward() {
		Node* temp = head;
		while (temp != nullptr) {

			cout << temp->data << " ";
			temp = temp->next;

		}

		cout << endl;
	}
	void printBackward() {
		Node* temp = tail;
		while (temp != nullptr) {

			cout << temp->data << " ";
			temp = temp->prev;

		}

		cout << endl;
	}

};

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

int main() {
	setlocale(LC_ALL, "uk_UA");

	//Односпрямований список

	SinglyLinkedList sList;

	Timer Timer1;

	for (int i = 0; i < 1000; i++)
	{
		sList.addElementHead(i);
	}
	for (int i = 0; i < 1000; i++)
	{
		sList.addElementTail(i);
	}

	for (int i = 0; i < 200; i++)
	{
		sList.deleteElementHead();
	}

	for (int i = 0; i < 200; i++)
	{
		sList.deleteElementTail();
	}

	Timer1.end();

	//Двоспрямований список

	DoublyLinkedList dList;

	Timer Timer2;

	for (int i = 0; i < 1000; i++)
	{
		dList.addElementHead(i);
	}
	for (int i = 0; i < 1000; i++)
	{
		dList.addElementTail(i);
	}

	for (int i = 0; i < 200; i++)
	{
		dList.deleteElementHead();
	}

	for (int i = 0; i < 200; i++)
	{
		dList.deleteElementTail();
	}

	Timer2.end();

	cout << "\nРезультат затрати часу односпрямованого/двоспрямованого списку (в мікросекундах):\n" << Timer1.result() << "/" << Timer2.result() << endl;

	return 0;
}