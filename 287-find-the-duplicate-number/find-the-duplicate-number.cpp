class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int num1 = nums[0];
        int num2 = nums[0];

        do{
            num1 = nums[num1];
            num2 = nums[nums[num2]];
        }
        while(num1 != num2);

        num1 = nums[0];
        while(num1 != num2){
            num1 = nums[num1];
            num2 = nums[num2];
        }
        return num2;
    }
};