class Solution {
public:
    int smallestRangeI(std::vector<int>& nums, int k) {
        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());

        return max(0, max_val - min_val - 2 * k);
    }
};
