class Solution {
 public int maxProfit(int k, int[] prices) {
     int n = prices.length;
     if( n <= 1)
         return 0;
     
     int[][] buy = new int[n][k+1];
     int[][] sell = new int[n][k+1];
     
     for(int i = 0 ; i < n; i++)
     {
         buy[i][0] = sell[i][0] = 0;
     }
     
     for(int i = 1 ; i <= k; i++)
     {
         buy[0][i] = -prices[0];
         sell[0][i] = 0;
     }
     
     for(int i  = 1; i < n ; i++)
     {
         for(int j = 1; j <= k; j++)
         {
             buy[i][j] = Math.max(buy[i-1][j], sell[i-1][j-1] - prices[i]);
             sell[i][j] = Math.max(sell[i-1][j], buy[i-1][j] + prices[i]);
         }
     }
     
     return sell[n-1][k];
 }
}



/*
class Solution {
 public int maxProfit(int k, int[] prices) {
    int n = prices.length;
    if (n <= 1) return 0;

    
    int[][] buy = new int[n][k+1];
    // buy[i][j] = profit on day i with j transaction, 
    // when we are in buy state (holding a stock) on day i
    
    int[][] sell = new int[n][k+1];
    // sell[i][j] = profit on day i with j transaction, 
    // when we are in sell state (holding no stock) on day i
    
    // when # of transaction = 0, we cannot make any profit on any day
    for (int i = 0; i < n; ++i) { // k == 0
        buy[i][0] = sell[i][0] = 0;
    }
    
    // on day 0, for all non-zero # of transaction
    for (int j = 1; j <= k; ++j) {
        buy[0][j] = -prices[0]; // we can make a purchase on day 0
        sell[0][j] = 0; // but we cannot sell on day 0
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            buy[i][j] = Math.max(buy[i-1][j], sell[i-1][j-1] - prices[i]);
            // we can either remian in buy state by doing nothing on day i (remain idle)
            // but for that we'll need to be in buy state on day i-1, with same no. of transations
            
            // or we can trasition into buy state by making a purchase
            // if we make a purchase on ith day and initiate jth transaction, then we must 
            // get profit from completion of (j-1)th trasaction on (i-1)th day
            
            
            sell[i][j] = Math.max(sell[i-1][j], buy[i-1][j] + prices[i]);
            // we can either remian in sell state by doing nothing on day i (remain idle)
            // but for that we'll need to be in sell state on day i-1, with same no. of transations
            
            // or we can trasition into sell state by making a sell
            // if we make a sell on ith day and finish jth transaction, then we must 
            // get profit from purchase of jth trasaction on (i-1)th day
        }
    }
    
    return sell[n-1][k];
}
}
*/