//method 1 : brute force

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int ans=0,x=matrix[0].size()<matrix.size()?matrix[0].size():matrix.size();

        for(int i=1;i<=x;++i) //size of square
        {
            for(int j=0;j<=matrix[0].size()-i;++j) //往右
            {
                int flag=0;
                for(int k=0;k<=matrix.size()-i;++k) //往下
                {
                    //check valid
                    int count=0;
                    for(int l=0;l<i;++l)
                    {
                        for(int m=0;m<i;++m)
                            count+=matrix[k+m][j+l]-'0';
                    }
                    if(count==i*i) //皆1就可存答案並跳掉
                    {
                        ans=count;
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
        }

        return ans;
    }
};
