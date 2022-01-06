class Solution {
public:
    int trap(vector<int>& height) 
    {
        int result = 0;
        int size = height.size();
        
        if(size <= 2)
            return 0;
    
        vector<int> leftMax(size), rightMax(size);
        leftMax[0] = height[0];
        rightMax[size-1] = height[size-1];
        for(int i = 1; i < size; i++)
        {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        
        for(int i = size - 2; i >= 0; i--)
        {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }
        
        for(int i = 1; i < size - 1; i++)
        {
            result += min(leftMax[i], rightMax[i]) - height[i];
        }
        return result;
    }
};

/*
int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}
*/