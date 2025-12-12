#include <stdlib.h>
#include <stdio.h>
#include "./headersfiles/trees.h"

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