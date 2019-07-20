// dp[i][j]表示从i到j的最小cost。那么(i,j)是多边形的一条边，枚举k作为(i,j)所在三角形的另外一个顶点。
// 把多边形分成dp[i][k]+dp[k][j]+A[i]*A[j]*A[k]。
class Solution {
public:
    int n;
    int dp[52][52];
    int minScoreTriangulation(vector<int>& A) {
        n = A.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
            dp[i][i+1] = 0;
        }
        for (int d = 2; d < n; ++d) {
            for (int i = 0; i + d < n; ++i) {
                int j = i + d;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+A[i]*A[j]*A[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};
