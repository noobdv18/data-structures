// Implement a stack structure using linked list
// Stack will contain int data types only
// Only one stack is allowed currently

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

// Function declarations

node **CreateListStack();
int push(node **pointer);
int pop(node **pointer, node *head);
int topElement(node *head);
int printStack(node *head);
int EmptyStack(node** pointer, node *head);
int isEmpty(node *head);
int size(node *head);

int stackflag = 0;

int main(void)
{
    // Get input from user and execute respective operation
    while (1)
    {
        printf("\n*******************************\n");
        printf(" 1. Create a stack\n 2. Push a number\n 3. Pop a stack\n 4. Check top \n 5. Print Stack \n 6. Empty Stack\n 7. Exit\n");

        printf("Enter operation: ");

        int operation;
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:;
            node **head_pointer = CreateListStack(); // head_pointer points to stack variable in in stack memory
            node *stack = *head_pointer;
            break;
        case 2:
            push(&stack); // argument requires variable that points to heap memory
            break;        // therefore &stack and not head_pointer
        case 3:
            pop(&stack, stack);
            break;
        case 4:
            topElement(stack);
            break;
        case 5:
            printStack(stack);
            break;
        case 6:
            EmptyStack(&stack, stack);
            break;
        case 7:
            EmptyStack(&stack, stack);
            printf("Good bye!\n");
            return 0;
        default:
            printf("Invalid operation!\n");
            return 1;
        }
    }
    return 0;
}

node **CreateListStack()
{
    if (stackflag == 1)
    {
        printf("Stack already exists!\n");
        return NULL;
    }

    node *head = NULL;

    node **pointer = &head;

    printf("Empty stack has been created!\n");
    stackflag = 1;
    return pointer;
}

int push(node **pointer)
{
    if (stackflag == 0)
    {
        printf("No stack is created!\n");
        return 1;
    }

    printf("Enter a number to push: ");
    int input;
    scanf("%d", &input);

    // First node

    if (*pointer == NULL)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            printf("Memory could not be allotted!\n");
            return 1;
        }

        n->number = input;
        n->next = NULL;
        *pointer = n;

        printf("%d has been successfully pushed on the stack.\n\n", input);
        return 0;
    }
    else
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Memory Could not be allotted!\n");
            return 1;
        }

        n->number = input;
        n->next = NULL;

        node *tmp = *pointer;
        *pointer = n;
        n->next = tmp;

        printf("%d has been successfully pushed on the stack.\n", input);
        return 0;
    }
}

int pop(node **pointer, node *head)
{
    // return if no stack is created or stack is empty

    if (stackflag == 0)
    {
        printf("No stack is created!\n");
        return 1;
    }
    else if (head == NULL)
    {
        printf("Stack is empty!\n");
        return 1;
    }

    if(size(head) == 1)
    {   
        printf("%d has successfully been popped out of the stack!\n", head->number);
        free(head);
        *pointer = NULL;
        
        return 0;
    }

    node *tmp = head->next;
    int top = head->number;
    free(head);
    *pointer = tmp;

    printf("%d has successfully popped out of the stack!\n", top);
    return 0;
}

int topElement(node *head)
{
    if (stackflag == 0)
    {
        printf("No stack is created!\n");
        return 1;
    }
    if (isEmpty(head))
    {
        printf("Stack is empty\n");
        return 1;
    }
    printf("top element is %d\n", head->number);

    return head->number;
}

int printStack(node *head)
{
    if (stackflag == 0)
    {
        printf("No stack is created!\n");
        return 1;
    }

    if (isEmpty(head))
    {
        printf("Stack is empty\n");
        return 1;
    }
    
    node *tmp = head;
    do
    {
        printf("%d\n", tmp->number);
        tmp = tmp->next;
    } while (tmp != NULL);

    return 0;
}

int EmptyStack(node** pointer, node *head)
{
    if (stackflag == 0)
    {
        printf("No stack is created!\n");
        return 1;
    }

    if (isEmpty(head))
    {
        printf("Stack is already empty\n");
        return 1;
    }

    node *tmp = head;

    do
    {
        tmp = tmp->next;
        free(head);
        head = tmp;

    } while (tmp != NULL);

    *pointer = NULL;

    printf("stack has been emptied!\n");
    return 0;
}

int isEmpty(node *head)
{
    if (stackflag)
    {
        if (head == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("No stack created!\n");
        return 0;
    }
}

int size(node *head)
{
    if (stackflag == 0)
    {
        printf("No stack is created!\n");
        return 1;
    }

    if (isEmpty(head))
    {
        printf("Stack is empty\n");
        return 1;
    }

    node *tmp = head;
    int counter = 0;

    while (tmp != NULL)
    {
        tmp = tmp->next;
        counter += 1;
    }
    return counter;
}
