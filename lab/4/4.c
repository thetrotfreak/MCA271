#include "4.h"
#include <stdio.h>
#include <stdlib.h>

void
newQueue (Queue *q)
{
  q->front = NULL;
  q->rear = NULL;
  q->length = 0;
}

void
freeQueue (Queue *q)
{
  if (queueNotEmpty (q))
    {
      SingleNetworkNode *temp = q->front;
      while (temp != NULL)
        {
          q->front = q->front->next;
          free (temp);
          temp = q->front;
        }
      newQueue (q);
    }
}

void
enqueue (Queue *q, Network network)
{
  SingleNetworkNode *node = createNode (network);
  if (queueEmpty (q))
    {
      q->front = node;
      q->rear = node;
    }
  else
    {
      q->rear->next = node;
      q->rear = node;
    }
  q->length++;
}

void
dequeue (Queue *q)
{
  if (queueNotEmpty (q))
    {
      SingleNetworkNode *temp = q->front;
      q->front = q->front->next;
      free (temp);
      q->length--;
    }
}

void
printQueue (Queue *q)
{
  if (queueNotEmpty (q))
    {
      SingleNetworkNode *temp = q->front;
      while (temp != NULL)
        {
          printNetwork (temp->network);
          temp = temp->next;
        }
    }
}

int
queueNotEmpty (Queue *q)
{
  return (q != NULL && q->front != NULL && q->rear != NULL) ? 1 : 0;
}

int
queueEmpty (Queue *q)
{
  return (q != NULL && q->front == NULL && q->rear == NULL) ? 1 : 0;
}
