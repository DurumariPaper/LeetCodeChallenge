class Solution {
public:
    bool canPermutePalindrome(string s) {
        int size = s.length();
        
        unordered_map<char, int> map;
        
        for(char c : s)
        {
            map[c]++;
        }
        
        if(size % 2 == 0)
        {
            for(auto data : map)
            {
                if(data.second %2 == 1)
                    return false;
            }
        }
        else
        {
            int count = 0;
            for(auto data : map)
            {
                if(data.second %2 == 1)
                    count++;
                if(count > 1)
                    return false;
            }
        }
        
        return true;
    }
};