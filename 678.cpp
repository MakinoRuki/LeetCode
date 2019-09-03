class Solution {
public:
    bool checkValidString(string s) {
        vector<int> ls;
        vector<int> ss;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') ls.push_back(i);
            else if (s[i] == '*') ss.push_back(i);
            else if (s[i] == ')') {
                if (!ls.empty()) ls.pop_back();
                else if (!ss.empty()) ss.pop_back();
                else return false;
            }
        }
        int tot = 0;
        while(!ls.empty()) {
            if (ss.empty()) {
                if (tot < 0) {
                    tot++;
                    ls.pop_back();
                } else {
                    return false;
                }
            } else {
                int i = ls.back();
                int j = ss.back();
                if (i < j) {
                    tot--;
                    ss.pop_back();
                } else {
                    tot++;
                    ls.pop_back();
                }
                if (tot > 0) return false;
            }
        }
        return true;
    }
};
