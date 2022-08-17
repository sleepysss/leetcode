/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    struct ListNode dummy;
    struct ListNode *fast=&dummy, *slow=&dummy, *preslow=&dummy;
    dummy.next=head;
    
    for(int i=0;i<n-1;++i)
        fast=fast->next;
    
    while(fast->next)
    {
        fast=fast->next;
        preslow=slow;
        slow=slow->next;    
    }
    preslow->next=slow->next;
    free(slow);
    
    return dummy.next;

}
