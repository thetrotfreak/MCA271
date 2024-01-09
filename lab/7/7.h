#ifndef _7_H_
#define _7_H_

#include "domain.h"

typedef struct binary_node_t
{
  struct binary_node_t *left;
  Outlet key;
  struct binary_node_t *right;
} BinaryTree;

size_t getSizeBT (BinaryTree *t);
size_t getHeight (BinaryTree *t);

BinaryTree *constructBT (const Outlet *nodelist, size_t nmemb,
                         int isDepthOrder);
void deconstructBT (BinaryTree *t);

BinaryTree *initDepthBT (const Outlet *nodelist, size_t nmemb);
BinaryTree *initLevelBT (const Outlet *nodelist, size_t nmemb);

void traverseInOrder (BinaryTree *t);
void traversePreOrder (BinaryTree *t);
void traversePostOrder (BinaryTree *t);

void reconstructBT (const Outlet *preorder, const Outlet *inorder,
                    size_t nmemb);

#endif // _7_H_
