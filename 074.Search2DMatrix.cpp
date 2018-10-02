/*Question:
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,
Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
Tags: Array, Binary Search
*/

/*思路：
1）先用二分查找确定目标元素可能在哪一行
2）在找到的行查找目标元素
*/

//Code:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int column = matrix.size();
        int row = matrix[0].size();
        
        int colBeg = 0, colEnd = column-1;
        while(colBeg <= colEnd)
        {
            //Find at which column
            int colMid = colBeg+(colEnd-colBeg)/2;
            if(matrix[colMid][row-1] < target) 
                colBeg = colMid+1;
            else if(matrix[colMid][0] > target) 
                colEnd = colMid-1;
            else
            {
                //Find at which row
                int rowBeg = 0, rowEnd = row-1;
                while(rowBeg <= rowEnd)
                {
                    int rowMid = rowBeg+(rowEnd-rowBeg)/2;
                    if(matrix[colMid][rowMid] == target) return true;
                    else if(matrix[colMid][rowMid] > target) 
                        rowEnd = rowMid-1;
                    else if(matrix[colMid][rowMid] < target) 
                        rowBeg = rowMid+1;
                }
                return false;
            }
        }
        return false;
    }
};
