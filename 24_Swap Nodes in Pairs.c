/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//method1:iterative

//重點:一組一組慢慢調,不要想一次調完全部
//即:dummy->1->2->3->4 變 dummy->2->1->3->4 再變 dummy->2->1->4->3


struct ListNode* swapPairs(struct ListNode* head){
    
    struct ListNode dummy; //幫助用(因為後面節點會移來移去)
    dummy.next=head;
    struct ListNode *res=&dummy,* Next,* tmp;
    
    
    while(head&&head->next)
    {
        Next=head->next;
        tmp=head->next->next;
        res->next=Next;
        Next->next=head;
        head->next=tmp;
        res=head;
        head=tmp;
    }
    return dummy.next;

}

//method2:recursive

struct ListNode* swapPairs(struct ListNode* head){
    
    if(!head||!(head->next))
        return head;
    
    struct ListNode *sec=head->next;
    head->next=swapPairs(sec->next);
    sec->next=head;
    
    return sec;
}
