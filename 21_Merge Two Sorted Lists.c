/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    struct ListNode *head=NULL, *ptr1, *ptr2, *store,* store2; //store:the node to be add;store2:traverse ne linked list
    int val1,val2;
    
    
    if(!list1&&!list2)
    {
        return NULL;
    }
    
    ptr1=list1;
    ptr2=list2;
    
    while(ptr1||ptr2)
    {
        val1=ptr1?ptr1->val:-101;  //-101 means NULL
        val2=ptr2?ptr2->val:-101;
        
        //choose smaller val and add to linked list
        if(val1<=val2&&val1!=-101) //val smaller and qualified
        {
            store=ptr1;
            ptr1=ptr1->next;
        }
        else if(val2<val1&&val2!=-101)  
        {
            store=ptr2;
            ptr2=ptr2->next;
        }
        else if(val1!=-101) //val2 not qualified,which means there is nothing on ptr2
        {
            if(!head)
                return ptr1;
            
            store2->next=ptr1;
            return head;
        }
        else if(val2!=-101)
        {
            if(!head)
                return ptr2;
         
            store2->next=ptr2;
            return head;
        }
        
        if(!head)
        {
            head=store;
            store2=head;
            continue;
        }
        store2->next=store;  
        store2=store2->next;
    }
        
    return head;    

}
