/*Question:
Related to question Excel Sheet Column Title--168
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    
Tags: Math
Similar Problems: 168
*/

/*思路:
累计乘以26，然后加
*/
//Code:
class Solution {
public:
    int titleToNumber(string s) {
        if(s.empty())
            return 0;
            
        int result = 0;
        for(auto item: s)
        {
            result = result * 26 + (item - 'A' + 1);
        }
        
        return result;
    }
};
