int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    
    //T毛可愛:)
    
    int okay_time=-1,count=0; //okay_time:正常狀態的時間 okay_time為2代表地2秒(含)以後為正常的
    
    for(int i=0;i<timeSeriesSize;++i)
    {
        if(timeSeries[i]>=okay_time)
        {
            okay_time=timeSeries[i]+duration;
            count+=duration;
        }
        else
        {
            count=count-(okay_time-timeSeries[i]);
            okay_time=timeSeries[i]+duration;
            count+=duration;
        }
    }
    return count;
}
