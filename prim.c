int minKey(int key[], bool mstSet[]) { 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < verticesNumber; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 

void printMST(int parent[], int** graph) {  
  int cost = 0;
  for (int i = 1; i < verticesNumber; i++) { 
    cout << "(" << parent[i] << ", " << i << ", " << graph[i][parent[i]] << ")" << endl; 
    cost += graph[i][parent[i]];
  }  
   cout << "Total cost: " << cost << endl;
} 

void prim(int** graph) { 
	int parent[verticesNumber]; 
	int key[verticesNumber]; 
	bool mstSet[verticesNumber]; 

	for (int i = 0; i < verticesNumber; i++) {
		key[i] = INT_MAX, mstSet[i] = false; 
  }

	key[0] = 0; 
	parent[0] = -1;

  int cost = 0;
  cout << "MST:" << endl;  
	for (int count = 0; count < verticesNumber - 1; count++) {
		int u = minKey(key, mstSet); 
		mstSet[u] = true; 

		for (int v = 0; v < verticesNumber; v++) {
			if (graph[u][v] != -1 && mstSet[v] == false && graph[u][v] < key[v]) {
				parent[v] = u;
        key[v] = graph[u][v];
        cost += key[v];
      } 
    }
	} 

  printMST(parent, graph); 
}