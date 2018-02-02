class Solution {
public:
    int n;
    map<int, int> rs;
    bool checkSubarraySum(vector<int>& nums, int k) {
        n = nums.size();
        rs.clear();
        rs[0] = -1;
        int zero = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (nums[i] == 0) zero++;
            else zero = 0;
            if (k == 0 && zero > 1) return true;
            if (k == 0) continue;
            int r = sum % k;
            if (rs.find(r) != rs.end() && rs[r] < i - 1) {
                return true;
            }
            if (rs.find(r) == rs.end()) rs[r] = i;
            else rs[r] = min(rs[r], i);
        }
        return false;
    }
};
