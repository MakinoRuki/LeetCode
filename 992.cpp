// 对于每一个i要维护两个指针j1和j2。
// 一个是刚好等于K的位置，一个是刚好小于K的位置。

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        unordered_map<int, int> cnt[2];
        int j1 = 0;
        int j2 = 0;
        int ans = 0;
        int tot1 = 0;
        int tot2 = 0;
        for (int i = 0; i < n; ++i) {
            cnt[0][A[i]]++;
            if (cnt[0][A[i]] == 1) tot1++;
            cnt[1][A[i]]++;
            if (cnt[1][A[i]] == 1) tot2++;
            while(j1 <= i && tot1 > K) {
                cnt[0][A[j1]]--;
                if (cnt[0][A[j1]] == 0) tot1--;
                j1++;
            }
            while(j2 <= i && tot2 >= K) {
                cnt[1][A[j2]]--;
                if (cnt[1][A[j2]] == 0) tot2--;
                j2++;
            }
            if (tot1 == K && tot2 == K-1) {
                ans += j2-j1;
            }
        }
        return ans;
    }
};
