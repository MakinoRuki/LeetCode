typedef long long ll;
class Solution {
public:
    int findKthNumber(int n, int k) {
        bool begin = true;
        ll res=0;
        while(true) {
            int l = (begin ? 1 : 0);
            int r = 9;
            int i;
            for (i = l; i <= r; ++i) {
                ll res2=res*10+i;
                ll nk=1;
                ll lv=res2;
                ll rv=res2;
                while(true) {
                    lv=lv*10;
                    rv = rv*10+9;
                    if (n < lv) break;
                    ll det=min((ll)n,rv)-lv+1;
                    nk += det;
                }
                if (nk < k) {
                    k -= nk;
                } else {
                    break;
                }
            }
            res=res*10LL+i;
            k--;
            if (k == 0) return res;
            begin = false;
        }
        return n;
    }
};
