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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            if (!top) break;
            q.push(top->left);
            q.push(top->right);
        }
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top) return false;
        }
        return true;
    }
};
