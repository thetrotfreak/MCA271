#ifndef STACK_H
#define STACK_H

#define ECA "error: calloc() failed\n"
#define EMA "error: malloc() failed\n"
#define WSO "warning: stack overflow\n"
#define WSU "warning: stack underflow\n"

typedef struct Node
{
  char symbol;
  struct Node *next;
} Node;

typedef struct Stack
{
  Node *top;
} Stack;

void newStack (Stack *);
void freeStack (Stack **);

void push (Stack *, char);
int isEmpty (Stack *);
char pop (Stack *);
char peek (Stack *);

#endif // STACK_H
