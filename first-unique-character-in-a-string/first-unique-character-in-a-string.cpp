class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> result;
        for(char c : s){
            result[c]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(result[s[i]] == 1)
                return i;
        }
        return -1;
    }
};