class Solution {
public:
    // =========== Bottom up from end ==============
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<int> temp(n+1, 350*2);  // Filling with max random
        
        // Edge case end + 1 is 0
        temp.at(n) = 0;
        
        for(int i=n-1; i>=0; i--){
            int day7 = i, day30 = i;
            // Moving pointer past 7 days
            while(day7 < n && days[day7] < days[i]+7) day7++;
            // Moving pointer past 30 days
            while(day30 < n && days[day30] < days[i] + 30) day30++;
            temp[i] = min({ costs[0] + temp[i+1], costs[1] + temp[day7], costs[2] + temp[day30] });
        }
        
        return temp[0];
    }
    /*
    // ============= Bottom up from start ================
        int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<int> temp(n+1, 350*2);  // Filling with max random
        
        // Edge case end + 1 is 0
        temp.at(0) = 0;
        
        for(int i=1; i<n+1 ; i++){
            int day7 = i, day30 = i;
            // Moving pointer past 7 days
            while(day7 > 0 && days[day7-1] > days[i-1]-7) day7--; // We are accessing i-1 coz index start at 0 for 1st element since i start at 1
            // Moving pointer past 30 days
            while(day30 > 0 && days[day30-1] > days[i-1] - 30) day30--;
            temp[i] = min({ costs[0] + temp[i-1], costs[1] + temp[day7], costs[2] + temp[day30] });
            cout<< days[i-1] << " ";
        }
        
        return temp[n];
    }*/
};


/*
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

*/
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