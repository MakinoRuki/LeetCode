class Solution {
public:
    int n;
    int dfs(vector<int>& nums, int b, int e) {
        if (b + 1 >= e) {
            return 0;
        }
        int m = (b+e)/2;
        int res = 0;
        res += dfs(nums, b, m);
        res += dfs(nums, m, e);
        int j = m;
        for (int i = b; i < m; ++i) {
            while(j < e && (long)nums[i] - nums[j] > nums[j]) {
                j++;
            }
            res += j - m;
        }
        sort(nums.begin() + b, nums.begin() + e);
        return res;
    }
    int reversePairs(vector<int>& nums) {
        n = nums.size();
        return dfs(nums, 0, n);
    }
};
