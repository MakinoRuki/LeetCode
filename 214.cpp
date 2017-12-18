class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string t = s + "#" + rev_s;
        vector<int> next(t.size(), -1);
        for (int i = 1; i < t.size(); ++i) {
            int j = next[i - 1];
            while(j >= 0 && t[j + 1] != t[i]) {
                j = next[j];
            }
            if (t[j + 1] == t[i]) next[i] = j + 1;
            else next[i] = -1;
        }
        return rev_s.substr(0, s.size() - next[t.size() - 1] - 1) + s;
    }
};
