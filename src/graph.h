#pragma once

#include <string>
#include <vector>
#include <map>
#include "wikinode.h"

#define ARTICLES "../dataset/articles.tsv"
#define LINKS "../dataset/links.tsv"
#define PLAINTEXT "../dataset/plaintext_articles"

using namespace std;

class Graph{
    public:
        Graph();
        ~Graph();
        WikiNode* getPage(string page_name);
        WikiNode* getRandomPage();
        void createGraphFromFile(string articles_path = ARTICLES, string links_path = LINKS, string plain_text = PLAINTEXT);

        void addNode(WikiNode* node);
    private:
        map<string, WikiNode*> name_node_map;
};