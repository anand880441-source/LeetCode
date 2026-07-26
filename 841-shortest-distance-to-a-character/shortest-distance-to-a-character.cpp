class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> result(n);
        
        int lastSeenC = -10000; 

        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                lastSeenC = i;
            }
            result[i] = i - lastSeenC;
        }

        lastSeenC = 20000; 

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                lastSeenC = i;
            }
            result[i] = min(result[i], lastSeenC - i);
        }

        return result;
    }
};
