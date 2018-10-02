/*
Given an integer, write a function to determine if it is a power of two.
*/

/*思路：
对于2的n次方的数，有一个特点：只有1位为1，所以对于这种数，会满足n&(n-1)==0
*/

//Code:
    bool isPowerOfTwo(int n) {
        if(( n <= 0 ) || (n & ( n - 1)) != 0) return false;
        return true;
    }
