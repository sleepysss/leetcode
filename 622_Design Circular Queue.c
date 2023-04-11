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
