/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
/*method:
//n=numRows
Δ=2n-2    1                           2n-1                         4n-3
Δ=        2                     2n-2  2n                    4n-4   4n-2
Δ=        3               2n-3        2n+1              4n-5       .
Δ=        .           .               .               .            .
Δ=        .       n+2                 .           3n               .
Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
Δ=2n-2    n                           3n-2                         5n-4
*/


//===================code1================
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(s.size() <= 1 || numRows < 2) return s;
        std::vector<std::string> sVec(numRows);
        bool down = true;
        for( int i = 0, j = 0, iEnd = s.size(); i < iEnd; ++i) {
            sVec[j].push_back(s[i]);
            j = down? j+1:j-1;
            
            if(j == numRows) {
                j = numRows - 2;
                down = false;
            }
            else if(j < 0) {
                j = 1;
                down = true;
            }
        }
        
        std::string result;
        for(auto&& value : sVec) {
            result.append(value);
        }
        return result;
    }
};

//==========================Code2==================
//Code 2:
std::string convert(std::string s, int nRows)
{
    if (s.size() <= 1 || nRows <= 1) return s;

    std::string result;

    //第一行元素
    for (int i = 0, iEnd = s.size(); i < iEnd; i += nRows*2-2)
        result.append(1, s[i]);

    //中间元素
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

    //最后一行元素
    for (int i = nRows - 1, iEnd = s.size(); i < iEnd; i += nRows * 2 - 2)
        result.append(1, s[i]);

    return result;
}
