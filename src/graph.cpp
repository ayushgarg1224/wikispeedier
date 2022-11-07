#include "graph.h"
#include "wikinode.h"
#include <string>

Graph::Graph(){}

Graph::Graph(string file_path){
    createGraphFromFile(file_path);
}

Graph::~Graph(){
    /* TODO bc memory ew */
}

/*
 * Returns pointer to WikiNode based on article name.
 * @param page_name Name of the page to find.
 * @return Pointer to WikiNode corresponding to page_name or NULL if does not exist.
 */
WikiNode* Graph::getPage(string page_name){
    map<string, WikiNode*>::iterator it = name_node_map.find(page_name);
    return (it != name_node_map.end()) ? it->second : NULL;
}

/*
 * Parses Wiki data to create graph.
 * @param file_path Path to file containing graph data
 */
void Graph::createGraphFromFile(string file_path){
    /* TODO: Parse through and create WikiNodes. Add these via pointer to the map. */
}

/* 
 * Inserts a new node into the graph.
 * @param node Pointer to node to be added
 */
void Graph::addNode(WikiNode* node){
    name_node_map.insert({node->getName(), node});
}