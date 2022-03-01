void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    int count1=0,count2=0;
    
    int *store=(int *)malloc(sizeof(int)*m);
    
    for(int i=0;i<m;++i)
        store[i]=nums1[i];
    
    for(int i=0;i<m+n;++i)
    {
        if(count1==m) //nothing in matrix 1
        {
            nums1[i]=nums2[count2];
            count2++;  
            continue;
        }
        if(count2==n) //nothing in matrix 2
        {
            nums1[i]=store[count1];
            count1++; 
            continue;
        }
        
        if(nums2[count2]<store[count1])
        {
            nums1[i]=nums2[count2];
            count2++;
        }
        else
        {
            nums1[i]=store[count1];
            count1++; 
        }
    }
    
}
