#include "7.h"
#include <stdio.h>
#include <stdlib.h>

void
print_array (int *arr, int n)
{
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", arr[i]);
    }
}

int
main ()
{
  int arr[] = { 9, 3, 15, 20, 7 };
  Node *root;
  printf ("\nCreating level order tree for array: ");
  print_array (arr, sizeof (arr) / sizeof (int));

  root = createLevelOrderTree (arr, root, 0, sizeof (arr) / sizeof (int));
  printf ("\nLevel Order traversal: ");
  LevelOrder (root);

  int inorder[] = { 9, 3, 15, 20, 7 };
  int preorder[] = { 3, 9, 20, 15, 7 };

  int preindex = 0;
  int size = sizeof (preorder) / sizeof (int);
  printf ("\n\nCreating binary tree...\n");
  root = buildTree (preorder, inorder, 0, size - 1, &preindex);

  printf ("\nTravesal of tree.");
  printf ("\nInorder: ");
  inorder_traversal (root);
  printf ("\nPreorder: ");
  preorder_traveral (root);

  free (root);

  return 0;
}
