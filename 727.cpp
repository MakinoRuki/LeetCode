// dp[i][j]表示S的前i个覆盖T的前j个的最大起始位置。

class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.size();
        int m = T.size();
        int dp[n+2][m+2];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (S[i-1] == T[j-1] ? dp[i-1][j-1] : dp[i-1][j]);
            }
        }
        int ans = n+1;
        int start = -1;
        for (int i = 1; i <= n; ++i) {
            if (dp[i][m] >= 0) {
                if (i - dp[i][m] < ans) {
                    ans = i - dp[i][m];
                    start = dp[i][m];
                }
            }
        }
        return (ans > n ? "" : S.substr(start, ans));
    }
};
