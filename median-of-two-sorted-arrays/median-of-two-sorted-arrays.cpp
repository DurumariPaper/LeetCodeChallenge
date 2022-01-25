class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> result;
        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        
        while(i != n && j != m)
        {
            if(nums1[i] < nums2[j])
            {
                result.push_back(nums1[i++]);
            }
            else
            {
                result.push_back(nums2[j++]);
            }
        }        
        
        while(i != n)
        {
            result.push_back(nums1[i++]);
        }
        while(j != m)
        {
            result.push_back(nums2[j++]);
        }
        
        int data = n + m;
        if(data % 2 == 1)
        {
            return result[data / 2];
        }
        else
        {
            return (result[data / 2 - 1] + result[data / 2]) / 2.0;
        }
        
        
    }
};