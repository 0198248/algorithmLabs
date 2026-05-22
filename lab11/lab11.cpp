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

// Binary search tree

class BinarySearchTree {

private:

	struct Node {

		int data;

		Node* left;
		Node* right;

		Node(int value) {

			data = value;

			left = nullptr;
			right = nullptr;
		}
	};

	Node* root;

	Node* insert(Node* node, int value) {

		if (node == nullptr) {
			return new Node(value);
		}

		if (value < node->data) {

			node->left = insert(node->left, value);
		}
		else if (value > node->data) {

			node->right = insert(node->right, value);
		}

		return node;
	}

	bool search(Node* node, int value) {

		if (node == nullptr) {
			return false;
		}

		if (node->data == value) {
			return true;
		}

		if (value < node->data) {

			return search(node->left, value);
		}
		else {

			return search(node->right, value);
		}
	}

	Node* findMin(Node* node) {

		while (node->left != nullptr) {

			node = node->left;
		}

		return node;
	}

	Node* remove(Node* node, int value) {

		if (node == nullptr) {
			return nullptr;
		}

		if (value < node->data) {

			node->left = remove(node->left, value);
		}
		else if (value > node->data) {

			node->right = remove(node->right, value);
		}


		else {

			if (node->left == nullptr &&
				node->right == nullptr) {

				delete node;

				return nullptr;
			}

			else if (node->left == nullptr) {

				Node* temp = node->right;

				delete node;

				return temp;
			}

			else if (node->right == nullptr) {

				Node* temp = node->left;

				delete node;

				return temp;
			}


			Node* temp = findMin(node->right);

			node->data = temp->data;

			node->right =
				remove(node->right, temp->data);
		}

		return node;
	}

	void preorder(Node* node) {

		if (node == nullptr) {
			return;
		}

		cout << node->data << " ";

		preorder(node->left);
		preorder(node->right);
	}

	void inorder(Node* node) {

		if (node == nullptr) {
			return;
		}

		inorder(node->left);

		cout << node->data << " ";

		inorder(node->right);
	}

	void postorder(Node* node) {

		if (node == nullptr) {
			return;
		}

		postorder(node->left);
		postorder(node->right);

		cout << node->data << " ";
	}

	void clear(Node* node) {

		if (node == nullptr) {
			return;
		}

		clear(node->left);
		clear(node->right);

		delete node;
	}

public:

	BinarySearchTree() {

		root = nullptr;
	}

	~BinarySearchTree() {

		clear(root);
	}

	void insert(int value) {

		root = insert(root, value);
	}

	bool search(int value) {

		return search(root, value);
	}

	void remove(int value) {

		root = remove(root, value);
	}

	void preorder() {

		preorder(root);

		cout << endl;
	}

	void inorder() {

		inorder(root);

		cout << endl;
	}

	void postorder() {

		postorder(root);

		cout << endl;
	}
};

int main() {

	setlocale(LC_ALL, "uk_UA");

	BinarySearchTree bst;


	bst.insert(50);
	bst.insert(30);
	bst.insert(70);
	bst.insert(20);
	bst.insert(40);
	bst.insert(60);
	bst.insert(80);


	cout << "PREORDER:\n";
	bst.preorder();

	cout << "\nINORDER:\n";
	bst.inorder();

	cout << "\nPOSTORDER:\n";
	bst.postorder();

	cout << "\nПошук 40:\n";

	if (bst.search(40)) {

		cout << "Елемент знайдено\n";
	}
	else {

		cout << "Елемент не знайдено\n";
	}

	cout << "\nВидалення 70\n";

	bst.remove(70);

	cout << "\nInorder після видалення:\n";

	bst.inorder();

	const int N = 1000;

	BinarySearchTree testTree;

	Timer insertTimer;

	for (int i = 0; i < N; i++) {

		testTree.insert(i);
	}

	insertTimer.end();

	Timer searchTimer;

	testTree.search(N - 1);

	searchTimer.end();


	Timer removeTimer;

	testTree.remove(N - 1);

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