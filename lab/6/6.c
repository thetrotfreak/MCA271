#include "6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void
getRandom (int threshold)
{
  srand ((unsigned int)clock () + time (NULL));
  printf ("\t$ [INFO] %d\n", rand () % 10 + 1);
}

// Merge function to merge two sorted halves of an array
void
merge (Outlet *outlets, int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays
  Outlet *leftArr = (Outlet *)malloc (n1 * sizeof (Outlet));
  Outlet *rightArr = (Outlet *)malloc (n2 * sizeof (Outlet));

  // Copy data to temporary arrays leftArr[] and rightArr[]
  for (i = 0; i < n1; i++)
    leftArr[i] = outlets[left + i];
  for (j = 0; j < n2; j++)
    rightArr[j] = outlets[mid + 1 + j];

  // Merge the temporary outletsays back into arr[left..right]
  i = 0;    // Initial index of first suboutletsay
  j = 0;    // Initial index of second suboutletsay
  k = left; // Initial index of merged suboutletsay

  while (i < n1 && j < n2)
    {
      // Compare names for sorting
      if (strcmp (leftArr[i].name, rightArr[j].name) <= 0)
        {
          outlets[k] = leftArr[i];
          i++;
        }
      else
        {
          outlets[k] = rightArr[j];
          j++;
        }
      k++;
    }

  // Copy the remaining elements of leftArr[], if there are any
  while (i < n1)
    {
      outlets[k] = leftArr[i];
      i++;
      k++;
    }

  // Copy the remaining elements of rightArr[], if there are any
  while (j < n2)
    {
      outlets[k] = rightArr[j];
      j++;
      k++;
    }

  // Free allocated memory
  free (leftArr);
  free (rightArr);
}

// Merge Sort function to recursively sort an array of Outlet structures
void
mergeSort (Outlet *outlets, int left, int right)
{
  if (left < right)
    {
      // Same as (left+right)/2, but avoids overflow for large left and right
      int mid = left + (right - left) / 2;

      // Sort first and second halves
      mergeSort (outlets, left, mid);
      mergeSort (outlets, mid + 1, right);

      // Merge the sorted halves
      merge (outlets, left, mid, right);
    }
}
