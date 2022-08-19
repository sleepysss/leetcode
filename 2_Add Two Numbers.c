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
