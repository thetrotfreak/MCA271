#include "7.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
isLeaf (BinaryTree *t)
{
  return t->left == NULL && t->right == NULL ? 1 : 0;
  return t == NULL ? 0 : 1;
}

size_t
getSizeBT (BinaryTree *t)
{
  return isLeaf (t) ? 0 : 1 + getSizeBT (t->left) + getSizeBT (t->right);
}

BinaryTree *
constructBT (const Outlet *nodelist, size_t nmemb, int isDepthOrder)
{
  size_t height = 
  BinaryTree *root = (Outlet *)malloc (sizeof (Outlet));
  if (root == NULL)
    {
      return NULL
    };
  root.key = nodelist;
  root.left = NULL;
  root.right = NULL;
  for (size_t i = 1; i < nmemb; i++)
    {
      
    }
}

BinaryTree *
initDepthBT (const Outlet *nodelist, size_t nmemb)
{
  BinaryTree *bt = constructBT (nodelist, nmemb, 1);
  return bt;
}

BinaryTree *
initLevelBT (const Outlet *nodelist, size_t nmemb)
{
  BinaryTree *bt = constructBT (nodelist, nmemb, 0);
  return bt;
}
