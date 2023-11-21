#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static List *
_new_node ()
{
  List *node = (List *)malloc (sizeof (List));
  return node;
}

List *
list_new ()
{
  static List *head;
  if (head != NULL)
    {
      return NULL;
    }
  return _new_node ();
}

void
list_free (List *head)
{
  if (head == NULL)
    {
      return;
    }

  do
    {
      List *temp = head;
      head = head->next;
      free (temp);
    }
  while (head->next != NULL);
}
