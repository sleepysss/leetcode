//method 1
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


//method 2

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    int *store=(int *)malloc(sizeof(int)*m);
    
    for(int i=0;i<m;++i)
        store[i]=nums1[i];
    
    int start1=0,start2=0; //小array將要traverse的index
    int start=0; //大array下一次被賦值的index
    
    while(start1<m&&start2<n)
        nums1[start++]=store[start1]<nums2[start2]?store[start1++]:nums2[start2++];
    while(start1<m)
        nums1[start++]=store[start1++];
    while(start2<n)
        nums1[start++]=nums2[start2++];
    free(store);
}

//method 3 : 從後面回來(找較大的)就不用令一個array了

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=m-1,j=n-1,count=m+n-1;

        while(i>=0&&j>=0)
            nums1[count--]=nums1[i]>nums2[j]?nums1[i--]:nums2[j--];
        while(i>=0)
            nums1[count--]=nums1[i--];
        while(j>=0)
            nums1[count--]=nums2[j--];
    }
};

