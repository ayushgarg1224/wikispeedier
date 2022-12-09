# Wikispeedier: Speedier than Wikispeedia
A project by Ethan Greenwald, Nathaniel Dyer, Ayush Garg, and Nitya Sunkad.
UIUC CS 225 | Fall 2022.

## Overview
This project is based on the game Wikispeedia, an web game where players attempt to get from one Wikipedia article to another exclusively through clicking links. Our project is designed to determine the shortest path between any two articles. This utilizes the Wikispeedia navigation paths dataset provided by SNAP. We have implemented three different algorithms to achieve this, each of which is described in detail below.

## Algorithms
##### **Breadth First Search (BFS)**
This algorithm works like a standard BFS with the added feature of maintaining a history of parents to recall the path used to find the destination. This is implemented using a map with WikiNode pointers as keys and values. This maps a WikiNode to its "parent", the previously visited node that linked to it. During traversal, this map is used to keep track of visited nodes as well. If the map does not contain the current article, it is visited and added to the map. Then, once the destination node is reached, the map is traversed beginning with the value linked to the destination node. In this way, the parents can be added until we reach the starting node, at which point the path is finished and returned.
##### **Dijkstra's Algorithm**
TODO!!!!!!!!!!!!!!!!!
##### **Iterative Deepening Depth First Search (IDDFS)**
TODO!!!!!!!!!!!!!!!!!
## Running the Program
##### Main
To run this program, install make and g++, then clone the repository and navigate to `./wikispeedier/build/`. From here, running `make main` will create `main.exe`. In the same directoy, call `./main` to run the program on the default dataset. If you wish to use custom articles and links, create a tsv for each. The articles tsv should just have the article names on each line. The links tsv should have the article and linked article separated by a tab on each line. Once these are created, run `./main <articles_path> <links_path> <article_count> <links_count>` to run the program. Article_count and links_count are the total lines in each tsv respectively.
##### Testing
Test cases have also been written for this program and can be executed by first running `make test` from `../build`. Then, `./test` will run all test cases. These can be viewed in `./wikispeedier/tests/tests.cpp`. 