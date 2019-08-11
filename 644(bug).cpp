// 二分这个最大的均值
#define eps 1e-5
class Solution {
public:
    int n;
    vector<int> ns;
    bool check(double m, int k) {
        double sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += ns[i] - m;
        }
        if (sum >= 0) return true;
        double pre = 0;
        double minpre = INT_MAX;
        for (int i = k; i < n; ++i) {
            sum += ns[i] - m;
            pre += ns[i-k] - m;
            minpre = min(minpre, pre);
            if (sum >= minpre) return true;
        }
        return false;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        ns = nums;
        n = ns.size();
        double minv = INT_MAX;
        double maxv = INT_MIN;
        for (int i = 0; i < n; ++i) {
            minv = min(minv, (double)ns[i]);
            maxv = max(maxv, (double)ns[i]);
        }
        double l = minv;
        double r = maxv;
        while(fabs(l-r) >= eps) {
            double mid = (l + r) * 0.5;
            if (check(mid, k)) l = mid;
            else r = mid;
        }
        return r;
    }
};
