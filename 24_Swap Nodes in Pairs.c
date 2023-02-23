/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//method1:iterative(有註解版)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){

    while(!head||!head->next)
        return head;
    struct ListNode dummy;
    dummy.next=head;

    //curr:上一輪接到這輪的first的那個節點
    //first:此輪第一個數
    //second:此輪第二個數
    //ex: 1-2-3-4-5-6
    //    目前：2-1-3-4-5-6 此輪轉3-4
    //    curr為1 first為3 second為4
    //    轉法：
    //    (1)3接到5(一定要比4接到3還先,因為4接到3會改變4的next)
    //    (2)4接到3   
    //    (3)1接到4
    //    (4)curr設為first,繼續下一輪

    //while內的條件：因為迴圈內會用到second->next和first->next,所以是卡
    //             curr->next&&curr->next->next這兩個

    struct ListNode *curr=&dummy, *first, *second;
    while(curr->next&&curr->next->next) 
    {
        first=curr->next;
        second=curr->next->next;
        first->next=second->next;
        second->next=first;
        curr->next=second;
        curr=first;
    }
    return dummy.next;
}


//method1:iterative

//重點:一組一組慢慢調,不要想一次調完全部
//即:dummy->1->2->3->4 變 dummy->2->1->3->4 再變 dummy->2->1->4->3


struct ListNode* swapPairs(struct ListNode* head){
    
    struct ListNode dummy; //幫助用(因為後面節點會移來移去)
    dummy.next=head;
    struct ListNode *res=&dummy,* Next,* tmp;
    
    
    while(head&&head->next)
    {
        Next=head->next;
        tmp=head->next->next;
        res->next=Next;
        Next->next=head;
        head->next=tmp;
        res=head;
        head=tmp;
    }
    return dummy.next;

}

//method2:recursive

struct ListNode* swapPairs(struct ListNode* head){
    
    if(!head||!(head->next))
        return head;
    
    struct ListNode *sec=head->next;
    head->next=swapPairs(sec->next);
    sec->next=head;
    
    return sec;
}
