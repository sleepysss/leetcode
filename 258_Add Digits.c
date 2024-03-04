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
