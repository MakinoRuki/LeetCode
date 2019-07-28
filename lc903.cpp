// dp[i,j]表示前i个数字的排列，第i个数字是j的方案数。
// 核心思想是当结尾是j时，前i-1个数字中所有>=j的数字向上+1。
// prefix sum从O(n^3)优化到O(n^2)。
const int mod = 1000000007;
class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.size();
        int dp[2][n+1];
        int sum[n+1];
        memset(sum, 0, sizeof(sum));
        memset(dp,0,sizeof(dp));
        dp[1][1] = 1;
        sum[1]= 1;
        for (int i = 2; i <= n; ++i) {
            int now = i&1;
            memset(dp[now], 0, sizeof(dp[now]));
            for (int j = 1; j <= i; ++j) {
                if (S[i-2] == 'D') {
                    dp[now][j] = sum[i-1]-sum[j-1];
                } else {
                    dp[now][j] = sum[j-1];
                }
                if (dp[now][j] >= mod) dp[now][j] -= mod;
            }
            memset(sum, 0, sizeof(sum));
            for (int j = 1; j <= i; ++j) {
                sum[j] = sum[j-1]+dp[now][j];
                if (sum[j] >= mod) sum[j] -= mod;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += dp[n&1][i];
            if (ans >= mod) ans -= mod;
        }
        return ans;
    }
};
