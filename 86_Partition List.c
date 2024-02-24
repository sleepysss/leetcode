//method 1
struct ListNode* partition(struct ListNode* head, int x){
    
    if(!head||!(head->next))
        return head;
    
    struct ListNode dummy1,dummy2; //dummy1:original list,dummy2:greater than or equal to x's list
    struct ListNode *ptr=head, *pre=&dummy1, *greater=&dummy2;
    dummy1.next=ptr;
    dummy2.next=NULL;
    while(ptr) //traverse 
    {
        if(ptr->val>=x)  //greater than or equal to x
        {
            greater->next=ptr;
            pre->next=ptr->next; //1->3
            ptr->next=NULL; //4->3 => 4->NULL (no this step,it will be a cycle)
            ptr=pre;
            greater=greater->next;
            
        }
        pre=ptr;
        ptr=ptr->next;    
    }
    pre->next=dummy2.next;
    return dummy1.next;
    
}


//method 2

struct ListNode* partition(struct ListNode* head, int x) {

    struct ListNode dummy;
    dummy.next=head;

    struct ListNode *ptr=&dummy;
    struct ListNode dummy2, *ptr2;
    dummy2.next=NULL;
    ptr2=&dummy2;

    while(ptr->next)
    {
        if(ptr->next->val>=x)
        {
            ptr2->next=ptr->next;
            ptr->next=ptr->next->next; //注意順序
            ptr2=ptr2->next;
            ptr2->next=NULL;
            continue;
        }
        ptr=ptr->next;
    }
    ptr->next=dummy2.next;
    return dummy.next;   
}
