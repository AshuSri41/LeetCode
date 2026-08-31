class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
         //two pointer swap
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};