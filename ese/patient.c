#include "patient.h"
#include <stddef.h> // for NULL
#include <stdio.h>
#include <stdlib.h>

void
printPatient (Patient *p)
{
  if (p != NULL)
    {
      printf ("==========\n");
      printf ("ID       : %u\n", p->id);
      printf ("Age      : %hd\n", p->age);
      printf ("Severity : %d\n", p->severity);
      printf ("==========\n");
    }
}

int
validPatient (Patient *p)
{
  if (p->severity >= L1 && p->severity <= L5)
    {
      return 1;
    }
  else
    {
      fprintf (stderr, "Invalid Illness Severity Level\n");
      return 0;
    }
}

void
enqueue (Patient *a, Patient p)
{
  if (rear == (SIZE - 1))
    {
      fprintf (stderr, "OVERFLOW\n");
    }
  if (front == -1 & rear == -1)
    {
      if (validPatient (&p))
        {
          front++;
          rear++;
          a[rear] = p;
        }
    }
  else
    {
      if (validPatient (&p))
        {
          a[++rear] = p;
        }
      qsort (&a[0], rear + 1, sizeof (Patient), cmp);
    }
}

void
traverse (Patient *a)
{
  if (front == -1 && rear == -1)
    {
      fprintf (stderr, "UNDERFLOW\n");
    }
  else if (front == 0 && rear == 0)
    {
      printPatient (&a[rear]);
    }
  else
    {
      for (int i = front; i <= rear; i++)
        {
          printPatient (&a[i]);
        }
    }
}

void
printSevere (Patient *a)
{
  if (front == -1 && rear == -1)
    {
      fprintf (stderr, "UNDERFLOW\n");
    }
  else
    {
      printf ("\n===========================================\n");
      printf ("                   Severe                      ");
      printf ("\n===========================================\n");
      int severe = 0;
      for (int i = front; i <= rear; i++)
        {
          if (a[i].severity == 1)
            {
              printPatient (&a[i]);
              severe++;
            }
        }
      if (severe==0)
        {
          printf ("(None)\n");
        }
    }
}

void
stats (Patient *a)
{
  if (front == -1 && rear == -1)
    {
      fprintf (stderr, "UNDERFLOW\n");
    }
  else
    {
      int l1 = 0;
      int l2 = 0;
      int l3 = 0;
      int l4 = 0;
      int l5 = 0;
      for (int i = front; i <= rear; i++)
        {
          switch (a[i].severity)
            {
            case 1:
              l1++;
              break;
            case 2:
              l2++;
              break;
            case 3:
              l3++;
              break;
            case 4:
              l4++;
              break;
            case 5:
              l5++;
              break;
            }
        }
      printf ("\n===========================================\n");
      printf ("                 Statistics                    ");
      printf ("\n===========================================\n");
      printf ("Frequency of Patients with Severity Level 1 : %d\n", l1);
      printf ("Frequency of Patients with Severity Level 2 : %d\n", l2);
      printf ("Frequency of Patients with Severity Level 3 : %d\n", l3);
      printf ("Frequency of Patients with Severity Level 4 : %d\n", l4);
      printf ("Frequency of Patients with Severity Level 5 : %d\n", l5);
    }
}

int
cmp (const void *p1, const void *p2)
{
  Patient *p = (Patient *)p1;
  Patient *q = (Patient *)p2;
  if (p->severity < q->severity)
    {
      return -1;
    }
  else if (p->severity > q->severity)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
