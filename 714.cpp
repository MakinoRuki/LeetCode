// 第i天可以选择买/卖股票。dp。
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[n+1][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i-1][0];
            if (dp[i-1][1] > INT_MIN) {
                dp[i][0] = max(dp[i][0], dp[i-1][1] - prices[i]);
            }
            dp[i][1] = dp[i-1][1];
            if (dp[i-1][0] > INT_MIN) {
                dp[i][1] = max(dp[i][1], dp[i-1][0] + prices[i] - fee);
            }
        }
        return dp[n-1][1];
    }
};
