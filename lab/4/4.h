#ifndef _4_H
#define _4_H

#include "../../lib/struct/sll.h"

typedef struct Queue
{
  SingleNetworkNode *front;
  SingleNetworkNode *rear;
  size_t length;
} Queue;

void newQueue (Queue *);
void freeQueue (Queue *);

void enqueue (Queue *, Network);
void dequeue (Queue *);

void printQueue (Queue *);

int queueEmpty (Queue *);
int queueNotEmpty (Queue *);

unsigned int getPriority (const Network *);
#endif // _4_H
