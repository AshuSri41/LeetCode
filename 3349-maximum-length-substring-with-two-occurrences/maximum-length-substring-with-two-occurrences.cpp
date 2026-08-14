class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            int freq[26] = {0};

            for (int j = i; j < s.length(); j++) {

                freq[s[j] - 'a']++;

                if (freq[s[j] - 'a'] > 2)
                    break;

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};