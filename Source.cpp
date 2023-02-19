#include <iostream>
#include <list>
#include "Graph.h"


using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");

	Graph graph(6);

	graph.AddEdge(1, 0);
	graph.AddEdge(0, 2);
	graph.AddEdge(1, 3);
	graph.AddEdge(3, 2);
	graph.AddEdge(2, 4);
	graph.AddEdge(2, 5);

	graph.TopologicalSort();
}