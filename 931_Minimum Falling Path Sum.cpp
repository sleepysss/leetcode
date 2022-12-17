class Solution {
public:
    int min(int a,int b,int c)
    {
        int min=a;
        if(min>b)
            min=b;
        if(min>c)
            min=c;
        return min;
    }
    int min(int a,int b) //多載(overloading) 相同名稱的函數有不同的功能
    {
        return a<b?a:b;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        vector<vector<int>> store(matrix); //store[i][j]: minFallingPathSum of index i,j
        for(int i=store[0].size()-2;i>=0;--i) //從倒數第2列開始
        {
            for(int j=0;j<store[0].size();++j)
            {
                if(j==0)
                    store[i][j]=min(store[i+1][j],store[i+1][j+1])+matrix[i][j];
                else if(j==store[0].size()-1)
                    store[i][j]=min(store[i+1][j-1],store[i+1][j])+matrix[i][j];
                else
                    store[i][j]=min(store[i+1][j-1],store[i+1][j],store[i+1][j+1])+matrix[i][j];
            }
        }
        int min=store[0][0];
        for(int i=1;i<store[0].size();++i) //選第一列最小來當答案
        {
            if(min>store[0][i])
                min=store[0][i];
        }
        return min;
    }
};
