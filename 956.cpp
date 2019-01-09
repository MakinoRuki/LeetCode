#define N 21
#define M 5001
#define inf 1000000000
class Solution {
public:
    int dp[N][M];
    int n;
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < M; ++j) {
                dp[i][j] = -inf;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < M; ++j) {
                if (dp[i][j] < 0) continue;
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                int v = rods[i];
                if (j + v < M) dp[i + 1][j + v] = max(dp[i + 1][j + v], dp[i][j] + v);
                if (v <= j) dp[i + 1][j - v] = max(dp[i + 1][j - v], dp[i][j]);
                else if (dp[i][j] + v - j < M) dp[i + 1][v - j] = max(dp[i + 1][v - j], dp[i][j] - j + v);
            }
        }
        return dp[n][0];
    }
};
