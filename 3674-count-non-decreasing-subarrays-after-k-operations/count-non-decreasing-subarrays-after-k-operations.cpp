class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        struct Seg { long long val; int s, e; };
        deque<Seg> dq;          // front = smallest index
        long long cost = 0, ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            // add nums[l] on the left
            int end = l;
            while (!dq.empty() && dq.front().val <= nums[l]) {
                Seg sg = dq.front();
                dq.pop_front();
                cost += (long long)(nums[l] - sg.val) * (sg.e - sg.s + 1);
                end = sg.e;
            }
            dq.push_front({nums[l], l, end});

            // shrink from the right until the cost fits
            while (cost > k) {
                Seg &back = dq.back();
                cost -= back.val - nums[r];
                --r;
                if (--back.e < back.s) dq.pop_back();
            }

            ans += r - l + 1;
        }
        return ans;
    }
};