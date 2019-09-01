class Solution {
public:
    int longestSubstring(string s, int k) {
        int num[26];
        int n = s.size();
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            num[s[i] - 'a']++;
        }
        for (int i = 0; i < n; ++i) {
            if (num[s[i]-'a'] < k) {
                pos.push_back(i);
            }
        }
        if (pos.empty()) return s.size();
        int pre = 0;
        int res= 0;
        for (int i = 0; i < pos.size(); ++i) {
            int p = pos[i];
            if (p - pre >= k) {
                res =  max(res, longestSubstring(s.substr(pre, p-pre), k));
            }
            pre = p+1;
        }
        if (n - pre >= k) {
            res=max(res, longestSubstring(s.substr(pre), k));
        }
        return res;
    }
};
