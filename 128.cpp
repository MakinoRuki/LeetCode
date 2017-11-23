class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int n = num.size();
        int maxLen = 0;
        int len = 0;
        unordered_set<int> occur;
        for (int i = 0; i < n; ++i) {
            occur.insert(num[i]);
        }
        for (int i = 0; i < n; ++i) {
            len = 1;
            for (int j = num[i] - 1; ; --j) {
                if (occur.find(j) != occur.end()) {
                    len++;
                    occur.erase(j);
                } else {
                    break;
                }
            }
            for (int j = num[i] + 1; ; ++j) {
                if (occur.find(j) != occur.end()) {
                    len++;
                    occur.erase(j);
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
