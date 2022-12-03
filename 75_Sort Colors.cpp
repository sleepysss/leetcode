class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3]={0};

        for(int i=0;i<nums.size();++i)
            count[nums[i]]++;
        
        int curr=0;
        for(int i=0;i<3;++i) //three colors
        {
            for(int j=0;j<count[i];++j) //each amount
                nums[curr++]=i;
        }

    }
};
