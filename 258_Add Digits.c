//法1

int addDigits(int num) {

    while(num)
    {
        if(num/10==0)
            return num;
        else
        {
            int sum=0;
            while(num)
            {
                sum=sum+num%10;
                num/=10;
            }
            num=sum;
        }
    }
    return num;
}

//法2 recursive

int addDigits(int num) {

    if(num/10==0)
        return num;
    
    int sum=0;
    while(num)
    {
        sum=sum+num%10;
        num/=10;
    }
    return addDigits(sum);
}
