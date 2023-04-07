/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int find_smallest(struct TreeNode *root)
{
    while(root->left)
        root=root->left;
    return root->val;
}

/*

find_smallest的另一種寫法

int findsmallest(struct TreeNode *root)
{
    int val=root->val;
    while(root->left)
    {
        val=root->left->val;
        root=root->left;
    }
    return val;
}


*/


struct TreeNode* deleteNode(struct TreeNode* root, int key){
    
    if(!root)
        return NULL;
    else if(root->val==key)
    {
        if(root->left&&root->right)
        {
            int smallest_in_right_subtree=find_smallest(root->right);
            root->val=smallest_in_right_subtree; //替換
            root->right=deleteNode(root->right,smallest_in_right_subtree); //刪掉替換的那個node
        }
        else
        {
            struct TreeNode *ptr1=root->left;
            struct TreeNode *ptr2=root->right;
            free(root);
            return ptr1?ptr1:ptr2; //return the root node reference of the BST
        }
        
        
    }
    else if(root->val>key)
        root->left=deleteNode(root->left,key); //deleteNode will return the (possibly update) root node reference of the BST(left-sub tree's root)
    else
        root->right=deleteNode(root->right,key);
    
    return root; //return the root node reference of the BST

}
