
//time limmit exceeded


//brute force
int trap(int* height, int heightSize){

    int left,right,total=0,x;

    for(int i=1;i<heightSize-1;++i)
    {
        left=0;
        right=0;
        for(int j=0;j<=i;++j)
        {
            if(height[j]>left)
                left=height[j];
        }
        for(int k=i;k<heightSize;++k)
        {
            if(height[k]>right)
                right=height[k];
        }
        x=(left>right)?right-height[i]:left-height[i];
        total+=x;
    }
    
    return total;
}
