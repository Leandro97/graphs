void bellmanFord(int** graph, int verticeId) {
  cout << "Minimum cost starting at " << verticeId << ":" << endl; 
  int V = verticesNumber; 
  int E = edgesNumber; 
  int dist[V]; 

  for (int i = 0; i < V; i++) 
    dist[i] = INT_MAX; 
  dist[verticeId] = 0; 

  for (int i = 1; i <= V - 1; i++) { 
    for (int j = 0; j < E; j++) { 
      int u      = edges[j].src; 
      int v      = edges[j].dest; 
      int weight = edges[j].cost; 

      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
          dist[v] = dist[u] + weight; 
    } 
  } 
  for (int i = 0; i < E; i++) { 
    int u      = edges[i].src; 
    int v      = edges[i].dest; 
    int weight = edges[i].cost; 

    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
      printf("Graph contains negative weight cycle"); 
      return; // If negative cycle is detected, simply return 
    } 
  }

  for (int i = 0; i < verticesNumber; i++) {
    cout << "(" << verticeId << ", " << i << ", " << dist[i] << ")" << endl;
  }
  return; 
} 