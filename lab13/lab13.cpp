#include <iostream>
#include <vector>
#include <queue>
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

class Graph {

private:

	int vertices;

	vector<vector<int>> adjList;

	void DFSRecursive(int vertex,
		vector<bool>& visited) {

		visited[vertex] = true;

		cout << vertex << " ";

		for (int neighbor : adjList[vertex]) {

			if (!visited[neighbor]) {

				DFSRecursive(neighbor, visited);
			}
		}
	}

public:

	Graph(int v) {

		vertices = v;

		adjList.resize(vertices);
	}


	void addEdge(int u, int v) {

		adjList[u].push_back(v);

		adjList[v].push_back(u);
	}

	void DFS(int startVertex) {

		vector<bool> visited(vertices, false);

		DFSRecursive(startVertex, visited);

		cout << endl;
	}

	void BFS(int startVertex) {

		vector<bool> visited(vertices, false);

		queue<int> q;

		visited[startVertex] = true;

		q.push(startVertex);

		while (!q.empty()) {

			int current = q.front();

			q.pop();

			cout << current << " ";

			for (int neighbor : adjList[current]) {

				if (!visited[neighbor]) {

					visited[neighbor] = true;

					q.push(neighbor);
				}
			}
		}

		cout << endl;
	}
};


int main() {

	setlocale(LC_ALL, "uk_UA");

	Graph g(7);

	g.addEdge(0, 1);
	g.addEdge(0, 2);

	g.addEdge(1, 3);
	g.addEdge(1, 4);

	g.addEdge(2, 5);
	g.addEdge(2, 6);

	cout << "DFS:\n";

	g.DFS(0);

	cout << "\nBFS:\n";

	g.BFS(0);

	const int V = 100;

	Graph bigGraph(V);


	for (int i = 0; i < V - 1; i++) {

		bigGraph.addEdge(i, i + 1);
	}

	Timer dfsTimer;

	bigGraph.DFS(0);

	dfsTimer.end();

	Timer bfsTimer;

	bigGraph.BFS(0);

	bfsTimer.end();

	cout << "Кількість вершин: "
		<< V
		<< endl << endl;

	cout << "DFS TIME: "
		<< dfsTimer.result()
		<< " мікросекунд\n";

	cout << "BFS TIME: "
		<< bfsTimer.result()
		<< " мікросекунд\n";

	return 0;
}