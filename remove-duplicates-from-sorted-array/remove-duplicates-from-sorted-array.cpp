class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        vector<int> data;
        int prev = -101;
        int result = 0;
        int i = 0;
        for(int val : nums)
        {
            if(prev != val)
            {
                prev = val;
                result++;  
                data.push_back(val);
            }
        }
        
        nums = data;
        return result;
    }
};