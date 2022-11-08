#pragma once

#include <string>
#include <vector>
#include <map>
#include "wikinode.h"

#define ARTICLES "../dataset/articles.tsv"
#define LINKS "../dataset/links.tsv"

using namespace std;

class Graph{
    public:
        Graph();
        ~Graph();
        WikiNode* getPage(string page_name);
        void createGraphFromFile(string articles_path = ARTICLES, string links_path = LINKS);

        void addNode(WikiNode* node);
    private:
        map<string, WikiNode*> name_node_map;
};