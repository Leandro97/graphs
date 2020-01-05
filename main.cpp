#include "graph.c"
#include "dijkstra.c"

int main() {
  verticesNumber = 4;
  int** graph = createGraph(verticesNumber);

  addEdge(graph, 0, 1, 3);
  addEdge(graph, 0, 2, 7);
  addEdge(graph, 1, 2, 7);
  addEdge(graph, 2, 1, 3);
  addEdge(graph, 1, 3, 2);
  addEdge(graph, 2, 3, 6);
  addEdge(graph, 3, 2, 1);
  //printGraph(graph);

  dijkstra(graph, 0);
}
