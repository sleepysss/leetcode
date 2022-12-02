class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left=0,right=0,count0=0,maxsize=0,size=0; //count0:將0變為1的個數

        for(right=0;right<nums.size();++right)
        {
            if(!nums[right])
                count0++;
               
            while(count0>k)
            {
                size--;
                if(!nums[left++])
                    count0--;
            }
            size=right-left+1; //cal the length of valid subarr
            maxsize=maxsize>size?maxsize:size;
        }
        return maxsize;
    }
};
