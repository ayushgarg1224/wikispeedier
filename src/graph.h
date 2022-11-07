#include <string>
#include <vector>
#include <map>
#include "wikinode.h"

using namespace std;

class Graph{
    public:
        Graph();
        ~Graph();
        WikiNode* getPage(string page_name);
        void createGraphFromFile(string articles_path, string links_path);

        void addNode(WikiNode* node);
    private:
        map<string, WikiNode*> name_node_map;
};