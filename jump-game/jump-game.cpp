class Solution
{
    public:
    bool canJump(vector<int>& nums)
    {
        int lastPos = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(i + nums[i] >= lastPos)
            {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};



/*
class Solution {

    unordered_map<int, bool> memo;
    
    public:
    bool canReach(vector<int>& nums, int index)
    {
        if(memo.count(index) != 0)
        {
            return memo[index];
        }
                
        int maxJump = min(nums[index] + index, (int)nums.size() - 1);
        for(int i = index + 1; i <= maxJump; i++)
        {
            if(canReach(nums, i))
            {
                memo[i] = true;
                return memo[i];   
            }                
        }
        
        memo[index] = false;
        return memo[index];
    }
    
    bool canJump(vector<int>& nums) {
        memo[nums.size() - 1] = true;
        return canReach(nums, 0);
    }
};
*/