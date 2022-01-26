class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int low = 0;
        int high = n - 1;
        vector<int> result;
        //find index lower than target
        while(low <= high)
        {
           // int mid = (low + high) / 2;
            if(target == numbers[low] + numbers[high])
            {
                result.push_back(low + 1);
                result.push_back(high + 1);
                break;
            }
            else if(target < numbers[low] + numbers[high])
            {
                high--;
            }
            else
            {
                low++;
            }
                
        }
        
        return result;
    }
};