#include "graph.h"
#include "wikinode.h"
#include "algorithms.h"
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
    if(path.size() == 0)
        cout << "Path could not be found" << endl;
    else
        alg->printPath(path);
    return 0;
}