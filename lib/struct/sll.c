#include "sll.h"
#include <stdio.h>
#include <stdlib.h>

SingleNetworkNode *
createNode (Network network)
{

  SingleNetworkNode *newNode
      = (SingleNetworkNode *)calloc (1, sizeof (SingleNetworkNode));
  if (newNode == NULL)
    {
      fprintf (stderr, "Memory allocation error\n");
      /* TODO:
       * we don't wanna exit(1) the program
       * without any cleanup
       * just becuase a node creation failed
       */

      exit (1);
    }

  newNode->network = network;
  return newNode;
}

// void
// appendNode (SingleNetworkNode **head, Network network)
// {
//   SingleNetworkNode *newNode = createNode (network);
//   if (*head == NULL)
//     {
//       *head = newNode;
//       newNode->prev = NULL;
//     }
//   else
//     {
//       SingleNetworkNode *current = *head;
//       while (current->next != NULL)
//         {
//           current = current->next;
//         }
//       current->next = newNode;
//       newNode->prev = current;
//     }
// }
//
// void
// freeList (SingleNetworkNode **head)
// {
//   SingleNetworkNode *current = *head;
//   SingleNetworkNode *next;
//   while (current != NULL)
//     {
//       next = current->next;
//       free (current);
//       current = next;
//     }
//   *head = NULL;
// }

void
newList_v2 (SLL *sll)
{
  sll->head = NULL;
  sll->size = 0;
}

void
freeList_v2 (SLL *sll)
{
  // if (sll->head != NULL && sll->size != 0)
  //   {
  //     SingleNetworkNode *current = sll->head;
  //     SingleNetworkNode *next;
  //     while (current != NULL)
  //       {
  //         next = current->next;
  //         free (current);
  //         current = next;
  //       }
  //   }
  SingleNetworkNode *current = sll->head;
  SingleNetworkNode *next;
  while (current != NULL)
    {
      next = current->next;
      free (current);
      current = next;
    }
  newList_v2 (sll);
}

// void
// prepend_v2 (SLL *sll, Network network)
// {
//   SingleNetworkNode *newNode = createNode (network);
//   if (sll->head == NULL)
//     {
//       // list is empty
//       sll->head = newNode;
//       sll->size++;
//       return;
//     }
//   // list is non-empty
//   // list has >=1 node
//   newNode->next = sll->head;
//   sll->head = newNode;
//   sll->size++;
// }

void
append_v2 (SLL *sll, Network network)
{
  SingleNetworkNode *newNode = createNode (network);

  if (sll->head == NULL)
    {
      sll->head = newNode;
      sll->size++;
      return;
    }
  SingleNetworkNode *temp = sll->head;
  while (temp->next != NULL)
    {
      temp = temp->next;
    }
  temp->next = newNode;
  sll->size++;
}

void
delete_v2 (SLL *sll)
{
  if (sll->head != NULL)
    {
      SingleNetworkNode *temp = sll->head;
      sll->head = sll->head->next;
      free (temp);
      sll->size--;
    }
}

void
printList (SLL *sll)
{
  if (sll->head != NULL)
    {
      SingleNetworkNode *temp = sll->head;
      while (temp != NULL)
        {
          printNetwork (temp->network);
          temp = temp->next;
        }
    }
}

void
printNetwork (Network n)
{
  printf ("From    : %s\n", n.from.name);
  printf ("To      : %s\n", n.to.name);
  printf ("Mode    : %d\n", n.mode);
  printf ("Distance: %d\n", n.distance);
  printf ("Cost    : %d\n", n.cost);
}
