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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (key == root->val) {
            if (!root->left) return root->right;
            TreeNode* cur=root->left;
            while(cur->right) {
                cur=cur->right;
            }
            cur->right = root->right;
            return root->left;
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        } else {
            root->right = deleteNode(root->right, key);
            return root;
        }
    }
};
