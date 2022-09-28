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
            ptr->next=NULL; //4->3 => 4->NULL
            ptr=pre;
            greater=greater->next;
            
        }
        pre=ptr;
        ptr=ptr->next;    
    }
    pre->next=dummy2.next;
    return dummy1.next;
    
}
