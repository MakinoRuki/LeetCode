// 动手写一下会发现(x1-y1)-(x2-y2)=(x1+y2)-(y1+x2)。
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
                if (!dp[i][j]) continue;
                dp[i+1][j] = true;
                dp[i+1][j+stones[i]] = true;
            }
            sum += stones[i];
        }
        int minv = sum+1;
        for (int i = 0; i <= sum; ++i) {
            if (dp[n][i]) {
                minv = min(minv, abs(sum-2*i));
            }
        }
        return minv;
    }
};
