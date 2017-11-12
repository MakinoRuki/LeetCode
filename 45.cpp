class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int steps = 0;
        vector<int> dis(n, 0);
        dis[0] = 0;
        for (int i = 0; i < n; ++i) {
            while(dis[steps] < i) {
                steps++;
            }
            dis[steps + 1] = max(dis[steps + 1], nums[i] + i);
            if (dis[steps] >= n - 1) return steps;
        }
    }
};
