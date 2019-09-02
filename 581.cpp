class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minv = INT_MAX;
        int l=n, r=-1;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > minv) {
                l = i;
            }
            minv = min(minv, nums[i]);
        }
        int maxv = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < maxv) {
                r = i;
            }
            maxv = max(maxv, nums[i]);
        }
        if (l < n) {
            return r-l+1;
        }
        return 0;
    }
};
