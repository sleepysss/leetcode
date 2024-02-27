struct ListNode *detectCycle(struct ListNode *head) {

    struct ListNode *slow=head, *fast=head;

    while(slow&&fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
