#include "5.h"
#include "domain.h"
#include <stdlib.h>
#include <string.h>

int
linearSearch (const void *array, size_t length, size_t size, const void *key,
              size_t (*fn) (const void *, const void *))
{
  const char *char_array = (const char *)array;
  /*
   * get byte-level access to the array
   * doing that we can jump to the next
   * appropriate byte by doing basic math
   * regardless of the type of the array
   *
   */
  for (size_t i = 0; i < length; i++)
    {
      if (fn (char_array + i * size, key) == 0)
        {
          return 1;
        }
    }
  return 0;
}

// int
// sentinelSearch (void *array, size_t length, size_t size, const void *key,
//                 size_t key_size, size_t (*fn) (const void *, const void *))
// {
//   /*
//    * TODO
//    * Endianness
//    * Alignment
//    * Strict Aliasing
//    */
//   char *char_array = (char *)array;
//   void *temp = calloc (1, size);
//   size_t i = 0;
//   int ret = 0;
//
//   // place the sentinel at the end
//   // char *sentinelPlacePointer = char_array + (length - 1) * size;
//   // take a copy of the last index element to a temp region
//   memmove (temp, char_array + (length - 1) * size, size);
//   memmove (char_array + (length - 1) * size, key, key_size);
//
//   //  while (fn (char_array + i * size, key) != 0)
//   //    {
//   //      ++i;
//   //    }
//
//   // restore the value at the end
//   // memmove (sentinelPlacePointer, temp, size);
//
//   // if (i < length - 1 || fn (char_array + (length - 1) * size, key) == 0)
//   if (i < length - 1)
//     {
//       ret = 1;
//     }
//   free (temp);
//   return ret;
// }

int
sentinelSearch (const Warehouse *w, size_t size, const char *name)
{
  // Add a sentinel at the end of the array with the target name
  Warehouse sentinel;
  sentinel.name = name;

  size_t i = 0;
  while (strcmp (w[i].name, name) != 0)
    {
      i++;
    }

  // Check if the found element is not the sentinel
  if (&w[i] != &sentinel)
    {
      return i;
    }
  else
    {
      return -1;
    }
}

int
binarySearch (const Warehouse *w, size_t size, const char *name)
{
  size_t left = 0;
  size_t right = size - 1;

  while (left <= right)
    {
      size_t mid = left + (right - left) / 2;

      int ret = strcmp (w[mid].name, name);

      if (ret == 0)
        {
          return mid;
        }
      else if (ret < 0)
        {
          left = mid + 1;
        }
      else
        {
          right = mid - 1;
        }
    }

  return -1;
}

void
bubbleSort (Warehouse *w, size_t size)
{
  for (size_t i = 0; i < size - 1; i++)
    {
      for (size_t j = 0; j < size - i - 1; j++)
        {
          if (strcmp (w[j].name, w[j + 1].name) > 0)
            {
              Warehouse temp = w[j];
              w[j] = w[j + 1];
              w[j + 1] = temp;
            }
        }
    }
}

void
insertionSort (Warehouse *w, size_t size)
{
  for (size_t i = 1; i < size; i++)
    {
      Warehouse key = w[i];
      int j = i - 1;

      // Move elements of the array that are greater than key to one position
      // ahead of their current position
      while (j >= 0 && strcmp (w[j].name, key.name) > 0)
        {
          w[j + 1] = w[j];
          j = j - 1;
        }

      w[j + 1] = key;
    }
}
