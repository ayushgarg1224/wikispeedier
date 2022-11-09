#pragma once

#include <string>
#include <vector>

using namespace std;

class WikiNode{
    public:
        WikiNode();
        ~WikiNode();
        WikiNode(string name);

        string getName();
        string getNameParsed();
        vector<WikiNode*> getLinks();
        vector<WikiNode*> getLinkedBy();
        bool isVisited();
        int getDepth();

        void setDepth(int d);
        void visit();
        void unvisit();
        void addConnection(WikiNode* other);

        bool isLinkedTo(string name);
        bool isLinkedTo(WikiNode* other);

        void printLinks();

    private:
        string page_name;
        vector<WikiNode*> links;
        vector<WikiNode*> linked_by;
        bool visited;
        int depth;

};