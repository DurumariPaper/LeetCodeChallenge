class Solution {
public:
    bool canPermutePalindrome(string s) {
        int size = s.length();
        
        unordered_map<char, int> map;
        
        for(char c : s)
        {
            map[c]++;
        }
        
        int count = 0;
        for(auto data : map)
        {
            count += data.second % 2;
        }
       
        return count <= 1;
    }
};