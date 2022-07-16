class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        
        int carry = 1;
        for(int i = 0; i < digits.size(); i++)
        {
            if(carry == 0)
                break;
            int sum = digits[i] + carry;
            if(sum >= 10)
                carry = 1;
            else
                carry = 0;
            
            digits[i] = sum % 10;        
        }
        
        if(carry == 1)
            digits.push_back(carry);
        
        reverse(digits.begin(), digits.end());
        return digits;
    }
};