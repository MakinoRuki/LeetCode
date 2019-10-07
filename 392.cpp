// 当|t|很大且s个数很多时。
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> pos;
        int n = s.size();
        int m = t.size();
        for (int i = 0; i < m; ++i) {
            pos[t[i]].push_back(i);
        }
        int cur=-1;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            auto vs = pos[c];
            auto itr = upper_bound(vs.begin(), vs.end(), cur);
            if (itr == vs.end()) return false;
            cur = *itr;
        }
        return true;
    }
};
