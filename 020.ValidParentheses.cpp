/*Question:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
Tags: stack, string
Similar Problems:
22, 32, 302
*/

/*思路:
如果是( [ {则进栈，否则与栈顶元素比较
方法二借助了string直接实现
*/

//Code:
//Code 1:
class Solution {
public:
    bool isValid(string s) {
        if(s.size() <= 1) return false;
        std::vector<char> check;
        
        for(auto item: s)
        {
            switch(item)
            {
                case '(':
                    check.push_back(item);
                    break;
                case '[':
                    check.push_back(item);
                    break;
                case '{':
                    check.push_back(item);
                    break;
                case ')':
                    if(check.empty() || check.back() != '(')
                        return false;
                    check.pop_back();
                    break;
                  case ']':
                    if(check.empty() || check.back() != '[')
                        return false;
                    check.pop_back();
                    break;
                  case '}':
                    if(check.empty() || check.back() != '{')
                        return false;
                    check.pop_back();
                    break;
                default:
                    break;
            }
        }
        
        if(check.empty()) return true;
        return false;
    }
};

//Code 2:
class Solution {
public:
    bool isValid(string s) {
        if(s.size() <= 1) return false;
        std::string check;
        
        for(auto item: s)
        {
            if(item == ')' && check.back() == '(')
                check.pop_back();
            else if(item == ']' && check.back() == '[')
                check.pop_back();
            else if(item == '}' && check.back() == '{')
                check.pop_back();
            else 
                check.push_back(item);
        }
    
        return check.empty();
    }
};
