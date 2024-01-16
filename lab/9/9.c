#include "9.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
initializeGraph (Graph *graph, int vertices)
{
  graph->vertices = vertices;

  // Initialize adjacency matrix with zeros
  memset (graph->adjacencyMatrix, 0, sizeof (graph->adjacencyMatrix));
}

void
addEdge (Graph *graph, int start, int end)
{
  // Assuming an undirected graph
  graph->adjacencyMatrix[start][end] = 1;
  graph->adjacencyMatrix[end][start] = 1;
}

void
DFT (Graph *graph, int vertex, int visited[])
{
  if (visited[vertex])
    {
      return;
    }

  printf ("%d ", vertex);
  visited[vertex] = 1;

  for (int i = 0; i < graph->vertices; ++i)
    {
      if (graph->adjacencyMatrix[vertex][i] && !visited[i])
        {
          DFT (graph, i, visited);
        }
    }
}

void
BFT (Graph *graph, int start)
{
  int visited[MAX_VERTICES] = { 0 };
  int queue[MAX_VERTICES];
  int front = 0, rear = 0;

  printf ("BFT starting from %d: ", start);
  printf ("%d ", start);
  visited[start] = 1;
  queue[rear++] = start;

  while (front < rear)
    {
      int currentVertex = queue[front++];

      for (int i = 0; i < graph->vertices; ++i)
        {
          if (graph->adjacencyMatrix[currentVertex][i] && !visited[i])
            {
              printf ("%d ", i);
              visited[i] = 1;
              queue[rear++] = i;
            }
        }
    }

  printf ("\n");
}

int searchDFT(Graph *graph, int start, int target, int visited[]) {
    visited[start] = 0;  // Reset the visited array
    return searchDFTRecursive(graph, start, target, visited);
}

int
searchDFTRecursive (Graph *graph, int start, int target, int visited[])
{
    if (start == target) {
        printf("Vertex %d found using DFT.\n", target);
        return 1;
    }

    visited[start] = 1;

    for (int i = 0; i < graph->vertices; ++i) {
        if (graph->adjacencyMatrix[start][i] && !visited[i]) {
            if (searchDFTRecursive(graph, i, target, visited)) {
                return 1;
            }
        }
    }

    return 0;
}

// Search using Breadth-First Traversal
int
searchBFT (Graph *graph, int start, int target)
{
  int visited[MAX_VERTICES] = { 0 };
  int queue[MAX_VERTICES];
  int front = 0, rear = 0;

  visited[start] = 1;
  queue[rear++] = start;

  while (front < rear)
    {
      int currentVertex = queue[front++];

      if (currentVertex == target)
        {
          printf ("Vertex %d found using BFT.\n", target);
          return 1;
        }

      for (int i = 0; i < graph->vertices; ++i)
        {
          if (graph->adjacencyMatrix[currentVertex][i] && !visited[i])
            {
              visited[i] = 1;
              queue[rear++] = i;
            }
        }
    }

  return 0;
}

int
main ()
{
  Graph graph;
  int vertices, edges;

  printf ("Enter the number of vertices: ");
  scanf ("%d", &vertices);

  printf ("Enter the number of edges: ");
  scanf ("%d", &edges);

  initializeGraph (&graph, vertices);

  printf ("Enter the edges (start end):\n");
  for (int i = 0; i < edges; ++i)
    {
      int start, end;
      scanf ("%d %d", &start, &end);
      addEdge (&graph, start, end);
    }

  int startVertex;
  printf ("Enter the starting vertex for traversal: ");
  scanf ("%d", &startVertex);

  int visited[MAX_VERTICES] = { 0 };
  printf ("DFT starting from %d: ", startVertex);
  DFT (&graph, startVertex, visited);
  printf ("\n");

  BFT (&graph, startVertex);

  int targetVertexDFT;
  printf ("Enter the target vertex for DFT search: ");
  scanf ("%d", &targetVertexDFT);
  if (!searchDFT (&graph, startVertex, targetVertexDFT, visited))
    {
      printf ("Vertex %d not found using DFT.\n", targetVertexDFT);
    }

  int targetVertexBFT;
  printf ("Enter the target vertex for BFT search: ");
  scanf ("%d", &targetVertexBFT);
  if (!searchBFT (&graph, startVertex, targetVertexBFT))
    {
      printf ("Vertex %d not found using BFT.\n", targetVertexBFT);
    }
  return 0;
}
