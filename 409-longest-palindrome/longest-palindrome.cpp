class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        for (char c : s) {
            count[c]++;
        }

        int length = 0;
        bool has_odd = false;

        for (int freq : count) {
            length += (freq / 2) * 2;

            if (freq % 2 != 0) {
                has_odd = true;
            }
        }

        if (has_odd) {
            length += 1;
        }

        return length;
    }
};
