/*Question:
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
Tags: Array
*/

/*思路：
法一：
空间复杂度为O(m+n);
1）借助两个vector，分别存储第几行第几列的元素是0
2）访问两个vector，将matrix中对应的元素设为0
法二：
在第一种方法的基础上，利用第0行第0列存储；首先存储第0行第0列第元素
*/

//Code:
//方法一：
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int row = matrix.size();
        int column = matrix[0].size();
        
        std::vector<bool> rowVec(row, false);
        std::vector<bool> colVec(column, false);
        
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < column; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    rowVec[i] = true;
                    colVec[j] = true;
                }
            }
            
        for(int i = 0; i < row; ++i)
        if(rowVec[i])
            for(int j = 0; j < column; ++j)
                matrix[i][j] = 0;
                
        for(int i = 0; i < column; ++i)
        if(colVec[i])
            for(int j = 0; j < row; ++j)
                matrix[j][i] = 0;
                
        return;
    }
};

//方法二：
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       if(matrix.empty() || matrix[0].empty()) return;
        int row = matrix.size();
        int column = matrix[0].size();
        
        bool firstRow = false;
        bool firstCol = false;
        
        for(int i = 0; i < column; ++i)
        if(matrix[0][i] == 0)
        {
            firstRow = true;
            break;
        }
        
        for(int i = 0; i < row; ++i)
        if(matrix[i][0] == 0)
        {
            firstCol = true;
            break;
        }
        
        //遍历第二行第二列开始的元素
        for(int i = 1; i < row; ++i)
            for(int j = 1; j < column; ++j)
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        
        //将第二行第二列的元素根据结果设置为0    
        for(int i = 1; i < row; ++i)
            for(int j = 1; j < column; ++j)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        //设置第一行的元素
        if(firstRow)
            for(int i = 0; i < column; ++i)
                matrix[0][i] = 0;
                
        //设置第一列的元素
        if(firstCol)
            for(int i = 0; i < row; ++i)
                matrix[i][0] = 0;
                
        return; 
    }
};

