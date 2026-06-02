class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> stable_indices;
        
        for (int i = 1; i < height.size(); ++i) {
            if (height[i - 1] > threshold) {
                stable_indices.push_back(i);
            }
        }
        
        return stable_indices;
    }
};