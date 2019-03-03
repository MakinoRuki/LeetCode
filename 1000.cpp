/*dp[i,j,t]表示从i-j合并成t堆最小代价。t只需要考虑1-k，转移时考虑最左边一堆是如何来的。*/
#define inf 1000000000
class Solution {
public:
    int n;
    int dp[32][32][32];
    int mergeStones(vector<int>& stones, int k) {
        n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int t = 0; t <= n; ++t) {
                    dp[i][j][t] = ((i == j && t == 1) ? 0 : inf);
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = 0;
                for (int t = i; t <= j; ++t) {
                    sum += stones[t];
                }
                for (int t = 1; t <= k; ++t) {
                    for (int p = 1; p <= j - i + 1; p += k - 1) {
                        dp[i][j][t] = min(dp[i][j][t], dp[i][i + p - 1][1] + dp[i + p][j][t - 1]);
                    }
                }
                if ((j - i) % (k - 1) == 0) dp[i][j][1] = min(dp[i][j][1], dp[i][j][k] + sum);
            }
        }
        return dp[0][n - 1][1];
    }
};
