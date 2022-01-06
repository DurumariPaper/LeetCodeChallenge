class Solution {
public:
    
    
    static bool cmp(string& str1, string& str2)
    {
        bool checker = true;
        int size1 = str1.size();
        int size2 = str2.size();        
        
        int i = str1.find(" ") + 1;
        int j = str2.find(" ") + 1;
        
        for(; i < size1 && j < size2 ; i++, j++)
        {
            if(str1[i] > str2[j])
                return false;
            else if(str1[i] < str2[j])
                return true;
        }
        
        if(i == size1 && j == size2)
        {
            int data = strcmp(str1.c_str(), str2.c_str());
                              
            if(strcmp(str1.c_str(), str2.c_str()) < 0)
                return true;
            else
                return false;                
        }
        
        if( i < size1)
            return false;
                
        return true;
    }
    
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters;
        vector<string> digits;
        for(string log : logs)
        {
            int index = log.find(" ");
            if(isdigit(log[index+1]))
            {
                digits.push_back(log);
            }
            else
            {
                letters.push_back(log);
            }
        }
        
        sort(letters.begin(), letters.end(), cmp);
        
        for(string digit : digits)
            letters.push_back(digit);
        
        return letters;
    }
};