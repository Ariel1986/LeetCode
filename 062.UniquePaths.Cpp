/* Question:
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Above is a 3 x 7 grid. How many possible unique paths are there?
Note: m and n will be at most 100.
Subscribe to see which companies asked this question
Tags: Array, DP
*/

/*思路：
对于m*n的元素，paths[i][j] = paths[i-1][j] +paths[i][j-1]
对于第0行和第0列的元素，方法只有一种，所以值为1
在实现的过程中用一维数组模拟二维数组的实现
*/

//Code:
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < 1 || n < 1) return 0;
        
        std::vector<int> paths(m*n, 1);
        
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                paths[i*n+j] = paths[(i-1)*n+j] +paths[i*n+j-1];
       
       return paths.back(); 
    }
};
