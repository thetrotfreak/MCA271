#ifndef DLL_H
#define DLL_H

#include "domain.h"
#include <stddef.h>

typedef struct DoubleNetworkNode
{
  Network network;
  struct DoubleNetworkNode *next;
  struct DoubleNetworkNode *prev;
} DoubleNetworkNode;

typedef struct DoublyLinkedList
{
  DoubleNetworkNode *head;
  DoubleNetworkNode *tail;
  size_t size;
} DLL;

static DoubleNetworkNode *createNode (Network);

/* Read:
 * https://stackoverflow.com/questions/32715339/does-passing-pointer-to-structure-to-a-function-create-local-copies-of-it-in-c
 */
// void freeList (DoubleNetworkNode **);
// void freeNode (DoubleNetworkNode **, unsigned int);
// void appendNode (DoubleNetworkNode **, Network);

/* v2 methods for this list
 * we'll wrap list relevant metadata
 * inside a struct
 * saving us the hassle of double pointers
 * as well as giving a cleaner code
 * this will also bring optimizations
 * with the introduction of the tail pointer
 */
void newList_v2 (DLL *);
void freeList_v2 (DLL *);
void append_v2 (DLL *, Network);
void prepend_v2 (DLL *, Network);
void insertAt_v2 (DLL *, Network, unsigned int);
void insertAfter_v2 (DLL *, Network, unsigned int);
void insertBefore_v2 (DLL *, Network, unsigned int);
void delete_v2 (DLL *, unsigned int);

#endif // DLL_H
