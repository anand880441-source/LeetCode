class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ashe = 0;

        for (int i = 0; i < timeSeries.size(); i++) {
            if (i != timeSeries.size() - 1) {
                int attack = timeSeries[i + 1] - timeSeries[i];
                if (attack >= duration) {
                    ashe = ashe + duration;
                } else {
                    ashe += timeSeries[i + 1] - timeSeries[i];
                }
            } else {
                ashe = ashe + duration;
            }
        }
        return ashe;
    }
};