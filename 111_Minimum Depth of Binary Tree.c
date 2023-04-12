//法1: DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root){
    if(!root)
        return 0;
    int store1=minDepth(root->left);   //left subtree min height
    int store2=minDepth(root->right);  //right subtree min height
    if(!(root->left)) //no left sub, so only path is right sub
        return store2+1;
    else if(!(root->right))
        return store1+1;
    else
        return (store1<store2)?store1+1:store2+1; //get smaller
}




//法2: BFS

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

int minDepth(struct TreeNode* root){
    if(!root)
        return 0;

    struct node q[100000]; 
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

            if(!ptr->left&&!ptr->right) //到最底了
                return height;

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
