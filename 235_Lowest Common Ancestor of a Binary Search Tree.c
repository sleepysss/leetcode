/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//method1:

bool findptr(struct TreeNode *root,struct TreeNode *ptr)
{
    if(!root)
        return false;
    else
    {
        if(root==ptr)
            return true;
        else if(root->val>ptr->val)
            return findptr(root->left,ptr);
        else
            return findptr(root->right,ptr);
    }
}


struct TreeNode *store=NULL;

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    if(!root)
        return NULL;
    if(findptr(root,p)&&findptr(root,q)) //is ancestor or not
    {
        store=root; //update
        
        if(root->val>=p->val&&root->val>=q->val) //LCA may in left sub
            lowestCommonAncestor(root->left,p,q);
        else if(root->val<=p->val&&root->val<=q->val)
            lowestCommonAncestor(root->right,p,q);
        else
            return root; //root is the LCA
    }
    return store;
}

//method2

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    if(!root)
        return NULL;
    else
    {
        if(root->val>p->val&&root->val>q->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(root->val<p->val&&root->val<q->val)
            return lowestCommonAncestor(root->right,p,q);
        else  //ex1,ex2
            return root;
    }
}
