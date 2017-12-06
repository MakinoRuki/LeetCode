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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* cur = root;
        TreeNode* preLeft = NULL;
        TreeNode* preRight = NULL;
        while(cur) {
            TreeNode* next = cur->left;
            cur->left = preLeft;
            TreeNode* tmp = cur->right;
            cur->right = preRight;
            preLeft = tmp;
            preRight = cur;
            cur = next;
        }
        return preRight;
    }
};
