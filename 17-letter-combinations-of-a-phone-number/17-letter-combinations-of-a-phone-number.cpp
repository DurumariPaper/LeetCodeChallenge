class Solution {
     vector<vector<char>> map = {{},{},{'a','b','c'}, {'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r', 's'},{'t','u','v'},{'w','x','y','z'}};        
    vector<string> output;
public:
    vector<string> letterCombinations(string digits) {
       
        
        string str;
        if(digits != "")
            makeOutput(digits, str, 0);
        
        return output;
    }
    
    void makeOutput(string& digits, string& result, int index)
    {   
        if(index == digits.size())
        {
            output.push_back(result);
            return;
        }
        
        int digit = digits[index] - '0';
        
        
        for(int i = 0; i < map[digit].size(); i++)
        {
            result.push_back(map[digit][i]);
            makeOutput(digits, result, index + 1);   
            result.pop_back();
        }
        
    }
};