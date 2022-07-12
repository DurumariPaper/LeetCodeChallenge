class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        
        string word = "";
        reverse(s.begin(),s.end());
        for(char c : s)
        {
            switch(c)
            {
            case '-':
                break;
            default:
                word += toupper(c);
                if(word.size() == k)
                {
                    if(result.size() != 0)
                        result += '-';
                    result += word;
                    word = "";
                }
                break;
            }
        }
        
        if(word.size() != 0)
        {
            if(result.size() != 0)
                result += '-';
            result += word;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};