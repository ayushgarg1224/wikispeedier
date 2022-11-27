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
        WikiNode* getRandomPage();
        void createGraphFromFile(string articles_path = ARTICLES, string links_path = LINKS, bool print_progress = true);
        void addNode(WikiNode* node);
        map<string, WikiNode*>& getMap();

    private:
        map<string, WikiNode*> name_node_map;
};