class Solution {
    int m;
    int n;
    int path = 0;
    int result = 0;
    int startPoint[2];
    
    int ptX[4] = {-1,0,1,0};
    int ptY[4] = {0,1,0,-1};
public:
    
    void dfs(vector<vector<int>>& grid, int x, int y, int length)
    {        
        if(grid[x][y] == -1)
            return;
        
        if(path < length)
            return;
        
        if(grid[x][y] == 2)
        {
            if(path == length)
            {
                result++;
            }
            return;
        }
        
        int point = grid[x][y];
        
        
        
        grid[x][y] = -1;
        for(int i = 0; i < 4 ; i++)
        {
            int nextX = x + ptX[i];
            int nextY = y + ptY[i];
            if(nextX < 0 || nextY < 0 || nextX >= m || nextY >= n)
                continue;
            
            dfs(grid,nextX,nextY,length+1);
        }
        grid[x][y] = point;
        
        
        return;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        path = m*n;
        //find opstacle & find start point      
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == -1)
                    path--;
                
                if(grid[i][j] == 1)
                {
                    startPoint[0] = i;
                    startPoint[1] = j;
                }
                    
            }
        }
        
        
        //dfs
        dfs(grid, startPoint[0], startPoint[1], 1);
        
        return result;
    }
};