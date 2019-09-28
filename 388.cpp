class Solution {
public:
    int lengthLongestPath(string input) {
        int ans=0;
        vector<pair<string, int> > stk;
        int i = 0;
        int tot=0;
        string ss="";
        int n =input.size();
        bool hasdot=false;
        while(i < n && input[i] != '\n') {
            ss.push_back(input[i]);
            if (input[i] == '.') hasdot=true;
            i++;
        }
        if (hasdot) return ss.size();
        tot=ss.size();
        stk.push_back(make_pair(ss, 0));
        while(i < n) {
            int  l =0;
           // cout<<"x"<<i<<" "<<input.substr(i,2)<<endl;
            i++;
          //  cout<<i<<","<<input.substr(i,2)<<endl;
            while(i < n && input[i] == '\t') {
                l++;
                i++;
            }
        //    cout<<"i="<<i<<endl;
            bool hasdot=false;
            string ss = "";
            while (i < n && input[i] != '\n') {
                ss.push_back(input[i]);
                if(input[i]=='.') hasdot=true;
                i++;
            }
            while(!stk.empty() && l <= stk.back().second) {
                tot -= stk.back().first.size()+1;
                stk.pop_back();
            }
            stk.push_back(make_pair(ss, l));
            tot += ss.size()+1;
        //    cout<<"tot="<<tot<<endl;
          //  cout<<ss<<endl;
            if (hasdot) ans = max(ans, tot);
       //     cout<<"i2="<<i<<endl;
        }
        return ans;
    }
};
