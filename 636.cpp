class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        vector<int> stk;
        int pre=0;
        string pret="";
        for (int i = 0; i < logs.size(); ++i) {
            int id=0;
            string ss;
            int tm=0;
            int cnt=0;
            for (int j = 0; j < logs[i].size(); ++j) {
                if (logs[i][j] == ':') cnt++;
                else {
                    if (cnt == 0) {
                        id=id*10+logs[i][j]-'0';
                    } else if (cnt==1) {
                        ss.push_back(logs[i][j]);
                    } else {
                        tm = tm*10+logs[i][j]-'0';
                    }
                }
            }
            if (stk.size()) {
                ans[stk.back()] += tm-pre;
            }
            pre = tm;
            if (ss == "start") {
                stk.push_back(id);
            } else {
                int id=stk.back();
                stk.pop_back();
                ans[id]++;
                pre++;
            }
        }
        return ans;
    }
};
