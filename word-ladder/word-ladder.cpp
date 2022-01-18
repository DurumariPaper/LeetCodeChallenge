class Solution {
    int shortestCount = INT_MAX;
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;
public:
    
    vector<string> getNeighbors(string& word, unordered_set<string>& wordList)
    {
        vector<string> neighbors;
        for(int i = 0; i < word.size(); i++)
        {
            char oldChar = word[i];   
            for(int j = 'a'; j <= 'z' ; j++)
            {
                word[i] = j;                    
                if(word[i] != oldChar && wordList.count(word) != 0)
                {
                    neighbors.push_back(word);
                }
            }
            word[i] = oldChar;   
        }
        return neighbors;
    }
    
    void backtrack(string & source, string& destination)
    {
        if(source == destination)
        {
            shortestPaths.push_back(currPath);
            if(shortestCount > currPath.size())
            {
                shortestCount = currPath.size();
            }
        }
        for(int i = 0; i < adjList[source].size();i++)
        {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }
    
    void bfs(string beginWord, string endWord, unordered_set<string> wordList)
    {
        queue<string> q;
        q.push(beginWord);
        
        if(wordList.find(beginWord) != wordList.end())
            wordList.erase(wordList.find(beginWord));
        
        unordered_map<string, int> isEnqueued;
        isEnqueued[beginWord] = 1;
        
        while(!q.empty())
        {
            vector<string> visited;
            
            for(int i = q.size() - 1; i >= 0; i--)
            {
                string currWord = q.front();
                q.pop();
                vector<string> neighbors = getNeighbors(currWord,wordList);
                for(auto word : neighbors)
                {
                    visited.push_back(word);
                    adjList[currWord].push_back(word);
                    if(isEnqueued.count(word) == 0)
                    {
                        q.push(word);
                        isEnqueued[word] = 1;
                    }
                }
            }
            for(int i = 0; i < visited.size(); i++)
            {
                if(wordList.find(visited[i]) != wordList.end()){
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        
        bfs(beginWord, endWord, copiedWordList);
        
        currPath = {beginWord};
        backtrack(beginWord, endWord);
        return shortestCount == INT_MAX ? 0 : shortestCount;
    }
};