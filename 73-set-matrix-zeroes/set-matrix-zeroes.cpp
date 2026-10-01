class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Make a copy of the original matrix
        vector<vector<int>> temp = matrix;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If original element was 0
                if (temp[i][j] == 0) {

                    // Make entire row 0
                    for (int k = 0; k < n; k++) {
                        matrix[i][k] = 0;
                    }

                    // Make entire column 0
                    for (int k = 0; k < m; k++) {
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};