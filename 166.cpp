typedef long long ll;
class Solution {
public:
    map<ll, int> m;
    string NumToString (ll num) {
        string res = "";
        stringstream ss;
        ss<<num;
        ss>>res;
        return res;
    }
    string fractionToDecimal(int numerator, int denominator) {
        string s1, s2;
        ll sign = 1;
        ll ntr = (ll)numerator;
        ll dtr = (ll)denominator;
        if (ntr < 0 && dtr > 0) sign = -1;
        if (ntr > 0 && dtr < 0) sign = -1;
        ntr = abs(ntr);
        dtr = abs(dtr);
        s1 = NumToString(ntr / dtr);
        ntr %= dtr;
        m.clear();
        while(true) {
            if (ntr == 0) break; 
            ntr *= 10LL;
            if (m.find(ntr) != m.end()) {
                int idx = m[ntr];
                s2 = s2.substr(0, idx) + "(" + s2.substr(idx, s2.size() - idx) + ")";
                break;
            } else {
                s2 += NumToString(ntr / dtr);
                m[ntr] = s2.size() - 1;
                ntr %= dtr;
            }
        }
        if (sign < 0) s1 = "-" + s1;
        return s2.empty() ? s1 : s1 + "." + s2;
    }
};
