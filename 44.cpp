class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int i = 0, j = 0;
        int star = -1, starCover = -1;
        while(i < n) {
            if (s[i] == p[j]) {
                i++;
                j++;
            } else {
                if (p[j] == '?') {
                    i++;
                    j++;
                } else {
                    if (p[j] == '*') {
                        star = j;
                        starCover = i;
                        j++;
                    } else {
                        if (star < 0) return false;
                        j = star + 1;
                        i = starCover + 1;
                        while(i < n && (s[i] != p[j] && p[j] != '?')) {
                            i++;
                        }
                        starCover = i;
                    }
                }
            }
        }
        while(j < m && p[j] == '*') j++;
        if (i == n && j == m) return true;
        return false;
    }
};
