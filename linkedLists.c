#include "./headersfiles/linkedLists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    List *lst = listInit();

    pushBack(lst, 5);
    pushBack(lst, 12);
    pushBack(lst, 121);
    pushBack(lst, -12);
    pushBack(lst, 2);

    pushFront(lst, 44);

    printList(*lst);

    printf("%d %d\n", (lst->head)->val, (lst->tail)->val);
}