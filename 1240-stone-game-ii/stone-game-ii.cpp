class Solution {
public:
    int dp[101][101];
    vector<int> suffix;
    int n;

    int solve(int i, int M) {
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int total = suffix[i];
        int best = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int opponent = solve(i + X, max(M, X));

            int current = total - opponent;

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            suffix[i] = piles[i] + suffix[i + 1];

        memset(dp, -1, sizeof(dp));

        return solve(0, 1);
    }
};