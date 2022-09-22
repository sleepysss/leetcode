int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    
    int okay_time=-1,count=0;
    
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
