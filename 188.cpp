class Solution {
public:
    int n;
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        if (n < 2) return 0;
        // k > n/2 直接转化成可交易任意次。
        if (k > n/2) {
            int ans =0;
            for (int i = 1; i < n; ++i) {
                int det = prices[i]-prices[i-1];
                if (det >= 0) ans+=det;
            }
            return ans;
        }
        int dp[n+1][n+1][2];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j][0] = INT_MIN;
                dp[i][j][1] = INT_MIN;
            }
        }
        dp[0][0][0] = 0;
        for (int i = 0; i < n - 1; ++i) {
            int det = prices[i+1]-prices[i];
            for (int j = 0; j <= k; ++j) {
                if (dp[i][j][0] > INT_MIN) {
                    dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][0]);
                    dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][0]+det);
                }
                if (dp[i][j][1] > INT_MIN) {
                    dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][1] + det);
                    dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][1] + max(det, 0));
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i <= k; ++i) {
            ans = max(ans, dp[n-1][i][0]);
            ans = max(ans, dp[n-1][i][1]);
        }
        return ans;
    }
};
