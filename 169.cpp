class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int num = nums[0];
        for (int i = 1; i < n; ++i) {
            if (cnt == 0) {
                num = nums[i];
                cnt++;
            } else {
                if (nums[i] == num) cnt++;
                else cnt--;
            }
        }
        return num;
    }
};
