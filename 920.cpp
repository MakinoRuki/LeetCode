typedef long long ll;
ll mod = 1e9+7;
class Solution {
public:
    ll dp[102][102];
    int numMusicPlaylists(int N, int L, int K) {
        memset(dp, 0LL, sizeof(dp));
        dp[0][0] = 1LL;
        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = dp[i - 1][j - 1] * (ll)(N-j+1) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j] * (ll)max(j - K, 0) % mod) % mod;
            }
        }
        return (int)dp[L][N];
    }
};
