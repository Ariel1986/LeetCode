/*Question:
Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh".
Tags: Two points, String
*/

//Code:
class Solution {
public:
    string reverseString(string s) {
        auto begIter = s.begin();
        auto endIter = s.end() - 1;
        
        while(begIter < endIter)
        {
            char temp = *begIter;
            *begIter = *endIter;
            *endIter = temp;
            ++begIter;
            --endIter;
        }
        return s;
    }
};
