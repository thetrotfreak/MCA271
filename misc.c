#include "misc.h"
#include <stdio.h>

void
hr (char c, unsigned int length)
{
  for (unsigned int i = 0; i < length; i++)
    {
      if (i == 0)
        printf ("\n");
      printf ("%c", c);
      if(i==length-1)
        printf ("\n");
    }
}
