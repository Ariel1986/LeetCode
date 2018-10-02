/*Question:
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.
Tags: Binary Search, Divide and Conquer
*/

/*思路：
思路一：对每一行进行二分查找
思路二：从第一行开始将每一行的最后一个元素跟target比较，如果：
1）matrix[row][column]==target，返回true
2）matrix[row][column]>target,说明元素在该行的下面，所以++row
3）matrix[row][column]<target,说明元素在该列的左边，--column
*/

//Code:
//代码一：
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        
        int column = matrix.size();
        int row = matrix[0].size();
        
        auto binarySearch = [&matrix, target, row](int col) -> bool
        {
            if(matrix[col][0] > target || matrix[col][row-1] < target)
                return false;
            int beg = 0, end = row-1;
            while(beg <= end)
            {
                int mid = beg+(end-beg)/2;
                if(matrix[col][mid] == target) 
                    return true;
                else if(matrix[col][mid] > target) 
                    end = mid-1;
                else if(matrix[col][mid] < target) 
                    beg = mid+1;
            }
            return false;
        };
        
        for(int i = 0; i < column; ++i)
        {   if(matrix[i][0] > target)
                return false;
            else if(matrix[i][row-1] < target) 
                continue;
            else if(binarySearch(i)) 
                return true;
        }
        
        return false; 
    }
};

//代码二:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto binarySearch = [&matrix, target]() -> bool
        {
            if(matrix.empty()) return false;
            
            int row = 0;
            int column = matrix[0].size()-1;
            
            while(row < matrix.size() && column >= 0)
            {
                if(matrix[row][column] == target) 
                    return true;
                else if(matrix[row][column] > target)
                    --column;
                else
                    ++row;
            }
            return false;
        };
        
        return binarySearch();
    }
};
