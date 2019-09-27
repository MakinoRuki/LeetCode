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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> stk;
        if (root) stk.push_back(root);
        while(stk.size()) {
            auto top = stk.back();
            stk.pop_back();
            ans.push_back(top->val);
            if (top->left) {
                stk.push_back(top->left);
            }
            if (top->right) {
                stk.push_back(top->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
