#include "dll.h"
#include <stdio.h>

int
main ()
{
  DoubleNetworkNode *list = NULL;

  // append network nodes
  appendNode (&list, (Network){ (Warehouse){ "W1", 100 }, (Outlet){ "O1", 50 },
                                ROAD, 200, 30 });
  appendNode (&list, (Network){ (Warehouse){ "W2", 200 }, (Outlet){ "O2", 60 },
                                AIR, 300, 40 });
  appendNode (&list, (Network){ (Warehouse){ "W3", 300 }, (Outlet){ "O3", 70 },
                                ROAD, 400, 50 });

  // free the memory
  freeList (&list);

  DLL l1;
  DLL l2;
  newList_v2 (&l1);
  newList_v2 (&l2);
  prepend_v2 (&l1, (Network){ (Warehouse){ "W1", 100 }, (Outlet){ "O1", 50 },
                             ROAD, 200, 30 });
  prepend_v2 (&l2, (Network){ (Warehouse){ "W2", 100 }, (Outlet){ "O2", 50 },
                              ROAD, 200, 30 });
  freeList_v2 (&l1);
  freeList_v2 (&l2);
  return 0;
}
