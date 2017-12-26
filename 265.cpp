#define inf 1000000000
int dp[10000];
int ldp[10000], rdp[10000];
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        int n = costs.size();
        int k = costs[0].size();
        for (int j = 0; j < k; ++j) {
            dp[j] = costs[0][j];
            ldp[j] = (j > 0 ? min(ldp[j - 1], dp[j]) : dp[j]);
        }
        for (int j = k - 1; j >= 0; --j) {
            rdp[j] = (j < k - 1 ? min(rdp[j + 1], dp[j]) : dp[j]);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[j] = inf;
                int pre = inf;
                if (j > 0) pre = min(pre, ldp[j - 1]);
                if (j < k - 1) pre = min(pre, rdp[j + 1]);
                dp[j] = min(dp[j], pre + costs[i][j]);
            }
            for (int j = 0; j < k; ++j) {
                if (j > 0) ldp[j] = min(ldp[j - 1], dp[j]);
                else ldp[j] = dp[j];
            }
            for (int j = k - 1; j >= 0; --j) {
                if (j < k - 1) rdp[j] = min(rdp[j + 1], dp[j]);
                else rdp[j] = dp[j];
            }
        }
        int ans = inf;
        for (int i = 0; i < k; ++i) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};
