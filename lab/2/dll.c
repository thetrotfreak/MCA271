#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

static DoubleNetworkNode *
createNode (Network network)
{

  DoubleNetworkNode *newNode
      = (DoubleNetworkNode *)calloc (1, sizeof (DoubleNetworkNode));
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

void
appendNode (DoubleNetworkNode **head, Network network)
{
  DoubleNetworkNode *newNode = createNode (network);
  if (*head == NULL)
    {
      *head = newNode;
      newNode->prev = NULL;
    }
  else
    {
      DoubleNetworkNode *current = *head;
      while (current->next != NULL)
        {
          current = current->next;
        }
      current->next = newNode;
      newNode->prev = current;
    }
}

void
freeList (DoubleNetworkNode **head)
{
  DoubleNetworkNode *current = *head;
  DoubleNetworkNode *next;
  while (current != NULL)
    {
      next = current->next;
      free (current);
      current = next;
    }
  *head = NULL;
}

void
newList_v2 (DLL *dll)
{
  dll->head = NULL;
  dll->tail = NULL;
  dll->size = 0;
}

void
freeList_v2 (DLL *dll)
{
  if (dll->head != NULL && dll->tail != NULL && dll->size != 0)
    {
      DoubleNetworkNode *current = dll->head;
      DoubleNetworkNode *next;
      while (current != NULL)
        {
          next = current->next;
          free (current);
          current = next;
        }
    }
  newList_v2 (dll);
}

void
prepend_v2 (DLL *dll, Network network)
{
  DoubleNetworkNode *newNode = createNode (network);
  if (dll->head == NULL)
    {
      // list is empty
      dll->head = newNode;
      dll->tail = newNode;
      dll->size += 1;
      return;
    }
  // list is non-empty
  // list has >=1 node
  newNode->next = dll->head;
  newNode->prev = NULL;
  dll->head = newNode;
  dll->size += 1;
}
