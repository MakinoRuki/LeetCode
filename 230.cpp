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
    int find(TreeNode* root, int & k) {
        if (root) {
            int val = find(root->left, k);
            if (k == 0) return val;
            k--;
            if (k == 0) return root->val;
            return find(root->right, k);
        }
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
};
