#include "graph.h"
#include "wikinode.h"
#include "algorithms.h"
#include "tests.h"
#include <iostream>
#include <vector>

using namespace std;

//to build and run, go to /build and run `make && ./main`
int main(){
    Graph* graph = new Graph();
    graph->createGraphFromFile();
    
    Algorithm* alg = new Algorithm(graph);
    WikiNode* start = graph->getRandomPage();
    WikiNode* end = graph->getRandomPage();

    cout << "Start: " << start->getName() << "\nEnd: " << end->getName() << endl;
    vector<WikiNode*> path = alg->getBFSPath(start, end);
    vector<WikiNode*> pathDijkstra = alg->getDijkstraPath(start, end);
    if(path.size() == 0)
        cout << "Path could not be found" << endl;
    else{
        cout << "Printing BFS's Path:" << endl;
        alg->printPath(path);
    }
    if (pathDijkstra.size() == 0) {
        cout << "Dijkstra path could not be found" << endl;
    } else {
        cout << "Printing Dijkstra's Path:" << endl;
        alg->printPath(pathDijkstra);
    }
    // Tests* tester = new Tests();
    // tester->runAllTests();
    return 0;
}