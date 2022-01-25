class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> result;
        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        
        if(n+m == 0)
            return 0;
        
        int data = n + m;
        int count = data / 2;
            
        int index = 0;
        while(i != n && j != m && count >= index)
        {
            if(nums1[i] < nums2[j])
            {
                result.push_back(nums1[i++]);
            }
            else
            {
                result.push_back(nums2[j++]);
            }
            index++;
        }        
        
        while(count >= index)
        {
            while(i != n)
            {
                result.push_back(nums1[i++]);
                index++;
            }
            while(j != m)
            {
                result.push_back(nums2[j++]);
                index++;
            }
            
        }
        
        
        if(data % 2 == 1)
        {
            return result[count];
        }
        else
        {
            return (result[count - 1] + result[count]) / 2.0;
        }
        
        
    }
};