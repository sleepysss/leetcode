/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//iterative

//method1  (not good)
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *store1=head,* store2, *store3;       //ex:if store1=node1 then store2 will be node 2 and store3 will be node 3
    
    if(!head)
        return head;
    store2=head->next;
    while(store2)
    {
        store3=store2->next;
        store2->next=store1;  //ex: 1<-2
        store1=store2;
        store2=store3;    
    }
    head->next=NULL; //last one point to null
    return store1; 
}

//method2
struct ListNode* reverseList(struct ListNode* head){
    
    struct ListNode *current=head, *back=NULL, *front=NULL;
    
    // if 1 is current then 2 is front , NULL is back
    //        1 ->  2 -> NULL
    // NULL<- 1 <- 2
    //雨刷的概念,本來->變<-,每個node當作雨刷的中心
    
    while(current)
    {
        front=current->next;  //get next node
        current->next=back;   //change current's -> to <-
        back=current;         //move on to 'next round' 
        current=front;
    }
    return back;
}


//recursive
struct ListNode* reverseList(struct ListNode* head){
       
    //original linked list can be combine by sub linked list 1 and 2-> 3->4 
    //      black box
    // 1 -> 2 -> 3 -> 4
    // if black box (sub linked list) finished reverse, it will get  NULL <- 2 <- 3 <- 4
    // so what we need to do now (for a single node ie:1) is 
    // 1. 1 -> next -> next == 1 itself (1->next is 2 and our target is reverse)
    // 2. 1 -> next == NULL 
    //then (sub) linked list 1->blackbox finish reverse  ie: NULL <- 1 <- 2 <- 3 <- 4  (black box + single node finished reverse)
    
    //|base|
    
    if(head==NULL)
        return NULL;
    if(head->next==NULL)  //single node does not need to do anything
        return head;
    
    //|general|
    
    struct ListNode *store=reverseList(head->next);  //sub linked list do reverse and return the reversed list's head 
    //single node do reverse
    head->next->next=head;  
    head->next=NULL;
    
    return store;  //store is finished reverse's linked list 's head  ie:5
}

