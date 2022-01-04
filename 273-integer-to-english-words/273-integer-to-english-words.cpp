class Solution {
public:
    string nums[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
    string chunk(int num) {
        if (num < 20) return nums[num];
        else if (num < 100) 
            return tens[(num/10)%10] 
            + (num%10 ? " " : "") 
            + chunk(num%10);
        else {
            return chunk(num/100) + " " 
                + "Hundred" 
                + (num%100 ? " " : "") 
                + chunk(num%100);
        }
    }
    
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string s = "";
        
        int i = 1000000000;
        
        while (i != 0) {
            s = s + chunk(num/i);
            switch(i) {
                case 1000000000 :
                    s = s + (num/i ? " Billion" : "");
                    if (num%i != 0 && num > i) s += " ";
                    break;
                case 1000000 :
                    s = s + (num/i ? " Million": "");
                    if (num%i != 0 && num > i) s += " ";
                    break;
                case 1000 : 
                    s = s + (num/i ? " Thousand" : "");
                    if (num%i != 0 && num > i) s += " ";
                    break;
            }
            num = num % i;
            i = i / 1000;
        }
        return s;           
    }
};