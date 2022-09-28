struct ListNode* deleteDuplicates(struct ListNode* head){
    
    if(!head)
        return NULL;
    
    int num=head->val;
    struct ListNode *ptr=head->next, *pre=head;
    
    while(ptr)
    {
        if(ptr->val==num)
        {
            pre->next=ptr->next;
            free(ptr);
            ptr=pre;
        }
        num=ptr->val;
        pre=ptr;
        ptr=ptr->next;
    }
    
    return head;
}
