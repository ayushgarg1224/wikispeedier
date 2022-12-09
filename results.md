# CS225 Final Project Report
## Project: wikispeedier
## Names: Nathaniel Dyer, Ayush Garg, Ethan Greenwald, Nitya Sunkad


Leading Question 
[Ayush]
Algorithms

We used the following algorithms to find the most efficient path from a chosen source Wikipedia article to a chosen destination Wikipedia article.



BFS
[Ethan]
Dijkstra’s Algorithm - O(V2)
Dijkstra’s Algorithm is a popular algorithm for finding shortest paths in a weighted, directed graph. The algorithm works by starting at a source node in the graph and exploring all of its neighbors, and adding the lowest cost node to the path. Similar to BFS, which constructs a path using a FIFO queue, Dijkstra’s constructs a path using a min-heap (priority queue) to prioritize adding nodes with shorter distances from source to the path.

In our implementation, we find the shortest path from our source article to our destination article by running Dijkstra’s on the graph of WikiNodes, using a min-heap implemented with a priority queue. Weights are assigned to nodes based on how many outgoing links they have, which is a rough estimate of the page size and load time of each article.

For Dijkstra’s we are testing four situations: 
No valid path exists in the data set between the two given nodes
If a valid path exists, it starts and ends where its supposed to
If the weight factor (the dividing factor for the number of outgoing links before they are added to the weight of an edge) is comparable to the outgoing links in a given path, it chooses the path with the less number of outgoing links
If the weight factor is not comparable and the number of outgoing links don’t matter, then we get the same result as BFS

Iterative Deepening Depth-First Search (IDDFS)
[Nathan]
