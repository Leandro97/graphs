#include "../graph.c"
void dijkstra(int** graph, int verticeId){
  cout << "Minimum cost starting at " << verticeId << ":" << endl;

  int vertices[verticesNumber];
	iota(vertices, vertices + verticesNumber, 0);

  int verticeIndex;
  int dist[verticesNumber];
  int visited[verticesNumber];
  int i, visitedCounter = 0, loopCounter = 0;
  
  for (int i = 0; i < verticesNumber; i++) {
    if (i == verticeId) {
      dist[i]      = 0;
      verticeIndex = i;
    } else {
      dist[i] = INT_MAX;
    }
    visited[i] = 0;
  }
  
  do {
    myNeighbors neighbors = getVerticeNeighbors(graph, verticeIndex);

    for (int i = 0; i < neighbors.size(); i++) {
      int neighborIndex = get<0>(neighbors.at(i));
      int cost          = dist[verticeIndex] + get<1>(neighbors.at(i));
    
      //cout << "To " << neighborIndex << ". Cost: " << dist[neighborIndex] << "\n";

      if (dist[neighborIndex] > cost) {
        dist[neighborIndex] = cost;

        //cout << "To " << neighborIndex << ". Updated cost: " << dist[neighborIndex] << "\n";
      }
    }

    visited[verticeIndex] = 1;
    visitedCounter++;
    
    int min = 999999;
    for (int i = 0; i < verticesNumber; i++) {
        if (!visited[i] && dist[i] < min) {
          verticeIndex = i;
          min          = dist[i];
        }
    }

    //cout << "\n";
  } while (visitedCounter < verticesNumber);
  
  for (int i = 0; i < verticesNumber; i++) {
    cout << "(" << verticeId << ", " << i << ", " << dist[i] << ")" << endl;
  }
}

int main() {
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
  return 0;
}