/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* oddEvenList(struct ListNode* head){
    
    if(!head||!head->next)
        return head;
    
    struct ListNode *odd=head, *even=head->next, *even_head=head->next;
    
    //偶數個的情況到最後面odd為NULL,even為NULL
    //奇數個的情況到最後面odd非NULL,even為NULL
    //所以條件設為even&&even->next
    while(even&&even->next)
    {
        odd->next=even->next; //改成指向原本下個節點的下一個節點
        even->next=even->next->next; //改成指向原本下個節點的下一個節點
        odd=odd->next;  //next round
        even=even->next;
    }
    odd->next=even_head; //link
    
    return head;
    
}
