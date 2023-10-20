class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> path;
        get_ans(s,-1,path,ans);
        return ans;
    }

    void get_ans(string s,int index_now,vector<int> &path,vector<string> &ans)
    {
        if(path.size()==4&&index_now==s.size()-1)
        {
            string result;
            //轉回string,並加入"."
            for(int i=0;i<path.size();++i)
            {
                result +=to_string(path[i]);
                if(i<path.size()-1)
                    result+=".";
            }
            ans.push_back(result);
        }
        if(path.size()>=4)
            return;

        for(int i=1;i<=3;++i)
        {
            int last = index_now+i;
            //out of range
            if(last>(s.size()-1))
                continue;
            // has leading zeros
            if(s[index_now+1]=='0' && last!=index_now+1)
                continue;
            //取出
            string num_str = s.substr(index_now+1,last-index_now); //指定的起始位置,長度
            //轉成數字
            int num;
            stringstream ss(num_str);
            ss >> num;
            //判斷範圍
            if(num<0||num>255)
                continue;
            else
            {
                path.push_back(num);
                get_ans(s,last,path,ans);
                path.pop_back();
            }
        }
    }
};
