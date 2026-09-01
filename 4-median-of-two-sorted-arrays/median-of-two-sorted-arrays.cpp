class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        int i = 0;
        int j = 0;

        while (i != nums1.size() && j != nums2.size()) {
            if (nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                res.push_back(nums2[j]);
                i++;
                j++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }

        while (i != nums1.size()) {
            res.push_back(nums1[i]);
            i++;
        }

        while (j != nums2.size()) {
            res.push_back(nums2[j]);
            j++;
        }

        int sizeOfres = res.size();
        if (sizeOfres % 2 == 1) {
            return res[sizeOfres / 2];
        } else {
            int mid = sizeOfres / 2;
            return (res[mid - 1] + res[mid]) / 2.0;
        }
    }
};