class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        for (int i = 0; i < n && i <= r; ++i) {
            if (l >= r) break;
            if (nums[i] == 0) {
                if (i != l) {
                    swap(nums[i], nums[l]);
                    i--;
                }
                l++;
            } else if (nums[i] == 2) {
                if (i != r) {
                    swap(nums[i], nums[r]);
                    i--;
                }
                r--;
            }
        }
    }
};
