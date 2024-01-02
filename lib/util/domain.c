#include "domain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
printNetwork (Network n)
{
  printf ("[Network]\n");
  printf ("\tFrom    : %s\n", n.from.name);
  printf ("\tTo      : %s\n", n.to.name);
  printf ("\tMode    : %d\n", n.mode);
  printf ("\tDistance: %d\n", n.distance);
  printf ("\tCost    : %d\n", n.cost);
}

void
printOutlet (Outlet outlet)
{
  printf ("[Outlet]\n");
  printf ("\tName  : %s\n", outlet.name);
  printf ("\tDemand: %u\n", outlet.demand);
}

void
asOutlet (const char *string, int field, Outlet *outlets)
{
  /*
   * `string` is an Outlet string of the form
   * Outlet.name<sep>Outlet.demand\n
   * The aim is to tokenize the string using the `<sep>`
   * assuming the order of the fields declared is maintained in the `string`
   * removing any `<sep>` and `\n` from the tokenized data
   *
   * if `*outlet` is not NULL
   * then the tokenized (and sanitized data) will be assigned to its fields
   * else, a malloced struct will be returned with the data assigned to it.
   * */
  switch (field)
    {
    case 1:
      outlets->name = strdup (string);
      break;
    case 2:
      outlets->demand = (unsigned int)strtol (string, NULL, 10);
      break;
    default:
      break;
    }
}

Outlet *
freadOutlet (const char *filepath, const char *delim)
{
  if (filepath == NULL)
    return NULL;

  FILE *fp = fopen (filepath, "r");

  if (fp != NULL)
    {
      char *lineptr = NULL;
      size_t n = 0;

      char *token = NULL;
      size_t newline;
      char *sanitized_token = NULL;

      // Outlet outlet = { 0 };
      int field = 0;
      unsigned int nmemb = 1;
      Outlet *outlet = (Outlet *)calloc (nmemb, sizeof (Outlet));

      while (getline (&lineptr, &n, fp) != -1)
        {
          while ((token = strtok (lineptr, delim)) != NULL)
            {
              newline = strcspn ((const char *)token, "\n");
              sanitized_token = strndup ((const char *)token, newline);
              lineptr = NULL;
              ++field;
              asOutlet ((const char *)sanitized_token, field,
                        outlet + (nmemb - 1));
            }
          printOutlet (*(outlet + (nmemb - 1)));
          nmemb++;
          outlet = realloc (outlet, nmemb * sizeof (Outlet));
          if (outlet == NULL)
            {
              nmemb--;
              return NULL;
            }
          free (lineptr);
          field = 0;
        }
      fclose (fp);
      return outlet;
    }
  return NULL;
}

void
fwriteOutlet (const Outlet *outlet, size_t nmemb, const char *filepath,
              const char *delim)
{
  FILE *fp = fopen (filepath != NULL ? filepath : "out.txt", "w");

  if (fp != NULL)
    {
      for (size_t i = 0; i < nmemb; i++)
        {
          /*
           * TODO
           * fwrite() does not handle dynamic arrays properly
           * like Outlet {char *name}
           * fwrite ((outlet + i), sizeof (Outlet), i, fp);
           */
          fprintf (fp, "%s%s%u\n", (outlet + i)->name, delim,
                   (outlet + i)->demand);
        }

      fclose (fp);
    }
}
