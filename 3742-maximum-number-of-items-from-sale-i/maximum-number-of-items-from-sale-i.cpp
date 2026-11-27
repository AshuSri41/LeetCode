
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        for (auto& item : items) {
            minPrice = min(minPrice, item[1]);
        }

        // dp[j] = maximum copies from first purchases
        // using at most j budget
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            // Count all items divisible by this factor.
            // Includes the current item itself.
            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (items[j][0] % factor == 0) {
                    cnt++;
                }
            }

            // 0/1 Knapsack: buy the first copy of item i
            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + cnt);
            }
        }

        int ans = 0;

        // Spend remaining budget on the cheapest item
        for (int j = 0; j <= budget; j++) {
            int remaining = budget - j;

            ans = max(ans, dp[j] + remaining / minPrice);
        }

        return ans;
    }
};
