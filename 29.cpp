class Solution {
public:
    int divide(long long  dividend, long long divisor) {
        long long  ans = 0;
        long long MAX_INT = (1LL<<31) - 1;
        int sign = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            sign = -1;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor) {
            long long sum = 1, tmp = divisor;
            while (tmp + tmp <= dividend) {
                tmp += tmp;
                sum += sum;
            }
            dividend -= tmp;
            ans += sum;
            if (sign > 0) {
                if (ans > MAX_INT) return MAX_INT;
            } else {
                if (ans > MAX_INT + 1) return -(MAX_INT + 1);
            }
        }
        return sign * ans;
    }
};
