/*Question:
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".
Subscribe to see which companies asked this question
Tags: Math, String
*/

/*思路：
由后到前加元素
重点：如何将代码写的很优雅
*/

//Code:
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int aIndex = a.size()-1;
        int bIndex = b.size()-1;
        
        int index = std::max(aIndex,bIndex);
        while(index >= 0 || carry > 0)
        {
            int sum = (aIndex>=0 && a[aIndex--]=='1') + (bIndex>=0 && b[bIndex--] == '1') + carry;
            result += (sum%2 == 1)?'1': '0';
            carry = sum/2;
            --index;
        }
        
        std::reverse(std::begin(result), std::end(result));
        return result;
    }
};
