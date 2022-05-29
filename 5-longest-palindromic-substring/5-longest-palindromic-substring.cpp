class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        int minLeft = 0;
        int maxLength = 1;
        int maxRight = s.size() - 1;
        
        for(int mid = 0; mid < s.size();)
        {
            int left = mid;
            int right = mid;
            
            while(right < maxRight && s[right+1] == s[right])
            {
                right++;
            }
            mid = right + 1;
            while(right < maxRight && left > 0 && s[right+1] == s[left - 1])
            {
                right++;
                left--;
            }
            
            int length = right - left + 1;
            if(maxLength < length)
            {
                maxLength = length;
                minLeft = left;
            }
        }
        
        return s.substr(minLeft, maxLength);
    }
};
