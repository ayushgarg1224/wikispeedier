#include "graph.h"
#include "wikinode.h"
#include "algorithms.h"
#include <iostream>
#include <vector>

using namespace std;
//to build and run, go to /build and run `make && ./main`
int main(){
    Graph* graph = new Graph();
    vector<WikiNode *> links = graph->getPage("%C3%85land")->getLinks();
    for(auto& link : links)
        cout << link->getName() << endl;
    return 0;
}