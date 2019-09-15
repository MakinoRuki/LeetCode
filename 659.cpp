class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt;
        for (int i = 0; i < n; ++i) {
            if (nums[i] - nums[0] >= cnt.size()) {
                for (int j = cnt.size(); j <= nums[i] - nums[0]; ++j) {
                    cnt.push_back(0);
                }
                cnt[nums[i] - nums[0]]++;
            } else {
                cnt[nums[i] - nums[0]]++;
            }
        }
        int i = 0;
        while(i < cnt.size()) {
            if (cnt[i] == 0) {
                i++;
                continue;
            }
            cnt[i]--;
            int j;
            for (j = i + 1; j < cnt.size(); ++j) {
                if (cnt[j] > cnt[j-1]) cnt[j]--;
                else break;
            }
            if (j - i <= 2) return false;
        }
        return true;
    }
};
