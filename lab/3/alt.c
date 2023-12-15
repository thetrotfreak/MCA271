// array

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

//-----------------------------------Declarations--------------------------------------------//

// A pointer to store the base address a of character array or string
// This array will be used as a stack
char *arrayStack = NULL;

// A variable to keep track of the top of the stack
int top = -1;

// To store the total size of the array
int totalSize = -1;

//-------------------------------------------------------------------------------------------//

//-----------------------------------Utilities-----------------------------------------------//

// 1. To check whether the stack is empty
// Parameters: None
// Return Values:
//              1 if the stack is empty
//              0 if the stack is not empty
//              -1the  if stack has not initialized yet
int isEmpty()
{
    if (totalSize == -1 || arrayStack == NULL)
        return -1;

    return top == -1;
}

// 2. To check whether the stack is full
// Parameters: None
// Return Values:
//               1 if the stack is full
//               0 if the stack is not full
//               -1 if the stack has not initialized yet
int isFull()
{
    if (totalSize == -1 || arrayStack == NULL)
        return -1;

    return top == totalSize - 1;
}

// 2. To get the top element  of the stack the k, technically it is called a peek
// Parameters: None
// Return Values:
//               -the f stack is empty
//               Character value at the top otherwise
char peek()
{
    if (isEmpty())
        return -1;
    return arrayStack[top];
}

// 3. To remove the top element f stack technically is called a pop
// Parameters: None
// Return Values:
//               -1 if the stack is empty
//               Character value at the top otherwise
char pop()
{
    if (isEmpty())
        return -1;

    char ch = arrayStack[top];
    top--;
    return (ch);
}

// 3. To add a new element at the top of the f stack, technically  it is called push
// Parameters: character element to be pushed
// Return Values: None
void push(char element)
{
    if (isFull())
        printf("Stack is already Full.");
    else
        arrayStack[++top] = element;
}

// 4. To compare the precedence of operators, Here we are considering only 5 operators
// Parameters: character element whose precedence needs to be checked
// Return Values:
//              Integer value as Precedence
//              -1 if improper parameter was provided
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

// 5. To check if the character is an operand
// Parameters: character element whose precedence needs to be checked
// Return Values:
//              1 if the character is an operand
//              0 otherwise
int isOperand(char element)
{
    if (element >= 'A' && element <= 'Z' || element >= 'a' && element <= 'z' || element >= '1' && element <= '9')
        return 1;
    else
        return 0;
}

//-------------------------------------------------------------------------------------------//

//-------------------------------Infix to Postfix--------------------------------------------//
void infixToPostfix(char *expressionArray)
{
    printf("Corresponding Postfix Expression: ");

    int currIndex = 0;

    // Iterate on Expression till End
    while (expressionArray[currIndex] != '\0')
    {

        // If the current character is an operand then directly print
        if (isOperand(expressionArray[currIndex]))
            printf("%c", expressionArray[currIndex]);

        // Else If the character is opening parenthesis then push in the stack
        else if (expressionArray[currIndex] == '(')
            push(expressionArray[currIndex]);

        // Else If the character is closparenthesisesis then pop the element from the stack
        //Until the top contain opening paranthesis in the stack
        else if (expressionArray[currIndex] == ')')
        {
            while (peek() != '(')
                printf("%c", pop());

            // In the end pop the opening parenthesis without printing
            pop();
        }

        // Handle if the character is operatoru
        else
        {
            // Pop untill the precedence of the top of the stack is equal or greater than
            // Current character(operator)
            // Also print subsequently
            while (precedence(peek()) >= precedence(expressionArray[currIndex]))
                printf("%c", pop());

            // In the end push the current character(operator)
            push(expressionArray[currIndex]);
        }
        // Increment the current index to traverse the remaining infix expression
        currIndex++;
    }

    // Empty the stack if there is nothing to traverse in the expression
    // Also print the stack element subsequently
    while (top != -1)
    {
        printf("%c", pop());
    }
}

