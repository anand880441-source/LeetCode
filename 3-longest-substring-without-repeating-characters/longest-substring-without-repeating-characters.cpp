class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;

        int left = 0;
        int maxLen = 0;

        for(int i = 0; i<s.length(); i++){
            char c = s[i];

            if(lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= left){
                left = lastIndex[c] + 1;
            }

            lastIndex[c] = i;
            maxLen = max(maxLen,i - left + 1);

        }
        return maxLen;
    }
};