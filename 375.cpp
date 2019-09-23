class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n+2][n+2];
        memset(dp, 0, sizeof(dp));
        for (int i = n; i >= 1; --i) {
            dp[i][i+1] = i;
            for (int j = i+2; j <= n; ++j) {
                dp[i][j] = INT_MAX;
                for (int k= i+1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], k+max(dp[i][k-1], dp[k+1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
