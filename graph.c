#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<tuple<int, int, int>> my_edges;
my_edges edges; 

typedef vector<tuple<int, int>> my_neighbors;

int verticesNumber;

int** createGraph(unsigned verticesNumber) {
  int** graph = 0;
  graph = new int*[verticesNumber];

  for(int row = 0; row < verticesNumber; row++) {
    graph[row] = new int[verticesNumber];

    for(int col = 0; col < verticesNumber; col++){
      graph[row][col] = 999999;
    }
  }

  return graph;
}

void addEdge(int** graph, int origin, int end, int cost) {
  graph[origin][end] = cost;
  edges.push_back(tuple<int, int, int> (origin, end, cost));
}

void addDoubleEdge(int** graph, int origin, int end, int cost) {
  addEdge(graph, origin, end, cost);
  addEdge(graph, end, origin, cost);
}
void printGraph(int ** graph) {
  for(const auto& i : edges) {
    cout << "(" << get<0>(i) << ", " << get<1>(i)<< ", " << get<2>(i) << ")" << endl;
  }
}

my_neighbors getVerticeNeighbors(int** graph, int verticeId) {
  my_neighbors neighbors; 

  for(int i = 0; i < verticesNumber; i++) {
    if (graph[verticeId][i] != 999999) {
      neighbors.push_back(tuple<int, int> (i, graph[verticeId][i]));
    }
  }

  return neighbors;
}
