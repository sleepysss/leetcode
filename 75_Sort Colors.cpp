class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3]={0},i;

        for(i=0;i<nums.size();++i)
            count[nums[i]]++;
        for(i=0;i<count[0];++i)
            nums[i]=0;
        for(i=0;i<count[1];++i)
            nums[i+count[0]]=1;
        for(i=0;i<count[2];++i)
            nums[i+count[0]+count[1]]=2;
    }
};
