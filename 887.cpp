class Solution {
public:
    int dp[2][102];
    int superEggDrop(int K, int N) {
        memset(dp, 0, sizeof(dp));
        int cnt = 0;
        while(true) {
            ++cnt;
            int now = cnt & 1;
            memset(dp[now], 0, sizeof(dp[now]));
            for (int j = 1; j <= K; ++j) {
                dp[now][j] = dp[now ^ 1][j] + dp[now ^ 1][j - 1] + 1;
                if (dp[now][j] >= N) return cnt;
            }
        }
        return 0;
    }
};
