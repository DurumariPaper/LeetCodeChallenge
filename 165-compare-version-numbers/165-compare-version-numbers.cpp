
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> data1;
        vector<int> data2;
        int size1 = calculateData(data1, version1);
        int size2 = calculateData(data2, version2);
        int minSize = (size1 > size2) ? size2 : size1;
        
        for(int i = 0; i < minSize; i++){
            if(data1[i] > data2[i])
                return 1;
            else if (data1[i] < data2[i])
                return -1;
        }
        
        if(minSize < size1)
        {
            while(minSize < size1){
                if(data1[minSize++] != 0)
                    return 1;
            }
        }
           
        if(minSize < size2)
        {
            while(minSize < size2){
                if(data2[minSize++] != 0)
                    return -1;
            }
        }
        
        return 0;
    }
    
    int calculateData(vector<int>& data, string& value)
    {
        int index = 0;
        int sum = 0;
        for(char c : value)
        {
            if(isdigit(c))
            {
                sum = sum * 10 + (c - '0');
            }
            if(c == '.')
            {
                index++;
                data.push_back(sum);
                sum = 0;
            }
        }
        if(sum != 0)
        {
            index++;
            data.push_back(sum);
        }
        return index;
    }
    
};

/*
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0, m = version1.length(), n = version2.length();
        while(i < m || j < n){
            int num1 = 0, num2 = 0;
            while(i < m && version1[i] != '.') num1 = num1*10 + (version1[i++] - '0');
            while(j < n && version2[j] != '.') num2 = num2*10 + (version2[j++] - '0');
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            i++, j++;
        }
        return 0;
    }
};*/