#include "7.h"
#include <stdio.h>
#include <stdlib.h>

Node *
getNode (int n)
{
  Node *newnode = (Node *)malloc (sizeof (Node));
  newnode->data = n;
  newnode->left = newnode->right = NULL;

  return newnode;
}

Node *
createLevelOrderTree (int *arr, Node *root, int i, int n)
{
  if (i < n)
    {
      root = getNode (arr[i]);

      root->left = createLevelOrderTree (arr, root->left, 2 * i + 1, n);
      root->right = createLevelOrderTree (arr, root->right, 2 * i + 2, n);
    }
  return root;
}

int
height (Node *node)
{
  if (node == NULL)
    return 0;
  else
    {
      int lheight = height (node->left);
      int rheight = height (node->right);
      if (lheight > rheight)
        return (lheight + 1);
      else
        return (rheight + 1);
    }
}

void
CurrentLevel (Node *root, int level)
{
  if (root == NULL)
    return;
  if (level == 1)
    printf ("%d ", root->data);
  else if (level > 1)
    {
      CurrentLevel (root->left, level - 1);
      CurrentLevel (root->right, level - 1);
    }
}

void
LevelOrder (Node *root)
{
  int h = height (root);
  int i;
  for (i = 1; i <= h; i++)
    CurrentLevel (root, i);
}

void
preorder_traveral (Node *root)
{
  if (root == NULL)
    {
      return;
    }
  printf ("%d ", root->data);

  preorder_traveral (root->left);
  preorder_traveral (root->right);
}

void
postorder_traversal (Node *root)
{
  if (root == NULL)
    {
      return;
    }
  postorder_traversal (root->left);
  postorder_traversal (root->right);

  printf ("%d ", root->data);
}

void
inorder_traversal (Node *root)
{
  if (root == NULL)
    {
      return;
    }
  inorder_traversal (root->left);
  printf ("%d ", root->data);
  inorder_traversal (root->right);
}

// Args: inorder, start index, end index, value
int
findIndex (int inorder[], int start, int end, int value)
{
  for (int i = start; i <= end; ++i)
    {
      if (inorder[i] == value)
        {
          return i;
        }
    }
    return -1; // Not found
}

// Args: preorder, inorder, start index, end index, pre index
Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    
    Node* root = getNode(preorder[*preIndex]);
    (*preIndex)++;

    // Find the index of the current element in inorder array
    int inIndex = findIndex(inorder, inStart, inEnd, root->data);

    // Recursively build left and right subtrees
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}
