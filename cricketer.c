#include "cricketer.h"
#include "misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
fmt (Cricketer *c)
{
  hr ('*', 78, 1);
  printf ("Batsman         : %s\n", c->name);
  printf ("Plays for       : %s\n", c->team);
  printf ("Batting Average : %.2f\n", c->batting_average);
}

void
read (Cricketer *c, const unsigned int n)
{
  char *buffer;
  for (size_t i = 0; i < n; i++)
    {
      // eat the \n
      getc (stdin);

      printf ("Batsman? ");
      fgets (buffer, sizeof (c[i].name), stdin);
      strncpy (c[i].name, buffer, strcspn (buffer, "\n"));

      printf ("Plays for? ");
      fgets (buffer, sizeof (c[i].team), stdin);
      strncpy (c[i].team, buffer, strcspn (buffer, "\n"));

      printf ("Batting average? ");
      scanf ("%f", &c[i].batting_average);
    }
}

void
display (Cricketer *c, const unsigned int n)
{
  for (size_t i = 0; i < n; i++)
    {
      fmt (&c[i]);
    }
}

char *
search (Cricketer *c, unsigned int n, const char *name)
{
  for (size_t i = 0; i < n; i++)
    {
      if (strlen (name) == 0)
        return (char *)NULL;
      if (strstr (c[i].name, name) != NULL)
        fmt (&c[i]);
    }
}

int
main (int argc, char **argv)
{
  unsigned int n;
  printf ("Number of Cricketers? ");
  scanf ("%u", &n);

  Cricketer *c = (Cricketer *)calloc (n, sizeof (Cricketer));
  read (c, n);
  display (c, n);
  free (c);
  return 0;
}
