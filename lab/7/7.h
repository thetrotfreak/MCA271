#ifndef _7_H
#define _7_H

typedef struct Node
{
  struct Node *left;
  int data;
  struct Node *right;
} Node;

Node *getNode (int n);
Node *createLevelOrderTree (int *, Node *, int, int);

void preorder_traveral (Node *);
void postorder_traversal (Node *);
void inorder_traversal (Node *);

int height (Node *);
void CurrentLevel (Node *, int);
void LevelOrder (Node *root);

int findIndex (int[], int, int, int);
Node *buildTree (int[], int[], int, int, int *);

#endif
