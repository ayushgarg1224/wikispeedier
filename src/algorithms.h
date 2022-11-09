#pragma once

#include <string>
#include <utility>
#include "wikinode.h"
#include "graph.h"

using namespace std;

class Algorithm {
    public:
        Algorithm(Graph* graph);
        vector<pair<vector<WikiNode*>, double>> compareAlgs(WikiNode* start, WikiNode* end);
        vector<WikiNode*> getDijkstraPath(WikiNode* start, WikiNode* end);
        vector<WikiNode*> getBFSPath(WikiNode* start, WikiNode* end);
        vector<WikiNode*> getIDDFSPath(WikiNode* start, WikiNode* end);
        void printPath(vector<WikiNode*> path);
    private:
        Graph* graph;
};