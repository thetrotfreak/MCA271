#include "1.h"
#include "misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_WIDTH 64

static void
fill (const char *fillFrom, const char *fillTo)
{
  // remove the nasty \n
  if (fillTo == NULL)
    {
      fillTo = fillFrom;
    }
  int idx_newline = (int)strcspn (fillFrom, "\r\n");
  fillTo = strndup (fillFrom, idx_newline);
}

void
scanNetwork (Network **network, unsigned int warehouses, unsigned int outlets)
{
  for (unsigned int i = 0; i < warehouses; i++)
    {
      network[i] = (Network *)calloc (outlets, sizeof (Network));
      printf ("\nWarehouse? ");
      fgets (network[i]->from.name, STR_WIDTH, stdin);
      fill (network[i]->from.name, NULL);
      // printf ("Supply? ");
      for (unsigned int j = 0; j < outlets; j++)
        {
          printf ("Outlet? ");
          fgets(network
          fgets (*((network + i) + j).to.name, STR_WIDTH, stdin);
          // fgets (*((network + i) + j)->to->name, STR_WIDTH, stdin);
          // fill (*((network + i) + j)->from, NULL);
          // printf ("Demand? ");
          // printf ("Cost? ");
          // printf ("Mode? ");
          printf ("Distance? ");
          scanf ("%u", &(*(network + i) + j)->distance);
          printf ("%u", (*(network + i) + j)->distance);
        }
    }
}

void
freeNetwork (Network **network, unsigned int warehouses, unsigned int outlets)
{
  for (unsigned int i = 0; i < warehouses; i++)
    {
      free (*(network + i));
    }
    free (network);
    network = NULL;
}

void
menu (Network **s, unsigned int r, unsigned int c)
{
  int sentinel = 1;
  int choice = 0;
  while (sentinel)
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

      scanf ("%d", &choice);
      switch (choice)
        {
        case 1:
          scanNetwork (s, r, c);
          break;
        case 2:
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
          freeNetwork (s, r, c);
          sentinel = 0;
        }
    }
}

int main(){
  /* Network n = {
   *   .from = "Jadugoda",
   *   .to = "Bangalore",
   *   .mode = AIR,
   *   .cost = 4800,
   *   .distance = 1800,
   * };
   */

  unsigned int warehouses = 0;
  unsigned int outlets = 0;

  printf ("\nNumber of Warehouse? ");
  scanf ("%u", &warehouses);

  printf ("\nNumber of Outlet? ");
  scanf ("%u", &outlets);

  Network **netw = (Network **)calloc (warehouses, sizeof (Network *));

  menu (netw, warehouses, outlets);

  return 0;
}
