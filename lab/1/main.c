#include "1.h"
#include "misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_WIDTH 64

unsigned int w;
unsigned int o;

void
scanNetwork (Network **network)
// scanNetwork (Network **network, unsigned int warehouses, unsigned int
// outlets)
{
  for (unsigned int i = 0; i < w; i++)
    {
      network[i] = (Network *)calloc (o, sizeof (Network));
      for (unsigned int j = 0; j < o; j++)
        {
          network[i][j].from.name = (char *)calloc (STR_WIDTH, sizeof (char));
          network[i][j].to.name = (char *)calloc (STR_WIDTH, sizeof (char));
          if (j == 0)
            {
              /*
               * read warehouse once per row
               * we'll copy the warehouse to the subsequent columns
               */
              printf ("\nWarehouse #%u? ", i);
              readStr (network[i][j].from.name, STR_WIDTH);
              // printf ("Supply? ");
            }
          else
            {
              strcpy (network[i][j].from.name, network[i][j - 1].from.name);
              if (i == 0)
                {
                  printf ("Outlet #%u? ", j);
                  readStr (network[i][j].to.name, STR_WIDTH);
                }
              else
                {
                  strcpy (network[i][j].to.name, network[i - 1][j].to.name);
                }
              // printf ("Demand? ");
              // printf ("Cost? ");
              // printf ("Mode? ");
              printf ("Distance? ");
              readUInt (&network[i][j].distance, STR_WIDTH);
            }
        }
    }
}

void
freeNetwork (Network **network)
{
  for (unsigned int i = 0; i < w; i++)
    {
      for (unsigned int j = 0; j < o; j++)
        {
          free (network[i][j].from.name);
          free (network[i][j].to.name);
        }
      free (network[i]);
    }
  free (network);
}

void
menu (Network **s)
{
  int sentinel = 0;
  int choice = 0;
  while (sentinel == 0)
    {
      hr ('-', 32);
      printf ("1. Enter Network");

      printf ("\n2. Add Warehouse to Network");
      printf ("\n3. Remove Warehouse from Network");

      printf ("\n4. Add Outlet to Network");
      printf ("\n5. Remove Outlet from Network");

      printf ("\n6. Find route by distance");
      printf ("\n7. Find route by cost");
      hr ('-', 32);

      readInt (&choice, STR_WIDTH);

      switch (choice)
        {
        case 1:
          scanNetwork (s);
          break;
        case 2:
          // addWarehouse (s, r, c, "Wn");
          // printf ("%s", s[r][0].from.name);
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          break;
        default:
          freeNetwork (s);
          sentinel = 1;
        }
    }
}

int
main ()
{
  /* Network n = {
   *   .from = "Jadugoda",
   *   .to = "Bangalore",
   *   .mode = AIR,
   *   .cost = 4800,
   *   .distance = 1800,
   * };
   */

  // unsigned int warehouses = 0;
  // unsigned int outlets = 0;

  printf ("\nNumber of Warehouse? ");
  readUInt (&w, 128);

  printf ("\nNumber of Outlet? ");
  readUInt (&o, 128);

  Network **netw = (Network **)calloc (w, sizeof (Network *));
  if (netw == NULL)
    {
        printf("ENOMEM");
    }
  // rest of the dynamic memory allocation
  // is taken care of in
  // scanNetwork
  // this is to save loop iterations

  else
    {
        menu (netw);
    }

  return 0;
}
