
class Solution {
public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
        long long k = (long long)k1 + k2, sum = 0;
        vector<int> d(a.size());

        for (int i = 0; i < a.size(); i++) {
            d[i] = abs(a[i] - b[i]);
            sum += d[i];
        }

        if (k >= sum) return 0;

        int l = 0, r = 100000;
        while (l < r) {
            int m = (l + r) / 2;
            long long need = 0;
            for (int x : d) need += max(0, x - m);
            if (need <= k) r = m;
            else l = m + 1;
        }

        long long ans = 0;
        for (int x : d) {
            int y = max(x, l);
            ans += 1LL * min(x, l) * min(x, l);
        }

        long long used = 0;
        for (int x : d) used += max(0, x - l);
        long long rem = k - used;

        ans = 0;
        for (int x : d) {
            int y = max(0, x - l);
            ans += 1LL * min(x, l) * min(x, l);
        }
        return ans - rem * (2LL * l - 1);
    }
};
