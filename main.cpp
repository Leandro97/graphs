#include "graph.c"
#include "dijkstra.c"
#include "bellmanFord.c"
#include "kruskal.c"
#include "prim.c"
#include "fordFulkerson.c"

void runDijkstra() {
  cout << "### Dijkstra ###" << endl;

  verticesNumber = 9;
  int** graph = createGraph(verticesNumber);

  addEdge(graph, 0, 1, 4);
  addEdge(graph, 0, 7, 8);
  addEdge(graph, 1, 7, 11);
  addEdge(graph, 1, 2, 8);
  addEdge(graph, 2, 8, 2);
  addEdge(graph, 7, 8, 7);
  addEdge(graph, 7, 6, 1);
  addEdge(graph, 6, 8, 6);
  addEdge(graph, 6, 5, 2);
  addEdge(graph, 2, 3, 7);
  addEdge(graph, 2, 5, 4);
  addEdge(graph, 3, 5, 14);
  addEdge(graph, 3, 4, 9);
  addEdge(graph, 4, 5, 10);

  dijkstra(graph, 0);
  cout << endl;
  destroyGraph();
}

void runBellmanFord() {
  cout << "### Bellman-Ford ###" << endl;

  verticesNumber = 5;
  int** graph = createGraph(verticesNumber);

  addEdge(graph, 0, 1, -1);
  addEdge(graph, 0, 2, 4);
  addEdge(graph, 1, 2, 3);
  addEdge(graph, 3, 2, 5);
  addEdge(graph, 1, 3, 1);
  addEdge(graph, 1, 3, 2);
  addEdge(graph, 1, 4, 2);
  addEdge(graph, 4, 3, -3);

  bellmanFord(graph, 0);
  cout << endl;
  destroyGraph();
}

void runKruskal() {
  cout << "### Kruskal ###" << endl;

  verticesNumber = 9;
  int** graph = createGraph(verticesNumber);

  addEdge(graph, 0, 1, 4);
  addEdge(graph, 0, 7, 8);
  addEdge(graph, 1, 7, 11);
  addEdge(graph, 1, 2, 8);
  addEdge(graph, 2, 8, 2);
  addEdge(graph, 7, 8, 7);
  addEdge(graph, 7, 6, 1);
  addEdge(graph, 6, 8, 6);
  addEdge(graph, 6, 5, 2);
  addEdge(graph, 2, 3, 7);
  addEdge(graph, 2, 5, 4);
  addEdge(graph, 3, 5, 14);
  addEdge(graph, 3, 4, 9);
  addEdge(graph, 4, 5, 10);

  kruskal(graph);
  cout << endl;
  destroyGraph();
}

void runPrim() {
  cout << "### Prim ###" << endl;

  verticesNumber = 9;
  int** graph = createGraph(verticesNumber);

  addDoubleEdge(graph, 0, 1, 4);
  addDoubleEdge(graph, 0, 7, 8);
  addDoubleEdge(graph, 1, 7, 11);
  addDoubleEdge(graph, 1, 2, 8);
  addDoubleEdge(graph, 2, 8, 2); 
  addDoubleEdge(graph, 7, 8, 7);
  addDoubleEdge(graph, 7, 6, 1);
  addDoubleEdge(graph, 6, 8, 6);
  addDoubleEdge(graph, 6, 5, 2);
  addDoubleEdge(graph, 2, 3, 7);
  addDoubleEdge(graph, 2, 5, 4);
  addDoubleEdge(graph, 3, 5, 14);
  addDoubleEdge(graph, 3, 4, 9); 
  addDoubleEdge(graph, 4, 5, 10);

  prim(graph);
  cout << endl;
  destroyGraph();
}

void runFordFulkerson() {
  cout << "### Ford-Fulkerson ###" << endl;

  verticesNumber = 6;
  int** graph = createGraph(verticesNumber);

  addEdge(graph, 0, 1, 16);
  addEdge(graph, 0, 2, 13);
  addEdge(graph, 1, 2, 10);
  addEdge(graph, 2, 1, 4);
  addEdge(graph, 1, 3, 12);
  addEdge(graph, 3, 2, 9);
  addEdge(graph, 2, 4, 14);
  addEdge(graph, 4, 3, 7);
  addEdge(graph, 3, 5, 20);
  addEdge(graph, 4, 5, 4);

  fordFulkerson(graph, 0, 5);
  cout << endl;
  destroyGraph();
}

int main() {
  runDijkstra();
  runBellmanFord();
  runKruskal();
  runPrim();
  runFordFulkerson();  
  return 0;
}
