
//核心想法:每一格的雨水量是由min(左邊最高的牆,右邊最高的牆)-那格的高度來決定的,且這個值要>0

//brute force (time limmit exceeded)
//雨水的高度是由兩側較低的磚塊高度來決定。故我們先用i遍歷height(用height[i]表示)，在每個height[i]我們分別往左邊找在height[0:i-1]範圍內的最大值maxLeft，
//也往右邊找在height[i+1:n-1]範圍內的最大值maxRight(其中n為height的size)，然後我們在取得maxLeft與maxRight的叫小值(curLevel)，就是可以儲存雨水的最高level了，
//所以我們只要重複這個動作，若height[i] < curLevel，我們只要累加curLevel-height就可以計算出答案了

int trap(int* height, int heightSize){
    
    int left_biggest,right_biggest,sum=0,water;
    
    for(int i=0;i<heightSize;++i)
    {
        left_biggest=0;
        right_biggest=0;
        
        for(int j=0;j<i;++j)
        {
            if(height[j]>left_biggest)
                left_biggest=height[j];
        }
        for(int j=i+1;j<heightSize;++j)
        {
            if(height[j]>right_biggest)
                right_biggest=height[j];
        }
        
        water=right_biggest>left_biggest?left_biggest:right_biggest;
        sum=water>height[i]?sum+water-height[i]:sum;
    }
    
    return sum;
}

//改良版
//因為我們用brute force時內層for在計算maxLeft與maxRight時會一直掃過重複的地區
//而經過神機妙算後可得知l_biggest[i]=max(l_biggest[i-1],height[i-1])
//就可用這特性來先把各個格子的l_biggest和r_biggest算出來,最後再直接判定就行
int trap(int* height, int heightSize){
    
    int *l_biggest=(int *)malloc(sizeof(int)*heightSize);
    int *r_biggest=(int *)malloc(sizeof(int)*heightSize);
    int left_biggest=height[0],right_biggest=height[heightSize-1],water,sum=0;
    
    l_biggest[0]=0;
    r_biggest[heightSize-1]=0;
    
    //把brute force中的第2個for提出來
    //idea:l_biggest[i]=max(l_biggest[i-1],height[i-1])
    //某一點左邊最高的牆為前一點來看最高的牆和前一點的高度取max
    for(int i=1;i<heightSize;++i)
        l_biggest[i]=l_biggest[i-1]>height[i-1]?l_biggest[i-1]:height[i-1];
    for(int i=heightSize-2;i>=0;--i)
        r_biggest[i]=r_biggest[i+1]>height[i+1]?r_biggest[i+1]:height[i+1];
    
    for(int i=0;i<heightSize;++i)
    {
        water=l_biggest[i]>r_biggest[i]?r_biggest[i]:l_biggest[i];
        sum=(water>height[i])?sum+water-height[i]:sum;
    }
    
    free(l_biggest);
    free(r_biggest);
    
    return sum;
}

