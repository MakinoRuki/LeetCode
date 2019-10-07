class Solution {
public:
    string countOfAtoms(string formula) {
        vector<pair<string, int>> stk;
        int n = formula.size();
        int i = 0;
        while(i < n) {
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                string ns = formula.substr(i, 1);
                i++;
                while(i < n && formula[i] >= 'a' && formula[i] <= 'z') {
                    ns.push_back(formula[i]);
                    i++;
                }
                int cnt=0;
                if (i < n && formula[i] >= '0' && formula[i] <= '9') {
                    while(i < n && formula[i] >= '0' && formula[i] <= '9') {
                        cnt = cnt*10 + formula[i] - '0';
                        i++;
                    }
                } else {
                    cnt=1;
                }
                stk.push_back(make_pair(ns, cnt));
            } else if (formula[i] == '(') {
                stk.push_back(make_pair("(", 0));
                i++;
            } else if (formula[i] == ')') {
                int cnt=0;
                if (i + 1 < n && formula[i+1] >= '0' && formula[i+1] <= '9') {
                    i++;
                    while(i < n && formula[i] >= '0' && formula[i] <= '9') {
                        cnt=cnt*10+formula[i]-'0';
                        i++;
                    }
                } else {
                    cnt=1;
                }
                vector<pair<string, int> > tmp;
                while(stk.back().first != "(") {
                    auto top = stk.back();
                    stk.pop_back();
                    top.second *= cnt;
                    tmp.push_back(top);
                }
                stk.pop_back();
                while(!tmp.empty()) {
                    stk.push_back(tmp.back());
                    tmp.pop_back();
                }
            }
        }
        map<string, int> totcnt;
        for (int i = 0; i < stk.size(); ++i) {
            totcnt[stk[i].first] += stk[i].second;
        }
        string ans= "";
        for (auto v : totcnt) {
            ans += v.first + (v.second> 1 ? to_string(v.second) : "");
        }
        return ans;
    }
};
