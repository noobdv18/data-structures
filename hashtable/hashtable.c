// Hash table containing string nodes
// Maximum allowable length of words is 45

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define bool int
#define true 1
#define false 0

#define LENGTH 26

typedef struct node
{
    char *word;
    struct node *next;
} node;

// Hash table
node *table[LENGTH];

// Function declarations
int hash(char *name);
bool search(char *name);
int print_table(node *table);
void free_table_node(node *tableNode);
bool validate_input(char *input);
bool check_duplicate(char *input);


int main(void)
{

    // Set all values to NULL
    for (int i = 0; i <= LENGTH; i++)
    {
        table[i] = NULL;
    }

    // Get and store user data into hash table
    printf("Enter q to indicate end of list\n");

    char *input;

    while (1)
    {
        printf("Enter a word to insert: ");
        input = malloc(45 * sizeof(char));

        if (input == NULL)
        {
            return 1;
        }

        scanf("%s", input);

        // Validate input
        if (!validate_input(input))
        {
            printf("invalid characters\n");
            free(input);
            continue;
        }

        if (strcasecmp(input, "q") != 0)
        {
            node *element = malloc(sizeof(node));

            if (element == NULL)
            {
                free(element);
                free(input);
                return 1;
            }

            // Check for already existing entry (case insensitive)
            // returns true if copy DOES NOT EXIST.
            if (!check_duplicate(input))
            {
                free(input);
                free(element);
                continue;
            }

            element->word = input;
            element->next = table[hash(input)];
            table[hash(input)] = element;
        }
        else
        {
            free(input); // free 'q'
            break;
        }
    }

    // Print data in hashtable in alphabetical order
    printf("Stored Words in alphabetical order : \n");

    for (int i = 0; i < LENGTH; i++)
    {
        print_table(table[i]);
    }

    // Clear input buffer
    while ((getchar() != '\n'));

    // Search for a name
    printf("Search for: ");
    char *name = malloc(24 * sizeof(char));
    if (name == NULL)
    {
        return 1;
    }

    scanf("%s", name);

    search(name);

    // Free Memory
    for (int i = 0; i <= LENGTH; i++)
    {
        free_table_node(table[i]);
    }
    free(name);

    return 0;
}

// Function definitions
int hash(char *name)
{
    return tolower(name[0]) - 97;
}

bool search(char *name)
{
    // Find hash of name
    int index = hash(name);
    node *tmp = table[index];

    if (tmp != NULL)
    {
        do
        {
            if (strcmp(tmp->word, name) == 0)
            {
                printf("Found!\n");
                return true;
            }
            tmp = tmp->next;
        } while (tmp != NULL);

        printf("Not Found!\n");
        return false;
    }
    else
    {
        printf("Not Found!\n");
        return false;
    }
}

int print_table(node *tableNode)
{
    node *tmp = tableNode;
    if (tmp != NULL)
    {
        // Print linked list of corresponding index of hash table
        do
        {
            printf("%s\n", tmp->word);
            tmp = tmp->next;

        } while (tmp != NULL);
    }

    return 0;
}

void free_table_node(node *tableNode)
{
    if (tableNode != NULL)
    {
        do
        {
            node *tmp = tableNode->next;
            free(tableNode->word);
            free(tableNode);
            tableNode = tmp;
        }
        while (tableNode != NULL);
    }
}

bool validate_input(char *input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        char c = tolower(input[i]);

        if (c > 122 || c < 97)
        {
            return false;
        }

    }
    return true;
}

// Checks for already existing word (case insensitive)
// retuns true if no duplictates else returns false
bool check_duplicate(char *input)
{
    node *tmp = table[hash(input)];

    // If new entry at hashed index
    if (tmp == NULL)
    {
        return true;
    }

    do
    {
        if (strcasecmp(input, tmp->word) == 0)
        {
            return false;
        }

        tmp = tmp->next;
    } while (tmp != NULL);

    return true;
}