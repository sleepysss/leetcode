// method 1 : brute force ... TLE

class Solution {
public:
    // compare the temp array with the arrays stored in your res array to detect a duplicate set and if duplicate continue
    bool duplicate(const vector<vector<int>> &ans,const vector<int> &tmp)
    {
        for(int i=0;i<ans.size();++i)
        {
            if(ans[i][0]==tmp[0]&&ans[i][1]==tmp[1]&&ans[i][2]==tmp[2])
                return true;
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();++i)
        {
            if(i&&nums[i]==nums[i-1])
                continue;
            else
            {
                for(int j=i+1;j<nums.size();++j)
                {
                    for(int k=j+1;k<nums.size();++k)
                    {
                        if(nums[i]+nums[j]+nums[k]==0)
                        {
                            //check duplicate
                            vector<int> tmp={nums[i],nums[j],nums[k]};
                            if(!duplicate(ans,tmp))
                                ans.push_back(tmp);   
                        }
                    }
                }
            }
            
        }
        return ans;
    }
};

//method 2 : two pointer

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        int left,right;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;++i)
        {
            if(i>0&&nums[i]==nums[i-1]) //解決duplicate
                continue;
            else  //類似two sum的方法
            {
                 left=i+1;
                right=nums.size()-1;
                while(left<right)
                {
                    if(nums[left]+nums[right]==-nums[i]) 
                    {
                        ans.push_back({nums[i],nums[left],nums[right]});
                        while(left<right&&nums[right]==nums[right-1]) //解決duplicate
                            right--;
                        while(left<right&&nums[left]==nums[left+1]) //解決duplicate
                            left++;   
                        right--;
                        left++;
                    }   
                    else if(nums[left]+nums[right]>-nums[i])
                        right--;
                    else
                        left++;
                }
            }
        }
        return ans;
    }
};
