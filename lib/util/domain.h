#ifndef DOMAIN_H
#define DOMAIN_H

#include <stddef.h>

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

void asOutlet (const char *string, int field, Outlet *outlets);
Outlet *freadOutlet (const char *filepath, const char *delim);
void fwriteOutlet (const Outlet *outlet, size_t nmemb, const char *filepath,
                   const char *delim);
void printNetwork (Network);
void printOutlet (Outlet outlet);

#endif // DOMAIN_H
