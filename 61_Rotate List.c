/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {

    //想法:
    //1.可以直接移整體(ex:k=2:倒數兩個直接拔起來丟到最前面)
    //2.旋轉list長度的次數會回到原來的樣子,所以旋轉k次和旋轉k%list_size結果會一樣
    // 1 -> 2 -> 3 -> 4 -> 5   ,k=2
    // h         t    s    b

    if(!head||!head->next)
        return head;

    //先看list size

    struct ListNode *ptr=head ,*back;
    int count=0;
    while(ptr)
    {
        back=ptr; //用來找尾部node
        ptr=ptr->next;
        count++;
    }

    //抓出倒數第k%list_size個node和他的前一個node
    
    if(k%count==0) //不用旋轉(一定要這個條件)
        return head;

    struct ListNode *slow=head, *fast=head, *temp;

    for(int i=0;i<k%count;++i)
        fast=fast->next;

    while(fast)
    {
        temp=slow; //slow的前一個
        fast=fast->next;
        slow=slow->next;
    }
    temp->next=NULL;
    back->next=head;

    return slow;
}
