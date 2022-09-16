/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *build(int *preorder,int *inorder,int pre_start,int pre_end,int in_start,int in_end)
{
    if(pre_start>pre_end||in_start>in_end)
        return NULL;
    
    struct TreeNode *ptr=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    ptr->val=preorder[pre_start];
    ptr->left=NULL;
    ptr->right=NULL;
    if(pre_start==pre_end)
        return ptr;
    int count=0;
    for(int i=in_start;i<=in_end;++i)
    {
        if(inorder[i]==preorder[pre_start])
            break;
        count++;
    }
    ptr->left=build(preorder,inorder,pre_start+1,pre_start+count,in_start,in_start+count-1);
    ptr->right=build(preorder,inorder,pre_start+1+count,pre_end,in_start+count+1,in_end);
    
    return ptr;
}



struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    
    return build(preorder,inorder,0,preorderSize-1,0,inorderSize-1);
}
