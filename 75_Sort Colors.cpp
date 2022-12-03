//method 1 : count sort

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


//method 2 : two pointer

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //用類似quicksort lomuto那個方法
        int red=0,blue=nums.size()-1; //red左的index皆為red,blue右的index皆為blue
        for(int i=0;i<=blue;++i) //blue右的index皆為blue,所以<=blue就好
        {
            if(nums[i]==0)
            {
                int tmp=nums[i];
                nums[i]=nums[red];
                nums[red]=tmp;
                red++;
                //因為是從左到右traverse,2必定已被換掉,所以不用i--
            }
            else if(nums[i]==2)
            {
                int tmp=nums[i];
                nums[i]=nums[blue];
                nums[blue]=tmp;
                blue--;
                i--;  //因為可能會把0,1,2swap到原本位置,而0,2會引發問題,所以要i--
            }
        }
    }
};
