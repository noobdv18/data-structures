#include <stdio.h>
#include <stdlib.h>

// Define a node that will contain our data and pointer to next node
typedef struct node
{
    int number;
    struct node* next; 
}
node;


int main(void)
{
    // Initialize the linked list
    node* list = NULL;

    // Create first node and enter data, set next value to be NULL
    node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        return 1;
    } 

    n -> number = 1;
    n -> next = NULL;

    // Assign list address of first node i.e. n
   
    list = n;
    // |list| -> | 1 | NULL |
    
    // Create a second node
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }

    n -> number = 2;
    n -> next = NULL;
    // | n | -> | 2 | NULL |
    
    // Assign address of second node to next field of first node
    list -> next = n;
    // |list|-> | 1 |  | -> | 2 | NULL | 

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list -> next);
        free(list);
        return 1;
    }

    n -> number = 3; 
    n -> next = NULL;
    // |n| -> | 3 | NULL |

    // Now assign address of third node to next field of second node
    list -> next -> next = n;
    // |list| -> | 1 |  | -> | 2 |  | -> | 3 | NULL |


    // Print the linked list from start to end
    n = list; 
    do 
    {
        printf("%d\n", n -> number);
        n = n -> next;
    }
    while (n != NULL);

    // Reverse the linked list

    // Free all the malloc'ed memory
    do
    {
        node* n = list -> next; 
        free(list);
        list = n ; 
    }
    while (list -> next != NULL);

    free(list);
    // because last node has next field null, loop will stop before freeing it
    // So free it separately
    
}

