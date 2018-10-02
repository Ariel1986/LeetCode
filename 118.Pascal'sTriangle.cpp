/*Question:
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
Tags: Array
Similar Problems: 119
*/

/*思路:
每到新的一层，都根据上一层的元素求得。
在求每一层新的元素时，从后向前处理
*/

//Code:
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows <= 0)
            return {};
        std::vector<std::vector<int>> result(1, {1});
        
        for(int curRow = 2;curRow <= numRows; ++curRow)
        {
            std::vector<int> cur = result[curRow - 2];
            cur.push_back(1);
            
            for(int i = cur.size() - 2; i > 0; --i)
                cur[i] = cur[i] + cur[i-1];
            
            result.push_back(cur);
        }
        return result;
    }
};
