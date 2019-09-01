class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i] - 'a']++;
        }
        string res = "";
        unordered_set<char> mm;
        mm.clear();
        for (int i = 0; i < n; ++i) {
            if (mm.find(s[i]) != mm.end()) {
                cnt[s[i] - 'a']--;
                continue;
            }
            while(!res.empty() && s[i] <= res.back()) {
                if (cnt[res.back() - 'a'] > 1) {
                    cnt[res.back() - 'a']--;
                    mm.erase(res.back());
                    res.pop_back();
                } else {
                    break;
                }
            }
            if (mm.find(s[i]) == mm.end()) {
                res.push_back(s[i]);
                mm.insert(s[i]);
            }
        }
        return res;
    }
};
