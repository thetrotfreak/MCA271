#include "1.h"
#include "misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
addWarehouse (Network **n, const char *name)
{
  Network **p = (Network **)realloc (n, (w + 1) * sizeof (Network *));
  if (p == NULL)
    {
      fprintf (stderr, "Not enough memory for reallocation");
      return;
    }
  n = p;
  w++;
  for (unsigned int j = 0; j < o; j++)
    {
      n[w][j].from.name = (char *)calloc (64, sizeof (char));
      n[w][j].to.name = (char *)calloc (64, sizeof (char));

      strcpy (n[w][j].from.name, name);
      strcpy (n[w][j].to.name, n[w - 1][j].to.name);
    }
}
