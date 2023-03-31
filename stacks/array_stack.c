// Implement stack using an array
// Only one stack structure is allowed 

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *array;
} stack;

// Function declarations
stack *buildStack();
int push(stack *inputStack);
int pop(stack *inputStack);
int isFull(stack *inputStack);
int isEmpty(stack *inputStack);
int top(stack *inputStack);
int printStack(stack *inputStack);
void EmptyStack(stack *inputStack);

int stackflag = 0;

int main(void)
{

    while (1)
    {
        printf("*******************************\n");
        printf(" 1. Create a stack\n 2. Push a number\n 3. Pop a stack\n 4. Check top \n 5. Print Stack \n 6. Empty Stack\n 7. Exit\n\n");

        printf("Enter operation: ");

        int operation;
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:;
            stack *newStack = buildStack();
            break;
        case 2:
            push(newStack);
            break;
        case 3:
            pop(newStack);
            break;
        case 4:
            top(newStack);
            break;
        case 5:
            printStack(newStack);
            break;
        case 6:
            EmptyStack(newStack);
            break;
        case 7:
            free(newStack->array);
            free(newStack);
            return 0;

        default:
            break;
        }
    }
    return 0;
}

// Functions:

stack *buildStack(void)
{
    // User input
    if (stackflag == 0)
    {
        printf("enter size of stack: ");
        int size;
        scanf("%d", &size);

        stack *newStack = malloc(sizeof(stack));

        if (newStack == NULL)
        {
            printf("Memory could not be allotted!");
            return NULL;
        }

        newStack->size = size;
        newStack->top = 0;

        int *stackArray = malloc(sizeof(int) * size);
        newStack->array = stackArray;
        EmptyStack(newStack);

        printf("New Stack created succssfully!\n\n");
        stackflag = 1;

        return newStack;
    }
    else
    {
        printf("One stack already exists!\nAnd only one allowed currently!\n\n");
        return NULL;
    }
}


int push(stack *inputStack)
{
    if (inputStack == NULL)
    {
        printf("No stack available\n");
        return 1;
    }

    printf("Enter a number to push: ");
    int number;
    scanf("%d", &number);

    if (isFull(inputStack))
    {
        printf("Stack is full!");
        return 1;
    }

    int topIndex = inputStack->top;
    inputStack->array[topIndex] = number;
    inputStack->top++;

    printf("%d pushed successfully on stack.\n\n", number);
    return 0;
}

int pop(stack *inputStack)
{
    if (inputStack == NULL)
    {
        printf("No stack available\n");
        return 1;
    }

    if (inputStack == NULL)
    {
        printf("No stack available\n");
        return 1;
    }

    if (isEmpty(inputStack))
    {
        printf("Stack is empty!");
        return 1;
    }

    int number = inputStack->array[inputStack->top - 1];
    inputStack->array[inputStack->top - 1] = 0;
    inputStack->top -= 1;

    printf("Number %d successfully popped out! \n\n", number);

    return 0;
}

int isFull(stack *inputStack)
{
    if (inputStack == NULL)
    {
        printf("No stack available\n");
        return 1;
    }

    if (inputStack->top - 1 == inputStack->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(stack *inputStack)
{
    if (inputStack == NULL)
    {
        printf("No stack available\n");
        return 1;
    }

    if (inputStack->top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int top(stack *inputStack)
{
    if (inputStack == NULL)
    {
        printf("No stack available\n");
        return 1;
    }

    int top = inputStack->top;
    int topElement = inputStack->array[top - 1];
    printf("top index is %d\ntop element is %d \n\n", top, topElement);
    return topElement;
}

int printStack(stack *inputStack)
{
    if (inputStack == NULL)
    {
        printf("No stack available\n");
        return 1;
    }

    if (isEmpty(inputStack))
    {
        printf("Stack is empty! Nothing to print!\n");
        return 1;
    }

    for (int i = (inputStack->top - 1); i >= 0; i--)
    {
        printf("%d\n", inputStack->array[i]);
    }
    return 0;
}

void EmptyStack(stack *inputStack)
{
    if (inputStack == NULL)
    {
        printf("No stack available\n");
        return;
    }

    int length = inputStack->top;
    for (int i = 0; i < length; i++)
    {
        inputStack->array[i] = 0;
        inputStack->top -= 1;
    }

    printf("Stack emptied Successfully!\n\n");
}
