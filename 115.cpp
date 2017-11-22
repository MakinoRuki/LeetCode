class Solution {
public:
    int n,m;
    int numDistinct(string S, string T) {
        n=S.size();
        m=T.size();
        int dp[2][m+2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;++i){
            int now_i = i&1;
            dp[now_i][0]=1;
            for(int j=1;j<=m;++j){
                dp[now_i][j] = dp[now_i^1][j];
                if(S[i-1]==T[j-1]){
                    dp[now_i][j] += dp[now_i^1][j-1];
                }
            }
        }
        return dp[n&1][m];
    }
};
