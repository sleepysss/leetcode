/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//equal height of binary tree

int maxDepth(struct TreeNode* root){
    if(!root)
        return 0;
    else
    {
        int store1=maxDepth(root->left);
        int store2=maxDepth(root->right);
        return store1>store2?1+store1:1+store2;
    }
}
