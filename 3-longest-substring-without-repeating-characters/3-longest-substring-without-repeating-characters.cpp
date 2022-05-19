class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int chars[128] = {0};
        
        int left = 0;
        int right = 0;
        
        int result = 0;
        
        while(right < s.length())
        {
            char r = s[right];
            chars[r]++;
            
            while(chars[r] > 1)
            {
                char l = s[left];
                chars[l]--;
                left++;
            }
            result = max(result, right - left + 1);
            
            right++;
            
        }
        return result;
    }
};