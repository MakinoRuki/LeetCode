//  直接记下路径，而不是pre word。
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        unordered_map<string, int> dist;
        q.push(beginWord);
        unordered_map<string, vector<vector<string>>> pre;
        pre[beginWord].push_back({beginWord});
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur == endWord) {
                return pre[cur];
            }
            for (int i = 0; i < cur.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == cur[i]) continue;
                    string t = cur;
                    t[i] = c;
                    if (dict.find(t) == dict.end()) continue;
                    if (dist.find(t) == dist.end() || dist[t] > dist[cur]+1) {
                        dist[t] = dist[cur]+1;
                        q.push(t);
                        pre[t].clear();
                        auto lists = pre[cur];
                        for (auto list : lists) {
                            list.push_back(t);
                            pre[t].push_back(list);
                        }
                    } else if (dist[t] == dist[cur]+1) {
                        auto lists = pre[cur];
                        for (auto list : lists) {
                            list.push_back(t);
                            pre[t].push_back(list);
                        }
                    }
                }
            }
        }
        if (pre.find(endWord) == pre.end()) return {};
        return pre[endWord];
    }
};
