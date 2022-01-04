class Solution {
public:
    bool isValid(string s) {
        vector<char> check;
        
        for(char c : s)
        {
            switch(c)
            {
            case '(':
            case '[':
            case '{':
                check.push_back(c);
                break;
            case ')':
                {
                    if(check.empty()) 
                        return false;    
                    char val = check.empty() ? '#' : check.back();
                    check.pop_back();
                    if(val != '(')
                        return false;
                    break;
                }
            case ']':
                {
                    if(check.empty()) 
                        return false;    
                    char val = check.empty() ? '#' : check.back();
                    check.pop_back();
                    if(val != '[')
                        return false;
                    break;
                }
            case '}':
                {
                    if(check.empty()) 
                        return false;    
                    char val = check.empty() ? '#' : check.back();
                    check.pop_back();
                    if(val != '{')
                        return false;
                    break;
                }             
            }
        }
        
        return check.empty();
    }
};