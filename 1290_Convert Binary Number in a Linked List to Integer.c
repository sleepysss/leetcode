/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//https://www.cuemath.com/numbers/binary-to-decimal/


//Positional Notation Method

int Pow(int num,int a)
{
    int store=1;
    for(int i=0;i<a;++i)
    {
        store*=num;
    }
    return store;
}

int getDecimalValue(struct ListNode* head){
    int num=0,count=0;;  //num:see how many bits are there   count:store result
    struct ListNode *store=head;
    while(store)
    {
        num++;
        store=store->next;
    }
    num--;
    store=head;
    while(store)
    {
        count+=(Pow(2,num--)*(store->val));
        store=store->next;
    }
    
    return count;
    
}


//Doubling Method

int getDecimalValue(struct ListNode* head){
    
    int total=0;
    struct ListNode *store=head;
    
    while(store)
    {
        total=total*2+store->val;  //Double the previous number and add the current digit.
        store=store->next;
    }
    return total;
}

//using bit Manipulation
int getDecimalValue(struct ListNode* head){
    
    int total=0;
    struct ListNode *store=head;
    
    while(store)
    {
        total=(total<<1)|(store->val);  //Double the previous number and add the current digit.
        store=store->next;
    }
    return total;
}

