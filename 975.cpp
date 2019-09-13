class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
      int n = A.size();
      bool dp[n+1][2];
      memset(dp, false, sizeof(dp));
      dp[n-1][0] = true;
      dp[n-1][1] = true;
      int ans = 1;
      map<int, int> m;
      m.clear();
      m[A[n-1]] = n-1;
      for (int i = n-2; i >= 0; --i) {
        auto idx1 = m.upper_bound(A[i]);
        auto idx2 = m.lower_bound(A[i]);
        if (idx2->first == A[i]) {
          int j  =idx2->second;
          dp[i][0] = dp[j][1];
          dp[i][1] = dp[j][0];
        } else {
          if (idx1 != m.end()) {
            int j = idx1->second;
            dp[i][1] = dp[j][0];
          }
          if (idx2 != m.begin()) {
            idx2--;
            int j = idx2->second;
            dp[i][0] = dp[j][1];
          }
        }
        m[A[i]] = i;
        if (dp[i][1]) ans++;
      }
      return ans;
    }
};
