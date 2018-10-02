/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example,
Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

/*思路:
由左－>右，上－>下，右－>左，下->上的顺序访问二维数组
*/

//Code:
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return {};
        
        std::vector<int> result;
        int begRow = 0;
        int endRow = matrix.size() - 1;
        int begCol = 0;
        int endCol = matrix[0].size() - 1;
        
        while(begRow <= endRow && begCol <= endCol)
        {
            //left->right
            if(begRow <= endRow)
            {
                for(int i = begCol; i <= endCol; ++i)
                    result.emplace_back(matrix[begRow][i]);
                ++begRow;
            }
            
            //up->down
            if(begCol <= endCol)
            {
                for(int i = begRow; i <= endRow; ++i)
                    result.emplace_back(matrix[i][endCol]);
                --endCol;
            }
            
            //right->left
            if(begRow <= endRow)
            {
                for(int i = endCol; i >= begCol; --i)
                    result.emplace_back(matrix[endRow][i]);
                --endRow;
            }
            
            //down->up
            if(begCol <= endCol)
            {
                for(int i = endRow; i >= begRow; --i)
                    result.emplace_back(matrix[i][begCol]);
                ++begCol;
            }
        }
        
        return result;
    }
};
