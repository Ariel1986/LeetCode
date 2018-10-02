/*Question:
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1].
Note:
Could you optimize your algorithm to use only O(k) extra space?
Tag: Array
SP: 118
*/

/*思路:
从后向前处理，倒数第二个元素开始，result[j] = result[j] + result[j - 1];
*/

//Code:
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0)
            return {};
        vector<int> result{1};
        
        for(int i = 1; i <= rowIndex; ++i)
        {
            result.push_back(1);
            for(int j = i - 1; j > 0; --j)
                result[j] = result[j] + result[j - 1];
        }
        return result;
    }
};
