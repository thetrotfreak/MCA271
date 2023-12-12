#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFIX_EXPRESSION_LENGTH 64


// Function to get the precedence of an operator
int
getPrecedence (char operator)
{
  switch (operator)
    {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return 0; // Assuming parentheses have the lowest precedence
    }
}

// Function to convert infix expression to postfix notation
char *
infixToPostfix (char *infixExpression)
{
  Stack operatorStack;
  initializeStack (&operatorStack);

  int infixLength = strlen (infixExpression);
  char *postfixExpression = (char *)malloc ((infixLength + 1) * sizeof (char));

  if (postfixExpression == NULL)
    {
      fprintf (stderr, "Memory allocation error\n");
      return NULL;
    }

  int postfixIndex = 0;

  for (int i = 0; i < infixLength; ++i)
    {
      char currentChar = infixExpression[i];

      if (isalnum (currentChar))
        {
          postfixExpression[postfixIndex++] = currentChar;
        }
      else if (currentChar == '(')
        {
          push (&operatorStack, currentChar);
        }
      else if (currentChar == ')')
        {
          while (!isEmpty (&operatorStack) && peek (&operatorStack) != '(')
            {
              postfixExpression[postfixIndex++] = pop (&operatorStack);
            }
          printf ("DEBUG: %c\n", postfixExpression[postfixIndex]);

          // Check if there is a '(' on the stack
          if (!isEmpty (&operatorStack) && peek (&operatorStack) == '(')
            {
              pop (&operatorStack); // Pop the '('
            }
          else
            {
              fprintf (
                  stderr,
                  "Error: Mismatched parentheses whilst looking for '('\n");
              free (postfixExpression);
            }
        }
      else
        {
          // Current character is an operator
          while (!isEmpty (&operatorStack)
                 && getPrecedence (peek (&operatorStack))
                        >= getPrecedence (currentChar))
            {
              postfixExpression[postfixIndex++] = pop (&operatorStack);
            }
          push (&operatorStack, currentChar);
        }
    }

  // Pop any remaining operators from the stack
  while (!isEmpty (&operatorStack))
    {
      if (peek (&operatorStack) == '(')
        {
          fprintf (stderr,
                   "Error: Mismatched parentheses whilst popping operators\n");
          free (postfixExpression);
        }
      postfixExpression[postfixIndex++] = pop (&operatorStack);
    }

  postfixExpression[postfixIndex]
      = '\0'; // Null-terminate the postfix expression

  return postfixExpression;
}

// Function to evaluate a postfix expression
int
evaluatePostfix (char *postfixExpression)
{
  Stack operandStack;
  initializeStack (&operandStack);

  int postfixLength = strlen (postfixExpression);

  for (int i = 0; i < postfixLength; ++i)
    {
      char currentChar = postfixExpression[i];

      if (isdigit (currentChar))
        {
          push (&operandStack, currentChar - '0'); // Convert char to int
        }
      else
        {
          // Current character is an operator
          int operand2 = pop (&operandStack);
          int operand1 = pop (&operandStack);

          switch (currentChar)
            {
            case '+':
              push (&operandStack, operand1 + operand2);
              break;
            case '-':
              push (&operandStack, operand1 - operand2);
              break;
            case '*':
              push (&operandStack, operand1 * operand2);
              break;
            case '/':
              push (&operandStack, operand1 / operand2);
              break;
            default:
              fprintf (stderr,
                       "Error: Invalid operator in postfix expression\n");
            }
        }
    }

  // The final result is on the stack
  return pop (&operandStack);
}

int
main ()
{
  char infixExpression[INFIX_EXPRESSION_LENGTH] = "(3 + 4 * ( 2 - 1 ))";
  printf ("Infix Expression: %s\n", infixExpression);

  char *postfixExpression = infixToPostfix (infixExpression);
  printf ("Postfix Expression: %s\n", postfixExpression);
  //
  int result = evaluatePostfix ("23+");
  printf ("Result of Evaluation: %d\n", result);
  //
  //  free (postfixExpression); // Free dynamically allocated memory

  return 0;
}
