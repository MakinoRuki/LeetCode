class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1, num2, cnt1=0,cnt2=0;
        for (int i = 0; i < n; ++i) {
            if (cnt1 && num1 == nums[i]) {
                cnt1++;
            } else if (cnt2 && num2 == nums[i]) {
                cnt2++;
            } else if (cnt1==0) {
                cnt1=1;
                num1=nums[i];
            } else if (cnt2==0) {
                cnt2=1;
                num2 = nums[i];
            } else {
                cnt1--;
                cnt2--;
            }
        }
        bool has1=(cnt1>0);
        bool has2=(cnt2>0);
        cnt1=0, cnt2=0;
        for (int i = 0; i < n; ++i) {
            if (has1&&nums[i] == num1) cnt1++;
            if (has2&&nums[i] == num2) cnt2++;
        }
        vector<int> ans;
        ans.clear();
        if (cnt1 > n/3) ans.push_back(num1);
        if (cnt2 > n/3) ans.push_back(num2);
        return ans;
    }
};
