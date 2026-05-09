class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size() - 1;
        int expected = 0;

        while(first <= last){
            if(nums[first] >= target){
                return first;
            }else if(nums[last] == target){
                return last;
            }else if(nums[last] < target){
                return last + 1;
            }
            first++;
            last--;
        }
        return first;
    }
};