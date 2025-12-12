#include "./../headersfiles/linkedLists.h"
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

// given a node ptr "node" (!= NULL), the function returns a pointer to
// the last node of the list
node* getNodeTail(node* node)
{
    if(!node->next) return node;
    else
    {
        return getNodeTail(node->next);
    }
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

// pushBack wrapper for user-interface
void pushBack(List* lst, int v)
{
    if(!(lst->head))
    {
        pushFront(lst, v);
        return;
    }
    lst->tail->next = makeNode(v);
    lst->tail = lst->tail->next;
}
