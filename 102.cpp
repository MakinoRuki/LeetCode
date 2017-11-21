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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*>q[2];
        int now = 0;
        vector<vector<int> > ans;
        ans.clear();
        if (!root) return ans;
        q[now].push_back(root);
        while(true) {
            if (q[now].size() == 0) break;
            vector<int> tmp;
            tmp.clear();
            for (int i = 0; i < q[now].size(); ++i) {
                TreeNode* cur = q[now][i];
                tmp.push_back(cur->val);
                if (cur->left) q[now^1].push_back(cur->left);
                if (cur->right) q[now^1].push_back(cur->right);
            }
            q[now].clear();
            now ^= 1;
            ans.push_back(tmp);
        }
        return ans;
    }
};
