class Solution {
public:
    int findGCD(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int maxValue, minValue;
        maxValue = minValue = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < minValue)
                minValue = nums[i];
            if(nums[i] > maxValue)
                maxValue = nums[i];
        }
        
        return gcd(minValue, maxValue);
    }
};