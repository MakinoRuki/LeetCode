// 上次的可能已经读过了但是没有放进buf中。
// 因此要用cache保存下来。

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int cur = 0;
    int sz = 0;
    char cache[4];
    int read(char *buf, int n) {
        int cnt = 0;
        while(true) {
            if (cur < sz) {
                while(cur < sz) {
                    if (cnt == n) return n;
                    buf[cnt++] = cache[cur++];
                }
            } else {
                cur = 0;
                sz = read4(cache);
                if (sz == 0) return cnt;
            }
        }
        return min(n, cnt);
    }
};
