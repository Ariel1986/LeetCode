/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?
*/

//Code:
//Code 1:
void rotate(vector<vector<int>>& matrix) {
    if(matrix.size() < 2) return;
    
    std::vector<int> vec;
    
    int i = 0, iEnd = matrix.size() - 1, j = 0,  jEnd = matrix[0].size() - 1;
    
    
    for(int i = 0, iEnd = matrix.size() - 1, j = 0,  jEnd = matrix[0].size() - 1;
    i < iEnd && j < jEnd; ++i, ++j, --iEnd, --jEnd)
    {
        vec.clear();
        
        //存第一行
        for(int k = j; k <= jEnd; ++k)
            vec.emplace_back(matrix[i][k]);
        
        //left -> top
        for(int m = i + 1, n = jEnd - 1;m <= iEnd && n >= j; ++m, --n)
            matrix[i][n] = matrix[m][j];
        
        //down ->left
        for(int m = i+1, n = j+1;m <= iEnd && n <= jEnd; ++m, ++n)
            matrix[m][j] = matrix[iEnd][n];
        
        //right->down
        for(int m = iEnd-1, n = j + 1;m >i && n < jEnd; --m, ++n)
            matrix[iEnd][n] = matrix[m][jEnd];
        
        //top->right    
        for(int m = i; m <= iEnd; ++m)
            matrix[m][jEnd] = vec[m-i];
    }
    return;
}

//Code 2:
void rotate(std::vector<std::vector<int>>& matrix)
{
    if (matrix.empty() || matrix.back().empty() || matrix.size() == 1) return;
    const int N = (int)matrix.size();
    for (int i = 0, iEnd = N / 2; i < iEnd; ++i)
    {
        for (int k = 0, kEnd = N - i * 2 - 1; k < kEnd; ++k)
        {
            std::swap(matrix[i][i + k], matrix[i+k][N-i-1]);
            std::swap(matrix[i][i + k], matrix[N-i-1][N-i-k-1]);
            std::swap(matrix[i][i + k], matrix[N-i-k-1][i]);
        }
    }
}
