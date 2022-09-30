//method1:decomposition

struct ListNode *reverselist(struct ListNode *head)
{
    struct ListNode *curr=head, *pre=NULL, *next;
    
    while(curr)
    {
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    return pre;
}

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

//method1:改良
//1.用fast,slow pointer找start 2.翻轉後半部(這樣就不用cut了)

struct ListNode *reverselist(struct ListNode *head)
{
    struct ListNode *curr=head, *pre=NULL, *next;
    
    while(curr)
    {
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    return pre;
}

struct ListNode *getfirst(struct ListNode *head)
{
    struct ListNode *fast=head, *slow=head;
    
    while(1)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(!fast)
            return slow;
        if(!(fast->next))
            return slow->next;
    }
}

bool isPalindrome(struct ListNode* head){
    
    if(!(head->next))
        return true;
    
    //get head of the second part list
    struct ListNode *start=getfirst(head);
    
    //reverse second part of the list
    
    start=reverselist(start);
    
    //traverse&compare
    while(start)
    {
        if(head->val!=start->val)
            return false;
        
        head=head->next;
        start=start->next;
    }
    
    return true; //all nums are the same
}

//method2:stack

bool isPalindrome(struct ListNode* head){
    
    int count=0,store[50000],x=-1;
    struct ListNode *ptr=head, *start;
    
    if(!(head->next))
        return true;
    
    //count num
    while(ptr)
    {
        count++;
        ptr=ptr->next;
    }
    
    ptr=head;
    for(int i=0;i<=(count/2)-1;++i)
    {
        store[++x]=ptr->val;
        ptr=ptr->next;
    }
    if(count%2)
        ptr=ptr->next;
    
    while(ptr)
    {
        if(store[x]!=ptr->val)
            return false;
        ptr=ptr->next;
        x--;
    }
    return true; 
}

