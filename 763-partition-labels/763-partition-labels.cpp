class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {0};
        for(int i = 0 ; i < s.length() ; i++)
        {
            last[s[i] - 'a'] = i;
        }
        
        int j = 0;
        int cutter = 0;
        
        vector<int> result;
        
        for(int i = 0; i < s.length() ; i++)
        {
            j = max(j, last[s[i] - 'a']);
            if(i == j)
            {
                result.push_back(i - cutter + 1);
                cutter = i + 1;
            }
        }
        
        return result;
    }
};