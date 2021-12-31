class Solution {
public:
    const int invalid = -2;
    const int minus = -1;
    
    int myAtoi(string s) {
        int sign = 1;
        int result = 0;        
        int index = 0;
        int n = s.length();
        
        
        while (index < n && s[index] == ' ') { 
            index++; 
        }
        
        if (index < n && s[index] == '+') {
            sign = 1;
            index++;
        } else if (index < n && s[index] == '-') {
            sign = -1;
            index++;
        }
        
        
         while (index < n && isdigit(s[index])) {
            int digit = s[index] - '0';  
             
                        // Check overflow and underflow conditions. 
            if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) { 
                // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.    
                return sign == 1 ? INT_MAX : INT_MIN;
            }
             
            result = 10 * result + digit;
            index++;
        }
        
        return sign * result;
    }
    
};