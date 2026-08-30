class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int currMax = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currMax++;
                if (currMax > max) {
                    max = currMax;
                }
            } else {
                currMax = 0;
            }
        }
        return max;
    }
};