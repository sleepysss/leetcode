/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//iterative

//method1
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
//核心想法:把後面的當作已經做完ㄌ,只要改自己在的這個就好(讓整個由->變成<-)  ex:  2 -> |已經完成的部分|   改成  NULL <- 2 <- |已經完成的部分|
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* store;
    if(!head||!head->next)
        return head;
    
    store=reverseList(head->next); //已經完成的部分的頭
    head->next->next=head;  // 2 <- |已經完成的部分|
    head->next=NULL;  // NULL <- 2
    return store; //因為reverseList傳的是已經被反過來的list的head
}

