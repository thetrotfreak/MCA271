#ifndef _9_H
#define _9_H

#define MAX_VERTICES 100

// Graph structure using adjacency matrix
typedef struct
{
  int vertices;
  int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to initialize a graph
void initializeGraph (Graph *graph, int vertices);

// Function to add an edge to the graph
void addEdge (Graph *graph, int start, int end);

// Depth-First Traversal (Recursive)
void DFT (Graph *graph, int vertex, int visited[]);

// Breadth-First Traversal (Iterative)
void BFT (Graph *graph, int start);

// BFT Search
int searchBFT (Graph *graph, int start, int target);

// DFT Search
int searchDFT (Graph *graph, int start, int target, int visited[]);
int searchDFTRecursive (Graph *graph, int start, int target, int visited[]);

#endif
