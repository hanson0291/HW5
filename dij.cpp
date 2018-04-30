//---------------------------------------------------------------------
// Name: Andrew Hanson
// Email: awh5563@psu.edu
// Class: CMPSC 122, Section 3
// Program 4.1
//
// Description: Contains List and Stack implementations from
// class notes.
//
//------

#include <iostream>
#include <string>
#include "graph.h"
#include "min_heap.h"
#include "set.h"
#include "stack.h"

using namespace std;

void dijkstra(Graph g, int start, int target){

	int shortestdistance[0], v = 0, u;
	int previous[0];

	MinHeap Q;

	// for each v in g
	for(v = 0; v < target; v++){
		//g.get_weight(v,target);
		
		// IF v is not source 
		//if(target != start){
		cout << "v = " << v << endl;
		cout << "start = " << start << endl;

		if(v != start){
			shortestdistance[v] = 0;
			previous[v] = -1;

			cout << "shortestdistance[v] = " << shortestdistance[v] << endl;
			cout << "previous[v] = " << previous[v] << endl;

		}
		cout << "shortestdistance[v] = " << shortestdistance[v] << endl;
		cout << "previous[v] = " << previous[v] << endl;

cout << "\n\nno crash yet 1\n\n";
		// insert(value, priority)

		//Q.insert(v, shortestdistance[v]);
		//Q.add_with_priority(v, shortestdistance[v]);
		Q.insert(shortestdistance[v], v);
		//Q.insert(v, previous[v]);

cout << "\n\nno crash yet 3\n\n";

	}
	
	while(!Q.is_empty()){

		int u = Q.extract_min();
cout << "\n\nno crash yet 4\n\n";
		// if u is in target
		if(u == target){
			//break out of while loop, you have found the last vertex
			cout << "\n\nno crash yet 5\n\n";
			break;
		}
cout << "\n\nno crash yet 6\n\n";
		// for each neighbor(v still in q), # of edges we can have
		for(int i = 0; Q.min() >= 0; v--){
			//int alt = shortestdistance[vertex] + length(alt,vertex);
			int alt = shortestdistance[v] + g.get_weight(u,v);
				if(alt < shortestdistance[v]){
					shortestdistance[v] = alt;
					//previous[vertex] = u;
					Q.decrease_priority(v, alt);
				}
		}
	}
// DETERMING THE SHORTEST PATH from source to target using previous array
	Stack S;
	u = target;

	while(previous[u] > 1){
		S.push(u);
		u = previous[u];
	}
	S.push(u);
}

int main() {
	Graph g;
	string path, start, target;
	
	cout << "Please enter location of graph file to load: ";
	cin >> path;

	cout << "Please enter the index of the starting vertex: ";
	cin >> start;

	cout << "Please enter the index of the starting vertex: ";
	cin >> target;

	cout << "The shortest path from vertex 0 to vertex 7 is:\n\n";

		int startx = 0;
		int targetx = 0;
		istringstream ss1(start);
		istringstream ss2(target);
		ss1 >> startx;
		ss2 >> targetx;

		dijkstra(g,startx,targetx);
	
	g.create_graph(path);

	//RETURNS ADJUSTED MATRIX DISTANCE
	cout << g.dimension() << endl;
	g.print_adj_matrix();

	return 0;
}


//cout << "start = " << start << endl;
//cout << "target = " << target << endl;
		//Q.add_with_priority or append it to the graph
		//Q.insert(vertex, shortestdistance[vertex]);
		//Q.insert(vertex, shortestdistance[vertex]);
		//Q.insert(shortestdistance[vertex], vertex);