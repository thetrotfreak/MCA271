#include "stack.h"
#include <stdlib.h>
#include <string.h>

void
newStack (Stack *stack)
{
  stack->top = NULL;
}

void
freeStack (Stack **stack)
{
  while(
}

void
push (Stack *stack, char symbol)
{
  Node *node = (Node *)calloc (1, sizeof (Node));
  if (node == NULL)
    {
      fprintf (stderr, ECA);
      return;
    }
  node->symbol = symbol;
  node->next = stack->top;
  stack->top = node;
}

int
isEmpty (Stack *stack)
{
  return stack->top == NULL ? 0 : 1;
}

char
pop (Stack *stack)
{
  char symbol = '\0';
  if (isEmpty (stack))
    {
      fprintf (stderr, WSU);
    }
  else
    {
      symbol = stack->top;
      Node *temp = stack->top;
      stack->top = stack->next;
      free (temp);
    }
  return symbol;
}

char
peek (Stack *stack)
{
  char symbol = '\0';
  if (isEmpty (stack))
    {
      fprintf (stderr, WSU);
    }
  else
    {
      symbol = stack->top->symbol;
    }
  return symbol;
}
