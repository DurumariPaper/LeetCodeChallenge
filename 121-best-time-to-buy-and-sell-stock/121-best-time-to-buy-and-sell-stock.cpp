class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        int result = 0;
        int minValue = prices[0];
        int maxValue = prices[0];
        
        for(int i = 1; i < prices.size() ; i++)
        {
            if(minValue > prices[i])
            {
                minValue = prices[i];
                maxValue = prices[i];
                continue;
            }
            maxValue = max(maxValue, prices[i]);
            result = max(result, maxValue - minValue);            
        }
        
        return result;      
    }
};