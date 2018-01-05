class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m = nums.size();
        vector<int> ans;
        ans.clear();
        long long maxv = 0;
        int i = 0;
        long long cnt = 0;
        while(i < m) {
            if (maxv >= n) break;
            if (nums[i] - maxv > 1) {
                ans.push_back(maxv + 1);
                maxv = max(maxv, 2 * maxv + 1);
                cnt++;
            } else {
                ans.push_back(nums[i]);
                maxv = max(maxv, maxv + nums[i]);
                i++;
            }
        }
        while(maxv < n) {
            cnt++;
            maxv = max(maxv, 2 * maxv + 1);
        }
        return cnt;
    }
};
