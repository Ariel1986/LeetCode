/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
Tags: Array Dynamic Programming
*/

/*思路:
方法一：
创建一个与二维数组同样大小的二维数组result，对于每一行的元素，与自己左右相邻的元素相加，并将二者中较小的保存result中。
但是这种方法要占用O(n^2)的存储空间
方法二:
从triangle的底层开始处理，一直到顶层元素。只需要创建大小为row－1到的一维数组，而且不需要在循环过程中判断是否为首尾元素。
*/

//Code:
//Code 1:
// Using O(n^2) extra space
int minimumTotal(std::vector<std::vector<int>>& triangle)
{
    if (triangle.empty() || triangle.front().empty())
        return 0;
    std::vector<std::vector<int>> sums(triangle);
    for (auto r = 1, rEnd = (int)triangle.size(); r < rEnd; ++r)
    {
        for (auto c = 0, cEnd = (int)triangle[r].size(); c < cEnd; ++c)
        {
            if (c == 0)
                sums[r][c] = sums[r - 1][c] + triangle[r][c];
            else if (c > 0 && c < cEnd - 1)
                sums[r][c] = std::min(sums[r - 1][c] + triangle[r][c], sums[r - 1][c - 1] + triangle[r][c]);
            else
                sums[r][c] = sums[r - 1][c - 1] + triangle[r][c];
        }
    }
    return *std::min_element(sums.back().begin(), sums.back().end());
}
//Code 2:
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty() || triangle[0].empty())
            return 0;
            
        int row = triangle.size();
        vector<int> sumVec(triangle[row-1]);
        
        for(int i = row - 2, col = row -1; i >= 0; --i, --col)
            for(int j = 0; j < col; ++j)
                sumVec[j] = std::min(sumVec[j], sumVec[j+1]) + triangle[i][j];
   
        return sumVec[0];    
    }
};
