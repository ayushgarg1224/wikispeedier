#include <string>
#include <vector>
#include "wikinode.h"

using namespace std;

WikiNode::WikiNode() : page_name(""), links() {}

WikiNode::WikiNode(string name) : page_name(name) {}

WikiNode::~WikiNode(){
    /* TODO bc i don't like dealing with memory leaks */
}

string WikiNode::getName(){
    return page_name;
}

vector<WikiNode*> WikiNode::getLinks(){
    return links;
}

void WikiNode::addConnection(WikiNode* other){
    links.push_back(other);
}

bool WikiNode::isLinkedTo(string name){
    for(auto& link : links)
        if(!link->getName().compare(name))
            return true;
    return false;
}

bool WikiNode::isLinkedTo(WikiNode* other){
    for(auto& link : links)
        if(link == other)
            return true;
    return false;
}