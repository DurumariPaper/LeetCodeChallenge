class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> result;
        vector<int> ret;
        
        for(int i = 0; i < nums.size() ; i++)
        {
            if(result.find(target - nums[i]) == result.end())
            {
                result[nums[i]] = i; 
            }
            else
            {
                ret = {result[target - nums[i]], i};
                return ret;
            }
        }
        
        return ret;
    }
};