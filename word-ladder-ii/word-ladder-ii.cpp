class Solution {
public:
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;
    
    vector<string> findNeighbors(string &word, unordered_set<string>& wordList) {
        vector<string> neighbors;
        
        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];   
            
            // replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                
                // skip if the character is same as original or if the word is not present in the wordList
                if (c == oldChar || !wordList.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }
    
    void backtrack(string &source, string &destination) {
        // store the path if we reached the endWord
        if (source == destination) {
            shortestPaths.push_back(currPath);
        }
        for (int i = 0; i < adjList[source].size(); i++) {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }
    
    void bfs(string beginWord, string endWord, unordered_set<string> wordList) {
        queue<string> q;
        q.push(beginWord);
        
        // remove the root word which is the first layer
        if (wordList.find(beginWord) != wordList.end()) {
            wordList.erase(wordList.find(beginWord));
        }
        
        unordered_map<string, int> isEnqueued;
        isEnqueued[beginWord] = 1;
        
        while (!q.empty())  {
            // visited will store the words of current layer
            vector<string> visited;
            
            for (int i = q.size() - 1; i >= 0; i--) {
                string currWord = q.front(); 
                q.pop();

                // findNeighbors will have the adjacent words of the currWord
                vector<string> neighbors = findNeighbors(currWord, wordList);
                for (auto word : neighbors) {
                    visited.push_back(word);
                    // add the edge from currWord to word in the list
                    adjList[currWord].push_back(word);
                    
                    if (isEnqueued.find(word) == isEnqueued.end()) {
                        q.push(word);
                        isEnqueued[word] = 1;
                    }
                }
            }
            // removing the words of the previous layer
            for (int i = 0; i < visited.size(); i++) {
                if (wordList.find(visited[i]) != wordList.end()) {
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // copying the words into the set for efficient deletion in BFS
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        // build the DAG using BFS
        bfs(beginWord, endWord, copiedWordList);
        
        // every path will start from the beginWord
        currPath = {beginWord};
        // traverse the DAG to find all the paths between beginWord and endWord
        backtrack(beginWord, endWord);
        
        return shortestPaths;
    }
};





/*


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
};*/