/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct Temp
{
    int index;
    int temperature;
}Temp;


int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    
    
    int *ans=(int *)malloc(sizeof(int)*temperaturesSize);
    Temp *monotonic_stack=(Temp *)malloc(sizeof(Temp)*temperaturesSize);
    int top=-1;
    
    for(int i=temperaturesSize-1;i>=0;--i)
    {
        while(top!=-1&&temperatures[i]>=monotonic_stack[top].temperature)
            top--;
        ans[i]=top!=-1?monotonic_stack[top].index-i:0;
        top++;
        monotonic_stack[top].temperature=temperatures[i];
        monotonic_stack[top].index=i;
    }
    
    free(monotonic_stack);
    *returnSize=temperaturesSize;
    return ans;

}
