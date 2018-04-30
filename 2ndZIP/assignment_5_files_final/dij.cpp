#include <iostream>
#include <string>
#include "graph.h"
#include "min_heap.h"
#include "set.h"
#include "stack.h"

using namespace std;

int main()
{
	Graph g;
	string path;
	MinHeap h;

	cout << "Please enter location of graph file to load: ";
	cin >> path;

	g.create_graph(path);

	cout << g.dimension() << endl;

	g.print_adj_matrix();

	return 0;
}
