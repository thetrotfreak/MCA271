#include "2.h"
#include <stdio.h>

int
main ()
{
  NetworkNode *singlyLinkedList = NULL;

  // Insert nodes at the beginning
  insertNodeAtBeginning (&singlyLinkedList,
                         (Network){ (Warehouse){ "W1", 100 },
                                    (Outlet){ "O1", 50 }, ROAD, 200, 30 }

  );
  insertNodeAtBeginning (
      &singlyLinkedList,
      (Network){ (Warehouse){ "W2", 200 }, (Outlet){ "O2", 60 }, AIR, 300, 40 }

  );
  insertNodeAtBeginning (&singlyLinkedList,
                         (Network){ (Warehouse){ "W3", 300 },
                                    (Outlet){ "O3", 70 }, ROAD, 400, 50 }

  );

  // Print the list
  printf ("Singly Linked List:\n");
  printList (singlyLinkedList);

  // Delete a node based on cost
  deleteNode (&singlyLinkedList, 200);

  // Print the updated list
  printf ("\nList after deletion:\n");
  printList (singlyLinkedList);

  // Search for a node based on cost
  NetworkNode *searchResult = searchNode (singlyLinkedList, 400);
  if (searchResult != NULL)
    {
      printf ("\nNode found: Cost %u\n", searchResult->network.cost);
    }
  else
    {
      printf ("\nNode not found\n");
    }

  // Free the memory
  freeList (&singlyLinkedList);

  return 0;
}
