#ifndef DOMAIN_H
#define DOMAIN_H

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

typedef struct NetworkNode
{
  Network network;
  struct NetworkNode *next;
} NetworkNode;

#endif // DOMAIN_H
