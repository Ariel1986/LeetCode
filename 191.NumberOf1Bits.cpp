/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

//Code:
//Code 1: 借助标准库中的bitset实现
class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::bitset<32> b(n);
        return b.count();
    }
};

//Code 2:
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n != 0)
        {
            n &= (n-1);
            ++result;
        }
        return result;
    }
};
