struct TreeNode *build(int *preorder,int *postorder,int pre_start,int pre_end,int post_start,int post_end)
{
    if(pre_start>pre_end||post_start>post_end)
        return NULL;
    
    struct TreeNode *ptr=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    ptr->val=preorder[pre_start];
    ptr->left=NULL;
    ptr->right=NULL;
    if(pre_start==pre_end)
        return ptr;
    int num=preorder[pre_start+1],count=0;
    for(int i=post_start;i<=post_end;++i)
    {
        count++;
        if(postorder[i]==num)
            break;
    }
    ptr->left=build(preorder,postorder,pre_start+1,pre_start+count,post_start,post_start+count-1);
    ptr->right=build(preorder,postorder,pre_start+1+count,pre_end,post_start+count,post_end-1);
    return ptr;
}

struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize){
    
    return build(preorder,postorder,0,preorderSize-1,0,postorderSize-1);
    
}
