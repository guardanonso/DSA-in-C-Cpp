typedef struct Node node;
struct Node
{
    node* next;
    int val;
};

typedef struct List List;
struct List
{
    node* head;
    node* tail;
};

node* makeNode(int v);

node* getNodeTail(node* node);

List* listInit();

void printList(List list);

void printNodes(node* Node);

void pushFront(List* lst, int v);

void pushBack(List* List, int v);