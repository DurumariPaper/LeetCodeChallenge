class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int size = nums.size();
        int left = 0;
        int right = 0;
        int maxLength = 0;
        
        if(size <= 1)
            return size;
                
        int prevValue = INT_MIN;
        while(right < size)
        {
            if(prevValue < nums[right])
            {                
                maxLength = max(maxLength, right - left + 1);
            }
            else
            {
                left = right;
            }            
            prevValue = nums[right];
            right++;
        }
        
        return maxLength;
    }
};