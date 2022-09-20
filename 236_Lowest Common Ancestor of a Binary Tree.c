//method 1

bool find(struct TreeNode *root,struct TreeNode *p) //see whether node p is inside the tree or not
{
    if(!root)
        return false;
    else if(root==p)
        return true;
    else
        return find(root->left,p)||find(root->right,p);
}

struct TreeNode *store;

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    if(find(root,p)&&find(root,q)) //see whether p and q is inside the tree or not
    {
        store=root;
        lowestCommonAncestor(root->left,p,q);
        lowestCommonAncestor(root->right,p,q);
    }
    
    return store;
}

//method 2

bool find(struct TreeNode *root,struct TreeNode *p) //see whether node p is inside the tree or not
{
    if(!root)
        return false;
    else if(root==p)
        return true;
    else
        return find(root->left,p)||find(root->right,p);
}

struct TreeNode *store;

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    //通過確定兩個節點的位置,然後再用recursive解決問題
  
    if(root==p) //example 1
        return p;
    if(root==q)
        return q;
    if(find(root->left,p)&&find(root->right,q)||find(root->left,q)&&find(root->right,p)) //p,q在左右子樹中
        return root;
    else if(find(root->left,p)&&find(root->left,q))  //p,q都在左子樹中
        return lowestCommonAncestor(root->left,p,q);
    else
        return lowestCommonAncestor(root->right,p,q);
}
