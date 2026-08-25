class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int x = k;

        while (true) {
            if (find(nums.begin(), nums.end(), x) == nums.end()) {
                return x;
            }

            x += k;
        }
    }
};