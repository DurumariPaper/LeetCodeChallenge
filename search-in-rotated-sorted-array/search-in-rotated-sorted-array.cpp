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

// 기본 바이너리 서치에서
// 값을 비교한 뒤에, 해당 방향으로 sorting이 되어있는 영역인지 아닌지를 판단해서 분기 영역을 나눈다
// 그럼 한두개의 조건문을 걸어서 해결이 가능하다.
// O(log(n))