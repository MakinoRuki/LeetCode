/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> pars;
    void getans(TreeNode* cur, TreeNode* no, int dis, vector<int>& ans) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(cur, 0));
        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();
            TreeNode* p = tmp.first;
            int d = tmp.second;
            if (d == dis) {
                ans.push_back(p->val);
            }
            if (d > dis) continue;
            if (p->left && p->left != no) {
                q.push(make_pair(p->left, d + 1));
            }
            if (p->right && p->right != no) {
                q.push(make_pair(p->right, d+1));
            }
        }
    }
    void getpars(TreeNode* cur, TreeNode* par) {
        if (!cur) return;
        pars[cur] = par;
        getpars(cur->left, cur);
        getpars(cur->right, cur);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        getpars(root, NULL);
        vector<int> ans;
        getans(target, NULL, K, ans);
        TreeNode* cur = target;
        for (int i = 1; i <= K; ++i) {
            if (pars[cur] == NULL) break;
            getans(pars[cur], cur, K-i, ans);
            cur = pars[cur];
        }
        return ans;
    }
};
