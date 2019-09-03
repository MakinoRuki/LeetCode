// 维护一个单调递增的前缀和序列，每次在里面二分。
class Solution {
public:
    int getidx(vector<pair<int, int> >& rk, int tar) {
        int l = 0, r = rk.size();
        while(l < r) {
            int m = (l+r)/2;
            if (rk[m].first > tar) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
    int shortestSubarray(vector<int>& A, int K) {
        vector<pair<int, int> > rk;
        rk.clear();
        int n = A.size();
        rk.push_back(make_pair(0, 0));
        int sum = 0;
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            sum += A[i-1];
            int idx = getidx(rk, sum-K);
            if (idx > 0) {
                idx = rk[idx-1].second;
                if (ans < 0) {
                    ans = i - idx;
                } else {
                    ans = min(ans, i-idx);
                }
            }
            while(!rk.empty()) {
                auto pr = rk.back();
                if (sum <= pr.first) {
                    rk.pop_back();
                } else {
                    break;
                }
            }
            rk.push_back(make_pair(sum, i));
        }
        return ans;
    }
};
