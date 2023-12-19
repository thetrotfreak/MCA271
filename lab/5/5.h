#ifndef _5_H
#define _5_H

#include "domain.h"
#include <stddef.h>

int linearSearch (const void *, size_t, size_t, const void *,
                  size_t (*) (const void *, const void *));

// int sentinelSearch (void *, size_t, size_t, const void *, size_t,
//                     size_t (*) (const void *, const void *));

int sentinelSearch (const Warehouse *, size_t, const char *);

int binarySearch (const Warehouse *, size_t, const char *);

void bubbleSort (Warehouse *, size_t);
void insertionSort (Warehouse *, size_t);

#endif // _5_H
