class Solution {
public:
    vector<string> ans;

    bool valid(string s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') cnt++;
            else cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }

    void solve(string s, int n) {
        if (s.size() == 2 * n) {
            if (valid(s)) ans.push_back(s);
            return;
        }

        solve(s + "(", n);
        solve(s + ")", n);
    }

    vector<string> generateParenthesis(int n) {
        solve("", n);
        return ans;
    }
};