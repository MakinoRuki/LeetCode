class Solution {
public:
    vector<int> sum;
    int n;
    Solution(vector<int>& w) {
        n = w.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0) sum.push_back(w[i]);
            else sum.push_back(sum.back() + w[i]);
        }
    }
    
    int pickIndex() {
        int pos = rand() % sum.back();
        int idx = upper_bound(sum.begin(), sum.end(), pos) - sum.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
