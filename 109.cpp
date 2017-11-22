/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* cur;
    TreeNode* dfs (int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* left = dfs(start, mid - 1);
        TreeNode* root = new TreeNode(cur->val);
        root->left = left;
        cur = cur->next;
        TreeNode* right = dfs(mid + 1, end);
        root->right = right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        for (cur = head; cur; cur = cur->next) {
            size++;
        }
        cur = head;
        return dfs(0, size - 1);
    }
};
