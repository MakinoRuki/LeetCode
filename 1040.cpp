// 最小就是枚举终点i，然后全部聚集到[i-n+1, i];
// 最大就是每次把最边缘的移动到最靠近它的可以放的位置。
class Solution {
public:
    int n;
    vector<int> numMovesStonesII(vector<int>& stones) {
        n = stones.size();
        sort(stones.begin(), stones.end());
        int maxs = max(stones[n-1]-stones[1]-(n-2), stones[n-2]-stones[0]-(n-2));
        int mins = INT_MAX;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while(j <= i && stones[i]-stones[j]+1 > n) {
                j++;
            }
            if (i-j+1 == n-1 && stones[i]-stones[j]+1 == n-1) {
                mins = min(mins, 2);
            } else {
                mins = min(mins, n - (i-j+1));
            }
        }
        return {mins, maxs};
    }
};
