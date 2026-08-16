class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_set<string> seenWords;

        for (int i = 0; i < pattern.length(); ++i) {
            char ch = pattern[i];
            string current_word = words[i];

            if (charToWord.find(ch) != charToWord.end()) {
                if (charToWord[ch] != current_word) {
                    return false;
                }
            } else {
                if (seenWords.find(current_word) != seenWords.end()) {
                    return false;
                }
                charToWord[ch] = current_word;
                seenWords.insert(current_word);
            }
        }

        return true;
    }
};
