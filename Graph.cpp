#include "Graph.h"


Graph::Graph(int n) {
	V = n;
	Edges = new list<int>[n];
	deg_plus = new int[n];
	V2 = new int[n];
	for (int i = 0; i < V; i++) {
		V2[i] = i;
	}
}

void Graph::AddEdge(int a, int b)
{
	Edges[a].push_back(b);
}

void Graph::Deg_plus(int n)
{
	for (int i = 0; i < V; i++)
		for (auto it1 = Edges[n].begin(); it1 != Edges[n].end(); it1++) {
			if ((*it1) == V2[i]) {
				deg_plus[i]++;
			}
		}
}

int* Graph::TopologicalSort()
{
	int* answer = new int[V];
	int counter1 = V;
	int counter = 0;

	for (int i = 0; i < V; i++) {
		this->deg_plus[i] = 0;
	}

	while (1) {
		for (int i = 0; i < V; i++) {
			Deg_plus(i);
		}

		bool flag1 = false;
		for (int i = 0; i < V; i++) {
			if (deg_plus[i] == 0) {
				answer[counter] = V2[i];
				counter++;
				flag1 = true;
			}
		}
		if (flag1 == false) {
			cout << "\nGraph can't be fully sorted, sorted part: ";
			for (int j = 0; j < counter; j++) {
				cout << answer[j];
			}
			return answer;
		}


		for (int i = 0; i < V; i++) {
			if (deg_plus[i] == 0) {
				Edges[i].clear();
				swap(V2[i], V2[V-1]);
				V--;
			}
		}

		for (int i = 0; i < 6; i++) {
			deg_plus[i] = 0;
		}

		if (counter == counter1) {
			cout << "Graph fully sorted: ";
			for (int j = 0; j < counter; j++) {
				cout << answer[j];
			}
			return answer;
		}
	}
}
