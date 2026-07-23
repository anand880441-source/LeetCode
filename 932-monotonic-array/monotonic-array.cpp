class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isInc = true;
        bool isDec = true;
        int i = 0;

        while(i < nums.size() - 1) {
            if (nums[i] > nums[i + 1]) {
                isInc = false;
            }
            if (nums[i] < nums[i + 1]) {
                isDec = false;
            }
            i++;
        }

        return isInc || isDec;
    }
};