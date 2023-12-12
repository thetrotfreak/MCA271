#ifndef _SLL_H
#define _SLL_H

#include "domain.h"
#include <stddef.h>

typedef struct SingleNetworkNode
{
  Network network;
  struct SingleNetworkNode *next;
} SingleNetworkNode;

typedef struct SinglyLinkedList
{
  SingleNetworkNode *head;
  size_t size;
} SLL;

// static SingleNetworkNode *createNode (Network);
SingleNetworkNode *createNode (Network);

/* Read:
 * https://stackoverflow.com/questions/32715339/does-passing-pointer-to-structure-to-a-function-create-local-copies-of-it-in-c
 */
void freeList (SingleNetworkNode **);
void freeNode (SingleNetworkNode **, unsigned int);
void appendNode (SingleNetworkNode **, Network);

/* v2 methods for this list
 * we'll wrap list relevant metadata
 * inside a struct
 * saving us the hassle of double pointers
 * as well as giving a cleaner code
 * this will also bring optimizations
 * with the introduction of the tail pointer
 */
void newList_v2 (SLL *);
void freeList_v2 (SLL *);
void append_v2 (SLL *, Network);
void prepend_v2 (SLL *, Network);
void insertAt_v2 (SLL *, Network, unsigned int);
void insertAfter_v2 (SLL *, Network, unsigned int);
void insertBefore_v2 (SLL *, Network, unsigned int);
void delete_v2 (SLL *);
void printList (SLL *);
void printNetwork (Network);

#endif // _SLL_H
