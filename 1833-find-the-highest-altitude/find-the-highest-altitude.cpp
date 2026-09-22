class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, ans = 0;

        for (int x : gain) {
            alt += x;
            ans = max(ans, alt);
        }

        return ans;
    }
};