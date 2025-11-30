#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node tree;

struct node
{
    int val;
    tree* left;
    tree* right;
};

void removeLeaves(tree** T)
{   
    if ( !(*T) )        // if we end up on NULL ptr
    {
        return;
    }
    else if ((*T)->left == NULL && (*T)->right == NULL)
    {
        free(*T);
        *T = NULL;
        return;
    }
    removeLeaves(&((*T)->left));
    removeLeaves(&((*T)->right));
}

void printTree(tree* T)
{
    if (T == NULL) return;
    printTree(T->left);
    printTree(T->right);
    printf("%d ", T->val);
}

tree* makeNode(int v)
{
    tree* T = malloc(sizeof(tree));
    T->val =  v;
    T->left = NULL;
    T->right = NULL;
    return T;
}

void insert(tree** T, int v)
{
    if (*T == NULL)
    {
        tree* newNode = makeNode(v);
        *T = newNode;
    }
    else if ( (*T)->val >= v )
    {
        insert(&((*T)->left), v);
    }
    else
    {
        insert(&((*T)->right), v);
    }
}

bool search(tree* T, int v)
{
    if(!T) return false;
    else if(T->val == v) return true;
    else if(T->val > v) return search(T->left, v);
    else return search(T->right, v);
}

int main (void)
{
    tree* T = NULL;

    insert(&T, 5);
    insert(&T, 4);
    insert(&T, 10);
    insert(&T, 12);
    insert(&T, 23);
    insert(&T, 1);
    printTree(T);
    printf("\n");

    removeLeaves(&T);
    printTree(T);
}