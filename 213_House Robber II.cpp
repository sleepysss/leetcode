class Solution {
public:

    int max(int a,int b)
    {
        return a>b?a:b;
    }

    int rob(vector<int>& nums) {
        
        //Actually there are four cases, but with first and last element is invalid, 
        //and without both is already covered by either case described above. which is R R, R N, N R and N N, 
        //where R stands for rob and N stands for no rob. R R is invalid. R N and N N is covered by without last element, 
        //and NR and N N is covered by without first element.
        
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);

        //不搶尾
        vector<int> store1(nums.size()-1);
        store1[0]=nums[0];
        store1[1]=max(nums[0],nums[1]);

        for(int i=2;i<nums.size()-1;++i)
            store1[i]=max(store1[i-1],store1[i-2]+nums[i]);
        
        //不搶頭
        vector<int> store2(nums.size()-1);
        store2[0]=nums[1];
        store2[1]=max(nums[1],nums[2]);

        for(int i=2;i<nums.size()-1;++i)
            store2[i]=max(store2[i-1],store2[i-2]+nums[i+1]);

        return max(store1[nums.size()-2],store2[nums.size()-2]);
    }
};
