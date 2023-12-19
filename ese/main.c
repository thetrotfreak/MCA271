#include "patient.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch,
 * system("pause") or input loop */
int front = -1;
int rear = -1;

int
main (int argc, char *argv[])
{
  Patient p1 = { .id = 1, .age = 12, .severity = 1 };
  Patient p2 = { .id = 2, .age = 22, .severity = 3 };
  Patient p3 = { .id = 3, .age = 33, .severity = 2 };
  Patient p[SIZE];

  enqueue (&p[0], p1);
  enqueue (&p[0], p2);
  enqueue (&p[0], p3);
  printSevere (&p[0]);
  stats (&p[0]);
  traverse (&p[0]);
  return 0;
}
