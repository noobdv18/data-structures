// Binary tree to store integer data
// Does not store digit more than once
// All functions use recursion method

// binary tree condition is that
// left_child < current_node < right_child


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

int store(node *n, node *root);
int print(node* root);
int free_root(node* root);
int search(int input, node* root);

int main(void)
{
    node *root = NULL;
    int check;
    printf("Enter number to store and hit enter for next number.\n");
    printf("Enter any character to indicate end of inputs.\n");
    
    // Get user data and store it inside tree according to conditions
    while (1)
    {
        int input;
        printf("Enter a number: ");
        check = scanf("%d", &input);

        if (check == 0)
        {
            break;
        }

        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            printf("Memory could not be alloted.");
        }

        n->number = input;
        n->left = NULL;
        n->right = NULL;

        if (root == NULL)
        {
            root = n;
        }
        else
        {
            store(n, root);
        }
    }

    //Clear input buffer
    while(getchar() != '\n');

    // Search for a number
    int input;
    printf("Search for a number: \n");
    int scan = scanf ("%d", &input);
    if (scan != 0)
    {
        search(input, root);
    }
    else
    {
        printf("Invalid input\n");
    }

    // Print and free the root
    printf("Data stored in binary tree in ascending order: \n");
    print(root);
    free_root(root);

    return 0;
}


int store(node *n, node *root)
{
    if (n->number < root->number)
    {
        if (root->left == NULL)
        {
            root->left = n;
            return 0;
        }
        else
        {
            store(n, root->left);
        }
    }
    else if (n->number > root->number)
    {
        if (root->right == NULL)
        {
            root->right = n;
            return 0;
        }
        else
        {
            store(n, root->right);
        }
    }
    else
    {
        // Number already exists and not to be stored. Free allocated memory.
        free(n); 
        return 0;
    }
return 0;
}

// prints tree elements in ascending order
int print(node* root)
{
    if(root->left != NULL)
    {
        print(root->left);
        printf("%d\n", root->number); // because root is greater than left and less than right
    }
    else
    {
        printf("%d\n", root->number);
    }

    if (root->right != NULL)
    {
        print(root->right); // right child will be root in next recursion, eventually will be printed as a root.
    }

    return 0;
}

//Free tree elements
int free_root(node* root)
{
    // find lowest child and free data recursively
    if (root->left != NULL) 
    {
        free_root(root->left);
    }
    if (root->right != NULL)
    {
        free_root(root->right);
    }
    else
    {
        free(root);
        return 0;
    }

    free(root);
    return 0;
}

// Binary search 
int search(int input, node* root)
{
    if (input < root->number && root->left != NULL)
    {
        search(input, root->left);
    }
    else if (input > root->number && root->right != NULL)
    {
        search(input,root->right);
    }
    else if (input == root->number)
    {
        printf("Found!\n");
        return 0;
    }
    else
    {
        printf("Not Found!\n");
        return 0;
    }
return 0;
}
