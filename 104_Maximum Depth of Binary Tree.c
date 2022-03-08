/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(!root)
        return 0;
    int leftdepth=maxDepth(root->left); //calculate left subtree maxdepth
    int rightdepth=maxDepth(root->right);
    if(leftdepth>rightdepth) //choose longer
        return leftdepth+1;
    else
        return rightdepth+1;

}
