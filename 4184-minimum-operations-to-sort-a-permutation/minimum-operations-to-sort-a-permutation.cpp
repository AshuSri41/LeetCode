class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool asc = true, desc = true;
        for (int i = 0; i < n; i++) {
            int nxt = nums[(i + 1) % n];
            if (nxt != (nums[i] + 1) % n) asc = false;
            if (nxt != (nums[i] - 1 + n) % n) desc = false;
        }

        if (asc) {
            int k = nums[0];
            return min((n - k) % n, k + 2);
        }
        if (desc) {
            int s = (nums[0] + 1) % n;
            return 1 + min(s, (n - s) % n);
        }
        return -1;
    }
};