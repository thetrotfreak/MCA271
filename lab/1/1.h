#ifndef _1_H
#define _1_H

/*
 * Domain identified from
 * https://personal.utdallas.edu/~scniu/OPRE-6201/documents/TP1-Formulation.pdf
 */

typedef enum TransportationMode
{
  AIR,
  RAIL,
  ROAD,
  SEA
} TransportationMode;

typedef struct Warehouse
{
  char *name;
  unsigned int supply;
} Warehouse;

typedef struct Outlet
{
  char *name;
  unsigned int demand;
} Outlet;

typedef struct Network
{
  Warehouse from;
  Outlet to;
  TransportationMode mode;
  unsigned int cost;
  unsigned int distance;
} Network;

// DS operations
void combineDistance ();
void optimizeTransport ();
void shortestDistance ();

// Matrix operations
void addWarehouse ();
void removeWarehouse ();

void addOutlet ();
void removeOutlet ();

/*
 * Matrix:
 *
 *     | O1 | O2 | ... | On |
 * ----|----|----|-----|----|
 *  W1 |
 * ----|----|----|-----|----|
 *  W2 |
 * ----|----|----|-----|----|
 *  ...|
 * ----|----|----|-----|----|
 *  Wn |
 * ----|----|----|-----|----|
 *
 */
#endif
