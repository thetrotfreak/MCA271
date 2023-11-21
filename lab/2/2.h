#ifndef _2_H
#define _2_H

#include "domain.h"

NetworkNode *createNode (Network);
NetworkNode *searchNode (NetworkNode *, unsigned int);
void deleteNode (NetworkNode **, unsigned int);
void freeList (NetworkNode **);
void insertNodeAtBeginning (NetworkNode **, Network);
void printList (NetworkNode *);

#endif //_2_H
