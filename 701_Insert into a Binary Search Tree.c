struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    
    if(!root)
    {
        struct TreeNode *ptr=(struct TreeNode *)malloc(sizeof(struct TreeNode));
        ptr->left=NULL;
        ptr->right=NULL;
        ptr->val=val;
        return ptr;
    }
    else
    {
        if(root->val>val)
            root->left=insertIntoBST(root->left,val);
        else
            root->right=insertIntoBST(root->right,val);
    }
    return root;
}
