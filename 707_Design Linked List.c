//singly linked list

typedef struct Node
{
    int val;
    struct Node *next;
} Node;


typedef struct List {
    Node *head;
    int count;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {

    MyLinkedList *ptr=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    ptr->head=NULL;
    ptr->count=0;
    return ptr;
}

int myLinkedListGet(MyLinkedList* obj, int index) {

    if(index>obj->count-1||!obj->head)
        return -1;
    
    Node *ptr=obj->head;
    for(int i=0;i<index;++i)
        ptr=ptr->next;
    return ptr->val;   
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

    Node dummy;
    dummy.next=obj->head;
    Node *ptr=(Node *)malloc(sizeof(Node));
    ptr->val=val;
    ptr->next=NULL;

    ptr->next=dummy.next;
    dummy.next=ptr;
    obj->head=dummy.next;
    obj->count++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {

    Node dummy;
    dummy.next=obj->head;
    Node *ptr=(Node *)malloc(sizeof(Node));
    ptr->val=val;
    ptr->next=NULL;

    Node *temp=&dummy;
    while(temp->next)
        temp=temp->next;
    temp->next=ptr;
    obj->head=dummy.next;
    obj->count++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    if(index>obj->count)
        return;

    Node dummy;
    dummy.next=obj->head;
    Node *ptr=(Node *)malloc(sizeof(Node));
    ptr->val=val;
    ptr->next=NULL;

    Node *temp=&dummy;
    
    for(int i=0;i<index;++i)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    obj->head=dummy.next;
    obj->count++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

    if(index>obj->count-1)
        return;
    
    Node dummy;
    dummy.next=obj->head;
    Node *temp=&dummy;

    for(int i=0;i<index;++i)
        temp=temp->next;
    Node *temp2=temp->next;
    temp->next=temp->next->next;
    free(temp2);
    obj->head=dummy.next;
    obj->count--;
}

void myLinkedListFree(MyLinkedList* obj) {

    Node *ptr=obj->head;
    while(obj->count)
        myLinkedListDeleteAtIndex(obj,0);
    free(obj);
}
