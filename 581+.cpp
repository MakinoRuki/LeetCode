class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> maxn;
        vector<int> minn;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0) maxn.push_back(nums[i]);
            else maxn.push_back(max(maxn.back(), nums[i]));
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) minn.push_back(nums[i]);
            else minn.push_back(min(minn.back(), nums[i]));
        }
        reverse(minn.begin(), minn.end());
        int l, r;
        for (l = 0; l < n; ++l) {
            if (l > 0 && nums[l] < nums[l - 1]) break;
            if (l < n - 1 && nums[l] > minn[l + 1]) break;
        }
        for (r = n - 1; r >= 0; --r) {
            if (r < n - 1 && nums[r] > nums[r + 1]) break;
            if (r > 0 && nums[r] < maxn[r - 1]) break;
        }
        return max(r - l + 1, 0);
    }
};
