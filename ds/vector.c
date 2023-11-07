#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector *
vector_new ()
{
  Vector *v = (Vector *)malloc (sizeof (Vector));

  if (v == NULL)
    {
      fprintf (stderr, "Dynamic memory allocation for Vector failed");
      abort ();
    }

  v->length = 0;
  v->capacity = DEFAULT_CAPACITY;
  v->vector = (int *)malloc (sizeof (int) * v->capacity);

  if (v->vector == NULL)
    {
      fprintf (stderr,
               "Dynamic memory allocation for Vector storage engine failed");
      abort ();
    }
  return v;
}

void
vector_free (Vector *v)
{
  free (v->vector);
  free (v);
}

void
vector_append (Vector *v, int i)
{
  const unsigned int length = v->length + 1;
  if (length >= v->capacity)
    {
        vector_grow(v);
    }
  v->vector[v->length++] = i;
}

void
vector_grow (Vector *this)
{
  /*
   * TODO
   * Can realloc properly free `Vector *this`?
   * If NO, then use vector_free()
   */
  Vector *that = (Vector *)realloc (this, GROWTH_FACTOR);
  if (that == NULL)
    {
        fprintf (stderr, "Vector can not grow beyond current capacity");
        abort ();
    }
  that->capacity = this->capacity * GROWTH_FACTOR;
  this = that;
}

// Vector *vector_shrink (Vector *v)
// {
// }

void
vector_insert (Vector *this, int value, int index)
{
}

unsigned int
_index (Vector *v, int i)
{
  if (i < 0)
    {
      i = v->length + i;
    }
  if (i < 0 || i >= v->length)
    {
      fprintf (stderr, "Index out of range");
      abort ();
    }
  return i;
}

int
vector_get (Vector *v, int i)
{
  return v->vector[_index (v, i)];
}

void
vector_str (Vector *v)
{
  for (size_t i = 0; i < v->length; i++)
    {
      if (i == 0)
        {
          printf ("\n[ %d, ", v->vector[i]);
        }
      else if (i < v->length - 1)
        {
          printf ("%d, ", v->vector[i]);
        }
      else
        {
          printf ("%d ]", v->vector[i]);
        }
    }
}
