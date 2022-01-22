class Solution {
    int m;
    int n;
    
    int ptX[4] = {-1,0,1,0};
    int ptY[4] = {0,1,0,-1};
    
public:
    
    bool find(vector<vector<char>>& board, string& word, int x, int y, int index, vector<vector<bool>>& visited)
    {
        if(word.size() == index)
            return false;
        
        if(word.size() - 1 == index && word[index] == board[x][y])
            return true;
        
        if(word[index] != board[x][y])
            return false;
        
        for(int i = 0; i < 4; i++)
        {
            int nextX = x + ptX[i];
            int nextY = y + ptY[i];
            
            if(nextX >= 0 and nextX < m and nextY >=0 and nextY < n)
            {         
                if(!visited[nextX][nextY])
                {
                    visited[nextX][nextY] = true;
                    if(find(board, word, nextX, nextY, index + 1, visited))
                        return true;      
                    visited[nextX][nextY] = false;                    
                }

            }                
        }        
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(!visited[i][j])
                {
                    visited[i][j] = true;
                    if(find(board, word, i, j, 0, visited))
                        return true;
                    visited[i][j] = false;
                }

            }   
        }
        
        return false;
    }
};