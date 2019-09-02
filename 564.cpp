typedef long long ll;
class Solution {
public:
    string nearestPalindromic(string n) {
        int sz = n.size();
        set<ll> cdd;
        cdd.insert(pow(10, sz-1)-1);
        cdd.insert(pow(10, sz) + 1);
        string pre = n.substr(0, (sz+1)/2);
        for (int d = -1; d <= 1; ++d) {
            ll tmp = stol(pre)+d;
            string tmp2 = to_string(tmp);
            string tmp3 = tmp2.substr(0, sz/2);
            reverse(tmp3.begin(), tmp3.end());
            cdd.insert(stol(tmp2 + tmp3));
        }
        ll diff = LONG_MAX;
        string ans;
        for (auto c : cdd) {
            if (c == stol(n)) continue;
            if (abs(stol(n) - c) < diff) {
                diff = abs(stol(n)-c);
                ans = to_string(c);
            } else if (abs(stol(n) - c) == diff) {
                if (c < stol(ans)) {
                    ans = to_string(c);
                }
            }
        }
        return ans;
    }
};
