class Solution {
public:
    int n;
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        n = stones.size();
        int ub = max(stones[n-1]-stones[1]-n+2, stones[n-2]-stones[0]-n+2);
        int i = 0;
        int lb = n;
        for (int j = 0; j < n; ++j) {
            while(stones[j] - stones[i] >= n) i++;
            if (j-i+1 == n-1 && stones[j]-stones[i]+1==n-1) {
                lb=min(lb,2);
            } else {
                lb=min(lb, n-(j-i+1));
            }
        }
        return {lb, ub};
    }
};
