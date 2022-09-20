/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

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
    //題目因此可以變成『給一個排序好的序列，裡面恰好有兩個數字被交換，找出原本的序列』
    //case1:交換的數字是相鄰的:會有一組當前比後面大的
    //case2:交換的數字是不相鄰的:代表會有兩組當前比後面大的,第一組取當前,第二組取當前的下一個
    //1 2 3 4 5 6 7 8 9  3,7互換
    //1 2 7 4 5 6 3 8 9 的7,4 6,3
    //1 2 3 4 5 6 7 8 9  3,4互換
    //1 2 4 3 5 6 7 8 9 的4,3

    for(int i=0;i<count_node-1;++i)
    {
        if(store[i]->val > store[i+1]->val)
        {
            if(!first)
            {
                first=store[i];
                second=store[i+1]; //考慮到交換的數字是相鄰的case
            }
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