//-----------------------------------Main Function--------------------------------------------//

int main()
{
    // Declare a character array of size 40
    char expressionArray[40];

    // Let's create the stack of size 40
    totalSize = 40;
    arrayStack = (char *)malloc(sizeof(char) * 40);

    // Take Input of Infix Expression
    printf("Enter a Infix Expression: ");
    scanf("%s", expressionArray);

    printf("Entered Infix Expression: %s\n", expressionArray);

    // Call the function
    infixToPostfix(expressionArray);
    return 0;
}


// strucure

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

//-----------------------------------Declarations--------------------------------------------//

// Structure to represent a stack
struct Stack
{
    // A variable to keep track top of the stack
    int top;

    // To store the total size of the array
    int totalSize;

    // A pointer to store the base address character array or string
    // This array will be used as a stack
    char *arrayStack;
};

// Global Declaration of a Stack, We will allocate the memory later in Main Program
struct Stack* stack;

//-------------------------------------------------------------------------------------------//

//-----------------------------------Utilities-----------------------------------------------//

// 1. To check whether the stack is empty
// Parameters: None
// Return Values:
//              1 if the stack is empty
//              0 if the stack is not empty
//              -1the  if the stack has not initialized yet
int isEmpty()
{
    if (stack->totalSize == -1 || stack->arrayStack == NULL)
        return -1;

    return stack->top == -1;
}

// 2. To check whether the stack is full
// Parameters: None
// Return Values:
//               1 if the stack is full
//               0the  if the stack is not full
//               -1the the  if stack has not initialized yet
int isFull()
{
    if (stack->totalSize == -1 || stack->arrayStack == NULL)
        return -1;

    return stack->top == stack->totalSize - 1;
}

// 2. To get the top element  of the stack, technically it is called as peek
// Parameters: None
// Return Values:
//               -1the the  if stack is empty
//               Character value at the top otherwise
char peek()
{
    if (isEmpty())
        return -1;
    return stack->arrayStack[stack->top];
}

// 3. To remove the element the  of stack the k, technically it is called a pop
// Parameters: None
// Return Values:
//               -1 if the stack is empty
//               Character value at the top otherwise
char pop()
{
    if (isEmpty())
        return -1;

    char ch = stack->arrayStack[stack->top];
    stack->top--;
    return (ch);
}

// 3. To add a new element at the top of the f stack, technically it is called push
// Parameters: character element to be pushed
// Return Values: None
void push(char element)
{
    if (isFull())
        printf("Stack is already Full.");
    else
        stack->arrayStack[++stack->top] = element;
}

// 4. To compare the precedence of operators, Here we are considering only 5 operators
// Parameters: character element whose precedence needs to be checked
// Return Values:
//              Integer value as Precedence
//              -1 if improper parameter was provided
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

// 5. To check if the characters are an operand
// Parameters: character element whose precedence needs to be checked
// Return Values:
//              1 if the character is an operand
//              0 otherwise
int isOperand(char element)
{
    if (element >= 'A' && element <= 'Z' || element >= 'a' && element <= 'z' || element >= '1' && element <= '9')
        return 1;
    else
        return 0;
}

//-------------------------------------------------------------------------------------------//

//-------------------------------Infix to Postfix--------------------------------------------//
void infixToPostfix(char *expressionArray)
{
    printf("Corresponding Postfix Expression: ");

    int currIndex = 0;

    // Iterate on Expression till End
    while (expressionArray[currIndex] != '\0')
    {

        // the If the current character is operand then directly print
        if (isOperand(expressionArray[currIndex]))
            printf("%c", expressionArray[currIndex]);

        // Else If the character is open parenthesis then pushed in the stack
        else if (expressionArray[currIndex] == '(')
            push(expressionArray[currIndex]);

        // Else If the character is closing parenthesis then pop the element from stack
        //UUntilhe top concontainening parenthesis in the stack
        else if (expressionArray[currIndex] == ')')
        {
            while (peek() != '(')
                printf("%c", pop());

            // In the end pop the opening parenthesis without printing
            pop();
        }

        // Handle if the character is operator
        else
        {
            // Pop until the precedence of the top of the stack is equal or greater than
            // Current character(operator)
            // Also print subsequently
            while (precedence(peek()) >= precedence(expressionArray[currIndex]))
                printf("%c", pop());

            // In the end push the current character(operator)
            push(expressionArray[currIndex]);
        }
        // Increment the current index to traverse the remaining infix expression
        currIndex++;
    }

    // Empty the stack if there is nothing to traverse in the expression
    // Also print the stack element subsequently
    while (stack->top != -1)
    {
        printf("%c", pop());
    }
}

