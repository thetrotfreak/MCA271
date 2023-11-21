#include "2.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node
NetworkNode *
createNode (Network n)
{
  NetworkNode *newNode = (NetworkNode *)malloc (sizeof (NetworkNode));
  if (newNode == NULL)
    {
      fprintf (stderr, "Memory allocation error\n");
      exit (1);
    }

  newNode->network = n;
  newNode->next = NULL;

  return newNode;
}

// Function to insert a new node at the beginning of the linked list
void
insertNodeAtBeginning (NetworkNode **head, Network n)
{
  NetworkNode *newNode = createNode (n);
  newNode->next = *head;
  *head = newNode;
}

// Function to delete a node with a specific condition (e.g., based on cost)
void
deleteNode (NetworkNode **head, unsigned int targetCost)
{
  NetworkNode *current = *head;
  NetworkNode *prev = NULL;

  while (current != NULL && current->network.cost != targetCost)
    {
      prev = current;
      current = current->next;
    }

  if (current == NULL)
    {
      printf ("Node with cost %u not found\n", targetCost);
      return;
    }

  if (prev == NULL)
    {
      // The target node is the head
      *head = current->next;
    }
  else
    {
      prev->next = current->next;
    }

  free (current);
}

// Function to search for a node based on a condition (e.g., search by cost)
NetworkNode *
searchNode (NetworkNode *head, unsigned int targetCost)
{
  NetworkNode *current = head;

  while (current != NULL)
    {
      if (current->network.cost == targetCost)
        {
          return current;
        }
      current = current->next;
    }

  return NULL; // Node not found
}

// Function to print the linked list
void
printList (NetworkNode *head)
{
  NetworkNode *current = head;

  while (current != NULL)
    {
      printf ("From: %s, To: %s, Mode: %d, Cost: %u, Distance: %u\n",
              current->network.from.name, current->network.to.name,
              current->network.mode, current->network.cost,
              current->network.distance);
      current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void
freeList (NetworkNode **head)
{
  NetworkNode *current = *head;
  NetworkNode *next;

  while (current != NULL)
    {
      next = current->next;
      free (current);
      current = next;
    }

  *head = NULL; // Set the head to NULL after freeing all nodes
}
