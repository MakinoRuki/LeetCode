class Solution {
public:
    vector<int> GetNext (const string& needle) {
        int n = needle.size();
        vector<int> next(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = next[i - 1];
            while(j >= 0) {
                if (needle[j + 1] == needle[i]) {
                    next[i] = j + 1;
                    break;
                }
                j = next[j];
            }
            if (needle[j + 1] == needle[i]) {
                next[i] = j + 1;
            }
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> next = GetNext(needle);
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (j == m) return i - m;
            if (haystack[i] == needle[j]) {
                j++;
            } else {
                if (j == 0) continue;
                int k = next[j - 1];
                while(k >= 0) {
                    if (needle[k + 1] == haystack[i]) {
                        break;
                    }
                    k = next[k];
                }
                if (needle[k + 1] == haystack[i]) {
                    j = k + 1;
                } else {
                    j = -1;
                }
                j++;
            }
        }
        if (j == m) return n - m;
        return -1;
    }
};
