
/*
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows.
How should you handle such cases?
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

/*思路：
对于有可能产生溢出的情况，先用long long类型存储，然后判断
*/

//Code:
    int reverse(int x) {
        int sign = x > 0? 1 : -1;
        long long xcopy = std::abs(x);
        long long result = 0;
        
        while(xcopy > 0)
        {
            result = result * 10 + xcopy % 10;
            xcopy /= 10;
        }
        
        result *= sign;
        if(result < INT_MIN || result > INT_MAX)
            return 0;
            
        return static_cast<int>(result);
    }
