class Solution {
public:
    int n;
    int dp[52][52];
    int minScoreTriangulation(vector<int>& A) {
        n = A.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                dp[i][j]=INT_MAX;
            }
        }
        for (int i = 0; i <n; ++i) {
            dp[i][i]=0;
            dp[i][i+1]=0;
        }
        for (int d=2; d < n; ++d) {
            for (int i = 0; i+d < n; ++i) {
                for (int k=i+1; k < i+d; ++k) {
                    int j = i+d;
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]+A[i]*A[j]*A[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};
