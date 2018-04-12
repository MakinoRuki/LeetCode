class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnts;
        int n = wall.size();
        int ans = wall.size();
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j) {
                sum += wall[i][j];
                cnts[sum]++;
                ans = min(ans, n - cnts[sum]);
            }
        }
        return ans;
    }
};
