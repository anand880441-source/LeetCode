class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> anagram;

        for(string& s: strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            anagram[sorted].push_back(s);
        }

        vector<vector<string>> res;
        for(auto& pair : anagram){
            res.push_back(pair.second);
        }
        return res;
    }
};