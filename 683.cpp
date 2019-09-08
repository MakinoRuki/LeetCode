// 并查集可以到O(n)。
// 开灯时候把i合并到i-1的父亲集合上。
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        set<int> ons;
        ons.clear();
        int n = bulbs.size();
        for (int i = 0; i < n; ++i) {
            if (ons.empty()) {
                ons.insert(bulbs[i]);
            } else {
                auto idx = ons.upper_bound(bulbs[i]);
                if (idx == ons.end()) {
                    auto pre = idx;
                    pre--;
                    if (bulbs[i]-(*pre)-1 == K) return i+1;
                } else if (idx == ons.begin()) {
                    if ((*idx)-bulbs[i]-1 == K) return i + 1;
                } else {
                    auto pre = idx;
                    pre--;
                    if ((*idx)-bulbs[i]-1==K || bulbs[i]-(*pre)-1==K) return i+1;
                }
                ons.insert(bulbs[i]);
            }
        }
        return -1;
    }
};
