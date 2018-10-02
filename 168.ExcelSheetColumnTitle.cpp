/*Question:
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    
    Tag: Math
    Similar problems: 171
    */
    
    /*思路:
    */
    
    //Code:
    class Solution {
public:
    string convertToTitle(int n) {
        if(n < 0)
            return "";
        std::string result;
        while(n > 0)
        {
            int temp = n % 26;
            char t = (temp == 0) ? 'Z' : 'A'+ temp - 1;
            result.insert(result.begin(), t);
            n = (n - 1) /26;
        }
        return result;
    }
};
