// 当sum<0时，下标最小的小于sum的位置一定是sum-1的下标。
// 当每个值并非1/-1而是任意整数时，可以从左到右维护presum最小值的单减序列以及从右到左维护presum最大值的单增序列。
// 然后因为两者都单调，可以两指针扫。复杂度仍然为O(n)。
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
