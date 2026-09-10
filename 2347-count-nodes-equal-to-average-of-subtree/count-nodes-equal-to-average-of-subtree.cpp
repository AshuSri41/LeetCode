/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        int sum = root->val + l.first + r.first;
        int cnt = 1 + l.second + r.second;

        return {sum, cnt};
    }

    int solve(TreeNode* root) {
        if (!root) return 0;

        auto p = dfs(root);

        return (root->val == p.first / p.second)
             + solve(root->left)
             + solve(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        return solve(root);
    }
};