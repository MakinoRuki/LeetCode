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
    int ans = 0;
    int dfs(TreeNode* root) {
        if (!root) return 2;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (!l || !r) {
            ans++;
            return 1;
        }
        if (r == 1 || l == 1) {
            return 2;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) ans++;
        return ans;
    }
};
