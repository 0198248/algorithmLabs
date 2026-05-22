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

class AdjacencyListGraph {

private:

	int vertices;

	vector<vector<int>> adjList;

public:

	AdjacencyListGraph(int v) {

		vertices = v;

		adjList.resize(vertices);
	}

	void addEdge(int u, int v) {

		adjList[u].push_back(v);

		adjList[v].push_back(u);
	}

	void removeEdge(int u, int v) {

		for (int i = 0; i < adjList[u].size(); i++) {

			if (adjList[u][i] == v) {

				adjList[u].erase(adjList[u].begin() + i);

				break;
			}
		}

		for (int i = 0; i < adjList[v].size(); i++) {

			if (adjList[v][i] == u) {

				adjList[v].erase(adjList[v].begin() + i);

				break;
			}
		}
	}


	bool hasEdge(int u, int v) {

		for (int neighbor : adjList[u]) {

			if (neighbor == v) {

				return true;
			}
		}

		return false;
	}


	void print() {

		for (int i = 0; i < vertices; i++) {

			cout << i << ": ";

			for (int neighbor : adjList[i]) {

				cout << neighbor << " ";
			}

			cout << endl;
		}
	}
};

class AdjacencyMatrixGraph {

private:

	int vertices;

	vector<vector<int>> matrix;

public:

	AdjacencyMatrixGraph(int v) {

		vertices = v;

		matrix.resize(vertices,
			vector<int>(vertices, 0));
	}


	void addEdge(int u, int v) {

		matrix[u][v] = 1;

		matrix[v][u] = 1;
	}


	void removeEdge(int u, int v) {

		matrix[u][v] = 0;

		matrix[v][u] = 0;
	}


	bool hasEdge(int u, int v) {

		return matrix[u][v] == 1;
	}


	void print() {

		for (int i = 0; i < vertices; i++) {

			for (int j = 0; j < vertices; j++) {

				cout << matrix[i][j] << " ";
			}

			cout << endl;
		}
	}
};

int main() {

	setlocale(LC_ALL, "uk_UA");

	const int V = 1000;

	AdjacencyListGraph listGraph(V);

	Timer listAdd;

	for (int i = 0; i < V - 1; i++) {

		listGraph.addEdge(i, i + 1);
	}

	listAdd.end();

	Timer listSearch;

	listGraph.hasEdge(10, 11);

	listSearch.end();

	Timer listRemove;

	listGraph.removeEdge(10, 11);

	listRemove.end();

	AdjacencyMatrixGraph matrixGraph(V);

	Timer matrixAdd;

	for (int i = 0; i < V - 1; i++) {

		matrixGraph.addEdge(i, i + 1);
	}

	matrixAdd.end();

	Timer matrixSearch;

	matrixGraph.hasEdge(10, 11);

	matrixSearch.end();

	Timer matrixRemove;

	matrixGraph.removeEdge(10, 11);

	matrixRemove.end();

	cout << "Список суміжності\n";

	cout << "ADD EDGE: "
		<< listAdd.result()
		<< " мікросекунд\n";

	cout << "SEARCH EDGE: "
		<< listSearch.result()
		<< " мікросекунд\n";

	cout << "REMOVE EDGE: "
		<< listRemove.result()
		<< " мікросекунд\n\n";

	cout << "Матриця суміжності\n";

	cout << "ADD EDGE: "
		<< matrixAdd.result()
		<< " мікросекунд\n";

	cout << "SEARCH EDGE: "
		<< matrixSearch.result()
		<< " мікросекунд\n";

	cout << "REMOVE EDGE: "
		<< matrixRemove.result()
		<< " мікросекунд\n";


	return 0;
}