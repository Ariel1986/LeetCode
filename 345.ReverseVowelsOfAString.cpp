/*
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".
*/

//Code:
class Solution {
public:
    string reverseVowels(string s) 
    {
        if(s.size() < 2) return s;
        
        std::string vowels = "aeiouAEIOU";
        std::string str(s);
        
        for(int i = 0, j = str.size() - 1; i < j; ++i, --j)
        {
            while(i < j && vowels.find(str[i]) == std::string::npos)
                ++i;
                
            while(i < j && vowels.find(str[j]) == std::string::npos)
                --j;
                
            if(i < j)
                std::swap(str[i], str[j]);
        }
        return str;
    }
};
