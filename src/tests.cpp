#include "graph.h"
#include "wikinode.h"
#include "algorithms.h"
#include "tests.h"
#include <cassert>
#include <map>
#include <iostream>

#define NUM_ARTICLES 4604
#define NUM_LINKS 119882
#define TEST_ARTICLES "../dataset/test_articles.tsv"
#define TEST_LINKS "../dataset/test_links.tsv"

/* DATA PARSING TESTS */

void Tests::testGraphSize(){
    Graph* graph = new Graph();
    graph->createGraphFromFile();
    std::cout << "HERE" << std::endl;
    assert(graph->getMap().size() == NUM_ARTICLES);
}

void Tests::testLinks(){
    Graph* graph = new Graph();
    graph->createGraphFromFile(TEST_ARTICLES, TEST_LINKS); 
    vector<WikiNode*> links = graph->getPage("A")->getLinks();
    assert(links.size() == 3);
    assert(!links[0]->getName().compare("B"));
    assert(!links[1]->getName().compare("C"));
    assert(!links[2]->getName().compare("D"));
}

void Tests::testAddNode(){
    Graph* graph = new Graph();
    WikiNode* node = new WikiNode("random_name!@#$%^&*(");
    graph->addNode(node);
    assert(!graph->getPage("random_name!@#$%^&*(")->getName().compare(node->getName()));
}


/* WIKINODE TESTS */

void Tests::testIsLinkedTo(){
    WikiNode* A = new WikiNode("A");
    WikiNode* B = new WikiNode("B");

    A->addConnection(B);

    assert(A->isLinkedTo(B));
    assert(A->isLinkedTo("B"));
}

void Tests::testGetLinks(){
    WikiNode* A = new WikiNode("A");
    WikiNode* B = new WikiNode("B");
    WikiNode* C = new WikiNode("C");

    A->addConnection(B);
    A->addConnection(C);
    vector<WikiNode*> links = A->getLinks();

    assert(links[0] == B);
    assert(links[1] == C);
}

/* BFS TESTS */

void Tests::testValidPath(){
    Graph* graph = new Graph();
    graph->createGraphFromFile(TEST_ARTICLES, TEST_LINKS);
    WikiNode* start = graph->getPage("H");
    WikiNode* end = graph->getPage("E");

    Algorithm* alg = new Algorithm(graph);
    vector<WikiNode*> path = alg->getBFSPath(start, end);

    assert(!path[0] ->getName().compare("H"));
    assert(!path[path.size()-1] ->getName().compare("E"));
}

void Tests::testImpossiblePath(){
    Graph* graph = new Graph();
    graph->createGraphFromFile(TEST_ARTICLES, TEST_LINKS);
    WikiNode* start = graph->getPage("F");
    WikiNode* end = graph->getPage("I");

    Algorithm* alg = new Algorithm(graph);
    vector<WikiNode*> path = alg->getBFSPath(start, end);
    assert(path.size() == 0);
}

void Tests::testEqualPathsBFS(){
    Graph* graph = new Graph();
    graph->createGraphFromFile(TEST_ARTICLES, TEST_LINKS);
    WikiNode* start = graph->getPage("J");
    WikiNode* end = graph->getPage("C");

    Algorithm* alg = new Algorithm(graph);
    vector<WikiNode*> path = alg->getBFSPath(start, end);
    assert(!path[1]->getName().compare("A"));
    assert(!path[2]->getName().compare("B"));
}

/* MAIN TEST FUNCTION */
void Tests::runAllTests(){
    /* Graph */
    testGraphSize();
    testLinks();
    testAddNode();

    /* WikiNode */
    testIsLinkedTo();
    testGetLinks();

    /* BFS */
    testValidPath();
    testImpossiblePath();
    testEqualPathsBFS();
}