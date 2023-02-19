#pragma once
#include <list>
#include <vector>
#include <iostream>


using namespace std;


class Graph
{
public:
	int V;
	int* V2;
	list<int>* Edges;
	int* deg_plus;


	Graph(int);

	void AddEdge(int,int);

	void Deg_plus(int);

	void Deg_minus(int);

	int* TopologicalSort();
};

