class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int d = 1;
        for (int i = 1; i < n; ++i) {
            if ((d && nums[i] < nums[i - 1]) || (!d && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
            d = !d;
        }
    }
};
