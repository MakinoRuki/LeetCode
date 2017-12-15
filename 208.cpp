class Trie {
public:
    struct node {
        string val;
        node* next[26];
    } tree[1000];
    int top = 0;
    /** Initialize your data structure here. */
    Trie() {
        for (int i = 0; i < 1000; ++i) {
            tree[i].val = "";
            for (int j = 0; j < 26; ++j) {
                tree[i].next[j] = NULL;
            }
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* root = &tree[0];
        for (int i = 0; i < word.size(); ++i) {
            if (root->next[word[i] - '26'] == NULL) {
                root->next[word[i] - '26'] = &tree[++top];
            } else {
                root = root->next[word[i] - '26'];  
            }
        }
        root->val = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* root = &tree[0];
        for (int i = 0; i < word.size(); ++i) {
            if (root->next[word[i] - '26'] == NULL) return false;
            root = root->next[word[i] - '26'];
        }
        if (root->val != word) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* root = &tree[0];
        for (int i = 0; i < prefix.size(); ++i) {
            if (root->next[prefix[i] - '26'] == NULL) return false;
            root = root->next[prefix[i] - '26'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
