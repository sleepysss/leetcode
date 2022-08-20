//method1:trival division algorithm
//Instead of trying from 1 to min, try from min to 1, if the remainder is 0, it is GCD !

int findGCD(int* nums, int numsSize){
    
    int smallest=nums[0],biggest=nums[0],ans;
    
    for(int i=1;i<numsSize;++i)
    {
        if(nums[i]<smallest)
            smallest=nums[i];
        if(nums[i]>biggest)
            biggest=nums[i];
    }
    
    for(int i=smallest;i>=1;--i)
    {
        if(smallest%i==0&&biggest%i==0)
        {
            ans=i;
            break;
        }
    }
    return ans;
}

//method2:Euclidean Algorithm

//if a=bq+r then gcd(a,b)=gcd(b,r)
//proof:
//if we can proof all common divisors of (a,b) and (b,r) are same then gcd(a,b)=gcd(b,r)
//if t is a common divisior of (a,b) -> t|a , t|b and by theorem:if a|b and a|c then a|mb+nc , so we can get t|a-bq and it is equal to t|r
//it means:if t is a common divisior of (a,b)then t will also be a common divisior of (b,r)
//if s is a common divisior of (b,r) -> s|b ,s|r --> we can get s|bq+r and it is  equal to s|a
//it means:if s is a common divisior of (b,r)then s will also be a common divisior of (a,b)
//so we get all common divisors of (a,b) and (b,r) are same  (The condition for two sets A and B to be equal is x∈A <=> x∈B,A:common divisior of (a,b),B:common divisior of (b,r))
//so gcd(a,b)=gcd(b,r)


//iterative
int findGCD(int* nums, int numsSize){
    
    int smallest=nums[0],biggest=nums[0],ans;
    
    for(int i=1;i<numsSize;++i)
    {
        if(nums[i]<smallest)
            smallest=nums[i];
        if(nums[i]>biggest)
            biggest=nums[i];
    }
    
    //1.If a is a non-zero integer, then gcd(a,0)=a  (0 % any num is 0)
    //2.gcd(10,20)=gcd(20,10),it will convert by itself,so we dont need to take careful of which one is bigger(a>b or b>a)
    
    while(smallest!=0)
    {
        int r=biggest%smallest;
        biggest=smallest;
        smallest=r;
    }
    return biggest;
}

//recursive
int cal_gcd(int a,int b)
{
    if(!b)
        return a;
    else
        return cal_gcd(b,a%b);
}

int findGCD(int* nums, int numsSize){
    
    int smallest=nums[0],biggest=nums[0],ans;
    
    for(int i=1;i<numsSize;++i)
    {
        if(nums[i]<smallest)
            smallest=nums[i];
        if(nums[i]>biggest)
            biggest=nums[i];
    }
    
    //1.If a is a non-zero integer, then gcd(a,0)=a
    //2.gcd(10,20)=gcd(20,10),it will convert by itself,so we dont need to take careful of which one is bigger
    
    return cal_gcd(biggest,smallest);
}

