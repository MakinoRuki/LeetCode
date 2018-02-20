/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  public:
    TreeNode* cur;
    queue<TreeNode*> q;
    bool isleft;
    BSTIterator(TreeNode* root, bool left) {
        cur = root;
        isleft = left;
        q.push(root);
        if (isleft) {
            while(root->left) {
                q.push(root->left);
                root = root->left;
            }
        } else {
            while(root->right) {
                q.push(root->right);
                root = root->right;
            }
        }
    }
    int getNext() {
        if (q.empty()) {
            return INT_MIN;
        }
        TreeNode* top = q.front();
        if (isleft) {
            q.push(top->right);
            TreeNode* cur = top->right;
            while(cur->left) {
                q.push(cur->left);
                cur = cur->left;
            }
        } else {
            q.push(top->left);
            TreeNode* cur = top->left;
            while(cur->right) {
                q.push(cur->right);
                cur = cur->right;
            }
        }
        return top->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator litr(root, 1);
        BSTIterator ritr(root, 0);
        int lv = litr.getNext();
        int rv = ritr.getNext();
        while(true) {
            if (lv == INT_MIN) return false;
            if (rv == INT_MIN) return false;
            if (lv + rv == k) return true;
            else if (lv + rv < k) {
                lv = litr.getNext();
            } else {
                rv = ritr.getNext();
            }
        }
        return false;
    }
};