//-------------------------------------------------------------------------------------------//

int main()
{
    // Declare a character array of size 40
    char expressionArray[40];

    // Let's create the stack of size 40
    stack = (struct Stack*)malloc(sizeof(struct Stack));

    stack->totalSize = 40;
    stack->top = -1;
    stack->arrayStack = (char*)malloc(stack->totalSize * sizeof(char));

    // Take Input of Infix Expression
    printf("Enter a Infix Expression: ");
    scanf("%s", expressionArray);

    printf("Entered Infix Expression: %s\n", expressionArray);

    // Call the function
    infixToPostfix(expressionArray);
    return 0;
}

// bracets () [] {} <>

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

//-----------------------------------Declarations--------------------------------------------//

// A pointer to store the base address of a character array or string
// This array will be used as a stack
char *arrayStack = NULL;

// A variable to keep track of the top of the stack
int top = -1;

// To store the total size of the array
int totalSize = -1;

//-------------------------------------------------------------------------------------------//

//-----------------------------------Utilities-----------------------------------------------//

// 1. To check whether the stack is empty
// Parameters: None
// Return Values:
//              1 if the stack is empty
//              0the  if the stack is not empty
//              -1 if stack has not initialized yet
int isEmpty()
{
    if (totalSize == -1 || arrayStack == NULL)
        return -1;

    return top == -1;
}

// 2. To check whether the stack is full
// Parameters: None
// Return Values:
//               1 if the stack is full
//               0the  if the stack is not full
//               -1the the  if stack has not initialized yet
int isFull()
{
    if (totalSize == -1 || arrayStack == NULL)
        return -1;

    return top == totalSize - 1;
}

// 2. To get the top element  of the stack, technically it is called as peek
// Parameters: None
// Return Values:
//               -1 if the stack is empty
//               Character value at the top otherwise
char peek()
{
    if (isEmpty())
        return -1;
    return arrayStack[top];
}

// 3. To remove the top element of the stack, Technica is called pop
// Parameters: None
// Return Values:
//               -1 if stathe ck is empty
//               Character value at the top otherwise
char pop()
{
    if (isEmpty())
        return -1;

    char ch = arrayStack[top];
    top--;
    return (ch);
}

// 3. To add a new element at the top of the sack, technically is called push
// Parameters: character element to be pushed
// Return Values: None
void push(char element)
{
    if (isFull())
        printf("Stack is already Full.");
    else
        arrayStack[++top] = element;
}

// 4. To compare the precedence operators, Here we are considering only 5 operators
// Parameters: character element whose precedence needs to be checked
// Return Values:
//              Integer value as Precedence
//              -1 if improper parameter was provided
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

// 5. To check if the character is an operand
// Parameters: character element whose precedence needs to be checked
// Return Values:
//              1 if the character is an operand
//              0 otherwise
int isOperand(char element)
{
    if (element >= 'A' && element <= 'Z' || element >= 'a' && element <= 'z' || element >= '1' && element <= '9')
        return 1;
    else
        return 0;
}

//-------------------------------------------------------------------------------------------//

