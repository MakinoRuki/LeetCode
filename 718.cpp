// 或者可以二分+hash。
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans=0;
        int n = A.size();
        int m = B.size();
        for (int j = 1; j <= m; ++j) {
            int cnt=(A[0] == B[j-1] ? 1 : 0);
            ans=max(ans, cnt);
            for (int i = 2; i <= n; ++i) {
                if (i-1 + j > m) break;
                if (A[i-1] == B[j+i-1-1]) {
                    cnt++;
                } else {
                    cnt=0;
                }
                ans=max(ans,cnt);
            }
        }
        for (int i = 1; i <= n; ++i) {
            int cnt=(A[i-1] == B[0] ? 1 : 0);
            ans=max(ans,cnt);
            for (int j = 2; j <= m; ++j) {
                if (i + j-1 > n) break;
                if (A[i+j-1-1] == B[j-1]) {
                    cnt++;
                } else {
                    cnt=0;
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};
