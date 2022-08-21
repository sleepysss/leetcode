//method1:brute force ---TLE
int maxArea(int* height, int heightSize){
    
    
    int left,right,sum,biggest=0;
    
    //try every pair of walls
    for(left=0;left<heightSize;++left)
    {
        for(right=left+1;right<heightSize;++right)
        {
            //cal area
            sum=height[left]>height[right]?height[right]*(right-left):height[left]*(right-left);
            
            if(sum>biggest)
                biggest=sum;
        }
    }
    return biggest;
}


//method2
//面積=高度*長度
//Staring from widest bars (i.e. first and last bar) and then narrowing width to find potentially better pair(s).
//從頭尾向內夾找出最大值
//因為最大容量是用比較短的一端決定，且向內移動勢必讓寬度下降，若兩端高度不變則面積也會變小
//所以比較兩個指針在陣列中的長度，長度較短的指針向中心移動
//在這個邏輯下，若指針向內移動找到更長的一端，面積才有變大的可能！
//proof:https://blog.csdn.net/weixin_34060741/article/details/88730322

int maxArea(int* height, int heightSize){
    int left=0,right=heightSize-1,sum,biggest=0;
    
    while(right>left)
    {
        sum=height[left]>height[right]?height[right]*(right-left):height[left]*(right-left);
        if(sum>biggest)
            biggest=sum;
        
        height[left]>height[right]?right--:left++;
    }
    
    return biggest;
}



