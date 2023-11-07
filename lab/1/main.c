#include "1.h"
#include "misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_WIDTH 64

void
scanNetwork (Network **network, unsigned int warehouses, unsigned int outlets)
{
  for (unsigned int i = 0; i < warehouses; i++)
    {
      network[i] = (Network *)calloc (outlets, sizeof (Network));
      network[i]->from.name = (char *)calloc (STR_WIDTH, sizeof (char));
      printf ("\nWarehouse? ");
      readStr (network[i]->from.name, STR_WIDTH);
      // printf ("Supply? ");
      for (unsigned int j = 0; j < outlets; j++)
        {
          printf ("Outlet? ");
          readStr (network[i]->to.name, STR_WIDTH);
          //  printf ("Demand? ");
          //  printf ("Cost? ");
          //  printf ("Mode? ");
          printf ("Distance? ");
          readUInt (&network[i]->distance, STR_WIDTH);
        }
    }
}

void
freeNetwork (Network **network, unsigned int warehouses, unsigned int outlets)
{
  for (unsigned int i = 0; i < warehouses; i++)
    {
      for (unsigned int j = 0; j < outlets; j++)
        {
          free (network[i]->from.name);
          free (network[i]->to.name);
          free (network[i]);
        }
    }
  free (network);
  network = NULL;
}

void
menu (Network **s, unsigned int r, unsigned int c)
{
  int sentinel = 1;
  int choice = 0;
  char buffer[128];
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

      // scanf (" %d", &choice);
      //      fgets (buffer, sizeof (buffer), stdin);
      //      choice = strtol (buffer, NULL, 10);
      readInt (&choice, 128);

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
  // char buffer[128];

  printf ("\nNumber of Warehouse? ");
  readUInt (&warehouses, 128);
  // fgets (buffer, sizeof (buffer), stdin);
  // warehouses = strtol (buffer, NULL, 10);

  printf ("\nNumber of Outlet? ");
  readUInt (&outlets, 128);
  // scanf ("%u", &outlets);
  // fgets (buffer, sizeof (buffer), stdin);
  // warehouses = strtol (buffer, NULL, 10);

  Network **netw = (Network **)calloc (warehouses, sizeof (Network *));

  menu (netw, warehouses, outlets);

  return 0;
}
