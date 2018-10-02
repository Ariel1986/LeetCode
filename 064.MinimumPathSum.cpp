/*Question:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Tags: Array, DP
*/

//Code:
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        std::vector<std::vector<int>> sums(row, std::vector<int>(col, 0));
        
        sums[0][0] = grid[0][0];
        for(int i = 1; i < row; ++i)
            sums[i][0] = sums[i-1][0] + grid[i][0];
        for(int i = 1; i < col; ++i)
            sums[0][i] = sums[0][i-1] + grid[0][i];
            
        for(int i = 1; i < row; ++i)
            for(int j = 1; j < col; ++j)
                sums[i][j] = grid[i][j] + std::min(sums[i-1][j], sums[i][j-1]);
               
        return sums[row-1][col-1];
    }
};
