class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int count = 0;

        for(int num : nums){
            count = count + num;
            res.push_back(count);
        }

        return res;
        

    }
};