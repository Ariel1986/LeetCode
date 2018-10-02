/*
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
Example: 19 is a happy number
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Tags: Hash Table Math
Similar Problems: (E)258 (E)263
*/

//Code:
class Solution {
public:
    bool isHappy(int n) {
        std::vector<int> squares{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
        std::unordered_set<int> existingNum;
        
        auto calc = [&squares](int n)->int
        {
            int result = 0;
            while(n > 0)
            {
                result += squares[n % 10];
                n /= 10;
            }
            return result;
        };

        while(n > 1)
        {
            n = calc(n);
            auto iter = existingNum.emplace(n);
            if(!iter.second)
                return false;
        }
        return (n == 1)? true : false;
    }
};
