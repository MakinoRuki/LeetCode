class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        int n = num.size();
        string res = "";
        int cnt=0;
        for (int i = 0; i < n; ++i) {
            while(res.size() && num[i] < res.back() && cnt < k) {
                res.pop_back();
                cnt++;
            }
            res.push_back(num[i]);
        }
        int i=0;
        while(i < res.size() && res[i] == '0') i++;
        if (i == res.size()) return "0";
        res = res.substr(i);
        while(cnt < k && res.size()) {
            res.pop_back();
            cnt++;
        }
        if (res.empty()) return "0";
        return res;
    }
};
