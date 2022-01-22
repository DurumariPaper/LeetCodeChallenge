

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;
    TrieNode(){word.clear();}
};

class Solution {
    int m;
    int n;
    
    TrieNode* trie;
    vector<string> result;
    
    int ptX[4] = {-1,0,1,0};
    int ptY[4] = {0,1,0,-1};
    
public:
    void backtracking(vector<vector<char>>& board, vector<string>& words, int x, int y, TrieNode* root)
    {
        char letter = board[x][y];
        
        if(letter == '#' || root->children.count(letter) == 0)
            return;
                    
        TrieNode* currentNode = root->children[letter];
        
        if(!currentNode->word.empty())
        {
            result.push_back(currentNode->word);
            currentNode->word.clear();
        }
        
        board[x][y] = '#';
        
        for(int i = 0; i < 4 ; i++)
        {
            int nextX = x + ptX[i];
            int nextY = y + ptY[i];
            
            if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
                continue;
            
            if(currentNode->children.count(board[nextX][nextY]) != 0)
                backtracking(board,words,nextX,nextY,currentNode);
            
        }
        
        board[x][y] = letter;
                  
    }
    void buildTrie(vector<string>& words)
    {
        trie = new TrieNode();
        //gen Trie        
        for(string word : words)
        {
            TrieNode* tail = trie;
            for(int i = 0; i < word.size(); i++)
            {
                if(tail->children.count(word[i]) == 0) 
                {
                    TrieNode* node = new TrieNode();
                    tail->children[word[i]] = node;
                }
                tail = tail->children[word[i]];
            }
            
            tail->word = word;
        }
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        
        buildTrie(words);
        
        for (int row = 0; row < board.size(); ++row) 
        {
            for (int col = 0; col < board[row].size(); ++col) 
            {
                backtracking(board, words, row, col, trie);
            }
        }
        
        
        return result;        
    }
};