class Solution {
public:
    int size = 0;
    void rotate(vector<vector<int>>& matrix) {
        size = matrix[0].size();
        transpose(matrix);
        flip(matrix);
    }
    
    void transpose(vector<vector<int>>& matrix)
    {
        for(int i = 0; i < size ; i++)
        {
            for(int j = i;j < size ; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
    
    void flip(vector<vector<int>>& matrix)
    {
        for(int i = 0; i < size ; i++)
        {
            for(int j = 0;j < size/2 ; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][size - j - 1];
                matrix[i][size - j - 1] = temp;
            }
        }
    }
};