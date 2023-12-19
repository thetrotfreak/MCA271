#ifndef _PATIENT_H
#define _PATIENT_H

#define SIZE 128

typedef enum t_Severity_Level_of_Illness
{
  L1 = 1,
  L2 = 2,
  L3 = 3,
  L4 = 4,
  L5 = 5
} Severity;

typedef struct t_Patient
{
  unsigned int id;
  unsigned short age;
  Severity severity;
} Patient;

extern int front;
extern int rear;

void printPatient (Patient *);
void enqueue (Patient *, Patient);
void traverse (Patient *);
void printSevere (Patient *);
void stats (Patient *);
int cmp (const void *p1, const void *p2);

#endif // _PATIENT_H
