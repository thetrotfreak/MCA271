#include <stdio.h>

void
hr (char c, unsigned int length, int newline)
{
  for (unsigned int i = 0; i < length; i++)
    {
      printf ("%c", c);
    }
  if (newline > 0)
    {
      printf ("\n");
    }
}
