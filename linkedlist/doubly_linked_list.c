// Doubly linked list

#include <stdio.h>
#include <stdlib.h>

// Define a node that will contain our data and a pointer to next node
typedef struct node
{
    int number;
    struct node *next;
    struct node *back;
} node;

int main(void)
{
    printf("Enter any char at the end of the list and hit enter.\n");

    // Initialize the linked list
    node *head = NULL;

    // Create an int variable to track return value of scanf which returns 0 if char entered instead of an int for %d
    // This value will be used as an indicator of end of the list
    int value;
    
    node *tmp;

    while (1)
    {
        printf("Enter a number: ");

        // First Node
        if (head == NULL)
        {
            node *n = (node *)malloc(sizeof(node));

            if (n == NULL)
            {
                return 1;
            }

            value = scanf("%d", &(n->number));

            if (value == 0)
            {
                break;
            }

            n->back = NULL;
            n->next = NULL;
            // |n| -> |NULL|data|NULL|

            head = n;
            // |head| -> |NULL|data|NULL|  (first Node)

            tmp = head;
            // |tmp| -> |NULL|data|NULL|  (first Node)
        }

        // Succeding nodes
        else
        {
            node *n = (node *)malloc(sizeof(node));

            if (n == NULL)
            {
                do
                {
                    node *n = head->next;
                    free(head);
                    head = n;
                } while (head->next != NULL);
            }

            value = scanf("%d", &(n->number));
            if (value == 0)
            {
                break;
            }
            n->back = tmp;
            n->next = NULL;
            // n -> |&previousNode|data|NULL|

            tmp->next = n;
            // |previous Node| -> |&previousNode|data|NULL| (new Node)

            tmp = n;
            // |tmp| -> |&previousNode|data|NULL| (new Node)
        }
    }

    // Print the list either ascending or descending

    // Prompt Ascending or Descending
    printf("Enter a for ascending and d for Descending order: ");
    char order;
    char trash, trash2;
    
    // Clear the buffer
    scanf("%c%c", &trash, &trash2);
    scanf("%c", &order);

    node *n = head;
    node *end = NULL;

    if (n != NULL) // Confirm that inputs were given
    {
        if (order == 'a')
        {
            node *start = head;
            do
            {
                printf("%d\n", start->number);
                start = start->next;
            } while (start != NULL);
        }
        else if (order == 'd')
        {
            
            do
            {
                end = n;
                n = n->next;
            } while (n != NULL);

            do
            {
                printf("%d\n", end->number);
                end = end->back;
            } while (end != NULL);
        }

        // Free all the malloc'ed memory
        n = head;
        do
        {
            n = n->next;
            free(head);
            head = n;
        } while (n != NULL);
    }
    else
    {
        printf("No valid inputs were received.\n");
        return 1;
    }
}
