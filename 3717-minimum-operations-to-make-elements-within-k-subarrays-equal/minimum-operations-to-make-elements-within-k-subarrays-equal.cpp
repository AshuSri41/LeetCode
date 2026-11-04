class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        auto balance = [&]() {
            int target = (x + 1) / 2;

            while (low.size() > target) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < target && !high.empty()) {
                int val = *high.begin();
                high.erase(high.begin());
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }

            balance();
        };

        auto remove = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            balance();
        };

        auto getCost = [&]() -> long long {
            long long median = *low.rbegin();

            return median * (long long)low.size() - sumLow
                 + sumHigh - median * (long long)high.size();
        };

        // Step 1: Calculate costs of all windows.
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        // Step 2: DP
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        // Zero subarrays require zero operations.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Option 1: Skip current element.
                dp[i][j] = dp[i - 1][j];

                // Option 2: Select a window of size x.
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};