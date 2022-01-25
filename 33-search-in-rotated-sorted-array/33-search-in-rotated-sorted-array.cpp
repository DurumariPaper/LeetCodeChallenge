class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return -1;
        if(n == 1)
            return (nums[0] == target) ? 0 : -1;
        
        int k = 0;
        for(int i = 1 ; i < n; i++)
        {
            if(nums[i - 1] > nums[i])
            {
                k = i;
                break;
            }
        }
        
        int low = 0;
        int high = n - 1;
        
        if(k != 0)
        {
            if(target < nums[0])
                low = k;
            else
                high = k - 1;
                   
        }

        
        int val = -1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(target == nums[mid])
            {
                val = mid;
                break;
            }
            else if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return val;
        
    }
};