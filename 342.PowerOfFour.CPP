/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Example:
Given num = 16, return true. Given num = 5, return false.
Follow up: Could you solve it without loops/recursion?
*/

/*思路：
对于是否为2的次幂，可以通过(n & (n-1)) == 0判断，对于4的次幂，除了要满足该条件外，还要满足在1的位右边0的个数为偶数个。
*/

//Code:
//Code 1:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        if((num & (num -1)) == 0)
        {
            int count = 0;
            while(!(num & 1))
            {
                num >>= 1;
                ++count;
            }
            if(count % 2 == 0) return true;
        }
        
        return false;
    }
    
//Code 2:
bool isPowerOfFour(int num)
{
    if (num <= 0) return false;

    if ((num & (num - 1)) != 0) return false;

    const int mask = 0b01010101010101010101010101010101;
    if ((num & mask) != 0) return true;

    return false;
}
