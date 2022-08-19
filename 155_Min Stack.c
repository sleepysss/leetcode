typedef struct {
    int storenum[10000];
    int storemin[1000];
    int num_top;
    int min_top;
    
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    
    MinStack *ptr=(MinStack *)malloc(sizeof(MinStack));
    ptr->num_top=-1;
    ptr->min_top=-1;
    return ptr;  
}

void minStackPush(MinStack* obj, int val) {
    if(obj->min_top==-1||obj->storemin[obj->min_top]>=val)
    {
        obj->min_top++;
        obj->storemin[obj->min_top]=val;
    }
    obj->num_top++;
    obj->storenum[obj->num_top]=val;
}

void minStackPop(MinStack* obj) {
    if(obj->num_top==-1)
        return;
    else if(obj->storenum[obj->num_top]==obj->storemin[obj->min_top])
    {
        obj->num_top--;
        obj->min_top--;
    }
    else
        obj->num_top--;
}

int minStackTop(MinStack* obj) {
    return obj->storenum[obj->num_top];
}

int minStackGetMin(MinStack* obj) {
    return obj->storemin[obj->min_top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
