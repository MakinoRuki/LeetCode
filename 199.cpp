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
    void dfs(TreeNode* root, int lv, vector<int>& ans) {
        if (!root) return;
        if (lv >= ans.size()) ans.push_back(root->val);
        dfs(root->right, lv + 1, ans);
        dfs(root->left, lv + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        dfs(root, 0, ans);
        return ans;
    }
};
