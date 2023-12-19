#include "5.h"
#include "domain.h"
#include <stdio.h>
#include <string.h>

size_t compareWarehouseName (const void *, const void *);
size_t compareWarehouseSupply (const void *, const void *);

int
main (int argc, char **argv)
{
  Warehouse array[] = {
    (Warehouse){ .name = "Mumbai", .supply = 100 },
    (Warehouse){ .name = "Bangalore", .supply = 200 },
    (Warehouse){ .name = "Gujarat", .supply = 300 },
  };

  char *name_key = "Gujarat";
  size_t supply_key = 99;

  linearSearch (array, sizeof (array) / sizeof (Warehouse), sizeof (Warehouse),
                name_key, compareWarehouseName)
      ? printf ("Ok\n")
      : printf ("!Ok\n");

  linearSearch (array, sizeof (array) / sizeof (Warehouse), sizeof (Warehouse),
                &supply_key, compareWarehouseSupply)
      ? printf ("Ok\n")
      : printf ("!Ok\n");

  //   sentinelSearch (array, sizeof (array) / sizeof (Warehouse),
  //                   sizeof (Warehouse), &supply_key, sizeof (supply_key),
  //                   compareWarehouseSupply)
  //       ? printf ("Ok\n")
  //       : printf ("!Ok\n");

  // bubbleSort (array, sizeof (array) / sizeof (Warehouse));
  insertionSort (array, sizeof (array) / sizeof (Warehouse));
  if (binarySearch (array, sizeof (array) / sizeof (Warehouse),
                    (const char *)name_key)
      != -1)
    {
      printf ("Ok\n");
    }
  else
    {
      printf ("!Ok\n");
    }

  char *name = "Mumbai";
  if (sentinelSearch (array, sizeof (array) / sizeof (Warehouse),
                      (const char *)name)
      != -1)
    {
      printf ("Ok\n");
    }
  else
    {
      printf ("!Ok\n");
    }
  return 0;
}

size_t
compareWarehouseName (const void *a, const void *b)
{
  return strcasecmp ((const char *)((const Warehouse *)a)->name,
                     (const char *)b);
}

size_t
compareWarehouseSupply (const void *a, const void *b)
{
  return (((const Warehouse *)a)->supply - (*(unsigned int *)b));
}
