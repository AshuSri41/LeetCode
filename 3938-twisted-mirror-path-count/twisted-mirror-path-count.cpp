class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> R(m + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> D(m + 1, vector<long long>(n + 1, 0));

        // Starting at (0,0), empty cell: treat as one way to be here
        R[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == m - 1 && j == n - 1) continue;
                long long r = R[i][j] % MOD, d = D[i][j] % MOD;
                if (grid[i][j] == 0) {
                    long long t = (r + d) % MOD;
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + t) % MOD;
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + t) % MOD;
                } else {
                    // entered moving right -> deflect down
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + r) % MOD;
                    // entered moving down -> deflect right
                    if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + d) % MOD;
                }
            }
        }
        return (R[m - 1][n - 1] + D[m - 1][n - 1]) % MOD;
    }
};