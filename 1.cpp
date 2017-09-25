class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int rem = target - nums[i];
            if (hash.find(rem) != hash.end() && hash[rem] != i) {
                vector<int> ans{hash[rem], i};
                return ans;
            }
            hash[nums[i]] = i;
        }
        vector<int> ans(2);
        return ans;
    }
};
