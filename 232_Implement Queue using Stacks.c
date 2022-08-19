typedef struct {
    int st1[100];
    int st2[100];
    int st1_top;
    int st2_top;
    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *ptr=(MyQueue *)malloc(sizeof(MyQueue));
    ptr->st1_top=-1;
    ptr->st2_top=-1;
    return ptr;
}

void myQueuePush(MyQueue* obj, int x) {
    
    obj->st1_top++;
    obj->st1[obj->st1_top]=x;
}

void move_st1_to_st2(MyQueue *obj)
{
    while(obj->st1_top!=-1)
    {
        obj->st2_top++;
        obj->st2[obj->st2_top]=obj->st1[obj->st1_top];
        obj->st1_top--;
    }
}


int myQueuePop(MyQueue* obj) {
    if(obj->st2_top==-1)
        move_st1_to_st2(obj);
    return obj->st2[obj->st2_top--];
}

int myQueuePeek(MyQueue* obj) {
    if(obj->st2_top==-1)
        move_st1_to_st2(obj);
    return obj->st2[obj->st2_top];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->st1_top==-1&&obj->st2_top==-1?true:false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
