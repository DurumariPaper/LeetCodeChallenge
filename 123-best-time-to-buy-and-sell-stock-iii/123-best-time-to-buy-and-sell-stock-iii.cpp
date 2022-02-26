class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        const int size = prices.size();
        
        vector<int> left(size, 0);
        vector<int> right(size, 0);
        
        int maxValue = prices[0];
        int minValue = prices[0];
        int result = 0;
        for(int i = 0; i < size; i++)
        {
            if(minValue > prices[i])
            {
                minValue = prices[i];
                maxValue = prices[i];
                left[i] = result;
            }
            else
            {
                maxValue = max(maxValue, prices[i]);
                result = max(result, maxValue - minValue);
                left[i] = result;
            }
        }
        
        maxValue = prices[size - 1];
        minValue = prices[size - 1];
        result = 0;
        for(int i = size - 1; i >= 0; i--)
        {
            if(maxValue < prices[i])
            {
                minValue = prices[i];
                maxValue = prices[i];
                right[i] = result;
            }
            else
            {
                minValue = min(minValue, prices[i]);
                result = max(result, maxValue - minValue);
                right[i] = result;
            }
        }
        
        result = 0;
        for(int i = 0 ; i < size - 1; i++)
        {
            result = max(result, left[i] + right[i+1]);
        }
        result = max(result,left[size-1]);
        
        return result;
    }
    
 
};