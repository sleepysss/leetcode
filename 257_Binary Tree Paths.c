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
