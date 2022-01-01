class Solution {
    int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};    
    string symbols[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
public:
    string intToRoman(int num) {        
        string result;
        int index;
        
         for (int i = 0; num > 0; i++) {
            while (values[i] <= num) {
                num -= values[i];
                result.append(symbols[i]);
            }
        }
        
        return result;
    }
};