class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) 
            return 0;
        
        int maxValue = nums[0];
        int minValue = nums[0];
        int result = maxValue;
        
        for(int i = 1; i < nums.size() ; i++)
        {
            int current = nums[i];
            auto value = minmax({maxValue * current, minValue * current, current});
            minValue = value.first;
            maxValue = value.second;
            result = max(result, maxValue);
        }
        
        return result;
    }
};