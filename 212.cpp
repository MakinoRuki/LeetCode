class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    struct node {
        bool ok;
        node* next[26];
        node() : ok(false) {
            for (int i = 0; i < 26; ++i) {
                next[i] = NULL;
            }
        }
    };
    void insert(node* root, string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (!root->next[s[i]-'a']) {
                root->next[s[i]-'a'] = new node();
            }
            root = root->next[s[i]-'a'];
        }
        root->ok = true;
    }
    void dfs(node* root, int i, int j, vector<vector<char>>& board, string& tmp, unordered_set<string>& res, bool* vis) {
        if (root->ok) {
            res.insert(tmp);
        }
        int m = board[0].size();
        vis[i*m+j] = true;
        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
                if (root->next[board[ni][nj]-'a'] && !vis[ni*m+nj]) {
                    tmp.push_back(board[ni][nj]);
                    dfs(root->next[board[ni][nj]-'a'], ni, nj, board, tmp, res, vis);
                    tmp.pop_back();
                }
            }
        }
        vis[i*m+j] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        if (!n) return {};
        int m = board[0].size();
        node* root = new node();
        for (int i = 0; i < words.size(); ++i) {
            insert(root, words[i]);
        }
        unordered_set<string> res;
        bool vis[n*m+m+2];
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (root->next[board[i][j] - 'a']) {
                    string tmp="";
                    tmp.push_back(board[i][j]);
                    dfs(root->next[board[i][j]-'a'], i, j, board, tmp, res, vis);
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
