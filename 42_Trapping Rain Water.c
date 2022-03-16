
//brute force (time limmit exceeded)
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

//改良:先算過全部的左最大和右最大(靠left,right記目前最大,在和當前的比),然後和brute force最後一步一樣

int trap(int* height, int heightSize){

    int left=height[0],right=height[heightSize-1],total=0,x;
    
    int *store1=(int *)malloc(sizeof(int)*heightSize);
    int *store2=(int *)malloc(sizeof(int)*heightSize);
    
    for(int i=0;i<heightSize;++i) //left max height of i
    {
        if(height[i]>left)
            left=height[i];
        store1[i]=left;   
    }
    for(int i=heightSize-1;i>=0;--i) //right max height
    {
        if(height[i]>right)
            right=height[i];
        store2[i]=right;   
    }
    
    for(int i=1;i<heightSize-1;++i)
    {
        x=(store1[i]>store2[i])?store2[i]-height[i]:store1[i]-height[i];
        total+=x;
    }
    
    free(store1);
    free(store2);
    
    return total;
}


//改良:dp 把left,right拿掉,用前一個比,即: left_max[i] = max(height[i], left_max[i - 1])     right_max[i] = max(height[i], right_max[i + 1])

int trap(int* height, int heightSize){

    int total=0,x;
    
    int *store1=(int *)malloc(sizeof(int)*heightSize);
    int *store2=(int *)malloc(sizeof(int)*heightSize);
    
    store1[0]=height[0];
    for(int i=1;i<heightSize;++i) //left max height of i
    {
        if(height[i]>store1[i-1])
            store1[i]=height[i];  
        else
            store1[i]=store1[i-1];
    }
    store2[heightSize-1]=height[heightSize-1];
    for(int i=heightSize-2;i>=0;--i) //right max height
    {
        if(height[i]>store2[i+1])
            store2[i]=height[i]; 
        else
            store2[i]=store2[i+1];    
    }
    
    for(int i=1;i<heightSize-1;++i)
    {
        x=(store1[i]>store2[i])?store2[i]-height[i]:store1[i]-height[i];
        total+=x;
    }
    
    free(store1);
    free(store2);
    
    return total;
}
