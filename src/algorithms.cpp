#include "algorithms.h"
#include "graph.h"
#include "wikinode.h"

#include <chrono>
#include <queue>
#include <iostream>
#include <algorithm>

#define NUM_ARTICLES 4604
#define NUM_LINKS 119882

using namespace std;
using namespace std::chrono;

Algorithm::Algorithm(Graph* graph) : graph(graph) {}

/// @brief Compares the three search algorithms in terms of path size and runtime.
/// @param start Starting page
/// @param end Destination page
/// @return Vector of pairs where the first element is a path vector of WikiNode pointers and the second is the algorithm's runtime in seconds.
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

/// @brief This function will print the article names in order of the given path
/// @param path Vector of pointers to the path's WikiNodes
void Algorithm::printPath(vector<WikiNode*> path){
    WikiNode* node;

    for(int i = 0; i < (int)path.size(); i++){
        node = path[i];
        if(i != (int)path.size()-1)
            cout << node->getName() << " -> ";
        else
            cout << node->getName() << endl;
    }
}

/// @brief This function determines the shortest path between two WikiNodes using Dijkstra's algorithm.
/// @param start start Starting page
/// @param end end Destination page
/// @return Vector containing the order of pages to visit for the shortest path
vector<WikiNode*> Algorithm::getDijkstraPath(WikiNode* start, WikiNode* end){
    return vector<WikiNode*>();
}

/// @brief This function determines the shortest path between two WikiNodes using a Breadth First Search
/// @param start Starting page
/// @param end Destination page
/// @return Vector containing the order of pages to visit for the shortest path, empty if path cannot be found
vector<WikiNode*> Algorithm::getBFSPath(WikiNode* start, WikiNode* end){
    queue<WikiNode*> queue;
    vector<WikiNode*> curLinks;
    vector<WikiNode*> path;

    WikiNode* curr;
    int depth;

    /* Initialize queue with starting node */
    start->visit();
    start->setDepth(0);
    queue.push(start);

    while(!queue.empty()){
        /* Get current depth and pop curr */
        curr = queue.front();
        depth = curr->getDepth();
        queue.pop();
        if(curr == end){                     //we have found the destination and assigned depths along the way
            curr->setDepth(depth);
            break;
        }

        /* For each unvisited link from the current node, visit it and assign depth of current + 1 */
        curLinks = curr->getLinks();
        for(auto& link : curLinks)
            if(!link->isVisited()){
                link->visit();
                link->setDepth(depth + 1);
                queue.push(link);
            }
    }

    /* Check to see if the end node was actually reached */
    if(curr != end)
        return vector<WikiNode*>();

    /* Backwards traversal via depth minimization */
    depth = 0;
    path.push_back(curr);
    while(curr != start){
        curLinks = curr->getLinkedBy();                 //vector of articles that link here
        for(auto& link : curLinks){
            if(link->getDepth() < curr->getDepth()){    //if a previous article was closer to the start, move there
                link->visit();
                curr = link;
                path.push_back(link);
                break;
            }
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

/// @brief This function determines the shortest path between two WikiNodes using Iterative Deepening Depth-First Search
/// @param start Starting page
/// @param end Destination page
/// @return Vector containing the order of pages to visit for the shortest path
vector<WikiNode*> Algorithm::getIDDFSPath(WikiNode* start, WikiNode* end){
    return vector<WikiNode*>();
}
