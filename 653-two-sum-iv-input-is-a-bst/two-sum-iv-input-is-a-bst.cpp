class Solution {
public:
    unordered_set<int> st;

    bool solve(TreeNode* root, int k) {
        if (root == NULL)
            return false;

        // Check if complement already exists
        if (st.count(k - root->val))
            return true;

        st.insert(root->val);

        return solve(root->left, k) || solve(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return solve(root, k);
    }
};