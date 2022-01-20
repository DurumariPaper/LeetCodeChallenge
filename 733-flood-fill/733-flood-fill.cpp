class Solution {
    
    int x[4] = {-1, 0, 1, 0};
    int y[4] = { 0, 1, 0,-1};
    
    int m,n;
    
public:
    void fill(vector<vector<int>>& image, int sr, int sc, int& newColor, int& originalColor){
        if(image[sr][sc] == originalColor)
        {
            image[sr][sc] = newColor;
            
            for(int i = 0 ; i < 4 ; i++)
            {
                int nextX = sr + x[i];
                int nextY = sc + y[i];
                if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
                    fill(image, nextX, nextY, newColor, originalColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> result(image);
        m = image.size();
        n = image[0].size();
        int originalColor = image[sr][sc];
        if(originalColor != newColor)
            fill(result, sr, sc, newColor, originalColor);
        return result;
    }
};