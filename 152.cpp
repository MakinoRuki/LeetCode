typedef long long ll;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        ll ans = nums[0];
        ll maxV = ans;
        ll minV = ans;
        for (int i = 1; i < n; ++i) {
            ll tmpMax = maxV;
            ll tmpMin = minV;
            maxV = max(max(tmpMax * nums[i], tmpMin * nums[i]), (ll)nums[i]);
            minV = min(min(tmpMax * nums[i], tmpMin * nums[i]), (ll)nums[i]);
            ans = max(ans, maxV);
        }
        return ans;
    }
};
