#include "4.h"

int
main (int argc, char **argv)
{
  Queue q;
  newQueue (&q);
  enqueue (&q, (Network){ (Warehouse){ .name = "Pune", .supply = 100 },
                          (Outlet){ .name = "Jadugoda", .demand = 10 },
                          .mode = ROAD, .cost = 80000, .distance = 1200 });
  enqueue (&q, (Network){ (Warehouse){ .name = "Thane", .supply = 100 },
                          (Outlet){ .name = "Jadugoda", .demand = 10 },
                          .mode = ROAD, .cost = 70000, .distance = 1000 });
  enqueue (&q, (Network){ (Warehouse){ .name = "Bangalore", .supply = 100 },
                          (Outlet){ .name = "Jadugoda", .demand = 10 },
                          .mode = AIR, .cost = 35000, .distance = 1800 });
  printQueue (&q);
  dequeue (&q);
  printQueue (&q);
  freeQueue (&q);

  return 0;
}
