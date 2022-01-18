class Solution {
    int count = 0;
    vector<vector<bool>> visited;
    int m;
    int n;
    
    int x[4] = {-1,0,1,0};
    int y[4] = {0,1,0,-1};
public:
    void findIsland(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j] = '0';
        
        for(int k =0; k < 4; k++)
        {
            int nextX = i + x[k];
            int nextY = j + y[k];
            
            if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
            {
                if(!visited[nextX][nextY] && grid[nextX][nextY] == '1')
                {
                    findIsland(grid,nextX,nextY);
                }
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        //초기화
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            vector<bool> visit;
            for(int j = 0; j < n; j++)
            {
                visit.push_back(false);
            }
            visited.push_back(visit);
        }
                
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    findIsland(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};