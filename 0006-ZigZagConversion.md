/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

//Code 1:
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows <= 1 || numRows >= s.size()) return s;
        
        std::vector<std::string> vec(numRows);
        int row = 0, step = 1;
        for(auto&& ch: s){
            vec[row] += ch;
            if(row == 0){
                step = 1;
            }else{
                if(row == numRows - 1){
                    step = -1;
                }
            }
            row += step;
        }
        
        std::string result;
        for(auto item : vec){
            result += item;
        }
        return result;
    }
};
