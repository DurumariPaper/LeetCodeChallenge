class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        transpos(matrix, size);
        flip(matrix, size);
    }
    
    void transpos(vector<vector<int>>& matrix, int& size){
        for(int i = 0; i < size; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                //swap(matrix[i][j], matrix[j][i]);
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }    
        }
    }
    
    void flip(vector<vector<int>>& matrix, int& size){
        for(int i = 0; i < size / 2; i++)
        {
            int end = size - i - 1;
            
            for(int j = 0; j < size; j++)
            {
                //swap(matrix[j][i], matrix[j][end]);
                int temp = matrix[j][i];
                matrix[j][i] = matrix[j][end];
                matrix[j][end] = temp;
            }    
        }
    }
};