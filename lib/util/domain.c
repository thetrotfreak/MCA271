#include "domain.h"
#include <stdio.h>

void
printNetwork (Network n)
{
  printf ("From    : %s\n", n.from.name);
  printf ("To      : %s\n", n.to.name);
  printf ("Mode    : %d\n", n.mode);
  printf ("Distance: %d\n", n.distance);
  printf ("Cost    : %d\n", n.cost);
}
