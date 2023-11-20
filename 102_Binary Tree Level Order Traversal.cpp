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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans; //最終的ans
        if(!root)
            return ans;
        queue<TreeNode*> q; //BFS要maintain的queue
        q.push(root);
        //每次都要紀錄最右邊的節點，而最右邊的節點則是，
        //當目前的節點已經是之前紀錄最右邊的節點時，
        //queue 最後面的就是下個最右邊的節點。
        TreeNode *rightmost = root;
        vector<int> temp; //存這一層的值
        while(!q.empty())
        {
            TreeNode* current=q.front();
            temp.push_back(current->val);
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
            if(current==rightmost)
            {
                ans.push_back(temp);
                temp.clear();
                rightmost = q.back(); //更新
            }
            q.pop();
        }
        return ans;
    }
};
