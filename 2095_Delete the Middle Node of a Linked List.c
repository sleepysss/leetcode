/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {

    if(head->next==NULL) //only one
        return NULL;

    struct ListNode *fast=head, *slow=head, *slow_pre;

    while(fast&&fast->next)
    {
        slow_pre=slow; //上一次的slow
        slow=slow->next;
        fast=fast->next->next;
    }
    slow_pre->next=slow->next;
    free(slow);
    return head;
}
