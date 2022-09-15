//method 1:iterative

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


int* preorderTraversal(struct TreeNode* root, int* returnSize){
        
    int countnode=CountNode(root); //count the amount of node
    
    struct TreeNode *STACK[100]; //stack內不能只存數字,還要存tree的相關資訊,所以用struct TreeNode * 而非int
    int *store=(int *)malloc(sizeof(int)*countnode);
    int count=0,top=-1;
    
    if(!root)  //empty tree
    {
        *returnSize=0;
        return store;
    }
    STACK[++top]=root; //push root to stack
    
    
    while(top!=-1)
    {
        struct TreeNode *ptr=STACK[top];
        store[count++]=ptr->val;  //put the val in array
        top--; //pop
        if(ptr->right)
        {
            STACK[++top]=ptr->right;
        }
        if(ptr->left)
        {
            STACK[++top]=ptr->left;
        }
    }
    *returnSize=countnode;
    return store;
}

//method2:recursive


