
/*Question:
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.
Tags: Array, DP
*/

/*思路：
分别处理第一行、第一列以及剩下的元素
*/

//Code:
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0]==1)
            return 0;

        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        std::vector<int> paths(row*column, 1);

        //处理第一行
        for (int i = 1; i<column; ++i)
        {
            if (obstacleGrid[0][i] == 1)
                paths[i] = 0;
            else
                paths[i] = paths[i - 1];
        }
        //处理第一列
        for (int i = 1; i<row; ++i)
        {
            if (obstacleGrid[i][0] == 1)
                paths[i*column] = 0;
            else if (i > 0)
                paths[i*column] = paths[(i - 1)*column];
        }
        //处理第一行第一列之外的
        for (int i = 1; i<row; ++i)
            for (int j = 1; j<column; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    paths[i*column + j] = 0;
                else
                    paths[i*column + j] = paths[(i - 1)*column + j] + paths[i*column + j - 1];
            }
        return paths[row*column - 1];
     }
};


//Code2:
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;

        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        std::vector<int> paths(row*column, 1);

        for(int i=0; i < row; ++i)
            for(int j=0; j<column; ++j)
            {
                if(obstacleGrid[i][j] == 1)
                    paths[i*column+j] = 0;
                else
                {
                    if(i>0 && j>0)
                        paths[i*column + j] = paths[(i - 1)*column + j] + paths[i*column + j - 1];
                    else if(i==0 && j>0)  //第一行
                        paths[j] = paths[j-1];
                    else if(j==0 && i>0)
                        paths[i*column] = paths[(i-1)*column];
                    else 
                        paths[i*column+j] = 1;
                }
            }
       
        return paths[row*column - 1];
     }
};
