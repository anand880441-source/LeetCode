class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> sortedScores(n);
        
        for (int i = 0; i < n; ++i) {
            sortedScores[i] = {score[i], i};
        }
        
        sort(sortedScores.begin(), sortedScores.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        
        vector<string> answer(n);
        
        for (int rank = 0; rank < n; ++rank) {
            int originalIndex = sortedScores[rank].second;
            if (rank == 0) {
                answer[originalIndex] = "Gold Medal";
            } else if (rank == 1) {
                answer[originalIndex] = "Silver Medal";
            } else if (rank == 2) {
                answer[originalIndex] = "Bronze Medal";
            } else {
                answer[originalIndex] = to_string(rank + 1);
            }
        }
        
        return answer;
    }
};
