class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> unique;

        for(int i = 0; i<sentence.size(); i++){
            unique.insert(sentence[i]);
        }

        return unique.size() == 26;
    }
};