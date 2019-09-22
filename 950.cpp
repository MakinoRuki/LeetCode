class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> idx;
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            dq.push_back(i);
        }
        vector<int> res(n, 0);
        while(!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            idx.push_back(u);
            if (!dq.empty()) {
                int v = dq.front();
                dq.pop_front();
                dq.push_back(v);
            }
        }
        for (int i = 0; i < idx.size(); ++i) {
            res[idx[i]] = deck[i];
        }
        return res;
    }
};
