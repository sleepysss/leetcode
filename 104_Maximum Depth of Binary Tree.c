//法1 DFS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//equal height of binary tree

int maxDepth(struct TreeNode* root){
    if(!root)
        return 0;
    else
    {
        int store1=maxDepth(root->left);
        int store2=maxDepth(root->right);
        return store1>store2?1+store1:1+store2;
    }
}


//法2 BFS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct node
{
    int val;
    struct TreeNode *ptr;
};

int maxDepth(struct TreeNode* root){

    if(!root)
        return 0;

    struct node q[10000]; 
    int front=0,rear=0;
    int node_count; //number of nodes in a level
    int height=0;   //height=maximum depth
    struct TreeNode *ptr;     
    q[0].val=root->val;
    q[0].ptr=root;

    while(front!=-1&&front<=rear) //queue not empty
    {
        height++;
        node_count=rear-front+1; //這層node的數量為queue內元素的數量

        while(node_count--)  //traverse這輪(因為我們知道這輪有幾個)
        {
            ptr=q[front].ptr;

            if(ptr->left)  //add member to queue
            {
                q[++rear].val=ptr->left->val;
                q[rear].ptr=ptr->left;
            }
            if(ptr->right)
            {
                q[++rear].val=ptr->right->val;
                q[rear].ptr=ptr->right;
            }

            front++; //走訪過的pop掉
        }
    }
    return height;
}
