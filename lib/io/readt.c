#include "readt.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned int DEFAULT_BUFFER_LENGTH = 8;

void
fill (char *source, char **sink)
{
  if (sink == NULL || *sink == NULL)
    {
      perror ("NULL");
      // sink = &source;
    }
  unsigned int newline_at
      = (unsigned int)strcspn ((const char *)source, "\r\n");
  printf ("%u", newline_at);
  *sink = strndup (source, newline_at);
  printf ("%s", *sink);
}

void
readStr (char *p, int buffer_size)
{
  if (fgets (p, buffer_size, stdin) == NULL)
    {
      perror ("fgets");
      return;
    }
  fill (p, NULL);
}

void
readInt (int *p, int buffer_size)
{
  const int radix = 10;
  char *endptr;
  long val;

  if (buffer_size <= 0)
    {
      buffer_size = DEFAULT_BUFFER_LENGTH;
    }

  char buffer[buffer_size];

  if (fgets (buffer, buffer_size, stdin) == NULL)
    {
      // perror("fgets");
      return;
    }

  errno = 0; // To distinguish success/failure after call
  val = strtol (buffer, &endptr, radix);

  // Check for various possible errors.
  if (errno != 0)
    {
      // perror("strtol");
      return;
    }

  // If we got here, strtol() successfully parsed a number.
  // Store the result in the memory location pointed to by p
  *p = (int)val;
}

void
readUInt (unsigned int *p, int buffer_size)
{
  const int radix = 10;
  char *endptr;
  long val;

  if (buffer_size <= 0)
    {
      buffer_size = DEFAULT_BUFFER_LENGTH;
    }

  char buffer[buffer_size];

  if (fgets (buffer, buffer_size, stdin) == NULL)
    {
      // perror("fgets");
      return;
    }

  errno = 0;
  val = strtol (buffer, &endptr, radix);

  if (errno != 0)
    {
      // perror("strtol");
      return;
    }

  *p = (unsigned int)val;
}

// char *
// readStr_v2 (unsigned int buffer_size)
// {
//   char *buffer = (char *)calloc (buffer_size, sizeof (char));
//   if (buffer == NULL)
//     {
//       fprintf (stderr, "dynamic memory allocation failed");
//       return '\0';
//     }
//   return buffer;
// }

void
readDouble (double *p, int buffer_size)
{
  char *endptr;
  double val;

  if (buffer_size <= 0)
    {
      buffer_size = DEFAULT_BUFFER_LENGTH;
    }

  char buffer[buffer_size];

  if (fgets (buffer, buffer_size, stdin) == NULL)
    {
      // perror("fgets");
      return;
    }

  errno = 0;
  val = strtod (buffer, &endptr);

  if (errno != 0)
    {
      // perror("strtol");
      return;
    }

  *p = (double)val;
}

void
readFloat (float *p, int buffer_size)
{
  char *endptr;
  float val;

  if (buffer_size == 0)
    {
      buffer_size = 8;
    }

  char buffer[buffer_size];

  if (fgets (buffer, buffer_size, stdin) == NULL)
    {
      // perror("fgets");
      return;
    }

  errno = 0;
  val = strtof (buffer, &endptr);

  if (errno != 0)
    {
      // perror("strtol");
      return;
    }

  *p = (float)val;
}
