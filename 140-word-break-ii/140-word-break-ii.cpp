class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       vector<bool> dp(s.length() + 1, false);
        set<string> wordSet(wordDict.begin(), wordDict.end());
        
        vector<vector<string>> result(s.length() + 1);
        
        dp[0] = true;
        result[0].push_back("");
        
        for(int i = 1; i <= s.length() ; i++)
        {            
            for(int j = 0; j < i ; j++ )
            {
                string str = s.substr(j,i -j);
                if(dp[j] and wordSet.find(str) != wordSet.end())
                {
                    for(int k = 0; k < result[j].size(); k++)
                    {
                        string data = result[j][k];
                        if(data != "")
                            data += ' ';
                        data += str;
                        result[i].push_back(data);
                    }
                    dp[i] = true;
                }
            }
            
        }
        return result[s.length()];
    }
};

