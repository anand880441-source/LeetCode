class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        deque<int> res;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                res.push_front(nums[i]);
            }else{
                res.push_back(nums[i]);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};