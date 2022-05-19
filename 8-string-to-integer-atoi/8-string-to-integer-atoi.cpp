class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int result = 0;
        int index = 0;
        int n = s.length();
        
    
        while( index < n && s[index] == ' ')
        {
            index++;
        }
    
        if(index < n)
        {
            if(s[index] == '+'){
                sign = 1;
                index++;
            }
            else if(s[index] == '-'){
                sign = -1;
                index++;
            }
        }
        
        while(index < n && isdigit(s[index])){
            int digit = s[index] - '0';
            
            
            //overflow check
            
            if(result > INT_MAX / 10 ||(result == INT_MAX / 10 && digit > INT_MAX % 10) )
            {
                if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            
            
            result = result * 10 + digit;
            index++;
        }
        
        
        return sign * result;
        
    }
    
    
};