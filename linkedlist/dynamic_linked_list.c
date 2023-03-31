// Dynamically added linked list

#include <stdio.h>
#include <stdlib.h>

// Define a node that will contain our data and a pointer to next node
typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    printf("Enter any char at the end of the list and hit enter.\n");

    // Initialize the linked list
    node *head = NULL;

    // Create an int variable to track return value of scanf which returns 0 if char entered instead of an int for %d
    // This value will be used as an indicator of end of the list

    // Add user data to list
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

            n->next = NULL;

            head = n;
            tmp = head;
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
            n->next = NULL;

            tmp->next = n;
            tmp = n;
        }
    }

    // Print the linked list from start to end if inputs were given
    node *n = head;

    if (n != NULL)
    {
        do
        {
            printf("%d\n", n->number);
            n = n->next;
        } while (n != NULL);
    

        // Free all the malloc'ed memory
        do
        {
            node *n = head->next;
            free(head);
            head = n;
        } while (head->next != NULL);

        free(head);
        // because last node has next field null, loop will stop before freeing it
        // So free it separately
    }
    else
        {
            printf("No valid inputs were received.\n");
            return 1;
        }
}
