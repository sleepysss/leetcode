// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    
    int left=1,right=n,mid;
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(isBadVersion(mid))
            right=mid-1;
        else
            left=mid+1;
    }
    return left;
}



//c++ ver

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int start=1,end=n;

        while(start<=end)
        {
            int mid = start+(end-start)/2;
            bool results = isBadVersion(mid);
            if(!results)
                start = mid+1;
            else
                end = mid-1;
        }
        return start;
    }
};
