class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentValue = nums[0];
        int maxValue = nums[0];
        
        for(int i = 1 ; i < nums.size(); i++)
        {
            int num = nums[i];
            currentValue = max(num, currentValue + num);
            maxValue = max(maxValue, currentValue);
            
        }
        return maxValue;
    }
};


/*
    int maxSubArray(vector<int>& nums) {
        const int size = nums.size();
        vector<vector<int>> dp( size , vector<int> (size, 0));
        if(size == 1)
            return nums[0];
        if(size == 0)
            return 0;
        int result = INT_MIN;
        for(int i = 0; i < size; i++)
        {
            dp[i][i] = nums[i];
            result = max(result, dp[i][i]);
            
        }
        for(int gap = 1; gap < size; gap++)
        {
            for(int i = 0; i < size - gap; i++)
            {
                dp[i][i+gap] = dp[i][i+gap-1] + nums[i+gap];
                result = max(result, dp[i][i+gap]);
            }
        }
        return result;
    }
*/