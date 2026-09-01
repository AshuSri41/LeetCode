class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //diagonal swap app
        if (n != m) {
            vector<vector<int>> ans(m, vector<int>(n));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[j][i] = matrix[i][j];
                }
            }

            return ans;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        return matrix;
    }
};