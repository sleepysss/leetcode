//method 1: naive inordertraverse
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

// method 2 改良版的inorder traverse
//在In-order的狀況下，
//對於二元搜尋樹可以得到一個由小到大的順序，所以只要記住上一個節點，每次去比較上一個節點和現在走到的節點，
//當現在的節點跟上一個節點相比較小或相等時，表示這不是二元搜尋樹(因為越後面的節點必須較大才行)；
//反之，當每個節點都走完沒有錯誤時，這時候就可以確認這個二元樹是二元搜尋樹了。


//當tree為valid時下面函數會返回true,當tree非valid時下面函數會返回false 
bool inordertraverse(struct TreeNode *root,struct TreeNode **last) //last:isValidBST function中的last的位址
{
    if(!root)
        return true;
    else
    {
        if(!inordertraverse(root->left,last)) //看左子樹合不合格
            return false;
        if(!(*last)) //empty
            *last=root;
        else
        {
            if((*last)->val>=root->val) //前面比後面大
                return false;
            *last=root;
        }
        if(!inordertraverse(root->right,last))
            return false;
    }
    return true;
}

bool isValidBST(struct TreeNode* root){
    
    struct TreeNode *last=NULL; //存上一個走到的節點的位址
    return inordertraverse(root,&last);
    
}

//method 3: using BST def

bool traverse_smaller(struct TreeNode *root,int val) //see if every node in tree is smaller than val
{
    if(!root)
        return true;
    else
    {
        if(root->val>=val)
            return false;
        return traverse_smaller(root->left,val)&&traverse_smaller(root->right,val);
    }
}


bool traverse_bigger(struct TreeNode *root,int val)
{
    if(!root)
        return true;
    else
    {
        if(root->val<=val)
            return false;
        return traverse_bigger(root->left,val)&&traverse_bigger(root->right,val);
    }
}

bool isValidBST(struct TreeNode* root){
    
    if(!root)
        return true;
    else
    {
        if(!(traverse_smaller(root->left,root->val)&&traverse_bigger(root->right,root->val)))   //BST def
            return false;
        else
            return isValidBST(root->left)&&isValidBST(root->right); //traverse every node
    }
}




//c++ ver

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inorder(TreeNode* root, vector<int> &store)
    {
        if(!root)
            return;
        else
        {
            inorder(root->left,store);
            store.push_back(root->val);
            inorder(root->right,store);
        }
    }

    bool isValidBST(TreeNode* root) {
        vector<int> store;
        inorder(root,store);
        for(int i=0;i<store.size()-1;++i)
        {
            if(store[i]>=store[i+1])
                return false;
        }
        return true;
    }
};

