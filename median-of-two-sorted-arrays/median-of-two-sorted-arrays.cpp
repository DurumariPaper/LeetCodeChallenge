class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        for( int num : nums2)
        {
            nums1.push_back(num);
        }
        sort(nums1.begin(), nums1.end());
        return (size % 2 == 1) ? nums1[size/2] : ((nums1[size/2] + nums1[size/2 - 1]) / 2.f);
    }
};