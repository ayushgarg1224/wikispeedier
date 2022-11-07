#include <string>
#include <vector>
#include <map>
#include "wikinode.h"

using namespace std;

class Graph{
    public:
        Graph();
        Graph(string file_path);
        ~Graph();
        WikiNode* getPage(string page_name);
        void createGraphFromFile(string file_path);

    private:
        void addNode(WikiNode* node);
        map<string, WikiNode*> name_node_map;
};