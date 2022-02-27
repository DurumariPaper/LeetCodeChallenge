class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length <= 1)
            return 0;
        
        int minValue = prices[0];
        int maxValue = prices[0];
        int result = 0;
        for(int i = 1; i < prices.length; i++)
        {
            if(minValue > prices[i])
            {
                result = Math.max(result, maxValue - minValue);
                minValue = prices[i];
                maxValue = prices[i];
            }
            else
            {
                maxValue = Math.max(maxValue, prices[i]);                
            }
        }
        
        result = Math.max(result, maxValue - minValue);
        
        return result;
        
    }
}