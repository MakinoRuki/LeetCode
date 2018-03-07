#define N 62
class Solution {
public:
    int pos[N];
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        for (int i = 0; i < n; ++i) {
            pos[row[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            if (row[i] / 2 == row[i + 1] / 2) continue;
            int idx;
            if (row[i] % 2 == 0) idx = pos[row[i] / 2 * 2 + 1];
            else idx = pos[row[i] / 2 * 2];
            ans++;
            swap(row[i + 1], row[idx]);
            pos[row[i + 1]] = i + 1;
            pos[row[idx]] = idx;
        }
        return ans;
    }
};
