#include "graph.h"
#include "wikinode.h"
#include "algorithms.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//to build and run, go to /build and run `make && ./main`
int main(int argc, char* argv[]){//int argc, char** argv
    Graph* graph = new Graph();

    try{
        string article_path(argv[1]);
        string links_path(argv[2]);
        cout << "\nCustom Articles: " << article_path << " | Custom Links: " << links_path << endl;
        graph->createGraphFromFile(article_path, links_path);
    }catch(...){
        cout << "\nUsing default articles & links..." << endl;
        graph->createGraphFromFile();
    }

    Algorithm* alg = new Algorithm(graph);
    WikiNode* start = graph->getRandomPage();
    WikiNode* end = graph->getRandomPage();
    vector<string> algorithm_names = {"Dijkstra: ", "BFS:      ", "IDDFS:    "};

    cout << "\nGOAL: " << start->getNameParsed() << " -> " << end->getNameParsed() << "\n-----" << endl;
    vector<pair<vector<WikiNode*>, double>> paths = alg->compareAlgs(start, end);

    int alg_idx = 0;
    for(auto& pair : paths){
        cout << algorithm_names[alg_idx++];
        if(pair.first.size() == 0)
            cout << "Path could not be found" << endl;
        else{
            alg->printPath(pair.first);
            cout << "(" << pair.first.size() << " articles long, " << (float)pair.second << " ms)\n-----" << endl;
        }
    }

    delete graph; delete alg;
    return 0;
}