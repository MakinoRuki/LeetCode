class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2,0);
        int n = nums.size();
        int xr = 0;
        for (int i = 0; i < n; ++i) {
            xr ^= nums[i];
        }
        int b = 0;
        while(!((1<<b) & xr)) {
            b++;
        }
        for (int i = 0; i < n; ++i) {
            if ((1<<b) & nums[i]) {
                ans[0] ^= nums[i];
            } else {
                ans[1] ^= nums[i];
            }
        }
        return ans;
    }
};
