class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        int idx= 0;
        int i = 1;
        while(i < n) {
            if (s[i] > s[idx]) {
                idx = i;
                i++;
            } else if (s[i] == s[idx]) {
                int j = idx+1;
                int k = i + 1;
                // 不需要比到底，到i即可。
                while(j < i && k < s.size() && s[j] == s[k]) {
                    j++;
                    k++;
                }
                if (j == i || k == s.size() || s[j] >= s[k]) {
                    i = k;
                    continue;
                }
                idx = i;
                i++;
            } else {
                i++;
            }
        }
        return s.substr(idx);
    }
};
