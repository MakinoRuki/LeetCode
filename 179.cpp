bool cmp(string a, string b) {
    return a + b > b + a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> ranks;
        ranks.clear();
        for (int i = 0; i < n; ++i) {
            ranks.push_back(to_string(nums[i]));
        }
        sort(ranks.begin(), ranks.end(), cmp);
        string ans = "";
        for (int i = 0; i < ranks.size(); ++i) {
            ans += ranks[i];
        }
        int idx = 0;
        while(idx < ans.size() - 1 && ans[idx] == '0') {
            idx++;
        }
        ans = ans.substr(idx, ans.size() - idx);
        return ans;
    }
};
