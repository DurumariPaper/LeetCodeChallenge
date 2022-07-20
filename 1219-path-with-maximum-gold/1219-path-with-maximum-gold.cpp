class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m;
    int n;
public:
    
    void collectGold(vector<vector<int>>& grid, vector<vector<bool>> &visited, int x, int y, int & gold, int currentGold)
    {
        visited[x][y] = true;
        currentGold += grid[x][y];
        gold = max(gold, currentGold);
        for(int i = 0; i < 4; i++)
        {
            int moveX = x + dx[i];
            int moveY = y + dy[i];
            if(moveX < 0 || moveX >= m || moveY < 0 || moveY >= n || visited[moveX][moveY] || grid[moveX][moveY] == 0)
                continue;
            collectGold(grid,visited, moveX, moveY, gold, currentGold);
        }
        visited[x][y] = false;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        /*bool visited[m][n];
        
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j > n; j++)
            {
                visited[i][j] = false;
            }
        }*/
        
        
        int maximumGold = 0;
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 0)
                {
                    int gold = 0;
                    collectGold(grid, visited, i, j, gold, 0);
                    maximumGold = max(maximumGold, gold);
                }
                
            }
        }
    
        return maximumGold;
    }
};