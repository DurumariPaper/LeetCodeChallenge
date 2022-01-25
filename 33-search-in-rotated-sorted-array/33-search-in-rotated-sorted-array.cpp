class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        int val = -1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(target == nums[mid])
                return mid;
            else if(nums[mid] < nums[low])
            {
                if(target <= nums[high] && target > nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;                
            }
            else
            {
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        
        return -1;
        
    }
};