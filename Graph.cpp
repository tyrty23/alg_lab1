#include "Graph.h"


Graph::Graph(int n) {
	/*this->*/V = n;
	/*this->*/Edges = new list<int>[n];
	/*this->*/deg_plus = new int[n];
	/*this->*/V2 = new int[n];
	for (int i = 0; i < V; i++) {
		/*this->*/V2[i] = i;
	}
}

void Graph::AddEdge(int a, int b)
{
	/*this->*/Edges[a].push_back(b);
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

void Graph::Deg_minus(int n)
{
	bool flag = true;
	for (int i = 0; i < V; i++) {
		for (auto it1 = Edges[n].begin(); it1 != Edges[n].end(); it1++) {
			if (deg_plus[i] == 0 ) {
				it1=Edges[n].erase(it1);				
				flag = false;
				if (it1 == Edges[n].end()) {
					break;
				}
			}
		}
		if (flag == false) {
			swap(V2[i], V2[V]);
			V--;
			flag = true;
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
		cout << "\nкруг" << endl;


		cout << "\nВыод листов\n";
		 
		for (int i = 0; i < V; i++) {
			for (auto it1 = Edges[i].begin(); it1 != Edges[i].end(); it1++) {
				cout << *it1;
			}

			cout << endl;
		}

		cout << "\nоставшиеся элементы\n";
		for (int i = 0; i < 6; i++) {
			cout << V2[i];
		}
		cout << endl;
		for (int i = 0; i < V; i++) {
			Deg_plus(i);
		}

		cout << endl;

		for (int i = 0; i < 6; i++) {
			cout << deg_plus[i];
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
			cout << "Полностью отсортировать граф не удалось, отсортированые элементы: ";
			for (int j = 0; j < counter; j++) {
				cout << answer[j];
			}
			return answer;
		}
		cout <<"\nanswer"<< endl;
		for (int j = 0; j < counter; j++) {
			cout << answer[j];
		}

		for (int i = 0; i < V; i++) {
			Deg_minus(i);
		}

		for (int i = 0; i < 6; i++) {
			deg_plus[i] = 0;
		}
		cout << "\nоставшиеся элементы\n";
		for (int i = 0; i < 6; i++) {
			cout<<V2[i];
		}
		cout << endl;


		if (counter == counter1) {
			cout << "Граф полностью отсортирован: ";
			for (int j = 0; j < counter; j++) {
				cout << answer[j];
			}
			return answer;
		}
	}
}