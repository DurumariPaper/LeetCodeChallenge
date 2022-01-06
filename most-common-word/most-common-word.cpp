class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> wordMap;
        string word = "";
        for(char c : paragraph)
        {
            if(c >= 'a' && c <= 'z')
            {
                word += c;
            }
            else if( c >= 'A' && c <= 'Z')
            {
                word += tolower(c);
            }
            else
            {
                if(word != "")
                {                    
                    wordMap[word]++;
                    word = "";
                }
            }
        }
        
        if(word != "")
        {
            wordMap[word]++;
        }
        
        for( string str : banned)
        {
            wordMap.erase(str);
        }
        
        string result = "";
        int max = 0;
        for(auto it = wordMap.begin(); it != wordMap.end() ; it++)
        {
            if(it->second > max)
            {
                max = it->second;
                result = it->first;
            }
        }
        return result;
    }
};