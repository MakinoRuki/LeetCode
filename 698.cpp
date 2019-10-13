// 有一些常熟优化。可以使用状压dp。
class Solution {
public:
    int n;
    bool dfs(vector<int>& nums, int st, int cnt, int sum, int limit, int k) {
        if (st == (1<<n)-1) {
            if (cnt==k && sum==0) {
                return true;
            }
            return false;
        }
        for (int i = n-1; i >= 0; --i) {
            if ((1<<i) & st) continue;
            if (nums[i] + sum > limit) continue;
            if (nums[i] + sum == limit) {
                if (dfs(nums, st|(1<<i), cnt+1, 0, limit, k)) return true;
            } else if (nums[i] + sum < limit) {
                if (dfs(nums, st|(1<<i), cnt, sum+nums[i], limit, k)) return true;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        int sum=0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        sort(nums.begin(), nums.end());
        if (sum%k) return false;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > sum/k) return false;
        }
        return dfs(nums, 0, 0, 0, sum/k, k);
    }
};
