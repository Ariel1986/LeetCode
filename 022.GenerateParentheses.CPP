/*Question:
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
Tags: Backtrackinig, string
Similar Problems: 20, 32, 301
*/

/*思路：
借助递归
Note：实现过程中用到了lambda递归
*/

//Code:
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n <= 0) return {};
        std::vector<std::string> result;

        std::function<void(std::string, int, int)>
        generateParenthesisHelper = [&](std::string s, int left, int right)
        {
            if(left == n && right == n)
            {
                result.emplace_back(s);
                return;
            }
            if(left < n)
                generateParenthesisHelper(s + "(", left + 1, right);
            if(left > right)
                generateParenthesisHelper(s + ")", left, right + 1);
        };

        generateParenthesisHelper("", 0, 0);
        
        return result;
    }
};


//对于上述问题中的递归调用，如果对string以引用的形式传递，需要注意的是：在当前循环结束时，需要将最后一个字符pop出来
vector<string> generateParenthesis(int n) {
        if(n <= 0) return {};
        std::vector<std::string> result;

        std::function<void(std::string&, int, int)>
        generateParenthesisHelper = [&](std::string& s, int left, int right)
        {
            if(left == n && right == n)
            {
                result.emplace_back(s);
                return;
            }
            if(left < n)
            {
                s += "(";
                generateParenthesisHelper(s, left + 1, right);
                s.pop_back();   //pop the last character
            }
            if(left > right)
            {
                s += ")";
                generateParenthesisHelper(s, left, right + 1);
                s.pop_back();   //pop the last character
            }
        };

        std::string s;
        generateParenthesisHelper(s, 0, 0);
        
        return result;
    }
