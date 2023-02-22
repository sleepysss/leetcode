//method 1 : 記pre

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



//method 2 : 刪下一個

struct ListNode* deleteDuplicates(struct ListNode* head){

    if(!head)
        return NULL;

    struct ListNode *ptr=head;
    int val=head->val;
    while(ptr&&ptr->next)
    {
        if(ptr->next->val!=val)
        {
            val=ptr->next->val;
            ptr=ptr->next;
        }
        else
            ptr->next=ptr->next->next;
    }
    return head;
}


