class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // dp[v] = longest consecutive run ending at value v
        vector<int> dp(1000003, 0);
        int ans = 1;

        for (int x : nums) {
            // Update x+1 first (using the old dp[x]), so the same
            // element is never used for both x and x+1.
            dp[x + 1] = dp[x] + 1;
            dp[x]     = dp[x - 1] + 1;
            ans = max({ans, dp[x], dp[x + 1]});
        }
        return ans;
    }
};