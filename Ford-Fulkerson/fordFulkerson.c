#include "../graph.c"
#include <queue> 

bool bfs(int** graph, int s, int t, int parent[]) { 
	bool visited[verticesNumber]; 
	memset(visited, 0, sizeof(visited)); 

	queue <int> q; 
	q.push(s); 
	visited[s] = true; 
	parent[s] = -1; 

	while (!q.empty()) { 
		int u = q.front(); 
		q.pop(); 

		for (int v = 0; v < verticesNumber; v++) { 
			if (visited[v] == false && graph[u][v] > 0) { 
				q.push(v); 
				parent[v] = u; 
				visited[v] = true; 
			} 
		} 
	} 

	return (visited[t] == true); 
} 

void fordFulkerson(int** graph, int s, int t) { 
	int u, v; 

	int parent[verticesNumber];
	int max_flow = 0; 

	while(bfs(graph, s, t, parent)) { 
		int path_flow = INT_MAX; 
		for (v = t; v != s; v = parent[v]) { 
			u = parent[v]; 
			path_flow = min(path_flow, graph[u][v]); 
		} 

		for (v = t; v != s; v = parent[v]) { 
			u = parent[v]; 
			graph[u][v] -= path_flow; 
			graph[v][u] += path_flow; 
		} 

		max_flow += path_flow; 
	} 

	cout << "Max flow: " << max_flow << endl; 
}

int main() {
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
  return 0;
}