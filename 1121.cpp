class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int n = nums.size();
        int maxv = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) cnt = 1;
            else if (nums[i] == nums[i-1]) {
                cnt++;
            } else {
                maxv = max(maxv, cnt);
                cnt = 1;
            }
        }
        maxv = max(maxv, cnt);
        if (n / maxv >= K) return true;
         return false;
    }
};
