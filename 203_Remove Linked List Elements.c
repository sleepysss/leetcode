//method 1 : traverse到要刪的點時才刪(需多一個prenode)

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


//method 2 : traverse 到要刪的點的前一個就刪了

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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode dummy(-1,head);
        ListNode *ptr=&dummy;
        while(ptr)
        {
            if(ptr->next&&ptr->next->val==val) //Traverse to element before the element to be deleted
            {
                ListNode *tmp=ptr->next;
                ptr->next=ptr->next->next;
                delete tmp;
            }
            else  //確定下一個不會是要刪的才移動(這裡要注意！！！,直接移的話可能會有error(ex: 1->1->1->1 刪1))
                ptr=ptr->next;
        }
        return dummy.next;
    }
};


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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode dummy;
        dummy.next=head;
        ListNode *ptr=&dummy;

        while(ptr&&ptr->next)
        {
            if(ptr->next->val==val)
                ptr->next=ptr->next->next;
            else
                ptr=ptr->next;
        }
        return dummy.next;
    }
};

