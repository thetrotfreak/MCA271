#include "student.h"
#include "misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
fmt (STUDENT *s)
{
  hr ('*', 78, 1);
  printf ("Name        : %s\n", s->name);
  printf ("Roll Number : %u\n", s->roll_number);
  printf ("Class       : %s\n", s->class);
  printf ("Marks       :\n");
  for (int i = 0; i < 3; i++)
    {
      printf ("  Subject %d : %.2f\n", i, s->marks[i]);
    }
}

char *
search_name (STUDENT *s, unsigned int n, const char *name)
{
  for (size_t i = 0; i < n; i++)
    {
      if (strlen (name) == 0)
        return (char *)NULL;
      if (strstr (s[i].name, name) != NULL)
        fmt (&s[i]);
    }
}
char *
search_roll_number (STUDENT *s, unsigned int n, const unsigned int roll_number)
{
  for (size_t i = 0; i < n; i++)
    {
      if (s[i].roll_number == roll_number)
        fmt (&s[i]);
    }
}

int
main (int argc, char **argv)
{
  unsigned int n;
  printf ("Number of students? ");
  scanf ("%u", &n);

  STUDENT *s = (STUDENT *)calloc (n, sizeof (STUDENT));

  STUDENT s0 = { .name = "Bivas Kumar",
                 .roll_number = 2347111,
                 .class = "2 MCA A",
                 .marks = { 89, 78, 90 } };
  STUDENT s1 = { .name = "Rohit Rajesh Tank",
                 .roll_number = 2347161,
                 .class = "2 MCA A",
                 .marks = { 89, 78, 90 } };
  STUDENT s2 = { .name = "Kushal Sourav",
                 .roll_number = 2347124,
                 .class = "2 MCA A",
                 .marks = { 89, 78, 90 } };
  s[0] = s0;
  s[1] = s1;
  s[2] = s2;
  search_name (s, n, "Bivas");
  search_roll_number (s, n, 2347161);
  free (s);
  return 0;
}
