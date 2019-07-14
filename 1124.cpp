// 当sum<0时，下标最小的小于sum的位置一定是sum-1的下标。
class Solution {
public:
    unordered_map<int, int> pre;
    int n;
    int longestWPI(vector<int>& hours) {
        n = hours.size();
        pre.clear();
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int res = (hours[i] > 8 ? 1 : -1);
            sum += res;
            if (sum > 0) {
                ans = i + 1;
            } else {
                if (pre.find(sum-1) != pre.end()) {
                    ans = max(ans, i - pre[sum-1]);
                }
            }
            if (pre.find(sum) == pre.end()) {
                pre[sum] = i;
            }
        }
        return ans;
    }
};
