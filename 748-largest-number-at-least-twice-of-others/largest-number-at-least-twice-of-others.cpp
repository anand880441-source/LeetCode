class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.empty()) return -1;

        int maxVal = *max_element(nums.begin(), nums.end());
        int maxIndex = -1;

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == maxVal) {
                maxIndex = i; 
            } else if (nums[i] * 2 > maxVal) {
                return -1;
            }
        }
        
        return maxIndex;
    }
};
