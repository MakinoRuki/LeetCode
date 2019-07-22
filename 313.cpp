// pos[i]表示对于第i个素数，下次乘prime[i]的时候要从第pos[i]这个数开始乘起。
// 可以类似认为是merge k sorted list。
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> idx(k, 0);
        vector<int> dp;
        dp.push_back(1);
        for (int i = 1; i < n; ++i) {
            int res = (1<<31) - 1;
            for (int j = 0; j < k; ++j) {
                res = min(res, dp[idx[j]] * primes[j]);
            }
            for (int j = 0; j < k; ++j) {
                if (dp[idx[j]] * primes[j] == res) {
                    idx[j]++;
                }
            }
            dp.push_back(res);
        }
        return dp[n - 1];
    }
};
