//method 1 : naive recursive

public:

    bool helper(vector<int>& nums,int index)
    {
        if(index==nums.size()-1)
            return true;
        if(index>=nums.size())
            return false;

        for(int i=1;i<=nums[index];++i)
        {
            if(helper(nums,index+i))
                return true;
        }
        return false;
    }


    bool canJump(vector<int>& nums) {

        return helper(nums,0); 
    }
};
