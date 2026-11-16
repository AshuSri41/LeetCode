class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long even = 1, odd = 0; // counts of prefix parities (empty prefix is even)
        long long result = 0;
        int parity = 0;

        for (int x : arr) {
            parity = (parity + x) & 1;
            if (parity) {
                // current prefix is odd -> pair with earlier even prefixes
                result += even;
                odd++;
            } else {
                // current prefix is even -> pair with earlier odd prefixes
                result += odd;
                even++;
            }
            result %= MOD;
        }
        return (int)result;
    }
};