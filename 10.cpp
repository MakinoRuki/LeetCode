class Solution {
public:
    int dp[1000][1000];
    bool dfs(string& s, int si, string& p, int pi) {
        if (dp[si][pi] >= 0) return dp[si][pi];
        if (si == s.size()) {
            if (pi == p.size()) return dp[si][pi] = 1;
            int i = pi;
            while (i < p.size()) {
                if (p[i] != '*') {
                    if (i + 1 < p.size() && p[i + 1] == '*') i++;
                    else return dp[si][pi] = 0;
                } else {
                    i++;
                }
            }
            return dp[si][pi] = 1;
        } else {
            if (pi == p.size()) {
                return dp[si][pi] = 0;
            }
            if (pi + 1 < p.size() && p[pi + 1] == '*') {
                if (dfs(s, si, p, pi + 2)) return dp[si][pi] = 1;
                if ((s[si] == p[pi] || p[pi] == '.') && dfs(s, si + 1, p, pi)) return dp[si][pi] = 1;
                return dp[si][pi] = 0;
            } else {
                if (s[si] == p[pi] || p[pi] == '.') return dp[si][pi] = dfs(s, si + 1, p, pi + 1);
                return dp[si][pi] = 0;
            }
        }
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        dfs(s, 0, p, 0);
        return dp[0][0];
    }
};
