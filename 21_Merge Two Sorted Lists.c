/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//iterative ver1
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



//iterative ver2
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    // dummy_head -> a -> b -> dummy_tail  dummy(協助者)用來簡化"不方便",ex:a當頭還會要額外設一些東西
    struct ListNode dummy_head;
    dummy_head.val=0;
    dummy_head.next=NULL;
    
    struct ListNode *store1=list1, *store2=list2; //store1:traverse list1,store2:traverse list 2
    
    struct ListNode *current=&dummy_head;  //where am i now
    while(store1&&store2)
    {
        if(store1->val<store2->val)
        {
            current->next=store1;
            current=current->next;
            store1=store1->next;  
        }
        else
        {
            current->next=store2;
            current=current->next;
            store2=store2->next;
        }
    }
    
    current->next=store1?store1:store2;
    return dummy_head.next;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy;
        dummy.next=NULL;
        ListNode *ptr=&dummy;
        while(list1&&list2)
        {
            if(list1->val<list2->val)
            {
                ptr->next=list1;
                list1=list1->next;
            }
            else
            {
                ptr->next=list2;
                list2=list2->next;
            }
            ptr=ptr->next;
        }
        
        ptr->next = list1?list1:list2;
        
        return dummy.next;
    }
};





//recursive
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    if(!list1)
        return list2;  //merge([],[2,3])=[2,3]
    if(!list2)
        return list1;
    if(list1->val<list2->val)
    {
        list1->next=mergeTwoLists(list1->next,list2); //merge([1 3 5 7],[2 4])=1+merge([3 5 7],[2 4]))
        return list1;
    }
    else
    {
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;   
    }
    
}





