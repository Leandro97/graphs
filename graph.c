#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int verticesNumber;
int edgesNumber = 0;

struct Edge {
  int src;
  int dest;
  int cost;
};

typedef vector<Edge> edgeList;
edgeList edges; 

typedef vector<tuple<int, int>> myNeighbors;

int** createGraph(unsigned verticesNumber) {
  int** graph = 0;
  graph = new int*[verticesNumber];

  for(int row = 0; row < verticesNumber; row++) {
    graph[row] = new int[verticesNumber];

    for(int col = 0; col < verticesNumber; col++){
      graph[row][col] = -1;
    }
  }

  return graph;
}

void destroyGraph() {
  edges.clear();
  verticesNumber = 0;
  edgesNumber = 0;
}

void addEdge(int** graph, int src, int dest, int cost) {
  graph[src][dest] = cost;
  
  Edge newEdge;
  newEdge.src = src;
  newEdge.dest = dest;
  newEdge.cost = cost;

  edges.push_back(newEdge);
  edgesNumber += 1;
}

void addDoubleEdge(int** graph, int src, int dest, int cost) {
  addEdge(graph, src, dest, cost);
  addEdge(graph, dest, src, cost);
}
void printGraph(int ** graph) {
  for(int i = 0; i < edges.size(); i++) {
    cout << "(" << edges.at(i).src << ", " << edges.at(i).dest << ", " << edges.at(i).cost << ")" << endl;  
  }
}

myNeighbors getVerticeNeighbors(int** graph, int verticeId) {
  myNeighbors neighbors; 

  for(int i = 0; i < verticesNumber; i++) {
    if (graph[verticeId][i] != -1) {
      neighbors.push_back(tuple<int, int> (i, graph[verticeId][i]));
    }
  }

  return neighbors;
}
