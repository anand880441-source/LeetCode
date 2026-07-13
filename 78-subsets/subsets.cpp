class Solution {
public:
    vector<vector<int>> result;  
    
    void backtrack(vector<int>& nums, vector<int>& path, int start) {
        result.push_back(path);
        
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            
            backtrack(nums, path, i + 1);
            
            path.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(nums, path, 0);
        return result;
    }
};