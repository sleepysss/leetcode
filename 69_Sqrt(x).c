//brute force
int mySqrt(int x){
    
    long int store=0;
    
    for(long int i=0;i<=x;++i)
    {
        if(i*i<=x)
            store=i;
        else
            break;
    }
    return store;
    
}

//***binary search template***

// range   [l,r)
// function binarysearch(l,r)
// {
//   while(l<r)
//   {
//     m=l+(r-l)/2
//     if f(m) return m (optional)
//     if g(m) return
//       r=m
//     else
//       l=m+1
//   }
//   return l or not found(if f() exist)
//   l will be smallest num that g() can exist  (given a function g(mid),returns the smallest mid in the range such that g(mid) holds true)
// }

//binary search

int mySqrt(int x){
    long long int left=1;
    long long right=(long long)x+1;
    long long mid;
    while(left<right)
    {
        mid=left+(right-left)/2;
        
        if(mid*mid>x)
            right=mid;
        else
            left=mid+1;
    }
    return left-1;
}





