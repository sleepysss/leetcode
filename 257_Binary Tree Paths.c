void btp_helper(struct TreeNode *root,int *helper,char **store,int helper_index,int *where)
{
    char ptr[10];
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        helper[helper_index++]=root->val;
        store[(*where)]=(char *)malloc(sizeof(char)*100);
        store[(*where)][0]='\0';
        for(int i=0;i<helper_index;++i)
        {
            if(i==(helper_index-1))
                sprintf(ptr,"%d",helper[i]);  //convert int to string
            else
                sprintf(ptr,"%d->",helper[i]);
            strcat(store[(*where)],ptr); //strcat 可串接兩個字串
        }
        *where=(*where)+1;
    }

    helper[helper_index]=root->val;
    btp_helper(root->left,helper,store,helper_index+1,where); //left
    btp_helper(root->right,helper,store,helper_index+1,where); //right

}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){

    char **store=(char **)malloc(sizeof(char *)*50), **store2;
    int where=0;
    int *helper=(int *)malloc(sizeof(int)*50);

    btp_helper(root,helper,store,0,&where);
    store2=realloc(store,sizeof(char *)*where);
    *returnSize=where;
    return store2;
}



//c++ ver.

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> store;
        string temp;
        bTP(root,store,temp);
        return store;    
    }

    void bTP(TreeNode* root,vector<string> &store,string temp)
    {
        if(!root->left&&!root->right) //到leaf了
        {
            temp+=to_string(root->val);
            store.push_back(temp);
        }
        
        //選擇清單就是這兩個if
        if(root->left) //看看左子樹
        {
            //直接改在裡面就不用復原了
            bTP(root->left,store,temp+to_string(root->val)+"->"); 
        }
        if(root->right) //看看右子樹
        {
            bTP(root->right,store,temp+to_string(root->val)+"->");
        }
    }
};
