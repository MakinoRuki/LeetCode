class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dpu[n + 1], dpd[n + 1];
        memset(dpu, 0, sizeof(dpu));
        memset(dpd, 0, sizeof(dpd));
        dpu[0] = 1;
        dpd[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                dpu[i] = dpd[i - 1] + 1;
                dpd[i] = dpd[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                dpu[i] = dpu[i - 1];
                dpd[i] = dpu[i - 1] + 1;
            } else {
                dpu[i] = dpu[i - 1];
                dpd[i] = dpd[i - 1];
            }
        }
        return max(dpu[n - 1], dpd[n - 1]);
    }
};
