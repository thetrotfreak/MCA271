#include "list.h"
#include "vector.h"
#include <stdio.h>

int
main (int argc, char **argv)
{
  // Vector v;
  // v.value.i = 0;
  // printf ("A%cB %d %f", v.value.c, v.value.i, v.value.f);
  // Vector *v = vector_new ();
  // printf ("\ncap is %d", v->capacity);
  // for (int i = 0; i < 64; i++)
  //   {
  //     vector_append (v, i);
  //   }
  // printf ("\ncap is %d", v->capacity);
  // vector_append (v, 0);
  // vector_append (v, 0);
  // printf ("\ncap is %d", v->capacity);
  // vector_free (v);
  List *head = NULL;
  List *tail= NULL;
  List *L = list_new ();
  list_free (L);

  return 0;
}
