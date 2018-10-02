/* Question:
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
*/

/* Method:
只需考虑5的个数，5, 25, 125....
*/

// Code:
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n != 0)
        {
            res += n/5;
            n /= 5;
        }
        return res;
    }
};
