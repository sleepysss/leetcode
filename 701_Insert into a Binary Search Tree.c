//method 1: recursive
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


//method 2: iterative
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){

    struct TreeNode *ptr=(struct TreeNode *)malloc(sizeof(struct TreeNode)), *ptr2=root;
    ptr->val=val;
    ptr->right=ptr->left=NULL;

    if(!root)
        return ptr;
    while(ptr2)
    {
        if(ptr2->val>val)
        {
            if(!ptr2->left) //這樣就不用再用一個節點把新的接起來
            {
                ptr2->left=ptr;
                break; //已插入了,跳離迴圈(一定要有這個,不然一定錯)
            }
            else //繼續找插入的地方
                ptr2=ptr2->left;
        }
        else
        {
            if(!ptr2->right)
            {
                ptr2->right=ptr;
                break;
            }   
            else
                ptr2=ptr2->right;
        }
    }
    return root;
}
