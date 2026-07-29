class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int res = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            int j = i + 1;
            int k = n - 1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];

                int cDiff = abs(sum - target);

                if(cDiff<diff)
                {
                    res = sum;
                    diff = cDiff;
                }

                int sign = sum-target;

                if(sign<0) j++;
                else k--;
            }
        }

    return res;
    }
};