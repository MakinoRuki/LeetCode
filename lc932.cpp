class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> ans;
        ans.clear();
        ans.push_back(1);
        while(true) {
            if (ans.size() == N) break;
            vector<int> a1, a2;
            a1.clear();
            a2.clear();
            for (int i = 0; i < ans.size(); ++i) {
                if (ans[i] * 2 - 1 <= N) a1.push_back(ans[i] * 2 - 1);
                if (ans[i] * 2 <= N) a2.push_back(ans[i] * 2);
            }
            ans.clear();
            for (int i = 0; i < a1.size(); ++i) ans.push_back(a1[i]);
            for (int i = 0; i < a2.size(); ++i) ans.push_back(a2[i]);
        }
        return ans;
    }
};
