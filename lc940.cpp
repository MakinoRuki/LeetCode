typedef long long ll;
ll mod = 1000000007LL;
class Solution {
public:
    int n;
    // 以字母i结尾的方案数。因为在乎的不是位置(选了j个)而是结束位置是什么字母。
    ll dp[30];
    int distinctSubseqII(string S) {
        n = S.size();
        ll tot = 1LL;
        memset(dp, 0LL, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            ll tmp = (tot - dp[S[i] - 'a'] + mod) % mod;
            dp[S[i] - 'a'] = tot;
            tot = (tmp + dp[S[i] - 'a']) % mod;
        }
        return tot - 1LL;
    }
};
