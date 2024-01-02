#include "6.h"
#include <stdio.h>
#include <stdlib.h>

void
help (int argc, char **argv)
{
  const char *prog = "6";
  if (argc < 3 || argc > 4)
    {
      printf ("Usage: %s <path/to/inputfile.txt> <separator> [path/to/outputfile.txt]\n",
              prog);
      /*TODO
       * Use `standar return status code instead`
       */
      exit (1);
    }
}

int
main (int argc, char **argv)
{
  help (argc, argv);
  // for (int i = 0; i < 10; i++)
  //   getRandom (100);
  Outlet *outlet = freadOutlet (argv[1], argv[2]);
  if (outlet != NULL)
    {
      mergeSort (outlet, 0, 2);
      fwriteOutlet (outlet, 3, NULL, "|");
      // printOutlet (*outlet);
      free (outlet);
    }
  return 0;
}
