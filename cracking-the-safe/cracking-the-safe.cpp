class Solution {
public:
    string crackSafe(int n, int k) {
        string ans = string(n, '0');
        unordered_set<string> visited;
        visited.insert(ans);
        
        for(int i = 0;i<pow(k,n);i++){
            string prev = ans.substr(ans.size()-n+1,n-1);
            for(int j = k-1;j>=0;j--){
                string now = prev + to_string(j);
                if(!visited.count(now)){
                    visited.insert(now);
                    ans += to_string(j);
                    break;
                }
            }
        }
        return ans;
    }
};