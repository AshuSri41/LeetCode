class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];

        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        for (int i = mn; i >= 1; i--) {
            if (mn % i == 0 && mx % i == 0) {
                return i;
            }
        }

        return 0;
    }
};