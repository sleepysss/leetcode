//arr type method 1

typedef struct {
    int *store;
    int front,rear,size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *q=(MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    q->store=(int *)malloc(sizeof(int)*(k+1));  //要多設一格,因為其中一個需要被浪費
    q->size=k+1;
    q->front=q->rear=0;
    return q;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj&&(obj->front==obj->rear))
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj&&((obj->rear+1)%obj->size==obj->front))
        return true;
    else
        return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if(myCircularQueueIsFull(obj))
        return false;
    obj->rear=(obj->rear+1)%obj->size;
    obj->store[obj->rear]=value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    obj->front=(obj->front+1)%obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;

    return obj->store[(obj->front+1)%obj->size];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;
    return obj->store[obj->rear];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->store);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/


//arr type method 2

typedef struct Q {
    int front;
    int back;
    int *store;
    int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue *ptr=(MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    ptr->front=-1; //含
    ptr->back=-1; //含
    ptr->store=(int *)malloc(sizeof(int)*k);
    ptr->size=k;
    return ptr;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if((obj->back+1)%obj->size==obj->front) //full
    {
        return false;
    }
    else if(obj->front==-1) //empty
    {
        obj->front++;
    }
    obj->back=(obj->back+1)%obj->size;
    obj->store[obj->back]=value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {

    if(obj->front==-1) //empty
        return false;
    if(obj->front==obj->back) //剩一個(一定要做這個,不然不會work)
        obj->front=obj->back=-1; //丟回index-1
    else
        obj->front=(obj->front+1)%obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {

    return obj->front==-1?-1:obj->store[obj->front];

}

int myCircularQueueRear(MyCircularQueue* obj) {

    return obj->back==-1?-1:obj->store[obj->back];
    
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    //  empty時,back和front一定會是-1(因為init和dequeue的關係)

    return obj->front==-1; //或obj->back==-1
    
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {

    return (obj->back+1)%obj->size==obj->front;
    
}

void myCircularQueueFree(MyCircularQueue* obj) {

    free(obj->store);
    free(obj);
}




//linked list

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct Q {
    Node *front;
    Node *back;
    int size;
    int count;
} MyCircularQueue;


// 1 -> 2 -> 3 -> NULL
// front     back

MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue *ptr=(MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    ptr->front=NULL;
    ptr->back=NULL;
    ptr->size=k;
    ptr->count=0;
    return ptr;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    
    if(obj->count==obj->size) //full
        return false;

    Node *ptr=(Node *)malloc(sizeof(Node));
    ptr->val=value;
    ptr->next=NULL;

    if(!obj->front) //empty
    {
        obj->front=ptr;
        obj->back=ptr;
        obj->count=obj->count+1; //等同obj->count++
    }
    else
    {
        obj->back->next=ptr;
        obj->back=ptr;
        obj->count=obj->count+1;
    }
    return true;   
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {

    if(obj->count==0) //empty
        return false;

    Node *ptr=obj->front;
    if(obj->front==obj->back) //剩一個
        obj->back=NULL;
    obj->front=obj->front->next;
    obj->count--;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    
    return obj->front?obj->front->val:-1;
}

int myCircularQueueRear(MyCircularQueue* obj) {

    return obj->back?obj->back->val:-1;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    if(!obj->count)
        return true;
    else
        return false;
    
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {

    if(obj->count==obj->size)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {

    while(obj->front)
        myCircularQueueDeQueue(obj);
    free(obj);
}



