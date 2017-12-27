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
    void dfs(TreeNode* root, double target, vector<int>& ans, int k) {
        if (!root) return;
        if (root->left) {
            dfs(root->left, target, ans, k);
        }
        if (ans.size() == k) {
            if (fabs(ans[0] - target) < fabs(root->val - target)) {
                return;
            } else {
                reverse(ans.begin(), ans.end());
                ans.pop_back();
                reverse(ans.begin(), ans.end());
            }
        }
        ans.push_back(root->val);
        dfs(root->right, target, ans, k);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        ans.clear();
        dfs(root, target, ans, k);
        return ans;
    }
};
