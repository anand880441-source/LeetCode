class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();

        if (n + m != s3.length()) {
            return false;
        }

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        return helper(s1, s2, s3, 0, 0, memo);
    }

    bool helper(string& s1, string& s2, string& s3, int i, int j,
                vector<vector<int>>& memo) {
        if (i == s1.length() && j == s2.length()) {
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j] == 1;
        }

        int k = i + j;

        if (i < s1.length() && s1[i] == s3[k]) {
            if (helper(s1, s2, s3, i + 1, j, memo)) {
                memo[i][j] = 1;
                return true;
            }
        }

        if (j < s2.length() && s2[j] == s3[k]) {
            if (helper(s1, s2, s3, i, j + 1, memo)) {
                memo[i][j] = 1;
                return true;
            }
        }

        memo[i][j] = 0;
        return false;
    }
};