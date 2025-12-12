#include "./headersfiles/linkedLists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    List* lst = listInit();

    pushBackLst(lst, 5);
    pushBackLst(lst, 12);
    pushBackLst(lst, 121);
    pushBackLst(lst, -12);
    pushBackLst(lst, 2);

    pushFront(lst, 44);

    printList(*lst);

    printf("%d %d\n", (lst->head)->val, (lst->tail)->val);
}