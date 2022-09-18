int countnode(struct TreeNode *root)
{
    if(!root)
        return 0;
    else
        return 1+countnode(root->left)+countnode(root->right);
}

void inordertraverse(struct TreeNode *root,int *count,int *store)
{
    if(!root)
        return;
    else
    {
        inordertraverse(root->left,count,store);
        store[*count]=root->val;
        (*count)++;
        inordertraverse(root->right,count,store);
    }
}

bool isValidBST(struct TreeNode* root){
    
    int size=countnode(root);
    int *store=(int *)malloc(sizeof(int)*size);
    int count=0;
    inordertraverse(root,&count,store);
    
    for(int i=0;i<size-1;++i)
    {
        if(store[i]>=store[i+1])
        {
            free(store);
            return false;
        }
    }
    free(store);
    return true;
}
