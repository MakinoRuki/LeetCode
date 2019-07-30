class Solution {
public:
    int dp[102][102][2];
    int n;
    vector<int> ps;
    int dfs(int rs, int m, int p) {
        if (dp[rs][m][p] >= 0) return dp[rs][m][p];
        if (rs == 0) {
            return dp[rs][m][p] = 0;
        }
        int sum = 0;
        if (!p) dp[rs][m][p] = INT_MIN;
        else dp[rs][m][p] = INT_MAX;
        for (int x = 1; x <= 2 * m; ++x) {
            if (n-rs+x-1 >= n) break;
            sum += ps[n-rs+x-1];
            if (!p) dp[rs][m][p] = max(dp[rs][m][p], sum+dfs(rs-x, max(m, x), !p));
            else dp[rs][m][p] = min(dp[rs][m][p], dfs(rs-x, max(m,x), !p));
        }
        return dp[rs][m][p];
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        ps = piles;
        memset(dp, -1, sizeof(dp));
        return dfs(n, 1, 0);
    }
};
