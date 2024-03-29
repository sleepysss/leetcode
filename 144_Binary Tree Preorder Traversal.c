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

void preorder(struct TreeNode *root,int store[],int *count_ptr)
{
    if(!root)
        return;
    else
    {
        store[*count_ptr]=root->val;
        *count_ptr=*count_ptr+1;
        preorder(root->left,store,count_ptr);
        preorder(root->right,store,count_ptr);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
        
    int countnode=CountNode(root); //count the amount of node
    
   
    int *store=(int *)malloc(sizeof(int)*countnode);
    int count=0;
   
    preorder(root,store,&count);
    
    *returnSize=countnode;
    return store;
}




//c++ ver

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> store;
        pre(root,store);
        return store;
    }

    void pre(TreeNode* root,vector<int> &store)
    {
        if(!root)
            return;
        else
        {
            store.push_back(root->val);
            pre(root->left,store);
            pre(root->right,store);
        }
    }
};
