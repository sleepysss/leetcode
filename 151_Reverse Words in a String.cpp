class Solution {
public:
    string reverseWords(string s) {

        if(s.length()==0)
            return "";
        stringstream ss(s);
        string temp,ans;
        while(ss>>temp)
        {
            ans=temp+ans;
            ans=" "+ans;
        }
        ans.erase(ans.begin());
        return ans;
    }
};