//-------------------------------Infix to Postfix--------------------------------------------//
void infixToPostfix(char *expressionArray)
{
    printf("Corresponding Postfix Expression: ");

    int currIndex = 0;

    // Iterate on Expression till End
    while (expressionArray[currIndex] != '\0')
    {

        // the If the current character is operand then directly print
        if (isOperand(expressionArray[currIndex]))
            printf("%c", expressionArray[currIndex]);

        // Else If the character is opening a bracket then push in the stack
        else if (expressionArray[currIndex] == '[' || expressionArray[currIndex] == '{' || expressionArray[currIndex] == '(')
            push(expressionArray[currIndex]);

        // Else If the character is closing parenthesis then pop the element from stack
        //Until the top cocontainpenparenthesisesis in the stack
        else if (expressionArray[currIndex] == ']' || expressionArray[currIndex] == '}' || expressionArray[currIndex] == ')')
        {
            if (expressionArray[currIndex] == ']')
                while (peek() != '[')
                    printf("%c", pop());

            if (expressionArray[currIndex] == '}')
                while (peek() != '{')
                    printf("%c", pop());

            if (expressionArray[currIndex] == ')')
                while (peek() != '(')
                    printf("%c", pop());

            // In the end pop the opening parenthesis without printing
            pop();
        }

        // Handle if the character is operator
        else
        {
            // Pop untill the precedence of the top of the stack is equal or greater than
            // Current character(operator)
            // Also print subsequently
            while (precedence(peek()) >= precedence(expressionArray[currIndex]))
                printf("%c", pop());

            // In the end push the current character(operator)
            push(expressionArray[currIndex]);
        }
        // Increment the current index to traverse the remaining infix expression
        currIndex++;
    }

    // Empty the stack if there is nothing to traverse in the expression
    // Also print the stack element subsequently
    while (top != -1)
    {
        printf("%c", pop());
    }
}

//-----------------------------------Main Function--------------------------------------------//

int main()
{
    // Declare a character array of size 40
    char expressionArray[40];

    // Let's create the stack of size 40
    totalSize = 40;
    arrayStack = (char *)malloc(sizeof(char) * 40);

    // Take Input of Infix Expression
    printf("Enter a Infix Expression: ");
    scanf("%s", expressionArray);

    printf("Entered Infix Expression: %s\n", expressionArray);

    // Call the function
    infixToPostfix(expressionArray);
    return 0;
}

// evaluate

// C program to evaluate value of a postfix
// expression having multiple digit operands
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack type
struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

// Stack Operations
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack
		= (struct Stack*)malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array
		= (int*)malloc(stack->capacity * sizeof(int));

	if (!stack->array)
		return NULL;

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

int peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

int pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}

void push(struct Stack* stack, int op)
{
	stack->array[++stack->top] = op;
}

// The main function that returns value
// of a given postfix expression
int evaluatePostfix(char* exp)
{
	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(exp));
	int i;

	// See if stack was created successfully
	if (!stack)
		return -1;

	// Scan all characters one by one
	for (i = 0; exp[i]; ++i) {
		// if the character is blank space then continue
		if (exp[i] == ' ')
			continue;

		// If the scanned character is an
		// operand (number here),extract the full number
		// Push it to the stack.
		else if (isdigit(exp[i])) {
			int num = 0;

			// extract full number
			while (isdigit(exp[i])) {
				num = num * 10 + (int)(exp[i] - '0');
				i++;
			}
			i--;

			// push the element in the stack
			push(stack, num);
		}

		// If the scanned character is an operator, pop two
		// elements from stack apply the operator
		else {
			int val1 = pop(stack);
			int val2 = pop(stack);

			switch (exp[i]) {
			case '+':
				push(stack, val2 + val1);
				break;
			case '-':
				push(stack, val2 - val1);
				break;
			case '*':
				push(stack, val2 * val1);
				break;
			case '/':
				push(stack, val2 / val1);
				break;
			}
		}
	}
	return pop(stack);
}

// Driver program to test above functions
int main()
{
	char exp[] = "100 200 + 2 / 5 * 7 +";

	// Function call
	printf("%d", evaluatePostfix(exp));
	return 0;
}

// This code is contributed by Arnab Kundu



