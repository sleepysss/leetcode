/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void invertbinarytree(struct TreeNode * root)
{
    //先轉左右子樹,再讓左右子樹做一樣的事情
    
    if(!root)
        return;
    struct TreeNode *store;
    store=root->left;
    root->left=root->right;
    root->right=store;
    invertbinarytree(root->left);
    invertbinarytree(root->right);
}

bool isSameTree(struct TreeNode *root1,struct TreeNode *root2)
{
    //先check自己,check完後看看左右子樹符不符合
    
    if(!root1&&!root2)
        return true;
    if(!root1||!root2)
        return false;
    if(root1->val==root2->val) //自己符合
        return isSameTree(root1->left,root2->left)&&isSameTree(root1->right,root2->right);
    else
        return false; //自己不符合
    
}


bool isSymmetric(struct TreeNode* root){
    
    if(!root)
        return true;
    invertbinarytree(root->right); //翻轉右子樹(左也可),因為若要是symmetric,翻轉後要和左子樹一樣
    return isSameTree(root->left,root->right);
    
}
