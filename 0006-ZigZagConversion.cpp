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

//Code 2:
std::string convert(std::string s, int nRows)
{
    if (s.size() <= 1 || nRows <= 1) return s;

    std::string result;

    for (int i = 0, iEnd = s.size(); i < iEnd; i += nRows*2-2)
        result.append(1, s[i]);

    for (int r = 1; r < nRows-1; ++r)
    {
        const int steps = 2 * nRows - 2 * r - 2;
        for (int i = r, iEnd = s.size(), k = 0; i < iEnd;)
        {
            result.append(1, s[i]);
            if (k++ % 2 == 0)
                i += steps;
            else
                i += r*2;
        }
    }

    for (int i = nRows - 1, iEnd = s.size(); i < iEnd; i += nRows * 2 - 2)
        result.append(1, s[i]);

    return result;
}
