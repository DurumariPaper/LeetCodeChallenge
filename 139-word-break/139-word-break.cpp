class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        set<string> wordSet(wordDict.begin(), wordDict.end());
        
        dp[0] = true;
        
        for(int i = 1; i <= s.length() ; i++)
        {            
            for(int j = 0; j < i ; j++ )
            {
                if(dp[j] and wordSet.find(s.substr(j,i -j)) != wordSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
            
        }
        return dp[s.length()];
    }
};