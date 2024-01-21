#ifndef MST_H
#define MST_H

// Kruskal
#define MAX 30

typedef struct edge
{
  int u, v, w;
} edge;

typedef struct edge_list
{
  edge data[MAX];
  int n;
} edge_list;

void kruskalAlgo (void);
int find (int belongs[], int vertexno);
void applyUnion (int belongs[], int c1, int c2);
void sort ();
void print ();

// Prim
#define INF 9999999

// number of vertices in graph
#define V 5
#endif
