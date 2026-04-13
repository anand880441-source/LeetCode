class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int num : arr) {
            count[num]++;
        }

        unordered_set<int> seen;
        for (auto const& [val, frequency] : count) {
            if (!seen.insert(frequency).second) {
                return false;
            }
        }

        return true;
    }
};
