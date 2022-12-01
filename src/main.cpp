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
    cout << "BFS Done" << endl;
    vector<WikiNode*> pathDijkstra = alg->getDijkstraPath(start, end);
    cout << "Dijkstra Done" << endl;
    vector<WikiNode*> pathIDDFS = alg->getIDDFSPath(start, end);
    cout << "IDDFS Done" << endl;
    // vector<WikiNode*> pathIDDFS_Visited = alg->getIDDFSPathVisited(start, end);
    // cout << "IDDFS_Visted Done" << endl;
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
    if (pathIDDFS.size() == 0) {
        cout << "IDDFS path could not be found" << endl;
    } else {
        cout << "Printing IDDFS's Path:" << endl;
        alg->printPath(pathIDDFS);
    }
    // if (pathIDDFS.size() == 0) {
    //     cout << "IDDFS_Visited path could not be found" << endl;
    // } else {
    //     cout << "Printing IDDFS_Visited's Path:" << endl;
    //     alg->printPath(pathIDDFS_Visited);
    // }
    delete graph; delete alg;
    return 0;
}