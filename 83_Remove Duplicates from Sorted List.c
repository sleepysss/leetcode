struct ListNode* deleteDuplicates(struct ListNode* head){
    
    if(!head)
        return NULL;

    struct ListNode *ptr=head->next, *pre=head;
    
    while(ptr)
    {
        if(ptr->val==pre->val)
        {
            pre->next=ptr->next;
            free(ptr);
            ptr=pre;
        }
        pre=ptr;
        ptr=ptr->next;
    }
    
    return head;
}
