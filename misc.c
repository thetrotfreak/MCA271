#include "misc.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
hr (char c, unsigned int length)
{
  for (unsigned int i = 0; i < length; i++)
    {
      if (i == 0)
        {
          printf ("\n");
        }
      printf ("%c", c);
      if (i == length - 1)
        printf ("\n");
    }
}

void
fill (char *source, char **sink)
{
  if (sink == NULL || *sink == NULL)
    {
      *sink = source;
    }
  unsigned int newline_at
      = (unsigned int)strcspn ((const char *)source, "\r\n");
  *sink = strndup (source, newline_at);
}

void
readStr (char *p, int buffer_size)
{
  if (fgets (p, buffer_size, stdin) == NULL)
    {
      // perror ("fgets");
      return;
    }
  fill (p, NULL);
}

void
readInt (int *p, int buffer_size)
{
  const int base = 10;
  char *endptr;
  long val;

  if (buffer_size <= 0)
    {
      buffer_size = 64;
    }

  char buffer[buffer_size];

  if (fgets (buffer, buffer_size, stdin) == NULL)
    {
      // perror("fgets");
      return;
    }

  errno = 0; // To distinguish success/failure after call
  val = strtol (buffer, &endptr, base);

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
  const int base = 10;
  char *endptr;
  long val;

  if (buffer_size <= 0)
    {
      buffer_size = 64;
    }

  char buffer[buffer_size];

  if (fgets (buffer, buffer_size, stdin) == NULL)
    {
      // perror("fgets");
      return;
    }

  errno = 0; // To distinguish success/failure after call
  val = strtol (buffer, &endptr, base);

  // Check for various possible errors.
  if (errno != 0)
    {
      // perror("strtol");
      return;
    }

  // If we got here, strtol() successfully parsed a number.
  // Store the result in the memory location pointed to by p
  *p = (unsigned int)val;
}
