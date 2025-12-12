#include <stdbool.h>

typedef struct node tree;
struct node
{
    int val;
    struct node* left;  // Meglio usare struct node* qui per evitare problemi di scope
    struct node* right;
};

void removeLeaves(tree** T);

void printTree(tree* T);

tree* makeNode(int v);

void insert(tree** T, int v);

bool search(tree* T, int v);