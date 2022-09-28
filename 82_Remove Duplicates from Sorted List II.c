struct ListNode* deleteDuplicates(struct ListNode* head){
    
    if(!head)
        return NULL;
    
    struct ListNode dummy, *ptr=head, *pre=&dummy;
    int num=101;
    dummy.next=head;
    
    while(ptr&&ptr->next)
    {
        if(ptr->next->val==ptr->val) //has duplicates
        {
            struct ListNode *ptr2=ptr->next;
            while(ptr2&&ptr2->val==ptr->val) //find how long is duplicates
                ptr2=ptr2->next;
            pre->next=ptr2; //link
            
            while(ptr!=pre->next)
            {
                ptr2=ptr;
                ptr=ptr->next;
                free(ptr2);
            }
            
            ptr=pre;
        }
        pre=ptr;
        ptr=ptr->next;
    }
    return dummy.next;
}
