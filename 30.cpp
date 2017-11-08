class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int l = words[0].size();
        int m = words.size();
        map<string, int> cnt1;
        map<string, int> cnt2;
        vector<int> ans;
        ans.clear();
        for (int i = 0; i < m; ++i) {
            cnt1[words[i]]++;
        }
        for (int i = 0; i < l; ++i) {
            cnt2.clear();
            int k = i;
            int tot = 0;
            for (int j = i; j < n; j += l) {
                string t = s.substr(j, l);
                cnt2[t]++;
                tot++;
                if (cnt2[t] > cnt1[t]) {
                    while(k <= j && cnt2[t] > cnt1[t]) {
                        cnt2[s.substr(k, l)]--;
                        tot--;
                        k += l;
                    }
                }
                if (tot == m) {
                    ans.push_back(j + l - m * l);
                }
            }
        }
        return ans;
    }
};
