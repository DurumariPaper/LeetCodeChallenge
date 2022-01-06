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