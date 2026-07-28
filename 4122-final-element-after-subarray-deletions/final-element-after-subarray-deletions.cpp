class Solution {
public:
    int finalElement(vector<int>& nums) {
        int max = 0;
        if(nums[0] > nums[nums.size() - 1]){
            max = nums[0];
        }else{
            max = nums[nums.size() - 1];
        }

        return max;
    }
};