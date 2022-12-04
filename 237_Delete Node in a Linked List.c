//method 1 : Delete next node instead of current one

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *temp;
    
    //because we need to know pre-node when delete,but in this question we dont know,so we use replacement method
    //ie: delete 5  ----> delete 1
    temp=node->next;
    node->val=temp->val;
    node->next=temp->next;
    free(temp);
}

//method 2 : 不太好的方法ㄏㄏ

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *pre;
        while(node->next)
        {
            pre=node;
            node->val=node->next->val;
            node=node->next;
        }
        pre->next=NULL;
    }
};
