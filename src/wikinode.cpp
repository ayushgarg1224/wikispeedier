#include <string>
#include <vector>
#include "wikinode.h"

using namespace std;

WikiNode::WikiNode() : page_name(""), links() {}

WikiNode::WikiNode(string name) : page_name(name) {}

WikiNode::~WikiNode(){
    /* TODO bc i don't like dealing with memory leaks */
}

/*
 * @return Name of the article as stored in articles.tsv
 */
string WikiNode::getName(){
    return page_name;
}

/*
 * @return Name of the article parsed to look normal
 */
string WikiNode::getNameParsed(){
    /*
    Dataset says to use URLDecorder (Java) to decode article names.
    https://docs.oracle.com/javase/7/docs/api/java/net/URLDecoder.html
    We can just implement this ourselves and it shouldn't be too bad.
    */
}

/*
 * Getter for an article's links
 * @return Vector containing pointers to linked articles
 */
vector<WikiNode*> WikiNode::getLinks(){
    return links;
}

/*
 * Adds a directed link to another article
 */
void WikiNode::addConnection(WikiNode* other){
    links.push_back(other);
}

/*
 * Checks whether or not this article is linked to another one
 * @param name Name of the potentially linked article
 * @return true if there is a link, false if there isn't
 */
bool WikiNode::isLinkedTo(string name){
    for(auto& link : links)
        if(!link->getName().compare(name))
            return true;
    return false;
}

/*
 * Checks whether or not this article is linked to another one
 * @param other Potentially linked WikiNode
 * @return true if there is a link, false if there isn't
 */
bool WikiNode::isLinkedTo(WikiNode* other){
    for(auto& link : links)
        if(link == other)
            return true;
    return false;
}