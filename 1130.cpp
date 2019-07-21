// dp可做。dp[i,j]表示i->j的最小sum，枚举中间划分的k。
// 每个arr中的值在向上走的时候会因为遇到左边第一个最大值or右边第一个最大值消失，并在此时计算属于它的cost。
// 因此只需要知道每个arr[i]左右较小的最大值然后相乘得cost。
class Solution {
public:
    int n;
    int mctFromLeafValues(vector<int>& arr) {
        n = arr.size();
        vector<int> maxv{INT_MAX};
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = arr[i];
            while(a >= maxv.back()) {
                int v = maxv.back();
                maxv.pop_back();
                int v2 = maxv.back();
                ans += v * min(v2, a);
            }
            maxv.push_back(a);
        }
        for (int i = 2; i < maxv.size(); ++i) {
            ans += maxv[i] * maxv[i-1];
        }
        return ans;
    }
};
