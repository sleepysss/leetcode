/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    struct ListNode *fast=head, *slow=head;
    
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            return true;
    }
    return false;  
}



//c++ ver

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;
        while(fast && fast->next && slow)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) //碰到了
                return true;    
        }
        return false;
    }
};
