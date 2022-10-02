//method 1

int power(int num,int i)
{
    int val=1;
    for(int j=0;j<i;++j)
        val*=num;
    return val;
}

int bitwiseComplement(int n){
    
    //ex:原數:0000101
    //   val:0000111
    //原數XORval可達成題目的要求(即:0000010)
    //所以主要目標為創造出val
  
    int num=n,count=0,val=0;
    //算有幾位
    while(num)
    {
        count++;
        num=num>>1;
    }
    
    //填1 (有3位=>要填3個1=>等價於十進位的1+2+4)
    for(int i=0;i<count;++i)
        val+=power(2,i);
    
    //0出來的結果要為1所以要有這行@@
    if(!val)
        val++;
    
    return n^val;

}

//method 2
int bitwiseComplement(int n){
    
    int num=n,count=0;
    //一邊算bit數時一邊創造val
    while(num)
    {
        count=(count<<1)+1;
        num=num>>1;
    }
    
    //0要為1
    if(!count)
        count++;
    
    return n^count;
}
