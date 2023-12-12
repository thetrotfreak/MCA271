#ifndef _VECTOR_H
#define _VECTOR_H

#define DEFAULT_CAPACITY 64
#define GROWTH_FACTOR 2

typedef struct Vector
{
  int *vector;
  unsigned int length;
  unsigned int capacity;
} Vector;

Vector *vector_new ();
void vector_free (Vector *v);
void vector_append (Vector *, int);
int vector_get (Vector *, int);
unsigned int _index (Vector *, int);
void vector_str (Vector *v);
void vector_grow (Vector *v);

#endif // VECTOR
