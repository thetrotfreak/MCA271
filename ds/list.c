#include "list.h"
#include <stdio.h>

extern List *head = NULL;
extern List *tail = NULL;

extern unsigned int length = 0;

static List *
_new_node ()
{
  List *node = (List *)malloc (sizeof (List));
  return node;
}

void list_new()
{
    if(head != NULL){
        return;
      }
    return _node_new ();
}

void
list_del ()
{
    if(head == NULL){
        return;
      }

    do{
        List *temp = head;
        head = head->next;
        free (temp);
      }
    while (head->next != NULL);
}
