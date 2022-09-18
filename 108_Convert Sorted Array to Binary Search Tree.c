/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



struct TreeNode *sortarr2BST(int* nums,int start,int end) //convert sorted arr's index [start,end] to a height-balanced BST
{
    if(start>end)
        return NULL;
    else
    {
        //取mid當root,分開的兩串陣列再取mid當左右節點,以此類推
        int mid=start+(end-start)/2;
        struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode));;
        root->val=nums[mid];
        
        root->left=sortarr2BST(nums,start,mid-1);  //it will convert sorted arr [-10,3] to a height-balanced BST
        root->right=sortarr2BST(nums,mid+1,end);   //[5,9]
        return root;
    }
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    
    return sortarr2BST(nums,0,numsSize-1);
}
