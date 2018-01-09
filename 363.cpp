class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        int ans = INT_MIN;
        for (int c1 = 0; c1 < m; ++c1) {
            vector<int>sum(n, 0);
            for (int c2 = c1; c2 < m; ++c2) {
                for (int r = 0; r < n; ++r) {
                    sum[r] += matrix[r][c2];
                }
                set<int> sums;
                sums.clear();
                int tsum = 0;
                for (int r = 0; r < n; ++r) {
                    tsum += sum[r];
                    sums.insert(tsum);
                    set<int>::iterator itr = lower_bound(sums.begin(), sums.end(), tsum - k);
                    if (itr != sums.end() && tsum - * itr != 0) {
                        ans = max(ans, tsum - *itr);
                    }
                //    if (tsum - *itr == 8) return r;
                    if (tsum <= k) {
                        ans = max(ans, tsum);
                    }
                }
            }
        }
        return ans;
    }
};
