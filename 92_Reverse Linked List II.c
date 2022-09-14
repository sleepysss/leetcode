/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *reverse_list(struct ListNode *head)
{
    struct ListNode *curr=head, *back=NULL, *front;
    while(curr)
    {
        front=curr->next;
        curr->next=back;
        back=curr;
        curr=front;
    }
    return back;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    
    struct ListNode dummy;
    dummy.next=head;
    int count=0;
    struct ListNode *ptr=&dummy, *left_nearby, *right_nearby, *reverse;
    
    while(ptr)
    {
        if(count==left-1)
            left_nearby=ptr;
        if(count==right)
        {
            right_nearby=ptr->next;
            ptr->next=NULL;
        } 
        count++;
        ptr=ptr->next;
    }
    reverse=reverse_list(left_nearby->next);
    left_nearby->next->next=right_nearby;
    left_nearby->next=reverse;
    return dummy.next;

}
