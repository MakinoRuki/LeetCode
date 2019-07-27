// 左指针从右往左找最小的，然后对于这个最小的，右指针从右往左找第一个大于等于它的。
// 然后左指针向左走，右指针跟着向右走。
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        vector<int> minv;
        for (int i = 0; i < n; ++i) {
            if (minv.empty() || A[i] < A[minv.back()]) {
                minv.push_back(i);
            }
        }
        int ans = 0;
        int maxi = n;
        int j = minv.size() - 1;
        for (int i = n - 1; i >= 0; --i){
            if (i == n - 1 || A[i] > A[maxi]) {
                maxi = i;
            }
            while(j >= 0 && A[minv[j]] <= A[maxi]) {
                j--;
            }
            j++;
            if (A[minv[j]] <= A[maxi]) {
                ans = max(ans, maxi - minv[j]);
            }
        }
        return ans;
    }
};
