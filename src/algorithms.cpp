#include "algorithms.h"
#include "graph.h"
#include "wikinode.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

Algorithm::Algorithm(Graph* graph) : graph(graph) {}

/*
 * This function compares the three algorithms in terms of path size and runtime.
 * @param start Starting page
 * @param end Destination page
 * @return Vector of pairs where the first element is a path vector of WikiNode pointers and the second is the algorithm's runtime in seconds.
 */
vector<pair<vector<WikiNode*>, double>> Algorithm::compareAlgs(WikiNode* start, WikiNode* end){
    vector<pair<vector<WikiNode*>, double>> paths;
    vector<WikiNode*> path;
    duration<double, std::milli> time;

    auto startTime = high_resolution_clock::now();
    path = getDijkstraPath(start, end);
    auto endTime = high_resolution_clock::now();
    time = endTime - startTime;
    paths.push_back(pair<vector<WikiNode*>, double>(path, time.count()));

    startTime = high_resolution_clock::now();
    path = getBFSPath(start, end);
    endTime = high_resolution_clock::now();
    time = endTime - startTime;
    paths.push_back(pair<vector<WikiNode*>, double>(path, time.count()));

    startTime = high_resolution_clock::now();
    path = getIDDFSPath(start, end);
    endTime = high_resolution_clock::now();
    time = endTime - startTime;
    paths.push_back(pair<vector<WikiNode*>, double>(path, time.count()));

    return paths;
}


/*
 * This function determines the shortest path between two WikiNodes using Dijkstra's algorithm.
 * @param start Starting page
 * @param end Destination page
 * @return Vector containing the order of pages to visit for the shortest path
 */
vector<WikiNode*> Algorithm::getDijkstraPath(WikiNode* start, WikiNode* end){
    return vector<WikiNode*>();
}

/*
 * This function determines the shortest path between two WikiNodes using a Breadth First Search
 * @param start Starting page
 * @param end Destination page
 * @return Vector containing the order of pages to visit for the shortest path
 */
vector<WikiNode*> Algorithm::getBFSPath(WikiNode* start, WikiNode* end){
    return vector<WikiNode*>();
}

/*
 * This function determines the shortest path between two WikiNodes using Iterative Deepening Depth-First Search
 * @param start Starting page
 * @param end Destination page
 * @return Vector containing the order of pages to visit for the shortest path
 */
vector<WikiNode*> Algorithm::getIDDFSPath(WikiNode* start, WikiNode* end){
    return vector<WikiNode*>();
}
