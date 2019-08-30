// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int tot = 0;
        while(true) {
            int sz = read4(buf+tot);
            if (sz == 0) break;
            tot += sz;
        }
        return min(tot, n);
    }
};
