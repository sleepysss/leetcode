/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//iterative
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    struct ListNode *head=NULL, *ptr1, *ptr2, *store,* store2; //store:the node to be add;store2:traverse ne linked list
    int val1,val2;
    
    
    if(!list1&&!list2)
    {
        return NULL;
    }
    
    ptr1=list1;
    ptr2=list2;
    
    while(ptr1&&ptr2)
    {
        
        //choose smaller val and add to linked list
        if(ptr1->val<=ptr2->val) //val smaller
        {
            store=ptr1;
            ptr1=ptr1->next;
        }
        else if(ptr2->val<ptr1->val)  
        {
            store=ptr2;
            ptr2=ptr2->next;
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
    
    //condition:(1) list1 traverse to null (2) list2 traverse to null (3) list1 and list2 traverse to null
    if(!head)
        return ptr1?ptr1:ptr2;
    
    store2->next=ptr1?ptr1:ptr2;
    
    return head;    
}



//recursive
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    if(list1->val<list2->val)
    {
        list1->next=mergeTwoLists(list1->next,list2);
        return list1;
    }
    else
    {
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;   
    }
    
}





