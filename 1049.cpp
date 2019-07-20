// 动手写一下会发现(x1-y1)-(x2-y2)=(x1+y2)-(y1+x2)。
// 答案可以转化成把n堆石子分成两个子集的sum的差最小。
class Solution {
public:
    int n;
    bool dp[32][3010];
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                if (dp[i][j]) {
                    dp[i+1][j] = true;
                    dp[i+1][j + stones[i]] = true;
                }
            }
            sum += stones[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i <= sum; ++i) {
            if (dp[n][i]) {
                ans = min(ans, abs(sum - i - i));
            }
        }
        return ans;
    }
};
