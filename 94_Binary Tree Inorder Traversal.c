/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int CountNode(struct TreeNode *root)
{
    if(!root)
        return 0;
    else
        return 1+CountNode(root->left)+CountNode(root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    
    int countnode=CountNode(root); //count the amount of node
    
    struct TreeNode *STACK[100]; //stack內不能只存數字,還要存tree的相關資訊,所以用struct TreeNode * 而非int
    int *store=(int *)malloc(sizeof(int)*countnode);
    int count=0,top=-1;
    struct TreeNode *p;
    
    if(!root)  //empty tree
    {
        *returnSize=0;
        return store;
    }
    
    STACK[++top]=root;
    p=root->left;
    while(top!=-1||p)
    {
        while(p)
        {
            STACK[++top]=p;
            p=p->left;
        }
        struct TreeNode *ptr=STACK[top];
        store[count++]=ptr->val;  //put the val in array
        top--;
        p=ptr->right;
    }
    *returnSize=countnode;
    return store;
}
