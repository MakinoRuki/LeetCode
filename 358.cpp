class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        int n = s.size();
        int maxnum = 0;
        int maxcnt = 0;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }
        priority_queue<pair<int, char> > pq;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0) continue;
            pq.push(make_pair(cnt[i], i + 'a'));
        }
        string res="";
        int tot=n;
        while(!pq.empty()) {
            vector<pair<int, int>> tmp;
            for (int i = 0; i < min(tot, k); ++i) {
                if (pq.empty()) return "";
                auto top = pq.top();
                pq.pop();
                res.push_back(top.second);
                top.first--;
                if (top.first) tmp.push_back(top);
            }
            tot -= min(tot, k);
            for (int i = 0; i < tmp.size(); ++i) {
                pq.push(tmp[i]);
            }
        }
        return res;
    }
};
