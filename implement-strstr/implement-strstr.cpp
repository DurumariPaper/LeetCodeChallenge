class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = -1;        
        
        if(haystack.size() == 0 && needle.size() == 0)
            return 0;
        
        int size = haystack.size() - needle.size();
        int i = 0;
        
        while(i <= size)
        {
            if(checkMatch(haystack, needle,i)) 
            {
                return i;
            }
            i++;
        }   
        
        return result;
    }
    
    bool checkMatch(string& haystack, string& needle, int i)
    {
        int index = 0;
        while(index < needle.size())
        {
            if(needle[index] == haystack[i])
            {
                index++;
                i++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    
};