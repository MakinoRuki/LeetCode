#define N 30005
typedef long long ll;
class Solution {
public:
    int n;
    int l[N], r[N];
    int sumSubarrayMins(vector<int>& A) {
        n = A.size();
        vector<pair<int, int> > vals;
        vals.clear();
        for (int i = 0; i < n; ++i) {
            vals.push_back(make_pair(A[i], i));
        }
        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        sort(vals.begin(), vals.end());
        int ans = 0;
        int mod = 1000000007;
        for (int i = n - 1; i >= 0; --i) {
            int idx = vals[i].second;
            int val = vals[i].first;
            l[idx] = r[idx] = idx;
            int lb = idx;
            if (idx > 0 && l[idx - 1] >= 0) {
                lb = l[idx -1];
            }
            int rb = idx;
            if (idx < n - 1 && r[idx + 1] >= 0) {
                rb = r[idx + 1];
            }
            int tmp = (ll)(idx - lb + 1) * (ll)(rb - idx + 1) % mod;
            ans = (ans + (ll)tmp * (ll)val % mod) % mod;
            l[rb] = lb;
            r[lb] = rb;
        }
        return ans;
    }
};
