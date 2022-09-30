bool isPalindrome(struct ListNode* head){
    
    int count=0;
    struct ListNode *ptr=head, *start;
    
    //count num
    while(ptr)
    {
        count++;
        ptr=ptr->next;
    }
    
    if(count==1)
        return true;
    
    //cut
    ptr=head;
    for(int i=0;i<(count/2)-1;++i)
        ptr=ptr->next;
    if(!(count%2)) //even num of nodes  1->2->2->1 (ptr will be first 2,start get second 2)
        start=ptr->next;
    else  //odd num of nodes  1->3->5->3->1 (ptr will be first 3,start get second 3)
        start=ptr->next->next;
    ptr->next=NULL;
    
    //reverse first part of the list
    
    head=reverselist(head);
    
    //traverse&compare
    while(head)
    {
        if(head->val!=start->val)
            return false;
        
        head=head->next;
        start=start->next;
    }
    
    return true; //all nums are the same
}
