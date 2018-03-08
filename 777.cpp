class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) return false;
        int n = start.size();
        string s1 = "", s2 = "";
        for (int i = 0; i < n; ++i) {
            if (start[i] != 'X') s1 += start[i];
        }
        for (int i = 0; i < n; ++i) {
            if (end[i] != 'X') s2 += end[i];
        }
        if (s1 != s2) return false;
        int i = 0, j = 0;
        while(i < n && j < n) {
            if (start[i] == 'X') i++;
            else if (end[j] == 'X') j++;
            else {
                if ((i < j && start[i] != 'R') || (i > j && start[i] != 'L')) return false;
                i++;
                j++;
            } 
        }
        return true;
    }
};
