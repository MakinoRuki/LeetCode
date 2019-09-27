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
    void flatten(TreeNode* root) {
        TreeNode* head=NULL;
        TreeNode* cur=NULL;
        vector<TreeNode*> stk;
        if (root) {
            stk.push_back(root);
        }
        while(!stk.empty()) {
            auto top = stk.back();
            stk.pop_back();
            if (top->right) {
                stk.push_back(top->right);
            }
            if (top->left) {
                stk.push_back(top->left);
            }
            top->left=NULL;
            if (!head) {
                head=top;
                cur=head;
            } else {
                cur->right=top;
                cur=cur->right;
            }
        }
        if (cur) {
            cur->right=NULL;
        }
        if (root) *root=*head;
    }
};
