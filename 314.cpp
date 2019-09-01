/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;
map<int, vector<int> > res;
class Solution {
public:
    vector<vector<int> > ans;
    void bfs(TreeNode* root) {
        if (!root) return;
        queue<pair<TreeNode*, int> > Q;
        Q.push(make_pair(root, 0));
        while(!Q.empty()) {
            pair<TreeNode*, int> cur = Q.front();
            Q.pop();
            int col = cur.second;
            TreeNode* node = cur.first;
            res[col].push_back(node->val);
            if (node->left) {
                Q.push(make_pair(node->left, col - 1));
            }
            if (node->right) {
                Q.push(make_pair(node->right, col + 1));
            }
        }
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        ans.clear();
        res.clear();
        bfs(root);
        for (map<int, vector<int> >::iterator itr = res.begin(); itr != res.end(); ++itr) {
            ans.push_back(itr->second);
        }
        return ans;
    }
};
