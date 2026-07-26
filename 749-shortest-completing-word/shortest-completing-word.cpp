class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> targetCount(26, 0);
        for (char c : licensePlate) {
            if (isalpha(c)) {
                targetCount[tolower(c) - 'a']++;
            }
        }

        string result = "";

        for (const string& word : words) {
            if (!result.empty() && word.length() >= result.length()) {
                continue;
            }

            vector<int> wordCount(26, 0);
            for (char c : word) {
                wordCount[c - 'a']++;
            }

            bool isMatch = true;
            for (int i = 0; i < 26; ++i) {
                if (wordCount[i] < targetCount[i]) {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch) {
                result = word;
            }
        }

        return result;
    }
};
