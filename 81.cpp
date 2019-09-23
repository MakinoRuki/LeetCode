class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int l = 0, r = n-1;
        while(l < r) {
            int m = (l+r)/2;
            if (nums[l] < nums[m]) {
                if (target <= nums[m] && target >= nums[l]) {
                    r = m;
                } else {
                    l= m+1;
                }
            } else if (nums[l] > nums[m]) {
                if (target <= nums[m] || target >= nums[l]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            } else {
                if (target == nums[m]) return true;
                else l++;
            }
        }
        return nums[r] == target;
    }
};
