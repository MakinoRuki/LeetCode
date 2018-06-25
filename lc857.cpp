class Solution {
public:
    int n;
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        n = quality.size();
        vector<pair<double, int> > rank;
        rank.clear();
        for (int i = 0; i < n; ++i) {
            rank.push_back(make_pair((double)wage[i] / (double)quality[i], quality[i]));
        }
        sort(rank.begin(), rank.end());
        int totq = 0;
        priority_queue<int> pq;
        double ans = -1;
        for (int i = 0; i < n; ++i) {
            pq.push(rank[i].second);
            totq += rank[i].second;
            if (pq.size() > K) {
                totq -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                double sum = rank[i].first * totq;
                if (ans < 0) ans = sum;
                else ans = min(ans, sum);
            }
        }
        return ans;
    }
};
