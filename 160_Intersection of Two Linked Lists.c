/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    struct ListNode *store1=headA, *store2=headB;
    int lengthA=0,lengthB=0;
    
    while(store1)
    {
        lengthA++;
        store1=store1->next;
    }
    while(store2)
    {
        lengthB++;
        store2=store2->next;
    }
    store1=headA;
    store2=headB;
    
    //因為長度不同,所以用類似偷跑的概念,比別人多幾個,就偷跑幾個
    if(lengthA>lengthB)
        for(int i=lengthA-lengthB;i>0;--i)
            store1=store1->next;
    else
        for(int i=lengthB-lengthA;i>0;--i)
            store2=store2->next;
    
    //find intersection
    while(store1)
    {
        if(store1==store2)
            return store1;
        store1=store1->next;
        store2=store2->next;
    }
    
    return NULL;
    
}
