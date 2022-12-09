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
    ListNode* removeNodes(ListNode* head) {

        vector<int> v;
        stack<int> s; //maintain a monotonic stack

        ListNode *ptr=head;
        while(ptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        int next_bigger[v.size()]; //也可vector<int>v2(v.size())

        for(int i=v.size()-1;i>=0;--i)
        {
            while(!s.empty()&&v[i]>=s.top())
                s.pop();
            next_bigger[i]=s.empty()?-1:s.top();
            s.push(v[i]);
        }
        struct ListNode dummy(0,head);
        ptr=&dummy;
        int count=0;
        while(ptr)
        {
            if(ptr->next&&next_bigger[count]!=-1) //traverse到要刪的前一個並看看是否符合條件
            {
                ListNode *temp=ptr->next;
                ptr->next=ptr->next->next;
                delete temp;
                count++;
                continue; //可能連續刪,所以不用ptr=ptr->next
            }
            count++;
            ptr=ptr->next;
        }
        return dummy.next;
        
    }
};
