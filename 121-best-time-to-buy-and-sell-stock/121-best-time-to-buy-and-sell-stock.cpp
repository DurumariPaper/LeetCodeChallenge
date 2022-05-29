class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = INT_MAX;
        int maxValue = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < left)
                left = prices[i];
            else if(prices[i] - left > maxValue)
                maxValue = prices[i] - left;
        }
        
        return maxValue;
    }
};