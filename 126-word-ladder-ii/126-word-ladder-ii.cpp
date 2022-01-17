class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, vector<string>& wL) {
      
      // push all words in set to make is easy to search
      unordered_set<string> words(wL.begin(), wL.end());
      
      // ans to store all min paths
      vector<vector<string>> ans;
      int path = INT_MAX;
      
      // push a path in queue
      // in starting path only has one node
      queue<vector<string>> q; q.push({ start });
      
      // erased from set, means node is maked visited
      words.erase(start);
      
      
      while(q.size()) {
        auto curr = q.front(); 
        q.pop();
        
        // stop this path, it's not valid
        if(curr.size() > path) continue;
        auto prev = curr.back();
        words.erase(prev);
        
        // we reached end
        // if curr path combination size is less than prev than clear prev ans
        if(prev == end) {
          if(curr.size() < path) ans.clear();
          ans.push_back(curr);
          path = curr.size();
          continue;
        }
        
        // generate all next combinations of most recent node in path vector
        for(int i=0; i<prev.size(); ++i) {
          for(char c='a'; c<='z'; ++c){
            string copy = prev;
            copy[i] = c;
            
            // if this next node is present in set, we can visite
            // hence push it in queue
            if(c != prev[i] && words.count(copy)) {
              curr.push_back(copy);
              q.push(curr);
              curr.pop_back();
            }
          }
        }
      }
      
      return ans;
    }
};