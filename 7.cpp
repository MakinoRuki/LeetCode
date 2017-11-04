class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int sign = x / abs(x);
        x = abs(x);
        int res1 = 0;
        int tmpx = x;
        while(tmpx) {
            res1 = res1 * 10 + tmpx % 10;
            tmpx /= 10;
        }
        tmpx = res1;
        int res2 = 0;
        while(tmpx) {
            res2 = res2 * 10 + tmpx % 10;
            tmpx /= 10;
        }
        if (x != res2) {
            int tmpy = 0;
            if (x > res2) {
                if (x % res2 != 0) return 0;
                tmpy = x / res2;
            } else {
                if (res2 % x != 0) return 0;
                tmpy = res2 / x;
            }
            while(tmpy > 1) {
                tmpy /= 10;
            }
            if (tmpy != 1) return 0;
        }
        return sign * res1;
    }
};
