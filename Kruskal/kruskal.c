#include "../graph.c"
#include <algorithm>

class subset {  
  public:
    int parent;  
    int rank;  
};  
  
int find(subset subsets[], int i) {   
  if (subsets[i].parent != i)  
    subsets[i].parent = find(subsets, subsets[i].parent);  

  return subsets[i].parent;  
}  
  
void Union(subset subsets[], int x, int y)  {  
  int xroot = find(subsets, x);  
  int yroot = find(subsets, y);  

  if (subsets[xroot].rank < subsets[yroot].rank)  
    subsets[xroot].parent = yroot;  
  else if (subsets[xroot].rank > subsets[yroot].rank)  
    subsets[yroot].parent = xroot;  
  else {  
    subsets[yroot].parent = xroot;  
    subsets[xroot].rank++;  
  }  
}  
  
int myComp(const Edge &a, const Edge &b) {   
  return a.cost < b.cost;  
}  
  
void kruskal(int** graph) {   
  Edge result[verticesNumber]; // Tnis will store the resultant MST  

/*
  Edge myEdges[edges.size()];
  std::copy(edges.begin(), edges.end(), myEdges);
*/
  int e = 0; // An index variable, used for result[]
  int i = 0; // An index variable, used for sorted edges  

  std::sort(edges.begin(), edges.end(), myComp);  

  // Allocate memory for creating V ssubsets  
  subset *subsets = new subset[(verticesNumber * sizeof(subset))];  

  // Create V subsets with single elements  
  for (int v = 0; v < verticesNumber; ++v) {  
      subsets[v].parent = v;  
      subsets[v].rank = 0;  
  }  

  // Number of edges to be taken is equal to V-1  
  while (e < verticesNumber - 1 && i < edges.size()) {  
    Edge next_edge = edges[i++];  

    int x = find(subsets, next_edge.src);  
    int y = find(subsets, next_edge.dest);  

    if (x != y) {  
      result[e++] = next_edge;  
      Union(subsets, x, y);  
    }  
  }  

  int cost = 0;
  cout << "MST:" << endl;  
  for (i = 0; i < e; ++i) {
    cout << "(" << result[i].src << ", " << result[i].dest << ", " << result[i].cost << ")" << endl;
    cost += result[i].cost;
  }
  cout << "Total cost: " << cost << endl;  
  return;  
}

int main() {
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
  return 0;
}