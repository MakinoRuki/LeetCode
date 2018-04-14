class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        int num[26];
        memset(num, 0, sizeof(num));
        for (int i = 0; i < m; ++i) {
            num[tasks[i] - 'A']++;
        }
        int maxCnt = 0, maxNum = 0;
        int oCnt = 0;
        for (int i = 0; i < 26; ++i) {
            if (num[i] > maxNum) {
                maxNum = num[i];
                maxCnt = 1;
            } else if (num[i] == maxNum) {
                maxCnt++;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (num[i] < maxNum) {
                oCnt += num[i];
            }
        }
        int delta = (n + 1) * (maxNum - 1) - maxCnt * (maxNum - 1) - oCnt;
        return delta > 0 ? m + delta : m;
    }
};
