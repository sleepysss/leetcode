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



//c++ ver

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next=head;
        //second:會在被刪的前一個
        ListNode *first=head, *second=&dummy;
        for(int i=0;i<n;++i)
            first=first->next;

        while(first)
        {
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        return dummy.next;
    }
};
