//method 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode *head=NULL, *ptr, *store;   //store:pre-node's address
    int num1,num2,count=0;
    
    //be careful of nothing in l1,nothing in l2,but still something in count(carry)
    while(l1||l2||count)
    {
        ptr=(struct ListNode *)malloc(sizeof(struct ListNode));
        num1=l1?l1->val:0;
        num2=l2?l2->val:0;
        ptr->val=(num1+num2+count)%10;
        count=(num1+num2+count)/10;
        ptr->next=NULL;
        if(!head)
            head=ptr;
        else
            store->next=ptr;
        store=ptr;
        if(l1)
            l1=l1->next;
        if(l2)
            l2=l2->next;
    }
    return head;
}

//method 2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    //general:link to l1
    //except 1.l1 first end ---> link to l2
    //except 2.l2 first end ---> link to l1
    // be careful of carry
    
    
    int carry=0,sum,x,y;
    struct ListNode dummy;
    struct ListNode *ptr=&dummy, *carry_ptr;
    
    while(l1||l2||carry)
    {
        x=l1?l1->val:0;
        y=l2?l2->val:0;
        sum=x+y+carry;
        
        if(!l1&&!l2&&carry)
        {
            carry_ptr=(struct ListNode *)malloc(sizeof(struct ListNode));
            carry_ptr->next=NULL;
            ptr->next=carry_ptr;
        }
        else if(!l1)
        {
            ptr->next=l2;
            l2=l2->next;

        }
        else if(!l2)
        {
            ptr->next=l1;
            l1=l1->next;
        }
        else
        {
            ptr->next=l1;
            l1=l1->next;
            l2=l2->next;
        }
        ptr=ptr->next;
        ptr->val=sum%10;
        carry=sum/10;
    }
    return dummy.next;
    
}



//method 3 

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int x=0,sum;
    struct ListNode dummy;
    struct ListNode *ptr=&dummy;

    while(l1||l2||x)
    {
        ptr->next=
        (struct ListNode *)malloc(sizeof(struct ListNode));
        ptr=ptr->next;
        sum=x;
        if(l1)
        {
            sum+=l1->val;
            l1=l1->next;
        } 
        if(l2)
        {
            sum+=l2->val;
            l2=l2->next;
        } 
        x=sum/10;
        sum%=10;
        ptr->val=sum;
        ptr->next=NULL;

    }
     return dummy.next;
}


