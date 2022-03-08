/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root){
    if(!root)
        return 0;
    int store1=minDepth(root->left);   //left subtree min height
    int store2=minDepth(root->right);  //right subtree min height
    if(!(root->left)) //no left sub, so only path is right sub
        return store2+1;
    else if(!(root->right))
        return store1+1;
    else
        return (store1<store2)?store1+1:store2+1; //get smaller
}
