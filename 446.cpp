class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> dp[n+1];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long det = (long)A[i] - (long)A[j];
                if (det < INT_MIN || det > INT_MAX) continue;
                dp[i][det]++;
                ans += dp[j][det];
                dp[i][det] += dp[j][det];
            }
        }
        return ans;
    }
};
