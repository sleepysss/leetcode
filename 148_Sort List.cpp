//method 1

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
    ListNode* sortList(ListNode* head) {
        
        vector<int> v;
        ListNode *ptr=head;
        while(ptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        sort(v.begin(),v.end());

        ListNode dummy;
        ptr=&dummy;
        for(int i=0;i<v.size();++i)
        {
            ptr->next=new ListNode(v[i]);
            ptr=ptr->next;
        }
        return dummy.next;
    }
};


//method 2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *merge_sortedlist_ascending(struct ListNode *ptr1,struct ListNode *ptr2)
{
    struct ListNode dummy;
    struct ListNode *ptr=&dummy;

    while(ptr1&&ptr2)
    {
        if(ptr1->val<ptr2->val)
        {
            ptr->next=ptr1;
            ptr1=ptr1->next;
            ptr=ptr->next;
        }
        else
        {
            ptr->next=ptr2;
            ptr2=ptr2->next;
            ptr=ptr->next;
        }
    }
    if(ptr1)
        ptr->next=ptr1;
    else
        ptr->next=ptr2;

    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {

    //解題原理: merge sort

    if(!head||!head->next)
        return head;
    
    //find mid (leetcode 876)

    struct ListNode *ptr1=head, *ptr2=head, *ptr3;

    while(ptr2&&ptr2->next)
    {
        ptr3=ptr1;
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }
    ptr3->next=NULL;
    // 現在list被分成兩個了 head~ptr3 ptr1~最後

    ptr2=sortList(head); //左邊做sorting (不要用ptr1接收,因為下面會用到)
    ptr3=sortList(ptr1); //右邊做sorting

    return merge_sortedlist_ascending(ptr2,ptr3); //合併  (leetcode 21)
}
