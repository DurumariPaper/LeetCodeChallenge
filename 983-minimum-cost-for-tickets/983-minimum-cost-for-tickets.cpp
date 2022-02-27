class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int memo[400];
        for(int i = 0; i < 400; i++)
            memo[i] = 0;
        
        set<int> daySet(days.begin(), days.end());
        
        for(int i = 365; i >= 1; i--)
        {
            if(daySet.count(i) == 0)
            {
                memo[i] = memo[i+1];
                continue;
            }
            memo[i] = min(memo[i+1] + costs[0], memo[i+7] + costs[1]);
            memo[i] = min(memo[i], memo[i+30] + costs[2]);
        }
        
        return memo[1];
    }
    
     
};


/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < amount + 1; i++) {
            for (auto coin: coins) {
                if(i - coin < 0) continue; 
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
*/