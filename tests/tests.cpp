#include "../src/graph.h"
#include "../src/wikinode.h"
#include "../src/algorithms.h"
#include <cassert>
#include <map>
#include <iostream>

#define NUM_ARTICLES 4604
#define NUM_LINKS 119882
#define TEST_ARTICLES "../dataset/test_articles.tsv"
#define TEST_LINKS "../dataset/test_links.tsv"

/* DATA PARSING TESTS */

void testGraphSize(){
    Graph* graph = new Graph();
    graph->createGraphFromFile(TEST_ARTICLES, TEST_LINKS, false);
    assert(graph->getMap().size() == 10);
    delete graph;
}

void testLinks(){
    Graph* graph = new Graph();
    graph->createGraphFromFile(TEST_ARTICLES, TEST_LINKS, false);
    vector<WikiNode*> links = graph->getPage("A")->getLinks();
    assert(links.size() == 3);
    assert(!links[0]->getName().compare("B"));
    assert(!links[1]->getName().compare("C"));
    assert(!links[2]->getName().compare("D"));
    delete graph;
}

void testAddNode(){
    Graph* graph = new Graph();
    WikiNode* node = new WikiNode("random_name!@#$%^&*(");
    graph->addNode(node);
    assert(!graph->getPage("random_name!@#$%^&*(")->getName().compare(node->getName()));
    delete graph;
}


/* WIKINODE TESTS */

void testIsLinkedTo(){
    WikiNode* A = new WikiNode("A");
    WikiNode* B = new WikiNode("B");

    A->addConnection(B);

    assert(A->isLinkedTo(B));
    assert(A->isLinkedTo("B"));
    delete A; delete B;
}

void testGetLinks(){
    WikiNode* A = new WikiNode("A");
    WikiNode* B = new WikiNode("B");
    WikiNode* C = new WikiNode("C");

    A->addConnection(B);
    A->addConnection(C);
    vector<WikiNode*> links = A->getLinks();

    assert(links[0] == B);
    assert(links[1] == C);
    delete A; delete B; delete C;
}

/* BFS TESTS */

void testValidPath(){
    Graph* graph = new Graph();
    graph->createGraphFromFile(TEST_ARTICLES, TEST_LINKS, false);
    WikiNode* start = graph->getPage("H");
    WikiNode* end = graph->getPage("E");

    Algorithm* alg = new Algorithm(graph);
    vector<WikiNode*> path = alg->getBFSPath(start, end);

    assert(!path[0] ->getName().compare("H"));
    assert(!path[path.size()-1] ->getName().compare("E"));
    delete graph; delete alg; 
}

void testImpossiblePath(){
    Graph* graph = new Graph();
    graph->createGraphFromFile(TEST_ARTICLES, TEST_LINKS, false);
    WikiNode* start = graph->getPage("F");
    WikiNode* end = graph->getPage("I");

    Algorithm* alg = new Algorithm(graph);
    vector<WikiNode*> path = alg->getBFSPath(start, end);
    assert(path.size() == 0);
    delete graph; delete alg;
}

void testEqualPathsBFS(){
    Graph* graph = new Graph();
    graph->createGraphFromFile(TEST_ARTICLES, TEST_LINKS, false);
    WikiNode* start = graph->getPage("J");
    WikiNode* end = graph->getPage("B");

    Algorithm* alg = new Algorithm(graph);
    vector<WikiNode*> path = alg->getBFSPath(start, end);

    assert(!path[1]->getName().compare("A"));
    delete graph; delete alg;
}

/* MAIN TEST FUNCTION */
int main(){
    /* Graph */
    testGraphSize();
    testLinks();
    testAddNode();
    std::cout << "Graph tests passed!" << std::endl;

    /* WikiNode */
    testIsLinkedTo();
    testGetLinks();
    std::cout << "WikiNode tests passed!" << std::endl;

    /* BFS */
    testValidPath();
    testImpossiblePath();
    testEqualPathsBFS();
    std::cout << "BFS tests passed" << std::endl;

    /* Dijkstra */
    //TODO
    
    /* IDDFS */
    //TODO

    std::cout << "\n#################################" << std::endl;
    std::cout <<   "##### ALL TEST CASES PASSED #####" << std::endl;
    std::cout <<   "#################################" << std::endl;
    return 0;
}