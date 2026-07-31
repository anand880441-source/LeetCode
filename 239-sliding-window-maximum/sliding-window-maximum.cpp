class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return {};
        if (k == 1) return nums;

        vector<int> left(n);
        vector<int> right(n);

        left[0] = nums[0];
        right[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            if (i % k == 0) left[i] = nums[i];
            else left[i] = max(left[i - 1], nums[i]);

            int j = n - 1 - i;
            if ((j + 1) % k == 0) right[j] = nums[j];
            else right[j] = max(right[j + 1], nums[j]);
        }

        vector<int> ans(n - k + 1);
        for (int i = 0; i <= n - k; i++) {
            ans[i] = max(right[i], left[i + k - 1]);
        }

        return ans;
    }
};