//unfinished!!!!!!!!!!!!!!!!!!!!!!!

int countnode(struct TreeNode *root)
{
    if(!root)
        return NULL;
    else
        return 1+countnode(root->left)+countnode(root->right);
}

void inorder(struct TreeNode *root,int *count,struct TreeNode **store)
{
    if(!root)
        return;
    else
    {
        inorder(root->left,count,store);
        store[*count]=root;
        (*count)++;
        inorder(root->right,count,store);
    }
    
}


void recoverTree(struct TreeNode* root){
    
    int count_node=countnode(root);
    struct TreeNode **store=(struct TreeNode **)malloc(sizeof(struct TreeNode *)*count_node);    
    int count=0;
    inorder(root,&count,store);
    struct TreeNode *first=NULL, *second=NULL;
    
    //find two error node
    for(int i=0;i<count_node-1;++i)
    {
        if(store[i]->val > store[i+1]->val)
        {
            if(!first)
                first=store[i];
            else
            {
                second=store[i+1];
                break;
            }
        }
    }
    
    //recover
    int temp=first->val;
    first->val=second->val;
    second->val=temp;
    
    return root;
}
