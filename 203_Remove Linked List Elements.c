/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    
    struct ListNode dummy;
    struct ListNode *delnode=&dummy, *prenode;
    
    dummy.next=head;
    
    while(delnode)
    {
        if(delnode->val==val&&delnode!=&dummy)
        {
            prenode->next=delnode->next;
            free(delnode);
            delnode=prenode->next;
            continue;
        }
        prenode=delnode;
        delnode=delnode->next;
    }
    
    return dummy.next;
}
