class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = mn; i <= mx; i++) {
            bool found = false;

            for (int x : nums) {
                if (x == i) {
                    found = true;
                    break;
                }
            }

            if (!found)
                ans.push_back(i);
        }

        return ans;
    }
};