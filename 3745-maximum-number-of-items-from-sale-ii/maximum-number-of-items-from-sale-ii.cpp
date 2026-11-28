
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mx = 0;
        int minPrice = INT_MAX;

        vector<int> freq(n + 1, 0);

        // Count frequencies of each factor
        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            freq[factor]++;
            mx = max(mx, factor);
            minPrice = min(minPrice, price);
        }

        // Calculate number of items divisible by each factor
        for (int i = 1; i <= mx; i++) {
            for (int j = 2 * i; j <= mx; j += i) {
                freq[i] += freq[j];
            }
        }

        // Sort items by price
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remaining = budget;

        // Greedily purchase items that provide free copies
        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            // Two cheapest purchases are better or equal
            if (price >= 2LL * minPrice)
                break;

            // Exclude the item itself
            int gain = freq[factor] - 1;

            if (gain <= 0)
                continue;

            // Each purchase gives 2 total items
            long long take = min((long long)gain,
                                 remaining / price);

            ans += 2 * take;
            remaining -= take * price;
        }

        // Spend remaining budget on the cheapest item
        ans += remaining / minPrice;

        return (int)ans;
    }
};
