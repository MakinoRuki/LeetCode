class Solution {
public:
    string getstr(int x) {
        stringstream ss;
        ss<<x;
        string s;
        ss>>s;
        return s;
    }
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string ans = "";
        for (int i = 0; i < n; ++i) {
            if (i == 0) ans += getstr(nums[i]);
            else {
                if (n > 1) ans += "/";
                if (n > 2 && i == 1) ans += "(";
                ans += getstr(nums[i]);
                if (n > 2 && i == n - 1) ans += ")";
            }
        } 
        return ans;
    }
};
