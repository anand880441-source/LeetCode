class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int len = nums.size();

        for(int i = 0; i<len; i++){
            int start = nums[i];

            while (i + 1 < len && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            if (start == nums[i]) {
                res.push_back(to_string(start));
            } else {
                res.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }
        return res;
    }
};