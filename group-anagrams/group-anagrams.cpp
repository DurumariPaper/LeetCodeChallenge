class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> data;
        for(int i = 0; i < strs.size(); i++)
        {
            data[strSort(strs[i])].push_back(strs[i]);            
        }
        
        vector<vector<string>> anagrams;
        for (auto p : data) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
        
    }
    private:
    string strSort(string s) {
        int n = s.size(), counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};