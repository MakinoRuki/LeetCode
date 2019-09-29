struct node {
    vector<int> ids;
    node* next[27];
    node() {
        ids.clear();
        for (int i = 0; i < 27; ++i) {
            next[i] = NULL;
        }
    }
};
class AutocompleteSystem {
 public:
    node* root;
    vector<string> ss;
    vector<int> tms;
    node* cur;
    string curs;
    bool fail;
    void insert(int id, string& s) {
        node* tmp = root;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (!tmp->next[26]) tmp->next[26] = new node();
                tmp = tmp->next[26];
            } else {
                if (!tmp->next[s[i]-'a']) tmp->next[s[i]-'a'] = new node();
                tmp = tmp->next[s[i]-'a'];
            }
            tmp->ids.push_back(id);
        }
        fail=false;
    }
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) : ss(sentences), tms(times) {
        root = new node();
        cur = root;
        curs.clear();
        for (int i = 0; i < sentences.size(); ++i) {
            insert(i, sentences[i]);
        }
    }
    vector<string> input(char c) {
        set<pair<int, string>> rk;
        vector<string> ans;
        if (c == '#') {
            int found=-1;
            auto lists = cur->ids;
            for (int i = 0; i < lists.size(); ++i) {
                if (ss[lists[i]] == curs) {
                    found = lists[i];
                }
            }
            if (found >= 0) {
                tms[found]++;
            } else {
                ss.push_back(curs);
                tms.push_back(1);
                insert(ss.size()-1, curs);
            }
            cur = root;
            curs.clear();
            fail = false;
        } else {
            curs.push_back(c);
            if (fail) return {};
            if (c == ' ') {
                if (!cur->next[26]) {
                    fail=true;
                    return {};
                } else {
                    cur=cur->next[26];
                }
            } else {
                if (!cur->next[c-'a']) {
                    fail = true;
                    return {};
                }
                cur=cur->next[c-'a'];
            }
            auto lists = cur->ids;
            if (lists.empty()) return {};
            for (int i = 0; i < lists.size(); ++i) {
                rk.insert(make_pair(-tms[lists[i]], ss[lists[i]]));
            }
        }
        ans.clear();
        while(ans.size() < 3 && !rk.empty()) {
            auto top = *rk.begin();
            rk.erase(top);
            ans.push_back(top.second);
        }
        return ans;
    }
 private:
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
