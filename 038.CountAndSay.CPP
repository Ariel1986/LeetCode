/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
Tags:string
*/

//Code:
class Solution {
public:
    string countAndSay(int n) {
        if(n < 0) return "";
        if(n == 1) return {1 + '0'};
        
        std::string str{"1"};
        
        while( n > 1)
        {
            std::string temp;
            int count = 1;
            int i = 1;
            for(; i < str.size(); ++i)
            {
                if(str[i] == str[i - 1])
                {
                    ++count;
                }
                else
                {
                    temp += count + '0';
                    temp += str[i -1];
                    count = 1;
                }
            }
            temp += count + '0';
            temp += str[i -1];
            str = temp;
            --n;
        }
        return str;
    }
};
