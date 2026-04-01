#include "./../include/linkedLists.h"
#include <stdlib.h>
#include <stdio.h>

// given an int value v, the function returns pointer to node struct
node* makeNode(int v)
{
    node* newNode = malloc(sizeof(node));
    newNode->val =  v;
    newNode->next = NULL;
    return newNode;
}

// returns a List ptr with head and tail set to NULL
List* listInit()
{
    List* newList = malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
};

// printNodes() wrapper for user-interface
void printList(List list)
{
    printNodes(list.head);
}

// given node ptr "Node", prints whole list pointed by Node
void printNodes(node* Node)
{
    if(!Node)
    {
        printf("\n");
        return;
    }
    printf("%d ", Node->val);
    printNodes(Node->next);
}

void pushFront(List* lst, int v)
{
    node* newNode = makeNode(v);
    newNode->next = lst->head;
    lst->head = newNode;
    if(!lst->tail)
    {
        lst->tail = lst->head;
    }
}


void pushBack(List* lst, int v)
{
    if(!(lst->head))
    {
        pushFront(lst, v);
        return;
    }
    else
    {
        lst->tail->next = makeNode(v);
        lst->tail = lst->tail->next; 
    }
}

// wrapper that calls freeNode() on lst->head
void freeList(List* lst)
{
    freeNode(lst->head);
}

// free whole list pointed by a node, iteratively
void freeNode(node* Node)
{
    node* curr = Node;
    while(curr)
    {
        Node = Node->next;
        free(curr);
        curr = Node;	
    }

}
