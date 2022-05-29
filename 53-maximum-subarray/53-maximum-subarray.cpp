class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currentArray = nums[0];
        int maxArray = nums[0];
        
        for(int i = 1 ; i < nums.size(); i++)
        {
            int num = nums[i];
            currentArray = max(num, currentArray + num);
            maxArray = max(maxArray, currentArray);            
        }
        
        return maxArray;
    }
};